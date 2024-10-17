class Solution {
public:
    int solve(int i, int arrows, vector<int>& aliceArrows, vector<int>& ans, vector<int>& bestAns, int &maxPoints) {
        // Base case: no more sections or no more arrows
        if (i >= 12 || arrows == 0) {
            // Calculate current points
            int currentPoints = 0;
            for (int j = 0; j < 12; j++) {
                if (ans[j] > aliceArrows[j]) {
                    currentPoints += j;
                }
            }
            // If current points are greater, update the bestAns
            if (currentPoints > maxPoints) {
                maxPoints = currentPoints;
                bestAns = ans; // store the best configuration of arrows
            }
            return currentPoints;
        }

        // Case 1: Exclude this section (Bob doesn't shoot here)
        int exclude = solve(i + 1, arrows, aliceArrows, ans, bestAns, maxPoints);

        int include = 0;
        if (arrows > aliceArrows[i]) { // Bob needs to shoot more arrows than Alice to win this section
            ans[i] = aliceArrows[i] + 1; // Bob shoots 1 more than Alice in section i
            include = i + solve(i + 1, arrows - (aliceArrows[i] + 1), aliceArrows, ans, bestAns, maxPoints);
            ans[i] = 0; 
        }

        // Return the maximum of include and exclude
        return max(include, exclude);
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> ans(12, 0);       // Current allocation of Bob's arrows
        vector<int> bestAns(12, 0);   // Best allocation found
        int maxPoints = 0;            // Max points Bob can earn
        solve(0, numArrows, aliceArrows, ans, bestAns, maxPoints);

        // Adjust the arrows to exactly match numArrows (if needed)
        int sumArrows = 0;
        for (int i = 0; i < 12; i++) {
            sumArrows += bestAns[i];
        }

        // If we have extra arrows left, assign them arbitrarily to any section
        if (sumArrows < numArrows) {
            bestAns[0] += (numArrows - sumArrows); // Add the remaining arrows to section 0
        }

        return bestAns; // Return the best configuration of arrows Bob used
    }
};
