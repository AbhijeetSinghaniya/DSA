class Solution {
public:
    vector<int> res;
    int ans = 0;
    void solve(int numArrows,int score,vector<int>& alice,vector<int>& bob,int sum){
        
        if(score == -1 || numArrows <= 0){
            if(sum > ans){
                if(numArrows > 0){
                    bob[0] += numArrows;
                }
                ans = sum;
                res = bob;
            }
            return;
        }        
        int req = alice[score] + 1;
        if(req <= numArrows){
            bob[score] = req;
            solve(numArrows - req,score-1,alice,bob,sum+score);
            bob[score] = 0;
        }
        solve(numArrows,score-1,alice,bob,sum);
        return;
    }
    
    vector<int> maximumBobPoints(int numArrows, vector<int>& alice) {
        vector<int> bob(12,0);
        solve(numArrows,11,alice,bob,0);
        return res;
    }
};
