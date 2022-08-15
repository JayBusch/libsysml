#ifndef LIBSYSML_SYSML_H_
#define LIBSYSML_SYSML_H_

#include <string>

#include "model.hpp"

class SysmlParseException : public std::exception {
    public:
	    const char* what () {
		    return (const char*)"Exception parsing Sysml";
	    }
};

void ParseString(const std::string& input, model& systemModel);
void ParseFile(const std::string& path, model& systemModel);


#endif  // LIBSYSML_SYSML_H_
