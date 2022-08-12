#ifndef LIBSYSML_MODEL_H_
#define LIBSYSML_MODEL_H_

#include <vector>
#include <iostream>

#include "element.hpp"
#include "element_collection.hpp"
#include "relationship.hpp"
#include "annotation.hpp"
#include "sysml_namespace.hpp"
#include "specialization.hpp"
#include "expression.hpp"

class model {

	private:
		element_collection elements;
		std::vector<relationship> relationships;
		std::vector<annotation> annotations;
		std::vector<sysml_namespace> namespaces;
		std::vector<specialization> specializations;
		std::vector<expression> expressions;
	public:
		void add_element() {
			elements.add_element();
		}

		element& last_element(){
			return elements.last_element();
		}
	
		friend inline std::ostream& operator<<( std::ostream& o, const model& m ) {
			o << std::endl << "elements: " << std::endl << m.elements;
			return o;
		}




};


#endif  // LIBSYSML_MODEL_H_
