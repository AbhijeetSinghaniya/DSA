class Node {
    Node* links[26];
public:
    bool containsKey(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s) {
    int cnt = 0;
    Node* root = new Node();

    for(int i=0; i<s.length();i++){
        Node* node = root;
        for(int j=i;j<s.length();j++) {
            if(!node->containsKey(s[j])) {
                node->put(s[j], new Node());
                cnt++;
            }
            node = node->get(s[j]);
        }
    }
    return cnt+1;
}
