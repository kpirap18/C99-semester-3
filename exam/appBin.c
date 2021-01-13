
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

// int pppp(int a, int p)
// {
//     int res = 1;
//     for (int i = 0 ; i < p; i++)
//     {
//         res = res * a;
//     }
//     return res;
// }

// // BY ALENA
// void print_in2_uc(unsigned char x)
// {
//     printf("uc: ");
//     unsigned char mask = 0x01 << 7;
//     while (mask)
//     {
//         printf("%d", (x & mask) == mask);
//         mask >>= 1;
//     }
//     printf("\n");
// }

// void print_in2_ui(unsigned int x)
// {
//     printf("ui: ");
//     unsigned int mask = 0x01 << 31;
//     while (mask)
//     {
//         printf("%d", (x & mask) == mask);
//         mask >>= 1;
//     }
//     printf("\n");
// }
// struct ui
// {
//     unsigned char uc1 : CHAR_BIT;
//     unsigned char uc2 : CHAR_BIT;
//     unsigned char uc3 : CHAR_BIT;
//     unsigned char uc4 : CHAR_BIT;
// };
// void print_in2_ui_t(struct ui ui_t)
// {
//     printf("unpacking back\n");
//     printf("ui_t:\n");
//     print_in2_uc(ui_t.uc1);
//     print_in2_uc(ui_t.uc2);
//     print_in2_uc(ui_t.uc3);
//     print_in2_uc(ui_t.uc4);
// }

// int main(void)
// {
//     // перевод в 2
//     {
//         int a = 8;
//         int i = 1;

//         int p = 0;
//         int number = 0;
//         do
//         {
//             if (a & i)
//             {
//                 number += pppp(10, p) * 1;
//                 p++;
//             }
//             else
//             {
//                 p++;
//             }

//             a >>= 1;
//         } while (a >= 1);
//     }

//     // перевод в 2, by Alena
//     {
//         unsigned char x = 32;
//         printf("uc: ");
//         unsigned char mask = 0x01 << 7;
//         while (mask)
//         {
//             printf("%d", (x & mask) == mask);
//             mask >>= 1;
//         }
//         printf("\n");
//     }
//     // упаковка и распаковка
//     {    
//         char              a = 'a', b = 'b', c = 'c', d = 'd';
//         unsigned int      pack;
    
//         pack = (((((a << CHAR_BIT) | b) << CHAR_BIT ) | c) << CHAR_BIT) | d;
//         printf("%d\n", (int)pack);

//         char buf = 0xff;
//         char a1, b1, c1, d1;

//         d1 = pack & buf;
//         pack >>= CHAR_BIT;
//         c1 = pack & buf;
//         pack >>= CHAR_BIT;
//         b1 = pack & buf;
//         pack >>= CHAR_BIT;
//         a1 = pack;

//         printf("%c %c %c %c\n", a1, b1, c1, d1);
//     }

//     // упаковка и распаковка by Alena
//     {
//         setbuf(stdout, NULL);
//         //битовые операции
//         {
//             printf("BYTE OPERATIONS:\n");
//             unsigned int ui = 0; //4
//             unsigned char uc;    //1
//             int n = 4;

//             printf("packing\n");
//             for (int i = 0; i < n; i++)
//             {
//                 fflush(stdin);
//                 scanf("%c", &uc);
//                 print_in2_uc(uc);

//                 ui <<= CHAR_BIT;
//                 ui |= uc;

//                 print_in2_ui(ui);
//             }
//             print_in2_ui(ui);

//             printf("unpacking back\n");
//             for (int i = 0; i < n; i++)
//             {
//                 print_in2_uc((ui >> (n - i - 1) * CHAR_BIT) & 0xff);
//             }
//         }
//         //битовые поля
//         {
//             printf("\nBYTE FIELDS:\n");
//             struct ui ui_t;
//             unsigned char uc;

//             printf("packing\n");
//             fflush(stdin);
//             scanf("%c", &uc);
//             ui_t.uc1 = uc;
//             fflush(stdin);
//             scanf("%c", &uc);
//             ui_t.uc2 = uc;
//             fflush(stdin);
//             scanf("%c", &uc);
//             ui_t.uc3 = uc;
//             fflush(stdin);
//             scanf("%c", &uc);
//             ui_t.uc4 = uc;

//             print_in2_ui_t(ui_t);
//         }
//     }
//     // сдвиг циклический вправо
//     {
//         char x = 65;
//         int k = 3;
//         x = (x >> k) | (x << (CHAR_BIT - k));
//         printf("%d\n", x);
//     }

//     // сдвиг циклический влево
//     {
//         char x = 65;
//         int k = 3;
//         x = (x << k) | (x >> (CHAR_BIT - k));
//         printf("%d\n", x);
//     }
//     return 0;
// }


// // сдвиги by ALENA

// unsigned int cycle_mov_left(unsigned int x, int n)
// {
//     assert(n > 0);
//     unsigned int tmp;
//     unsigned int size = sizeof(x) * CHAR_BIT;
//     unsigned int mask = 1;
//     for (unsigned int i = 1; i < size; i++)
//         mask *= 2;
//     for (int i = 0; i < n; i++)
//     {
//         tmp = (x & mask) == mask;
//         x <<= 1;
//         x |= tmp;
//     }
//     return x;
// }

// unsigned int cycle_mov_right(unsigned int x, int n)
// {
//     assert(n > 0);
//     unsigned int tmp;
//     unsigned int size = sizeof(x) * CHAR_BIT;
//     unsigned int mask = 1;

//     for (int i = 0; i < n; i++)
//     {
//         tmp = (x & mask) == mask;
//         x >>= 1;
//         x |= tmp << (size - 1);
//     }
//     return x;
// }

// задача 
// 21. Запишите в одно беззнаковое целое число (длина беззнакового целого равна 4байта) структуру, содержащую данные о файле аудиозаписи:
// 22. жанр ("народная "классическая "кантри "джаз "шансон "бардовская "поп "рэп "рок-н-ролл "рок "электронная "экзотическая "церковная "военная "детская "аудиок-нига");
// 23. стерео/моно;
// 24. длительность в секундах (от 1 до 8192);
// 25. размер файла в кб (от 1 до 16384).
// 26. Решите задачу несколькими способами.

// ИТАК
// содержание структуры
// всего 32 бита
// жанр - 4 (всего 16, а значит можно в 4 бита 0-15)
// стерео\моно - 1 
// размер от 1 до 8192 - 13 (2^13 = 8192)
// размер файла от 1 до 16384 - 14 (2^14 = 16384 - остаток в битах)

// typedef struct audio
// {
//     unsigned genre : 4;
//     unsigned stereo_mono : 1;
//     unsigned dur : 13;
//     unsigned size_file : 14;
// } audio_t;

// #define GENRE_MIN 0
// #define GENRE_MAX 15

// #define MONO 1
// #define STEREO 0

// #define DUR_MIN 0
// #define DUR_MAX 8192

// #define FILESIZE_MIN 0
// #define FILESIZE_MAX 16384

// void print_audio(unsigned genre, unsigned s_m, 
// unsigned duration, unsigned size)
// {
//     printf("AUDIO:\n");
//     printf("genre : %u\n", genre);
//     if (s_m)
//         printf("mono\n");
//     else
//         printf("stereo\n");
//     printf("duration : %u\n", duration + 1);
//     printf("size : %u\n\n", size + 1);
// }

// int main()
// {
//     audio_t aud1;
//     unsigned aud2;

//     // min
//     aud1.genre = GENRE_MIN;
//     aud1.stereo_mono = STEREO;
//     aud1.size_file = FILESIZE_MIN;
//     aud1.dur = DUR_MIN;
//     print_audio(aud1.genre, aud1.stereo_mono, aud1.dur, aud1.size_file);

//     // max
//     aud1.genre = GENRE_MAX;
//     aud1.stereo_mono = MONO;
//     aud1.size_file = FILESIZE_MAX;
//     aud1.dur = DUR_MAX;
//     print_audio(aud1.genre, aud1.stereo_mono, aud1.dur, aud1.size_file);

//     // max_min
//     aud1.genre = 8;
//     aud1.stereo_mono = 1;
//     aud1.size_file = 1268;
//     aud1.dur = 12549;
//     print_audio(aud1.genre, aud1.stereo_mono, aud1.dur, aud1.size_file);

//     // min
//     aud2 = 0;
//     aud2 |= GENRE_MIN;
//     aud2 <<= 4;
//     aud2 |= MONO;
//     aud2 <<= 1;
//     aud2 |= DUR_MIN;
//     aud2 <<= 13;
//     aud2 |= FILESIZE_MIN;

//     unsigned for_print = 255;
//     print_audio((aud2 >> 28) & 0x00000008, (aud2 >> 27) & 0x00000001,
//                 (aud2 >> 18) & 0x00001fff, aud2 & 0x00003fff);

//     unsigned s = 0x00000010;
//     printf("%d", s);

//     char g = 'g';
//     char dd[123];
//     int yy = snprintf(dd, 10, "s%cs%cs", g, g);
//         // min
//     aud2 = 0;
//     aud2 |= GENRE_MIN;
//     aud2 <<= 4;
//     aud2 |= MONO;
//     aud2 <<= 1;
//     aud2 |= DUR_MIN;
//     aud2 <<= 13;
//     aud2 |= FILESIZE_MIN;

//     return 0;
// }
