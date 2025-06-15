//
//  Creator3.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/15/25.
//
#pragma once
#include <memory>
#include <functional>

template <typename ProductType>
class Creator3 {
    
public:
    using FactoryFunc = std::function<std::shared_ptr<ProductType>()>;
    explicit Creator3(FactoryFunc factory) : _factory(factory) {}
    std::shared_ptr<ProductType> getProduct() {
        if (!_product) {
            _product = _factory();
        }
        return _product;
    }
private:
    FactoryFunc _factory;
    std::shared_ptr<ProductType> _product;
};
