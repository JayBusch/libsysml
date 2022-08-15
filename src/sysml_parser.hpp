#ifndef LIBSYSML_SYSML_PARSER_H_
#define LIBSYSML_SYSML_PARSER_H_

#include <tao/pegtl.hpp>

#include "model.hpp"
#include "element.hpp"

namespace pegtl = tao::pegtl;

namespace sysml_parser {

	// clang-format off
	struct element_command : pegtl::string< 'e', 'l', 'e', 'm', 'e', 'n', 't', ' ' > {};
	struct blanks : pegtl::star<pegtl::space> {};
	struct element_shortName_head : pegtl::seq<blanks,pegtl::one<'<'>,blanks> {};
	struct element_shortName_tail : pegtl::seq<blanks,pegtl::one<'>'>,blanks> {};
	struct element_shortName : pegtl::plus<pegtl::alpha> {};
	struct element_shortName_phrase : pegtl::seq<
				   	element_shortName_head , 
					element_shortName,
					element_shortName_tail
				> {};
	struct element_name : pegtl::plus<pegtl::alpha> {};
	struct element_name_phrase : pegtl::seq<
			      	blanks,
			      	element_name,
				blanks
				>{};
	struct element : pegtl::plus< pegtl::star<pegtl::space>,
			 	pegtl::seq< 
				       element_command, 
				       pegtl::if_must_else<
					      pegtl::not_at <
					      		element_shortName_phrase
						>,
						element_name_phrase,
						pegtl::seq<
							element_shortName_phrase,
							pegtl::star<element_name_phrase>
						>
					>,
				       pegtl::one<';'>,
				       pegtl::star<pegtl::space>
				>> {};
	
	struct grammar : pegtl::plus<element> {};

	// clang-format on
	template< typename Rule >
	struct action
	{};

	template<>
	struct action< element_command >
	{
		template< typename ActionInput >
		static void apply( const ActionInput& in, model& systemModel )
		{
			std::cout << "element_command = " << in.string() << std::endl;
			systemModel.add_element();
		}
	};


	template<>
	struct action< element_shortName >
	{
		template< typename ActionInput >
		static void apply( const ActionInput& in, model& systemModel )
		{
			std::cout << "shortName = " << in.string() << std::endl;
			systemModel.last_element().shortName=in.string();
		}
	};

	template<>
	struct action< element_name >
	{
		template< typename ActionInput >
		static void apply( const ActionInput& in, model& systemModel )
		{
			std::cout << "name = " << in.string() << std::endl;
			systemModel.last_element().name= in.string();
		}
	};

}

#endif  // LIBSYSML_SYSML_PARSER_H_
