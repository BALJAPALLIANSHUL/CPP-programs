class Solution {
    static bool cmp(pair<int, int>& a,
        pair<int, int>& b)
    {
        return a.second > b.second;
    }
vector<pair<int,int>> sort(map<int,int>& M)
{
    vector<pair<int, int> > A;
    for (auto& it : M) {
        A.push_back(it);
    }
    std::sort(A.begin(), A.end(), cmp);
    return A;
}
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n =nums.size();
        map<int,int> map;
        vector<int> v;vector<pair<int, int> > A;
        for(int i = 0;i<n;i++){
            if(map.find(nums[i]) == map.end()){
                map.insert({nums[i],1});
            }
            else{
                map[nums[i]]++;
            }
        }
        A = sort(map);
        for(auto& it:A){
            if(k--){
                v.push_back(it.first);
            }
            else{
                break;
            }
        }
        return v;
    }
};