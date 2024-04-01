#ifndef BinomialModel_h
#define BinomialModel_h
#include "Binlattice.h"
class BinModel
{
   private:
      double S0;
      double U;
      double D;
      double R;
      double N;

   public:
      //computing risk-neutral probability
      double RiskNeutProb();

      //computing the stock price at node n,i
      double S(int n, int i);

      //inputting, displaying and checking model data
      int GetInputData();

      double GetR();

      double GetN();

      void Tree(BinLattice<double>& Lol, BinModel S);

    
};

#endif
