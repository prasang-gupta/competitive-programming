/*
 * Complete the swapNodes function below.
 */
struct Node {
    int data;
    Node *left;
    Node *right;
};

Node* NewNode (int data) {
    Node *newnode = new Node;
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void inorder (Node *root, vector <int> &a) {
    if (root == NULL){
        return;
    }

    inorder(root->left, a);
    a.push_back(root->data);
    inorder(root->right, a);
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    /*
     * Write your code here.
     */
    vector <vector <int>> ans;
    Node *root = NewNode(1);
    queue <Node*> q;
    q.push(root);

    for (int i = 0; i < indexes.size(); ++i){
        if (q.front() == NULL){
            q.pop();
            i--;
            continue;
        }

        q.front()->left = (indexes[i][0] == -1) ? NULL : NewNode(indexes[i][0]);
        q.front()->right = (indexes[i][1] == -1) ? NULL : NewNode(indexes[i][1]);

        q.push(q.front()->left);
        q.push(q.front()->right);
        q.pop();
    }

    for (int i = 0; i < queries.size(); ++i){
        int curdepth = 1;
        vector <Node*> v;
        v.push_back(root);

        while(v.size()){
            vector <Node*> curv;
            for (int j = 0; j < v.size(); ++j){
                if (v[j] == NULL){
                    continue;
                }
                if (curdepth % queries[i] == 0){
                    Node *temp = v[j]->left;
                    v[j]->left = v[j]->right;
                    v[j]->right = temp;
                }
                curv.push_back(v[j]->left);
                curv.push_back(v[j]->right);
            }
            v = curv;
            curdepth++;
        }

        vector <int> curtree;
        inorder(root, curtree);
        ans.push_back(curtree);
    }

    return ans;
}