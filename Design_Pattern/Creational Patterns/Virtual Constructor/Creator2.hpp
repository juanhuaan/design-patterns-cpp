//
//  TemplateCreator.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/15/25.
//
#include <memory>
#pragma once

template <typename ProductType>
class Creator2 {
public:
    std::shared_ptr<ProductType> getProduct() {
        if (!_product) {
            _product = std::make_shared<ProductType>();
        }
        return _product;
    }
private:
    std::shared_ptr<ProductType> _product;
};
