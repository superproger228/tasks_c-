#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    int circle=0, square=100000, R=1;
    double x,y, Pi;

    for (int i = 1; i <= square; ++i) {
        x=2.0*double(rand())/(RAND_MAX-1);
        y=2.0*double(rand())/(RAND_MAX-1);
        x=abs(x-R);
        y=abs(y-R);
        if ((x*x)+(y*y)<1){
            circle+=1;
        }
    }
    Pi=(4.0*circle/square);
    cout << "Число Пи = " << Pi << endl;
    return 0;
}
