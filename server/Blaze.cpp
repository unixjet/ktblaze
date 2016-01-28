#include "blaze.h"
#include <Talk2Client.h>
#include "logger.hpp"
#include "Container/Ptr.h"
#include <QApplication>

static boost::asio::io_service service;

static boost::asio::ip::tcp::acceptor acceptor(service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8001));

static void HandleClientAccess(Talk2Client::ptr client, const boost::system::error_code & err)
{
	client->Start();
	Talk2Client::ptr new_client = Talk2Client::MakeClient(service);
	acceptor.async_accept(new_client->Sock(), boost::bind(HandleClientAccess, new_client, _1));
}

MsgTrigger::MsgTrigger(Urho3D::WeakPtr<Blaze>blaze, QObject* parent )
    :QObject(parent)
    ,timerId_(0)
    ,blaze_(blaze)
{
}

MsgTrigger::~MsgTrigger()
{
    if(timerId_) killTimer(timerId_);
}


void MsgTrigger::timerEvent(QTimerEvent *event)
{
    if (!blaze_.Expired())
    {
        auto p = blaze_.Lock();
        p->ProcessEvents();
    }
}

void MsgTrigger::Trigger()
{
    timerId_ = startTimer(2);
}


Blaze::Blaze(Urho3D::Context *context)
    :Urho3D::Object(context)
{

    context_->RegisterSubsystem(this);
    context_->RegisterSubsystem(new Logger(context_));

	// the global acceptor initializes
	LOG_NORMAL << "Sever Started";
	Talk2Client::ptr client = Talk2Client::MakeClient(service);
	acceptor.async_accept(client->Sock(), boost::bind(HandleClientAccess, client, _1));
}

Blaze::~Blaze()
{
}

void Blaze::ProcessEvents()
{
//    LOG_NORMAL << "Process Events";
	while (service.poll_one());
}

