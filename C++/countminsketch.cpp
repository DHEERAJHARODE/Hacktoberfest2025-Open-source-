#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <limits>

using namespace std;

class CountMinSketch {
private:
    int width, depth;
    vector<vector<int>> table;
    vector<hash<string>> hashFunctions;

public:
    CountMinSketch(int width, int depth) : width(width), depth(depth), table(depth, vector<int>(width, 0)) {
        for (int i = 0; i < depth; ++i) {
            hashFunctions.push_back(hash<string>());
        }
    }

    void update(const string& item, int count = 1) {
        for (int i = 0; i < depth; ++i) {
            size_t hashVal = hashFunctions[i](item + to_string(i));
            int index = hashVal % width;
            table[i][index] += count;
        }
    }

    int estimate(const string& item) const {
        int minCount = numeric_limits<int>::max();
        for (int i = 0; i < depth; ++i) {
            size_t hashVal = hashFunctions[i](item + to_string(i));
            int index = hashVal % width;
            minCount = min(minCount, table[i][index]);
        }
        return minCount;
    }
};

int main() {
    int width = 20, depth = 5;
    CountMinSketch cms(width, depth);

    string command;
    cout << "Count-Min Sketch Interactive Console\n";
    cout << "Commands:\n  add <item> <count>\n  query <item>\n  exit\n";

    while (true) {
        cout << "> ";
        cin >> command;

        if (command == "add") {
            string item;
            int count;
            cin >> item >> count;
            cms.update(item, count);
            cout << "Added " << count << " to '" << item << "'\n";
        } else if (command == "query") {
            string item;
            cin >> item;
            int estimate = cms.estimate(item);
            cout << "Estimated count for '" << item << "': " << estimate << "\n";
        } else if (command == "exit") {
            break;
        } else {
            cout << "Unknown command. Try 'add', 'query', or 'exit'.\n";
        }
    }

    return 0;
}