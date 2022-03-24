#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include<iostream>


class Product {
    private:
        int id;
        static int counter; 
        std::string name;
        std::string producent;
        double price;
        bool prescription;
        std::string type;
        int amount;
        // std::optional

    public:
        Product();
        Product(std::string name, std::string producent, double price, bool prescription,std::string type);
        Product(const Product &source);
        ~Product();
        double get_price() const;
        int get_id() const;
        std::string get_name() const;
        std::string get_producent() const;
        bool get_prescription() const;
        friend std::ostream &operator<<(std::ostream &os, const Product &p);
        std::string get_type() const;
        virtual void print(std::ostream&os) const;
        int get_amount() const;
        void add_amount(int a);
        void remove_amount(int a);

        void change_id(int new_id);
        void change_name(std::string name);
        void change_producent(std::string producent);
        void change_prescription(bool prescription);
        void change_price(double price);
        void change_amount(int amount);
        
};


std::ostream &operator<<(std::ostream &os, const Product &p);




#endif