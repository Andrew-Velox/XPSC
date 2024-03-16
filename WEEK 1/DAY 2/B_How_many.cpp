#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll a,b;
    cin>>a>>b;

    ll ans=0;

    for(int x=0;x<=100; x++){
        for(int y=0; y<=100;y++){
            for(int z=0;z<=100; z++){
                if(x+y+z<=a && x*y*z<=b) ans++;
            }
        }
    }

    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}