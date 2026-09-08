// Last updated: 08/09/2026, 11:33:26
/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {

     

   
    
    return function() {

        return n++;
       
        
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */