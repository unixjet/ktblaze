#ifndef TALK_TO_CLIENT
#define TALK_TO_CLIENT


#include <boost/function.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include "KTP/KTPLL.h"


#define MEM_FN(x)      boost::bind(&self_type::x, shared_from_this())
#define MEM_FN1(x,y)   boost::bind(&self_type::x, shared_from_this(),y)
#define MEM_FN2(x,y,z) boost::bind(&self_type::x, shared_from_this(), y, z)

class Talk2Client : public boost::enable_shared_from_this<Talk2Client>, boost::noncopyable
{
    typedef Talk2Client self_type;
	Talk2Client(boost::asio::io_service & service);

public:
    typedef boost::system::error_code error_code;
    typedef boost::shared_ptr<Talk2Client> ptr;

	static ptr MakeClient(boost::asio::io_service & service);

    void Start();
    void Stop();

    boost::asio::ip::tcp::socket & Sock()  { return sock_;}

private:
    void OnRead(const error_code & err, size_t bytes);
    void OnWrite(const error_code &err, size_t bytes);
    void DoRead();
    void DoWrite(const std::string & msg);
    size_t HandleReadComplete(const boost::system::error_code & err, size_t bytes);

private:
    boost::asio::ip::tcp::socket sock_;
    enum { max_msg = 1024 };
    char read_buffer_[max_msg];
    char write_buffer_[max_msg];
    bool started_;

	//logic link
	KTPLL ktpll_;
};

#endif // TALK_TO_CLIENT

