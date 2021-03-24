/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Problem : 1014
 * Date : 23/03/2021
 */
#include <iostream>
using namespace std;
#define MAX 50

void solve(int n) {
    int i, j = 0;
    int res[MAX];
    if (n == 0) {cout << "10" << endl; return;}
    if (n >= 1 && n <= 9) { //(If number is smaller than 10 to Q = N)
        cout << n;
        return;
    }
    for (i = 9; i > 1; i--) {
        while (n % i == 0) {
            n /= i;
            res[j] = i;
            j++;
        }
    }

    if (n > 10) {
        cout << "-1";
        return;
    }

    for(int x = j - 1;x >= 0;--x){
        cout << res[x];
    }
}

int main(){
    int n; cin >> n;
    solve(n);
}
