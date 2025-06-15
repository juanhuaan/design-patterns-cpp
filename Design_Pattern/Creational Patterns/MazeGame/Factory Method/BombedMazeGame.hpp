//
//  BombedMazeGame.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/14/25.
//

#pragma once
#include "MazeGame.hpp"
#include "RoomWithBomb.hpp"
#include "BombedWall.hpp"

class BombedMazeGame : public MazeGame {
public:
    BombedMazeGame() = default;

    std::shared_ptr<Wall> makeWall() const override {
        return std::make_shared<BombedWall>();
    }

    std::shared_ptr<Room> makeRoom(int n) const override {
        return std::make_shared<RoomWithBomb>(n);
    }
};
