#include <stdio.h>
int main() {
printf ("0. %c\n", 'a'); // char a
printf ("1. %c\n", 65); // char 65 = A on the ascii table 
printf ("2. %d\n", 100); // 100 decimal
printf ("3. %x\n", 100); // 100 decimal into hexadecimal 
printf ("4. %o\n", 100); // 100 decimal to octal
printf ("5. %#x\n", 100); // 100 DECIMAL into hexadecimal with 0x (# = use the form)
printf ("6. %#o\n", 100); // 100 decimal as octal with the prefix 0
printf ("7. %6.2f \n", 3.1416); // width of 6, 2 decimals (auto spaces on the left)
printf ("8. %6.2f \n", 31.416); // the same
printf ("9. %E \n", 3.1416); // scientific Notation
printf ("10. %*d \n", 5, 10); // dynamic width : 5
return 0;
}
