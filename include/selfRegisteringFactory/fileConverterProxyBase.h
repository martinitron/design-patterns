#ifndef FILE_CONVERTER_PROXY_BASE_H
#define FILE_CONVERTER_PROXY_BASE_H

#include <memory>
#include <string>

#include "selfRegisteringFactory/fileConverter.h"
#include "selfRegisteringFactory/selfRegisteringFactory.h"

class FileConverterProxyBase {
private:
protected:
public:
	FileConverterProxyBase(const FileConverterProxyBase* ptr) { gFactory.register_converter(ptr); }
	FileConverterProxyBase() = delete;
	
	virtual ~FileConverterProxyBase() = default;

	virtual FileConverter* createObject() const = 0;
	virtual std::string getExtension() const = 0;
	virtual bool isCompressed() const = 0;
};

#endif
