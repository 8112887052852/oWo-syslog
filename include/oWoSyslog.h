/*!
 * \file	oWoSyslog.h
 * \author	8112887052852
 * \brief	System header to use syslog calls from programs
 * \copyright
   Copyright (c) 2019, Tristan Roy
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright notice,
     this list of conditions and the following disclaimer in the documentation
     and/or other materials provided with the distribution.

   * Neither the name of the copyright holder nor the names of its
     contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
   SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
   CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
   OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _OWO_SYSLOG_VER
#define _OWO_SYSLOG_VER 1

#ifndef WIN32
  #define OWOSYSLOG_API
#elif defined(OWOSYSLOG_EXPORT)
  #define OWOSYSLOG_API __declspec(dllexport)
#else
  #define OWOSYSLOG_API __declspec(dllimport)
#endif // not WIN32

#ifdef __cplusplus
  #include <cstdarg>
  #include <cstdint>
  // Modern oWoSyslog requires at least c++14
  #if __cplusplus >= 201103L and not defined(DISABLE_MODERN_OWO_SYSLOG)
    #define _MODERN_OWO_SYSLOG_
  #endif // __cplusplus >= 201103L and not defined(DISABLE_MODERN_OWO_SYSLOG)
#else
  #include <stdarg.h>
  #include <stdint.h>
#endif // __cplusplus

#ifdef _MODERN_OWO_SYSLOG_
  namespace syslog
  {
#endif

  /*!
   * \brief   enum for priority codes
   */
  enum
  #ifdef _MODERN_OWO_SYSLOG_
    class
  #endif // _MODERN_OWO_SYSLOG_
  log_priorities
  #ifdef _MODERN_OWO_SYSLOG_
                 : uint8_t
  #endif // _MODERN_OWO_SYSLOG_
  {
  #ifndef _MODERN_OWO_SYSLOG_
    // use the old syslog header `standard` for retro compatibility
    LOG_EMERG = 0,
    LOG_ALERT = 1,
    LOG_CRIT = 2,
    LOG_ERR = 3,
    LOG_WARNING = 4,
    LOG_NOTICE = 5,
    LOG_INFO = 6,
    LOG_DEBUG = 7
  #else
    // use a scoped-enum style
    emerg = 0,
    alert = 1,
    crit = 2,
    err = 3,
    warning = 4,
    notice = 5,
    info = 6,
    debug = 7
  #endif // not _MODERN_OWO_SYSLOG_
  };

  enum
  #ifdef _MODERN_OWO_SYSLOG_
    class
  #endif // _MODERN_OWO_SYSLOG_
  log_facilities
  #ifdef _MODERN_OWO_SYSLOG_
                 : uint8_t
  #endif // _MODERN_OWO_SYSLOG_
  {
  #ifndef _MODERN_OWO_SYSLOG_
    // use the old syslog header `standard` for retro compatibility
    LOG_KERN = 0,
    LOG_USER = 1 << 3,
    LOG_MAIL = 2 << 3,
    LOG_DAEMON = 3 << 3,
    LOG_AUTH = 4 << 3,
    LOG_SYSLOG = 5 << 3,
    LOG_LPR = 6 << 3,
    LOG_NEWS = 7 << 3,
    LOG_UUCP = 8 << 3,
    LOG_CRON = 9 << 3,
    LOG_AUTHPRIV = 10 << 3,
    LOG_FTP = 11 << 3,
    /* [12...15] are reserved codes */
    LOG_LOCAL0 = 16 << 3,
    LOG_LOCAL1 = 17 << 3,
    LOG_LOCAL2 = 18 << 3,
    LOG_LOCAL3 = 19 << 3,
    LOG_LOCAL4 = 20 << 3,
    LOG_LOCAL5 = 21 << 3,
    LOG_LOCAL6 = 22 << 3,
    LOG_LOCAL7 = 23 << 3
  #else
    // use a more modern style
    kern = 0,
    user = 1 << 3,
    mail = 2 << 3,
    daemon = 3 << 3,
    auth = 4 << 3,
    syslog = 5 << 3,
    lpr = 6 << 3,
    news = 7 << 3,
    uucp = 8 << 3,
    cron = 9 << 3,
    auth_priv = 10 << 3,
    ftp = 11 << 3,
    /* [12...15] are reserved codes */
    local0 = 16 << 3,
    local1 = 17 << 3,
    local2 = 18 << 3,
    local3 = 19 << 3,
    local4 = 20 << 3,
    local5 = 21 << 3,
    local6 = 22 << 3,
    local7 = 23 << 3
  #endif // not _MODERN_OWO_SYSLOG_
  };

  #ifndef _MODERN_OWO_SYSLOG_
    #define LOG_PRI(pri) (pri & 0x7)
  #else

    constexpr log_priorities pri(uint8_t num) noexcept
    {
      return static_cast<log_priorities>(num bitand 7);
    }

  #endif // not _MODERN_OWO_SYSLOG_

  #ifndef _MODERN_OWO_SYSLOG_
    #define LOG_MAKEPRI(fac, pri) (fac | pri)
  #else

    constexpr uint8_t make_pri(const log_facilities fac, const log_priorities pri) noexcept
    {
      return static_cast<uint8_t>(fac) bitor static_cast<uint8_t>(pri);
    }

  #endif // not _MODERN_OWO_SYSLOG_

  #ifndef _MODERN_OWO_SYSLOG_
    /* The default header in many distros defines a weird LOG_FAC macro
       LOG_TRUEFAC will give the correct facility value, with the original shift */
    #define LOG_TRUEFAC(pri) (pri & 0xF8)
    #define LOG_FAC(pri) (LOG_TRUEFAC(pri) >> 3)
  #else

  constexpr log_facilities fac(const uint8_t pri) noexcept
  {
    return static_cast<log_facilities>(pri & 0xF8);
  }

  #endif // not _MODERN_OWO_SYSLOG_

  #ifdef SYSLOG_NAMES
    #ifdef _MODERN_OWO_SYSLOG_
    #else

      typedef struct _code {
        char *c_name;
        int c_val;
      } CODE;

      CODE prioritynames[] = {
        {"alert", LOG_ALERT},
        {"crit", LOG_CRIT},
        {"debug", LOG_DEBUG},
        {"emerg", LOG_EMERG},
        {"err", LOG_ERR},
        {"error", LOG_ERR},
        {"info", LOG_INFO},
        {"notice", LOG_NOTICE},
        {"panic", LOG_EMERG},
        {"warn", LOG_WARNING},
        {"warning", LOG_WARNING},
        {0,-1}
      };

      CODE facilitynames[] = {
        {"auth", LOG_AUTH},
        {"authpriv", LOG_AUTHPRIV},
        {"cron", LOG_CRON},
        {"daemon", LOG_DAEMON},
        {"ftp", LOG_FTP},
        {"kern", LOG_KERN},
        {"lpr", LOG_LPR},
        {"mail", LOG_MAIL},
        {"news", LOG_NEWS},
        {"security", LOG_AUTH},
        {"syslog", LOG_SYSLOG},
        {"user", LOG_USER},
        {"uucp", LOG_UUCP},
        {"local0", LOG_LOCAL0},
        {"local1", LOG_LOCAL1},
        {"local2", LOG_LOCAL2},
        {"local3", LOG_LOCAL3},
        {"local4", LOG_LOCAL4},
        {"local5", LOG_LOCAL5},
        {"local6", LOG_LOCAL6},
        {"local7", LOG_LOCAL7},
        {0, -1}
      };
    #endif // _MODERN_OWO_SYSLOG_
  #endif // SYSLOG_NAMES

#ifdef _MODERN_OWO_SYSLOG_
}
#endif

#ifdef _MODERN_OWO_SYSLOG_
  #define _SYSLOG_NAMESPACE ::syslog::
  #define _NO_THROW noexcept
  #else
  #define _SYSLOG_NAMESPACE
  #define _NO_THROW __THROW
#endif

#ifdef _MODERN_OWO_SYSLOG_
namespace syslog
{
#endif // _MODERN_OWO_SYSLOG_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

  OWOSYSLOG_API extern void closelog(void);

  OWOSYSLOG_API extern void openlog(const char* ident, int option, _SYSLOG_NAMESPACE log_facilities fac);

  OWOSYSLOG_API extern void setlogmask(uint8_t mask) _NO_THROW;

  OWOSYSLOG_API extern void syslog(_SYSLOG_NAMESPACE log_priorities pri, const char* fmt, ...)
  //TODO: Check format for Windows platform
  __attribute__ ((__format__ (__printf__, 2, 3)));

  OWOSYSLOG_API extern void vsyslog(_SYSLOG_NAMESPACE log_priorities pri, const char* fmt, __gnuc_va_list ap)
  //TODO: Check format for Windows platform
  __attribute__ ((__format__ (__printf__, 2, 0)));

#ifdef __cplusplus
}
#endif // __cplusplus

#ifdef _MODERN_OWO_SYSLOG_
}
#endif // _MODERN_OWO_SYSLOG_

#endif // _OWO_SYSLOG_VER
