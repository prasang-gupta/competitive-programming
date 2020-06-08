class LRUCache : public Cache {
    public:
        LRUCache (int cap) {
            cp = cap;
            tail = NULL;
            head = NULL;
        }

        void set(int k, int v) {
            Node *newnode;

            if (mp.empty()){
                newnode = new Node(k, v);
                tail = newnode;
                head = newnode;
                mp[k] = newnode;
                return;
            }

            auto it = mp.find(k);
            if (it != mp.end()){
                it->second->value = v;

                if (it->second == head){
                    return;
                }

                it->second->prev->next = it->second->next;

                if (it->second == tail){
                    tail = tail->prev;
                }
                else{
                    it->second->next->prev = it->second->prev;
                }

                it->second->next = head;
                it->second->prev = NULL;
                head->prev = it->second;
                head = it->second;
            }
            else{
                newnode = new Node(head->prev, head, k, v);
                
                head->prev = newnode;
                head = newnode;
                mp[k] = newnode;

                if (mp.size() > cp){
                    tail = tail->prev;
                    mp.erase(tail->next->key);
                    delete tail->next;
                    tail->next = NULL;
                }
            }
        }

        int get(int k) {
            auto it = mp.find(k);
            return (it == mp.end()) ? -1 : it->second->value;
        }
};
