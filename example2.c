// stuffing more data into buffer than it can handle
// buffer[] is much smaller than *str.  buffer[] is 16 bytes long, 
// and we are trying to stuff it with 256 bytes.

void function(char *str) {
   char buffer[16];

   strcpy(buffer,str);
}

void main() {
  char large_string[256];
  int i;

  for( i = 0; i < 255; i++)
    large_string[i] = 'A';

  function(large_string);
}