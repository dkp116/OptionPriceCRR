

#include "BinomialModel.h"
#include<cmath>


 double BinModel::GetR(){return R;}

 double BinModel::InputValues()
 {

//Enter Data
    cout<< "Enter S0"; cin>> S0;
    cout<< "Enter U"; cin>> U;
    cout<< "Enter D"; cin>> D;
    cout<< "Enter R"; cin>> R;

//Validate data
    
    if(S0<=0.0||U<=-1.0 || D<=-1.0 || R <=-1.0)
    {   cout<< "Illegal Data range"<< endl;
        return 1;}

//Check for Arbritrage

    if(U<R ||D>R)
        {
            cout << "Arbritriage detected" << endl;
            return 1;
        
        }

    cout << "Input Data has been checked \n No Arbritrage" << endl;


 }


//Find RNP
 double BinModel::RiskNeutralP()
{

    return (R-D)/(U-D);

 }

//Find Stock Price with i Up steps over n periods

  double BinModel::S(int n, int i)
  {
    return S0*pow(1+U,i)*pow(1+D,n-i);
    
  }