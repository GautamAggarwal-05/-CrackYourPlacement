class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearestx= max(x1,min(xCenter,x2));
        int nearesty = max(y1,min(yCenter,y2));
        int x,y;
        if(xCenter>nearestx)
            x=xCenter-nearestx;
        else
            x=nearestx-xCenter;
        
        if(yCenter>nearesty)
            y=yCenter-nearesty;
        else
            y=nearesty-yCenter;
        
        int dist = pow(x,2)+pow(y,2);
        if(dist <= (radius*radius))
            return true;
        return false;
    }
};