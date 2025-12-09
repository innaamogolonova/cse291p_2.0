#include <stdlib.h>
int main() {
  int *p = malloc(sizeof(int));
  *p = 5;
  free(p);
  p = NULL;
}