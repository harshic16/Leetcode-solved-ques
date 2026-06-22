class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int countB=0,countA=0,countL=0,countO=0,countN=0;
        for(char c : text){
            if(c=='b') countB++;
            if(c=='a') countA++;
            if(c=='l') countL++;
            if(c=='o') countO++;
            if(c=='n') countN++;
        }
        int ans=0;
        ans=min({countB,countA,countL/2,countO/2,countN});
        return ans;
    }
};