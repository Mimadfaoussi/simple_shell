/**
 * This function computes the Least Common Multiple (LCM) of three numbers.
 *
 * @param {number} num1 - The first number.
 * @param {number} num2 - The second number.
 * @param {number} num3 - The third number.
 * @returns {number} The LCM of the three numbers.
 */
function computeLCM(num1, num2, num3)
{
    // Find the maximum number among the three
    let maxNum = Math.max(num1, num2, num3);

    // Start with the maximum number and check if it is divisible by all three numbers
    for (let lcm = maxNum;; lcm += maxNum)
    {
        if (lcm % num1 == = 0 &&lcm % num2 == = 0 &&lcm % num3 == = 0)
        {
            return lcm;
        }
    }
}

/**
 * This function evaluates a polynomial for a given value of x.
 *
 * @param {number} a - Coefficient for x^2.
 * @param {number} b - Coefficient for x.
 * @param {number} c - Constant coefficient.
 * @param {number} x - The value for which the polynomial should be evaluated.
 * @returns {number} The result of the polynomial evaluation.
 */
function evaluatePolynomial(a, b, c, x)
{
    return a * x * x + b * x + c;
}

// Usage Examples

// Example 1: Computing LCM
const lcm = computeLCM(2, 4, 6);
console.log(`The LCM of 2, 4, and6 is : $ { lcm }`);

// Example 2: Evaluating Polynomial
const result = evaluatePolynomial(1, 2, 3, 2);
console.log(`The polynomial evaluates to ${result} when x = 2`);