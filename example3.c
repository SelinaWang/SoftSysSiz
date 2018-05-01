// executes arbitrary code
// buffer1[] is really 2 word so its 8 bytes long.  So the return 
// address is 12 bytes from the start of buffer1[].
// modify the return value in such a way that the
// assignment statement 'x = 1;' after the function call will be jumped.  To do
// so we add 8 bytes to the return address.

void function(int a, int b, int c) {
   char buffer1[5];
   char buffer2[10];
   int *ret;

   ret = buffer1 + 12;
   (*ret) += 8;
}

void main() {
  int x;

  x = 0;
  function(1,2,3);
  x = 1;
  printf("%d\n",x);
}