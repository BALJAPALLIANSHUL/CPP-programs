int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0,r = n-1;
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            while(height[r]<height[i] && r!=i){
                r--;
            }
            while(height[l]<height[i] && l!=i){
                l++;
            }
            ans = max(ans,max(height[i]*(i-l),height[i]*(r-i)));
            l = 0;r=n-1;
        }
        return ans;
    }