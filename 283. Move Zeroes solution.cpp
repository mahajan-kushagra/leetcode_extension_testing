class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        short offset= 0, lastIndex= 0;
        for(short i= 0; i < nums.size(); i++){
            if(!nums[i]){
                offset++;
                continue;
            }
            nums[i - offset]= nums[i];
            lastIndex++;
        }
        while(lastIndex < nums.size())
            nums[lastIndex++]= 0;
    }
};