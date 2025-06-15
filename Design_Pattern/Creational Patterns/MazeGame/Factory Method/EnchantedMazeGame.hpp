#pragma once
#include "MazeGame.hpp"
#include "EnchantedRoom.hpp"
#include "DoorNeedingSpell.hpp"
#include "Spell.hpp"
#include "Wall.hpp"

class EnchantedMazeGame : public MazeGame {
public:
    std::shared_ptr<Door> makeDoor(std::shared_ptr<Room> r1, std::shared_ptr<Room> r2) const override {
        return std::make_shared<DoorNeedingSpell>(r1, r2);
    }

    std::shared_ptr<Room> makeRoom(int n) const override {
        return std::make_shared<EnchantedRoom>(n, CastSpell());
    }

protected:
    std::shared_ptr<Spell> CastSpell() const {
        return std::make_shared<Spell>("✨ Basic enchantment");
    }
};
