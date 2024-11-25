
#include <bits/stdc++.h>
using namespace std;


class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:

    void preOrder(Node *root) {
        if (root == NULL) return;
        
        stack<Node*> s;
        s.push(root);
        
        while (!s.empty()) {
            Node* p = s.top();
            s.pop();
            cout << p->data << " ";
            if (p->right) s.push(p->right); 
            if (p->left) s.push(p->left);
        }
    }

    Node * insert(Node * root, int data) {
		Node* getNode = new Node(data);
        if (root == NULL) {
            return getNode;
        }
        Node* p = root;
        Node* q = NULL;
        while (p != NULL) {
            q = p;
            if (data < p->data) {
                p = p->left;
                if (p == NULL) {
                    q->left = getNode;
                }
            } else {
                p = p->right;
                if (p == NULL) {
                    q->right = getNode;
                }
            }
        }
        return root;
    }
};
    /* SV phai viet ca ham insert
    Node* insert(Node* root, int data);
     */

//End of Solution

int main() {

    Solution myTree;
    Node* root = NULL;

    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.preOrder(root);

    return 0;
}
