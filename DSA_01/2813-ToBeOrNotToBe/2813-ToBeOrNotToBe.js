// Last updated: 05/08/2026, 16:52:23
/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        // Checks if values are strictly equal
        toBe: function(expected) {
            if (val === expected) {
                return true;
            }
            throw new Error("Not Equal");
        },
        
        // Checks if values are strictly not equal
        notToBe: function(expected) {
            if (val !== expected) {
                return true;
            }
            throw new Error("Equal");
        }
    };
};
