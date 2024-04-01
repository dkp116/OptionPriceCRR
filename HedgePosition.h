#ifndef HedgePosition_h
#define HedgePosition_h

#include "BinLattice.h"
#include "BinomialModel.h"
#include "Option.h"


//Need to calculate x position first then y 

// x(1)=H1-H1/S1-S1

class Position
{

};

class XPosition
{
    public:
    void CalcXPosition(BinLattice<double>& Options, BinLattice<double>& StockPrices, BinLattice<double>& XPosition,BinModel Model) //Put the calcualted models in this 
    {
        int N = Model.GetN();
        XPosition.SetN(N);

        for (int n = N; n>0; n-- )
        {
            for(int i = 0 ; i<=n; i++)
            {
                int Value = (Options.GetNode(n,i+1)-Options.GetNode(n,i))/(StockPrices.GetNode(n,i+1)-StockPrices.GetNode(n,i));
                XPosition.SetNode(n,i,Value);
            }
        }
        
       


        //
        // //
        // // //
        // // // //
    }

};

#endif