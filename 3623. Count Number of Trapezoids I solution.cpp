#define MOD ((int) 1e9 + 7)
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int count = 0;
        long long sum = 0;
        unordered_map<int,int> xCoords;
        for (auto v : points)
            xCoords[v[1]]++;
        for (auto it : xCoords) {
            count = (count + (sum * it.second * (it.second - 1)) / 2) % MOD;
            sum += ((long long) it.second * (it.second - 1)) / 2;
        }
        return count % MOD;
    }
};