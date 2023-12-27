#pragma once
#include "npc.hpp"

class Visitor {
public:
    virtual bool visit(const std::shared_ptr<NPC>&) const = 0;
};

class OrcVisitor final : public Visitor {
public:
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::OrcType:
                result = false;
                break;

            case NpcType::DruidType:
                result = true;
                break;

            case NpcType::SquirrelType:
                result = false;
                break;
        }
        return result;
    }
};

class DruidVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::OrcType:
                result = false;
                break;

            case NpcType::DruidType:
                result = false;
                break;

            case NpcType::SquirrelType:
                result = true;
                break;
        }
        return result;
    }
};

class SquirrelVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::OrcType:
                result = false;
                break;

            case NpcType::DruidType:
                result = false;
                break;

            case NpcType::SquirrelType:
                result = false;
                break;
        }
        return result;
    }
};

class VisitorFactory {
public:
    static std::shared_ptr<Visitor> CreateVisitor(const NpcType& type) {
        std::shared_ptr<Visitor> result;
        switch (type) {
            case NpcType::OrcType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<OrcVisitor>());
                break;

            case NpcType::DruidType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<DruidVisitor>());
                break;

            case NpcType::SquirrelType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<SquirrelVisitor>());
                break;
            default:
                break;
        }
        return result;
    }
};
