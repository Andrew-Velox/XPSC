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

    vector<pair<ll,ll>> v1(len),v2(len),v3(len);

    for(int x=0; x<len; x++){
        cin >> v1[x].first;
        v1[x].second=x;
    }
    for(int x=0; x<len; x++){
        cin >> v2[x].first;
        v2[x].second=x;
    }
    for(int x=0; x<len; x++){
        cin >> v3[x].first;
        v3[x].second=x;
    }

    srt(v1);
    rev(v1)

    // for(int x=0; x<len; x++) cout << v1[x].first << " " << v1[x].second << endl;
    // cout << endl;
    srt(v2);
    rev(v2);
    
    srt(v3);
    rev(v3);

    ll ans = 0;
    for(int x=0; x<3;x++){
        for(int y=0; y<3; y++){
            for(int z=0; z<3;z++){

                if(v1[x].second!= v2[y].second && v1[x].second!=v3[z].second && v2[y].second!=v3[z].second){

                    // debug2(ans, v1[x].first+v2[y].first+v3[z].first)
                    ans = max(ans, v1[x].first+v2[y].first+v3[z].first);
                }
            }
        }
    }
 
    cout << ans << endl;


    // while(!pq1.empty()){
    //     pair<ll,ll> val=pq1.top();
    //     cout <<  val.first << " ";
    //     pq1.pop();
    // }

}

int main(){
    // error_txt();
    speed();
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}