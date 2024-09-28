struct Node {
    Node* links[2];

    bool containsKey(int bit) {
        return links[bit] != NULL;
    }
    Node* get(int bit) {
        return links[bit];
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for(int i=31;i>=0;i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMaxXor(int num) {
        Node* node = root;
        int maxNum = 0;

        for(int i=31;i>=0;i--) {
            int bit = (num >> i) & 1;
            if(node->containsKey(1 - bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }
            else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

bool comp(pair<vector<int>,int>& a, pair<vector<int>,int>& b) {
    return a.first[1] <= b.first[1];
}

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<int, pair<int, int> > > offlineQueries;
        int n = queries.size();

        for(int i=0;i<n;i++) {
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }   

        sort(offlineQueries.begin(), offlineQueries.end());
        sort(nums.begin(), nums.end());

        vector<int> maxXor(n,0);
        Trie trie;
        int k = 0;
        for(int i = 0;i<n;i++) {
            int val = offlineQueries[i].second.first;
            int limit = offlineQueries[i].first;
            int idx = offlineQueries[i].second.second;

            // cout<<val<<"  "<<limit<<"  "<<idx<<endl;

            while(k < nums.size() && nums[k] <= limit) {
                trie.insert(nums[k]);
                k++;
            }
            if(k == 0) maxXor[idx] = -1;
            else maxXor[idx] = trie.getMaxXor(val);        
        }
        return maxXor;
    }
};
