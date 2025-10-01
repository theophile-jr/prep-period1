// #include <stdio.h>
// int main()
// {
//     struct emp
//     {
//         char name[20];
//         float sal;
//     };
//     struct emp e[10];
//     int i;
//     for (i = 0; i <= 9; i++)
//         scanf("%s %f", e[i].name, &e[i].sal);
//     return 0;
// }
// #include <stdio.h>

// long fun(int num)
// {
//     int i;
//     long f = 1;
//     for (i = 1; i <= num; i++)
//         f = f * i;
//     return f;
// }

// int main () {
//     printf("%d",fun(5));
// }

// #include <stdio.h>
// int main()
// {
//     float a = 3.14;
//     char *j;
//     j = (char *)&a;
//     printf("%d\n", *j);
//     return 0;
// }
// #include <stdio.h>
// int main () {
//     int a = 3;
//     int *b = &a;
//     b++; // fucks the pointer
//     printf("%d", *b);
// }
// #include <stdio.h>
// int main()
// {
//     int a = 10, *j;
//     void *k;
//     j = k = &a;
//     j++;
//     k++;
//     printf("%u %u\n", j, k);
//     return 0;
// }

// #include <stdio.h>

// int main()
// {
//     char ch = 'A';

//     // Prints the size of:
//     // 1. ch (char, 1 byte)
//     // 2. 'A' (char constant promoted to int, 4 bytes)
//     // 3. 3.14f (float constant due to 'f' suffix, 4 bytes)
//     printf("%d, %d, %d", sizeof(ch), sizeof('A'), sizeof(3.14f)); //'' = treated as int
//     // 1,4,4
//     return 0;
// }

// #include <stdio.h>
// int main()
// {
//     char str[] = "Nagpur";
//     str[0] = 'K'; // works because return lvalue
//     printf("%s, ", str);
//     str = "Kanpur"; //cant excepted at declaration.
//     printf("%s", str + 1);
//     // return 0;
// }

int main()
{
    int A = 2;
    int B = 4;
    int C = 8;
    int *P1, *P2, *P3;
    P1 = &A;
    P2 = &C;
    P3 = P1++;
    *P1 = (*P2)++;
    P1 = P2;
    P2 = &B;
    *P1-- = *P3;
    ++*P2;
    *P3 *= *P2;
    A = ++*P2 * *P1;
    P1 = &A;
    *P2 = *P1 /= *P2;
    return 0;
}