#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "bill.h"
#include "person.h"
#include "prescription.h"
#include "product.h"
#include <vector>

class Customer : public Person {
private:
  double money;
  Prescription prescription;
  std::vector<Product> products;

public:
  Customer(double money, Prescription prescription);
  Prescription getPrescription();
  void decrease_money(double value);
  void appendProduct(Product &product);
  void display();
};

#endif