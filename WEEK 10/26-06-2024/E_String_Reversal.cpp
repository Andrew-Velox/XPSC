#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) ((x/gcd(x,y))*y)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl '\n'
#define fx(x) fixed<<setprecision(x)
template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void error_txt(){
    #ifdef velox
    freopen("error.txt","w",stderr);
    #endif
}



void solve(){
    ll len; cin >> len;
    string s; cin >> s;
    string r=s;

    rev(r);


    map<char,vector<ll>> str_s,str_r;

    for(int x=0; x<len; x++){
        str_s[s[x]].push_back(x);
        str_r[r[x]].push_back(x);
    }

    debug(str_s);
    debug(str_r);


    vector<ll> permutation(len);

    for(char x='a'; x<='z'; x++){

        for(int y=0; y<str_s[x].size(); y++){
            permutation[str_r[x][y]] = str_s[x][y];
        }
    }

    debug(permutation);


    ll ans=0;
    pbds<ll> pb;
    for(int x=len-1; x>=0; x--){
        ans+=pb.order_of_key(permutation[x]);
        pb.insert(permutation[x]);
    }

    cout << ans << endl;

    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll t=1; //cin >> t;
    while(t--) solve();
    return 0;
}