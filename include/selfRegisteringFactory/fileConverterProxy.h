#ifndef FILE_CONVERTER_PROXY_H
#define FILE_CONVERTER_PROXY_H

#include <memory>
#include <string>

#include "selfRegisteringFactory/fileConverterProxyBase.h"
#include "selfRegisteringFactory/fileConverter.h"

template <class T>
class FileConverterProxy : public FileConverterProxyBase{
	FileConverter* createObject() const { return new T; }
	std::string getExtension() const { return T::getExtension(); }
	bool isCompressed() const { return T::isCompressed(); }
};

#endif
