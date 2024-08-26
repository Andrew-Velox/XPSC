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
    ll m,n; cin >> m >> n;

    vector<tuple<ll,ll,ll>> v(n);

    for(int x=0; x<n; x++){
        ll a,b,c;
        cin >> a >> b >> c;
        v[x]={a,b,c};
    }

    // for(auto &&i: v){
    //     int x,y,z;
    //     tie(x,y,z)=i;
    //     cout << x << " " << y << " " << z << endl;
    // }


    vector<ll> anss(n);
    auto ok = [&] (ll mid){
        vector<ll> noww(n);
        ll has=m;
        for(int x=0; x<n; x++){
            tuple<ll,ll,ll> T = v[x];
            ll total,t,z,y;
            
            t=get<0>(T);
            z=get<1>(T);
            y=get<2>(T);

            total = (t*z)+y;

            ll get = (mid/total);
            ll rem = mid%total;

            ll curr = ((get*z) + min(z,(rem/t)));
            curr = min(has,curr);
            has-=curr;
            noww[x]=curr;

        }

        if(has==0){
            for(int x=0; x<n; x++){
                anss[x] = noww[x];
            }
        }

        return !has;
    };




    ll l=0,r=1e8,ans=0;

    while(l<=r){
        ll mid=l+(r-l)/2;

        if(ok(mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }

    cout << ans << endl;

    for(auto val: anss){
        cout << val << " ";
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