#include "Zenova.h"

#include <iostream>

#include "minecraft/VanillaItems.h"
#include "items/ENItems.h"

void (*_registerItems)(bool);
void registerItems(bool b1) {
	_registerItems(b1);

	ENItems::init();
}

void (*_initCreativeCategories)();
void initCreativeCategories() {
	_initCreativeCategories();

	ENItems::initCreativeCategories();
}

void (*_initCreativeItemsCallback)(class ActorInfoRegistry*, class BlockDefinitionGroup*, bool);
void initCreativeItemsCallback(class ActorInfoRegistry* actorInfoRegistry, class BlockDefinitionGroup* blockDefinitionGroup, bool b1) {
	_initCreativeItemsCallback(actorInfoRegistry, blockDefinitionGroup, b1);

	ENItems::initCreativeItemsCallback();
}

void (*_initClientData)();
void initClientData() {
	_initClientData();

	ENItems::initClientData();
}

class ExNihiloBedrock : public Zenova::Mod {
	virtual void Start() {
		Zenova::Platform::DebugPause();
		Zenova_Info("ExNihiloBedrock Start");

		Zenova::Platform::CreateHook(reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1594D20)), registerItems, (void**)&_registerItems);
		Zenova::Platform::CreateHook(reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15A3320)), initCreativeCategories, (void**)&_initCreativeCategories);
		Zenova::Platform::CreateHook(reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15A45F0)), initCreativeItemsCallback, (void**)&_initCreativeItemsCallback);
		Zenova::Platform::CreateHook(reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15A01D0)), initClientData, (void**)&_initClientData);
	}

	virtual ~ExNihiloBedrock() {}
	virtual void Update() {}
	virtual void Tick() {}
	virtual void Stop() {
		Zenova_Info("ExNihiloBedrock Stop");
	}
};

MOD_FUNCTION Zenova::Mod* CreateMod() {
	return new ExNihiloBedrock;
}
