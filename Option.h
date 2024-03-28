// Create a Class for an Option

#define Option_h

#include "BinomialModel.h"

//Define class for  European Option
class EurOption { 

    private:
        int N;

    public:
        void SetN(int N_){N=N_;}
        virtual double Payoff(double z){return 0;}
        double PriceCRR(BinModel insert);

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