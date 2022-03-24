#ifndef PHARMACIST_H
#define PPHARMIST_H

#include "person.h"
#include "product.h"
#include <vector>
#include <memory>

class Pharmacist : public Person {

public:
  Pharmacist(std::string first_name, std::string last_name);

   std::unique_ptr<Product> produce();

};

#endif