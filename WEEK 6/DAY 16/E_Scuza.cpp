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
    ll len1, len2; cin >> len1 >> len2;
    vector<ll> v1(len1);
    for(int x=0; x<len1; x++) cin >> v1[x];

    vector<ll> pref_sum(len1),max_sum(len1);
    
    pref_sum[0]=v1[0];
    max_sum[0]=v1[0];
    for(int x=1; x<len1; x++){
        pref_sum[x]=pref_sum[x-1]+v1[x];
        max_sum[x] = v1[x];
        if(max_sum[x-1] > v1[x]){
            max_sum[x]=max_sum[x-1];
        }
    }

    debug(pref_sum);
    debug(max_sum);

    while(len2--){
        ll val; cin >> val;

        auto it = upper_bound(max_sum.begin(),max_sum.end(),val);
        ll index = it-max_sum.begin()-1;
        if(index==-1){
            cout << 0 << " ";
            continue;
        }
        cout << pref_sum[index] << " ";
    }

    cout << endl;
    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}