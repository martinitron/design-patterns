#include <iostream>
#include <memory>

#include "selfRegisteringFactory/selfRegisteringFactory.h"
#include "selfRegisteringFactory/fileConverter.h"

int
main(int argc, char** argv) {
	std::cout << "Hello World!\n";
	
	FileConverter* converter = gFactory.createByExtension(".tif");
	if (converter) {
		converter->Import("this_file.tif");
		converter->Export("that_file.tif");
		delete converter;
	}

	return 0;
}