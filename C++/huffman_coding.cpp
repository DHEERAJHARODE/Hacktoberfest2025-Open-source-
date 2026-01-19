#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Node {
    char data;
    size_t frequency;
    Node* left;
    Node* right;

    Node(char data, size_t frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}

    Node(char data, size_t frequency, Node* left, Node* right) : data(data), frequency(frequency), left(left), right(right) {}

    ~Node() {
        delete left;
        delete right;
    }
};

struct NodeCompare {
    bool operator() (const Node* a, const Node* b) const {
        return a->frequency > b->frequency;
    }
};

void generate_codes(Node* root, string code, unordered_map<char, string>& huffman_codes) {
    if (!root) {
        return;
    }

    if (!root->left && !root->right) {
        huffman_codes[root->data] = code;
    }

    generate_codes(root->left, code + "0", huffman_codes);
    generate_codes(root->right, code + "1", huffman_codes);
}

pair<string, unordered_map<char, string>> huffman_encoding(const string& data) {
    unordered_map<char, size_t> frequency;
    for (char c : data) {
        frequency[c]++;
    }

    priority_queue<Node*, vector<Node*>, NodeCompare> pq;
    for (const auto& entry : frequency) {
        pq.push(new Node(entry.first, entry.second));
    }

    while (pq.size() != 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('\0', left->frequency + right->frequency, left, right);
        pq.push(parent);
    }

    unordered_map<char, string> huffman_codes;
    generate_codes(pq.top(), "", huffman_codes);

    string encoded_data;
    for (char c : data) {
        encoded_data += huffman_codes[c];
    }

    return {encoded_data, huffman_codes};
}

string huffman_decoding(const string& data, const unordered_map<char, string>& huffman_codes) {
    unordered_map<string, char> reverse_map;
    for (const auto& entry : huffman_codes) {
        reverse_map[entry.second] = entry.first;
    }

    string decoded_data;
    string code;
    for (char bit : data) {
        code += bit;
        if (reverse_map.find(code) != reverse_map.end()) {
            decoded_data += reverse_map.at(code);
            code = "";
        }
    }

    return decoded_data;
}

int main() {
    string data = "hello";
    auto result = huffman_encoding(data);
    string encoded_data = result.first;
    unordered_map<char, string> huffman_codes = result.second;

    string decoded_data = huffman_decoding(encoded_data, huffman_codes);

    cout << "Original data: " << data << endl;
    cout << "Encoded data: " << encoded_data << endl;
    cout << "Decoded data: " << decoded_data << endl;

    return 0;
}
