// This file was automatically generated using tools/process_csv.py
// Generated on Mon Jun 08 2020 16:28:55 UTC

#include <Zenova/Hook.h>
#include "minecraft/VanillaBlockRegistry.h"
#include "minecraft/ItemRegistry.h"
#include "minecraft/Item.h"

Block** VanillaBlocks::mGrass = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3050A98));
Block** VanillaBlocks::mDirt = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3051770));
Block** VanillaBlocks::mLeaves = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x30515D0));
Block** VanillaBlocks::mMycelium = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3050B50));
Block** VanillaBlocks::mLeaves2 = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x30510F0));
std::vector<SharedPtr<Item>>* ItemRegistry::mItemRegistry = reinterpret_cast<std::vector<SharedPtr<Item>>*>(Zenova::Hook::SlideAddress(0x3060120));
bool* Item::mInCreativeGroup = reinterpret_cast<bool*>(Zenova::Hook::SlideAddress(0x30507BA));

extern "C" {
	void* __0Item__QEAA_AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__F_Z_ptr;
	void* _beginCreativeGroup_Item__SAXAEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__PEAV1_FPEBVCompoundTag___Z_ptr;
	void* _addCreativeItem_Item__SAXPEAV1_F_Z_ptr;
	void* _getTextureItem_Item__SAAEBVTextureAtlasItem__AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std___Z_ptr;
	void* _getIconTextureUVSet_Item__SAAEBUTextureUVCoordinateSet__AEBVTextureAtlasItem__HH_Z_ptr;
	void* __0ItemStackBase__IEAA_AEBVItem__HH_Z_ptr;
	void* _set_ItemStackBase__QEAAXH_Z_ptr;
	void* _getAuxValue_ItemStackBase__QEBAFXZ_ptr;
	void* _getBlock_BlockSource__QEBAAEBVBlock__AEBVBlockPos___Z_ptr;
	void* _setBlock_BlockSource__QEAA_NAEBVBlockPos__AEBVBlock__HPEBUActorBlockSyncMessage___Z_ptr;
	void* _registerItem_ItemRegistry__SAXV_$SharedPtr_VItem_____Z_ptr;
	void* _registerItems_VanillaItems__SAX_N_Z_ptr;
	void* _initCreativeCategories_VanillaItems__SAXXZ_ptr;
	void* _initCreativeItemsCallback_VanillaItems__SAXPEAVActorInfoRegistry__PEAVBlockDefinitionGroup___N_Z_ptr;
	void* _initClientData_VanillaItems__SAXXZ_ptr;
	void* Item_vtable;
}

void InitBedrockPointers() {
	__0Item__QEAA_AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__F_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15614E0));
	_beginCreativeGroup_Item__SAXAEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__PEAV1_FPEBVCompoundTag___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1560AB0));
	_addCreativeItem_Item__SAXPEAV1_F_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1560C90));
	_getTextureItem_Item__SAAEBVTextureAtlasItem__AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15656C0));
	_getIconTextureUVSet_Item__SAAEBUTextureUVCoordinateSet__AEBVTextureAtlasItem__HH_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1565640));
	__0ItemStackBase__IEAA_AEBVItem__HH_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x156E6C0));
	_set_ItemStackBase__QEAAXH_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x156EF70));
	_getAuxValue_ItemStackBase__QEBAFXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15700E0));
	_getBlock_BlockSource__QEBAAEBVBlock__AEBVBlockPos___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1779710));
	_setBlock_BlockSource__QEAA_NAEBVBlockPos__AEBVBlock__HPEBUActorBlockSyncMessage___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x17797E0));
	_registerItem_ItemRegistry__SAXV_$SharedPtr_VItem_____Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15692F0));
	_registerItems_VanillaItems__SAX_N_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1594D20));
	_initCreativeCategories_VanillaItems__SAXXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15A3320));
	_initCreativeItemsCallback_VanillaItems__SAXPEAVActorInfoRegistry__PEAVBlockDefinitionGroup___N_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15A45F0));
	_initClientData_VanillaItems__SAXXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15A01D0));
	Item_vtable = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x2B766C0));
}

#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved) {
	if(fdwReason == DLL_PROCESS_ATTACH) InitBedrockPointers();
	return TRUE;
}
