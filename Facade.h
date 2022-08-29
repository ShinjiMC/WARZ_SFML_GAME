#pragma once
#include "about.h"
#include "LeaderBoard.h"
#include "Juego.h"
class Facade {
protected:
	juego* system1;
	leader* system2;
	about* system3;
public:
	Facade(juego* system1_ = nullptr, leader* system2_ = nullptr, about* system3_ = nullptr){
		this->system1 = system1_;
		this->system2 = system2_;
		this->system3 = system3_;
	}
	~Facade();
	void Operation(int);
	juego* getS1() { return system1; }
	leader* getS2() { return system2; }
	about* getS3() { return system3; }
};

