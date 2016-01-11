#include <talk_to_client.h>

using namespace boost::asio;
using namespace boost::posix_time;

talk_to_client::talk_to_client(boost::asio::io_service& service)
    :sock_(service), started_(false)
{}


void talk_to_client::start()
{
    started_ = true;
    do_read();
}

talk_to_client::ptr talk_to_client::make_client(boost::asio::io_service& service)
{
    talk_to_client::ptr new_client( new talk_to_client(service) );
    return new_client;
}

void talk_to_client::stop()
{
    if (!started_) return ;
    started_ = false;
    sock_.close();
}


void talk_to_client::on_read(const error_code & err, size_t bytes)
{
    if (!err)
    {
        std::string msg(read_buffer_, bytes);
        do_write(msg + "\n");
    }
    stop();
}

void talk_to_client::on_write(const error_code &err, size_t bytes)
{
    do_read();
}

void talk_to_client::do_read()
{
    async_read(sock_, buffer(read_buffer_),
              MEM_FN2(read_complete, _1, _2), MEM_FN2(on_read, _1, _2));
}

void talk_to_client::do_write(const std::string & msg)
{
//    std::cout << "Server Echo " << msg  << std::endl;
    std::copy(msg.begin(), msg.end(), write_buffer_);
    sock_.async_write_some(buffer(write_buffer_,msg.size()),
                           MEM_FN2(on_write, _1, _2));
}

size_t talk_to_client::read_complete(const boost::system::error_code & err, size_t bytes)
{
       if ( err) return 0;
       bool found = std::find(read_buffer_, read_buffer_ + bytes, '\n') < read_buffer_ + bytes;
       // we read one-by-one until we get to enter, no buffering
       return found ? 0 : 1;
}
