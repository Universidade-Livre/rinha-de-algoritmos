/*
LICENSE

Copyright (c) 2023 Felipe Markson dos Santos Monteiro

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

// Some macro magics to debug memory issues
#ifdef DEBUG
#define MATRIX(i_, j_) (*(matrix((i_), (j_), __LINE__)))
#define w(i_) (*(weigths(i_, __LINE__)))
#define v(i_) (*(values(i_, __LINE__)))
#define LOG(...) printf(__VA_ARGS__)
#define ASSERT(...) inner_assert(__VA_ARGS__)
#define LOGMEM(...) fprintf(stderr, __VA_ARGS__)

#else
#define MATRIX(i_, j_) buffer[(i_) * NCOL_MATRIX + (j_)]
#define w(i_) wt[(i_)]
#define v(i_) vl[(i_)]
#define LOG(...)
#define ASSERT(...)
#define LOGMEM(...)

// For common.c
#define inner_assert(...)
#endif  // DEBUG

#include "common.c"  // Just to reduce the compilation complexity
#define Int int32_t

// Dynamic memory meta-data
Int* buffer = 0;
Int* wt = 0;
Int* vl = 0;
Int N = 0;  // MAX 1000
Int W = 0;  // MAX 2666
#define NROW_MATRIX (N + 1)
#define NCOL_MATRIX (W + 1)
#define SIZE_MATRIX (NROW_MATRIX * NCOL_MATRIX)  // MAX 2669667
#define SIZE_BUFFER (SIZE_MATRIX + (N + N))      // MAX 2671667 => 10_686_668 Bytes or 11MB

// Helper functions to debug memory issues (used only in DEBUG mode).
Int* matrix(Int i, Int j, Int line) {
    Int local = i * NCOL_MATRIX + j;
    LOGMEM("M L:%d -> Accessing %d:(%d, %d) in %d\n", line, local, i, j, SIZE_MATRIX - 1);

    ASSERT(i < NROW_MATRIX, "Invalid access in row");
    ASSERT(j < NCOL_MATRIX, "Invalid access in col");
    ASSERT(local < SIZE_BUFFER, "Invalid access in buffer");
    return buffer + local;
}
Int* weigths(Int i, Int line) {
    LOGMEM("W L:%d -> Accessing %d in %d\n", line, i, N - 1);

    ASSERT(i < N, "Invalid access in w");
    return wt + i;
}
Int* values(Int i, Int line) {
    LOGMEM("V L:%d -> Accessing %d in %d\n", line, i, N - 1);

    ASSERT(i < N, "Invalid access in v");
    return vl + i;
}

// Here is where the magic happen
void recursive_knapsack(Int i, Int j) {
    ASSERT(i < NROW_MATRIX, "Invalid access in row");
    ASSERT(j < NCOL_MATRIX, "Invalid access in col");
    Int k = i - 1;
    Int wk = w(k);
    Int vk = v(k);
    if ((i == 0) || (j == 0)) {
        MATRIX(i, j) = 0;
        return;
    }

    if (MATRIX(k, j) == -1)
        recursive_knapsack(k, j);

    if (wk > j) {
        MATRIX(i, j) = MATRIX(k, j);
    } else {
        if (MATRIX(k, j - wk) == -1)
            recursive_knapsack(k, j - wk);
        Int value1 = MATRIX(k, j - wk) + vk;
        Int value2 = MATRIX(k, j);
        MATRIX(i, j) = (value1 > value2) ? value1 : value2;
    }
}

int main(int argc, char const* argv[]) {
    ASSERT(argc == 2, "Provide the file path");
    // General purpose Int
    Int i = 0;
    Int j = 0;

    // File Handlers
    str file = readfile(argv[1]);
    view_str file_view = {file.items, file.length};
    view_str line = pop_until(&file_view, '\n');

    ASSERT(line.length > 0, "could not read the file");
    i = sscanf(line.items, "%d %d", &N, &W);
    ASSERT(i == 2, "Could not read the N and W");

    LOG("Alocating %lu KB for the problem N: %d, W: %d\n", (SIZE_BUFFER * sizeof(buffer[0])) / 1000, N, W);

    // We call only one malloc to store the matrix, weights, and values.
    // Therefore, we will have only one big chunk of memory which (hopefully) can be
    // stored in the cache, improving the time to access memory.
    // Also, we do only one syscall insted of reallocing memory.
    buffer = malloc(SIZE_BUFFER * sizeof(buffer[0]));
    ASSERT(buffer != NULL, "Could not allocated memory");

    // Hopefully the compiller will optimize it for some sort of memset.
    for (j = 0; j < SIZE_BUFFER; j++)
        buffer[j] = -1;
    wt = buffer + SIZE_MATRIX;
    vl = wt + N;

    for (i = 0; i < N; i++) {
        line = pop_until(&file_view, '\n');
        j = sscanf(line.items, "%d\t%d", &(wt[i]), &(vl[i]));
        ASSERT(j == 2, "Could not read the value and weigth");
        LOG("v: %d | w: %d\n", vl[i], wt[i]);
    }

    recursive_knapsack(N, W);
    printf("%d\n", MATRIX(N, W));

    free(file.items);
    free(buffer);
    return 0;
}
