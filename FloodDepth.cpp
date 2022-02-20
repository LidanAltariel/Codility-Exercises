/*	
	Category: 2015 Contest
	Task name: FloodDepth
	Description: Find the maximum depth of water in mountains after a huge rainfall.
	Difficulty: Medium
	Link: https://app.codility.com/programmers/trainings/1/flood_depth/
	
	Solution time complexity: O(N)
	Score: 100%
	Correctness: 100%
	Performance: 100%
*/

#include <bits/stdc++.h>

int solution(vector<int> &A) {
    int maxDepth = 0;
    int curOpen = 1;
    int curMin = INT_MAX;
    int prev = 0;
    for (size_t i = 0; i < A.size(); i++){
        int cur = A[i];
        curMin = cur < curMin ? cur : curMin;
        if (cur > prev){
            int depth = min(cur, curOpen) - curMin;
            maxDepth = depth > maxDepth ? depth : maxDepth;
            if (cur >= curOpen){
                curOpen = cur;
                curMin = INT_MAX;
            }
        }
    }
    return maxDepth;
}