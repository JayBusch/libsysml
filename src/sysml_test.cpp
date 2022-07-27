#include "sysml.hpp"
#define BOOST_TEST_MODULE Simple testcases 3
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(sysml_suite_1)

BOOST_AUTO_TEST_CASE(test_parse_file) {
    BOOST_CHECK_EQUAL(0, ParseFile("src/test_data/test_1.sysml"));
}

BOOST_AUTO_TEST_CASE(test_parse__missing_file) {
    BOOST_CHECK_EQUAL(-1, ParseFile("src/test_data/test_DOESNOTEXIST.sysml"));
}

BOOST_AUTO_TEST_CASE(test_parse__bad_file) {
    BOOST_CHECK_EQUAL(-2, ParseFile("src/test_data/test_2.sysml"));
}


BOOST_AUTO_TEST_SUITE_END()
