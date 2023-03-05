class Solution {
public:
    int mod = 1e9+7;
    long long rec(int i, int target, vector<vector<int>> &dp, vector<vector<int>> &types)
    {
        if(target == 0) return 1;
        if(i == types.size()) return target == 0;
        if(dp[i][target] != -1) return dp[i][target]%mod;
        long long notTake = rec(i+1, target, dp, types);
        long long take = 0;
        for(int curr = 1;curr<=types[i][0];curr++)
        {
            if((target - types[i][1]*curr) >= 0)
                take += rec(i+1, target - types[i][1]*curr, dp, types)%mod;
        }
        return dp[i][target] = (take+notTake)%mod;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return rec(0, target, dp, types);
    }
};