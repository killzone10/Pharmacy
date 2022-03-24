#ifndef SELLER_H
#define SELLER_H

#include "customer.h"
#include "person.h"
#include "provider.h"
#include "storage.h"
#include <vector>

class Seller : public Person {
public:
  Seller(std::string first_name, std::string last_name);

  void handleCustomer(Customer &customer, Storage &storage);

  void handleProvider(Provider &provider, Storage &storage);
};

#endif