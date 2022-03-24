#include "pharmacist.h"
#include "herb.h"
#include "pill.h"
#include "product.h"
#include "sirup.h"
#include "suplement.h"
#include <iostream>
#include <stdexcept>

Pharmacist::Pharmacist(std::string first_name, std::string last_name)
    : Person(first_name, last_name) {}

 std::unique_ptr<Product> Pharmacist::produce() {
  std::string name;
  std::string producent;
  int product_type;
  double price;
  int amount;
  int tablets_count;
  int capacity;
  double weight;
  
  std::cout << "name: " << std::endl;
  std::cin >> name;
  std::cout << "producent: " << std::endl;
  std::cin >> producent;
  std::cout << "product_type: " << std::endl;
  std::cin >> product_type;
  std::cout << "price: " << std::endl;
  std::cin >> price;
  std::cout << "amount: " << std::endl;
  std::cin >> amount;
   
  switch (product_type) {
  case 0:
    {
    std::cout << "tablets count: " << std::endl;
    std::cin >> tablets_count;
    auto p1  = std::make_unique<Pill>(name, producent,price, false, tablets_count);
    return std::move(p1);
    }
  case 1:
    {
    std::cout << "capacity: " << std::endl;
    std::cin >> capacity;
    auto p1  = std::make_unique<Sirup>(name, producent,  price,false, capacity);
    return std::move(p1);
    }
  case 2:
    {
    std::cout << "weight: " << std::endl;
     auto p1  = std::make_unique<Suplement>(name, producent, price,false, weight);
    return std::move(p1);
    }
  case 3:
    {
    std::cout << "weight: " << std::endl;
     auto p1  = std::make_unique<Herb>(name, producent, price,false, weight);
    return std::move(p1);
    }
  default:
  {
    throw std::invalid_argument("Invalid argument"); // zwroc fakowy produkt 
  }
  }
}