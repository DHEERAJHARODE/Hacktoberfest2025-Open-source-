#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;

    // insert elements
    s.insert(5);
    s.insert(1);
    s.insert(3);
    s.insert(3); // duplicate ignored

    cout << "Set elements: ";
    for (int x : s) cout << x << " ";
    cout << endl;

    // check if element exists
    if (s.find(3) != s.end()) cout << "3 found!" << endl;

    // erase element
    s.erase(1);

    cout << "After erase: ";
    for (int x : s) cout << x << " ";
    cout << endl;

    return 0;
}
