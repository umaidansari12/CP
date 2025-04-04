class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        long long int A = 0, B = 0;
        int _size = player1.size();
        for (int i = 0; i < _size; i++) {
            int score1 = player1[i];
            int score2 = player2[i];
            if (i - 1 >= 0) {
                if (player1[i - 1] == 10) {
                    score1 = 2 * player1[i];
                }
                if (player2[i - 1] == 10) {
                    score2 = 2 * player2[i];
                }
            }
            if (i - 2 >= 0) {
                if (player1[i - 2] == 10) {
                    score1 = 2 * player1[i];
                }
                if (player2[i - 2] == 10) {
                    score2 = 2 * player2[i];
                }
            }
            A += score1;
            B += score2;
        }
        if (A > B)
            return 1;
        else if (B > A)
            return 2;
        return 0;
    }
};