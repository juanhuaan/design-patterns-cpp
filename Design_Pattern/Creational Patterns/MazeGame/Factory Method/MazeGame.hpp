#pragma once
#include "Maze.hpp"
#include "Room.hpp"
#include "Wall.hpp"
#include "Door.hpp"
#include "SimpleRoom.hpp"
#include <memory>

class MazeGame {
public:
    std::shared_ptr<Maze> createMaze() {
        std::shared_ptr<Maze> aMaze = makeMaze();
        std::shared_ptr<Room> room1 = makeRoom(1);
        std::shared_ptr<Room> room2 = makeRoom(2);
        std::shared_ptr<Door> theDoor = makeDoor(room1, room2);
        
        room1->setSide(North, makeWall());
        room1->setSide(East, theDoor);
        room1->setSide(South, makeWall());
        room1->setSide(West, makeWall());

        room2->setSide(North, makeWall());
        room2->setSide(East, makeWall());
        room2->setSide(South, makeWall());
        room2->setSide(West, theDoor);

        aMaze->addRoom(room1);
        aMaze->addRoom(room2);
        return aMaze;
    }

    // Virtual factory methods
    virtual std::shared_ptr<Maze> makeMaze() const {
        return std::make_shared<Maze>();
    }

    virtual std::shared_ptr<Room> makeRoom(int n) const {
        return std::make_shared<SimpleRoom>(n);
    }

    virtual std::shared_ptr<Door> makeDoor(std::shared_ptr<Room> r1, std::shared_ptr<Room> r2) const {
        return std::make_shared<Door>(r1, r2);
    }

    virtual std::shared_ptr<Wall> makeWall() const {
        return std::make_shared<Wall>();
    }
};

