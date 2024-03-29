#include "BinLattice.h"
#include "BinomialModel.h"
#include "Option.h"
#include <iostream>
using namespace std;

int main()
{
   BinModel Model;

   if (Model.GetInputData()==1) return 1;

   Put Option;
   Option.GetInputData();
   BinLattice<double> PriceTree;
   BinLattice<bool> StoppingTree;
   Option.PriceBySnell(Model,PriceTree,StoppingTree);
   cout << "American put prices:" << endl << endl;
   PriceTree.Display();
   cout << "American put exercise policy:"
        << endl << endl;
   StoppingTree.Display();
   return 0;
}