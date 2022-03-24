#include "provider.h"
#include "person.h"
#include "product.h"
#include <iostream>
#include <vector>


Provider::Provider(std::vector<std::unique_ptr<Product> > products )
    : Person("babuszka", "i wilk") {
  this->money = 0;
  this->nip = "XYZ";
  printf("products");
  this->products = std::move(products);
}

double Provider::get_money() { return this->money; }

double Provider::get_cost() {
  double cost = 0;
  for (auto &product : this->products) {
    cost += product->get_price() * 1.1;
  }
  return cost;
}

void Provider::increase_money(double incrementor) { this->money += incrementor; }

std::vector<std::unique_ptr<Product> >&  Provider::getProducts() {
  if (this->products.size() <= 0)
    throw "wektor ujemny";
  return this->products;
}

void Provider::display() {
  for (auto &product : this->products) {
    std::cout<<*product<<std::endl;
  }
  std::cout << "COST: " << this->get_cost();
}