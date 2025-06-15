#pragma once
#include "Door.hpp"
#include "Spell.hpp"
#include <iostream>
#include <memory>

class DoorNeedingSpell : public Door {
public:
    DoorNeedingSpell(std::shared_ptr<Room> r1, std::shared_ptr<Room> r2)
        : Door(r1, r2) {}

    void enter() override {
        std::cout << "[DoorNeedingSpell] You must cast a spell to pass through this door." << std::endl;
    }
};

