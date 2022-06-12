class Solution {
public:
   void setZeroes(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        bool isZeroCol = false;
        bool isZeroRow = false;
       
        int column = matrix.size();
        int row = matrix[0].size();
       
        for (int i = 0; i < column; i++) {
            if (matrix[i][0] == 0) {
                isZeroCol = true;
                break;
            } 
        }
       
        for (int i = 0; i < row; i++) { 
            if (matrix[0][i] == 0) {
                isZeroRow = true;
                break;
            } 
        }
       
        for (int i = 1; i < column; i++) { 
            for (int j = 1; j < row; j++) 
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
       
        for (int i = 1; i < column; i++) { 
           for (int j = 1; j < row; j++) 
               if (matrix[i][0] == 0 || matrix[0][j] == 0)
                   matrix[i][j] = 0;
        }
       
        if (isZeroCol) {                          
            for (int i = 0; i < column; i++) 
                matrix[i][0] = 0;
        }
       
        if (isZeroRow) {                        
            for (int i = 0; i < row; i++) 
                matrix[0][i] = 0;
        }
   }
};