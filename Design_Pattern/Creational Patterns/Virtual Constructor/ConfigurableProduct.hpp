//
//  ConfigurableProduct.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/15/25.
//

#pragma once
#include "Product.hpp"
#include <iostream>

class ConfigurableProduct: public Product {
    
public:
    ConfigurableProduct(int value) : _val(value) {
        std::cout << "The configurableProduct value is:  " << value << std::endl;
    }
private:
    int _val;
};
