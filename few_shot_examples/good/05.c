int main() {
  char buf[8];
  strncpy(buf, "this is too long", sizeof(buf) - 1);
  buf[sizeof(buf) - 1] = '\0';
}