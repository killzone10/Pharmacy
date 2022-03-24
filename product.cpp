#include "product.h"
#include <stdexcept>

int Product::counter = 0;

Product::Product():name("default"),producent("default"), price(0), prescription(true),type("None"){
    id++;
};


Product::Product(std::string name, std::string producent, double price, bool prescription,std::string type) :
                            name(name),producent(producent), price(price), prescription(prescription),type(type),amount(0){
                                id = counter;
                                counter++;
                            };


Product::Product(const Product &source):name(source.name),producent(source.producent), price(source.price), prescription(source.prescription),amount(source.amount){
        id = counter;
        counter++;
};

Product::~Product(){
    counter --;
}

std::string Product::get_name() const {
    return name;
}

std::string Product::get_producent() const {
    return producent;
}

double Product::get_price() const{
    return price;
}
 int Product::get_id() const{
    return id;
}
 bool Product::get_prescription() const{
     return prescription;
 }
std::string Product::get_type() const{
     return type;
 }
 int Product::get_amount() const{
    return amount;
}
std::ostream &operator<<(std::ostream &os, const Product&p){
    os << "Id: " <<p.get_id() <<" || Nazwa :  "<< p.get_name() << "||  Producent: " << p.get_producent()
    << "||  Ilosc : " << p.get_amount() << "||  Prescription:  " << p.get_prescription()<<"||  Price: "<< p.get_price()<<"|| Typ: " <<  p.get_type() ;
    p.print(os);
    return os;
}


 void Product::print(std::ostream& os) const {

     
 }

void Product::add_amount(int a) { 
    amount = amount + a;
}

void Product::remove_amount(int a) { 
    int r;
    try { 
        r = a - amount;
        amount = amount - a;
        
        if (amount < a){
            
            throw  std::range_error("You want to take more than its possible - taking all and making amount = 0");
        }
    }
    catch(const std::exception &e){
        std::cout<< e.what() << " All is : " << r <<  std::endl;
        amount = 0 ;
    }
}

void Product::change_name(std::string new_name){
    name = new_name;
}
void Product::change_producent(std::string new_producent){
    producent = new_producent;
}
void Product::change_prescription(bool new_prescription){
    prescription = new_prescription;
}
void Product::change_price(double new_price){
     try { 
        
        if (new_price < 0){
            
            throw  std::range_error("Price can;t be less than 0 ");
        }
        price = new_price;
    }
    catch(const std::exception &e){
        std::cout<< e.what()<< std::endl;
        
    }
    
}

void Product::change_amount(int new_amount) { 
     try { 
       
        
        if (new_amount < 0){
            
            throw  std::range_error("Amount can't be negatiave");
        }
        amount = new_amount;
    }
    catch(const std::exception &e){
        std::cout<< e.what() <<  std::endl;
        
    }
}

void Product::change_id(int new_id){
    id = new_id;
}