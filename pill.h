#ifndef PILL_H
#define PILL_H
#include "product.h"
class Pill : public Product {
   private:
         int tablets_count;

    public:
        // Pill();
        Pill(std::string name, std::string producent, double price, bool receipt, int tablets_count);
        // Herb(const Herb&source);
        // ~Pill();
        int get_tables_count();
        void print(std::ostream&os) const;
        void change_tables(int a);

};


#endif

