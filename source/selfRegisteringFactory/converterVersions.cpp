#include "selfRegisteringFactory/converterVersions.h"

#include <sstream>

int
ConverterVersions::getMajor() const
{
    return major_;
}

int
ConverterVersions::getMinor() const
{
    return minor_;
}

int
ConverterVersions::getPatch() const
{
    return patch_;
}

std::string
ConverterVersions::getString() const
{
    std::stringstream ss;
    ss << major_ << "." << minor_ << "." << patch_;
    return ss.str();
}