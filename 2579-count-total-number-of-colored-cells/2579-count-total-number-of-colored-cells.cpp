class Solution {
public:
    long long coloredCells(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 5;
        }
        if(n == 3){
            return 13;
        }

        int rectArea = 1;
        if(n % 2 == 0){
            rectArea = (n - 1)*(n - 1);
        }
        else{
            rectArea = n * n;
        }
        cout<<rectArea<<endl;

        int x = 0;
        int add = 1;
        for(int i = 0; i < n/2; i++)
        {
            x += add;
            add += 2;
        }
        cout<<x<<endl;
        rectArea += 4 * x;
        return rectArea;
    }
};