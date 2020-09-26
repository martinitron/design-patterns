#include "selfRegisteringFactory/tiffFileConverter.h"

#include <iostream>

char* TiffFileConverter::getExtension() {
	return ".tif";
}

bool TiffFileConverter::isCompressed() {
	return true;
}

void TiffFileConverter::Import(const char* filename) {
	std::cout << "Importing " << *filename << ".\n";
}

void TiffFileConverter::Export(const char* filename) {
	std::cout << "Exporting " << *filename << ".\n";
}