#ifndef SELF_REGISTERING_FACTORY_H
#define SELF_REGISTERING_FACTORY_H

#include <memory>
#include <vector>

//#include "selfRegisteringFactory/fileConverterProxyBase.h"

// We can forward declare as we are not using concrete instances.
class FileConverterProxyBase;
class FileConverter;

class Factory {
private:
	std::vector<const FileConverterProxyBase*>* v_ = nullptr;

	void Init();

protected:
public:
	Factory() = default;
	Factory(const Factory&) = default;
	~Factory();

	FileConverter* createByExtension(std::string&);
    FileConverter* createByExtension(std::string&&);
    
	void register_converter(const FileConverterProxyBase*);
};

extern Factory gFactory;

#endif
