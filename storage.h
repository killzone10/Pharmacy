#ifndef STORAGE_H
#define STORAGE_H
#include "Product.h"
#include <vector>
#include "sirup.h"
#include "pill.h"
#include "suplement.h"
#include "herb.h"
#include <memory>
#include <map>


class Storage {
    private:
        double money;
        std::vector<std::unique_ptr<Product>> products;
        // std::map<unsigned int,std::unique_ptr<Product>>mapa;

    public:
        void change_money (double new_money);
        double get_money();
        void increase_money(double incrementor);
        void decrease_money(double decrementor);
        void check();
        void add_product(std::unique_ptr<Product>);
        void add_amount(std::string name,std::string producent, int amount);
        void withdraw_product(std::string name,std::string producent1, int amount);
        void delete_product( const std::string& name);


        void amount_product(std::string name);
        void display_product_name(std::string name);
        void display_product_id(int i);
        void display_product_producent(std::string producent);
        void display_all();
        void display_product_npr(std::string name,std::string producent);

        
        void sort_by_price();
        void sort_by_amount();
        void sort_by_id();
        bool product_is_available(std::string name);
        void change_name(std::string name, std::string new_name);
        void change_producent(std::string name, std::string producent);
        void change_prescription(std::string name, bool prescription);
        void change_price(std::string name, double price);
        void change_amount(std::string name, int amount);
        void change_id(std::string name, int id);

        
       template<class T> 
        std::vector<T*> get_products_by_name (const std::string& name) {
        std::vector<T*> result;

        for(auto& p : products) {
            if(p->get_name() == name) {
                if(auto d = dynamic_cast<T*>(p.get())) {
                    result.push_back(d);
                }
            }
        }

        return result;
    }


};

bool compare_price(std::unique_ptr<Product> &p1, std::unique_ptr<Product> &p2);
bool compare_amount(std::unique_ptr<Product> &p1, std::unique_ptr<Product> &p2);
bool compare_id(std::unique_ptr<Product> &p1, std::unique_ptr<Product> &p2);


#endif