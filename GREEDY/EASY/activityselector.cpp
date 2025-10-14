#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an activity
struct Activity {
    int start, finish;
};

// Comparator to sort activities by finish time
bool activityCompare(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}

// Function to select maximum activities
void selectActivities(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), activityCompare);

    cout << "Selected activities:\n";

    int lastFinish = 0;
    for (const auto& act : activities) {
        if (act.start >= lastFinish) {
            cout << "(" << act.start << ", " << act.finish << ") ";
            lastFinish = act.finish;
        }
    }
    cout << endl;
}

int main() {
    vector<Activity> activities = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}
    };

    selectActivities(activities);

    return 0;
}
