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
    cin.tie(NULL);
    cout.tie(0);
    ios::sync_with_stdio(false);
}



void solve(){

    ll len;
    cin >> len;

    vll v(len);
    map<ll,ll> mp1,mp2;
    map<ll,ll> mx_idx;

    ll mn=INT_MAX; 
    ll mx=INT_MIN; 
    for(int x=0; x<len; x++){
        cin >> v[x];

        if(mp1[v[x]]==0){
            mp2[v[x]]=x;
            mp1[v[x]]++;
        }
        mx_idx[v[x]]=x;

        mx=max(mx,v[x]);
        mn=min(mn,v[x]);
    }

    // debug2(mp2[mx], mp2[mn]);

    ll in_ans=abs(v[0]-v[len-1]);


    if(mp2[mn]==0 || len<3 || mx_idx[mx]==len-1) cout << mx-mn << endl;

    else{
        
        ll mx_in=0;
        ll mx_in2=0;

        for(int x=0; x<len; x++){
            if(v[0]<v[x]){
                mx_in=max(mx_in,(v[x]-v[0]));
            }
        }
        for(int x=len-1; x>=0; x--){
            if(v[len-1]>v[x]){
                mx_in2=max(mx_in2,(v[len-1]-v[x]));
            }
        }

        ll ans=0;
        for(int x=0; x<len-1; x++){
            if(v[x]>v[x+1]){
                ans=max(ans,(v[x]-v[x+1]));
            }
        }

        // debug2(ans,mx_in);
        cout << max({ans,mx_in,mx_in2}) << endl;
    }

    
}

int main(){
    // error_txt();
    speed();
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}