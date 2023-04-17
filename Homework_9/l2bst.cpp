//treeNode struct
template <typename elemType>
struct TreeNode {
    int elem;
    TreeNode<elemType> *left;
    TreeNode<elemType> *right;
    TreeNode(int elem) {
        this->elem = elem;
        this->left = nullptr;
        this->right = nullptr;
    }
};

//listNode struct
template <typename elemType>
struct ListNode {
    int elem;
    ListNode<elemType> *next;
    ListNode(int elem) {
        this->elem = elem;
        this->next = nullptr;
    }
};

template <typename elemType>
TreeNode<elemType> *bst2l(ListNode<elemType> *head) {
    if (head == nullptr){
        return nullptr;
    }


    ListNode<elemType> *middle = head;
    ListNode<elemType> *left_side = nullptr;
    ListNode<elemType> *right_side = nullptr;

    //find the middle using an iterator that travels two elems every iteration
    ListNode<elemType> *iterator = head;
    while ((iterator != nullptr) && (iterator->next != nullptr)) {
        left_side = middle;
        middle = middle->next;
        iterator = iterator->next->next;
    }
    right_side = middle->next;

    TreeNode<elemType> root = new TreeNode<elemType>(middle->elem);

    //recursively find the left child of each node
    if (left_side != nullptr) {
        left_side->next = nullptr;
        root->left = bst2l(root);
    }

    //recursively find the right child of each node
    root->right = bst2l(right_side);
}