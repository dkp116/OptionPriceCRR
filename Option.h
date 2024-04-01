#ifndef Option_h
#define Option_h
#include "Binlattice.h"
#include "BinomialModel.h"

class Option
{
   private:
      int N; //steps to expiry

   public:
      void SetN(int N_){N=N_;}
      int GetN(){return N;}
      virtual double Payoff(double z)=0;
};

class EurOption: public virtual Option
{
   public:
      //pricing European option
     
      double PriceByCRR(BinModel Model, BinLattice<double>& PriceTree);   //Create Pricing Tree and Price of Option
    
};

class AmOption: public virtual Option
{
   public:
      //pricing American option
      double PriceBySnell(BinModel Model,
         BinLattice<double>& PriceTree,
         BinLattice<bool>& StoppingTree);
};

class Call: public EurOption, public AmOption
{
   private:
      double K; //strike price

   public:
      void SetK(double K_){K=K_;}
      int GetInputData();
      double Payoff(double z);
};

class Put: public EurOption, public AmOption
{
   private:
      double K; //strike price

   public:
      void SetK(double K_){K=K_;}
      int GetInputData();
      double Payoff(double z);
};

class DoubleDigital: public EurOption, public AmOption
{
   private:
      double KL;
      double KU;

   public:
      void setK(double KU_ , double KL_){KU = KU_; KL = KL_;}  //Error with this 
      int GetInputData();
      double Payoff(double z);
};

#endif
