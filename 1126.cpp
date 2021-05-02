/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Date : 7/4/2021
 */
#include <iostream>
#include <deque>
using namespace std;
int m,n = 0;

struct value{
    int vl;
    int index;
};

void solve(){
    cin >> m;
    value a1{};
    deque<value> d1;
    while((cin >> a1.vl) && a1.vl != -1){
        a1.index = n++;
        while(!d1.empty() && d1.front().index < n - m){
            d1.pop_front();
        }
        while(!d1.empty() && d1.back().vl < a1.vl){
            d1.pop_back();
        }

        d1.push_back(a1);

        if (n >= m){
            cout << d1.front().vl << endl;
        }
    }
}

int main(){
    solve();
    return 0;
}
