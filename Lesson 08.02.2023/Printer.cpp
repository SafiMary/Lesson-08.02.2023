#include "Printer.h"
#include <iostream>

using namespace Engine;

void Printer::printDefault() {
	std::cout << "Default Print message" << std:: endl;
}
void Printer::printavto(std::shared_ptr<Ivehicle>& vec) {
	vec->printType();

}