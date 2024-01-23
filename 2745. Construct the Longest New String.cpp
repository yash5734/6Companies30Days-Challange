class Solution {
public:
    int longestString(int x, int y, int z) {
        if(x==y) return 2*(x+y+z);
        else if(x<y) y = 1+x;
        else if(y<x) x = 1+y;
        return 2*(x+y+z);
    }
};
