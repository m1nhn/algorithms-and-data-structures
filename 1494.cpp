/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Date : 8/4/2021
 * Problem : 1494
 */

#include <iostream>
#include <deque>
using namespace std;
int m,n = 0,value,a = 1, last = 0;
deque<int> q1;

int peekBack(deque<int> &q){ //Get value of last element in deque
    return q.back();
}

void solve() {
    bool check = false;
    cin >> m;
    for (int i = 0; i < m; i++){
        cin >> value;
        while(a <= value) {
            q1.push_back(a);
            ++a;
        }
        //sort(q1.begin(), q1.end());
        if (peekBack(q1) != value) check = true;
        else q1.pop_back();
    }

    if (check) cout << "Cheater";
    else cout << "Not a proof";
}


int main(){
    solve();
    return 0;
}
