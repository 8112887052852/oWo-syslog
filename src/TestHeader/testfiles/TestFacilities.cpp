/*!
 * \file    TestPriorities.cpp
 * \author  8112887052852
 * \brief   Test for the log_facilities enum and helper functions|macros
 */

#include "TestHelpers.h"

#include <gtest/gtest.h>
#include <oWoSyslog.h>

#ifdef _MODERN_OWO_SYSLOG_
using namespace syslog;
#endif

/*!
 * \brief   Fixture for tests on the log_facilities enum
 */
struct test_log_facilities : public ::testing::Test
{
    /*!
     * \brief   Method to assert that LOG_TRUEFAC(fac) results in fac
     * \tparam  fac The facility to test against
     */
    template<log_facilities fac>
    void test_log_fac()
    #ifdef _MODERN_OWO_SYSLOG_
    {
        EXPECT_EQ(::syslog::fac(static_cast<uint8_t>(fac)), fac);
    }

    #else
    {
        EXPECT_EQ(LOG_TRUEFAC(fac), fac);
    }
    #endif

    /*!
     * \brief   Method to assert that LOG_TRUEFAC(fac)... results in fac...
     */
    template<log_facilities first, log_facilities second, log_facilities... next>
    void test_log_fac()
    {
        test_log_fac<first>();
        test_log_fac<second, next...>();
    }

    /*!
     * \brief   Method to assert that LOG_MAKEPRI(_, fac) results in _ & fac
     * \tparam  fac The facility to test against
     */
    template<log_facilities fac, log_priorities pri>
    void test_make_pri_for_fac()
    #ifdef _MODERN_OWO_SYSLOG_
    {
        EXPECT_EQ(::syslog::fac(make_pri(fac, pri)), fac);
    }

    #else
    {
        EXPECT_EQ(LOG_TRUEFAC(LOG_MAKEPRI(fac, pri)), fac);
    }
    #endif

    /*!
     * \brief   Method to assert that LOG_MAKEPRI(pri, fac)... results in (pri & fac)...
     * \tparam fac  The facility to tests against
     */
    template <log_facilities fac, log_priorities first, log_priorities second, log_priorities...next>
    void test_make_pri_for_fac()
    {
        test_make_pri_for_fac<fac, first>();
        test_make_pri_for_fac<fac, second, next...>();
    }

    /*!
     * \brief   Method to assert that LOG_MAKEPRI(_, fac)... results in (_ & fac)...
     */
    template<log_facilities first, log_facilities second, log_facilities... next>
    void test_make_pri()
    {
        test_make_pri<first>();
        test_make_pri<second, next...>();
    }

    /*!
     * \brief   Method to assert that LOG_MAKEPRI(_, fac) results in (_ & fac
     * \tparam fac
     */
    template<log_facilities fac>
    void test_make_pri()
    {
        test_make_pri_for_fac<fac, PRIORITIES>();
    }
};

TEST_F(test_log_facilities, LOG_FAC)
{
    test_log_fac<FACILITIES>();
}

TEST_F(test_log_facilities, MAKE_PRI)
{
    test_make_pri<FACILITIES>();
}