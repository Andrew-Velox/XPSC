class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &arr , int N){
        // code here 
        long long l=0,r=0;
        long long ans=0;
        
        long long sum=0;
        while(r<N){
            sum+=arr[r];
            if(r-l+1==k){
                
                ans=max(ans,sum);
                sum-=arr[l];
                l++;
                r++;
            }
            else {
                r++;

            }
            
        }
        
        return ans;
    }
};
