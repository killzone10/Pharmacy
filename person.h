#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
protected:
  std::string first_name;
  std::string last_name;

public:
  Person();
  Person(std::string first_name, std::string last_name);
  std::string getName();
};

#endif