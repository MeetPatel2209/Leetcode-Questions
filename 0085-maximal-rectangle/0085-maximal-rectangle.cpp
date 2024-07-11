class Solution {
public:
    int largestRectangleArea(vector < int > & histo) {
      stack < int > st;
      int maxA = 0;
      int n = histo.size();
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> row(m);
        for(int i=0;i<m;i++) {
            row[i] = matrix[0][i]-'0';
        }
        int maxA = largestRectangleArea(row);
        for(int i=1;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(matrix[i][j] == '0') row[j] = 0;
                else row[j] += matrix[i][j]-'0';
            }
            maxA = max(maxA,largestRectangleArea(row));
        }
        return maxA;
    }
};