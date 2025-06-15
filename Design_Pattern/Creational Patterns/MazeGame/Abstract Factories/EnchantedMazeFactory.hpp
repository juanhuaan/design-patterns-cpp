#pragma once
#include "MazeFactory.hpp"
#include "Maze.hpp"
#include "EnchantedRoom.hpp"
#include "DoorNeedingSpell.hpp"
#include "Spell.hpp"
#include <memory>

class EnchantedMazeFactory : public MazeFactory {
public:
    std::shared_ptr<Maze> makeMaze() const override {
        return std::make_shared<Maze>();
    }

    std::shared_ptr<Room> makeRoom(int roomNum) const override {
        return std::make_shared<EnchantedRoom>(roomNum, castSpell());
    }

    std::shared_ptr<Wall> makeWall() const override {
        return std::make_shared<Wall>();
    }

    std::shared_ptr<Door> makeDoor(std::shared_ptr<Room> r1,
                                   std::shared_ptr<Room> r2) const override {
        return std::make_shared<DoorNeedingSpell>(r1, r2);
    }

protected:
    std::shared_ptr<Spell> castSpell() const {
        return std::make_shared<Spell>();
    }
};


