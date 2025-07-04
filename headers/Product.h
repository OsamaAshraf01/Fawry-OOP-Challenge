//
// Created by OSAMA ASHRAF on 7/4/2025.
//

#ifndef FAWRY_OOP_TASK_PRODUCT_H
#define FAWRY_OOP_TASK_PRODUCT_H

#include <bits/stdc++.h>

using namespace std;

class Product {
    string name;
    int available_quantity;
    double price_in_dollars, weight_in_g;
    bool is_shippable, may_expire;
    time_t expiry_date;
public:

    Product(const string &name, int availableQuantity, double priceInDollars, double weightInG, bool isShippable,
            bool mayExpire);

    bool can_get(int quantity) const;

    pair<string, int> *get_some(int needed_quantity);

    bool is_expired();

    const string &getName() const;

    void setPrice(double priceInDollars);

    int getAvailableQuantity() const;

    double getWeight() const;

    double getPrice() const;
};


#endif //FAWRY_OOP_TASK_PRODUCT_H
