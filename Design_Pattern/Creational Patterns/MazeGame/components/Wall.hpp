
#pragma once
#include "MapSite.hpp"
#include <iostream>

class Wall : public MapSite {
public:
    void enter() override {
        std::cout << "[Wall] You bump into a cold, solid wall. There's no way through here." << std::endl;
    }
};
