
//
//  MyProduct.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/15/25.
//
#pragma once
#include "Product.hpp"
#include <iostream>

class MyProduct: public Product {
    
public:
    MyProduct(){
        std::cout << "This is MyProduct" << std::endl;
    };
};
