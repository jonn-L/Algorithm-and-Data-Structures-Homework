enum Color {RED, BLACK};
struct Node {
    int data;
    Color color;
    Node *left, *right, *parent;

};

class RedBlackTree {
    public:
        Node *root;
        Node *nil = nullptr;
    protected:
        void rotateLeft(Node *&);
        void rotateRight(Node *&);
    public:
        RedBlackTree();
        
        void insertRB_fixup(Node *&);
        void insertRB(int);

        void transplantRB(Node *&, Node *&);
        void deleteRB_fixup(Node *&);
        void deleteRB(Node *&);

        Node *predecessor(Node *&) const;
        Node *successor(Node *&) const;

        Node *getMinimum(Node *) const;
        Node *getMaximum(Node *) const;

        Node *search(int) const;
};