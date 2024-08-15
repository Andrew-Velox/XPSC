#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;

void solve(){
    ll len;
    char l;
    cin >> len >> l;
    string s; cin >> s;

    if(l=='g'){
        cout << 0 << endl;
        return;
    }

    ll f_to_g=0;
    int i=0,j=s.size()-1;
    

    // ll front=0,back=0;
    ll cnt,cnt_b=0;


    if(s[j]=='g'){
        ll cnt=0;
        bool f=false;
        ll ans=0;
        for(int x=0; x<len; x++){
            if(s[x]==l) f=true;
            if(s[x]=='g'){
                ans=max(ans,cnt); 
                cnt=0;
                f=false;
            }
            if(f) cnt++;

        }

        cout << ans << endl;
    }
    else{
        while(s[i]!='g'){ 
            f_to_g++;
            i++;
        }
 
        ll int mx=INT_MIN,cnt=0,lst_cnt=0;
        int f=0;
 
        for(int x=0; x<len; x++){
            if(s[x]==l){
                while(s[x]!='g'){
                    if(x==len-1){
                        cnt++;
                        f=1;
                        break;
                    }
                    cnt++;
                    x++;
                }
                // cout << s[x] << " " << cnt << endl;
                if(f && cnt+f_to_g>mx) mx=cnt+f_to_g;
                else mx=max(mx,cnt);
                cnt=0;
            }
        
        }
  
        cout << mx << endl;
 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll t; cin >> t;
    while(t--) solve();
    return 0;
}