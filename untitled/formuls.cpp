#include "iostream"
#include "math.h"
#include "stdio.h"
#include "string.h"

double Lvent(double K,double R, double Tn, double Pv, double Nven)
{
    return (K/(K-1)*R*Tn*(pow(Pv,(K/(K-1)))-1)*(1/Nven));
}

double TKVDvh(double Tn, double Lvent, double K, double R)
{
    return (Tn+(Lvent/(K/(K-1))*R));
}

double RKVDvh(double Pv, double Pn, double qvh, double qVNA, double qpereh)
{
    return (Pv*Pn*(qvh*qVNA/qpereh));
}

double LKVD(double K, double R )
{
    return 0;
}
