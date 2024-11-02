//Approach : Sort by end time, track of which time unit under duration is already present, assign the remaining ones as late as possible
class Solution {
    // static bool compare(vector<int>& a,vector<int>& b) {
        // return (a[1] != b[1]) ? a[1] < b[1] : a[0] < b[0];
    // }
public:

    int findMinimumTime(vector<vector<int>>& tasks) {
        // sort(tasks.begin(),tasks.end(),compare);
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] != b[1]) ? a[1] < b[1] : a[0] < b[0];
        });

        int count = 0;
        unordered_map<int,int> mp;
        for(auto task : tasks) {
            int timeUsed = 0;
            for(int t=task[0];t<=task[1];t++) {
                if(mp.count(t)) timeUsed++;
            }

            for(int t=task[1];timeUsed<task[2];t--) {
                if(!mp.count(t)) {
                    timeUsed++;
                    mp[t] = 1;
                    count++;
                }
            }
        }
        return count;
    }
};
