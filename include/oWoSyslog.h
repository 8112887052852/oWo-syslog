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

#ifdef __cplusplus
#include <cstdarg>
#else
#include <stdarg.h>
#endif

#ifdef __cplusplus
#if __cplusplus >= 201103L and not defined(DISABLE_MODERN_OWO_SYSLOG)
#define _MODERN_OWO_SYSLOG_
#include <cstdint>
#endif // __cplusplus >= 201103L and not defined(DISABLE_MODERN_OWO_SYSLOG)
#endif // __cplusplus

enum
#ifdef _MODERN_OWO_SYSLOG_
class
#endif // _MODERN_OWO_SYSLOG_
        log_priorities
#ifdef _MODERN_OWO_SYSLOG_
        : uint8_t
#endif // _MODERN_OWO_SYSLOG_
{
    LOG_EMERG = 0,
    LOG_ALERT = 1,
    LOG_CRIT = 2,
    LOG_ERR = 3,
    LOG_WARNING = 4,
    LOG_NOTICE = 5,
    LOG_INFO = 6,
    LOG_DEBUG = 7
};

#endif // _OWO_SYSLOG_VER