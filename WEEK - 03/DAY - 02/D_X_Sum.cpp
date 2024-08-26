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

ll n,m;
ll ar[205][205];



ll get_sum(ll ix,ll iy){
    ll sum=0;

    // diagonal
    ll dif=ix-iy;
    ll dif2=ix+iy;

    int y=iy;
    for(int x=ix; x<n && y<m; x++){
        // debug3(x,y,ar[x][y])
        sum+=ar[x][y];
        y++;
    }
    // debug(sum)
    y=iy-1;
    for(int x=ix-1; x>=0 && y>=0; x--){
        // debug3(x,y,ar[x][y]);
        sum+=ar[x][y];
        y--;
    }

    // debug(sum)
    y=iy+1;
    for(int x=ix-1; x>=0 && y<m; x--){
        // debug3(x,y,ar[x][y]);
        sum+=ar[x][y];
        y++;
    }
    // debug(sum)
    y=iy-1;
    for(int x=ix+1; x<n && y>=0; x++){
        // debug3(x,y,ar[x][y]);
        sum+=ar[x][y];
        y--;
    }
    
    // debug(sum)



    // cout << endl << endl;



    return sum;
}

void solve(){
    cin>> n >> m;

    for(int x=0; x<202; x++){
        for(int y=0; y<202; y++){
            ar[x][y]=0;
        }
    }

    for(int x=0; x<n; x++){
        for(int y=0; y<m; y++){
            cin >> ar[x][y];
        }
    }

    ll mx=INT_MIN;

    for(int x=0; x<n; x++){
        for(int y=0; y<m; y++){
            mx=max(mx,get_sum(x,y));
        }
    }

    cout << mx << endl;
}

int main(){
    // error_txt();
    speed();
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}