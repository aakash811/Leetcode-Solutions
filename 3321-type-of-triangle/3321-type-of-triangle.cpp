class Solution {
public:
    string triangleType(vector<int>& nums) {
        int x = nums[0];
        int y = nums[1];
        int z = nums[2];

        if((x + y > z) && (x + z > y) && (z + y > x)){
            if(x == y && y == z){
                return "equilateral";
            }
            if((x == y && x != z) || (z == y && z != x) || (x == z && x != y)){
                return "isosceles";
            } 
            else{
                return "scalene";
            }
        }

        return "none";
    }
};