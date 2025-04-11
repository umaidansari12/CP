int solution(vector<vector<int>> matrix) {
    int n = matrix.size(), m = matrix[0].size(), ans = 0;
    // pick row and then pick column
    for(int i=0;i<n;i++){
        // unordered_map<int, int> hash;
        // ith row picked
        // bool regular = true;
        // int element = matrix[i][0]; 
        // int intersection = 0;
        for(int k=0;k<m;k++){
            bool regular = true;
            int element = matrix[0][k]; 
            int intersection = 0;
            for(int l=0; l<n;l++){
                if(matrix[l][k] != element and l!=i)
                    regular = false;
            // element = matrix[i][0];
            if(matrix[i][k]!=element)
                regular = false;
            if(regular)
                ans++;
        }
                
                
        //         // temp_hash[matrix[l][k]]++;
        //     // cout << k << "col picked" << temp_hash.size()<<endl;
        //     // if(hash.size() + temp_hash.size() <=2)
        //         // ans++;
        }
        // for(int j=1;j<m;j++){
            // row picking -> (i, j)
            // col picking -> (j, i)
            // hash[matrix[i][j]]++;
            // if(matrix[i][j] != element){
                // regular = false;
            // }
        // }
        // intersection of row and column can change only
        // cout << i <<"row picked" << hash.size()<<endl;
        // kth column picking
        // for(int k=0;k<m;k++){
        //     // k-> 0 -> m
        //     // k will remain constant
        //     // unordered_map<int,int> temp_hash;
        //     // for(int l=0; l<n;l++)
        //         // temp_hash[matrix[l][k]]++;
        //     // cout << k << "col picked" << temp_hash.size()<<endl;
        //     // if(hash.size() + temp_hash.size() <=2)
        //         // ans++;
        // }
    }
    return ans;
}


