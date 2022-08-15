#include <unistd.h>
#include <iostream>

#include "sysml.hpp"
#include <string>
#include <fstream>
#include <sstream>

#include <tao/pegtl.hpp>

namespace pegtl = tao::pegtl;

#include "sysml_parser.hpp"

void ParseString (const std::string& input, model& systemModel) {
	
	pegtl::memory_input<> in(input, "");

	if ( pegtl::parse< sysml_parser::grammar, 
			sysml_parser::action >( in, systemModel ) ) {
		return;
	} else {
		SysmlParseException e;
		throw e;

	}
}

void ParseFile(const std::string& path, model& systemModel){

	std::cout << "Parsing: " << path << std::endl;

	std::ifstream input_file(path);

	if (!input_file.is_open()) {
		throw std::runtime_error("Could not open file");
	}

	pegtl::file_input<> in(path);

	if ( pegtl::parse< sysml_parser::grammar, 
			sysml_parser::action >( in, systemModel ) ) {
		return;

	} else {
		SysmlParseException e;
		throw e;
	}
}

