#include <unistd.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <boost/spirit/home/x3.hpp>
#include "sysml.hpp"
#include <string>
#include <fstream>
#include <sstream>



int ParseFile(const std::string& path){

	std::cout << "Parsing: " << path << std::endl;

	std::ifstream input_file(path);

	if (!input_file.is_open()) {
		std::cerr << "Could not open the file - '"
			<< path << "'" << std::endl;
		return -1;
	}

//	std::string fileContents = std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());

//	std::cout << "File Contents: " << std::endl << std::endl << fileContents << std::endl;

	std::string line;
	while (std::getline(input_file,line)){

		double rN = 0.0;
        	double iN = 0.0;
        	auto fr = [&](auto& ctx){ rN = boost::spirit::x3::_attr(ctx); };
        	auto fi = [&](auto& ctx){ iN = boost::spirit::x3::_attr(ctx); };

		auto start = line.begin();
		auto end = line.end();

		bool parsed = boost::spirit::x3::phrase_parse(start,end,
		//  Begin grammar
            	(
                    	'(' >> boost::spirit::x3::double_[fr]
                        	>> -(',' >> boost::spirit::x3::double_[fi]) >> ')'
                	|   boost::spirit::x3::double_[fr]
            	)
        	//  End grammar
			,boost::spirit::x3::ascii::space );

		if (!parsed || start != end) // fail if we did not get a full match
			return -2;
	}

	return 0;

}

