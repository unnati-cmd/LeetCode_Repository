var ArrayWrapper = function(nums) {
    this.nums = nums;
};

ArrayWrapper.prototype.valueOf = function() {

    let sum = 0;

    for(let num of this.nums) {
        sum += num;
    }

    return sum;
};

ArrayWrapper.prototype.toString = function() {

    return "[" + this.nums.toString() + "]";
};