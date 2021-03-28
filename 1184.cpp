/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Problem : 1184 (Cable Master)
 * Date : 24/03/2021
 */
#include <iostream>
#include <iomanip>
using namespace std;
int n,k;
float a[100000];

int check(int middle){
    int count = 0;
    for (int i = 0; i < n; i++){
        count += (int)(a[i]/middle);
    }
    return count;
}

void solve(){
    cin >> n >> k;
    for (int i = 0; i < n ; i++){
        cin >> a[i];
        a[i] *= 100;
    }
    int l = 0, r = 1000000000;
    float res;
    while (l <= r){
        int mid = (l + r)/2;
        if (check(mid) >= k){
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << fixed << setprecision(2) << res/100;
}

int main(){
    solve();
}

