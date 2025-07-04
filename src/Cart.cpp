//
// Created by OSAMA ASHRAF on 7/4/2025.
//

#include "../headers/Cart.h"

void Cart::add_item(Product* product, int quantity) {
    pair<Product*, int> item = {product, quantity};
    items.push_back(item);
    total_price_in_dollars += product->getPrice() * quantity;
    total_weight_in_g += product->getWeight() * quantity;
}

CartStatus Cart::check_cart_status(double balance) {
    if(items.empty())
        return CartEmpty;
    for(auto& [product, quantity]: items)
        if(!product->can_get(quantity) || product->is_expired())
            return ItemOutOfStockOrExpired;
    if(total_price_in_dollars > balance)
        return BalanceInsufficient;

    return CanCheckOut;
}

bool Cart::checkout(double balance) {
    if(check_cart_status(balance) != CanCheckOut)
        return false;

    for(auto& [product, quantity]: items)
        product->get_some(quantity);

    return true;
}

double Cart::getTotalPriceInDollars() const {
    return total_price_in_dollars;
}

double Cart::getTotalWeightInG() const {
    return total_weight_in_g;
}

const vector<pair<Product *, int>> &Cart::getItems() const {
    return items;
}

double Cart::getShippingPrice() {
    return total_weight_in_g / 1000 * 0.5; // %50 on weight
}

void Cart::remove_all_items() {
    items = {};
    total_weight_in_g = 0;
    total_price_in_dollars = 0;
}