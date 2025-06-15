//
//  SingleRoom.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/14/25.
//

#pragma once
#include "Room.hpp"
#include <iostream>

class SimpleRoom : public Room {
public:
    explicit SimpleRoom(int roomNo) : Room(roomNo) {}

    void enter() override {
        std::cout << "🚪 You entered room " << getRoomNum() << ". It's quiet in here.\n";
    }
};
