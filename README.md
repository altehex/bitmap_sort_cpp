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
BM_bitmap_sort               39.3 ns         39.3 ns     17847125
BM_bitmap_sort_min_max       26.2 ns         26.2 ns     26336625
BM_qsort                      132 ns          132 ns      5306954
BM_sort                      10.3 ns         10.3 ns     68088153
```

### SIZE = 100
```
-----------------------------------------------------------------
Benchmark                       Time             CPU   Iterations
-----------------------------------------------------------------
BM_bitmap_sort                233 ns          233 ns      2966174
BM_bitmap_sort_min_max        184 ns          184 ns      3965656
BM_qsort                     1828 ns         1826 ns       384468
BM_sort                       456 ns          456 ns      1449596
```

### SIZE = 1000
```
-----------------------------------------------------------------
Benchmark                       Time             CPU   Iterations
-----------------------------------------------------------------
BM_bitmap_sort               2730 ns         2727 ns       258217
BM_bitmap_sort_min_max       2134 ns         2131 ns       327466
BM_qsort                    20966 ns        20942 ns        33445
BM_sort                      7661 ns         7652 ns        91718
```

### SIZE = 10^7 (phone number sorting simulation)
```
-----------------------------------------------------------------
Benchmark                       Time             CPU   Iterations
-----------------------------------------------------------------
BM_bitmap_sort           71221903 ns     70800308 ns            9
BM_bitmap_sort_min_max   64665148 ns     64412033 ns           10
BM_qsort                456262049 ns    454764232 ns            2
BM_sort                 799785703 ns    798275555 ns            1
```
