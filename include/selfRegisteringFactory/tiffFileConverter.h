#ifndef TIFF_FILE_CONVERTER_H
#define TIFF_FILE_CONVERTER_H

#include "selfRegisteringFactory/selfRegisteringFactory.h"
#include "selfRegisteringFactory/fileConverterProxy.h"
#include "selfRegisteringFactory/fileConverter.h"

class TiffFileConverter : public FileConverter {
private:
protected:
public:
	static char* getExtension();
	static bool  isCompressed();

	void Import(const char*);
	void Export(const char*);
};

static FileConverterProxy<TiffFileConverter> gTiffProxy;

#endif
