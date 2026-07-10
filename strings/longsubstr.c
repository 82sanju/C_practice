#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    int seen[256] = {0};  // ASCII map
    int left = 0, maxLength = 0;

    for (int right = 0; s[right] != '\0'; right++) {

        // If duplicate found → shrink window
        while (seen[s[right]]) {
            seen[s[left]] = 0;
            left++;
        }

        // Add current character
        seen[s[right]] = 1;

        int length = right - left + 1;
        if (length > maxLength) {
            maxLength = length;
        }
    }

    return maxLength;
}
int main() {
    char s[] = "qweqmnbqmnmcdsadkacx";

    int result = lengthOfLongestSubstring(s);
    printf("Long substring length: %d\n", result);

    return 0;
}