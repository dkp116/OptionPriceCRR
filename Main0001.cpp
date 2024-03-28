#include "BinomialModel.h"
#include "Option.h"
#include <iostream>
using namespace std;

int main()
{
   BinModel Model;

   if (Model.InputValues()==1) return 1;

   Call Option1;
   Option1.GetInput();
   cout << "European call option price = "
        << Option1.PriceCRR(Model)
        << endl;
   cout << "American call option price = "
        << Option1.PriceBySnell(Model)
        << endl << endl;

   Put Option2;
   Option2.GetInput();
   cout << "European put option price = "
        << Option2.PriceCRR(Model)
        << endl;
   cout << "American put option price = "
        << Option2.PriceBySnell(Model)
        << endl << endl;

   return 0;
}