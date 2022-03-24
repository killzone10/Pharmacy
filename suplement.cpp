#include"suplement.h"


Suplement::Suplement(std::string name, std::string producent, double price, bool prescription, double weight):
                        Product(name,producent, price, prescription,"Suplement"),weight(weight){};

double Suplement::get_weight(){
    return weight;
};

 void Suplement::print(std::ostream& os) const {
     
     os << " || weight :  "<<weight;
 }


void Suplement::change_weight(double w){
    weight = w;
}
