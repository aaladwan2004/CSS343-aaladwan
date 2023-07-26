//Refrecned Rikam

class Solution {
public:
    // check if word exists in the board
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        if (word.empty()) return true;

        this->word = word; // stores word to search for

        // Check each cell in the board for the first letter of the word
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (DFS(i, j, 0, board)) return true;
                }
            }
        }

        return false; // Return false if the word is not found.
    }

private:
    string word; 

    // DFS from (i, j) to search for the word
    bool DFS(int i, int j, int idx, vector<vector<char>>& board) {
        // Base case: If the entire word is found, return true.
        if (idx == word.length()) return true;

        // Check if (i, j) is out of bounds or if it doesnt match the current letter in the word
        if (i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] != word[idx]) {
            return false;
        }

        char currChar = board[i][j];
        board[i][j] = ' '; // Mark the cell as visited

        // check surounding cells to find the next character in the word
        bool found = DFS(i - 1, j, idx + 1, board) ||
                     DFS(i, j - 1, idx + 1, board) ||
                     DFS(i + 1, j, idx + 1, board) ||
                     DFS(i, j + 1, idx + 1, board);

        board[i][j] = currChar; 
        return found; // Return true if the word is found
    }
};
