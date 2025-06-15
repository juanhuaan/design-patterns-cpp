//
//  Spell.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/12/25.
//
#pragma once
#include <iostream>
#include <string>

class Spell {
public:
    explicit Spell(const std::string& description = "A mysterious magical spell")
        : _description(description)
    {
        std::cout << "[Spell] " << _description << " has been created." << std::endl;
    }

    void cast() const {
        std::cout << "[Spell] Casting: " << _description << std::endl;
    }

private:
    std::string _description;
};
