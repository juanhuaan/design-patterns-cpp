//
//  RoomWithBomb.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/13/25.
//

#pragma once
#include "Room.hpp"
#include <iostream>

class RoomWithBomb : public Room {
public:
    explicit RoomWithBomb(int roomNo) : Room(roomNo), bombArmed(true) {}

    void enter() override {
        if (bombArmed) {
            std::cout << "💥 You entered Room " << getRoomNum() << ". The bomb explodes! Game over.\n";
            bombArmed = false;  // 一次性爆炸
        } else {
            std::cout << "🔁 You entered Room " << getRoomNum() << ". The bomb already exploded.\n";
        }
    }

private:
    bool bombArmed;
};
