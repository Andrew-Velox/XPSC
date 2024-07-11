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

class cmp{
    public:
        bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
            return get<2>(a) > get<2>(b);
        }
};


void solve(){
    ll len; cin >> len;
    vector<ll> a(len),b(len);

    for(int x=0; x<len; x++) cin >> a[x];
    for(int x=0; x<len; x++) cin >> b[x];

    vector<tuple<ll,ll,ll>> v;
    for(int x=0; x<len; x++){
        v.push_back({a[x],b[x],b[x]-a[x]});
    }

    sort(v.begin(),v.end(),cmp());

    // for(int x=0; x<len; x++){
    //     cout << get<0>(v[x]) << ", " << get<1>(v[x]) << ", " << get<2>(v[x]) << endl;
    // }
    // debug(v);

    

    ll l=0,r=len-1;
    ll lagbe=get<0>(v[l]),ache=get<1>(v[l]),ans=0;

    
    while(l<r){
        ll need = get<0>(v[r]);
        ll have = get<1>(v[r]);

        lagbe+=need;
        ache+=have;
        if(ache>=lagbe){
            ans++;
            l++;
            lagbe=get<0>(v[l]);
            ache=get<1>(v[l]);
        }
        else{
            lagbe-=need;
            ache-=have;
        }
        r--;
    }

    cout << ans << endl;

    
}

int main(){
    // error_txt();
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}