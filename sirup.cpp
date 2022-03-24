#include"sirup.h"


Sirup::Sirup(std::string name, std::string producent, double price, bool prescription, int capacity):
                        Product(name,producent, price, prescription,"Sirup"),capacity(capacity){};


int Sirup::get_capacity() const {
    return capacity;
}

void Sirup::change_capacity(int c){
    capacity = c;
}
 void Sirup::print(std::ostream& os) const {

     os <<  "||  capacity :  "<<capacity ;
 }