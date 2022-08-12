#ifndef LIBSYSML_ELEMENT_COLLECTION_H_
#define LIBSYSML_ELEMENT_COLLECTION_H_

#include <vector>
#include <iostream>

#include "element.hpp"


class element_collection {
	private:
		std::vector<element> elements;
	public:
		void add_element() {
			element* newElement = new element();
			elements.push_back(*newElement);
		}

		element& last_element() {
			return elements.back();
		}


		friend inline std::ostream& operator<<( std::ostream& o, const element_collection& ec ) {
			for (auto element : ec.elements){
				o << element;
			}
			return o;
		}

};


#endif  // LIBSYSML_ELEMENT_COLLECTION_H_
