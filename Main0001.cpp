#include "BinLattice.h"
#include "BinomialModel.h"
#include "Option.h"
#include "HedgePosition.h"

#include <iostream>
using namespace std;

int main()
{
   BinModel Model;


   if (Model.GetInputData()==1) return 1;

   BinLattice<double> OptionTree;
   BinLattice<double> StockTree;
   BinLattice<double> Xposition;
   Model.Tree(StockTree, Model);
   
   Call Option;
   Option.GetInputData();
   cout << "Put Option Price" << endl << endl;
   Option.PriceByCRR(Model,OptionTree);

   XPosition Hedge;

   Hedge.CalcXPosition(OptionTree,StockTree,Xposition,Model); /// European Option Price Incorrect, N needs to be the same , Check Hedging position

   cout << "Hedging Position" << endl << endl;

   Xposition.Display();

   


   /*
    Put Option;
   Option.GetInputData();
   BinLattice<double> PriceTree;
   BinLattice<bool> StoppingTree;
   Option.PriceBySnell(Model,PriceTree,StoppingTree);
   cout << "American Double Digital Barrier Prices:" << endl << endl;
   PriceTree.Display();
   cout << "American put exercise policy:"
        << endl << endl;
   StoppingTree.Display();
   return 0;
}

*/

}