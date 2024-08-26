#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
    ios_base::sync_with_stdio(false);
}

bool dp[3000][3000];

bool knapsack(vector<ll> &v, ll len, ll sum){
    if(len==0){
        return sum==0;
    }

    if(dp[len][sum]) return dp[len][sum];

    if(v[len-1]<=sum){
        bool opt1 = knapsack(v,len-1,sum-v[len-1]);
        bool opt2 = knapsack(v,len-1,sum);

        return  dp[len][sum]= opt1 || opt2;
    }

    else return dp[len][sum]=knapsack(v,len-1,sum);
}


void solve(){
    
    ll len; cin >> len;

    vector<ll> v(len);

    ll sum=0;

    for(int x=0; x<len; x++){
        cin >> v[x];
        sum+=v[x];
    }

    for(int x=0; x<=len; x++){
        for(int y=0; y<=sum; y++){
            dp[x][y]=false;
        }
    }

    // debug(sum)

    if(sum==360 || sum%360==0) cout << "YES" << endl;
    else if(sum%2==1) cout << "NO" << endl;
    else{

        if(knapsack(v,len,sum/2)) cout << "YES" << endl;
        else if(knapsack(v,len,(sum-360)/2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    

}

int main(){
    // error_txt();
    speed();
    ll t=1;// cin >> t;
    while(t--) solve();
    return 0;
}