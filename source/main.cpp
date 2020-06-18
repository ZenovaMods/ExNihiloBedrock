// This file was automatically generated using tools/process_csv.py
// Generated on Thu Jun 18 2020 17:35:09 UTC

#include <Zenova/Hook.h>
#include "main.h"
#include "minecraft/VanillaBlockRegistry.h"
#include "minecraft/VanillaBlockStates.h"
#include "minecraft/VanillaBlockTypeRegistry.h"
#include "minecraft/VanillaItemTiers.h"
#include "minecraft/ItemRegistry.h"
#include "minecraft/BlockTypeRegistry.h"
#include "minecraft/WorldSystems.h"
#include "minecraft/Item.h"
#include "minecraft/ActorType.h"
#include "minecraft/ProjectileFactory.h"
#include "minecraft/ActorFactory.h"

Block** VanillaBlocks::mGrass = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3050A98));
Block** VanillaBlocks::mDirt = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3051770));
Block** VanillaBlocks::mCobblestone = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3051570));
Block** VanillaBlocks::mSapling = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x30514D8));
Block** VanillaBlocks::mSand = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3050B58));
Block** VanillaBlocks::mGravel = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3050B60));
Block** VanillaBlocks::mLeaves = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x30515D0));
Block** VanillaBlocks::mCactus = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3050B30));
Block** VanillaBlocks::mReeds = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3050AA0));
Block** VanillaBlocks::mNetherrack = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3051478));
Block** VanillaBlocks::mMycelium = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3050B50));
Block** VanillaBlocks::mEndStone = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x3051470));
Block** VanillaBlocks::mCarrotCrop = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x30516A8));
Block** VanillaBlocks::mPotatoCrop = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x30516B0));
Block** VanillaBlocks::mLeaves2 = reinterpret_cast<Block**>(Zenova::Hook::SlideAddress(0x30510F0));
WeakPtr<BlockLegacy>* VanillaBlockTypes::mGrass = reinterpret_cast<WeakPtr<BlockLegacy>*>(Zenova::Hook::SlideAddress(0x3061468));
WeakPtr<BlockLegacy>* VanillaBlockTypes::mDirt = reinterpret_cast<WeakPtr<BlockLegacy>*>(Zenova::Hook::SlideAddress(0x3061470));
WeakPtr<BlockLegacy>* VanillaBlockTypes::mCobblestone = reinterpret_cast<WeakPtr<BlockLegacy>*>(Zenova::Hook::SlideAddress(0x3061478));
WeakPtr<BlockLegacy>* VanillaBlockTypes::mSand = reinterpret_cast<WeakPtr<BlockLegacy>*>(Zenova::Hook::SlideAddress(0x30614B8));
WeakPtr<BlockLegacy>* VanillaBlockTypes::mGravel = reinterpret_cast<WeakPtr<BlockLegacy>*>(Zenova::Hook::SlideAddress(0x30614C0));
WeakPtr<BlockLegacy>* VanillaBlockTypes::mLeaves = reinterpret_cast<WeakPtr<BlockLegacy>*>(Zenova::Hook::SlideAddress(0x30614E8));
WeakPtr<BlockLegacy>* VanillaBlockTypes::mMycelium = reinterpret_cast<WeakPtr<BlockLegacy>*>(Zenova::Hook::SlideAddress(0x30617F0));
WeakPtr<BlockLegacy>* VanillaBlockTypes::mLeaves2 = reinterpret_cast<WeakPtr<BlockLegacy>*>(Zenova::Hook::SlideAddress(0x30619E0));
ItemState* VanillaStates::SaplingType = reinterpret_cast<ItemState*>(Zenova::Hook::SlideAddress(0x30633C0));
Item::Tier* VanillaItemTiers::WOOD = reinterpret_cast<Item::Tier*>(Zenova::Hook::SlideAddress(0x2A39988));
Item::Tier* VanillaItemTiers::STONE = reinterpret_cast<Item::Tier*>(Zenova::Hook::SlideAddress(0x2A39A20));
Item::Tier* VanillaItemTiers::IRON = reinterpret_cast<Item::Tier*>(Zenova::Hook::SlideAddress(0x2A39658));
Item::Tier* VanillaItemTiers::DIAMOND = reinterpret_cast<Item::Tier*>(Zenova::Hook::SlideAddress(0x2A39A38));
Item::Tier* VanillaItemTiers::GOLD = reinterpret_cast<Item::Tier*>(Zenova::Hook::SlideAddress(0x2A39A50));
std::vector<SharedPtr<Item>>* ItemRegistry::mItemRegistry = reinterpret_cast<std::vector<SharedPtr<Item>>*>(Zenova::Hook::SlideAddress(0x3060118));
short* ItemRegistry::mMaxItemID = reinterpret_cast<short*>(Zenova::Hook::SlideAddress(0x30507BC));
std::unordered_map<std::string, SharedPtr<BlockLegacy>>* BlockTypeRegistry::mBlockLookupMap = reinterpret_cast<std::unordered_map<std::string, SharedPtr<BlockLegacy>>*>(Zenova::Hook::SlideAddress(0x3061390));
bool* Item::mInCreativeGroup = reinterpret_cast<bool*>(Zenova::Hook::SlideAddress(0x30507BA));
bool* WorldSystems::mInitialized = reinterpret_cast<bool*>(Zenova::Hook::SlideAddress(0x30507BE));
std::unordered_map<ActorType, ActorMapping>* ENTITY_TYPE_MAP = reinterpret_cast<std::unordered_map<ActorType, ActorMapping>*>(Zenova::Hook::SlideAddress(0x305C590));
std::unordered_map<std::string, std::function<std::unique_ptr<OnHitSubcomponent>()>>* ProjectileFactory::mSubcomponentMap = reinterpret_cast<std::unordered_map<std::string, std::function<std::unique_ptr<OnHitSubcomponent>()>>*>(Zenova::Hook::SlideAddress(0x305DD20));
std::unordered_map<std::string, ActorFactoryData>* _factoryFunctions = reinterpret_cast<std::unordered_map<std::string, ActorFactoryData>*>(Zenova::Hook::SlideAddress(0x305C460));

extern "C" {
	void* __0Item__QEAA_AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__F_Z_ptr;
	void* __0BlockPlanterItem__QEAA_AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__HAEBVBlock___N_Z_ptr;
	void* __0DiggerItem__IEAA_AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__HHAEBVTier_Item__AEBV_$vector_PEBVBlock__V_$allocator_PEBVBlock___std___2__Z_ptr;
	void* __0BlockItem__QEAA_AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__H_Z_ptr;
	void* _beginCreativeGroup_Item__SAXAEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__PEAV1_FPEBVCompoundTag___Z_ptr;
	void* _addCreativeItem_Item__SAXPEAV1_F_Z_ptr;
	void* _addCreativeItem_Item__SAXAEBVBlock___Z_ptr;
	void* _getTextureItem_Item__SAAEBVTextureAtlasItem__AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std___Z_ptr;
	void* _getIconTextureUVSet_Item__SAAEBUTextureUVCoordinateSet__AEBVTextureAtlasItem__HH_Z_ptr;
	void* _getCommandName_Item__QEBAAEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__XZ_ptr;
	void* __1ItemStackBase__UEAA_XZ_ptr;
	void* __0ItemStackBase__IEAA_XZ_ptr;
	void* __0ItemStackBase__IEAA_AEBVItem__HH_Z_ptr;
	void* __0ItemStackBase__IEAA_AEBVBlockLegacy__H_Z_ptr;
	void* __0ItemStackBase__IEAA_AEBVBlock__HPEBVCompoundTag___Z_ptr;
	void* __0ItemStackBase__IEAA_AEBV0__Z_ptr;
	void* __0ItemStack__QEAA_XZ_ptr;
	void* __0ItemStack__QEAA_AEBVItem__H_Z_ptr;
	void* __0ItemStack__QEAA_AEBVBlockLegacy__H_Z_ptr;
	void* __0ItemInstance__QEAA_XZ_ptr;
	void* __0ItemInstance__QEAA_AEBVItem__HH_Z_ptr;
	void* __0ItemInstance__QEAA_AEBVBlockLegacy__H_Z_ptr;
	void* __0ItemInstance__QEAA_AEBVBlock__HPEBVCompoundTag___Z_ptr;
	void* __0ItemInstance__QEAA_AEBV0__Z_ptr;
	void* _set_ItemStackBase__QEAAXH_Z_ptr;
	void* _getItem_ItemStackBase__QEBAPEBVItem__XZ_ptr;
	void* _getAuxValue_ItemStackBase__QEBAFXZ_ptr;
	void* _getBlock_BlockSource__QEBAAEBVBlock__AEBVBlockPos___Z_ptr;
	void* _setBlock_BlockSource__QEAA_NAEBVBlockPos__AEBVBlock__HPEBUActorBlockSyncMessage___Z_ptr;
	void* _getLegacyBlock_Block__QEBAAEBVBlockLegacy__XZ_ptr;
	void* _getSaplingType_Block__QEBAPEBV1_AEBVItemState__W4SaplingType___Z_ptr;
	void* __0BlockLegacy__QEAA_AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__HAEBVMaterial___Z_ptr;
	void* _getBlockItemId_BlockLegacy__QEBAFXZ_ptr;
	void* _tryGetStateFromLegacyData_BlockLegacy__QEBAPEBVBlock__G_Z_ptr;
	void* _popResource_BlockLegacy__QEBAPEAVItemActor__AEAVBlockSource__AEBVBlockPos__AEBVItemInstance___Z_ptr;
	void* _getDefaultState_BlockLegacy__QEBAAEAVBlock__XZ_ptr;
	void* _registerItem_ItemRegistry__SAXV_$SharedPtr_VItem_____Z_ptr;
	void* _getItem_ItemRegistry__SA_AV_$WeakPtr_VItem____F_Z_ptr;
	void* _lookupByName_ItemRegistry__SA_AV_$WeakPtr_VItem____AEAH0AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std___Z_ptr;
	void* _lookupByName_ItemRegistry__SA_AV_$WeakPtr_VItem____AEAHAEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std___Z_ptr;
	void* _registerItems_VanillaItems__SAX_N_Z_ptr;
	void* _initCreativeCategories_VanillaItems__SAXXZ_ptr;
	void* _initCreativeItemsCallback_VanillaItems__SAXPEAVActorInfoRegistry__PEAVBlockDefinitionGroup___N_Z_ptr;
	void* _initClientData_VanillaItems__SAXXZ_ptr;
	void* __genRandInt32_Random_Core__AEAAIXZ_ptr;
	void* _nextFloat_Random__QEAAMXZ_ptr;
	void* _getSelectedItem_Player__QEBAAEBVItemStack__XZ_ptr;
	void* _causeFoodExhaustion_Player__QEAAXM_Z_ptr;
	void* _getEnchantLevel_EnchantUtils__SAHW4Type_Enchant__AEBVItemStackBase___Z_ptr;
	void* _hasEnchant_EnchantUtils__SA_NW4Type_Enchant__AEBVItemStackBase___Z_ptr;
	void* _toLower_Util__YA_AV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__AEBV23__Z_ptr;
	void* _registerBlockGraphics_BlockGraphics__SAAEAV1_AEAV_$vector_VValue_Json__V_$allocator_VValue_Json___std___std__AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__3_W4BlockShape___Z_ptr;
	void* _registerLooseBlockGraphics_BlockGraphics__SAXAEAV_$vector_VValue_Json__V_$allocator_VValue_Json___std___std__AEBVBlockPalette___Z_ptr;
	void* _getMaterial_Material__SAAEBV1_W4MaterialType___Z_ptr;
	void* _init_WorldSystems__SAXPEAVResourcePackManager___Z_ptr;
	void* _shutdown_VanillaWorldSystems__YAXXZ_ptr;
	void* _registerBlocks_VanillaBlockTypes__YAXXZ_ptr;
	void* _lookupByName_BlockTypeRegistry__SA_AV_$WeakPtr_VBlockLegacy____AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std___Z_ptr;
	void* __1BlockLegacy__UEAA_XZ_ptr;
	void* __1Actor__UEAA_XZ_ptr;
	void* _registerBlocks_BlockDefinitionGroup__QEAAXXZ_ptr;
	void* _spawnProjectile_Spawner__QEAAPEAVActor__AEAVBlockSource__AEBUActorDefinitionIdentifier__PEAV2_AEBVVec3__3_Z_ptr;
	void* _spawnMob_Spawner__QEAAPEAVMob__AEAVBlockSource__AEBUActorDefinitionIdentifier__PEAVActor__AEBVVec3___N44_Z_ptr;
	void* _spawnItem_Spawner__QEAAPEAVItemActor__AEAVBlockSource__AEBVItemStack__PEAVActor__AEBVVec3__H_Z_ptr;
	void* __0ActorDefinitionIdentifier__QEAA_W4ActorType___Z_ptr;
	void* __initialize_ActorDefinitionIdentifier__AEAAXXZ_ptr;
	void* __extractIdentifier_ActorDefinitionIdentifier__CAXAEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__AEAU1__Z_ptr;
	void* _computeHash_HashedString__SA_KPEBD_Z_ptr;
	void* _initFactory_ProjectileFactory__SAXXZ_ptr;
	void* _EntityCanonicalName__YAAEBVHashedString__W4ActorType___Z_ptr;
	void* _EntityTypeToString__YA_AV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__W4ActorType__W4ActorTypeNamespaceRules___Z_ptr;
	void* __0ItemSpriteRenderer__QEAA_AEAVTextureGroup_mce__PEAVItem___N_Z_ptr;
	void* __1ItemSpriteRenderer__UEAA_XZ_ptr;
	void* _initializeEntityRenderers_ActorRenderDispatcher__QEAAXAEAVGeometryGroup__AEAVTextureGroup_mce__AEAVBlockTessellator__AEBVActorResourceDefinitionGroup__AEBVSemVersion___Z_ptr;
	void* _getRenderer_ActorRenderDispatcher__QEBAPEAVActorRenderer__AEBVHashedString___Z_ptr;
	void* _getDataDrivenRenderer_ActorRenderDispatcher__QEBAPEAVDataDrivenRenderer__AEBVHashedString___Z_ptr;
	void* _registerActorInfo_ActorInfoRegistry__QEAAXAEBUActorInfo___Z_ptr;
	void* _setDefinitionGroup_ActorFactory__QEAAXPEAVActorDefinitionGroup___Z_ptr;
	void* Item_vtable;
	void* DiggerItem_vtable;
	void* BlockPlanterItem_vtable;
	void* BlockItem_vtable;
	void* BlockLegacy_vtable;
	void* HeavyBlock_vtable;
	void* ItemInstance_vtable;
	void* ItemStack_vtable;
	void* Actor_vtable;
	void* Mob_vtable;
	void* Player_vtable;
}

void InitBedrockPointers() {
	__0Item__QEAA_AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__F_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15614E0));
	__0BlockPlanterItem__QEAA_AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__HAEBVBlock___N_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1515440));
	__0DiggerItem__IEAA_AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__HHAEBVTier_Item__AEBV_$vector_PEBVBlock__V_$allocator_PEBVBlock___std___2__Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1547810));
	__0BlockItem__QEAA_AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__H_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1514950));
	_beginCreativeGroup_Item__SAXAEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__PEAV1_FPEBVCompoundTag___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1560AB0));
	_addCreativeItem_Item__SAXPEAV1_F_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1560C90));
	_addCreativeItem_Item__SAXAEBVBlock___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1560BD0));
	_getTextureItem_Item__SAAEBVTextureAtlasItem__AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15656C0));
	_getIconTextureUVSet_Item__SAAEBUTextureUVCoordinateSet__AEBVTextureAtlasItem__HH_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1565640));
	_getCommandName_Item__QEBAAEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1565810));
	__1ItemStackBase__UEAA_XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x010B600));
	__0ItemStackBase__IEAA_XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x156E290));
	__0ItemStackBase__IEAA_AEBVItem__HH_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x156E6C0));
	__0ItemStackBase__IEAA_AEBVBlockLegacy__H_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x156E360));
	__0ItemStackBase__IEAA_AEBVBlock__HPEBVCompoundTag___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x156E3F0));
	__0ItemStackBase__IEAA_AEBV0__Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x156E7D0));
	__0ItemStack__QEAA_XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x156D210));
	__0ItemStack__QEAA_AEBVItem__H_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x156D270));
	__0ItemStack__QEAA_AEBVBlockLegacy__H_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x156D240));
	__0ItemInstance__QEAA_XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1568AD0));
	__0ItemInstance__QEAA_AEBVItem__HH_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1568C00));
	__0ItemInstance__QEAA_AEBVBlockLegacy__H_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1568B40));
	__0ItemInstance__QEAA_AEBVBlock__HPEBVCompoundTag___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1568B70));
	__0ItemInstance__QEAA_AEBV0__Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1568C30));
	_set_ItemStackBase__QEAAXH_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x156EF70));
	_getItem_ItemStackBase__QEBAPEBVItem__XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x01B9250));
	_getAuxValue_ItemStackBase__QEBAFXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15700E0));
	_getBlock_BlockSource__QEBAAEBVBlock__AEBVBlockPos___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1779710));
	_setBlock_BlockSource__QEAA_NAEBVBlockPos__AEBVBlock__HPEBUActorBlockSyncMessage___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x17797E0));
	_getLegacyBlock_Block__QEBAAEBVBlockLegacy__XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x00E9920));
	_getSaplingType_Block__QEBAPEBV1_AEBVItemState__W4SaplingType___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15AD390));
	__0BlockLegacy__QEAA_AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__HAEBVMaterial___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x164EC50));
	_getBlockItemId_BlockLegacy__QEBAFXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1651D90));
	_tryGetStateFromLegacyData_BlockLegacy__QEBAPEBVBlock__G_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x164F4B0));
	_popResource_BlockLegacy__QEBAPEAVItemActor__AEAVBlockSource__AEBVBlockPos__AEBVItemInstance___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1650520));
	_getDefaultState_BlockLegacy__QEBAAEAVBlock__XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1651D80));
	_registerItem_ItemRegistry__SAXV_$SharedPtr_VItem_____Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15692F0));
	_getItem_ItemRegistry__SA_AV_$WeakPtr_VItem____F_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1569180));
	_lookupByName_ItemRegistry__SA_AV_$WeakPtr_VItem____AEAH0AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x156B410));
	_lookupByName_ItemRegistry__SA_AV_$WeakPtr_VItem____AEAHAEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x156AA50));
	_registerItems_VanillaItems__SAX_N_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1594D20));
	_initCreativeCategories_VanillaItems__SAXXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15A3320));
	_initCreativeItemsCallback_VanillaItems__SAXPEAVActorInfoRegistry__PEAVBlockDefinitionGroup___N_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15A45F0));
	_initClientData_VanillaItems__SAXXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15A01D0));
	__genRandInt32_Random_Core__AEAAIXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x01AC370));
	_nextFloat_Random__QEAAMXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x0620D10));
	_getSelectedItem_Player__QEBAAEBVItemStack__XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1459C30));
	_causeFoodExhaustion_Player__QEAAXM_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x145BD20));
	_getEnchantLevel_EnchantUtils__SAHW4Type_Enchant__AEBVItemStackBase___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15506F0));
	_hasEnchant_EnchantUtils__SA_NW4Type_Enchant__AEBVItemStackBase___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x15507A0));
	_toLower_Util__YA_AV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__AEBV23__Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x0E52DA0));
	_registerBlockGraphics_BlockGraphics__SAAEAV1_AEAV_$vector_VValue_Json__V_$allocator_VValue_Json___std___std__AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__3_W4BlockShape___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x099C240));
	_registerLooseBlockGraphics_BlockGraphics__SAXAEAV_$vector_VValue_Json__V_$allocator_VValue_Json___std___std__AEBVBlockPalette___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x099CA10));
	_getMaterial_Material__SAAEBV1_W4MaterialType___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1892CB0));
	_init_WorldSystems__SAXPEAVResourcePackManager___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x19151A0));
	_shutdown_VanillaWorldSystems__YAXXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1B53370));
	_registerBlocks_VanillaBlockTypes__YAXXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x16E0AB0));
	_lookupByName_BlockTypeRegistry__SA_AV_$WeakPtr_VBlockLegacy____AEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x16D9640));
	__1BlockLegacy__UEAA_XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x164F200));
	__1Actor__UEAA_XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x125CAF0));
	_registerBlocks_BlockDefinitionGroup__QEAAXXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x169EDC0));
	_spawnProjectile_Spawner__QEAAPEAVActor__AEAVBlockSource__AEBUActorDefinitionIdentifier__PEAV2_AEBVVec3__3_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x18AC210));
	_spawnMob_Spawner__QEAAPEAVMob__AEAVBlockSource__AEBUActorDefinitionIdentifier__PEAVActor__AEBVVec3___N44_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x18ABF10));
	_spawnItem_Spawner__QEAAPEAVItemActor__AEAVBlockSource__AEBVItemStack__PEAVActor__AEBVVec3__H_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x18AC0A0));
	__0ActorDefinitionIdentifier__QEAA_W4ActorType___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x12ECB50));
	__initialize_ActorDefinitionIdentifier__AEAAXXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x12ECEA0));
	__extractIdentifier_ActorDefinitionIdentifier__CAXAEBV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__AEAU1__Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x12EC620));
	_computeHash_HashedString__SA_KPEBD_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x0E42550));
	_initFactory_ProjectileFactory__SAXXZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x146AD60));
	_EntityCanonicalName__YAAEBVHashedString__W4ActorType___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x1305C00));
	_EntityTypeToString__YA_AV_$basic_string_DU_$char_traits_D_std__V_$allocator_D_2__std__W4ActorType__W4ActorTypeNamespaceRules___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x13057E0));
	__0ItemSpriteRenderer__QEAA_AEAVTextureGroup_mce__PEAVItem___N_Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x0983AB0));
	__1ItemSpriteRenderer__UEAA_XZ_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x0983BC0));
	_initializeEntityRenderers_ActorRenderDispatcher__QEAAXAEAVGeometryGroup__AEAVTextureGroup_mce__AEAVBlockTessellator__AEBVActorResourceDefinitionGroup__AEBVSemVersion___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x093D2A0));
	_getRenderer_ActorRenderDispatcher__QEBAPEAVActorRenderer__AEBVHashedString___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x09410E0));
	_getDataDrivenRenderer_ActorRenderDispatcher__QEBAPEAVDataDrivenRenderer__AEBVHashedString___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x09410E0));
	_registerActorInfo_ActorInfoRegistry__QEAAXAEBUActorInfo___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x12F8840));
	_setDefinitionGroup_ActorFactory__QEAAXPEAVActorDefinitionGroup___Z_ptr = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x12ED4C0));
	Item_vtable = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x2B766C0));
	DiggerItem_vtable = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x2B72240));
	BlockPlanterItem_vtable = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x2B6F570));
	BlockItem_vtable = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x2B6F258));
	BlockLegacy_vtable = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x2B8E7D0));
	HeavyBlock_vtable = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x2BA8488));
	ItemInstance_vtable = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x2B769D8));
	ItemStack_vtable = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x2B76AD8));
	Actor_vtable = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x2B14130));
	Mob_vtable = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x2B442F0));
	Player_vtable = reinterpret_cast<void*>(Zenova::Hook::SlideAddress(0x2B59C90));
}

#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpReserved) {
	if(fdwReason == DLL_PROCESS_ATTACH) InitBedrockPointers();
	return TRUE;
}
