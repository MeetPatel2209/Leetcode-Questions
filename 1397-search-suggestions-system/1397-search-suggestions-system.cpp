struct Node {
    Node* links[26];
    bool flag = false;
    public:
    bool containsKey(char ch) {
        return links[ch-'a'] != NULL;
    }
    void putKey(char ch,Node* node) {
        links[ch-'a'] = node;
    }
    Node* getKey(char ch) {
        return links[ch-'a'];
    }
    bool getEnd() {
        return flag;
    }
    void setEnd() {
        flag = true;
    }

};

class Trie {
    Node* root;
    public:
    Trie() {
        root = new Node();
    }
    void insertWord(string str) {
        Node* node = root;
        for(int i=0;i<str.size();i++) {
            if(!node->containsKey(str[i])) {
                node->putKey(str[i],new Node());
            }
            node = node->getKey(str[i]);
        }
        node->setEnd();
    }

    void getStrings(vector<string> &ans,string temp,Node* node) {
        if(ans.size() == 3) return;
        if(node->getEnd() == true) {
            ans.push_back(temp);
        }
        for(char ch='a';ch<='z';ch++) {
            if(node->containsKey(ch)) {
                temp = temp + ch;
                getStrings(ans,temp,node->getKey(ch));
                temp.pop_back();
            } 
        }
    }

    vector<string> checkPrefix(string pre) {
        Node* node = root;
        string temp = "";
        vector<string> ans;
        for(int i=0;i<pre.size();i++) {
            if(node->containsKey(pre[i])) {
                temp += pre[i];
                node = node->getKey(pre[i]);
            }
            else return ans;
        }
        //if(node==root) return ans;
        getStrings(ans,temp,node);
        return ans;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        for(auto prod : products) {
            trie.insertWord(prod);
        }
        vector<vector<string>> ans;
        string pre = "";
        for(int i=0;i<searchWord.size();i++) {
            pre += searchWord[i];
            ans.push_back(trie.checkPrefix(pre));
        }
        return ans;
    }
};