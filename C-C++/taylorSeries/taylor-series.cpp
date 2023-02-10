#include <iostream>
#include <math.h>

using namespace std;

// Function to calculate the nth term of the Taylor series
double taylor_term(int n, double x)
{
    double term = 1;
    for (int i = 1; i <= n; i++)
    {
        term *= (x / i);
    }
    return term;
}

int main()
{
    // Calculate the Taylor series for e^x
    // up to the 10th term
    double x = 1.0;
    double sum = 1.0;
    for (int n = 1; n <= 10; n++)
    {
        sum += taylor_term(n, x);
    }
    cout << "e^x = " << sum << endl;

    // Calculate the Taylor series for sin(x)
    // up to the 10th term
    sum = 0.0;
    for (int n = 0; n <= 10; n++)
    {
        double term = taylor_term(n, x);
        // Alter the sign of the terms alternately
        if (n % 2 == 1)
            term *= -1;
        sum += term;
    }
    cout << "sin(x) = " << sum << endl;

    return 0;
}