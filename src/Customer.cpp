//
// Created by OSAMA ASHRAF on 7/4/2025.
//

#include "../headers/Customer.h"

Customer::Customer(const string &name, double balance_in_dollars) {
    this->name = name;
    this->cart = new Cart();
    this->balance_in_dollars = balance_in_dollars;
}

void Customer::empty_cart() {
    this->cart->remove_all_items();
}

void Customer::checkout() {
    double shipping_price = cart->getShippingPrice();

    auto cart_status = cart->check_cart_status(balance_in_dollars - shipping_price);
    if (cart_status == ItemOutOfStockOrExpired)
        cout << "Can't complete checkout, some items in cart are expired or out of stock.\n";
    else if (cart_status == CartEmpty)
        cout << "Can't complete checkout, cart is empty.\n";
    else if (cart_status == BalanceInsufficient)
        cout << "Can't complete checkout, customer's balance is insufficient.\n";
    else {
        cout << "==========================\n";
        cout << "** Shipment notice **\n";
        for (auto [product, quantity]: cart->getItems()) {
            cout << quantity << "x " << product->getName() << "\t" << quantity * product->getWeight() << "g\n";
        }
        cout << "Total package weight " << cart->getTotalWeightInG() / 1000 << "kg\n";
        cout << "\n** Checkout receipt **\n";
        for (auto [product, quantity]: cart->getItems()) {
            cout << quantity << "x " << product->getName() << "\t" << quantity * product->getPrice() << "$\n";
        }
        cout << "----------------------\n";

        double total_price = cart->getTotalPriceInDollars();

        cout << "Subtotal\t" << total_price << "$\n";
        cout << "Shipping\t" << shipping_price << "$\n";
        cout << "Amount\t\t" << total_price + shipping_price << "$\n";
        cout << "Balance After\t" << balance_in_dollars - total_price - shipping_price << "$\n";
        cout << "============================\n";
        cart->checkout(balance_in_dollars);

        balance_in_dollars -= total_price + shipping_price;
    }
}

double Customer::getBalance() const {
    return balance_in_dollars;
}

Cart *Customer::getCart() const {
    return cart;
}
