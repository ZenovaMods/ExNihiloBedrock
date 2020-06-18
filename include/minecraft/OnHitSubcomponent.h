#pragma once

class Actor;
class ProjectileComponent;
namespace Json { class Value; }

class OnHitSubcomponent {
public:
    OnHitSubcomponent() = default;
    virtual ~OnHitSubcomponent() {}
    virtual void readfromJSON(Json::Value&) = 0;
    virtual void writetoJSON(Json::Value&) const = 0;
    virtual void doOnHitEffect(Actor&, ProjectileComponent&) = 0;
    static const char* getSubcomponentName() { return "onHit"; }
protected:
    bool _canAttack(Actor*, Actor*) const;
};