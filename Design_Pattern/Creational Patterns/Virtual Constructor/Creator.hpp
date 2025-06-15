#pragma once
#include <memory>
#include "Product.hpp"
class Creator {
public:
    std::shared_ptr<Product> getProduct() {
        if (!_product)
            _product = createProduct();  // Factory method
        return _product;
    }

protected:
    virtual std::shared_ptr<Product> createProduct() = 0;  // pure virtual

private:
    std::shared_ptr<Product> _product;
};

