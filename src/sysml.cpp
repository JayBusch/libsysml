#include <unistd.h>
#include <iostream>
#include <boost/spirit/home/x3.hpp>

#include "sysml.hpp"
#include <string>
#include <fstream>
#include <sstream>

#include "kerml_ast.hpp"
#include "kerml_ast_adapted.hpp"
#include "element.hpp"

namespace x3 = boost::spirit::x3;
namespace ascii = boost::spirit::x3::ascii;

using x3::lit;
using x3::lexeme;
using ascii::char_;

int ParseFile(const std::string& path){

	std::cout << "Parsing: " << path << std::endl;

	std::ifstream input_file(path);

	if (!input_file.is_open()) {
		std::cerr << "Could not open the file - '"
			<< path << "'" << std::endl;
		return -1;
	}


	std::string line;


	while (std::getline(input_file,line)){

        	auto foundElement = [&](auto& ctx){ 
			std::cout << "Found element" << std::endl;
		};

		auto start = line.begin();
		auto end = line.end();

		bool parsed = boost::spirit::x3::phrase_parse(start,end,
		//  Begin grammar
            	(
                    	lit("element") >> lexeme[char_[foundElement]] >> ';'
            	)
        	//  End grammar
			,boost::spirit::x3::ascii::space );

		if (!parsed || start != end) // fail if we did not get a full match
			return -2;
	}

	return 0;

}

