class Solution {
public:
    double angleClock(int hour, int minutes) {
        double x=abs((float((hour%12))*30)-(float(minutes)*(5.5)));
        return min(x,360-x);
    }
};