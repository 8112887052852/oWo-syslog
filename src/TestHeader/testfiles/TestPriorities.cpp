/*!
 * \file    TestPriorities.cpp
 * \author  8112887052852
 * \brief   Test for the log_priorities enum and helper functions|macros
 */

#include "TestHelpers.h"

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

    template<log_priorities pri, log_facilities first, log_facilities second, log_facilities... next>
    void test_make_pri_for_pri()
    {
        test_make_pri_for_pri<pri, first>();
        test_make_pri_for_pri<pri, second, next...>();
    }

    template <log_priorities pri, log_facilities fac>
    void test_make_pri_for_pri()
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
     * \tparam  pri The priority to test against
     */
    template<log_priorities pri>
    void test_make_pri()
    {
        test_make_pri_for_pri<pri, FACILITIES>();
    }

    /*!
     * \brief   Method to assert that LOG_MAKEPRI(pri, _)... results in (pri & _)...
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
    test_log_pri<PRIORITIES>();
}

TEST_F(test_log_priorities, LOG_MAKEPRI)
{
    test_make_pri<PRIORITIES>();
}