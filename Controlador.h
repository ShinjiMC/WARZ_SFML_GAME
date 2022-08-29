#pragma once
#include "StrategyBase.h"
#include "HardStrategy.h"
#include "ChildStrategy.h"
class Controlador {
protected:
	StrategyBase* screenC;
public:
	Controlador(){}
	~Controlador(){}
	void SetStrategy(StrategyBase* alfa) { screenC = alfa; }
	void StartInterface() { screenC->Start(); }
	void StopInterface() { screenC->Stop(); }
};

