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
    vector<ll> v(len+1),vv;
    map<ll,ll> mp;

    for(int x=1; x<=len; x++){
        cin >> v[x];
        mp[v[x]]++;


        if(v[x]<=len && mp[v[x]]>1) vv.push_back(v[x]);
        else if(v[x]>len) vv.push_back(v[x]);
    }

    srt(vv);


    // for(auto val: mp) cout << val.first << " ";
    // cout << endl;
    

    ll in=0;
    for(int x=1; x<=len; x++){
        if(mp[x]==0){
           ll get = vv[in];
           if(get%(get-x)==x){
                in++;
            }

            else{
                cout << -1 << endl;
                return;
            }

        }

    }
    cout << vv.size() << endl;


    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}