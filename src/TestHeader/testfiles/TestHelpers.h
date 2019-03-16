#pragma once

#include <oWoSyslog.h>

#ifdef _MODERN_OWO_SYSLOG_
#define FACILITIES \
_SYSLOG_NAMESPACE log_facilities::kern, \
_SYSLOG_NAMESPACE log_facilities::user, \
_SYSLOG_NAMESPACE log_facilities::mail, \
_SYSLOG_NAMESPACE log_facilities::daemon, \
_SYSLOG_NAMESPACE log_facilities::auth, \
_SYSLOG_NAMESPACE log_facilities::syslog, \
_SYSLOG_NAMESPACE log_facilities::lpr, \
_SYSLOG_NAMESPACE log_facilities::news, \
_SYSLOG_NAMESPACE log_facilities::uucp, \
_SYSLOG_NAMESPACE log_facilities::cron, \
_SYSLOG_NAMESPACE log_facilities::auth_priv, \
_SYSLOG_NAMESPACE log_facilities::ftp, \
_SYSLOG_NAMESPACE log_facilities::local0, \
_SYSLOG_NAMESPACE log_facilities::local1, \
_SYSLOG_NAMESPACE log_facilities::local2, \
_SYSLOG_NAMESPACE log_facilities::local3, \
_SYSLOG_NAMESPACE log_facilities::local4, \
_SYSLOG_NAMESPACE log_facilities::local5, \
_SYSLOG_NAMESPACE log_facilities::local6, \
_SYSLOG_NAMESPACE log_facilities::local7
#else
#define FACILITIES \
LOG_KERN, \
LOG_USER, \
LOG_MAIL, \
LOG_DAEMON, \
LOG_AUTH, \
LOG_SYSLOG, \
LOG_LPR, \
LOG_NEWS, \
LOG_UUCP, \
LOG_CRON, \
LOG_AUTHPRIV, \
LOG_FTP, \
LOG_LOCAL0, \
LOG_LOCAL1, \
LOG_LOCAL2, \
LOG_LOCAL3, \
LOG_LOCAL4, \
LOG_LOCAL5, \
LOG_LOCAL6, \
LOG_LOCAL7
#endif

#ifdef _MODERN_OWO_SYSLOG_
#define PRIORITIES \
_SYSLOG_NAMESPACE log_priorities::emerg, \
_SYSLOG_NAMESPACE log_priorities::alert, \
_SYSLOG_NAMESPACE log_priorities::crit, \
_SYSLOG_NAMESPACE log_priorities::err, \
_SYSLOG_NAMESPACE log_priorities::warning, \
_SYSLOG_NAMESPACE log_priorities::notice, \
_SYSLOG_NAMESPACE log_priorities::info, \
_SYSLOG_NAMESPACE log_priorities::debug
#else
#define PRIORITIES \
LOG_EMERG \
LOG_ALERT \
LOG_CRIT \
LOG_ERR \
LOG_WARNING \
LOG_NOTICE \
LOG_INFO \
LOG_DEBUG
#endif
