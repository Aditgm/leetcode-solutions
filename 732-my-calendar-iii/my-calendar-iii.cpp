class Node {
public:
    int val, lazy;
    Node *left, *right;
    Node() : val(0), lazy(0), left(nullptr), right(nullptr) {}
};

class MyCalendarThree {
    Node* root;
    
    void update(Node* node, int s, int e, int l, int r) {
        if (l <= s && e <= r) {
            node->val += 1;
            node->lazy += 1;
            return;
        }
        
        int mid = s + (e - s) / 2;
        if (!node->left) node->left = new Node();
        if (!node->right) node->right = new Node();
        
        if (node->lazy != 0) {
            node->left->val += node->lazy;
            node->left->lazy += node->lazy;
            node->right->val += node->lazy;
            node->right->lazy += node->lazy;
            node->lazy = 0;
        }
        
        if (l < mid) update(node->left, s, mid, l, r);
        if (r > mid) update(node->right, mid, e, l, r);
        
        node->val = max(node->left->val, node->right->val);
    }

public:
    MyCalendarThree() {
        root = new Node();
    }
    
    int book(int startTime, int endTime) {
        update(root, 0, 1000000001, startTime, endTime);
        return root->val;
    }
};