/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        Node* mp[102]={nullptr};
        auto dfs=[&](auto &&self,Node *node1)->Node*{
            if(mp[node1->val]!=nullptr){
                return mp[node1->val];
            }
            Node* cln=new Node(node1->val);
            mp[node1->val]=cln;
            cln->neighbors.reserve(node1->neighbors.size());
            for(auto it:node1->neighbors){
                cln->neighbors.push_back(self(self,it));
            }
            return cln;
        };
        return dfs(dfs,node);
    }
};