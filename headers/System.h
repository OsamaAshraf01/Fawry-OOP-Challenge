//
// Created by OSAMA ASHRAF on 7/4/2025.
//

#ifndef FAWRY_OOP_TASK_SYSTEM_H
#define FAWRY_OOP_TASK_SYSTEM_H

#include "Product.h"
#include "Customer.h"
#include <bits/stdc++.h>

using namespace std;

class System {
public:
    vector<Product *> products;
    vector<Customer *> customers;

    void add_customer(Customer *customer);

    void add_product(Product *product);

    void update_price(const string &product_name, double new_price);

    Customer* get_customer(int id);
    Product* get_product(int id);
};


#endif //FAWRY_OOP_TASK_SYSTEM_H
