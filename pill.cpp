#include"pill.h"


Pill::Pill(std::string name, std::string producent, double price, bool prescription, int tablets_count):
                        Product(name,producent, price, prescription,"Pill"),tablets_count(tablets_count){};

int Pill::get_tables_count(){
    return tablets_count;
};

 void Pill::print(std::ostream& os) const {

     os <<  "|| amount :   "<<tablets_count ;
 }
 void Pill::change_tables(int a){
     tablets_count = a;
 }