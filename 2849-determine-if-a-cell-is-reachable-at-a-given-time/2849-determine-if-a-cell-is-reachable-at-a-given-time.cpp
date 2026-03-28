class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx==fx&&sy==fy&&t==1)return false;
        int dx = abs(fx-sx);
        int dy = abs(sy-fy);
        return max(dx, dy)<=t?true:false;
    }
};