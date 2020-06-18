#pragma once

#include "StringHash.h"

enum class ActorTypeNamespaceRules : int {
    ReturnWithoutNamespace,
    ReturnWithNamespace
};

struct ActorMapping {
    std::string mNamespace;
    std::string mPrimaryName;
    std::string mAlternateName;
    HashedString mCanonicalName;

    ActorMapping(const std::string& primary, const std::string& alt) : ActorMapping("minecraft", primary, alt) {}
    ActorMapping(const std::string& space, const std::string& primary, const std::string& alt) : mNamespace(space), mPrimaryName(primary), mAlternateName(alt) {
        mCanonicalName = HashedString(getMappingName(ActorTypeNamespaceRules::ReturnWithNamespace));
    }
    ActorMapping(const ActorMapping&) = default;
    ActorMapping(ActorMapping&&) = default;
    std::string getMappingName(ActorTypeNamespaceRules namespaceRule) const {
        if (namespaceRule == ActorTypeNamespaceRules::ReturnWithNamespace)
            return mNamespace + ":" + mPrimaryName;
        else
            return mPrimaryName;
    }
    const HashedString& getCanonicalName() const { return mCanonicalName; }
};