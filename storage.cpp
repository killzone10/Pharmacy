#include "storage.h"
#include <stdexcept>
#include <algorithm>
#include <string>


void Storage::add_product(std::unique_ptr<Product>p){
        //szukamy w liscie
         products.push_back(std::move(p));
        //  mapa[p->get_id()] = move(p);
            
};

void Storage::delete_product( const std::string& name) {
    products.erase(std::remove_if(products.begin(), products.end(), [&name](const std::unique_ptr<Product>& p) {
        return p->get_name() == name;
    }));
}

void Storage::check(){
    for (const auto &a : products){
        std::cout<<* a<< std::endl;
    }
};

void Storage::add_amount(std::string name,std::string producent1, int amount){
        //szukamy w liscie
        try{
            bool found = false;

            for(auto &el: products){
                if (el->get_name() == name && el->get_producent() == producent1){
                    el->add_amount(amount);
                    std::cout<< el->get_amount()<<std::endl;
                    found = true;
                }
            }
            if ( found == false ){
                // this->check();
                throw std::invalid_argument("Not found!");
                // printf("not fouud\n");
                // throw
            }
        }
        catch (const std::exception &e){
            std::cout <<"Exception: "<<e.what() << std::endl;
        }
    };

void Storage::withdraw_product(std::string name,std::string producent1, int amount = 1 ){
    try{
        bool found = false;
        for(auto &el: products){
            if (el->get_name() == name && el->get_producent() == producent1){
                el->remove_amount(amount);
                found = true;
            }
        }
        if ( found == false ){
            // this->check();
            throw std::invalid_argument("Not found!");
            // printf("not fouud\n");
            // throw
        }
        }
        catch (const std::exception &e){
                std::cout <<"Exception: "<<e.what() << std::endl;
        }
};

void Storage::display_product_id(int id){
    try{
        bool found = false;
        for(auto &el: products){
            if (el->get_id() == id ){
                std::cout<<* el<< std::endl;
                found = true;
            }
        }
        if ( found == false ){
            // this->check();
            throw std::invalid_argument("Not found!");
            // printf("not fouud\n");
            // throw
        }
        }
        catch (const std::exception &e){
                std::cout <<"Exception: "<<e.what() << std::endl;
        }
};


void Storage::display_product_name(std::string name){
    try{
        bool found = false;
        for(auto &el: products){
            if (el->get_name() == name ){
                std::cout<<* el<< std::endl;
                found = true;
            }
        }
        if ( found == false ){
            // this->check();
            throw std::invalid_argument("Not found!");
            // printf("not fouud\n");
            // throw
        }
        }
        catch (const std::exception &e){
                std::cout <<"Exception: "<<e.what() << std::endl;
        }
};


void Storage::display_product_producent(std::string producent){
    try{
        bool found = false;
        for(auto &el: products){
            if (el->get_producent() == producent ){
                std::cout<<* el<< std::endl;
                found = true;
            }
        }
        if ( found == false ){
            // this->check();
            throw std::invalid_argument("Not found!");
            // printf("not fouud\n");
            // throw
        }
        }
        catch (const std::exception &e){
                std::cout <<"Exception: "<<e.what() << std::endl;
        }
};

void Storage::display_product_npr(std::string name,std::string producent){
    try{
        bool found = false;
        for(auto &el: products){
            if (el->get_name() == name && el->get_producent() == producent ){
                std::cout<<* el<< std::endl;
                found = true;
            }
        }
        if ( found == false ){
            // this->check();
            throw std::invalid_argument("Not found!");
            // printf("not fouud\n");
            // throw
        }
        }
        catch (const std::exception &e){
                std::cout <<"Exception: "<<e.what() << std::endl;
        }
};


bool compare_price(std::unique_ptr<Product> &p1, std::unique_ptr<Product> &p2){
    return(p1->get_price()<p2->get_price());
}

bool compare_amount(std::unique_ptr<Product> &p1, std::unique_ptr<Product> &p2){
    return(p1->get_amount()<p2->get_amount());
}

bool compare_id(std::unique_ptr<Product> &p1, std::unique_ptr<Product> &p2){
    return(p1->get_id()<p2->get_id());
}

void Storage::sort_by_price(){
    std::sort(products.begin(),products.end(),compare_price);
    std:: cout << "Sorted by price: \n";
    for(auto &el: products){
        std::cout<<* el<< std::endl;
            }
 
}

void Storage::sort_by_amount(){
    std::sort(products.begin(),products.end(),compare_amount);
    std:: cout << "Sorted by amount: \n";
    for(auto &el: products){
        std::cout<<* el<< std::endl;
            }
 
}

void Storage::sort_by_id(){
    std::sort(products.begin(),products.end(),compare_id);
    std:: cout << "Sorted by ID: \n";
    for(auto &el: products){
        std::cout<<* el<< std::endl;
            }
 
}



void Storage::change_name(std::string name,std::string name1){
        //szukamy w liscie
        try{
            bool found = false;

            for(auto &el: products){
                if (el->get_name() == name ){
                    el->change_name(name1);
                    std::cout<< el->get_name()<<std::endl;
                    found = true;
                }
            }
            if ( found == false ){
                // this->check();
                throw std::invalid_argument("Not found!");
                // printf("not fouud\n");
                // throw
            }
        }
        catch (const std::exception &e){
            std::cout <<"Exception: "<<e.what() << std::endl;
        }
    };


void Storage::change_producent(std::string name,std::string producent){
        //szukamy w liscie
        try{
            bool found = false;

            for(auto &el: products){
                if (el->get_name() == name ){
                    el->change_producent(producent);
                    std::cout<< el->get_producent()<<std::endl;
                    found = true;
                }
            }
            if ( found == false ){
                // this->check();
                throw std::invalid_argument("Not found!");
                // printf("not fouud\n");
                // throw
            }
        }
        catch (const std::exception &e){
            std::cout <<"Exception: "<<e.what() << std::endl;
        }
    };


void Storage::change_prescription(std::string name,bool prescription){
        //szukamy w liscie
        try{
            bool found = false;

            for(auto &el: products){
                if (el->get_name() == name ){
                    el->change_prescription(prescription);
                    std::cout<< el->get_prescription()<<std::endl;
                    found = true;
                }
            }
            if ( found == false ){
                // this->check();
                throw std::invalid_argument("Not found!");
                // printf("not fouud\n");
                // throw
            }
        }
        catch (const std::exception &e){
            std::cout <<"Exception: "<<e.what() << std::endl;
        }
    };

void Storage::change_price(std::string name,double price){
        //szukamy w liscie
        try{
            bool found = false;

            for(auto &el: products){
                if (el->get_name() == name ){
                    el->change_price(price);
                    std::cout<< el->get_price()<<std::endl;
                    found = true;
                }
            }
            if ( found == false ){
                // this->check();
                throw std::invalid_argument("Not found!");
                // printf("not fouud\n");
                // throw
            }
        }
        catch (const std::exception &e){
            std::cout <<"Exception: "<<e.what() << std::endl;
        }
    };

void Storage::change_amount(std::string name,int amount){
        //szukamy w liscie
        try{
            bool found = false;

            for(auto &el: products){
                if (el->get_name() == name ){
                    el->change_amount(amount);
                    std::cout<< el->get_amount()<<std::endl;
                    found = true;
                }
            }
            if ( found == false ){
                // this->check();
                throw std::invalid_argument("Not found!");
                // printf("not fouud\n");
                // throw
            }
        }
        catch (const std::exception &e){
            std::cout <<"Exception: "<<e.what() << std::endl;
        }
    };


void Storage::change_id(std::string name,int id){
        //szukamy w liscie
        try{
            bool found = false;

            for(auto &el: products){
                if (el->get_name() == name ){
                    el->change_id(id);
                    std::cout<< el->get_id()<<std::endl;
                    found = true;
                }
            }
            if ( found == false ){
                // this->check();
                throw std::invalid_argument("Not found!");
                // printf("not fouud\n");
                // throw
            }
        }
        catch (const std::exception &e){
            std::cout <<"Exception: "<<e.what() << std::endl;
        }
    };



bool Storage::product_is_available(std::string name){
        bool found = false;
        for(auto &el: products){
            if (el->get_name() == name && el->get_amount() > 0 ){
                found = true;
            }
        }             
        return found;
        
};

double Storage::get_money(){
    return money;
}

void Storage::increase_money(double incrementor){
    money = money + incrementor ;

}

void Storage::decrease_money(double decrementator){
    money = money - decrementator ;
    
}

void Storage::change_money(double new_money){
    money = new_money;
}