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
        if(node == NULL)
            return NULL;
        stack<Node*> st;
        st.push(node);

        Node *cloneNode = new Node(node->val);
        vector<Node*> vec(101, NULL);
        vec[node->val] = cloneNode;

        while(!st.empty())
        {
            Node *temNode = st.top();
            st.pop();
            
            if(vec[temNode->val]->neighbors.size() != temNode->neighbors.size())
            {
                for(int i = 0; i < temNode->neighbors.size(); i++)
                {
                    st.push(temNode->neighbors[i]);
                    if(vec[temNode->neighbors[i]->val] == NULL)
                        vec[temNode->neighbors[i]->val] = new Node(temNode->neighbors[i]->val);
                    vec[temNode->val]->neighbors.emplace_back(vec[temNode->neighbors[i]->val]);
                }
            }

        }

        return cloneNode;
    }
};