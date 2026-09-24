#include <stdio.h>

int convert(int x, int s, int t) {
    if (s < 2 || s > 10 || t < 2 || t > 10) {
        printf("Cannot convert.\n");
        return -1;
    }
    
    else {

      int current_number = x;
      int decimal = 0;
      int power = 1;

      while (current_number > 0) {
          int digit;
          digit = current_number % 10;
        
          if (digit >= s) {
            printf("cannot convert.\n");
            return -1;
          }
          
          decimal = decimal + (digit * power);
          power = power * s;
          current_number = current_number / 10;
      }

      int result = 0;
      int radix = 1;

      while (decimal > 0) {
        int remainder = decimal % t;
        result = result + (remainder * radix);
        radix = radix * 10;
        decimal = decimal / t;
      }

      return result;
}
}
int main() {
    printf("%d",convert(1234, 8, 2)); 
    return 0;
}
