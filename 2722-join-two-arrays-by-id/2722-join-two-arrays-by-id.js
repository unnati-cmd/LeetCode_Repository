/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const mp = new Map();
    for(let obj of arr1){
        mp.set(obj.id, obj);
    }
    for(let obj of arr2){
        if(mp.has(obj.id)){
            mp.set(
                obj.id,
                {
                    ...mp.get(obj.id),
                    ...obj
                }
            );
        }
        else{
            mp.set(obj.id, obj);
        }
    }
    return Array.from(mp.values())
        .sort((a,b) => a.id - b.id);
};