#ifndef BinomialModel_h
#define BinomialModel_h

#include <iostream>
using namespace std;

class BinModel {
private: 
    double S0;
    double U;
    double D;
    double R;

public: 
    double GetR(); // Return R value
    double InputValues();  // Get input data for S0,U,D,R
    double RiskNeutralP(); // Find RNP
    double S(int n, int i); // Compute stock price 
};

#endif
