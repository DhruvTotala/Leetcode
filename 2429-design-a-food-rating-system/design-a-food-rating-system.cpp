class FoodRatings {
public:
    unordered_map<string, pair<string, int>> foodInfo; // food -> {cuisine, rating}
    unordered_map<string, set<pair<int, string>>> cuisineRatings; // cuisine -> sorted set { -rating, food }

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodInfo[foods[i]] = {cuisines[i], ratings[i]};
            cuisineRatings[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [cuisine, oldRating] = foodInfo[food];
        // Remove old entry
        cuisineRatings[cuisine].erase({-oldRating, food});
        // Insert new entry
        cuisineRatings[cuisine].insert({-newRating, food});
        // Update food info
        foodInfo[food] = {cuisine, newRating};
    }
    
    string highestRated(string cuisine) {
        // First element = highest rating (lowest -rating)
        return cuisineRatings[cuisine].begin()->second;
    }
};
