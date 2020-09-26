#include "selfRegisteringFactory/selfRegisteringFactory.h"

#include <iostream>
#include <memory>

#include "selfRegisteringFactory/fileConverterProxyBase.h"

Factory gFactory;

void Factory::Init() {
    if (v_ == nullptr) {
        v_ = std::make_unique<std::vector<const FileConverterProxyBase*>>();
    }
}

void Factory::register_converter(const FileConverterProxyBase* c) {
    Init();
    v_->push_back(c);
}

FileConverter* Factory::createByExtension(const char* ext) {
    for (unsigned i = 0; i < v_->size(); i++)
        if (_stricmp(v_->at(i)->getExtension(),
            ext) == 0)
            return v_->at(i)->createObject();
    return nullptr;
}