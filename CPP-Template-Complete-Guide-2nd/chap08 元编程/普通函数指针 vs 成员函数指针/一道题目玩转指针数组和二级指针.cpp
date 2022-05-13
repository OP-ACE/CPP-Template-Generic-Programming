#include <stdio.h>

int explain(){

    char *string0 = "COS1283/1284";
    char *string1 = "Programming";
    char *string2 =     "Techniques";
    char *string3 =     "is";
    char *string4 =     "great fun";

    char * lines[5];
    lines[0] = string0;
    lines[1] = string1;
    lines[2] = string2;
    lines[3] = string3;
    lines[4] = string4;

    char *str1 = lines[1];
    char *str2 = *(lines + 3);
    char c1    = *(*(lines + 4) + 6);
    char c2    = *(lines + 5)[5];
    char c3    = *lines[0] + 2;

    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("  c1 = %c\n", c1  );
    printf("  c2 = %c\n", c2  );
    printf("  c3 = %c\n", c3  );

    return 0;
}

int main()
{
    char* lines [5] = {
        "COS1283/1284",
        "Programming"
        "Techniques",
        "is",
        "great fun"
    };

    char * str1 = lines[1];
    char * str2 = *lines[+3];
    char c1 = *(*(lines + 4) + 6);
    char c2 = (*lines + 5)[5];
    char c3 = *lines[0] + 2;

    printf("str1 = %s\n", str1);
    printf("str2 = %s\n", str2);
    printf("  c1 = %c\n", c1  );
    printf("  c2 = %c\n", c2  );
    printf("  c3 = %c\n", c3  );

    return 0;

}