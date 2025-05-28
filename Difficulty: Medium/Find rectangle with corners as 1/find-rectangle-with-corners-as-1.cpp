class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m;i++) {
            for (int j =0; j < n;j++) {
                if (mat[i][j] == 1) {
                    for (int l = j+1; l < n;l++) {
                        if (mat[i][l] == 1) {
                            for (int lol = i+1;lol<m;lol++) if (mat[lol][j] == 1 && mat[lol][l] == 1) return true;
                            
                            
                            
                        }
                        
                    }
                    
                    
                }
                
                
            }
            
            
            
        }
        return false;
        
        
        
    }
};