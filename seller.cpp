#include "seller.h"
#include "bill.h"
#include "customer.h"
#include "prescription.h"
#include "storage.h"
#include <iostream>
#include <memory>

Seller::Seller(std::string first_name, std::string last_name)
    : Person(first_name, last_name) {}

void Seller::handleCustomer(Customer &customer, Storage &storage) {
  Bill bill;
  Prescription prescription = customer.getPrescription();
 const auto &products = prescription.getProducts();

  for (auto &product : products) {
    if (!storage.product_is_available(product->get_name()))
      throw "Producnt isnt avaible";
    bill.appendProduct(*product);
  }
  double cost = bill.getCost();
  customer.decrease_money(cost);
  storage.increase_money(cost);

  for (auto &product : products) {
    storage.withdraw_product(product->get_name(),product->get_producent(),1);
    customer.appendProduct(*product);
  }
}

void Seller::handleProvider(Provider &provider, Storage &storage) {
  double cost = provider.get_cost();
  storage.decrease_money(cost);
  provider.increase_money(cost);
  auto &products = provider.getProducts();
  for (auto &product : products) {
    // auto p1 = std::make_unique<Product>(product);
    storage.add_product(std::move(product));
  }
}