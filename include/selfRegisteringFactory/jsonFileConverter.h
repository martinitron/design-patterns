#ifndef JSON_FILE_CONVERTER_H
#define JSON_FILE_CONVERTER_H

#include "selfRegisteringFactory/selfRegisteringFactory.h"
#include "selfRegisteringFactory/fileConverterProxy.h"
#include "selfRegisteringFactory/fileConverter.h"

class JSONFileConverter : public FileConverter {
private:
protected:
public:
	static char* getExtension();
	static bool  isCompressed();

	void Import(const char*);
	void Export(const char*);
};

static FileConverterProxy<JSONFileConverter> gJSONProxy;

#endif
