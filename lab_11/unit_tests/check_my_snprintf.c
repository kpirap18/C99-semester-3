#include "check_main.h"

static int my_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
        {
			return -1;
        }
        i++;
	}
	if (s1[i] != '\0' || s2[i] != '\0')
    {
		return -1;
    }

    return 0;
}

START_TEST(tests_all)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "qqq 1 12 11 a";
    int count1 = 13;

    char str[] = "qqq";
    uint32_t a = 1;
    int b = 12;
    int16_t c = 11;
    uint64_t d = 10;
    char f[] = "%s %x %d %hd %llx";

    count = my_snprintf(s, 50, f, str, a, b, c, d);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, str, a, b, c, d);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_s)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "qqq ";
    int count1 = 4;

    char str[] = "qqq";
    char f[] = "%s ";

    count = my_snprintf(s, 50, f, str);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, 50, f, str);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_s1)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "I love C";
    int count1 = 8;

    char str[] = "I love C";
    char f[] = "%s";

    count = my_snprintf(s, 50, f, str);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, 50, f, str);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_s2)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "I love C99";
    int count1 = 10;

    char str[] = "I love C99";
    char f[] = "%s";

    count = my_snprintf(s, 50, f, str);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, 50, f, str);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_s3)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "I lo";
    int count1 = 10;

    char str[] = "I love C99";
    char f[] = "%s";

    count = my_snprintf(s, 5, f, str);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, 5, f, str);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_s_not_format)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "";
    int count1 = 0;

    char str[] = "I love C";
    char f[] = "";

    count = my_snprintf(s, 50, f, str);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, 50, f, str);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_s_not_args)
{
    char s[BUFSIZE] = "\0";
    int rc;
    char s1[BUFSIZE] = "";

    char f[] = "%s";

    // В данной ситуации при оспользовании библиотечной функции
    // возникает ошибка компиляции, поэтому проверяю только работу
    // моей программы (возвращение 0, как признак того, что ничего
    // не записалось в строку)
    my_snprintf(s, 50, f);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_s_nonesize)
{
    char s[BUFSIZE] = "\0";
    int count;
    int rc;

    char s1[BUFSIZE] = "";
    int count1 = 8;

    char str[] = "I love C";
    char f[] = "%s";

    count = my_snprintf(s, 0, f, str);
    ck_assert_int_eq(count1, count);
    printf("%s\n", s);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, 0, f, str);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_s_null_s)
{
    char *s = NULL;
    int count;

    int count1 = 8;

    char str[] = "I love C";
    char f[] = "%s";

    count = my_snprintf(s, 50, f, str);
    ck_assert_int_eq(count1, count);
    ck_assert_ptr_eq(s, NULL);
}
END_TEST

START_TEST(tests_s_null_none)
{
    char *s = NULL;
    int count;

    int count1 = 8;

    char str[] = "I love C";
    char f[] = "%s";

    count = my_snprintf(s, 0, f, str);
    ck_assert_int_eq(count1, count);
    ck_assert_ptr_eq(s, NULL);
    count = snprintf(s, 0, f, str);
    ck_assert_int_eq(count1, count);
    ck_assert_ptr_eq(s, NULL);
}
END_TEST

START_TEST(tests_x)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "1";
    int count1 = 1;

    uint32_t a = 1;
    char f[] = "%x";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_x1)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "a";
    int count1 = 1;

    uint32_t a = 10;
    char f[] = "%x";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_x2)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "84";
    int count1 = 2;

    uint32_t a = 132;
    char f[] = "%x";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_x3)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "487b";
    int count1 = 4;

    uint32_t a = 18555;
    char f[] = "%x";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_x4)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "0";
    int count1 = 1;

    uint32_t a = 0;
    char f[] = "%x";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_x5)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "ffffffff";
    int count1 = 8;

    uint32_t a = -1;
    char f[] = "%x";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_x_not_format)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "";
    int count1 = 0;

    uint32_t a = 18555;
    char f[] = "";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_d)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "1";
    int count1 = 1;

    int a = 1;
    char f[] = "%d";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_d1)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "32004";
    int count1 = 5;

    int a = 32004;
    char f[] = "%d";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_d2)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "-84";
    int count1 = 3;

    int a = -84;
    char f[] = "%d";

    count = my_snprintf(s, 50, f, a);
    printf("d2 %s\n", s);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_d3)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "0";
    int count1 = 1;

    int a = 0;
    char f[] = "%d";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_d4)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "2147483647";
    int count1 = 10;

    int a = INT_MAX;
    char f[] = "%d";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_d5)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "-2147483648";
    int count1 = 11;

    int a = INT_MIN;
    char f[] = "%d";

    count = my_snprintf(s, 50, f, a);
    printf("d5 %s\n", s);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_d_not_format)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "";
    int count1 = 0;

    int a = 18555;
    char f[] = "";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_hd)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "1";
    int count1 = 1;

    int16_t a = 1;
    char f[] = "%hd";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_hd1)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "16000";
    int count1 = 5;

    int16_t a = 16000;
    char f[] = "%hd";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_hd2)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "-84";
    int count1 = 3;

    int16_t a = -84;
    char f[] = "%hd";

    count = my_snprintf(s, 50, f, a);
    printf("hd2 %s", s);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_hd3)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "0";
    int count1 = 1;

    int16_t a = 0;
    char f[] = "%hd";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_hd_not_format)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "";
    int count1 = 0;

    int16_t a = 18555;
    char f[] = "";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_llx)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "1";
    int count1 = 1;

    uint64_t a = 1;
    char f[] = "%llx";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_llx1)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "a";
    int count1 = 1;

    uint64_t a = 10;
    char f[] = "%llx";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_llx2)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "84";
    int count1 = 2;

    uint64_t a = 132;
    char f[] = "%llx";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_llx3)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "a0e15";
    int count1 = 5;

    uint64_t a = 658965;
    char f[] = "%llx";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_llx4)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "0";
    int count1 = 1;

    uint64_t a = 0;
    char f[] = "%llx";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_llx5)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "ffffffffffffffff";
    int count1 = 16;

    uint64_t a = -1;
    char f[] = "%llx";

    count = my_snprintf(s, 50, f, a);
    printf("llx5 %s", s);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

START_TEST(tests_llx_not_format)
{
    char s[BUFSIZE];
    int count;
    int rc;

    char s1[BUFSIZE] = "";
    int count1 = 0;

    uint64_t a = 18555;
    char f[] = "";

    count = my_snprintf(s, 50, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
    count = snprintf(s, BUFSIZE, f, a);
    ck_assert_int_eq(count1, count);
    rc = my_strcmp(s1, s);
    ck_assert_int_eq(rc, 0);
}
END_TEST

Suite* my_snprintf_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("my_snprintf");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, tests_all);
    tcase_add_test(tc_pos, tests_s);
    tcase_add_test(tc_pos, tests_s1);
    tcase_add_test(tc_pos, tests_s2);
    tcase_add_test(tc_pos, tests_s3);
    tcase_add_test(tc_pos, tests_s_not_format);
    tcase_add_test(tc_pos, tests_s_not_args);
    tcase_add_test(tc_pos, tests_s_nonesize);
    tcase_add_test(tc_pos, tests_s_null_s);
    tcase_add_test(tc_pos, tests_s_null_none);
    tcase_add_test(tc_pos, tests_x);
    tcase_add_test(tc_pos, tests_x1);
    tcase_add_test(tc_pos, tests_x2);
    tcase_add_test(tc_pos, tests_x3);
    tcase_add_test(tc_pos, tests_x4);
    tcase_add_test(tc_pos, tests_x5);
    tcase_add_test(tc_pos, tests_x_not_format);
    tcase_add_test(tc_pos, tests_d);
    tcase_add_test(tc_pos, tests_d1);
    tcase_add_test(tc_pos, tests_d2);
    tcase_add_test(tc_pos, tests_d3);
    tcase_add_test(tc_pos, tests_d4);
    tcase_add_test(tc_pos, tests_d5);
    tcase_add_test(tc_pos, tests_d_not_format);
    tcase_add_test(tc_pos, tests_hd);
    tcase_add_test(tc_pos, tests_hd1);
    tcase_add_test(tc_pos, tests_hd2);
    tcase_add_test(tc_pos, tests_hd3);
    tcase_add_test(tc_pos, tests_hd_not_format);
    tcase_add_test(tc_pos, tests_llx);
    tcase_add_test(tc_pos, tests_llx1);
    tcase_add_test(tc_pos, tests_llx2);
    tcase_add_test(tc_pos, tests_llx3);
    tcase_add_test(tc_pos, tests_llx4);
    tcase_add_test(tc_pos, tests_llx5);
    tcase_add_test(tc_pos, tests_llx_not_format);
    suite_add_tcase(s, tc_pos);

    return s;
}
