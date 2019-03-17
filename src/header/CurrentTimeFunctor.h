/*!
 * \file    CurrentTimeFunctor.h
 * \author  8112887052852
 * \brief   Declaration of the CurrentTime functor, which formats the system time
 *          to the syslog:RFC5424 format and reuses the same buffer for each calls
 */

#pragma once

#include <sstream>
#include <string>

namespace owo
{
    namespace time
    {
        /*!
         * \brief   A functor to get the current system time in ISO notation
         */
        class CurrentTimeFunctor
        {
        public:
            // if it throws on std::string(), we are fucked anyway
            CurrentTimeFunctor() noexcept;

            using buffer_type = std::ostringstream;

            /*!
             * \brief   Function to get the timestamp string
             * \return  The timestamp string
             */
            std::string operator()();

        private:
            buffer_type m_buf;
        };
    }
}


