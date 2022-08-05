#if !defined(BOOST_SPIRIT_X3_KERML_AST_HPP)
#define BOOST_SPIRIT_X3_KERML_AST_HPP

#include <boost/fusion/include/io.hpp>

#include <iostream>

#include <string>
#include <boost/uuid/uuid.hpp>

namespace kerml {
	namespace ast {
		struct element {
			boost::uuids::uuid elementId;
			std::string name;
			std::string shortName;
		};
	}

	using boost::fusion::operator<<;
}

#endif
