//Count Occurences of Anagrams
// https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1?_gl=1*2hl6h9*_ga*MTYxMTcwOTY2OC4xNjYwMzk1MzY0*_ga_DWCCJLKX3X*MTY5Njc3NDQzNi4xLjEuMTY5Njc3NDUwNy4wLjAuMA..



#define ll long long
class Solution{
public:
	int search(string ck, string mn) {
	    // code here
        map<char,int> mp1;
        for(int x=0; x<ck.size();x++) mp1[ck[x]]++;
    
        int cnt=0,ans=0;
        
        ll s1=ck.size();
        ll s2=mn.size();
        map<char,int> mp2;
        
        int i=0,j=0;
        
        while(j<s2){
            mp2[mn[j]]++;

            //-----------print---------------//
            // cout<< mn[j] << " " << mp2[mn[j]] << " " << mp1[ mn[j]] << " " << cnt<<endl;
    
            if(j-i+1==s1){
    
                for(char x='a'; x<='z'; x++){
                    if(mp2[x]!=mp1[x]) break;
                    if(x=='z') ans++;
                }
                mp2[mn[i]]--;
                i++;
                j++;
                // cout << "df " << cnt << " fdg" << endl<<endl;
    
            }
    
            else j++;
    
        }
    
        // cout <<ans << endl;
        
        return ans;

	}

};
