#include <iostream>
#include <utility> // for pair
using namespace std;

int main() {
    pair<int, string> p1 = {1, "Alice"};
    cout << p1.first << " " << p1.second << endl;

    // another way
    pair<int, string> p2 = make_pair(2, "Bob");
    cout << p2.first << " " << p2.second << endl;

    // nested pair
    pair<int, pair<string, double>> p3 = {3, {"Charlie", 85.6}};
    cout << p3.first << " " << p3.second.first << " " << p3.second.second << endl;

    // we can also combine it in another data structures like vector for example vector<pair<int,int>>ab;

    

    return 0;
}
