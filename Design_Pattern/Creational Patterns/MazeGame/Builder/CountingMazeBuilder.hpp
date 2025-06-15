//
//  CountingMazeBuilder.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/14/25.
//

#pragma once
#include "MazeBuilder.hpp"
#include <memory>

class CountingMazeBuilder : public MazeBuilder {
public:
    CountingMazeBuilder() = default;

    void buildMaze() override {
        _rooms = 0;
        _doors = 0;
    }

    void buildRoom(int roomNo) override {
        ++_rooms;
    }

    void buildDoor(int roomFrom, int roomTo) override {
        ++_doors;
    }

    std::shared_ptr<Maze> getMaze() const override {
        return nullptr;  // No actual maze built
    }

    int getRoomCount() const { return _rooms; }
    int getDoorCount() const { return _doors; }
    void getCount(int& r, int& d) const {
        d = _doors;
        r = _rooms;
    }

private:
    int _doors{0};
    int _rooms{0};
};
