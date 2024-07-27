class LRUCache {
public:
    class   Node{
        public:
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int key,int value){
            this->key = key;
            this->value = value;
        }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    int cap;
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void insert(Node* newNode){
        Node* temp = head->next;

        newNode->next = temp;
        newNode->prev = head;

        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(Node* delnode){
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            Node* resNode = mp[key];
            int ans= resNode->value;

            mp.erase(key);
            deleteNode(resNode);
            insert(resNode);
            mp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        insert(new Node(key,value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */