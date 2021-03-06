#include "Logger.h"

#include <stdexcept>
#include <iostream>

using namespace Log;
using namespace boost;

namespace logging = boost::log;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace expr = boost::log::expressions;
namespace keywords = boost::log::keywords;

boost::log::sources::severity_logger<severity_levels> CLogger::mylog;

template< typename CharT, typename TraitsT >
inline std::basic_ostream< CharT, TraitsT >& operator<< (
    std::basic_ostream< CharT, TraitsT >& strm, severity_levels lvl) {
    static const char* const str[] =
    {
        "emergency",
        "alert",
        "critical",
        "error",
        "warning",
        "notice",
        "info",
        "debug"
    };
    if (static_cast<std::size_t>(lvl) < (sizeof(str) / sizeof(*str)))
        strm << str[lvl];
    else
        strm << static_cast<int>(lvl);
    return strm;
};

BOOST_LOG_ATTRIBUTE_KEYWORD(_severity, "Severity", severity_levels);
BOOST_LOG_ATTRIBUTE_KEYWORD(_timestamp, "TimeStamp", boost::posix_time::ptime);
BOOST_LOG_ATTRIBUTE_KEYWORD(_uptime, "Uptime", attrs::timer::value_type);
BOOST_LOG_ATTRIBUTE_KEYWORD(_scope, "Scope", attrs::named_scope::value_type);

CLogger::CLogger() {

}

CLogger::~CLogger() {

}

void CLogger::initLog(const char *filename) {
    auto asink = logging::add_console_log(std::clog, keywords::format = expr::stream
        << expr::format_date_time(_timestamp, "[%Y-%m-%d,%H:%M:%S.%f]")
        << " <" << _severity
        << ">: " << expr::message);

    asink->set_filter(expr::attr< severity_levels >("Severity") <= log_error);

    logging::core::get()->add_sink(asink);

    for (int i = log_emergency; i <= log_debug; i++) {
        std::stringstream allfilename;
        allfilename << "logs\\" << filename << "_" << (severity_levels)i << "_%Y%m%d_%H%M%S.log";
        auto sink = logging::add_file_log(
            keywords::file_name = allfilename.str(),
            keywords::rotation_size = 10 * 1024 * 1024,
            keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
            keywords::open_mode = std::ios::app,
            keywords::auto_flush = false
        );


        sink->locked_backend()->set_file_collector(sinks::file::make_collector(
            keywords::target = "logs",
            keywords::max_size = 30 * 1024 * 1024,
            keywords::min_free_space = 100 * 1024 * 1024
        ));

        sink->locked_backend()->scan_for_files();

        if (i <= log_error) {
            sink->locked_backend()->auto_flush();
        }

        sink->set_filter(expr::attr< severity_levels >("Severity") == (severity_levels)i);

        sink->set_formatter
        (
            expr::format("(%1%)<%2%_%3%>{%4%}:\n%5%")
            % expr::attr< attrs::current_thread_id::value_type >("ThreadID")
            % expr::format_date_time(_timestamp, "%Y-%m-%d,%H:%M:%S.%f")
            % expr::attr< boost::posix_time::time_duration >("Uptime")
            % expr::format_named_scope(_scope, keywords::format = "%n[%f:%l]", keywords::depth = 1)
            % expr::smessage
        );

        logging::core::get()->add_sink(sink);
    }

    logging::add_common_attributes();
    logging::core::get()->add_thread_attribute("Scope", attrs::named_scope());
    logging::core::get()->add_thread_attribute("Uptime", attrs::timer());
}

void CLogger::setLevel(severity_levels level) {
    logging::core::get()->set_filter(expr::attr< severity_levels >("Severity") <= level);
}