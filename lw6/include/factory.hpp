#pragma once
#include "druid.hpp"
#include "npc.hpp"
#include "observer.hpp"
#include "orc.hpp"
#include "squirrel.hpp"

class Factory {
public:
    static std::shared_ptr<NPC> CreateNPC(const NpcType& type, const std::string& name, int x, int y) {
        std::shared_ptr<NPC> result;
        switch (type) {
            case NpcType::OrcType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Orc>(name, x, y));
                break;

            case NpcType::DruidType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Druid>(name, x, y));
                break;

            case NpcType::SquirrelType:
                result = std::static_pointer_cast<NPC>(std::make_shared<Squirrel>(name, x, y));
                break;
            default:
                break;
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }

    static std::shared_ptr<NPC> CreateNPC(std::istream& is) {
        std::shared_ptr<NPC> result;
        int type{0};
        if (is >> type) {
            switch (type) {
                case NpcType::OrcType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Orc>(is));
                    break;

                case NpcType::DruidType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Druid>(is));
                    break;

                case NpcType::SquirrelType:
                    result = std::static_pointer_cast<NPC>(std::make_shared<Squirrel>(is));
                    break;
                default:
                    break;
            }
        } else {
            std::cerr << "Unexpected NPC type:" << type << std::endl;
        }

        if (result) {
            result->subscribe(TextObserver::get());
            result->subscribe(FileObserver::get());
        }

        return result;
    }
};
