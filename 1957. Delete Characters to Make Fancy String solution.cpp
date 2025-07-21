class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() < 3)
            return s;
        string result = "";
        result += s[0];
        result += s[1];
        bool same01 = (s[0] == s[1]), same12;
        for (int i = 2; i < s.size(); i++) {
            same12 = (s[i] == s[i - 1]);
            if (!same01 || !same12)
                result += s[i];
            same01 = same12;
        }
        return result;
    }
};