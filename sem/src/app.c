#include <math.h>
#include <unistd.h>
#include "count.h"

#define NFILES 5
#define LENNAME 50

char files[NFILES][LENNAME] = { "src/app.c", "src/mycheck.c", "src/count.c", "inc/count.h", "inc/mycheck.h" };

int main()
{
    setbuf(stdout, NULL);

    int all = count("tests.c");

    fprintf(stdout, "In the specified files %d words\n", all);

    return 0;
}

// int main(int argc, char **argv)
// {
//     setbuf(stdout, NULL);
//     int all;
   
//     if (argc == 1)
//     {
//         fprintf(stdout, "Don't specify any file\n");
//         return ERROR;
//     }

//     switch (argc)
//     {
//         case 2:
//             all = count(argv[1]);
//             break;
//         case 3:
//             all = count(argv[1], argv[2]);
//             break;
//         case 4:
//             all = count(argv[1], argv[2], argv[3]);
//             break;
//         case 5:
//             all = count(argv[1], argv[2], argv[3], argv[4]);
//             break;
//         case 6:
//             all = count(argv[1], argv[2], argv[3], argv[4], argv[5]);
//             break;
//         case 7:
//             all = count(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6]);
//             break;
//         case 8:
//             all = count(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
//             break;
//         case 9:
//             all = count(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
//             break;
//         case 10:
//             all = count(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9]);
//             break;
//         case 11:
//             all = count(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10]);
//             break;
//         case 12:
//             all = count(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8], argv[9], argv[10], argv[11]);
//             break;
//         default:
//             break;
//     }

//     fprintf(stdout, "In the specified files %d words\n", all);

//     return 0;
// }