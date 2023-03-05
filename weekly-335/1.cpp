class Solution {
public:
    int passThePillow(int n, int time) {
        int i = 1;
        while(time)
        {
            while(time && i<n)
            {
                i++;
                time--;
            }
            while(time and i>1)
            {
                i--;
                time--;
            }
        }
        return i;
    }
};