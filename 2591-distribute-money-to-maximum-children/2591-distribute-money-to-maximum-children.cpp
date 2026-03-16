class Solution {
public:
    int distMoney(int money, int children) {
        // Check if there is enough money to distribute
        if(money<children)return -1;
        // Allocate single dollar to every child
        money-=children;
        // Initialise a count to track the number of people who receive 8 dollar
        int count = 0;
        // Check the number childrens who can receive 8 dollars
        count = min(children, money/7);
        // Remove the money allocated
        money-=(count*7);
        // Remove the number of childrens who receive 
        children-=count;
        // check if you children left || money left
        if((children==1&&money==3)||(children==0&&money>0))count--;
        return count;
    }
};
