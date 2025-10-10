#include <stdio.h>
#include <cs50.h>

// Function to calculate the length of the number
typedef unsigned long long ull;

int get_length(ull number) {
    int length = 0;
    while (number > 0) {
        number /= 10;
        length++;
    }
    return length;
}

// Function to implement Luhn's Algorithm
bool luhn_check(ull number) {
    int sum = 0; // This will hold the total sum for Luhn's algorithm
    bool alternate = false; // This keeps track of whether to double the digit
    while (number > 0) {
        // Extract the last digit without using %
        int digit = number - (number / 10) * 10;
        if (alternate) {
            // Double the digit
            int doubled = digit * 2;
            // If doubled is two digits, add both digits separately
            if (doubled >= 10) {
                int first_digit = doubled / 10; // Get the tens place
                int second_digit = doubled - (first_digit * 10); // Get the ones place
                sum = sum + first_digit;
                sum = sum + second_digit;
            } else {
                sum = sum + doubled;
            }
        } else {
            // Just add the digit
            sum = sum + digit;
        }
        alternate = !alternate; // Switch between alternate and not
        number = number / 10; // Remove the last digit
    }
    // Check if the last digit of sum is 0 (valid card)
    int last_digit = sum - (sum / 10) * 10;
    if (last_digit == 0) {
        return true;
    } else {
        return false;
    }
}

int main(void) {
    ull number = get_long("Number: ");
    int length = get_length(number);

    // Get starting digits
    ull start = number;
    while (start >= 100) {
        start /= 10;
    }
    ull first = start / 10;
    ull second = start % 10;

    if (luhn_check(number)) {
        if (length == 15 && (start == 34 || start == 37)) {
            printf("AMEX\n");
            return 0;
        } else if (length == 16 && (start >= 51 && start <= 55)) {
            printf("MASTERCARD\n");
            return 0;
        } else if ((length == 13 || length == 16) && first == 4) {
            printf("VISA\n");
            return 0;
        }
    }
    printf("INVALID\n");
    return 0;
}

// Test with card # 4003600000000014
// Test with card # 378282246310005
// Test with card # 371449635398431
// Test with card # 5555555555554444
// Test with card # 5105105105105100
// Test with card # 4111111111111111