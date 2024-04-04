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

    string a,b;

    cin >> a >> b;

    if(a==b) cout << "=" << endl;
    else{
        ll len1=a.size();
        ll len2=b.size();

        if(a[a.size()-1] == 'S' && b[b.size()-1] == 'S'){
            if(a.size()>b.size()) cout << "<" << endl;
            else cout << ">" << endl;
        }
        else if(a[len1-1]=='L' && b[len2-1]=='L'){
            if(len1>len2) cout << ">" << endl;
            else cout << "<" << endl;
        }
        else if(a[len1-1]=='S' && b[len2-1]=='L'){
            cout << "<" << endl;
        }
        else if(a[len1-1]=='L' && b[len2-1]=='S'){
            cout << ">" << endl;
        }
        else if(a[len1-1]=='M'){
            if(b[len2-1]=='L') cout << "<" << endl;
            else if(b[len2-1]=='S') cout << ">" << endl;
        }
        else if(b[len2-1]=='M'){
            if(a[len1-1]=='L') cout << ">" << endl;
            else if(a[len1-1]=='S') cout << "<" << endl;
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