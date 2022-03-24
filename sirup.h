#ifndef SIRUP_H
#define SIRUP_H
#include "product.h"


class Sirup : public Product {
   private:
        int capacity;

    public:
        // Sirup();
        Sirup(std::string name, std::string producent, double price, bool prescription, int capacity);
        int get_capacity() const ;
        void print(std::ostream&os) const;
        void change_capacity(int c);

};


#endif