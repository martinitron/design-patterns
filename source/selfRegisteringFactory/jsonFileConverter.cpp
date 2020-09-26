#include "selfRegisteringFactory/jsonFileConverter.h"

#include <iostream>

char* JSONFileConverter::getExtension() {
	return ".json";
}

bool JSONFileConverter::isCompressed() {
	return false;
}

void JSONFileConverter::Import(const char* filename) {
	std::cout << "Importing " << *filename << ".\n";
}

void JSONFileConverter::Export(const char* filename) {
	std::cout << "Exporting " << *filename << ".\n";
}