class Solution {
public:
    /* start aur end point ki heights kai sath array banao -num to represent start + for end
-ve hai toh maxi set mai add karo end hai toh hata do abh agar maximum height change hui hai toh new point banega mtlb*/

vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> result;
    vector<pair<int,int>> heights;
    // Create critical points for each building
    for(auto b : buildings){
        heights.push_back({b[0], -b[2]}); // Start of building with negative height
        heights.push_back({b[1], b[2]});  // End of building with actual height
    }
    // Sort critical points based on x-coordinate
    sort(heights.begin(), heights.end());
    
    multiset<int> mp;
    int previous = 0, curr = 0;
    mp.insert(0); // Insert ground level initially
    // Iterate through critical points
    for(auto h : heights){
        if(h.second < 0){
            // If it's a start point, insert the negative height
            mp.insert(-h.second);
        }
        else{
            // If it's an end point, erase the corresponding height
            mp.erase(mp.find(h.second));
        }
        // Get the maximum height encountered so far
        curr = *mp.rbegin();
        // If the maximum height changes, add the critical point to the result
        if(curr != previous){
            result.push_back({h.first, curr});
            previous = curr;
        }
    }
    return result;
}
};