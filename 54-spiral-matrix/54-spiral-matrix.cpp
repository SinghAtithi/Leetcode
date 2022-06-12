class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        
        int row = mat.size();
        int col = mat[0].size();
        int dir = 0;
        int i =  0, j = 0, left = row * col;
        vector<int>ans;
        
        while(left--){
            ans.push_back(mat[i][j]);
            mat[i][j] = -111;
            if(dir == 0){
                j++;
                if(j >= col || mat[i][j] == -111){
                    j--;
                    i++;
                    dir = 1;
                }
            }
            else if(dir == 1){
                i++;
                if(i >= row || mat[i][j] == -111){
                    i--;
                    j--;
                    dir = 2;
                }
            }
            else if(dir == 2){
                j--;
                if(j <0  || mat[i][j] == -111){
                    i--;
                    j++;
                    dir = 3;
                }
            }
            else{
                i--;
                if(i <0  || mat[i][j] == -111){
                    i++;
                    j++;
                    dir = 0;
                }
            }
        }
        return ans;
    }
};