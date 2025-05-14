#ifndef CONVERTER_VERISONS_H
#define CONVERTER_VERISONS_H

#include <string>

class ConverterVersions
{
    private:
    int major_{0};
    int minor_{0};
    int patch_{1};

    protected:
    public:

    ConverterVersions() = default;
    ~ConverterVersions() = default;

    int getMajor() const;
    int getMinor() const;
    int getPatch() const;

    std::string getString() const;


};

#endif //CONVERTER_VERISONS_H