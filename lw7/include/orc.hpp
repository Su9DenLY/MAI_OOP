#pragma once
#include "npc.hpp"
#include "visitor.hpp"

class Orc final : public NPC {
public:
    Orc(const std::string&, int, int);
    Orc(std::istream&);

    virtual bool accept(const std::shared_ptr<NPC>&) const override;

    void print() override;
    void save(std::ostream&) override;

    friend std::ostream& operator<<(std::ostream&, Orc&);
};