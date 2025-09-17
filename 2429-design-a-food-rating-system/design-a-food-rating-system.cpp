class FoodRatings {
public:

    unordered_map <string, int> food_ratings;
    unordered_map <string, set<pair<int, string>>> cuisines_ratings_food;
    unordered_map <string, string> food_cuisines;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0; i < n; i++) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];

            cuisines_ratings_food[cuisine].insert({-rating, food});
            food_cuisines[food] = cuisine;
            food_ratings[food] = rating; 
        }
        
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = food_cuisines[food];
        int oldRating = food_ratings[food];
        food_ratings[food] = newRating;
        cuisines_ratings_food[cuisine].erase({-oldRating, food});
        cuisines_ratings_food[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return cuisines_ratings_food[cuisine].begin() -> second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */