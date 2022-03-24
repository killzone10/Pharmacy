#include"Herb.h"


Herb::Herb(std::string name, std::string producent, double price, bool prescription, double weight):
                        Product(name,producent, price, prescription,"Herb"),weight(weight){};

double Herb::get_weight(){
    return weight;
};

void Herb::change_weight(double w){
    weight = w;
}

 void Herb::print(std::ostream& os) const {

     os <<  "|| weight : "<<weight;
 }
