class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>result;
        int r=matrix.size();
        int c=matrix[0].size();
        int minr = 0;
        int minc = 0;
        int maxr = r-1;
        int maxc = c-1;
        int tne = r * c;
        int cnt = 0;
        
        while (cnt < tne)
        {
        for (int i = minr, j = minc; j <= maxc && cnt < tne; j++)
        {
            result.push_back(matrix[i][j]);
            cnt++;
        }
        minr++;

        for (int i = minr,  j = maxc; i <= maxr && cnt < tne; i++)
        {
            result.push_back(matrix[i][j]);
            cnt++;
        }
        maxc--;

        for (int i = maxr,  j = maxc; j >= minc && cnt < tne; j--)
        {
            result.push_back(matrix[i][j]);
            cnt++;
        }
        maxr--;

        for (int i = maxr,  j = minc; i >= minr && cnt < tne; i--)
        {
            result.push_back(matrix[i][j]);
            cnt++;
        }
        minc++;
        }
        return result;
    }
};
