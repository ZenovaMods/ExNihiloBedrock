#pragma once

#include "../util/StringHash.h"

enum class RedefinitionMode : signed char {
	KeepCurrent,
	UpdateToNewDefault
};

enum class AttributeOperands : int {
	OPERAND_MIN,
	OPERAND_MAX,
	OPERAND_CURRENT,
	TOTAL_OPERANDS,
	OPERAND_INVALID = 3
};

class Attribute {
	RedefinitionMode mRedefinitionMode;
	bool mSyncable;
	uint32_t mIDValue;
	HashedString mName;
};

class AttributeModifier {
	char filler[0x58];
public:
	virtual ~AttributeModifier();
};

class BaseAttributeMap {
	char filler[0x58];
};

class TemporalAttributeBuff {
	char filler[0x68];
};

class AttributeInstanceHandle {
	uint32_t mAttributeID;
	BaseAttributeMap* mAttributeMap;
};

class AttributeInstanceDelegate {
	AttributeInstanceHandle mAttributeHandle;
public:
	virtual ~AttributeInstanceDelegate();
};

class AttributeInstance {
	typedef std::vector<AttributeModifier> ModifierVector;

	BaseAttributeMap* mAttributeMap;
	const Attribute* mAttribute;
	ModifierVector mModifierList;
	std::vector<TemporalAttributeBuff> mTemporalBuffs;
	std::vector<AttributeInstanceHandle> mListeners;
	std::shared_ptr<AttributeInstanceDelegate> mDelegate;

	union {
		struct {
			float mDefaultValues[3];
		};
		struct {
			float mDefaultMinValue;
			float mDefaultMaxValue;
			float mDefaultValue;
		};
	};
	union {
		struct {
			float mCurrentValues[3];
		};
		struct {
			float mCurrentMinValue;
			float mCurrentMaxValue;
			float mCurrentValue;
		};
	};

public:
	float getMaxValue() const {
		return mCurrentMaxValue;
	}
	float getCurrentValue() const {
		return mCurrentValue;
	}
	void serializationSetValue(float currentValue, int operand, float maxValue) {
		if (operand >= 0 && operand < enum_cast(AttributeOperands::TOTAL_OPERANDS)) {
			mCurrentValues[operand] = (currentValue <= maxValue) ? currentValue : maxValue;
		}
	}
};

class SharedAttributes {
public:
	static Attribute* HEALTH;
};