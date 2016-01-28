#include <Talk2Client.h>

using namespace boost::asio;
using namespace boost::posix_time;

Talk2Client::Talk2Client(boost::asio::io_service& service)
    :sock_(service), started_(false)
{}


void Talk2Client::Start()
{
    started_ = true;
    DoRead();
}

Talk2Client::ptr Talk2Client::MakeClient(boost::asio::io_service& service)
{
	Talk2Client::ptr new_client( new Talk2Client(service) );
    return new_client;
}

void Talk2Client::Stop()
{
    if (!started_) return ;
    started_ = false;
    sock_.close();
}


void Talk2Client::OnRead(const error_code & err, size_t bytes)
{
    if (!err)
    {
        std::string msg(read_buffer_, bytes);
        DoWrite(msg + "\n");
    }
    Stop();
}

void Talk2Client::OnWrite(const error_code &err, size_t bytes)
{
	// signal next reading operation 
    DoRead();
}

void Talk2Client::DoRead()
{
    async_read(sock_, buffer(read_buffer_),
              MEM_FN2(HandleReadComplete, _1, _2), MEM_FN2(OnRead, _1, _2));
}

void Talk2Client::DoWrite(const std::string & msg)
{
//    std::cout << "Server Echo " << msg  << std::endl;
    std::copy(msg.begin(), msg.end(), write_buffer_);
    sock_.async_write_some(buffer(write_buffer_,msg.size()),
                           MEM_FN2(OnWrite, _1, _2));
}

size_t Talk2Client::HandleReadComplete(const boost::system::error_code & err, size_t bytes)
{
       if ( err) return 0;
	   size_t begin, end;
	   bool found = ktpll_.Parser(read_buffer_, bytes, begin, end);
//       bool found = std::find(read_buffer_, read_buffer_ + bytes, '\n') < read_buffer_ + bytes;
       // we read one-by-one until we get to enter, no buffering
       return found ? 0 : 1;
}
