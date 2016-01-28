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

#include "Core/Object.h"
#include "Core/Context.h"

namespace logging = boost::log;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;

enum SeverityLevel
{
    normal,
    notification,
    warning,
    error,
    critical
};

template< typename CharT, typename TraitsT >
inline std::basic_ostream< CharT, TraitsT >& operator<<
(std::basic_ostream< CharT, TraitsT >& strm, SeverityLevel lvl)
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

class Logger : public  Urho3D::Object
{
    URHO3D_OBJECT(Logger, Urho3D::Object)

public:

    Logger(Urho3D::Context * context);


    ~Logger();

    void Start()
    {
        // The first thing we have to do to get using the library is
        // to set up the logging sinks - i.e. where the logs will be written to.
        logging::add_console_log(std::clog, keywords::format = "%TimeStamp%: %Message%");

        // One can also use lambda expressions to setup filters and formatters
        logging::add_file_log
        (
            "ktblaze.log",
            keywords::filter = expr::attr< SeverityLevel >("Severity") >= warning,
            keywords::format = expr::stream
                << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d, %H:%M:%S.%f")
                << " [" << expr::format_date_time< attrs::timer::value_type >("Uptime", "%O:%M:%S")
                << "] [" << expr::format_named_scope("Scope", keywords::format = "%n (%f:%l)")
                << "] <" << expr::attr< SeverityLevel >("Severity")
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

   void Stop()
   {
       ;
   }

   static src::severity_logger<SeverityLevel> & ExportLogStream();

//   src::logger& get_logger() { return lg_;}
   src::severity_logger<SeverityLevel> & GetSeverityLog() { return slg_;}

private:
   src::logger lg_;
   src::severity_logger<SeverityLevel> slg_;
};

#define LOG_NORMAL BOOST_LOG_SEV(Logger::ExportLogStream(), normal)
#define LOG_WARNING BOOST_LOG_SEV(Logger::ExportLogStream(), warning)
#define LOG_ERROR BOOST_LOG_SEV(Logger::ExportLogStream(), error)

#endif // LOGGER

