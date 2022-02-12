/*	
	Category: 2017 Contest
	Task name: SocksLaundering
	Description: From drawers containing both clean and dirty socks, choose socks to launder in order to obtain the maximum number of clean pairs of socks.
	Difficulty: Medium
	Link: https://app.codility.com/programmers/trainings/3/socks_laundering/
	
	Solution time complexity: Not assessed (but it's O(N+M))
	Score: 100%
	Correctness: 100%
	Performance: Not assessed
*/

#include <vector>
#include <utility>
#define MAX_COLOR 50

int solution(int K, vector<int> &C, vector<int> &D) {
    vector<pair<int, int>> socksByColor (MAX_COLOR+1, pair<int, int>(0, 0));
    for (size_t i = 0; i < C.size(); i++){
        socksByColor[C[i]].first++;
    }
    for (size_t i = 0; i < D.size(); i++){
        socksByColor[D[i]].second++;
    }
    
    int cleanPairs = 0, halfPairs = 0, dirtyPairs = 0;
    for (size_t i = 0; i < MAX_COLOR+1; i++){
        cleanPairs += socksByColor[i].first / 2;
        if (socksByColor[i].first % 2 == 1 && socksByColor[i].second > 0){
            halfPairs++;
            socksByColor[i].second -= 1;
        }
        dirtyPairs += socksByColor[i].second / 2;
    }
    
    int sol = cleanPairs;
    if (halfPairs <= K){
        sol += halfPairs;
        K -= halfPairs;
        if (dirtyPairs * 2 <= K){
            sol += dirtyPairs;
        } else {
            sol += K / 2;
        }
    } else {
        sol += K;
    }
    return sol;
}