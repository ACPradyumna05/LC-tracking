/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    void serializeDFS(TreeNode* node, string& s){
        if(!node){
            s+="#,";
            return;
        }

        s+=to_string(node->val)+",";

        serializeDFS(node->left, s);
        serializeDFS(node->right,s);
    }

    TreeNode* deserializeDFS(stringstream& ss){
        string token;

        if(!getline(ss, token, ',')){
            return nullptr;
        }
        if(token=="#"){
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(token)); //string to int
        node->left = deserializeDFS(ss);
        node->right= deserializeDFS(ss);
        return node;

    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out = "";
        serializeDFS(root, out);
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeDFS(ss);
        
    }
};
