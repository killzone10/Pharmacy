#ifndef BILL_H
#define BILL_H

#include "product.h"
#include <vector>
#include <memory>


class Bill {
private:
  std::vector<Product> products;

public:
  Bill();
  void appendProduct(Product &product);
  double getCost();
};

#endif