#include <iostream>
#include <memory>

#include "selfRegisteringFactory/selfRegisteringFactory.h"
#include "selfRegisteringFactory/fileConverter.h"

#include "selfRegisteringFactory/converterVersions.h"

int
main(int argc, char** argv) {
	std::cout << "Hello World!\n";
	
	ConverterVersions cv;

	std::cout << "Converter Version: " << cv.getString() << "\n";

	// FileConverter* converter = gFactory.createByExtension(".json");
	FileConverter* converter = gFactory.createByExtension(".yaml");

	if (!converter) {std::cout << "Converter not found.\n";}
    
	if (converter != nullptr) {
		converter->Import("this_file.json");
		converter->Export("that_file.json");
		delete converter;
	}

	return 0;
}
