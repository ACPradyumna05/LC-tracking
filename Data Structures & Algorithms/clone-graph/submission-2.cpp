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
    unordered_map<Node*, Node*> Clones;

    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;

        if(Clones.find(node) != Clones.end()){
            return Clones[node];
        }
        Node* copy= new Node(node->val);
        Clones[node]=copy;

        for(Node* neighbor: node->neighbors){
            copy->neighbors.push_back(cloneGraph(neighbor));
        }
        return copy;
    }
};
