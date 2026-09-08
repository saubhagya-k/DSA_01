// Last updated: 08/09/2026, 11:33:17
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
