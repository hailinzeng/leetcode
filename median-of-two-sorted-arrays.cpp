class Solution {
public:
    // 0 ~ (m + n -1)
    // odd : (m + n -1) / 2
    // even: (m + n -1) / 2 , (m + n - 1)/2 + 1
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int mergeIdx = 0;
        int median = 0;
        
        int idxA = 0;
        int idxB = 0;
        while(mergeIdx <= (m + n -1)/2){
            if(idxA < m && idxB < n){
                if(A[idxA] < B[idxB]){
                    median = A[idxA++];
                }else{
                    median = B[idxB++];
                }
            }else if(idxA < m){
                median = A[idxA++];
            }else{
                median = B[idxB++];
            }
            mergeIdx ++;
        }
        
        if((m + n) % 2){
            return median;
        }else{
            int next = 0;
            
            if(idxA < m && idxB < n){
                if(A[idxA] < B[idxB]){
                    next = A[idxA++];
                }else{
                    next = B[idxB++];
                }
            }else if(idxA < m){
                next = A[idxA++];
            }else{
                next = B[idxB++];
            }
            
            return ((double)median + next) / 2;
        }
    }
};
