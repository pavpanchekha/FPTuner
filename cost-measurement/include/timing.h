

#include "types.h"

#include <stddef.h>
#include <stdio.h>




typedef fp32(*unop_fp32)(fp32);
typedef fp64(*unop_fp64)(fp64);

typedef fp32(*binop_fp32)(fp32, fp32);
typedef fp64(*binop_fp64)(fp64, fp64);

typedef fp32(*triop_fp32)(fp32, fp32, fp32);
typedef fp64(*triop_fp64)(fp64, fp64, fp64);




void register_performance_handler(void);

void time_unop_fp32(fp32 low, fp32 high,
                    unop_fp32* functions, char** names, size_t count,
                    size_t log2_values, size_t runs, size_t secs);

void time_unop_fp64(fp64 low, fp64 high,
                    unop_fp64* functions, char** names, size_t count,
                    size_t log2_values, size_t runs, size_t secs);

void time_binop_fp32(fp32 low_1, fp32 high_1, fp32 low_2, fp32 high_2,
                     binop_fp32* functions, char** names, size_t count,
                     size_t log2_values, size_t runs, size_t secs);

void time_binop_fp64(fp64 low_1, fp64 high_1, fp64 low_2, fp64 high_2,
                     binop_fp64* functions, char** names, size_t count,
                     size_t log2_values, size_t runs, size_t secs);

void time_triop_fp32(fp32 low_1, fp32 high_1, fp32 low_2, fp32 high_2, fp32 low_3, fp32 high_3,
                     triop_fp32* functions, char** names, size_t count,
                     size_t log2_values, size_t runs, size_t secs);

void time_triop_fp64(fp64 low_1, fp64 high_1, fp64 low_2, fp64 high_2, fp64 low_3, fp64 high_3,
                     triop_fp64* functions, char** names, size_t count,
                     size_t log2_values, size_t runs, size_t secs);
