class Solution {
public:
    int distMoney(int money, int children) {
        if(money < children)
            return -1;
        money -= children;
        if(money < 7 * children)
            // int result= money/7;
            // return result - ((money % 7 == 3) && (children - result == 1));
            return money/7 - ((money % 7 == 3) && (children - money/7 == 1));
        return children - (money > 7 * children);
        
        // if(result == children - 1 && money % 7 == 3 && result > 0)
        //     result--;
        // return result;
    }
};