
#include "prescription.h"
#include "product.h"
#include <vector>

Prescription::Prescription() {}

Prescription::Prescription(std::vector<std::unique_ptr<Product> > products) {
  this->products = move(products);
}

std::vector<std::unique_ptr<Product> > & Prescription::getProducts() { return this->products; }
