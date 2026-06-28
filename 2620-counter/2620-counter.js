/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    var l = 0;
    return function() {
        if(l) n+=1;
        l+=1;
        return n;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */