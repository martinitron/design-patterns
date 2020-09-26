#include <iostream>
#include <memory>

#include "selfRegisteringFactory/selfRegisteringFactory.h"
#include "selfRegisteringFactory/fileConverter.h"

int
main(int argc, char** argv) {
	std::cout << "Hello World!\n";
	
	FileConverter* converter = gFactory.createByExtension(".json");
    
	if (converter != nullptr) {
		converter->Import("this_file.json");
		converter->Export("that_file.json");
		delete converter;
	}

	return 0;
}
