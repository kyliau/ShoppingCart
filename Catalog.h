#ifndef _CATALOG_H_
#define _CATALOG_H_

#include "Product.h"
#include <deque>
using namespace std;

enum category {  CD, BOOKS, MAGAZINES };

class Catalog
{
  private:
    deque<Product> itemsForSale;
    
  public:
    Catalog();
    void printCatalog() const;
    void getProductInfo(const int prodID) const;
    const Product& getProduct(const int prodID) const;
};

#endif 