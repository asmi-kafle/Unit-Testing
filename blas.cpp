/*
BLAS Level 1 function definitions
*/

#include "blas.h"
#include <iostream>
#include <cmath>

using namespace std;


int amax(const double *x, const unsigned int len)
{

    //NEED TO LOOP THROUGH LIST AND COMPARE THE ABSOLUTE VALUE OF EACH ENTRY AND RETURN THE HIGHEST INDEX
    //need to loop for (len - 1) but since len is unsigned the integer i below is also unsigned.
    unsigned int maxIndex = 0;
   if(len==0){
            return -1;
        }else{ 
    double tmp = x[0];
    for (unsigned int i = 0; i < len; i++)
    {
        // cout << x[i] << "  |  "<< tmp << endl;
        //storing the number in the list
        double num = abs(x[i]);
        
            // cout << tmp << "    tmp" << endl;
            if (num>tmp)
            {
            //got a new highest number
            // cout << "new number  " << tmp << maxIndex << endl;
            maxIndex = i;
            tmp = num;
            }
            else{
            }
        }
    }

    // cout << "NOW RETURNING with index       " << maxIndex << endl;
return maxIndex;
}




double asum(const double *x, const unsigned int len)
{
    double sum = 0;
    if (x==0){
        return 0;
    }else{
    for (unsigned int i = 0; i < len; i++)
    {
        sum = sum + abs(x[i]);

    }
    // cout << sum << "   SUM" << endl;
    return sum;
    }
}

void axpy(const double a, const double *x, double *y, const unsigned int len)
{
    
//y s datd as y = a*x + y
    // cout << "this is axpy" << a << len <<endl;
    for (unsigned int i = 0; i < len; i++)
    {
        double k = x[i]*a;
        double j = k + y[i];
        y[i]=j;
    }
    
}

void copy(const double *src, double *dest, const unsigned int len)
{

    for (unsigned int i = 0; i < len; i++)
    {
        dest[i] = src[i];
        
    }
    cout << dest[0]<<endl;
}


double dot(const double *x, const double *y, const unsigned int len)
{
    double prod;
    for (unsigned int i = 0; i < len; i++)
    {
        prod += x[i]*y[i];
    }

    if (len==0){
    return 0;
    }
    else{
        return prod;
    }
}

double norm2(const double *x, const unsigned int len)
{
    double norm;
    if(len==0){
    return 0;
    }else{
    for (unsigned int i = 0; i < len; i++)
    {
        norm += x[i]*x[i];
    }

    norm = sqrt(norm);

    return norm;
    }
}

void scale(const double a, double *x, const unsigned int len)
{
    
    for (unsigned int i = 0; i < len; i++)
    {
        x[i] = x[i]*a;
    }
}

void swap(double *x, double *y, const unsigned int len)
{

    for (unsigned int i = 0; i < len; i++)
    {
        double tmp = x[i];
        x[i] = y[i];
        y[i] = tmp;
    }
}