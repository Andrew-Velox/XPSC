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

    ll len, q;
    cin >> len >> q;

    map<ll,ll> ck,mp1,mp2;
    map<ll,bool> mpb;

    for(int x=0; x<len; x++){
        ll val; cin >> val;
        if(ck[val]==0){
            mp1[val]=x;
            ck[val]++;
        }
        mp2[val]=x;
        mpb[val]=true;
    }


    while(q--){

        ll a,b;
        cin >> a >> b;

        if(mpb[a]==false || mpb[b]==false) NO;
        else{

            // debug2(mp1[a], mp2[b]);
            if(mp1[a]<mp2[b]) YES;
            else NO;
        }

    }

}

int main(){
    // error_txt();
    speed();
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}