/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Date : 8/4/2021
 * Problem : 1987
 */
#include <iostream>
#include <stack>
#define max_size 1000012
using namespace std;
int n;

struct segment{
    int l, r, ind;
}a[max_size];

stack<segment> s1;

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].l >> a[i].r;
        a[i].ind = i;
    }
    int q; cin >> q;
    int pivot = 1;
    while(q--){
        int co; //Input coordinates
        cin >> co;
        while(pivot <= n && a[pivot].l <= co){ //Okay, check coordinate's left and push it into stack
            s1.push(a[pivot]);
            pivot++;
        }
        while(!s1.empty() && s1.top().r < co){
            s1.pop();
        }
        if(s1.empty()){
            cout << "-1" << endl;
            continue;
        }
        segment t = s1.top();
        if (co >= t.l && co <= t.r){
            cout << t.ind << endl;
            continue;
        }
        cout << -1 << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}
