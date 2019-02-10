/*!
 * \file	main.cpp
 * \author	8112887052852
 * \brief	Tests for liboWoSyslog
 */

#include <gtest/gtest.h>

/*!
 * \brief	Main test function
 */
int main(const int argc, char const * const * const argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

