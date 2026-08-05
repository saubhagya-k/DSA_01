// Last updated: 05/08/2026, 16:52:25
/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        return "Hello World"
        
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */