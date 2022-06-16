class Solution {
public:
    int solve(vector<int> nums, int start, int n){
        int prev2 = 0, prev = nums[start];
        
        for(int i=start+1 ; i<n; i++){
            int pick = prev2 + nums[i];
            int notpick = prev;
            
            int curr = max(pick,notpick);
            prev2 = prev;
            prev = curr;
        }
        
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)
            return nums[0] ;
        
        //agar adjacent nahi le sakte to hum ek baar first element ko lenge aur last ko hata denge aur ek baar last ko lenge aur first ko hata denge 
        int ans1 = solve(nums,0,n-1);
        int ans2 = solve(nums,1,n);
        
        return max(ans1,ans2);
    }
};
