//
// Created by OSAMA ASHRAF on 7/4/2025.
//

#ifndef FAWRY_OOP_TASK_CART_H
#define FAWRY_OOP_TASK_CART_H
#include "Product.h"
#include <bits/stdc++.h>
enum CartStatus {CanCheckOut, BalanceInsufficient, ItemOutOfStockOrExpired, CartEmpty};
using namespace std;

class Cart {
    vector<pair<Product*, int>> items;
    double total_weight_in_g, total_price_in_dollars;
public:
    CartStatus check_cart_status(double balance);
    bool checkout(double balance);
    void add_item(Product* product, int quantity);

    double getTotalPriceInDollars() const;

    double getTotalWeightInG() const;

    const vector<pair<Product *, int>> &getItems() const;

    double getShippingPrice();

    void remove_all_items();
};


#endif //FAWRY_OOP_TASK_CART_H
