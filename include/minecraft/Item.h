#pragma once

#include <string>
#include <functional>

#include "SharedPtr.h"

class ItemInstance;
class ItemStack;
class ItemStackBase;
class Level;
class CompoundTag;
enum class Color;
class Player;
class BlockSource;
class Container;
class Vec3;
class Block;
class Mob;
class Actor;
class IDataInput;
class ReadOnlyBinaryStream;
class IDataOutput;
class ItemDescriptor;
enum class BlockShape;
enum class InHandUpdateType;
enum class ItemUseMethod;
class TextureUVCoordinateSet;
class TextureAtlasItem;
class FoodItemComponent;
class SeedItemComponent;
class CameraItemComponent;
class BlockLegacy;

#include "CreativeItemCategory.h"
#include "UseAnimation.h"

#include "BlockPos.h"
#include "TextureUVCoordinateSet.h"


typedef unsigned char byte;

class HashedString {
    unsigned long mStrHash;
    std::string mStr;
};
class SemVersion {
    uint16_t mMajor;
    uint16_t mMinor;
    uint16_t mPatch;
    std::string mPreRelease;
    std::string mBuildMeta;
    std::string mFullVersionString;
    bool mValidVersion;
    bool mAnyVersion;
};

class BaseGameVersion {
    SemVersion mSemVersion;
};

enum class CooldownType : int {
    TypeNone = -1,
    ChorusFruit,
    EnderPearl,
    IceBomb,
    Count
};

class Item {
protected:
    byte m_maxStackSize;
    std::string m_textureAtlasFile;
    int m_frameCount;
    bool m_animatesInToolbar;
    bool mIsMirroredArt;
    UseAnimation mUseAnim;
    const std::string* mHoverTextColorFormat;
    const TextureUVCoordinateSet* mIconTexture;
    const TextureAtlasItem* mIconAtlas;
    bool mUsesRenderingAdjustment;
    Vec3 mRenderingAdjTrans;
    Vec3 mRenderingAdjRot;
    float mRenderingAdjScale;
    short mId;
    std::string mDescriptionId;
    std::string mRawNameId;
    std::string mNamespace;
    HashedString mFullName;
    short mMaxDamage;
    bool mIsGlint : 1;
    bool mHandEquipped : 1;
    bool mIsStackedByData : 1;
    bool mRequiresWorldBuilder : 1;
    bool mExplodable : 1;
    bool mShouldDespawn : 1;
    bool mAllowOffhand : 1;
    bool mIgnoresPermissions : 1;
    bool mExperimental : 1;
    int mMaxUseDuration;
    BaseGameVersion mMinRequiredBaseGameVersion;
    WeakPtr<BlockLegacy> mLegacyBlock;
    CreativeItemCategory mCreativeCategory;
    Item* mCraftingRemainingItem;
    std::unique_ptr<FoodItemComponent> mFoodComponent;
    std::unique_ptr<SeedItemComponent> mSeedComponent;
    std::unique_ptr<CameraItemComponent> mCameraComponent;
    std::vector<std::function<void()>> mOnResetBAIcallbacks;
public:
    static bool* mInCreativeGroup;

    Item(const std::string&, short);
    virtual ~Item();
    virtual void tearDown();
    virtual int getMaxUseDuration(const ItemInstance*) const;
    virtual int getMaxUseDuration(const ItemStack*) const;
    virtual bool isExperimental(const ItemDescriptor*) const;
    virtual Item& setMaxStackSize(byte);
    virtual Item& setCategory(CreativeItemCategory);
    virtual Item& setStackedByData(bool);
    virtual Item& setMaxDamage(int);
    virtual Item& setHandEquipped();
    virtual Item& setUseAnimation(UseAnimation);
    virtual Item& setMaxUseDuration(int);
    virtual Item& setRequiresWorldBuilder(bool);
    virtual Item& setExplodable(bool);
    virtual Item& setIsGlint(bool);
    virtual Item& setShouldDespawn(bool);
    virtual BlockShape getBlockShape() const;
    virtual bool canBeDepleted() const;
    virtual bool canDestroySpecial(const Block&) const;
    virtual int getLevelDataForAuxValue(int) const;
    virtual bool isStackedByData() const;
    virtual short getMaxDamage() const;
    virtual int getAttackDamage() const;
    virtual bool isHandEquipped() const;
    virtual bool isArmor() const;
    virtual bool isDye() const;
    virtual bool isFertilizer(int) const;
    virtual bool isGlint(const ItemStackBase&) const;
    virtual bool isThrowable() const;
    virtual bool isPattern() const;
    virtual bool showsDurabilityInCreative() const;
    virtual bool isWearableThroughLootTable(const std::unique_ptr<CompoundTag>&) const;
    virtual bool canDestroyInCreative() const;
    virtual bool isDestructive(int) const;
    virtual bool isLiquidClipItem(int) const;
    virtual bool requiresInteract() const;
    virtual void appendFormattedHovertext(const ItemStackBase&, Level&, std::string&, const bool) const;
    virtual bool isValidRepairItem(const ItemInstance&, const ItemInstance&) const;
    virtual int getEnchantSlot() const;
    virtual int getEnchantValue() const;
    virtual int getArmorValue() const;
    virtual bool isComplex() const;
    virtual bool isValidAuxValue(int) const;
    virtual int getDamageChance(int) const;
    virtual bool uniqueAuxValues() const;
    virtual bool isMultiColorTinted(const ItemStack&) const;
    virtual Color getColor(const std::unique_ptr<CompoundTag>&, const ItemDescriptor&) const;
    virtual Color getBaseColor(const ItemStack&) const;
    virtual Color getSecondaryColor(const ItemStack&) const;
    virtual void saveAdditionalData(const ItemStackBase&, CompoundTag&) const;
    virtual void readAdditionalData(ItemStackBase&, const CompoundTag&) const;
    virtual bool isTintable() const;
    virtual ItemStack& use(ItemStack&, Player&) const;
    virtual bool dispense(BlockSource&, Container&, int, const Vec3&, unsigned char) const;
    virtual ItemUseMethod useTimeDepleted(ItemInstance&, Level*, Player*) const;
    virtual ItemUseMethod useTimeDepleted(ItemStack&, Level*, Player*) const;
    virtual void releaseUsing(ItemInstance&, Player*, int) const;
    virtual void releaseUsing(ItemStack&, Player*, int) const;
    virtual float getDestroySpeed(const ItemInstance&, const Block&) const;
    virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
    virtual void hurtEnemy(ItemStack&, Mob*, Mob*) const;
    virtual bool mineBlock(ItemInstance&, const Block&, int, int, int, Actor*) const;
    virtual bool mineBlock(ItemStack&, const Block&, int, int, int, Actor*) const;
    virtual std::string buildDescriptionId(const ItemDescriptor&, const std::unique_ptr<CompoundTag>&) const;
    virtual std::string buildEffectDescriptionName(const ItemStackBase&) const;
    virtual std::string buildCategoryDescriptionName() const;
    virtual void readUserData(ItemStackBase&, IDataInput&, ReadOnlyBinaryStream&) const;
    virtual void writeUserData(const ItemStackBase&, IDataOutput&) const;
    virtual byte getMaxStackSize(const ItemDescriptor&) const;
    virtual bool inventoryTick(ItemStack&, Level&, Actor&, int, bool) const;
    virtual void refreshedInContainer(ItemStackBase&, Level&) const;
    virtual CooldownType getCooldownType() const;
    virtual int getCooldownTime() const;
    virtual void fixupOnLoad(ItemStackBase&) const;
    virtual void fixupOnLoad(ItemStackBase&, Level&) const;
    virtual short getDamageValue(const std::unique_ptr<CompoundTag>&) const;
    virtual void setDamageValue(ItemStackBase&, short) const;
    virtual InHandUpdateType getInHandUpdateType(const Player&, const ItemInstance&, const ItemInstance&, const bool, const bool) const;
    virtual InHandUpdateType getInHandUpdateType(const Player&, const ItemStack&, const ItemStack&, const bool, const bool) const;
    virtual bool isSameItem(const ItemStackBase&, const ItemStackBase&) const;
    virtual std::string getInteractText(const Player&) const;
    virtual int getAnimationFrameFor(Mob*, bool, const ItemStack*, const bool) const;
    virtual bool isEmissive(int) const;
    virtual const TextureUVCoordinateSet& getIcon(const ItemStackBase&, int, bool) const;
    virtual int getIconYOffset() const;
    virtual Item& setIcon(const std::string&, int);
    virtual Item& setIcon(const TextureUVCoordinateSet&);
    virtual Item& setIconAtlas(const std::string&, int);
    virtual bool canBeCharged() const;
    virtual void playSoundIncrementally(const ItemInstance&, Mob&) const;
    virtual void playSoundIncrementally(const ItemStack&, Mob&) const;
    virtual std::string getAuxValuesDescription() const;

    Item& setAllowOffhand(bool offhand) {
        mAllowOffhand = offhand;
        return *this;
    }

    static const TextureAtlasItem& getTextureItem(const std::string&);
    static const TextureUVCoordinateSet& getIconTextureUVSet(const TextureAtlasItem&, int, int);

    static void beginCreativeGroup(const std::string&, Item*, short, const CompoundTag*);
    static void addCreativeItem(Item*, short);
    static void endCreativeGroup() {
        *mInCreativeGroup = false;
    }
private:
    virtual bool _checkUseOnPermissions(Actor&, ItemInstance&, const unsigned char&, const BlockPos&) const;
    virtual bool _checkUseOnPermissions(Actor&, ItemStack&, const unsigned char&, const BlockPos&) const;
    virtual bool _calculatePlacePos(ItemInstance&, Actor&, unsigned char&, BlockPos&) const;
    virtual bool _calculatePlacePos(ItemStack&, Actor&, unsigned char&, BlockPos&) const;
    virtual bool _useOn(ItemInstance&, Actor&, BlockPos, unsigned char, float, float, float) const;
    virtual bool _useOn(ItemStack&, Actor&, BlockPos, unsigned char, float, float, float) const;
};