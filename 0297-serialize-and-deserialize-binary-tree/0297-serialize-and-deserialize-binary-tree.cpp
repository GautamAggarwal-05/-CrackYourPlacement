class Codec {
public:
    
       string serialize(TreeNode* root) {
        string result;
        preorder(root, result);
        return result;
    }

    void preorder(TreeNode* root, string& result) {
        if (root == NULL) {
            result += "#,";
            return;
        }
        result += to_string(root->val) + ",";
        preorder(root->left, result);
        preorder(root->right, result);
    }

    
    TreeNode* deserialize(string data) {
        queue<string> q;
        string s;

        for(int i=0;i<data.size();i++){
            if(data[i]==','){
                q.push(s);
                s="";
                continue;
            }

            s+=data[i];
        }
        if(s.size()!=0)
            q.push(s);
        
        return solve(q);
    }
TreeNode* solve(queue<string>& q) {
    if (q.empty()) return NULL;

    string s = q.front();
    q.pop();

    if (s == "#") return NULL;  

    TreeNode* root = new TreeNode(stoi(s));
    root->left = solve(q);
    root->right = solve(q);
    return root;
}
};
