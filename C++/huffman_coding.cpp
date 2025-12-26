#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// A Huffman tree node
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparison object to order the heap based on frequency
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Function to print the Huffman Codes from the root of the tree
void printHuffmanCodes(Node* root, string str) {
    if (!root)
        return;

    // If this is a leaf node, then it contains one of the input characters
    if (!root->left && !root->right)
        cout << root->ch << ": " << str << "\n";

    printHuffmanCodes(root->left, str + "0");
    printHuffmanCodes(root->right, str + "1");
}

// Main function to build Huffman Tree and decode characters
void huffmanCoding(const unordered_map<char, int>& freqMap) {
    // Create a priority queue (min heap)
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : freqMap)
        pq.push(new Node(pair.first, pair.second));

    // Iterate until the heap contains only one node (root of the Huffman tree)
    while (pq.size() != 1) {
        // Remove the two nodes of highest priority (lowest frequency)
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        // Create a new internal node with these two nodes as children
        // The frequency of the new node is the sum of their frequencies
        Node* internalNode = new Node('$', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        // Add this node to the heap
        pq.push(internalNode);
    }

    // Print the Huffman codes by traversing the tree
    printHuffmanCodes(pq.top(), "");
}

int main() {
    // Input: Frequency of characters
    unordered_map<char, int> freqMap = {
        {'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}
    };

    // Build Huffman Tree and display the codes
    huffmanCoding(freqMap);

    return 0;
}
