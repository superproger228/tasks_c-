#include <iostream>
#include <cmath>

using namespace std;

long double f(long double x) {
    return 1/sqrtl(1-x*x);
}

long double integrateRectangle(long double (*f)(long double), long double from, long double to, int N) {
    const long double delta = (to-from)/N;
    long double ans = 0;
    for(int i = 0; i < N; ++i) {
        const long double xc = from + delta*i + delta/2;
        ans += delta*f(xc);
    }
    return ans;
}

long double integrateTrapezoid(long double (*f)(long double), long double from, long double to, int N) {
    const long double delta = (to-from)/N;
    long double ans = 0;
    for(int i = 0; i < N; ++i) {
        const long double x1 = from + delta*i;
        const long double x2 = x1 + delta;
        ans += delta*(f(x2)+f(x1))/2;
    }
    return ans;
}


long double integrateSimpson(long double (*f)(long double), long double from, long double to, int N) {
    const long double delta = (to-from)/N;
    long double ans = 0;
    for(int i = 0; i < N; ++i) {
        const long double x1 = from + delta*i;
        const long double x2 = x1 + delta;
        ans += (x2-x1)/6.0 * (f(x1) + 4.0*f(x1+(x2-x1)/2) + f(x2));
    }
    return ans;
}


int main() {
    cout << "Rectangular method: " << integrateRectangle(f, -1, 1, 1000000) << "\n";
    cout << "Trapezoid method: " << integrateTrapezoid(f, -1+0.00000001, 1-0.00000001, 1000000) << "\n";
    cout << "Simpson method: " << integrateSimpson(f, -1+0.00000001, 1-0.00000001, 1000000) << "\n";
    return 0;
}
