#include "customer.h"
#include "bill.h"
#include "person.h"
#include "prescription.h"
#include "product.h"
#include <vector>
#include <memory>
#include "product.h"

Customer::Customer(double money,Prescription prescription) {
  this->first_name = "";
  this->last_name = "";
  this->money = money;
  this->prescription = std::move(prescription);
}

Prescription Customer::getPrescription() { 
  auto ptr = std::move(prescription);
  return ptr; 
  }

void Customer::decrease_money(double value) {
  double new_money = this->money - value;
  if (new_money < 0.0)
    throw "Brak pininedzy";
  this->money = new_money;
}

void Customer::appendProduct(Product &product) {
  this->products.push_back(product);
}

void Customer::display(){
  std::cout << " Money"<<std::endl;
  }

