#ifndef TIFF_FILE_CONVERTER_H
#define TIFF_FILE_CONVERTER_H

#include <string>

#include "selfRegisteringFactory/selfRegisteringFactory.h"
#include "selfRegisteringFactory/fileConverterProxy.h"
#include "selfRegisteringFactory/fileConverter.h"

class TiffFileConverter : public FileConverter {
private:
protected:
public:
	static std::string getExtension();
	static bool  isCompressed();

	void Import(const std::string&);
	void Export(const std::string&);
    
    void Import(const std::string&&);
	void Export(const std::string&&);
};

static FileConverterProxy<TiffFileConverter> gTiffProxy;

#endif
