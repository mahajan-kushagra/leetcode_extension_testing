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
    /* string makeFancyS tring2(string s) {
        int offset = 0;
        bool same01, same12;
        for (int i = 2; i < s.size() - offset;) {
            s[i] = s[i + offset];
            same01 = (s[i - 1] == s[i - 2]);
            same12 = (s[i - 1] == s[i]);
            if (same01 && same12) {
                while (i + offset < s.size() && s[i] == s[i + offset])
                    offset++;
            }
            else ++i;
        }
        if (s.size() > 3 && s[s.size() - 1] == s[s.size() - 2] && s[s.size() - 2] == s[s.size() - 3])
            offset++;
        if (offset)
            s.resize(s.size() - offset);
        return s;
    } */
};