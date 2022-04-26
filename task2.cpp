#include <iostream>
#include <cstdlib>

using namespace std;

double getPi(int square)
{
    int circle=0, R=1;
    double x,y;

    for (int i = 1; i <= square; ++i) {
        x=double(std::rand())/RAND_MAX;
        y=double(std::rand())/RAND_MAX;
        x=abs(x-R);
        y=abs(y-R);
        if ((x*x)+(y*y)<1){
            circle+=1;
        }
    }
    return (4.0*circle/square);

}

int main() {
    int square;
    double Pi;
    cout << "Введите число точек" << endl;
    cin >> square;
    Pi = getPi(square);
    cout << "Число Пи = " << Pi << endl;
    return 0;
}
