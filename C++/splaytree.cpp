#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
    int key;
    Node *left, *right, *parent;
};

class SplayTree {
public:
    Node *root;

    SplayTree() : root(nullptr) {}

    Node* newNode(int key) {
        Node* node = new Node;
        node->key = key;
        node->left = node->right = node->parent = nullptr;
        return node;
    }

    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr) y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    void rightRotate(Node* x) {
        Node* y = x->left;
        x->left = y->right;
        if (y->right != nullptr) y->right->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;
        y->right = x;
        x->parent = y;
    }

    void splay(Node* x) {
        while (x->parent != nullptr) {
            Node* p = x->parent;
            Node* g = p->parent;
            if (g == nullptr) { // Zig rotation
                if (x == p->left) rightRotate(p);
                else leftRotate(p);
            } else if (x == p->left && p == g->left) { // Zig-Zig (left-left)
                rightRotate(g);
                rightRotate(p);
            } else if (x == p->right && p == g->right) { // Zig-Zig (right-right)
                leftRotate(g);
                leftRotate(p);
            } else if (x == p->left && p == g->right) { // Zig-Zag (right-left)
                rightRotate(p);
                leftRotate(g);
            } else { // Zig-Zag (left-right)
                leftRotate(p);
                rightRotate(g);
            }
        }
        root = x;
    }

    Node* insert(int key) {
        Node* prev = nullptr;
        Node* temp = root;
        while (temp != nullptr) {
            prev = temp;
            if (key < temp->key) temp = temp->left;
            else if (key > temp->key) temp = temp->right;
            else { // Key already exists
                splay(temp);
                return temp;
            }
        }

        Node* node = newNode(key);
        node->parent = prev;
        if (prev == nullptr) root = node;
        else if (key < prev->key) prev->left = node;
        else prev->right = node;

        splay(node);
        return node;
    }

    Node* search(int key) {
        Node* temp = root;
        Node* lastVisited = nullptr;
        while (temp != nullptr) {
            lastVisited = temp;
            if (key < temp->key) temp = temp->left;
            else if (key > temp->key) temp = temp->right;
            else {
                splay(temp);
                return temp;
            }
        }
        if (lastVisited != nullptr) splay(lastVisited);
        return nullptr;
    }

    void remove(int key) {
        Node* node = search(key);
        if (node == nullptr || node->key != key) return;

        if (node->left == nullptr) {
            root = node->right;
            if (root != nullptr) root->parent = nullptr;
        } else if (node->right == nullptr) {
            root = node->left;
            if (root != nullptr) root->parent = nullptr;
        } else {
            Node* leftSubtree = node->left;
            Node* rightSubtree = node->right;
            
            leftSubtree->parent = nullptr; 
            
            Node* maxLeft = leftSubtree;
            while(maxLeft->right != nullptr) maxLeft = maxLeft->right;
            splay(maxLeft); 
            
            maxLeft->right = rightSubtree;
            if(rightSubtree != nullptr) rightSubtree->parent = maxLeft;
            root = maxLeft;
        }
        delete node;
    }

    void inorderTraversal(Node* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        std::cout << node->key << " ";
        inorderTraversal(node->right);
    }
};

int main() {
    SplayTree st;
    int choice, key;

    while (true) {
        std::cout << "\nSplay Tree Operations:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Search\n";
        std::cout << "3. Delete\n";
        std::cout << "4. Inorder Traversal\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter key to insert: ";
                std::cin >> key;
                st.insert(key);
                std::cout << "Key " << key << " inserted.\n";
                break;
            case 2:
                std::cout << "Enter key to search: ";
                std::cin >> key;
                if (st.search(key) != nullptr && st.root->key == key) {
                    std::cout << "Key " << key << " found and splayed to root.\n";
                } else {
                    std::cout << "Key " << key << " not found.\n";
                }
                break;
            case 3:
                std::cout << "Enter key to delete: ";
                std::cin >> key;
                st.remove(key);
                std::cout << "Key " << key << " deleted (if present).\n";
                break;
            case 4:
                std::cout << "Inorder Traversal: ";
                st.inorderTraversal(st.root);
                std::cout << "\n";
                break;
            case 5:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}