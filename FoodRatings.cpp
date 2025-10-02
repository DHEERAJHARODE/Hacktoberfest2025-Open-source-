#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
public:
    unordered_map<string, string> foodtocuisine;   // maps food -> cuisine
    unordered_map<string, int> foodtorating;       // maps food -> rating

    struct cmp {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first) {
                return a.second > b.second; // smaller lexicographic food first
            }
            return a.first < b.first; // higher rating first
        }
    };

    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, cmp>> cuisineHeap;

    // Constructor
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < (int)foods.size(); i++) {
            foodtocuisine[foods[i]] = cuisines[i];
            foodtorating[foods[i]] = ratings[i];
            cuisineHeap[cuisines[i]].push({ratings[i], foods[i]});
        }
    }

    // Change the rating of a food
    void changeRating(string food, int newRating) {
        string cuisine = foodtocuisine[food];
        foodtorating[food] = newRating;
        cuisineHeap[cuisine].push({newRating, food});
    }

    // Get highest rated food in a cuisine
    string highestRated(string cuisine) {
        auto& heap = cuisineHeap[cuisine];
        while (!heap.empty()) {
            auto [rating, food] = heap.top();
            if (foodtorating[food] == rating) {
                return food; // valid entry
            }
            heap.pop(); // outdated entry
        }
        return "";
    }
};

int main() {
    vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
    vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
    vector<int> ratings = {9, 12, 8, 15, 14, 7};

    FoodRatings obj(foods, cuisines, ratings);

    cout << obj.highestRated("korean") << "\n";   // kimchi
    cout << obj.highestRated("japanese") << "\n"; // ramen

    obj.changeRating("sushi", 16);

    cout << obj.highestRated("japanese") << "\n"; // sushi

    obj.changeRating("ramen", 16);

    cout << obj.highestRated("japanese") << "\n"; // ramen (tie -> lexicographically smaller)
    
    return 0;
}
