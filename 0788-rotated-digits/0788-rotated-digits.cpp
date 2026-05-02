class Solution {
public:
    int rotatedDigits(int n) {
        // Mapping array: index represents original digit, value represents rotated digit
        // -1 means the digit cannot be rotated (3, 4, 7)
        // 0->0, 1->1, 2->5, 5->2, 6->9, 8->8, 9->6
        int digitMapping[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
      
        // Lambda function to check if a number is "good" after rotation
        auto isGoodNumber = [&](int number) -> bool {
            int rotatedNumber = 0;  // Store the rotated number
            int originalNumber = number;  // Keep a copy of the original number
            int placeValue = 1;  // Track the place value (1, 10, 100, ...)
          
            // Process each digit from right to left
            while (originalNumber > 0) {
                int currentDigit = originalNumber % 10;
              
                // If current digit cannot be rotated, the number is not valid
                if (digitMapping[currentDigit] == -1) {
                    return false;
                }
              
                // Build the rotated number digit by digit
                rotatedNumber = digitMapping[currentDigit] * placeValue + rotatedNumber;
                placeValue *= 10;
                originalNumber /= 10;
            }
          
            // A good number must be different after rotation
            return number != rotatedNumber;
        };
      
        // Count all good numbers from 1 to n
        int goodNumberCount = 0;
        for (int i = 1; i <= n; ++i) {
            if (isGoodNumber(i)) {
                goodNumberCount++;
            }
        }
      
        return goodNumberCount;
    }
};
