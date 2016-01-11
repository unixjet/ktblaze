#include <QCoreApplication>
#include <iostream>
#include <talk_to_client.h>
#include "XlsReader.h"
#include "logger.hpp"


boost::asio::io_service service;

boost::asio::ip::tcp::acceptor acceptor(service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 8001));

static void handle_accept(talk_to_client::ptr client, const boost::system::error_code & err)
{
    client->start();
    talk_to_client::ptr new_client = talk_to_client::make_client(service);
    acceptor.async_accept(new_client->sock(), boost::bind(handle_accept, new_client, _1));
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

#if 0
    std::cout << "Server Run" << std::endl;
    talk_to_client::ptr client = talk_to_client::make_client(service);
    acceptor.async_accept(client->sock(), boost::bind(handle_accept, client, _1));
    service.run();
#endif

    logger lg;
    lg.start();

    // And output...
    BOOST_LOG(lg.get_logger()) << "Hello, World!";

    // Now, let's try logging with severity
    boost::log::sources::severity_logger<severity_level> slg(lg.get_severitylog());

    // Let's pretend we also want to profile our code, so add a special timer attribute.
    slg.add_attribute("Uptime", attrs::timer());

    BOOST_LOG_SEV(slg, normal) << "A normal severity message, will not pass to the file";
    BOOST_LOG_SEV(slg, warning) << "A warning severity message, will pass to the file";
    BOOST_LOG_SEV(slg, error) << "An error severity message, will pass to the file";

#if 1
    std::string file = std::string("E:\\mgzhou\\WorkSpace\\Project\\ktblaze\\res\\files\\KT protocols.xls");
    xls::WorkBook foo(file,0);

    xls::cellContent cell = foo.GetCell(0,1,2);
    foo.ShowCell(cell);

    foo.InitIterator(0);

    while(true)
    {
        xls::cellContent c = foo.GetNextCell();
        if(c.type == xls::cellBlank) break;
        foo.ShowCell(c);
    }
    std::cout << "parser done!" << std::endl;
#endif
//    service.run(); // and applicataion loop
    a.exit(0);
    return 0;
//    return a.exec();
}
