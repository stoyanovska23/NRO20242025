#include <iostream>
#include <cmath>

double calcAtan(double* x, int* N_steps) 
{
    if (std::abs(*x) >= 1.0) { 
        std::cerr << "Napaka: Ne konvergira za |x| >= 1" << std::endl;
        return 0.0;
    }

    double rezult = 0.0; 
    double clen = *x;    
    for (int n = 0; n < *N_steps; ++n) {
        if (n > 0) {
            clen *= -(*x) * (*x); 
        }
        rezult += clen / (2 * n + 1); 
    }
    return rezult;
}

// f(x) = e^(3x) * arctan(x/2)
double f(double x, int N_steps) 
{
    double x_pola = x / 2.0;                
    double atan_x_pola = calcAtan(&x_pola, &N_steps); 
    return exp(3 * x) * atan_x_pola;        
}

// Trapezna metoda 
double trapezoidal(double a, double b, int n, int N_steps) 
{
    double h = (b - a) / n; 
    double integral = 0.0;

    for (int i = 0; i <= n; ++i) 
    {
        double x = a + i * h; 
        double utez = (i == 0 || i == n) ? 1 : 2; 
        integral += utez * f(x, N_steps);
    }

    integral *= h / 2; 
    return integral;
}

int main() 
{
    double a = 0;                 
    double b = std::atan(1.0);   
    int n = 1000;                  
    int N_steps = 20;             

     
    double rezult = trapezoidal(a, b, n, N_steps);

    std::cout << "Resitev integrala je: " << rezult << std::endl;

    return 0;
}
