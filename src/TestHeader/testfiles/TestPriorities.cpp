/*!
 * \file    TestPriorities.cpp
 * \author  8112887052852
 * \brief   Test for the log_priorities enum and helper functions|macros
 */

#include <gtest/gtest.h>
#include <oWoSyslog.h>

#ifdef _MODERN_OWO_SYSLOG_
using syslog::log_facilities;
using syslog::log_priorities;
using syslog::make_pri;
using syslog::pri;
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
    template<log_priorities pri, log_facilities fac
    #ifdef _MODERN_OWO_SYSLOG_
    = syslog::log_facilities::syslog
    #else
            = LOG_SYSLOG
    #endif
    >
    void test_make_pri()
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
     * \brief   Method to assert that LOG_MAKEPRI(pri, _) results in pri & _
     * \tparam first
     * \tparam second
     * \tparam next
     */
    template<log_priorities first, log_priorities second, log_priorities... next>
    void test_make_pri()
    {
        test_make_pri<first>();
        test_make_pri<second, next...>();
    }
};

TEST_F(test_log_priorities, LOG_PRI)
{
    #ifdef _MODERN_OWO_SYSLOG_
    test_log_pri<
            log_priorities::emerg,
            log_priorities::alert,
            log_priorities::crit,
            log_priorities::err,
            log_priorities::warning,
            log_priorities::notice,
            log_priorities::info,
            log_priorities::debug
    >();
    #else
    test_log_pri<
            LOG_EMERG,
            LOG_ALERT,
            LOG_CRIT,
            LOG_ERR,
            LOG_WARNING,
            LOG_NOTICE,
            LOG_INFO,
            LOG_DEBUG
    >();
    #endif
}

TEST_F(test_log_priorities, LOG_MAKEPRI)
{
    #ifdef _MODERN_OWO_SYSLOG_
    test_make_pri<
            log_priorities::emerg,
            log_priorities::alert,
            log_priorities::crit,
            log_priorities::err,
            log_priorities::warning,
            log_priorities::notice,
            log_priorities::info,
            log_priorities::debug
    >();
    #else
    test_make_pri<
            LOG_EMERG,
            LOG_ALERT,
            LOG_CRIT,
            LOG_ERR,
            LOG_WARNING,
            LOG_NOTICE,
            LOG_INFO,
            LOG_DEBUG
    >();
    #endif
}