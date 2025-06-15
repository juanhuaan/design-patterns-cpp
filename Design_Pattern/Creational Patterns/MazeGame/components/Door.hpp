#pragma once
#include "MapSite.hpp"
#include "Room.hpp"
#include <iostream>
#include <memory>

class Door : public MapSite {
protected:
    std::shared_ptr<Room> room1;
    std::shared_ptr<Room> room2;

public:
    Door(std::shared_ptr<Room> r1, std::shared_ptr<Room> r2)
        : room1(r1), room2(r2) {}

    void enter() override {
        std::cout << "You pass through a shared door." << std::endl;
    }
    
};

