class Solution {
public:
    int poww(int b, int p)
    {
        int res = 1;
        while(p--)
        {
            if(res >= mod)
            {
                res %= mod;
            }
            res *= b;
        }
        return res%mod;
    }
    int mod = 1e9 + 7;
    int countWays(vector<vector<int>>& ranges) {
        vector<vector<int>>res;
        sort(ranges.begin(), ranges.end());
        res.push_back(ranges[0]);
        for(int i = 1;i<ranges.size();i++)
        {
            vector<int> &recent = res.back();
            if(ranges[i][0] <= recent[1])
            {
                recent[1] = max(recent[1], ranges[i][1]);
            }
            else 
            {
                res.emplace_back(ranges[i]);
            }
        }
        
        return poww(2,res.size());
    }
};