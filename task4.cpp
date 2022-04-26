#include <iostream>
#include <cmath>

using namespace std;

long double f(long double x) {
    return 1/sqrtl(1-x*x);
}

long double integrateRectangle(long double *Fvals, int N, long double delta) {
    long double ans = 0;
    for(int i = 0; i < N; ++i)
        ans += delta*Fvals[i];
    return ans;
}

long double integrateTrapezoid(long double *Fvals, int N, long double delta) {
    long double ans = 0;
    for(int i = 0; i < N-1; ++i)
        ans += delta*(Fvals[i+1]+Fvals[i])/2;
    return ans;
}


long double integrateSimpson(long double *Fvals, int N, long double delta) {
    long double ans = 0;
    for(int i = 0; i < N-2; i+=2) {
        const long double x1 = Fvals[i];
        const long double xc = Fvals[i+1];
        const long double x2 = Fvals[i+2];
        ans += 2*delta/6.0 * (x1 + 4.0*xc + x2);
    }
    return ans;
}


int main() {
    const int N = 100000;
    long double from = -0.99999999;
    long double to = 0.99999999;
    long double delta = (to-from)/N;
    long double values[N];
    for(int i = 0; i < N; ++i)
        values[i] = f(from + delta*i);


    cout << "Rectangular method: " << integrateRectangle(values, N, delta) << "\n";
    cout << "Trapezoid method: " << integrateTrapezoid(values, N, delta) << "\n";
    cout << "Simpson method: " << integrateSimpson(values, N, delta) << "\n";
    return 0;
}