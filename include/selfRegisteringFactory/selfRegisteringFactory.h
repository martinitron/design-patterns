#ifndef SELF_REGISTERING_FACTORY_H
#define SELF_REGISTERING_FACTORY_H

#include <memory>
#include <vector>

// #include "selfRegisteringFactory/fileConverterProxyBase.h"
// #include "selfRegisteringFactory/fileConverter.h"


// We can forward declare as we are not using concrete instances.
class FileConverterProxyBase;
class FileConverter;

class Factory {
private:
	static std::vector<const FileConverterProxyBase*>* v_;

	void Init();

protected:
public:
	Factory();
	Factory(const Factory&) = default;
	~Factory();

	FileConverter* createByExtension(std::string&);
    FileConverter* createByExtension(std::string&&);
    
	void register_converter(const FileConverterProxyBase*);
};

extern Factory gFactory;

#endif
