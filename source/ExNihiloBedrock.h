#pragma once

#include "Zenova.h"

class ExNihiloDefaultRecipes;

class ExNihiloBedrock : public Zenova::Mod {
private:
	static ExNihiloDefaultRecipes* defaultRecipes;

	virtual void Start();
	virtual ~ExNihiloBedrock() {}
	virtual void Update() {}
	virtual void Tick() {}
	virtual void Stop() {
		Zenova_Info("ExNihiloBedrock Stop");
	}
};