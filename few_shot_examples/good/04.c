int main() {
  int *p = malloc(sizeof(int));
  if (p) *p = 10;
  free(p);
}