/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Problem : 1047 (Simple Calculations)
 * Date : 24/03/2021
 */
#include <iostream>
#include <iomanip>
using namespace std;
int n,i;
float a,b,c;

void solve(){
    cin >> n;
    cin >> a >> b; //a = a0, b = a_(n+1)
    float a1, sum = 0;
    for (i = 0; i < n; ++i){
        cin >> c;
        sum += (n - i) * c;
    }
    a1 = (n * a + b - 2 * sum) / (n + 1);
    cout << fixed << setprecision(2) << a1;
}

int main(){
    solve();
}

