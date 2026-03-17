class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children)return -1;
        money-=children;
        int count = min(children, money/7);
        money-=(count*7);
        children-=count;
        if(money>0&&children==0)count--;
        if(money==3&&children==1)count--;
        return count;
    }
};