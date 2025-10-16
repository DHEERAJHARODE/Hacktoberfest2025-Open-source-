#include <iostream>
#include <map>
using namespace std;

// Methods ---> insert / delete / update / iterate

int main() {
    map<int, string> m;

    // insert key-value pairs
    m[1] = "Apple";
    m[3] = "Banana";
    m[2] = "Cherry";

    // another insertion method
    m.insert({4, "Date"});

    // iterate
    cout << "Map contents:\n";
    for (auto &p : m)
        cout << p.first << " => " << p.second << endl;

    // find an element
    if (m.find(3) != m.end())
        cout << "Found key 3: " << m[3] << endl;

    // erase an element
    m.erase(2);

    cout << "After erase:\n";
    for (auto &p : m)
        cout << p.first << " => " << p.second << endl;

    return 0;
}
