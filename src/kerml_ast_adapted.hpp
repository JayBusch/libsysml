#if !defined(BOOST_SPIRIT_X3_MINIMAL_AST_ADAPTED_HPP)
#define BOOST_SPIRIT_X3_MINIMAL_AST_ADAPTED_HPP

#include <boost/fusion/include/adapt_struct.hpp>
#include "kerml_ast.hpp"

BOOST_FUSION_ADAPT_STRUCT(kerml::ast::element,
	elementId, name, shortName
)

#endif
