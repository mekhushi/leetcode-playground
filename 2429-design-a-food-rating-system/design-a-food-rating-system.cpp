#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineToHeap[cuisines[i]].push({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        const string& cuisine = foodToCuisine[food];
        foodToRating[food] = newRating;
        cuisineToHeap[cuisine].push({newRating, food});
    }

    string highestRated(string cuisine) {
        auto& maxHeap = cuisineToHeap[cuisine];
        while (true) {
            auto [rating, food] = maxHeap.top();
            if (foodToRating[food] == rating) {
                return food;
            }
            maxHeap.pop();
        }
    }

private:
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;

    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
    };

    unordered_map<string, priority_queue<pair<int, string>, vector<pair<int, string>>, Compare>> cuisineToHeap;
};
