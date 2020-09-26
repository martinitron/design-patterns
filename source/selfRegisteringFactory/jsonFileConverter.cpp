#include "selfRegisteringFactory/jsonFileConverter.h"

#include <iostream>
#include <string>

std::string JSONFileConverter::getExtension() {
	return ".json";
}

bool JSONFileConverter::isCompressed() {
	return false;
}


void JSONFileConverter::Import(const std::string&& filename) {
	Import(filename);
}

void JSONFileConverter::Export(const std::string&& filename) {
	Export(filename);
}

void JSONFileConverter::Import(const std::string& filename) {
	std::cout << "Importing " << filename << ".\n";
}

void JSONFileConverter::Export(const std::string& filename) {
	std::cout << "Exporting " << filename << ".\n";
}
