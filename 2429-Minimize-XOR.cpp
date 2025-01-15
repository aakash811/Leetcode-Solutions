#include <bitset>
#include <cstdint>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bc1 = __builtin_popcount(num1); 
        int bc2 = __builtin_popcount(num2);
        if (bc1 >= bc2) {
            for (int i = 0; i < bc1 - bc2; ++i) {
                num1 = num1 & (num1 - 1); 
            }
        } else {
            for (int i = 0; i < bc2 - bc1; ++i) {
                num1 = ~(~num1 & (~num1 - 1));
            }
        }
        return num1;
    }
};
