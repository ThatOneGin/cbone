extern void foo(void);
extern void bar(void);

void foobar(void) {
  foo();
  bar();
}

int main(void) {
  foobar();
  return 0;
}
