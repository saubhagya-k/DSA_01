// Last updated: 05/08/2026, 16:52:30
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
