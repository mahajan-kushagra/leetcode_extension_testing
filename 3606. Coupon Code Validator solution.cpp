class Solution {
private:
    bool validateCode(vector<string>& code, string s) {
        if (s == "")
            return false;
        for (char ch : s) {
            if (!isalnum(ch) && ch != '_')
                return false;
        }
        return true;
    }
    bool validateBL(vector<string>& businessLine, string s) {
        return (s == "electronics" ||
            s == "grocery" ||
            s == "pharmacy" ||
            s == "restaurant");
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<int> indices;
        for (int i = 0; i < code.size(); i++)
            if (isActive[i] && validateBL(businessLine, businessLine[i]) && validateCode(code, code[i]))
                indices.push_back(i);
        sort(indices.begin(), indices.end(), [&businessLine, &code](int a, int b) {
            if (businessLine[a] == businessLine[b])
                return (code[a] < code[b]);
            return (businessLine[a] < businessLine[b]);
        });
        vector<string> result;
        for (int it : indices)
            result.push_back(code[it]);
        return result;
    }
};