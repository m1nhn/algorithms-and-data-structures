#include <iostream>
using namespace std;

void solve(){
                int n; cin>>n;
                int a[n + 2],b[n + 2];
                for(int i = 0;i < n;++i){
                    cin>>a[i]>>b[i];
                    if(a[i] > b[i]){
                        swap(a[i],b[i]);
                    }
                }
                for(int i = 0;i < n;++i){
                    for(int j = 0;j < i;++j){
                        if(a[j] > a[i]){
                            swap(a[i],a[j]);
                            swap(b[i],b[j]);
                        } else if(a[j] == a[i] && b[j] > b[i]){
                            swap(a[i],a[j]);
                            swap(b[i],b[j]);
                        }
                    }
                }
                int dp[n + 2];
                int prev[n + 2];
                for(int i = 0;i < n;++i){
                    dp[i] = 1;
                    prev[i] = -1;
                }
                int mx = -1;
                int res = -1;
                for(int i = 0;i < n;++i){
                    for(int j = i - 1;j >= 0;--j){
                        if(b[j] <= a[i]){
                            if(dp[i] < dp[j] + 1){
                                dp[i] = dp[j] + 1;
                                prev[i] = j;
                            }
                        }
                    }
                    if(mx < dp[i]){
                        mx = dp[i];
                        res = i;
                    }
                }
                cout<<mx<<'\n';
                int u[n + 2],v[n + 2];
                int j = 0;
                while(res != -1){
                    u[j] = a[res];
                    v[j] = b[res];
                    j++;
                    res = prev[res];
                }
                for(int i = j - 1;i >= 0;--i){
                    cout<<u[i]<<' '<<v[i]<<'\n';
                }
            

int main(){
	solve();
}
