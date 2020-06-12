/**
*   Return the second largest number in the array.
*   @param {Number[]} nums - An array of numbers.
*   @return {Number} The second largest number in the array.
**/
function getSecondLargest(nums) {
    // Complete the function
    var max = nums[0], max2 = nums[0];
    for (let i of nums){
        if (i > max){
            max2 = max;
            max = i;
        }
        else if (i > max2 && i != max){
            max2 = i;
        }
    }
    return max2;
}