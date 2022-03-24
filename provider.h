#ifndef PROVIDER_H
#define PROVIDER_H

#include "person.h"
#include "product.h"
#include <vector>
#include <memory>

class Provider : public Person {
private:
  double money;
  std::string nip;
  std::vector<std::unique_ptr<Product> > products;

public:
  Provider(std::vector<std::unique_ptr<Product> > products);

  double get_money();
  double get_cost();
  void increase_money(double incrementor);
  std::vector<std::unique_ptr<Product> >& getProducts();
  void display();
};

#endif