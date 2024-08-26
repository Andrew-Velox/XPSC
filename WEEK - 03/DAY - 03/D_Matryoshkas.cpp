#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define pi pair<int,int>
#define pll pair<ll,ll>

#define srt(v) sort(v.begin(),v.end())
#define grtsrt(v) sort(v.begin(),v.end(),greater<ll>())
#define rev(v) reverse(v.begin(),v.end());
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define endl "\n"
#define fx(x) fixed<<setprecision(x)

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<":- "<<x<<" "<< endl;
#define debug2(x,y) cerr<<#x<<":- "<<x<<" | "<<#y<<":- "<<y<<endl;
#define debug3(x,y,z) cerr<<#x<<":- "<<x<<" | "<<#y<<":- "<<y<<" | "<<#z<<":- "<<z<<endl;
#else
#define debug(x)
#define debug(x,y)
#define debug(x,y,z)
#endif

void error_txt(){
    #ifndef ONLINE_JUDGE
    freopen("error.txt","w",stderr);
    #endif
}
void speed(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}



void solve(){

    ll len; cin >> len;

    vll v(len);

    set<ll> st;
    for(int x=0; x<len; x++){
        cin >> v[x];
        st.insert(v[x]);
    }

    srt(v);

    map<ll,ll> mp;

    for(int x=0; x<len; x++){
        if(mp[v[x]-1]>0){
            mp[v[x]-1]--;
            mp[v[x]]++;
            // debug3("i",mp[v[x]-1],v[x])

        }
        else{

            mp[v[x]]++;
            // debug3("e",mp[v[x]],v[x])
        }
    }


    ll ans=0;
    for(auto val: st) ans+=mp[val];

    cout << ans << endl;

}

int main(){
    // error_txt();
    speed();
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}