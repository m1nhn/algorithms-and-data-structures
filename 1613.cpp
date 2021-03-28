/*
 * Author : Nguyen Le Minh
 * Group : N3251
 * Date : 25/3/2021
 * Problem : 1613
 */
#include <iostream>
using namespace std;
int n,q,x,y,z;

struct info{
    int idCity;
    int numTou;
}a[70001];

bool sortS(info m, info b){
    return (m.numTou < b.numTou) || (m.numTou == b.numTou && m.idCity < b.idCity);
}

void bSearch(int l, int r, int x1, int n1){
    int left = 0, right = n - 1;
    while(right >= left){
        int mid = (left + right)/2;
        if (a[mid].numTou == x1 && a[mid].idCity >= l && a[mid].idCity <= r){
            cout << "1";
            return;
        }
        else if (a[mid].numTou < x1 || (a[mid].numTou == x1 && a[mid].idCity < l)){
            left = mid + 1;
        }else if (a[mid].numTou > x1 || (a[mid].numTou == x1 && a[mid].idCity > r)){
            right = mid - 1;
        }
    }
    cout << "0";
    return;
}
void solver(){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i].numTou;
        a[i].idCity = i + 1;
    }
    sort(a, a + n, sortS);

    cin >> q;
    while(q--){
        cin >> x >> y >> z;
        bSearch(x,y,z,n);
    }
    cout << "\n";
}
int main(){
    solver();
    return 0;
}
