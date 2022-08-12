#ifndef LIBSYSML_ELEMENT_H_
#define LIBSYSML_ELEMENT_H_

class element {
	public:
		std::string id;
		std::string shortName;
		std::string name;

		friend inline std::ostream& operator<<( std::ostream& o, const element& e ) {
			o << "id: " << e.id << std::endl;
			o << "shortName: " << e.shortName << std::endl;
			o << "name: " << e.name << std::endl;
			return o;
		}

};


#endif  // LIBSYSML_ELEMENT_H_
