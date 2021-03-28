#include <iostream>
using namespace std;

const int MAXN = 1e5;
const int MAXSEG = 5e3;
int L[MAXN + 5],R[MAXN + 5];
int optR[MAXSEG + 2];
int idx[MAXSEG + 2];
int dp[MAXSEG + 2];
int trace[MAXSEG + 2];

bool cmp(int i,int j){
    return (L[i] < L[j]) || (L[i] == L[j] && R[i] < R[j]);
}

void solve(){
    int M; cin>>M;
    int n = 0;
    for(int i = 0;i <= MAXSEG;++i){
        optR[i] = MAXN;
        idx[i] = trace[i] = -1;
    }

    while(cin>>L[n]>>R[n]){
        if(L[n] == 0 && R[n] == 0){
            break;
        }
        if(R[n] >= 0){
            int r = min(R[n],M);
            int l = max(L[n],0);
            if(optR[r] > l){
                optR[r] = l;
                idx[r] = n;
            }
        }
        ++n;
    }
    for(int i = 0;i <= MAXSEG;++i){
        dp[i] = MAXN;
    }
    for(int i = 0;i <= MAXSEG;++i){
        if(optR[i] == 0){
            dp[i] = 1;
        }
    }
    for(int i = 0;i <= MAXSEG;++i){
        if(optR[i] == MAXN){
            continue;
        }
        for(int j = i;j >= optR[i];--j){
            if(dp[i] > dp[j] + 1){
                dp[i] = dp[j] + 1;
                trace[i] = j;
            }
        }
    }
    if(dp[M] == MAXN){
        cout<<"No solution"<<'\n';
    } else {
        cout<<dp[M]<<'\n';
        int ord[dp[M] + 5];
        int j = 0;
        while(true){
            ord[j++] = idx[M];
            M = trace[M];
            if(M < 0){
                break;
            }
        }
        sort(ord,ord + j,cmp);
        for(int i = 0;i < j;++i){
            cout<<L[ord[i]]<<' '<<R[ord[i]]<<'\n';
        }
    }
}
int main(){
    solve();
    return 0;
}


