struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};


class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string &word) {
        Node* node = root;
        for(int i=0;i<word.length();i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }   

    bool checkIfPrefixExists(string &word) {
        bool fl = true;
        Node* node = root;

        for(int i=0;i<word.length();i++) {
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->get(word[i]);
            if(!node->isEnd()) return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    //Store all strings first
    Trie trie;
    for(auto &it : a) {
        trie.insert(it);
    }

    string ans = "";
    int ansLen = 0;

    for(auto &it : a) {
        if((it.length() > ans.length() || (it.length() == ans.length() && it < ans)) && 
            trie.checkIfPrefixExists(it)) {
            // if(it.length() > ans.length()) {
                ans = it;
            // }
            // else if(it.length() == ans.length() && it < ans) {
            //     ans = it;
            // }
        }
    }

    return (ans == "") ? "None" : ans;
}
