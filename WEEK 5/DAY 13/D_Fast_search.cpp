#include <bits/stdc++.h>
using namespace std;

#ifdef velox
#include "debug.h"
#else
#define debug(x...)
#endif

#define ll long long
#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define unq(v) v.erase(unique(v.begin(),v.end()),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl '\n'
#define fx(x) fixed<<setprecision(x)

void error_txt(){
    #ifdef velox
    freopen("error.txt","w",stderr);
    #endif
}



void solve(){
    ll len; cin >> len;
    vector<ll> v(len);


    for(int x=0; x<len; x++) cin >> v[x];

    srt(v);

    ll q; cin >>q;
    while(q--){
        ll a,b; cin >> a >>b;

        auto it = lower_bound(v.begin(),v.end(),a);
        ll in_a= it-v.begin();

        it = upper_bound(v.begin(),v.end(),b);
        
        ll in_b= it-v.begin();
        debug(in_a, in_b);


        cout << abs(in_a-in_b) << " ";

    }
    cout << endl;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}