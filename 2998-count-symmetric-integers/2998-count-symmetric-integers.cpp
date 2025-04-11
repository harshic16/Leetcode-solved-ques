class Solution {
public:
    // Function to count the symmetric integers between `low` and `high`.
    int countSymmetricIntegers(int low, int high) {
        // Initialize the answer counter.
        int count = 0;
        // Define the lambda function to check if an integer is symmetric.
        auto isSymmetric = [](int num) {
            // Convert the number to a string.
            string numStr = to_string(num);
            // Get the number of digits in the string.
            int length = numStr.size();
            // Check if the number of digits is odd. If it is, return 0 immediately.
            if (length % 2 == 1) {
                return 0;
            }
            // Initialize the sums of the first half and second half of the digits.
            int sumFirstHalf = 0, sumSecondHalf = 0;
            // Iterate over the first half and second half digits and sum them up.
            for (int i = 0; i < length / 2; ++i) {
                sumFirstHalf += numStr[i] - '0';
                sumSecondHalf += numStr[length / 2 + i] - '0';
            }
            // Return 1 if the sums are equal, else return 0.
            return sumFirstHalf == sumSecondHalf ? 1 : 0;
        };
        // Iterate over the range of numbers from `low` to `high`.
        for (int num = low; num <= high; ++num) {
            // Increase the counter if the current number is symmetric.
            count += isSymmetric(num);
        }
        // Return the final count of symmetric integers.
        return count;
    }
};