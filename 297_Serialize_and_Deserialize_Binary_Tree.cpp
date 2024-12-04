/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string tree = "";
        if (!root)
            return tree;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();

            if (tmp) {
                tree += to_string(tmp->val) + ",";
                q.push(tmp->left);
                q.push(tmp->right);
            } else {
                tree += "#,";
            }
        }
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0)
            return nullptr;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (getline(s, str, ',')) {
                if (str == "#") {
                    node->left = nullptr;
                } else {
                    TreeNode* left_node = new TreeNode(stoi(str));
                    node->left = left_node;
                    q.push(left_node);
                }
            }

            if (getline(s, str, ',')) {
                if (str == "#") {
                    node->right = nullptr;
                } else {
                    TreeNode* right_node = new TreeNode(stoi(str));
                    node->right = right_node;
                    q.push(right_node);
                }
            }
        }
        return root;
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
