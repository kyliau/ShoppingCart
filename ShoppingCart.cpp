#include "ShoppingCart.h"
#include <iostream>
#include <vector>
using namespace std;

void ShoppingCart::checkout()
{
  printf("\n%s%6.2f\n", "  Your total is: $", calculateTotal());
  //cout << "  Your total is: " << calculateTotal() << endl;
  cout << "  Thank you for shopping with us today!\n";
}

double ShoppingCart::calculateTotal()
{
  double total = 0;
  auto it = itemsInCart.begin();
  while (it != itemsInCart.end())
  {
    total += (it->first.getPrice() * it->second);
    it++;
  }
  return total;
}

void ShoppingCart::addItem(vector<Product>& products)
{
  
  if (products.size() <= 0)
    return;
    
  cout << "\n  The following item(s) have been added to your cart.\n";
  // print header
  cout << '\n'
       << "    Product ID            Description            Price\n"
       << "   ------------ ------------------------------- -------"
       << '\n';
  /*
  for (unsigned int i = 0; i < products.size(); i++)
  {
    products[i].setQuantity(1);
    //itemsInCart.push_back(products[i]);
    //itemsInCart.insert(make_pair<Product, int>(products[i], 1));
    auto it = itemsInCart.find(products[i]);
    if (it != itemsInCart.end())
    {
      it->second++;
    }
    else
    {
      itemsInCart.emplace(products[i], 1);
    }
    printf("%9c%-7i%-30s%8.2f\n", ' ', products[i].getID(), 
    products[i].getName().c_str(), products[i].getPrice());
  }
  */
}

void ShoppingCart::printSummary()
{
  if (itemsInCart.empty())
  {
    cout << '\n'
         << "  Your cart is currently empty!\n";
    return;
  }
  
  cout << '\n'
       << "  You currently have " << itemsInCart.size() 
       << " items in your cart."
       << '\n';
  
  // print header
  cout << '\n'
       << "     Quantity            Description            Price\n"
       << "    ---------- ------------------------------- -------"
       << '\n';
  /*
  auto it = itemsInCart.begin();
  while (it != itemsInCart.end())
  {
    printf("%9c%-6i%-30s%8.2f\n", ' ', it->second, 
    it->first.getName().c_str(), it->first.getPrice());
    it++;
  }
  cout << '\n';
  */
}

void ShoppingCart::printSummaryToFile()
{

}
