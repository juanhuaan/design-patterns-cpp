//
//  MyCreator.hpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/15/25.
//
#pragma once
#include <memory>
#include "Creator.hpp"
#include "Product.hpp"
#include "MyProduct.hpp"
class MyCreator : public Creator {
protected:
    std::shared_ptr<Product> createProduct() override {
        return std::make_shared<MyProduct>();
    }
};
