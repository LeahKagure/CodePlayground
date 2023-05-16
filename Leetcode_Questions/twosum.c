/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int *twoSum(int *nums, int numsSize, int target, int *returnSize){
    int *ret_arr = malloc(2*sizeof(int)); //the size of the returned array will be 2
    *returnSize = 2;
    for(int i=0; i<numsSize-1; i++){
        for(int j=i+1; j<numsSize; j++) {
            if(nums[i] + nums[j] == target){
                ret_arr[0] = i;
                ret_arr[1] = j;
                return ret_arr;
            }
        }
    }
    return ret_arr;
}