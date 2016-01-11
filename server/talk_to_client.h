#ifndef TALK_TO_CLIENT
#define TALK_TO_CLIENT


#include <boost/function.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>


#define MEM_FN(x)      boost::bind(&self_type::x, shared_from_this())
#define MEM_FN1(x,y)   boost::bind(&self_type::x, shared_from_this(),y)
#define MEM_FN2(x,y,z) boost::bind(&self_type::x, shared_from_this(), y, z)

class talk_to_client : public boost::enable_shared_from_this<talk_to_client>, boost::noncopyable
{
    typedef talk_to_client self_type;
    talk_to_client(boost::asio::io_service & service);

public:
    typedef boost::system::error_code error_code;
    typedef boost::shared_ptr<talk_to_client> ptr;

    void start();
    static ptr make_client(boost::asio::io_service & service);
    void stop();

    boost::asio::ip::tcp::socket & sock()  { return sock_;}

private:
    void on_read(const error_code & err, size_t bytes);
    void on_write(const error_code &err, size_t bytes);
    void do_read();
    void do_write(const std::string & msg);
    size_t read_complete(const boost::system::error_code & err, size_t bytes);

private:
    boost::asio::ip::tcp::socket sock_;
    enum { max_msg = 1024 };
    char read_buffer_[max_msg];
    char write_buffer_[max_msg];
    bool started_;
};

#endif // TALK_TO_CLIENT

