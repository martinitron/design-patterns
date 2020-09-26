#include "selfRegisteringFactory/tiffFileConverter.h"

#include <iostream>
#include <string>

std::string TiffFileConverter::getExtension() {
	return ".tif";
}

bool TiffFileConverter::isCompressed() {
	return true;
}

void TiffFileConverter::Import(const std::string&& filename) {
	Import(filename);
}

void TiffFileConverter::Export(const std::string&& filename) {
	Export(filename);
}

void TiffFileConverter::Import(const std::string& filename) {
	std::cout << "Importing " << filename << ".\n";
}

void TiffFileConverter::Export(const std::string& filename) {
	std::cout << "Exporting " << filename << ".\n";
}
