/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        queue<Node*>q;
        q.push(root);
        root->next=NULL;
        q.push(NULL);
        vector<Node*>temp={};
        while(!q.empty()){
            Node* top = q.front();
            q.pop();
            if(top == NULL){
                temp.push_back(NULL);
                for(int i=0;i<temp.size()-1;i++){
                    temp[i]->next = temp[i+1];
                }
                temp.clear();
                if (!q.empty()) {
                    q.push(NULL);
                }
            }
            else{
                if(top->left){
                    q.push(top->left);
                    temp.push_back(top->left);
                }
                if(top->right){
                    q.push(top->right);
                    temp.push_back(top->right);
                }
            }
        }
        return root;
    }
};