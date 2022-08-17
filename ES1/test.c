#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "provapuntatorevoi.h"
#include "unity.h"



#define ARRAY_INT_LENGHT 10



int cmp_int(const record *a, const record *b)
{
    return (a->field3)-(b->field3);
}

int cmp_float(const void *f, const void *s)
{
  record *a = (record*)f;
  record *b = (record*)s;
  if((a->field4)>(b->field4))
    return 1;
  else if((a->field4)<(b->field4))
    return -1;
  else
    return 0;
}

int cmp_string (const void * f, const void * s ) {
    record *a = (record*)f;
    record *b = (record*)s;
    //printf("%s %s", a->field2, b->field2);
    return strcmp(a->field2, b->field2);
}


// Data elements that are initialized before each test
static int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;
static int x1, x2, x3, x4, x5, x6, x7, x8, x9, x10;

void setUp(void)
{
    i1 = 1;
    i2 = 2;
    i3 = 3;
    i4 = 4;
    i5 = 5;
    i6 = 6;
    i7 = 7;
    i8 = 8;
    i9 = 9;
    i10 = 10;
    x1 = 1.01;
    x2 = 1.02;
    x3 = 1.03;
    x4 = 1.04;
    x5 = 1.05;
    x6 = 1.06;
    x7 = 10.7;
    x8 = 1.08;
    x9 = 1.09;
    x10 = 1.1;
}

/*BINARY TEST*/
static void test_three_el_int_insertion_binary(void)
{
    int *array_expected[] = {&i1, &i2};
    int *actual_array[] = {&i2, &i1};

    insertionSort((record**)actual_array, (CMPFUNC)cmp_int,0,1); //binary
    TEST_ASSERT_EQUAL_PTR_ARRAY(array_expected, actual_array, 2);
}

static void test_ten_el_int_insertion_binary(void)
{
    int *array_expected[] = {&i1, &i2, &i3,&i4,&i5,&i6,&i7,&i8,&i9,&i10};
    int *actual_array[] = {&i10, &i9, &i8, &i7, &i6, &i5, &i4, &i3, &i2, &i1};

    insertionSort((record**)actual_array, (CMPFUNC)cmp_int,0,9); //binary
    TEST_ASSERT_EQUAL_PTR_ARRAY(array_expected, actual_array, 10);
}

static void test_one_el_int_binary(void)
{
    int *array_expected[] = {&i1};
    int *actual_array[] = {&i1};

    insertionSort((record**)actual_array, (CMPFUNC)cmp_int, 0,0); //binary
    TEST_ASSERT_EQUAL_PTR_ARRAY(array_expected, actual_array, 1);
}

static void test_equal_el_binary(void)
{
    int *array_expected[] = {&i1, &i1, &i1};
    int *actual_array[] = {&i1, &i1, &i1};

    insertionSort((record**)actual_array, (CMPFUNC)cmp_int, 0,2); //binary
    TEST_ASSERT_EQUAL_PTR_ARRAY(array_expected, actual_array, 3);
}

static void test_fifty_el_string_binary(void)
{
    double *array_expected[] = {&x1, &x2, &x3, &x4, &x5};
    double *actual_array[] = {&x5, &x3, &x2, &x4, &x1};
    insertionSort((record**)actual_array, (CMPFUNC)cmp_float,0,4); //binary
    TEST_ASSERT_EQUAL_PTR_ARRAY(array_expected, actual_array, 5);
}

static void test_three_el_string_binary(void)
{
    
    double *array_expected[] = {&x1, &x2, &x3};
    double *actual_array[] = {&x1, &x3, &x2};
    
    insertionSort((record**)actual_array, (CMPFUNC)cmp_float,0,2); //binary
    TEST_ASSERT_EQUAL_PTR_ARRAY(array_expected, actual_array, 3);
}

static void test_one_el_string_binary(void)
{
    double *array_expected[] = {&x1};
    double *actual_array[] = {&x1};

    insertionSort((record**)actual_array, (CMPFUNC)cmp_float,0,0); //binary
    TEST_ASSERT_EQUAL_PTR_ARRAY(array_expected, actual_array, 1);
}



/*quicksort TEST*/

static void test_three_el_int_insertion_quick(void)
{
    int *array_expected[] = {&i1, &i2, &i3};
    int *actual_array[] = {&i3, &i2, &i1};

    quick_sort((record**)actual_array, (CMPFUNC)cmp_int,0 ,2); //QUICK
    TEST_ASSERT_EQUAL_PTR_ARRAY(array_expected, actual_array, 3);
}


static void test_equal_el_quick(void)
{
    int *array_expected[] = {&i1, &i1, &i1};
    int *actual_array[] = {&i1, &i1, &i1};

    quick_sort((record**)actual_array, (CMPFUNC)cmp_int, 0,2); //QUICK
    TEST_ASSERT_EQUAL_PTR_ARRAY(array_expected, actual_array, 3);
}

static void test_fifty_el_string_quick(void)
{
    char *array_expected[] = {"Acerbo", "Figliastro", "Mosterrà", "Quei", "Sfinge", "ago", "avea", "birra", "bullo", "cavallo", "ercole", "faccia", "facocero", "gigi", "hotel", "italia", "lame", "mamma", "mano", "nebula", "nebuloso", "oca", "occhio", "pippo", "pluto", "pollo", "quadretto", "quadro", "resto", "rutto", "sotto", "stato", "tetto", "tubercolosi", "ululato", "uovo", "uuu", "vai", "via", "vuoto", "wee", "would", "wow", "xenon", "xox", "ye", "you", "zeta", "zorro", "zzz"};
    char *actual_array[] = {"you", "Quei", "zeta", "pollo", "italia", "resto", "ercole", "rutto", "stato", "cavallo", "sotto", "zorro", "ululato", "mamma", "uuu", "Mosterrà", "Sfinge", "ago", "quadretto", "avea", "tetto", "bullo", "quadro", "vai", "wow", "via", "wee", "occhio", "would", "xenon", "faccia", "facocero", "gigi", "lame", "Acerbo", "Figliastro", "mano", "vuoto", "nebula", "oca", "tubercolosi", "zzz", "birra", "pluto", "hotel", "xox", "nebuloso", "uovo", "ye", "pippo"};

    quick_sort((record**)actual_array, (CMPFUNC)cmp_string,0,49); //QUICK
    TEST_ASSERT_EQUAL_PTR_ARRAY(array_expected, actual_array, 50);
}

static void test_three_el_string_quick(void)
{
    
    char *array_expected[] = {"albero", "bici", "casa"};
    char *actual_array[] = {"casa", "bici", "albero"};
    
    quick_sort((record**)actual_array, (CMPFUNC)cmp_string,0,2); //QUICK
    TEST_ASSERT_EQUAL_PTR_ARRAY(array_expected, actual_array, 3);
}

static void test_one_el_string_quick(void)
{
    char *array_expected[] = {"albero"};
    char *actual_array[] = {"albero"};

    quick_sort((record**)actual_array, (CMPFUNC)cmp_string,0,0); //QUICK
    TEST_ASSERT_EQUAL_PTR_ARRAY(array_expected, actual_array, 1);
}

int main(void)
{
    // test session
    UNITY_BEGIN();

    /*BINARY INSERTION SORT TEST*/
    RUN_TEST(test_three_el_int_insertion_binary);
    RUN_TEST(test_equal_el_binary);
    RUN_TEST(test_three_el_string_binary);
    RUN_TEST(test_fifty_el_string_binary);
    /*BINARY INSERTION SORT TEST*/

    /*QUICKSORT TEST*/
    RUN_TEST(test_three_el_int_insertion_quick);
    RUN_TEST(test_equal_el_quick);
    RUN_TEST(test_three_el_string_quick);
    RUN_TEST(test_fifty_el_string_quick);
    /*QUICKSORT TEST*/

    return UNITY_END();
}