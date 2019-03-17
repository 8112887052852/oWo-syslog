/*!
 * \file    CurrentTimeFunctor.cpp
 * \author  8112887052852
 * \brief   Implementation of the CurrentTime functor
 */

#include "CurrentTimeFunctor.h"

#include <chrono>
#include <iomanip>

using owo::time::CurrentTimeFunctor;

/*!
 * \brief   Constructor for the functor
 *          Buffer space is already reserved for future uses.
 */
CurrentTimeFunctor::CurrentTimeFunctor() noexcept
: m_buf([]{
    std::string s;
    s.reserve(sizeof("2019-03-17T21:18:34+00:00"));
    return s;}())
{
}

/*!
 * \brief   Operator to get the current time using the syslog:RFC5424 format
 *          The buffer pointer is set back to 0 to permit the reuse of the
 *          same buffer space.
 * \return  A copy of the buffer string
 */
std::string CurrentTimeFunctor::operator()()
{
    using std::chrono::system_clock;
    const auto& l_now = system_clock::now();
    const auto& l_now_tt = system_clock::to_time_t(l_now);
    const auto& l_gm_now_tt = gmtime(&l_now_tt);

    m_buf << std::put_time(l_gm_now_tt, "%FT%T");

    // syslog:5424 does not use a real iso format, so we need to format the rest by hand
    if(l_gm_now_tt->tm_isdst)
    {
        m_buf << std::setfill('0') << (l_gm_now_tt->tm_isdst < 0 ? '-': '+') << std::setw(2) << l_gm_now_tt->tm_isdst / 100 << ":" << std::setw(2) << l_gm_now_tt->tm_isdst % 100;
    }
    else
    {
        // fill the rest with null chars to prevent weird stuff on tm_isdst changes
        m_buf << "Z\0\0\0\0\0";
    }

    // resets the buffer position to index 0 for next call
    m_buf.seekp(0);
    //return a copy of the buffer
    return m_buf.str();
}