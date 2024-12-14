/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        Node* node=head;
        while(node){
            Node* newNode = new Node(node->val);
            mp[node] = newNode;
            node = node->next;
        }
        node = head;
        while(node){
            mp[node]->next = mp[node->next];
            mp[node]->random = mp[node->random];
            node = node->next;
        }
    return mp[head];
    }
};
static const auto kds = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
