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
            int numBit = (num >> i) & 1;
            if(node->containsKey(1 - numBit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(1-numBit);
            }
            else {
                node = node->get(numBit);
            }
        }
        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &it : nums) {
            trie.insert(it);
        }

        int maxXor = 0;
        for(auto &it : nums) {
            maxXor = max(maxXor, trie.getMaxXor(it));
        }
        return maxXor;
    }
};
