#ifndef FILE_CONVERTER_H
#define FILE_CONVERTER_H

#include <string>

class FileConverter {
private:
protected:
public:
	FileConverter() = default;
	FileConverter(const FileConverter&) = default;
	virtual ~FileConverter() = default;

	virtual void Import(const std::string&) = 0;
	virtual void Export(const std::string&) = 0;
    
    virtual void Import(const std::string&&) = 0;
	virtual void Export(const std::string&&) = 0;
};

#endif
