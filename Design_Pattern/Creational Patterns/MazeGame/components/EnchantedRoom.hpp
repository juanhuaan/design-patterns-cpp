#pragma once
#include "Room.hpp"
#include "Spell.hpp"
#include <iostream>
#include <memory>

class EnchantedRoom : public Room {
private:
    std::shared_ptr<Spell> spell;

public:
    EnchantedRoom(int number, std::shared_ptr<Spell> s)
        : Room(number), spell(s) {}

    void enter() override {
        std::cout << "[EnchantedRoom] You feel a magical aura as you enter room " << getRoomNum() << "." << std::endl;

        const char* directions[] = { "North", "East", "South", "West" };
        for (int i = 0; i < 4; ++i) {
            std::cout << " ~ To the " << directions[i] << ": ";
            if (_sides[i]) {
                _sides[i]->enter();
            } else {
                std::cout << "mystical mist obscures your view." << std::endl;
            }
        }
    }
};
