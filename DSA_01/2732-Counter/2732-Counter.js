// Last updated: 05/08/2026, 16:52:32
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