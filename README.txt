# Bitmap sort
---
C++ implementation of bitmap sorting algorithm described in Jon Bentley's Programming Pearls book. This algorithm is effective for sorting an array of unique integer numbers.
Google Benchmark is required for benchmark.cpp.


## Benchmark results
Performance worsens as the maximum possible value(DIST) increases. In the following examples DIST = SIZE.

### SIZE = 10
```
-----------------------------------------------------------------
Benchmark                       Time             CPU   Iterations
-----------------------------------------------------------------
BM_bitmap_sort               39.0 ns         38.9 ns     18136098
BM_bitmap_sort_min_max       24.7 ns         24.7 ns     29131138
BM_sort                      10.5 ns         10.5 ns     67003362
```

### SIZE = 100
```
-----------------------------------------------------------------
Benchmark                       Time             CPU   Iterations
-----------------------------------------------------------------
BM_bitmap_sort                220 ns          220 ns      3130183
BM_bitmap_sort_min_max        190 ns          190 ns      3554883
BM_sort                       471 ns          471 ns      1387135
```

### SIZE = 1000
```
BM_bitmap_sort               2468 ns         2465 ns       292130
BM_bitmap_sort_min_max       2140 ns         2138 ns       325280
BM_sort                      7687 ns         7679 ns        90787
```

### SIZE = 10^7 (phone number sorting simulation)
```
-----------------------------------------------------------------
Benchmark                       Time             CPU   Iterations
-----------------------------------------------------------------
BM_bitmap_sort           73006674 ns     72686436 ns            9
BM_bitmap_sort_min_max   65324549 ns     64941644 ns           10
BM_sort                 812270826 ns    808860171 ns            1
```
