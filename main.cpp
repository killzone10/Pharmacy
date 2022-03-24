#include "customer.h"
#include "person.h"
#include "pharmacist.h"
#include "pill.h"
#include "product.h"
#include "provider.h"
#include "seller.h"
#include "sirup.h"
#include "storage.h"
#include <iostream>
#include <memory>
#include <random>
#include <random>
#include <iterator>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <ctime>

std::vector<std::string> menu = {"\ndisplay products sorted by amount",
                                 "display products sorted by price",
                                 "get product by name",
                                 "produce new product",
                                 "change price product",
                                 "handle client"
                                 "handle provider"};

std::string randomString(size_t length) {
  auto randchar = []() -> char {
    const char charset[] = "0123456789"
                           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                           "abcdefghijklmnopqrstuvwxyz";
    const size_t max_index = (sizeof(charset) - 1);
    return charset[rand() % max_index];
  };
  std::string str(length, 0);
  std::generate_n(str.begin(), length, randchar);
  return str;
}

double randomDouble(double fMin, double fMax) {
  double f = (double)rand() / RAND_MAX;
  return fMin + f * (fMax - fMin);
}

std::unique_ptr<Product> randomProduct() {
  int product_type = rand() % 4;
  std::string name = randomString(3);
  std::string producent = randomString(3);
  double price = randomDouble(5.0, 120.0);
  // int amount = rand() % 4 + 1;
  int tablets_count = rand() % 30 + 15;
  int capacity = rand() % 500 + 500;
  double weight = randomDouble(10, 100);

  switch (product_type) {
    case 0: {
      auto p1  = std::make_unique<Pill>(name, producent,price, false, tablets_count);
      // std::unique_ptr<Product> p1(new Pill(name, producent,price, false, tablets_count));
      return std::move(p1);
    }

    case 1: {
      auto p1  = std::make_unique<Sirup>(name, producent,  price,false, capacity);
      return std::move(p1);
    }

    case 2: {
      auto p1  = std::make_unique<Suplement>(name, producent, price,false, weight);
      return std::move(p1);
    }

    case 3: {
      auto p1  = std::make_unique<Herb>(name, producent, price,false, weight);
      return std::move(p1);
    }
  }
 auto p2  = std::make_unique<Product>(name, producent, price,false, "Product");
 return std::move(p2);

}

std::vector<std::unique_ptr<Product> > randomProducts() {
  // std::vector<Product> products;
  std::vector <std::unique_ptr<Product> >products;
  int n = rand() % 5;
  for (int i = 0; i < n; ++i) {
    products.push_back(std::move(randomProduct()));
  }
 return std::move(products);

};


int getUserChoice(Storage &storage, Person &user, Customer &customer,
                  Provider &provider) {
  std::cout << "CURRENT MONEY: " << storage.get_money() << std::endl;
  std::cout << "CURRENT CUSTOMER:" << std::endl;
  customer.display();
  std::cout << "CURRENT PROVIDER:" << std::endl;
  provider.display();

  int user_choice = 1;
  int menu_choice = 1;
  for (auto menu_option : menu) {
    std::cout << menu_choice << " - " << menu_option << std::endl;
    menu_choice++;
  }

  std::cin >> user_choice;
  return user_choice;
}

int main() {
  srand(time(NULL));
  Storage storage;
  storage.change_money(400);
  // auto a1 = std::make_unique<Pill>("Witamina A","Vitamex",7,false,10);
  Pharmacist pharmacist = Pharmacist("Adrian", "Trabka");
  Seller seller = Seller("Bartosz", "Krajewski");

  Customer customer = Customer(rand() % 500, Prescription(randomProducts()));
  
  Provider provider = Provider(randomProducts());
  while (true) {
    int choice = getUserChoice(storage, seller, customer, provider);
    try {
      switch (choice) {

      case 1: {
        storage.sort_by_amount();
        break;
      }

      case 2: {
        storage.sort_by_price();
        break;
      }

      case 3: {
        std::string name;
        std::string producent;
        std::cout << "name: ";
        std::cin >> name;
        std::cout << "producent: ";
        std::cin >> producent;
        storage.display_product_npr(name,producent);
        break;
      }

      case 5: {
        auto p1 = pharmacist.produce();
        storage.add_product(move(p1));
        break;
      }

      case 6: {
        std::string id;
        double new_price;
        std::cout << "ID: ";
        std::cin >> id;
        std::cout << "New price: ";
        std::cin >> new_price;
        storage.change_price(id, new_price);
        break;
      }

      case 7: {
        seller.handleCustomer(customer, storage);
        // customer = Customer(rand() % 500, Prescription(randomProducts()));
        break;
      }

      case 8: {
        seller.handleProvider(provider, storage);
        // provider = Provider(randomProducts());
        break;
      }
      }
    } catch (std::string err) {
      std::cerr << err << std::endl;
    }
    std::cout << std::endl << std::endl;
  }

  return 0;
}
