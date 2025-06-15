//
//  MapSite.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/11/25.
//
#pragma once


enum Direction { North = 0, East, South, West };
class MapSite {
public:
    virtual void enter() = 0;
    virtual ~MapSite() = default;  // ✅ Needed for polymorphic shared_ptr
};

