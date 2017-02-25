/************************************************* 
Author: candy_pz
Email: candy_pz@outlook.com
FileName: Logger.h
Date: 2016-11-19
Description: logger
**************************************************/

#ifndef LOGGER_H_
#define LOGGER_H_

#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/attributes/timer.hpp>
#include <boost/log/attributes/named_scope.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/support/date_time.hpp>

namespace Log {
    enum severity_levels
    {
        log_emergency = 0,                //log_emerg
        log_alert     = 1,                //log_alert
        log_critical  = 2,                //log_crit
        log_error     = 3,                //log_error 大于log_error的log不会在console显示 并且不会马上写入文件
        log_warning   = 4,                //log_warning
        log_notice    = 5,                //log_notice
        log_info      = 6,                //log_info
        log_debug     = 7                 //log_debug
    };

    class CLogger {
    public:
        ~CLogger();
        static boost::log::sources::severity_logger<severity_levels> mylog;
        static void initLog(const char *filename);
        static void setLevel(severity_levels level);
    private:
        CLogger();
    };


#define BOOST_MYLOG(log_lvl) BOOST_LOG_FUNCTION();BOOST_LOG_SEV(Log::CLogger::mylog, log_lvl)

#define LOG_EMERGENCY BOOST_MYLOG(Log::log_emergency)
#define LOG_ALERT BOOST_MYLOG(Log::log_alert)
#define LOG_CRITICAL BOOST_MYLOG(Log::log_critical)
#define LOG_ERROR BOOST_MYLOG(Log::log_error)
#define LOG_WARNING BOOST_MYLOG(Log::log_warning)
#define LOG_NOTICE BOOST_MYLOG(Log::log_notice)
#define LOG_INFO BOOST_MYLOG(Log::log_info)
#define LOG_DEBUG BOOST_MYLOG(Log::log_debug)

};

#endif // LOGGER_H_