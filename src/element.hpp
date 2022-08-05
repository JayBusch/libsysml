#if !defined(ELEMENT_HPP)
#define ELEMENT_HPP

#include <boost/spirit/home/x3.hpp>

#include "kerml_ast.hpp"

namespace kerml
{
    namespace parser
    {
        namespace x3 = boost::spirit::x3;
        using element_type = x3::rule<class element, kerml::ast::element>;
        BOOST_SPIRIT_DECLARE(element_type);
    }

    parser::element_type element();
}

#endif
