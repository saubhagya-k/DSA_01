// Last updated: 05/08/2026, 17:03:19
class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int size = height.size();
        int l=0;
        int r = size-1;

        int maxArea = 0;

        while(l<r){
            int h = min(height[l],height[r]);

            int width = r-l;

            int area = h*width;

            maxArea = max(maxArea,area);


            if(height[l]<=height[r]){
                l++;
            }
            else r--;
        }

        return maxArea;
    }
};