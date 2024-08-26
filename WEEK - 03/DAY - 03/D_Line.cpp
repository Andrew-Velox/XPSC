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
    string s; cin >> s;

    ll cnt=0;

    if(len==1){
        cout << 0 << endl;
        return;
    }

    vll diff,ans;

    if(len%2==0){
        for(int x=len/2; x<len; x++) cnt+=(x*2);
    }
    else{
        cnt+=(len/2);
        for(int x=(len/2)+1; x<len; x++) cnt+=(x*2);
    }
    
    for(int x=0; x<len; x++){
        ll dif=0;
        if(s[x]=='L' && x<(len/2)){
            dif=abs((len-(x+1))-(x));
            diff.push_back(dif);
        }
        else if(s[x]=='R' && x>(len/2)){
            dif=abs((len-(x+1))-(x));
            diff.push_back(dif);
        }
        else if(x==len/2 && s[x]=='L'){
            diff.push_back(0);
        }
        else if(x==len/2 && s[x]=='R'){
            dif=abs((len-(x+1))-(x));
            diff.push_back(dif);
        }


        // debug3(len-(x+1),x,dif)
    
    }
    // debug(cnt)

    grtsrt(diff);

    // for(auto val: diff) cout << val << " ";
    // cout << endl;

    ll tmp=cnt;
    for(int x=diff.size()-1; x>0; x--){
        tmp-=diff[x];
        ans.push_back(tmp);
    }

    rev(ans);
    ll i=0;
    for(auto val: ans){
        cout << val << " ";
        i++;
    }

    if(i<=len){
        for(int x=i; x<len; x++) cout << cnt << " ";
    }
    cout << endl;



}

int main(){
    // error_txt();
    speed();
    ll t; cin >> t;
    while(t--) solve();
    return 0;
}