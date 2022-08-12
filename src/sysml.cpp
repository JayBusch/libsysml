#include <unistd.h>
#include <iostream>

#include "sysml.hpp"
#include <string>
#include <fstream>
#include <sstream>

#include <tao/pegtl.hpp>

namespace pegtl = tao::pegtl;

#include "sysml_parser.hpp"

int ParseFile(const std::string& path){

	std::cout << "Parsing: " << path << std::endl;

	std::ifstream input_file(path);

	if (!input_file.is_open()) {
		std::cerr << "Could not open the file - '"
			<< path << "'" << std::endl;
		return -1;
	}

	pegtl::file_input<> in(path);
	model systemModel;

	if ( pegtl::parse< sysml_parser::grammar, 
			sysml_parser::action >( in, systemModel ) ) {
		std::cout << "PARSE SUCCESS!!!" << std::endl;
		std::cout << "systemModel: " << systemModel << std::endl;

	} else {
		std::cerr << "PARSE ERROR" << std::endl;
		std::cout << "systemModel: " << systemModel << std::endl;

		return -2;
	}
	return 0;
}

