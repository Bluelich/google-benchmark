//
//  main.cpp
//  google-benckmark
//
//  Created by Bluelich on 2018/5/24.
//  Copyright © 2018年 Bluelich. All rights reserved.
//

#include <iostream>
#include "benckmark/benchmark.h"

using namespace benchmark;
static void _test_uint2str(State& state) {
    unsigned int num = 1234;
    while (state.KeepRunning()){
        //num -> string
        char str[12];
        sprintf(str, "%d", num);
    }
}
/*
 BENCHMARK(BM_uint2str);
 */
using namespace benchmark::internal;
static Benchmark* _benchmark_123_test_uint2str __attribute__((unused)) = RegisterBenchmarkInternal(new FunctionBenchmark("BM_uint2str",_test_uint2str));
using namespace benchmark;
static void _test_memcpy(State& state) {
    char* src = new char[state.range(0)];
    char* dst = new char[state.range(0)];
    memset(src, 'x', state.range(0));
    while (state.KeepRunning()){
        memcpy(dst, src, state.range(0));
    }
    state.SetBytesProcessed(int64_t(state.iterations()) *
                            int64_t(state.range(0)));
    delete[] src;
    delete[] dst;
}
//fuctions just return this like masonry
BENCHMARK(_test_memcpy)->Arg(1<<3)->Arg(1<<6)->Arg(1<<9)->Arg(1<<10)->Arg(1<<13);

/*
 BENCHMARK_MAIN();
 */
using namespace std;
int main(int argc, const char * argv[]) {
    // Register the function as a benchmark
    benchmark::RunSpecifiedBenchmarks();
    cout << endl;
    cout << "Hello, World!\n";
    cout << endl;
    return 0;
}
