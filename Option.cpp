#include "Option.h"
#include "BinomialModel.h"





double EurOption::PriceCRR(BinModel Model)
{
    double q= Model.RiskNeutralP();
    int N = GetN();
    double Price[N+1];
    

    for (int i = 0; i<=N; i++)
        {
            Price[i]=Payoff(Model.S(N,i));
        }

        for(int n = N-1; n>= 0; n--)
        {   
            for (int i = 0; i<=n; i++)
            {
                Price[i]=(q*Price[i+1] + (1-q)*Price[i])/(1+Model.GetR());
            }


            }
            return Price[0];
}

double AmOption::PriceBySnell(BinModel Model)
{
    double q = Model.RiskNeutralP();
    int N = GetN();
    double Price[N+1];
    int ContVal;
    for (int i=0 ; i<=N; i++)
    {
        Price[i]=Payoff(Model.S(N,i));
        
    }

    for (int n = N-1;n>=0; n--)
    {
        for(int i =0; i<=n;i++)
        {
            ContVal= (Price[i+1]*q+Price[i]*(1-q))/(1+Model.GetR());
            Price[i]=Payoff(Model.S(n,i));
         if (ContVal>Price[i]) Price[i]=ContVal;

        }
    }
    return Price[0];
}

int Call::GetInput()
{   
    int N;
    cout<< "Enter how many steps N "; cin >> N;
    SetN(N);
    cout << "Enter Strike Price "; cin >> K;
    SetK(K);
}

double Call::Payoff(double z)
{
    if (z>K) {return z-K;}
    return 0.0;
}

int Put::GetInput()
{   
    int N;
    cout<< "Enter how many steps N "; cin >> N;
    SetN(N);
    cout << "Enter Strike Price "; cin >> K;
    SetK(K);
}

double Put::Payoff(double z)
{
    if (z<K) {return K-z;}
    return 0.0;
}

int DigitalCall::GetInput()
{
    cout<< " Enter Lower Strike"; cin >> K1;
    cout << "Enter Upper Strike" ; cin >> K2;
}

double DigitalCall::Payoff(double S)
{
    if(S>K1 && S<K2) {return 1.0;}
    return 0; 
}

