#include <benchmark/benchmark.h>

#include <my_malloc.h>

static void get_hello(benchmark::State& state) {
	MyMalloc m;
	for (auto _ : state) {
		auto hello = m.malloc(10);
		m.free(hello);
	}
}

BENCHMARK(get_hello);
