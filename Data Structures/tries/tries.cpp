#include<bits/stdc++.h>

using namespace std;

struct TrieNode {
    int value;
    vector<TrieNode *> links;

    TrieNode() {
        this->value = -1;
        this->links = vector<TrieNode *>(26, nullptr);
    }

    TrieNode(int value) {
        this->value = value;
        this->links = vector<TrieNode *>(26, nullptr);
    }
};

class Trie {
    private:
    TrieNode *root;

    list<string> collect_keys(TrieNode *root, string str) {
        list<string> keys;
        
        if(root->value != -1) {
            keys.push_back(str);
        }
        
        list<string> sub_keys;
        for(int i = 0; i < 26; i++) {
            if(root->links[i] != nullptr) {
                sub_keys = collect_keys(root->links[i], str + string(1, i + 'a'));

                //Join the keys and keys of subtrie
                for(auto it = sub_keys.begin(); it != sub_keys.end(); it++) {
                    keys.push_back(*it);
                }
            }
        }

        return keys;
    }

    TrieNode* prefix(TrieNode* root, int pos, string str) {
        if(pos == str.length()) return root;

        if(root->links[str[pos] - 'a'] == nullptr) return nullptr;
        else return prefix(root->links[str[pos] - 'a'], pos + 1, str);
    }

    void delete_key(TrieNode* &root, int pos, string str) {
        if(pos != str.length()) {
            delete_key(root->links[str[pos] - 'a'], pos + 1, str);
        }
        
        bool flag = false;

        for(int i = 0; i < 26; i++) {
            if(root->links[i] != nullptr) {
                flag = true;
                break;
            }
        }

        if(flag) {
            root->value = -1;
        }
        else {
            free(root);
            root = nullptr;
        }

        return;
    }

    bool search(TrieNode *root, int pos, string key) {
        if(pos == key.length()) {
            if(root->value != -1) return true;
            else return false;
        }
        else {
            if(root->links[key[pos] - 'a'] == nullptr) return false;
            else return search(root->links[key[pos] - 'a'], pos + 1, key);
        }
    }

    //Procedures to print the keys
    public:
    Trie() {
        this->root = new TrieNode();
    }
    
    void insert_key(string key, int value) {
        TrieNode* temp = this->root;
        int pos = 0;

        while(pos != key.length()) { 
            int link_idx = key[pos] - 'a';
            // cout << key[pos] << " " << link_idx << "\n";

            if(temp->links[link_idx] == nullptr) {
                // cout << "Null next link\n";
                TrieNode *newNode;

                if(pos == key.length() - 1) {
                    newNode = new TrieNode(value);
                }
                else {
                    newNode = new TrieNode();
                }
                    
                temp->links[link_idx] = newNode;
            }
            else if(pos == key.length() - 1) {
                // cout << "Not Null\n";
                temp->links[link_idx]->value = value;
            }

            temp = temp->links[link_idx];
            pos++;
        }

        return;
    }

    bool search(string key) {
        return search(this->root, 0, key);
    }

    void delete_key(string str) {
        delete_key(this->root->links[str[0] - 'a'], 1, str);
        return;
    }

    TrieNode* prefix(string str) {
        return prefix(this->root, 0, str);
    }
    
    list<string> collect_keys() {
        return collect_keys(prefix(""), "");
    }
    
    list<string> collect_keys(string ptr) {
        list<string> keys = collect_keys(prefix(ptr), "");
        for(auto it = keys.begin(); it != keys.end(); it++) {
            *it = ptr + *it;
        }
        return keys;
    }
};

int main() {
    Trie* t = new Trie();
    t->insert_key("shell", 1);
    t->insert_key("shellsort", 2);
    t->insert_key("trie", 3);

    list<string> keys = t->collect_keys();
    for(auto it = keys.begin(); it != keys.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";

    keys = t->collect_keys("sh");
    for(auto it = keys.begin(); it != keys.end(); it++) {
        cout << *it << " ";
    }
    cout << "\n";

    return 0;
}