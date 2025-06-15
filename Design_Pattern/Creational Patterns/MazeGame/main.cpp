#include "Components/Maze.hpp"
#include "MazeGame2.hpp"
#include "Abstract Factories/EnchantedMazeFactory.hpp"
#include "Abstract Factories//BombedMazeFactory.hpp"
#include "Builder/StandardMazeBuild.hpp"
#include "Builder/MazeBuilder.hpp"
#include "Builder/CountingMazeBuilder.hpp"
#include "Factory Method/MazeGame.hpp"
#include "BombedMazeGame.hpp"
#include "EnchantedMazeGame.hpp"


int main1() {
    MazeGame2 game;
    int rooms = 0, doors = 0;
    CountingMazeBuilder cntBuilder;
    game.createMazeByBuilder(cntBuilder);
    cntBuilder.getCount(rooms, doors);
    std::cout << "The Maze has Rooms: " << rooms << " and Doors: " << doors << std::endl;

    std::cout << "Choose maze type: 1 = Bombed, 2 = Enchanted > ";
    int choice;
    std::cin >> choice;

    // Step 1: Choose factory based on input
    std::shared_ptr<MazeFactory> factory;

    if (choice == 1) {
        factory = std::make_shared<BombedMazeFactory>();
    } else {
        factory = std::make_shared<EnchantedMazeFactory>();  
    }

    // Step 2: Create builder with selected factory
    StandardMazeBuilder builder(factory);

    // Step 3: Let the game build the maze
    std::shared_ptr<Maze> maze = game.createMazeByBuilder(builder);

    // Step 4: Enter the starting room
    auto startRoom = maze->roomNo(1);
    if (startRoom) {
        startRoom->enter();  // Triggers room behavior
    } else {
        std::cout << "Failed to find room 1." << std::endl;
    }

    return 0;
}

int main2() {
    std::shared_ptr<MazeGame> game;
    std::cout << "Choose maze type: 1 = Bombed, 2 = Enchanted > ";
    int choice;
    std::cin >> choice;
    if (choice == 1)
        game = std::make_shared<BombedMazeGame>();
    else
        game = std::make_shared<EnchantedMazeGame>();

    auto maze = game->createMaze();  // polymorphic creation
    return 0;

}


