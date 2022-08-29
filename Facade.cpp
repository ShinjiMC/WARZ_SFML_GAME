#include "Facade.h"

Facade::~Facade()
{
	delete system1, system2, system3;
}
void Facade::Operation(int val) {
	if (val == 1) {
		this->system1->getventana()->display();
	}
	else if (val == 2) {
		this->system2->getventana()->display();
	}
	else if (val == 3) {
		this->system3->getventana()->display();
	}
}
