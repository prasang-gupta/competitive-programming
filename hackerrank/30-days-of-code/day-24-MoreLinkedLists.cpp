Node* removeDuplicates(Node *head)
{
    //Write your code here
    Node *top = head, *unique = NULL;
    while (top != NULL){
        if (unique == NULL){
            unique = top;
            top = top->next;
            continue;
        }
        if (top->data == unique->data){
            Node * temp = top;
            top = top->next;
            unique->next = top;
            delete(temp);
        }
        else{
            unique = top;
            top = top->next;
        }
    }
    return head;
}