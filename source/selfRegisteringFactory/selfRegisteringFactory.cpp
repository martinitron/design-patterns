#include "selfRegisteringFactory/selfRegisteringFactory.h"

#include <iostream>
#include <memory>
#include <string>

#include "selfRegisteringFactory/fileConverterProxyBase.h"

//strcasecmp for linux
//_stricmp for visual studio

Factory gFactory;

std::vector<const FileConverterProxyBase*>* Factory::v_ = nullptr;

namespace {
    
#include <cctype>
bool compareChar(char & c1, char & c2)
{
    if (c1 == c2)
    {
        return true;
    }
    else if (std::toupper(c1) == std::toupper(c2))
    {
        return true;
    }
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

Factory::Factory()
{
    std::cout << "Generating Factory instance\n";
    // Factory::v_ = nullptr;
}

Factory::~Factory()
{
    std::cout << "Deleting ConverterProxy Vector\n";
    // delete Factory::v_;
}

void Factory::Init()
{
    if (Factory::v_ == nullptr) {
        std::cout << "Initialising ConverterProxy Vector\n";
        Factory::v_ = new std::vector<const FileConverterProxyBase*>();
    }
}

void Factory::register_converter(const FileConverterProxyBase* c)
{
    // std::cout << "Registering ConverterProxy " << c->getExtension() << "\n";
    Init();
    Factory::v_->push_back(c);
    std::cout << "v_ size: " << Factory::v_->size() << "\n";
}

FileConverter* Factory::createByExtension(std::string&& ext)
{
    return createByExtension(ext);
}

FileConverter* Factory::createByExtension(std::string& ext)
{
    std::cout << "creating converter for extension: " << ext << "\n";

    if (Factory::v_ == nullptr) { /*throw std::runtime_error("v_ not allocated");*/ return nullptr; }

    if (! Factory::v_->size()) { throw std::runtime_error("v_ has size 0"); }

    for (unsigned i = 0; i < Factory::v_->size(); i++) 
    {
        std::string i_ext = Factory::v_->at(i)->getExtension();
        std::cout << "checking against converter for extension: " << i_ext << "\n";
        if (caseInSensStringCompare(i_ext, ext)) 
        {
            return Factory::v_->at(i)->createObject();
        }
    }
    return nullptr;
}


