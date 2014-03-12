#include "Catalog.h"
#include <iostream>
#include <string>
using namespace std;

//unsigned int Product::counter = 1;

Catalog::Catalog()
{
  // add all the items into the catalog
  const string category[] = { "Music CD", "Books", "Magazines" };
  
  // add two music CDs
  Product CD1("Spirit", 9.99, category[0]);
  itemsForSale.push_back(CD1);
  Product CD2("Hola", 14.99, category[0]);
  itemsForSale.push_back(CD2);
  
  // add two books
  Product book1("Introduction to Algorithms", 13.00, category[1]);
  Product book2("The Missing Manual", 19.46, category[1]);
  itemsForSale.push_back(book1);
  itemsForSale.push_back(book2);
  
  // add two Magazines
  Product mag1("National Geographic", 5.00, category[2]);
  Product mag2("Popular Science", 7.25, category[2]);
  itemsForSale.push_back(mag1);
  itemsForSale.push_back(mag2);
}

void Catalog::printCatalog() const
{
  if (itemsForSale.empty())
  {
    cout << "The catalog is empty!" << endl;
    return;
  }
  
  // print header
  cout << '\n'
       << "     Product ID   Category            Description            Price\n"
       << "    ------------ ---------- ------------------------------- -------"
       << '\n';
  
  auto it = itemsForSale.begin();
  while (it != itemsForSale.end())
  {
    printf("%9c%-8i%-11s%-30s%8.2f\n", ' ', it->getID(), 
      it->getCategory().c_str(), it->getName().c_str(), it->getPrice());
    it++;
  }
  cout << '\n';
}

void Catalog::getProductInfo(const int prodID) const
{
  
  cout << "Details about the item " << prodID << endl;
}

const Product& Catalog::getProduct(const int prodID) const
{
  return itemsForSale.at(prodID - 1);
}