class Solution {
public:
    
    bool checkRow(vector<string> board,int i,int col) {
        int dr = i;
        int dc = col;
        while(dr>=0 && dc>=0) {
            if(board[dr][dc] == 'Q') return false;
            dr--;
            dc--;
        }
        dr = i;
        dc = col;
        while(dc>=0) {
            if(board[dr][dc] == 'Q') return false;
            dc--;
        }
        dr = i;
        dc = col;
        while(dr<board.size() && dc>=0) {
            if(board[dr][dc] == 'Q') return false;
            dr++;
            dc--;
        }
        return true;
    }
    
    void check(vector<vector<string>> &res,vector<string> board,int col,int n) {
        if(col == n) {
            res.push_back(board);
            return;
        }
        for(int i=0;i<n;i++) {
            if(checkRow(board,i,col)) {
                board[i][col] = 'Q';
                check(res,board,col+1,n);
                board[i][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) {
            board[i] = s;
        }
        check(res,board,0,n);
        return res;
    }
};