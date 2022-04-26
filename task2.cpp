#include <iostream>
#include <cstdlib>

using namespace std;

double getPi(int square)
{
    int circle=0, R=1;
    double x,y, Pi;

    for (int i = 1; i <= square; ++i) {
        x=double(std::rand())/RAND_MAX;
        y=double(std::rand())/RAND_MAX;
        x=abs(x-R);
        y=abs(y-R);
        if ((x*x)+(y*y)<1){
            circle+=1;
        }
    }
    Pi=(4.0*circle/square);
    cout << "Число Пи = " << Pi << endl;
}

int main() {
    int square;
    cout << "Введите число точек" << endl;
    cin >> square;
    getPi(square);
    return 0;
}
