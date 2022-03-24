#ifndef HERB_H
#define HERB_H
#include  "Product.h"
class Herb: public Product {
   private:
       double weight;
    public:
        // Herb();
        Herb( std::string name, std::string producent, double price , bool receipt,double weight);
        // ~Herb();
        double get_weight();
        void print(std::ostream&os) const;
        void change_weight(double weight);
};

#endif