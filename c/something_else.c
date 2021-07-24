#include <stdio.h>

void transform_string(char string[]) {
  if (string[0] >= 65 && string[0] <= 90) {
    string[0] += 32; 
  }
}

int main() {
  char name[] = "Daivat";
  transform_string(name);
  printf("string now is %s\n", name);
  return 0;
}
