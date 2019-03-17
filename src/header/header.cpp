#include <oWoSyslog.h>

#define UNUSED(name)

void _SYSLOG_NAMESPACE closelog()
{

}

void _SYSLOG_NAMESPACE openlog(const char *const UNUSED(ident), int UNUSED(option), _SYSLOG_NAMESPACE log_facilities UNUSED(fac))
{

}

void  _SYSLOG_NAMESPACE setlogmask(uint8_t UNUSED(mask)) _NO_THROW
{

}

void _SYSLOG_NAMESPACE syslog(_SYSLOG_NAMESPACE log_priorities pri, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    _SYSLOG_NAMESPACE vsyslog(pri, fmt, args);
    va_end(args);
}

void _SYSLOG_NAMESPACE vsyslog(_SYSLOG_NAMESPACE log_priorities UNUSED(pri), const char* UNUSED(fmt), __gnuc_va_list UNUSED(ap))
{

}