class Solution {
public:
    bool check(string word,vector<vector<char>>& board,int i,int j,int index) {
        if(index == word.size()) return true;
        if(i<0 || j < 0 || i>=board.size() || j >=board[0].size() || board[i][j] == '0' || board[i][j] != word[index]) return false;
        
        char ch = board[i][j];
        board[i][j] = '0';
        
        bool top = check(word,board,i-1,j,index+1);
        bool bottom = check(word,board,i+1,j,index+1);
        bool right = check(word,board,i,j-1,index+1);
        bool left = check(word,board,i,j+1,index+1);
        
        board[i][j] = ch;
        
        return top || bottom || left || right;
        
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == word[0]) {
                    if(check(word,board,i,j,0) == true) return true;
                }
            }
        }
        return false;
    }
};