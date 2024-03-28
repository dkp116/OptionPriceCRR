#include "Option.h"
#include "BinomialModel.h"

double EurOption::PriceCRR(BinModel Model)
{
    double q= Model.RiskNeutralP();
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

int Call::GetInput()
{   
    int N;
    cout<< "Enter how many steps N"; cin >> N;
    SetN(N);
    cout << "Enter Strike Price"; cin >> K;
    SetK(K);
}

double Call::Payoff(double z)
{
    if (z>K) {return z-K};
    return 0.0;
}


