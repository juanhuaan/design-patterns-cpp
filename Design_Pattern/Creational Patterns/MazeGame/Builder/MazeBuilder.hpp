//
//  MazeBuilder.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/14/25.
//
/**
 Usually, the builder does maintain state, like storing a pointer to the maze being constructed.
 So in most cases:
 You should remove const from these methods unless you’re certain your builder holds no internal mutable state.
 */
#pragma once
#include <memory>
#include "../Components/Maze.hpp"

class Maze;

class MazeBuilder {
public:
    virtual void buildMaze() = 0;
    virtual void buildRoom(int room) = 0;
    virtual void buildDoor(int roomFrom, int roomTo) = 0;
    virtual std::shared_ptr<Maze> getMaze() const = 0;
    virtual ~MazeBuilder() = default;
    
protected:
    MazeBuilder() = default;
    
};
