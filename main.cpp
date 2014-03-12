#include "Catalog.h"
#include "ShoppingCart.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
using namespace std;

int printMainOptions();
void printProductOptions(const Catalog& catalog, ShoppingCart& cart);

enum options { ERROR, VIEW_CATALOG, VIEW_CART, PRINT_TO_FILE, CHECKOUT };

int main()
{
  Catalog catalog;
  ShoppingCart cart;
  int option = 0;
  while (option != CHECKOUT)
  {
    option = printMainOptions();
    switch (option)
    {
      case VIEW_CATALOG:
        catalog.printCatalog();
        printProductOptions(catalog, cart);
        break;
      case VIEW_CART:
        cart.printSummary();
        break;
      case PRINT_TO_FILE:
        cart.printSummaryToFile();
        break;
      case CHECKOUT:
        cart.checkout();
        break;
    }
  }
  return 0;
}

int printMainOptions()
{
  ostringstream oss;
  oss << "\nWelcome to Flow Science!\n";
  oss << "How can we help you today?\n";
  oss << "  1. Browse the catalog\n";
  oss << "  2. View my cart\n";
  oss << "  3. Print order summary to file\n";
  oss << "  4. Checkout / Exit\n";
  oss << "Please choose an option: ";
  cout << oss.str();
  int option;
  cin >> option;
  if (cin && option > 0 && option <= 4)
  {
    return option;
  }
  cin.clear();
  cin.ignore(200, '\n');
  cerr << "\nERROR: Sorry, that is an invalid option\n";
  return ERROR;
}

enum catalogOptions { RETURN, MORE_INFO, PLACE_ORDER };

void printProductOptions(const Catalog& catalog, ShoppingCart& cart)
{
  int response;
  cout << "  Would you like to\n"
       << "  0. Go back to main menu\n"
       << "  1. Get more information about a product\n"
       << "  2. Place order for one / multiple item(s)?\n"
       << "  Enter 0, 1, or 2: ";
  cin >> response;
  int prodID;
  if (response == MORE_INFO)
  {
    cout << '\n'
         << "  Which product would like to know more about?\n"
         << "  Product ID: ";
    cin >> prodID;
    catalog.getProductInfo(prodID);
  }
  else if (response == PLACE_ORDER)
  {
    cout << '\n'
         << "  Enter the ID(s) of the product you would like to buy\n"
         << "  To buy more than one item, separate product IDs with space\n"
         << "  Product ID(s): ";
    cin.ignore();
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<Product> list;
    while(iss >> prodID)
    {
      list.push_back(catalog.getProduct(prodID));
    }
    cart.addItem(list);
  }
}