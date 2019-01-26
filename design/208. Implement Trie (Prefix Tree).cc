#include <memory>
#include <string>
#include <vector>
using namespace std;

class Trie {
    class TreeNode;

public:
    Trie()
        : root(new TreeNode())
    {
    }
    Trie(const Trie&) = delete;
    Trie& operator=(const Trie&) = delete;

    void insert(string word)
    {
        TreeNode* cur = root.get();
        for (auto x : word) {
            if (!cur->children[x - 'a'])
                cur->children[x - 'a'] = new TreeNode();
            cur = cur->children[x - 'a'];
        }
        ++(cur->times);
    }
    bool search(string word)
    {
        const TreeNode* cur = find(word);
        return cur && (cur->times>0);
    }
    bool startsWith(string prefix)
    {
        return find(prefix) != nullptr;
    }

private:
    const TreeNode* find(const string& prefix)
    {
        const TreeNode* cur = root.get();
        for (const char c : prefix) {
            cur = cur->children[c - 'a'];
            if (cur == nullptr)
                break;
        }
        return cur;
    }

private:
    class TreeNode {
    public:
        TreeNode()
            : times(0)
            , children(26, nullptr)
        {
        }
        ~TreeNode()
        {
            for (auto& x : children) {
                if (x)
                    delete x;
            }
        }
        int times;
        char data;
        vector<TreeNode*> children;
    };
    std::unique_ptr<TreeNode> root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */