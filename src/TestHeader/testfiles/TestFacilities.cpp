/*!
 * \file    TestPriorities.cpp
 * \author  8112887052852
 * \brief   Test for the log_facilities enum and helper functions|macros
 */

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
    template<log_facilities fac>
    void test_make_pri(log_priorities pri =
    #ifdef _MODERN_OWO_SYSLOG_
    log_priorities::debug
    #else
            LOG_DEBUG
    #endif
    )
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
     * \brief   Method to assert that LOG_MAKEPRI(_, fac)... results in (_ & fac)...
     */
    template<log_facilities first, log_facilities second, log_facilities... next>
    void test_make_pri(log_priorities pri =
    #ifdef _MODERN_OWO_SYSLOG_
    log_priorities::debug
    #else
            LOG_DEBUG
    #endif
    )
    {
        test_make_pri<first>(pri);
        test_make_pri<second, next...>(pri);
    }
};

TEST_F(test_log_facilities, LOG_FAC)
{
    test_log_fac<
    #ifdef _MODERN_OWO_SYSLOG_
            log_facilities::kern,
            log_facilities::user,
            log_facilities::mail,
            log_facilities::daemon,
            log_facilities::auth,
            log_facilities::syslog,
            log_facilities::lpr,
            log_facilities::news,
            log_facilities::uucp,
            log_facilities::cron,
            log_facilities::auth_priv,
            log_facilities::ftp
    #else
    LOG_KERN,
    LOG_USER,
    LOG_MAIL,
    LOG_DAEMON,
    LOG_AUTH,
    LOG_SYSLOG,
    LOG_LPR,
    LOG_NEWS,
    LOG_UUCP,
    LOG_CRON,
    LOG_AUTHPRIV,
    LOG_FTP
    #endif
    >();
}

TEST_F(test_log_facilities, MAKE_PRI)
{
    test_make_pri<
    #ifdef _MODERN_OWO_SYSLOG_
            log_facilities::kern,
            log_facilities::user,
            log_facilities::mail,
            log_facilities::daemon,
            log_facilities::auth,
            log_facilities::syslog,
            log_facilities::lpr,
            log_facilities::news,
            log_facilities::uucp,
            log_facilities::cron,
            log_facilities::auth_priv,
            log_facilities::ftp
    #else
    LOG_KERN,
            LOG_USER,
            LOG_MAIL,
            LOG_DAEMON,
            LOG_AUTH,
            LOG_SYSLOG,
            LOG_LPR,
            LOG_NEWS,
            LOG_UUCP,
            LOG_CRON,
            LOG_AUTHPRIV,
            LOG_FTP
    #endif
    >();
}