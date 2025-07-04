//
// Created by OSAMA ASHRAF on 7/4/2025.
//

#include "../headers/Product.h"

bool Product::can_get(int quantity) const {
    return quantity <= available_quantity;
}

pair<string, int>* Product::get_some(int needed_quantity){
    if(!can_get(needed_quantity))
        return nullptr;

    this->available_quantity -= needed_quantity;
    auto item = new pair<string, int>(this->name, needed_quantity);
    return item;
}

const string &Product::getName() const {
    return name;
}

bool Product::is_expired() {
    time_t current_time;
    time(&current_time);

    return current_time > expiry_date;
}

Product::Product(const string &name, int availableQuantity, double priceInDollars, double weightInG, bool isShippable,
                 bool mayExpire) : name(name), available_quantity(availableQuantity), price_in_dollars(priceInDollars),
                                   weight_in_g(weightInG), is_shippable(isShippable), may_expire(mayExpire) {}

void Product::setPrice(double priceInDollars) {
    price_in_dollars = priceInDollars;
}

int Product::getAvailableQuantity() const {
    return available_quantity;
}

double Product::getWeight() const {
    return weight_in_g;
}

double Product::getPrice() const {
    return price_in_dollars;
}
