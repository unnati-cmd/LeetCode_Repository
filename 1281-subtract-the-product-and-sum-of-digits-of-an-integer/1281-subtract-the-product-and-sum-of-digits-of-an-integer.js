/**
 * @param {number} n
 * @return {number}
 */
var subtractProductAndSum = function(n) {
    let sum=0;
    let product=1;
    while(n!==0){
        let temp=n%10;
        sum+=temp;
        product*=temp;
        n= Math.floor(n/10);
    }

    return product-sum;
};