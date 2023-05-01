#include <iostream>

//node struct
template <typename elemType>
struct Node {
    int elem;
    Node<elemType> *left;
    Node<elemType> *right;
    //Node constructor 
    Node(int elem) {
        this->elem = elem;
        this->left = nullptr;
        this->right = nullptr;
    }
};

template <typename elemType>
void convert(Node<elemType> *root, Node<elemType> *&prev, Node<elemType> *&head) {
    if (root == nullptr) {
        return;
    }
    //float all the way down to the left-most node
    convert(root->left, prev, head);

    if (prev == nullptr) {
        //assign head
        head = root;
    }
    else {
        //this adds the root to the linked list
        prev->right = root;
    }

    //prepare for the next elem by making the current root the previous element
    //of the linked list
    prev = root;
    //do the same for the right side
    convert(root->right, prev, head);
}

template <typename elemType>
Node<elemType> *bst_to_list(Node<elemType> *root) {
    if (root == nullptr) {
        return nullptr;
    }

    /*
        head - holds the head of the linked list
        prev - holds the previous elem of the linked list
    */
    Node<elemType> *prev = nullptr;
    Node<elemType> *head = nullptr;
    convert(root, prev, head);

    return head;
}

int main() {
    Node<int>* root = new Node<int>(4);
    root->left = new Node<int>(2);
    root->right = new Node<int>(5);
    root->left->left = new Node<int>(1);
    root->left->right = new Node<int>(3);

    Node<int>* linked_list_head = bst_to_list(root);
    while (linked_list_head) {
        std::cout << linked_list_head->elem << " ";
        linked_list_head = linked_list_head->right;
    }
    std::cout << std::endl;

    return 0;
}