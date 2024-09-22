class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        sort(deck.begin(), deck.end());
        vector<int> ans(n,0);
        deque<int> dq;

        for(int i=0;i<n;i++) dq.push_back(i);

        int skip = 0, k = 0;
        while(!dq.empty()){
            if(skip == 0){
                int p = dq.front();
                dq.pop_front();
                ans[p] = deck[k++];
                skip = 1;
            }
            else {
                int p = dq.front();
                dq.pop_front();
                dq.push_back(p);
                skip = 0;
            }
        }
        return ans;
    }
};
