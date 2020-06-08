Node* insert(Node *head,int data)
    {
        //Complete this method

        Node *newnode = new Node(data);
        if (head == NULL){
            return newnode;
        }
        
        Node *iter = head;
        while (iter->next != NULL){
            iter = iter->next;
        }
        iter->next = newnode;
        return head;
    }