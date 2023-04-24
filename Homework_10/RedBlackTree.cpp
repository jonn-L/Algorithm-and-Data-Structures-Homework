#include "RedBlackTree.hpp"
#include <iostream>

RedBlackTree::RedBlackTree() {
    this->root = this->nil;
}

void RedBlackTree::rotateLeft(Node *&rotate) {
    Node *pivot = new Node;
    pivot->data = rotate->right->data;
    pivot->left = rotate->right->left;
    pivot->right = rotate->right->right;

    rotate->right = pivot->left;

    if (pivot->left != this->nil) {
        pivot->left->parent = rotate;
    }
    pivot->parent = rotate->parent;

    if (rotate->parent == this->nil) {
        this->root = pivot;
    }
    else if (rotate == rotate->parent->left) {
        rotate->parent->left = pivot;
    }
    else {
        rotate->parent->right = pivot;
    }

    rotate->parent = pivot;
    pivot->left = rotate;
}


void RedBlackTree::rotateRight(Node *&rotate) {
    Node *pivot = new Node;
    pivot->data = rotate->left->data;
    pivot->left = rotate->left->left;
    pivot->right = rotate->left->right;

    rotate->left = pivot->right;

    if (pivot->right != this->nil) {
        pivot->right->parent = rotate;
    }
    pivot->parent = rotate->parent;

    if (rotate->parent == this->nil) {
        this->root = pivot;
    }
    else if (rotate == rotate->parent->right) {
        rotate->parent->right = pivot;
    }
    else {
        rotate->parent->left = pivot;
    }

    pivot->right = rotate;
    rotate->parent = pivot;
}

void RedBlackTree::insertRB_fixup(Node *&new_node) {
    if (new_node == this->root) {
        new_node->color = BLACK;
        return;
    }
    
    while (new_node->parent->color == RED) {
        if (new_node->parent == new_node->parent->parent->left) {
            Node *uncle = new_node->parent->parent->right;
            
            if (uncle->color == RED) {
                new_node->parent->color = BLACK;
                uncle->color = BLACK;
                new_node->parent->parent->color = RED;
                new_node = new_node->parent->parent;
                break;
            }
            else if (new_node == new_node->parent->right) {
                new_node = new_node->parent;
                rotateLeft(new_node);

                new_node->parent->color = BLACK;
                new_node->parent->parent->color = RED;
                rotateRight(new_node->parent->parent);
            }
        }
        else {
            Node *uncle = new_node->parent->parent->left;

            if ((uncle != this->nil) && (uncle->color == RED)) {
                new_node->parent->color = BLACK;
                uncle->color = BLACK;
                new_node->parent->parent->color = RED;
                new_node = new_node->parent->parent;
            }
            else if (new_node == new_node->parent->left) {
                new_node = new_node->parent;
                rotateRight(new_node);

                new_node->parent->color = BLACK;
                new_node->parent->parent->color = RED;
                rotateLeft(new_node->parent->parent);
            }
        }
    }

    this->root->color = BLACK;
}

void RedBlackTree::insertRB(int new_data) {
    Node *new_node = new Node; 
    new_node->data = new_data;

    Node *leaf = this->nil;
    Node *iterator = this->root;

    while (iterator != this->nil) {
        leaf = iterator;
        if (new_node->data < iterator->data) {
            iterator = iterator->left;
        }
        else {
            iterator = iterator->right;
        }
    }

    new_node->parent = leaf;
    if (leaf == this->nil) {
        this->root = new_node;
    }
    else if (new_node->data < leaf->data) {
        leaf->left = new_node;
    }
    else {
        leaf->right = new_node;
    }
    
    new_node->left = this->nil;
    new_node->right = this->nil;
    new_node->color = RED;
    insertRB_fixup(new_node);
}

void RedBlackTree::transplantRB(Node *&node, Node*&subtree) {
    if (node->parent == this->nil) {
        this->root = subtree;
    }
    else if (node == node->parent->left) {
        node->parent->left = subtree;
    }
    else {
        node->parent->right = subtree;
    }

    if (subtree != this->nil) {
        subtree->parent = node->parent;
    }
}

void RedBlackTree::deleteRB_fixup(Node *&node) {
    while (node != root && node->color == BLACK) {
        if (node == node->parent->left) {
            Node* sibling = node->parent->right;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rotateLeft(node->parent);
                sibling = node->parent->right;
            }

            if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
                sibling->color = RED;
                node = node->parent;
            } 
            else {
                if (sibling->right->color == BLACK) {
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    rotateRight(sibling);
                    sibling = node->parent->right;
                }

                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->right->color = BLACK;
                rotateLeft(node->parent);
                node = root;
            }
        } 
        else {
            Node* sibling = node->parent->left;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rotateRight(node->parent);
                sibling = node->parent->left;
            }

            if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
                sibling->color = RED;
                node = node->parent;
            } 
            else {
                if (sibling->left->color == BLACK) {
                    sibling->right->color = BLACK;
                    sibling->color = RED;
                    rotateLeft(sibling);
                    sibling = node->parent->left;
                }

                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->left->color = BLACK;
                rotateRight(node->parent);
                node = root;
            }
        }
    }
    node->color = BLACK;
}

void RedBlackTree::deleteRB(Node *&delete_node) {
    Node* to_delete = delete_node;
    Node* child;
    Color original_color = to_delete->color;

    if (delete_node->left == this->nil) {
        child = delete_node->right;
        transplantRB(delete_node, delete_node->right);
    } 
    else if (delete_node->right == this->nil) {
        child = delete_node->left;
        transplantRB(delete_node, delete_node->left);
    } 
    else {
        to_delete = getMinimum(delete_node->right);
        original_color = to_delete->color;
        child = to_delete->right;

        if (to_delete->parent == delete_node) {
            child->parent = to_delete;
        } 
        else {
            transplantRB(to_delete, to_delete->right);
            to_delete->right = delete_node->right;
            to_delete->right->parent = to_delete;
        }

        transplantRB(delete_node, to_delete);
        to_delete->left = delete_node->left;
        to_delete->left->parent = to_delete;
        to_delete->color = delete_node->color;
    }

    if (original_color == BLACK) {
        deleteRB_fixup(child);
    }

    delete to_delete;
}

Node *RedBlackTree::predecessor(Node *&node) const {
    if (node->left != this->nil) {
        Node *predecessor = getMaximum(node);
        return predecessor;
    }

    Node *predecessor = node->parent;
    while ((predecessor != this->nil) && (node == predecessor->left)) {
        node = predecessor;
        predecessor = predecessor->parent;
    }

    return predecessor;
}

Node *RedBlackTree::successor(Node *&node) const{
    if (node->right != this->nil) {
        Node *successor = getMinimum(node);
        return successor;
    }

    Node *successor = node->parent;
    while ((successor != this->nil) && (node == successor->right)) {
        node = successor;
        successor = successor->parent;
    }

    return successor;
}

Node *RedBlackTree::getMinimum(Node *node) const {
    Node *minimum = node;
    while (minimum->left != this->nil) {
        minimum = minimum->left;
    }

    return minimum;
}

Node *RedBlackTree::getMaximum(Node *node) const {
    Node *maximum = node;
    while (maximum->right != this->nil) {
        maximum = maximum->right;
    }

    return maximum;
}

Node *RedBlackTree::search(int value) const {
    Node *curr = this->root;
    while ((curr != nullptr) || (curr->data != value)) {
        if (curr->data > value) {
            curr = curr->left;
        }
        else {
            curr = curr->right;
        }
    }

    if (curr != nullptr) {
        return curr;
    }

    throw std::out_of_range("Value not Found!");
}
