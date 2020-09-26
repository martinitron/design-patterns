#include "selfRegisteringFactory/selfRegisteringFactory.h"

#include <iostream>
#include <memory>
#include <string>

#include "selfRegisteringFactory/fileConverterProxyBase.h"

//strcasecmp for linux
//_stricmp for visual studio

Factory gFactory;

namespace {
    
#include <cctype>
bool compareChar(char & c1, char & c2)
{
    if (c1 == c2)
        return true;
    else if (std::toupper(c1) == std::toupper(c2))
        return true;
    return false;
}
/*
 * Case Insensitive String Comparision
 */
bool caseInSensStringCompare(std::string &str1, std::string &str2)
{
    return ( (str1.size() == str2.size() ) &&
             std::equal(str1.begin(), str1.end(), str2.begin(), &compareChar) );
}
    
}

Factory::~Factory() {
    delete v_;
}

void Factory::Init() {
    if (v_ == nullptr) {
        v_ = new std::vector<const FileConverterProxyBase*>;
    }
}

void Factory::register_converter(const FileConverterProxyBase* c) {
    Init();
    v_->push_back(c);
}

FileConverter* Factory::createByExtension(std::string&& ext) {
    return createByExtension(ext);
}

FileConverter* Factory::createByExtension(std::string& ext) {
    for (unsigned i = 0; i < v_->size(); i++) {
        std::string i_ext = v_->at(i)->getExtension();
        if (caseInSensStringCompare(i_ext, ext)) {
            return v_->at(i)->createObject();
        }
    }
    return nullptr;
}


