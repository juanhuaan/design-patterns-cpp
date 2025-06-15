#pragma once
#include "Wall.hpp"
#include <iostream>

class BombedWall : public Wall {
public:
    void enter() override {
        std::cout << "💥 You hit a bombed wall! It's charred and impassable.\n";
    }
};


