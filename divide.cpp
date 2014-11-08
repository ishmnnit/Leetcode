#include<iostream>
#include<cmath>
using namespace std;



int divide(int dividend , int divisor ) {
    int sign=1;
    if( dividend < 0 ) sign = -sign ;
    if( divisor < 0 ) sign = -sign ;

    long dividen = abs (dividend );
    long diviso = abs (divisor);
    
    int result=0;

    int div= diviso;
    int d=1;

    while(dividend > div ) {
        div=div<<1;
        d=d<<1;
    }

    d=d>>1;
    div=div>>1;

    while(dividen >= diviso ) {
        while( (dividen - div) >= 0 ) {
            dividen=dividen -div;
            result=result+d;
        }
        div=div>>1;
        d=d>>1;
    }
    return sign*result;

}




int main(){
    int dividend;
    int divisor;
    cout<< "Input dividend:";
    cin >> dividend;
    cout<<" Input divisor:";
    cin >> divisor;
    cout<< "Result:";
    cout<< divide(dividend,divisor);
}

