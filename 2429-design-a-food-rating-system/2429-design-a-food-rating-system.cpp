class FoodRatings {
public:
    unordered_map<string, string>foodToCuisine;
    unordered_map<string, int>foodToRating;
    unordered_map<string, set<pair<int, string>>>cuisineToFood;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++){
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] =  ratings[i];
            cuisineToFood[cuisines[i]].insert({-ratings[i], foods[i]});
        }    
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];

        cuisineToFood[cuisine].erase({-oldRating, food});
        cuisineToFood[cuisine].insert({-newRating, food});
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisineToFood[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */