#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll k,s; cin>> k >>s;

    ll cnt=0;
    
    for(int x=0; x<=k; x++){
        for(int y=0; y<=k; y++){
            int z=s-(x+y);
            if(z>=0 && z<=k) cnt++;
        }
    }
    cout << cnt << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1; //cin >> t;
    while(t--) solve();
    return 0;
}