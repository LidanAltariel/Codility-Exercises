/*	
	Category: Data Structures
	Task name: CountriesCount
	Description: Count the number of different countries that a map contains.
	Difficulty: Hard
	Link: https://app.codility.com/programmers/trainings/7/countries_count/
	
	Solution time complexity: O(N*M)
	Score: 100%
	Correctness: 100%
	Performance: 100%
*/

struct DisjointSet {
    vector<int> parent;
    vector<int> size;
    int groupsNum;

    DisjointSet(int maxSize) {
        parent.resize(maxSize);
        size.resize(maxSize);
        groupsNum = maxSize;
        for (int i = 0; i < maxSize; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            groupsNum--;
        }
    }
};

int solution(vector< vector<int> > &A) {
    int rowsNum = A.size();
    int colsNum = A[0].size();
    DisjointSet Countries(rowsNum * colsNum);
    for (int i = 0; i < rowsNum; i++){
        for(int j = 0; j < colsNum; j++){
            if (i > 0 && A[i][j] == A[i-1][j]){
                int x = (i * colsNum) + j;
                int y = ((i-1) * colsNum) + j;
                Countries.union_set(x, y);
            }
            if (j > 0 && A[i][j] == A[i][j-1]){
                int x = (i * colsNum) + j;
                int y = (i * colsNum) + (j-1);
                Countries.union_set(x, y);
            }
        }
    }
    return Countries.groupsNum;
}