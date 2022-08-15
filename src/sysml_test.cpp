#include "sysml.hpp"

#define BOOST_TEST_MODULE libsysml test cases
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(sysml_suite_1)

BOOST_AUTO_TEST_CASE(test_parse_file_missing_file) {

	model systemModel;
	BOOST_CHECK_THROW(ParseFile("src/test_data/test_DOESNOTEXIST.sysml",systemModel), std::exception);

}

BOOST_AUTO_TEST_CASE(test_parse_file_elements) {
	model systemModel;
	BOOST_CHECK_NO_THROW(ParseFile("src/test_data/test_1.sysml",systemModel));
	std::cout << systemModel << std::endl;

}

BOOST_AUTO_TEST_CASE(test_parse_string_element_shortname_only) {
	model systemModel;
	BOOST_CHECK_NO_THROW(ParseString("element <testShortNameOnlyID>;",systemModel));
}

BOOST_AUTO_TEST_SUITE_END()
