#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

#include "bitmap_sort.hpp"

#include <benchmark/benchmark.h>

using namespace std;


static const size_t SIZE = 10000000;
static const size_t DIST = SIZE;


vector<int> generate_vector(size_t s, int d)
{
	auto const time = chrono::system_clock::now();
	
	mt19937                     gen;
	uniform_int_distribution<>  dist(0, d);
	vector<int>                 vec;
	
	gen.seed(chrono::system_clock::to_time_t(time));
	for (int i = s; i; --i)
		vec.push_back(dist(gen));

	return vec;
}


static void BM_bitmap_sort(benchmark::State & state)
{
	vector<int> v = generate_vector(SIZE, DIST);

	for (auto _ : state)
		bitmap_sort(v.begin(), v.end());
}
BENCHMARK(BM_bitmap_sort);


static void BM_bitmap_sort_min_max(benchmark::State & state)
{
	vector<int> v = generate_vector(SIZE, DIST);

	for (auto _ : state)
		bitmap_sort(v.begin(), v.end(), 0, DIST);
}
BENCHMARK(BM_bitmap_sort_min_max);


static void BM_sort(benchmark::State & state)
{
	vector<int> v = generate_vector(SIZE, DIST);

	for (auto _ : state)
		sort(v.begin(), v.end());
}
BENCHMARK(BM_sort);


BENCHMARK_MAIN();

