//
//  main.cpp
//  Design_Pattern
//
//  Created by Juanhua An on 6/15/25.
//
#include "MyProduct.hpp"
#include "ConfigurableProduct.hpp"
#include "MyCreator.hpp"
#include "Creator2.hpp"
#include "Creator3.hpp"
#include "Creator4.hpp"

int main_factory() {
    // If we don't use template we must create several virtual class which is subclassing for support different product, here MyCreator is creating MyProduct
    MyCreator creator;
    std::shared_ptr<Product> p1 = creator.getProduct();
    // Using Template will help us eleminate too many subclass issue, we don't need MyCreator.cpp to create the MyProduct
    Creator2<MyProduct> creator2;
    auto p = creator2.getProduct();  // returns shared_ptr<MyProduct>
    // creator3 provide a parameter passing where creator2 could not provide, sometime the product need a paramter passing for build the product, however, using Creator3 for simplicity when the creation is fixed. when 42 always 42,
    Creator3<Product> creator3([](){
        return std::make_shared<ConfigurableProduct>(42);
    });
    auto p2 = creator3.getProduct();
    
    std::string type = "B";
    Creator3<Product> creatorDynamic([&]() -> std::shared_ptr<Product>{
       if (type == "A") return std::make_shared<MyProduct>();
       else return std::make_shared<ConfigurableProduct>(12);
   });
   auto p3 = creatorDynamic.getProduct();
    // Use CreatorFlexible when you need runtime configurability.
    CreatorFlexible<Product, int> creator4([](int val) {
        return std::make_shared<ConfigurableProduct>(val);
    });

    int userInput = 55;
    auto product = creator4.getProduct(userInput);  // Now passes 55 into constructor
    return 0;
}
