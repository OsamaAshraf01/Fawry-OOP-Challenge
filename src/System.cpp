//
// Created by OSAMA ASHRAF on 7/4/2025.
//

#include "../headers/System.h"

void System::add_customer(Customer* customer) {
    customers.push_back(customer);
}

void System::add_product(Product* product) {
    products.push_back(product);
}

void System::update_price(const string &product_name, double new_price) {
    for(auto& product : products){
        if(product->getName() == product_name) {
            product->setPrice(new_price);
            return;
        }
    }
}

Customer *System::get_customer(int id) {
    if(id >= customers.size())
        return nullptr;
    return customers[id];
}

Product *System::get_product(int id) {
    if(id >= products.size())
        return nullptr;
    return products[id];
}