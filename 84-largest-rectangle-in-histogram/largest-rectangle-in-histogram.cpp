class Solution {
public:

    vector <int> p_small(vector <int>& heights) {
        int n = heights.size();
        vector <int> pre_smaller(n, -1);
        stack <int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(!st.empty()) {
                pre_smaller[i] = st.top();
            }
            st.push(i);
        }
        return pre_smaller;
    }

    vector <int> s_small(vector <int>& heights) {
        int n = heights.size();
        vector <int> next_smaller(n, n);
        stack <int> st;
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if(!st.empty()) {
                next_smaller[i] = st.top();
            }
            st.push(i);
        }
        return next_smaller;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        vector <int> pre_smaller = p_small(heights);
        vector <int> next_smaller = s_small(heights);
        for(int i = 0; i < n; i++) {
            int width = next_smaller[i] - pre_smaller[i] - 1;
            int curr = heights[i] * width;
            ans = max(ans, curr);
        }
        return ans;
    }
};