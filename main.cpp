#include <bits/stdc++.h>
#include "headers/System.h"

using namespace std;

int main() {
    System e_commerce_system;

    vector<Product *> products = {
            new Product("Cheese", 100, 5.0, 100.0, true, true),
            new Product("Biscuits", 100, 10.0, 10.0, false, true),
            new Product("TV", 100, 5.0, 100.0, true, false),
            new Product("Mobile", 100, 5.0, 100.0, false, false)
    };

    // Feed system with products
    for (auto &product: products)
        e_commerce_system.add_product(product);

    vector<Customer *> customers = {
            new Customer("Osama", 100),
            new Customer("Ahmed", 200),
            new Customer("Omar", 300)
    };

    // Feed system with customers
    for (auto &customer: customers)
        e_commerce_system.add_customer(customer);


    Customer *customer1 = e_commerce_system.get_customer(0), *customer2 = e_commerce_system.get_customer(1);
    Product *product1 = e_commerce_system.get_product(0), *product2 = e_commerce_system.get_product(1);
    customer1->getCart()->add_item(product1, 5);
    customer1->getCart()->add_item(product2, 5);
    customer1->checkout();
    cout << "Available Quantity of " << product1->getName() << " is " << product1->getAvailableQuantity() << "\n";

    // invalid case 1
    customer2->getCart()->add_item(product1, 200);
    customer2->checkout();

    // invalid case 2
    customer2->empty_cart();
    customer2->checkout();

    // invalid case 3
    customer2->empty_cart();
    customer2->getCart()->add_item(product1, 40); // 40 * 5 = 200, but if we added shipping price it will be 202 > customer's balance
    customer2->checkout();

    // Another Valid case
    customer2->empty_cart();
    customer2->getCart()->add_item(product1, 39);
    customer2->checkout();
    cout << customer2->getBalance() << "\n";

    return 0;
}
