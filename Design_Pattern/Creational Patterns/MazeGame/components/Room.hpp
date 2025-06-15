#pragma once
#include "MapSite.hpp"
#include <memory>
#include <array>
#include <iostream>

class Room : public MapSite{
private:
    int _roomNumber;
    
    std::shared_ptr<MapSite> getSide(int direction) const {
        return _sides[direction];
    }
    
protected:
    std::array<std::shared_ptr<MapSite>, 4> _sides;
    Room(int num) : _roomNumber(num) {}
    
public:
    virtual void enter() = 0;
    virtual ~Room() = default;
    int getRoomNum() const {
        return _roomNumber;
    }
    
    void setSide(int direction, std::shared_ptr<MapSite> site) {
        _sides[direction] = site;
    }
};
