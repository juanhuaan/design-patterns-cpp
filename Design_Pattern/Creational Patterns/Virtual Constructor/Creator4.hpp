//
//  Creator4.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/15/25.
//
#pragma once
#include <memory>
#include <functional>

template <typename ProductType, typename... Args>
class CreatorFlexible {
public:
    using FactoryFunc = std::function<std::shared_ptr<ProductType>(Args...)>;// the lambda need a input the type is Args

    explicit CreatorFlexible(FactoryFunc factory) : _factory(factory) {} //assign the input lambda to _factory

    std::shared_ptr<ProductType> getProduct(Args... args) {
        return _factory(std::forward<Args>(args)...);// call the lambda function here we assign the args into the lambda function args is the concreate value and Args is the type
    }

private:
    FactoryFunc _factory;
};
