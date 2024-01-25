class Solution {
public:
    int countCollisions(string directions) {
        int ans =0;
        int cntRight = 0;
        bool stay = false;  // it use for show that accident happended at that position

        for(int i=0;i<directions.size();i++){
            char ch = directions[i];
            if(ch=='R'){
                cntRight++; // count right moving car
            }else if(ch=='L'){
                if(cntRight>0){
                    ans+=2; // bcz 2 cars are collide
                    cntRight--; // decrement previously right moving car bcz it collide with left car and car will stay at that position
                    ans+=cntRight; // all the previously right moving car are also collide hence accident is happend at thr point.
                    cntRight = 0; // no right moving car left bcz all cars are collide

                    stay = true; // accident happend at that position 
                }
                else if(stay){  // if accident happend and cars moving left so they will collide
                    ans+=1;
                }
            }else if(ch=='S'){
                ans+=cntRight; // all right moving car are collide with the stayed car;
                cntRight =0;
                stay = true;
            }
        }
        return ans;
    }
};
