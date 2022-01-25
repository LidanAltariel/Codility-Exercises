/*	
	Category: Data Structures
	Task name: TreeLongestZigzag
	Description: Given a tree, find a downward path with the maximal number of direction changes.
	Difficulty: Medium
	Link: https://app.codility.com/programmers/trainings/7/tree_longest_zig_zag/
	
	Solution time complexity: O(N)
	Score: 100%
	Correctness: 100%
	Performance: 100%
*/

int solution_aux(tree * T, bool isRightSon, int counter) {
    int rightCounter = (isRightSon) ? counter : counter + 1;
    int leftCounter = (isRightSon) ? counter + 1 : counter;
    int rightSol = (T->r != NULL) ? solution_aux(T->r, true, rightCounter) : counter;
    int leftSol = (T->l != NULL) ? solution_aux(T->l, false, leftCounter) : counter;
    return max(rightSol, leftSol);
}

int solution(tree * T) {
    if (T == NULL) return 0;
    int rightSol = (T->r != NULL) ? solution_aux(T->r, true, 0) : 0;
    int leftSol = (T->l != NULL) ? solution_aux(T->l, false, 0) : 0;
    return max(rightSol, leftSol);
}