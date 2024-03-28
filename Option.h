// Create a Class for an Option
#ifndef Option_h
#define Option_h

#include "BinomialModel.h"

//Define class for  European Option
class EurOption { 

    private:
        int N;

    public:
        void SetN(int N_){N=N_;}
        virtual double Payoff(double z){return 0;}
        double PriceCRR(BinModel Model);

};

class Call: public EurOption
{
    private:
        double K; // The strike price for the option

    public:
        void SetK(double K_){K=K_;}
        int GetInput();
        double Payoff(double z);

};

class Put: public EurOption
{
    private:
        double K;
    public:
        void SetK(double K_){K=K_;}
        int GetInput();
        double Payoff(double z);
};


class DigitalCall: public EurOption
{
    private:
        double K1,K2;
    public:
        void SetK(double K1_, double K2_){K1=K1_; K2=K2_;}
        int GetInput();
        double Payoff(double S);

};

#endif