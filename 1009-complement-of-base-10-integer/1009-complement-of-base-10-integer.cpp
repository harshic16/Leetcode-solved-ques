class Solution {
public:
    int bitwiseComplement(int n) {
        // Special case: complement of 0 is 1
        if (n == 0) {
            return 1;
        }
      
        int result = 0;
        int bitPosition = 0;
      
        // Process each bit of n from right to left
        while (n != 0) {
            // Get the least significant bit, flip it (XOR with 1),
            // shift it to the correct position, and add to result
            int flippedBit = (n & 1) ^ 1;
            result |= flippedBit << bitPosition;
          
            // Move to the next bit position
            bitPosition++;
          
            // Right shift n to process the next bit
            n >>= 1;
        }
      
        return result;
    }
};
