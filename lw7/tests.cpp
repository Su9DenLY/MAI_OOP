#include <gtest/gtest.h>

#include "druid.hpp"
#include "npc.hpp"
#include "orc.hpp"
#include "squirrel.hpp"
#include "visitor.hpp"

TEST(npc_test, accept_test) {
    std::shared_ptr<NPC> orc, druid, squirrel;
    orc = std::make_shared<Orc>("George", 0, 15);
    druid = std::make_shared<Druid>("John", 50, 15);
    squirrel = std::make_shared<Squirrel>("David", 100, 15);

    ASSERT_TRUE(druid->accept(orc));
    ASSERT_FALSE(orc->accept(orc));
    ASSERT_FALSE(squirrel->accept(orc));
    ASSERT_TRUE(squirrel->accept(druid));
    ASSERT_FALSE(orc->accept(druid));
    ASSERT_FALSE(druid->accept(druid));
    ASSERT_FALSE(orc->accept(squirrel));
    ASSERT_FALSE(druid->accept(squirrel));
    ASSERT_FALSE(squirrel->accept(squirrel));
}

TEST(npc_test, is_close_test) {
    std::shared_ptr<NPC> orc, druid, squirrel;
    orc = std::make_shared<Orc>("George", 0, 15);
    druid = std::make_shared<Druid>("John", 50, 15);
    squirrel = std::make_shared<Squirrel>("David", 100, 15);

    ASSERT_FALSE(orc->is_close(druid));
    ASSERT_FALSE(druid->is_close(squirrel));
    ASSERT_FALSE(squirrel->is_close(orc));
}

TEST(visitor_test, visit_test) {
    std::shared_ptr<NPC> orc, druid, squirrel;
    std::shared_ptr<Visitor> orc_visitor, druid_visitor, squirrel_visitor;
    orc = std::make_shared<Orc>("George", 0, 15);
    druid = std::make_shared<Druid>("John", 50, 15);
    squirrel = std::make_shared<Squirrel>("David", 100, 15);

    orc_visitor = std::make_shared<OrcVisitor>();
    druid_visitor = std::make_shared<DruidVisitor>();
    squirrel_visitor = std::make_shared<SquirrelVisitor>();

    ASSERT_FALSE(orc_visitor->visit(std::static_pointer_cast<Orc>(orc)));
    ASSERT_TRUE(orc_visitor->visit(std::static_pointer_cast<Druid>(druid)));
    ASSERT_FALSE(orc_visitor->visit(std::static_pointer_cast<Squirrel>(squirrel)));
    ASSERT_FALSE(druid_visitor->visit(std::static_pointer_cast<Orc>(orc)));
    ASSERT_FALSE(druid_visitor->visit(std::static_pointer_cast<Druid>(druid)));
    ASSERT_TRUE(druid_visitor->visit(std::static_pointer_cast<Squirrel>(squirrel)));
    ASSERT_FALSE(squirrel_visitor->visit(std::static_pointer_cast<Orc>(orc)));
    ASSERT_FALSE(squirrel_visitor->visit(std::static_pointer_cast<Druid>(druid)));
    ASSERT_FALSE(squirrel_visitor->visit(std::static_pointer_cast<Squirrel>(squirrel)));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}