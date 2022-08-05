#if !defined(ELEMENT_DEF_HPP)
#define ELEMENT_DEF_HPP

#include <boost/spirit/home/x3.hpp>

#include "kerml_ast.hpp"
#include "kerml_ast_adapted.hpp"
#include "element.hpp"

namespace kerml
{
    namespace parser
    {
        namespace x3 = boost::spirit::x3;
        namespace ascii = boost::spirit::x3::ascii;

        using x3::int_;
        using x3::lit;
        using x3::double_;
        using x3::lexeme;
        using ascii::char_;

        x3::rule<class element, kerml::ast::element> const element = "element";

        auto const quoted_string = lexeme['"' >> +(char_ - '"') >> '"'];

        auto const element_def =
            lit("element")
            >> '{'
            >>  int_ >> ','
            >>  quoted_string >> ','
            >>  quoted_string >> ','
            >>  double_
            >>  '}'
            ;

        BOOST_SPIRIT_DEFINE(element);
    }

    parser::element_type element()
    {
        return parser::element;
    }
}

#endif

