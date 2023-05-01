struct Node {
    int key;
    int value;
    Node(int key, int value) {
        this->key = key;
        this->value = value;
    }
};

class HashTable {
    private:
        Node **arr;
        int maxSize;
        int currentSize;
    public:
        HashTable();
        
        int hashCode(int key);
        void insertNode(int key, int value);
        int get(int key);
        bool isEmpty() const;
};
  
