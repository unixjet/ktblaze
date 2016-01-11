#ifndef LOGGER
#define LOGGER

#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/attributes/timer.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/support/date_time.hpp>

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;

enum severity_level
{
    normal,
    notification,
    warning,
    error,
    critical
};

template< typename CharT, typename TraitsT >
inline std::basic_ostream< CharT, TraitsT >& operator<<
(std::basic_ostream< CharT, TraitsT >& strm, severity_level lvl)
{
    static const char* const str[] =
    {
        "normal",
        "notification",
        "warning",
        "error",
        "critical"
    };
    if (static_cast< std::size_t >(lvl) < (sizeof(str) / sizeof(*str)))
        strm << str[lvl];
    else
        strm << static_cast< int >(lvl);
    return strm;

}

class logger
{
public:
    logger() = default ;
    ~logger() = default;

    void start()
    {
        // The first thing we have to do to get using the library is
        // to set up the logging sinks - i.e. where the logs will be written to.
        logging::add_console_log(std::clog, keywords::format = "%TimeStamp%: %Message%");

        // One can also use lambda expressions to setup filters and formatters
        logging::add_file_log
        (
            "ktblaze.log",
            keywords::filter = expr::attr< severity_level >("Severity") >= warning,
            keywords::format = expr::stream
                << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
                << " [" << expr::format_date_time< attrs::timer::value_type >("Uptime", "%O:%M:%S")
                << "] [" << expr::format_named_scope("Scope", keywords::format = "%n (%f:%l)")
                << "] <" << expr::attr< severity_level >("Severity")
                << "> " << expr::message
        /*
        keywords::format = expr::format("%1% [%2%] [%3%] <%4%> %5%")
        % expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
        % expr::format_date_time< attrs::timer::value_type >("Uptime", "%O:%M:%S")
        % expr::format_named_scope("Scope", keywords::format = "%n (%f:%l)")
        % expr::attr< severity_level >("Severity")
        % expr::message
        */
        );

        // Also let's add some commonly used attributes, like timestamp and record counter.
        logging::add_common_attributes();
        logging::core::get()->add_thread_attribute("Scope", attrs::named_scope());

    }

   void stop()
   {
       ;
   }

   src::logger& get_logger() { return lg_;}
   src::severity_logger<severity_level> & get_severitylog() { return slg_;}

private:
   src::logger lg_;
   src::severity_logger<severity_level> slg_;
};

#endif // LOGGER

