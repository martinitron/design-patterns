#ifndef JSON_FILE_CONVERTER_H
#define JSON_FILE_CONVERTER_H

#include <string>

#include "selfRegisteringFactory/selfRegisteringFactory.h"
#include "selfRegisteringFactory/fileConverterProxy.h"
#include "selfRegisteringFactory/fileConverter.h"

#include <iostream>

class JSONFileConverter : public FileConverter {
private:
protected:
public:

	JSONFileConverter() {std::cout << "Creating JSONFileConverter()\n";}
	static std::string getExtension();
	static bool  isCompressed();

	void Import(const std::string&);
	void Export(const std::string&);
    
    void Import(const std::string&&);
	void Export(const std::string&&);
};

static FileConverterProxy<JSONFileConverter> gJSONProxy;

#endif
