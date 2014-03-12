#ifndef _SHOPPING_CART_H_
#define _SHOPPING_CART_H_

#include "Product.h"
#include <unordered_map>
#include <deque>
#include <vector>
using namespace std;

class ShoppingCart
{
  private:
    //deque<Product> itemsInCart;
    unordered_map<Product, int> itemsInCart;
    double calculateTotal();
    
  public:
    void addItem(vector<Product>& products);
    void checkout();
    void printSummary();
    void printSummaryToFile();
};

#endif 
