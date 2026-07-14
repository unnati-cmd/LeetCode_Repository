/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function(arr, n) {

    let result = [];

    function dfs(arr, depth) {

        for(let item of arr) {

            if(Array.isArray(item) && depth < n) {
                dfs(item, depth + 1);
            }
            else {
                result.push(item);
            }
        }
    }

    dfs(arr, 0);

    return result;
};