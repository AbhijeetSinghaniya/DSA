//M-I : Bringing the goal post closer approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int minJump = 0;
        int n = nums.size();
        for(int i=n-2;i>=0;i--) {
            minJump++;
            if(nums[i] >= minJump) {
                minJump = 0;
            }
        }
        if(minJump == 0) return true;
        return false; 
    }
};

//M-II : Keeping track of maximum reach at all indices
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int reach = 0;
        int n = nums.size();
        
        if(nums[0] == 0){
            if(n == 1) return true;
            return false;
        }
        
        for(int i=0;i<n;i++){
            
            if(nums[i] == 0){
                if(reach > i) continue;
                else return false;
            }
            reach = max(nums[i] + i , reach);
            //cout<<reach<<"  ";
            if(reach >= n-1) return true;
        }
        return false;
    }
};
