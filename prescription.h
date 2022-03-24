#ifndef PRESCRIPTION_H
#define PRESCRIPTION_H
#include "Product.h"
#include <vector>
#include <memory>

class Prescription {
private:
  std::vector<std::unique_ptr<Product> > products;

public:
  Prescription();
  Prescription(std::vector<std::unique_ptr<Product> > products);
  std::vector<std::unique_ptr<Product> > & getProducts();
};

#endif