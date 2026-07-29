/**
 * @param {number[]} nums
 * @param {number} n
 * @return {number[]}
 */
var shuffle = function (nums, n) {
    let start = 0;
    let end = n;
    let arr = [];
    for (let i = 0; i < n; i++) {
        arr.push(nums[start]);
        arr.push(nums[end]);
        start += 1;
        end += 1;
    }
    return arr;

}; 