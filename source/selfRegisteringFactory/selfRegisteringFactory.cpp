#include "selfRegisteringFactory/selfRegisteringFactory.h"

#include <iostream>

Factory::Factory() {
	std::cout << "Hello from Factory\n";
}

Factory::Factory(const Factory&) {

}

Factory::~Factory() {
	std::cout << "Goodbye from Factory\n";
}