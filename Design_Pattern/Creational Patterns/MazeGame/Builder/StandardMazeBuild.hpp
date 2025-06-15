
//
//  StandardMazeBuild.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/14/25.
//
#pragma once
#include "MazeBuilder.hpp"
#include "MazeFactory.hpp"
#include "Maze.hpp"
#include "Room.hpp"
#include "Door.hpp"
#include <memory>
#include <unordered_map>

class StandardMazeBuilder: public MazeBuilder {
public:
    StandardMazeBuilder(std::shared_ptr<MazeFactory> factory) :_factory(std::move(factory)){}
    
    void buildMaze() override {
        _currentMaze = std::make_shared<Maze>();
    }
    
    void buildRoom(int room) override {
        if (!_currentMaze->roomNo(room)) {
            auto curRoom = _factory->makeRoom(room);
            _currentMaze->addRoom(curRoom);
            for (int i = 0; i < 4; ++i) {
                curRoom->setSide(i, std::make_shared<Wall>());
            }
        }
    }
    
    void buildDoor(int roomFrom, int roomTo) override {
        auto r1 = _currentMaze->roomNo(roomFrom);
        auto r2 = _currentMaze->roomNo(roomTo);
        if (!r1 || !r2) {
           std::cerr << "Error: one or both rooms do not exist.\n";
           return;
        }
        
        auto door = _factory->makeDoor(r1, r2);
        r1->setSide(commonWall(r1, r2), door);  // East
        r2->setSide(commonWall(r2, r1), door);  // West
    }
    
    std::shared_ptr<Maze> getMaze() const override {
        return _currentMaze;
    }
    
private:
    std::shared_ptr<Maze> _currentMaze;
    std::shared_ptr<MazeFactory> _factory;
    
    Direction commonWall(std::shared_ptr<Room> r1, std::shared_ptr<Room> r2) {
        int r1Num = r1->getRoomNum();
        int r2Num = r2->getRoomNum();

        if (r1Num + 1 == r2Num) return East;
        if (r1Num - 1 == r2Num) return West;
        if (r1Num + 10 == r2Num) return South;
        if (r1Num - 10 == r2Num) return North;

        std::cerr << "Warning: unknown relative room position.\n";
        return North;  // fallback
    }
};
