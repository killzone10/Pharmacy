#ifndef SUPLEMENT_H
#define SUPLEMENT_H
#include "Product.h"
class Suplement : public Product {
    private:
       double weight;
    public:
        // Suplement();
        Suplement(std::string name, std::string producent, double price , bool receipt,double weight);
        // ~Suplement();
        double get_weight();
        void print(std::ostream&os) const;

        void change_weight(double w);
                
};

#endif