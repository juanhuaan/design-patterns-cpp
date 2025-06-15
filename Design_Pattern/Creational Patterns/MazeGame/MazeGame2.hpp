#pragma once
#include <memory>
#include "Components/Maze.hpp"
#include "Components/Room.hpp"
#include "Components/MapSite.hpp"
#include "Components/Wall.hpp"
#include "Components/Door.hpp"
#include "MazeFactory.hpp"
#include "Builder/MazeBuilder.hpp"

class MazeGame2 {
public:
    std::shared_ptr<Maze> createMaze(MazeFactory& factory) {
        auto maze = std::make_shared<Maze>();

        auto room1 = factory.makeRoom(1);
        auto room2 = factory.makeRoom(2);
        auto door = factory.makeDoor(room1, room2);

        // Helper function to cast to MapSite

        auto toSiteWall = [](const std::shared_ptr<Wall>& wall) -> std::shared_ptr<MapSite> {
            return std::static_pointer_cast<MapSite>(wall);
        };
        auto toSiteDoor = [](const std::shared_ptr<Door>& door) -> std::shared_ptr<MapSite> {
            return std::static_pointer_cast<MapSite>(door);
        };

        room1->setSide(North, toSiteWall(factory.makeWall()));
        room1->setSide(East, toSiteDoor(door));
        room1->setSide(South, toSiteWall(factory.makeWall()));
        room1->setSide(West, toSiteWall(factory.makeWall()));

        room2->setSide(North, toSiteWall(factory.makeWall()));
        room2->setSide(East, toSiteWall(factory.makeWall()));
        room2->setSide(South, toSiteWall(factory.makeWall()));
        room2->setSide(West, toSiteDoor(door));

        maze->addRoom(room1);
        maze->addRoom(room2);

        return maze;
    }
    
    std::shared_ptr<Maze> createMazeByBuilder(MazeBuilder& builder) {
        builder.buildMaze();
        builder.buildRoom(1);
        builder.buildRoom(2);
        builder.buildDoor(1, 2);
        return builder.getMaze();
    }
};

