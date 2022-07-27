#include "sysml.hpp"
#define BOOST_TEST_MODULE Simple testcases 1
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(suite1)

BOOST_AUTO_TEST_CASE(test1) {
    BOOST_CHECK_EQUAL(0, ParseFile("TESTPATH"));
}

BOOST_AUTO_TEST_SUITE_END()
