#include <iostream>
using namespace std;

int main() {
    double a[5],sum;
    for(int i = 0;i<5;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    printf("%.2lf",sum / 5.0);
}