#ifndef FILE_CONVERTER_PROXY_H
#define FILE_CONVERTER_PROXY_H

#include <memory>
#include <string>

#include "selfRegisteringFactory/fileConverterProxyBase.h"
#include "selfRegisteringFactory/fileConverter.h"

template <class T>
class FileConverterProxy : public FileConverterProxyBase
{
private:
protected:
public:
	FileConverterProxy() : FileConverterProxyBase(this) {}
	virtual FileConverter* createObject() const final { return new T; } 
	virtual std::string getExtension() const final { return T::getExtension(); } 
	virtual bool isCompressed() const final { return T::isCompressed(); } 

	virtual ~FileConverterProxy() override = default;
};

#endif
