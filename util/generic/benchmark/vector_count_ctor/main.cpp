#include "f.h"

#include <library/testing/benchmark/bench.h>

#define DEFINE_BENCHMARK(N)                   \
    Y_CPU_BENCHMARK(Yvector_##N, iface) {     \
        CreateYvector(N, iface.Iterations()); \
    }                                         \
    Y_CPU_BENCHMARK(Carray_##N, iface) {      \
        CreateCarray(N, iface.Iterations());  \
    }

DEFINE_BENCHMARK(1)
DEFINE_BENCHMARK(2)
DEFINE_BENCHMARK(8)
DEFINE_BENCHMARK(10)
DEFINE_BENCHMARK(16)
DEFINE_BENCHMARK(20)
DEFINE_BENCHMARK(1000)
DEFINE_BENCHMARK(1024)
DEFINE_BENCHMARK(8192)
DEFINE_BENCHMARK(10000)
DEFINE_BENCHMARK(65536)
DEFINE_BENCHMARK(100000)
DEFINE_BENCHMARK(4194304)
DEFINE_BENCHMARK(1000000)
DEFINE_BENCHMARK(33554432)
DEFINE_BENCHMARK(10000000)
DEFINE_BENCHMARK(268435456)
DEFINE_BENCHMARK(100000000)
