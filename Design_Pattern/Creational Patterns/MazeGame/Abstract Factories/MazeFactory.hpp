
#pragma once
#include <memory>

class Room;
class Wall;
class Door;

class MazeFactory {
public:
    virtual std::shared_ptr<Maze> makeMaze() const = 0;
    virtual std::shared_ptr<Room> makeRoom(int roomNum) const = 0;
    virtual std::shared_ptr<Wall> makeWall() const = 0;
    virtual std::shared_ptr<Door> makeDoor(std::shared_ptr<Room> r1,
                                           std::shared_ptr<Room> r2) const = 0;

    //Destructor is a must, so that the smart pointer learn how to do the memory allocation
    virtual ~MazeFactory() = default;
};

