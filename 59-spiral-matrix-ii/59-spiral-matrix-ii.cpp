class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        int temp = 0;
        int i = 0;
        int j = 0;
        int x = 1;
        while(true){
            if(x > (n*n)){
                break;
            }
            // cout<<i<<" "<<j<<"\n";
            
            ans[i][j]=x;
            x++;

            if(temp==0){
                j++;
                if(j==n || ans[i][j]!=0){
                    j--;
                    i++;
                    temp = 1;
                }
            }
            else if(temp == 1 ){
                i++;
                if(i==n || ans[i][j]!=0){
                    i--;
                    j--;
                    temp = 2;
                }
            }
            else if(temp == 2){
                j--;
                // cout<<"j : "<<j<<" ";
                if(j<0  || ans[i][j]!=0){
                    j++;
                    i--;
                    temp = 3;
                }
                // cout<<j<<"\n";
            }
            else {
                i--;
                if(i<0 || ans[i][j]!=0){
                    i++;
                    j++;
                    temp = 0;
                }
            }
        }
        return ans;
    }
};