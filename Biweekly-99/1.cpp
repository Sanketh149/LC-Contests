class Solution {
public:
    int splitNum(int num) {
        string res = to_string(num);
        sort(res.begin(), res.end());
        string s1, s2;
        for(int i = 0;i<res.size();i+=2)
        {
            s1 += res[i];
            s2 += res[i+1];
        }
        return stoi(s1)+stoi(s2);
    }
};
