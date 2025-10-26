class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_ans = 0;
        int i = 0;
        int j = n - 1;
        while(i < j) {
            int h = min(height[i], height[j]);
            int width = j - i;
            int area = h * width;
            max_ans = max(max_ans, area);

            if(height[i] < height[j]) i++;
            else j--; 
        }
        return max_ans;
    }
};