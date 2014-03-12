#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>
using namespace std;

static unsigned int counter = 1;

class Product
{
  private:
    unsigned int productID;
    double price;
    string name;
    string category;
    unsigned int quantity;
    //static unsigned int counter;  // a counter for the productID
    
  public:
    Product(const string inName, const double inPrice, const string cat) : 
      productID(counter++), price(inPrice), name(inName), category(cat),
      quantity(0) {}
    void setQuantity(const int inQuantity) { quantity = inQuantity; }
    int getQuantity() const { return quantity; }
    string getCategory() const { return category; }
    double getPrice() const { return price; }
    int getID() const { return productID; }
    string getName() const { return name; }
    //void printInfo() = 0;
};

#endif 
