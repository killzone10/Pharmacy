#include "bill.h"
#include "product.h"
#include <vector>

Bill::Bill() {}

void Bill::appendProduct(Product &product ) { this->products.push_back(product); }

double Bill::getCost() {
  if (this->products.empty())
    throw "bill is empty";
  double cost = 0.0;
  for (auto &product : this->products)
    cost += product.get_price();
  return cost;
}
