#ifndef FILE_CONVERTER_PROXY_BASE_H
#define FILE_CONVERTER_PROXY_BASE_H

#include <memory>

#include "selfRegisteringFactory/fileConverter.h"
#include "selfRegisteringFactory/selfRegisteringFactory.h"

class FileConverterProxyBase {
private:
protected:
public:
	FileConverterProxyBase() { gFactory.register_converter(this); }
	//FileConverterProxyBase();
	~FileConverterProxyBase() = default;

	virtual FileConverter* createObject() const = 0;
	virtual char* getExtension() const = 0;
	virtual bool isCompressed() const = 0;
};

#endif
