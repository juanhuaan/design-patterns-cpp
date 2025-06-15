//
//  Maze.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/13/25.
//
#pragma once
#include "Room.hpp"
#include <map>
#include <memory>

class Maze {
public:
    Maze() = default;

    void addRoom(std::shared_ptr<Room> room) {
        int number = room->getRoomNum();
        rooms[number] = room;
    }

    std::shared_ptr<Room> roomNo(int number) const {
        auto it = rooms.find(number);
        return (it != rooms.end()) ? it->second : nullptr;
    }

private:
    std::map<int, std::shared_ptr<Room>> rooms;
};

