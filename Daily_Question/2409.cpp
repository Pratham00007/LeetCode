#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int date_to_day(string date,vector<int>mth_day){
            int mth=stoi(date.substr(0,2));
            int days=stoi(date.substr(3));

            return mth_day[mth-1]+days;
        }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        
        vector<int>mth_day={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        vector<int>cntMthDy(13,0);

        cntMthDy[1]=31;
        for(int i=2;i<=12;i++) {
            cntMthDy[i]=cntMthDy[i-1]+mth_day[i-1];


        }

        int Alice_arive=date_to_day(arriveAlice,cntMthDy);
        
        int Alice_leave=date_to_day(leaveAlice,cntMthDy);
        
        int bob_arive=date_to_day(arriveBob,cntMthDy);
        
        int bob_leave=date_to_day(leaveBob,cntMthDy);
        
        int overLap=min(Alice_leave,bob_leave )- max(Alice_arive,bob_arive)+1;
        
        return overLap<0 ? 0 : overLap;

        

    }
};