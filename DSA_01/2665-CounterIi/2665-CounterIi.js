// Last updated: 08/09/2026, 11:33:27
function createCounter(init) {
    // Store the working value of the counter
    let currentValue = init;

    return {
        // Increases the value by 1 and returns it
        increment: function() {
            currentValue += 1;
            return currentValue;
        },
        // Reduces the value by 1 and returns it
        decrement: function() {
            currentValue -= 1;
            return currentValue;
        },
        // Resets the value back to the original init and returns it
        reset: function() {
            currentValue = init;
            return currentValue;
        }
    };
}
