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
    vll v[len];

    for(int x=0; x<len; x++){
        for(int y=0; y<len-1; y++){
            int val; cin >> val;
            v[x].push_back(val);
        }
    }

    map<ll,ll> mp;

    ll val = 0,val2= 0;

    vector<ll> ans;
    ll last=0,ls=0;;
    for(int x=0; x<len-1; x++){
        for(int y=0; y<len; y++){
            // cout << v[y][x] << " ";
            mp[v[y][x]]++;
            if(mp[v[y][x]]==1 && val==0) val= v[y][x];
            else if(mp[v[y][x]]==1) val2= v[y][x];
        }

        if(mp[val]>mp[val2]){
            ans.push_back(val);
            val=0;
            last=val2;
        }
        
        else if(mp[val2]>mp[val]){
            ans.push_back(val2);
            val2=0;
            last=val;
        }
        else if(mp[val2]==mp[val]){
            ans.push_back(last);
            if(last!=val) ans.push_back(val);
            else ans.push_back(val2);
        }
    }



    for(auto gg: ans) cout << gg << " ";

    cout << endl; 

}

int main(){
    // error_txt();
    speed();
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}