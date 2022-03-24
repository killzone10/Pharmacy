#include "person.h"
#include <string>

Person::Person() {
  this->first_name = "abc";
  this->last_name = "abc";
}

Person::Person(std::string first_name, std::string last_name) {
  this->first_name = first_name;
  this->last_name = last_name;
}

std::string Person::getName() {
  return this->first_name + " " + this->last_name;
}
