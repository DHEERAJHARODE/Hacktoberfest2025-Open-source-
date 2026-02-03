#include <iostream>
#include <list>

struct Node {
    int data;
    Node* next;
};

int main() {
    std::list<Node> linkedList;

    // Create the linked list
    linkedList.push_back({ 10, nullptr });
    linkedList.push_back({ 20, nullptr });
    linkedList.push_back({ 30, nullptr });

    // Connect the nodes
    auto it = linkedList.begin();
    auto prev = it;
    while (++it != linkedList.end()) {
        prev->next = &(*it);
        prev = it;
    }

    // Print the linked list
    Node* current = &linkedList.front();
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}
