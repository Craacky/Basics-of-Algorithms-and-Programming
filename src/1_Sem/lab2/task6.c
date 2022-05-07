#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("----------------------------------------\n");
    printf("Memory SCAHR:   %zu\n", sizeof(signed char));
    printf("SCHAR_MAX   :   %d\n", SCHAR_MAX);
    printf("SCHAR_MIN   :   %d\n", SCHAR_MIN);
    printf("----------------------------------------\n");
    printf("Memory UCAHR:   %zu\n", sizeof(unsigned char));
    printf("UCHAR_MAX   :   %u\n", UCHAR_MAX);
    printf("UCHAR_MIN   :   %d\n", NULL);
    printf("----------------------------------------\n");
    printf("Memory SINT :   %zu\n", sizeof(signed int));
    printf("SINT_MAX    :   %d\n", INT_MAX);
    printf("SINT_MIN    :   %d\n", INT_MIN);
    printf("----------------------------------------\n");
    printf("Memory UINT :   %zu\n", sizeof(unsigned int));
    printf("UINT_MAX    :   %u\n", UINT_MAX);
    printf("UINT_MIN    :   %d\n", NULL);
    printf("----------------------------------------\n");
    printf("Memory SHRT :   %zu\n", sizeof(signed short int));
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n", SHRT_MIN);
    printf("----------------------------------------\n");
    printf("Memory USHRT:   %zu\n", sizeof(unsigned short int));
    printf("USHRT_MAX   :   %u\n", USHRT_MAX);
    printf("USHRT_MIN   :   %d\n", NULL);
    printf("----------------------------------------\n");
    printf("Memory LONG :   %zu\n", sizeof(signed long int));
    printf("LONG_MAX    :   %ld\n", LONG_MAX);
    printf("LONG_MIN    :   %ld\n", LONG_MIN);
    printf("----------------------------------------\n");
    printf("Memory ULONG:   %zu\n", sizeof(unsigned long int));
    printf("ULONG_MAX   :   %lu\n", ULONG_MAX);
    printf("ULONG_MIN   :   %d\n", NULL);
    printf("----------------------------------------\n");
    printf("Memory FLT  :   %zu\n", sizeof(float));
    printf("FLT_MAX     :   %g\n", FLT_MAX);
    printf("FLT_MIN     :   %g\n", FLT_MIN);
    printf("----------------------------------------\n");
    printf("Memory DBL  :   %zu\n", sizeof(double));
    printf("DBL_MAX     :   %g\n", DBL_MAX);
    printf("DBL_MIN     :   %g\n", DBL_MIN);
    printf("----------------------------------------\n");
    printf("Memory LDBL :   %zu\n", sizeof(long double));
    printf("LDBL_MAX    :   %LE\n", LDBL_MAX);
    printf("LDBL_MIN    :   %LE\n", LDBL_MIN);
    printf("----------------------------------------\n");
    return 0;
}