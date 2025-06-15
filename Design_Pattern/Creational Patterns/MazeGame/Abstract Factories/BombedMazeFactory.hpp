#pragma once
#include "MazeFactory.hpp"
#include "Maze.hpp"
#include "Room.hpp"
#include "Wall.hpp"
#include "Door.hpp"
#include "RoomWithBomb.hpp"
#include <memory>

class BombedMazeFactory : public MazeFactory {
public:
    std::shared_ptr<Maze> makeMaze() const override {
        return std::make_shared<Maze>();
    }

    std::shared_ptr<Room> makeRoom(int roomNum) const override {
        return std::make_shared<RoomWithBomb>(roomNum);
    }

    std::shared_ptr<Wall> makeWall() const override {
        return std::make_shared<Wall>();
    }

    std::shared_ptr<Door> makeDoor(std::shared_ptr<Room> r1,
                                   std::shared_ptr<Room> r2) const override {
        return std::make_shared<Door>(r1, r2);
    }
};
