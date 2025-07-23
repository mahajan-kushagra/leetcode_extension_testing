class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string result = "";
        for(short int i = 0; i < numRows; i++){
            short int ss = 2*(numRows - 1 - i);
            bool isEven = true;
            for(short int j = i; j < s.length(); ){
                result += s[j];
                if(i == 0 || i == numRows - 1){
                    j += 2*(numRows - 1);
                    continue;
                }
                else if(isEven)
                    j += ss;
                else
                    j += 2*numRows - 2 - ss;
                isEven = !isEven;
            }
        }
        return result;
    }
};