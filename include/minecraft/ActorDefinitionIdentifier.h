#pragma once

#include "StringHash.h"

enum class ActorType : int;

struct ActorDefinitionIdentifier {
    static const std::string NAMESPACE_SEPARATOR;
    static const std::string EVENT_BEGIN;
    static const std::string EVENT_END;
private:
    std::string mNamespace;
    std::string mIdentifier;
    std::string mInitEvent;
    std::string mFullName;
    HashedString mCanonicalName;

public:
    ActorDefinitionIdentifier() = default;
    ActorDefinitionIdentifier(const std::string& fullName) {
        _extractIdentifier(fullName, *this);
        _initialize();
    }
    ActorDefinitionIdentifier(const char* fullName) : ActorDefinitionIdentifier(std::string(fullName)) {}
    ActorDefinitionIdentifier(ActorType);
    ActorDefinitionIdentifier(const ActorDefinitionIdentifier&) = default;
    ActorDefinitionIdentifier(ActorDefinitionIdentifier&&) = default;
    ActorDefinitionIdentifier& operator=(const ActorDefinitionIdentifier&) = default;
    bool isEmpty() const { return mNamespace.empty() && mIdentifier.empty(); }
    void setIdentifier(const std::string& identifier) { mIdentifier = identifier; }
    void setInitEvent(const std::string& initEvent) { mInitEvent = initEvent; }
    const std::string& getNamespace() const { return mNamespace; }
    const std::string& getIdentifier() const { return mIdentifier; }
    const std::string& getInitEvent() const { return mInitEvent; }
    const std::string& getCanonicalName() const { return mCanonicalName.getString(); }
    const HashedString& getCanonicalHash() const { return mCanonicalName; }
    bool isVanilla() const { return mNamespace == "minecraft"; }
private:
    void _initialize();
    static void _extractIdentifier(const std::string&, ActorDefinitionIdentifier&);
};