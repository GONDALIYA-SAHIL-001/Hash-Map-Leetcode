class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& b) {

        for (int i = 0; i < 9; i++) {
            vector<int> v1(9, 1);
            for (int j = 0; j < 9; j++) {
                if (b[i][j] != '.') {
                    int k = (b[i][j] - '0');
                    v1[k - 1] -= 1;
                    if (v1[k - 1] < 0)
                        return false;
                }
            }
        }

        for (int j = 0; j < 9; j++) {
            vector<int> v2(9, 1);
            for (int i = 0; i < 9; i++) {
                if (b[i][j] != '.') {
                    int k = b[i][j] - '0';
                    v2[k - 1] -= 1;
                    if (v2[k - 1] < 0)
                        return false;
                }
            }
        }
    
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<int> v3(9, 1);
                for (int i1 = 0; i1 < 3; i1++) {
                    for (int j1 = 0; j1 < 3; j1++) {
                        if (b[i + i1][j + j1] != '.') {
                            int k = b[i + i1][j + j1] - '0';
                            v3[k - 1] -= 1;
                            if (v3[k - 1] < 0)
                                return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
