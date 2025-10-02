class Solution {
public:
    struct Trie {
        unordered_map<string, Trie*> children;
        bool toDelete = false;
    };

    unordered_map<string, vector<Trie*>> seen;

    string serialize(Trie* node) {
        if (node->children.empty()) return "";
        vector<pair<string, string>> serials;
        for (auto& [name, child] : node->children) {
            serials.push_back({name, serialize(child)});
        }
        sort(serials.begin(), serials.end());
        string key;
        for (auto& [name, s] : serials) {
            key += "(" + name + s + ")";
        }
        seen[key].push_back(node);
        return key;
    }

    void markToDelete() {
        for (auto& [key, nodes] : seen) {
            if (nodes.size() > 1 && !key.empty()) {
                for (auto* node : nodes) {
                    node->toDelete = true;
                }
            }
        }
    }

    void insert(Trie* root, vector<string>& path) {
        Trie* curr = root;
        for (const string& folder : path) {
            if (!curr->children.count(folder))
                curr->children[folder] = new Trie();
            curr = curr->children[folder];
        }
    }

    void collect(Trie* node, vector<string>& curr, vector<vector<string>>& res) {
        for (auto& [name, child] : node->children) {
            if (!child->toDelete) {
                curr.push_back(name);
                res.push_back(curr);
                collect(child, curr, res);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie* root = new Trie();
        for (auto& path : paths) {
            insert(root, path);
        }
        serialize(root);
        markToDelete();
        vector<vector<string>> res;
        vector<string> curr;
        collect(root, curr, res);
        return res;
    }
};
