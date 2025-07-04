//
// Created by OSAMA ASHRAF on 7/4/2025.
//

#ifndef FAWRY_OOP_TASK_CUSTOMER_H
#define FAWRY_OOP_TASK_CUSTOMER_H

#include "Product.h"
#include "Cart.h"
#include <bits/stdc++.h>

using namespace std;

class Customer {
    string name;
    double balance_in_dollars;
    Cart *cart;
public:
    Customer(const string &name, double balance_in_dollars = 0);

    void checkout();

    void empty_cart();

    double getBalance() const;

    Cart *getCart() const;
};


#endif //FAWRY_OOP_TASK_CUSTOMER_H
