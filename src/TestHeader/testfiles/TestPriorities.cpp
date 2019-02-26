/*!
 * \file    TestPriorities.cpp
 * \author  8112887052852
 * \brief   Test for the log_priorities enum and helper functions|macros
 */

#include <gtest/gtest.h>
#include <oWoSyslog.h>

#ifdef _MODERN_OWO_SYSLOG_
using namespace syslog;
#endif

/*!
 * \brief   Fixture for tests on the log_priorities enum
 */
struct test_log_priorities : public ::testing::Test
{
    /*!
     * \brief   Method to assert that LOG_PRI(pri) results in pri
     * \tparam  pri The priority to test against
     */
    template<log_priorities pri>
    void test_log_pri()
    #ifdef _MODERN_OWO_SYSLOG_
    {
        EXPECT_EQ(::syslog::pri(static_cast<uint8_t>(pri)), pri);
    }

    #else
    {
        EXPECT_EQ(LOG_PRI(pri), pri);
    }
    #endif

    /*!
     * \brief   Method to assert that LOG_PRI(pri)... results in pri...
     */
    template<log_priorities first, log_priorities second, log_priorities... next>
    void test_log_pri()
    {
        test_log_pri<first>();
        test_log_pri<second, next...>();
    }

    /*!
     * \brief   Method to assert that LOG_MAKEPRI(pri, _) results in pri & _
     * \tparam  pri The priority to test against
     */
    template<log_priorities pri>
    void test_make_pri(log_facilities fac =
    #ifdef _MODERN_OWO_SYSLOG_
    log_facilities::ftp
    #else
            LOG_SYSLOG
    #endif
    )
    #ifdef _MODERN_OWO_SYSLOG_
    {
        EXPECT_EQ(::syslog::pri(make_pri(fac, pri)), pri);
    }

    #else
    {
        EXPECT_EQ(LOG_PRI(LOG_MAKEPRI(fac, pri)), pri);
    }
    #endif

    /*!
     * \brief   Method to assert that LOG_MAKEPRI(pri, _)... results in (pri & _)...
     */
    template<log_priorities first, log_priorities second, log_priorities... next>
    void test_make_pri(log_facilities fac
    #ifdef _MODERN_OWO_SYSLOG_
    = log_facilities::ftp
    #else
            = LOG_SYSLOG
    #endif
    )
    {
        test_make_pri<first>(fac);
        test_make_pri<second, next...>(fac);
    }
};

TEST_F(test_log_priorities, LOG_PRI)
{
    test_log_pri<
    #ifdef _MODERN_OWO_SYSLOG_
            log_priorities::emerg,
            log_priorities::alert,
            log_priorities::crit,
            log_priorities::err,
            log_priorities::warning,
            log_priorities::notice,
            log_priorities::info,
            log_priorities::debug
    #else
            LOG_EMERG,
            LOG_ALERT,
            LOG_CRIT,
            LOG_ERR,
            LOG_WARNING,
            LOG_NOTICE,
            LOG_INFO,
            LOG_DEBUG

    #endif
    >();
}

TEST_F(test_log_priorities, LOG_MAKEPRI)
{
    test_make_pri<
    #ifdef _MODERN_OWO_SYSLOG_
            log_priorities::emerg,
            log_priorities::alert,
            log_priorities::crit,
            log_priorities::err,
            log_priorities::warning,
            log_priorities::notice,
            log_priorities::info,
            log_priorities::debug
    #else
            LOG_EMERG,
            LOG_ALERT,
            LOG_CRIT,
            LOG_ERR,
            LOG_WARNING,
            LOG_NOTICE,
            LOG_INFO,
            LOG_DEBUG
    #endif
    >();
}