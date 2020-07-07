	void levelOrder(Node * root){
        //Write your code here
        queue <Node*> q;
        q.push(root);
        while (!q.empty()){
            Node* n = q.front();
            if (n == NULL){
                q.pop();
                continue;
            }
            cout << n->data << " ";
            q.push(n->left);
            q.push(n->right);
            q.pop();
        }
	}