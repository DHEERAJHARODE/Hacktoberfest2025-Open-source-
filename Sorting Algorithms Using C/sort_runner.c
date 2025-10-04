/* sort_runner.c
 * A unified command-line runner for classic sorting algorithms.
 *
 * Features
 * - Choose algo: quick, merge, heap, insertion, selection, counting, radix
 * - Input from stdin (whitespace-separated ints) or random generation
 * - Verification of sorted output
 * - Optional printing of sorted array
 * - Timing via clock_gettime() (POSIX) or clock() fallback
 *
 * Build:
 *   gcc -O2 -Wall -Wextra -std=c11 sort_runner.c -o sort_runner
 *
 * Examples:
 *   # read numbers from stdin and sort with quicksort
 *   echo "5 4 2 9 1 5" | ./sort_runner --algo quick --stdin --print --verify
 *
 *   # generate 100000 random ints and measure heap sort (no printing)
 *   ./sort_runner --algo heap --size 100000 --verify
 *
 *   # radix/counting sort assume non-negative integers
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

#ifndef ARRAYLEN_MAX
#define ARRAYLEN_MAX (50 * 1000 * 1000) /* safety guard */
#endif

/* ============================================================
   Utility
   ============================================================ */
static void die(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
    exit(EXIT_FAILURE);
}

static void *xmalloc(size_t n) {
    void *p = malloc(n);
    if (!p) die("out of memory");
    return p;
}

static void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

static bool is_sorted(const int *a, size_t n) {
    if (n == 0) return true;
    for (size_t i = 1; i < n; ++i) {
        if (a[i-1] > a[i]) return false;
    }
    return true;
}

static void print_array(const int *a, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    putchar('\n');
}

static long long now_ns(void) {
#if defined(_POSIX_TIMERS) && (_POSIX_TIMERS > 0)
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000000000LL + ts.tv_nsec;
#else
    /* Fallback */
    return (long long)clock() * (1000000000LL / CLOCKS_PER_SEC);
#endif
}

/* ============================================================
   Sorting algorithms
   Each sorts in-place an array a[0..n-1]
   ============================================================ */

/* Insertion sort (stable, O(n^2)) */
static void insertion_sort(int *a, size_t n) {
    for (size_t i = 1; i < n; ++i) {
        int key = a[i];
        size_t j = i;
        while (j > 0 && a[j-1] > key) {
            a[j] = a[j-1];
            --j;
        }
        a[j] = key;
    }
}

/* Selection sort (unstable, O(n^2)) */
static void selection_sort(int *a, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) min_idx = j;
        }
        if (min_idx != i) swap(&a[i], &a[min_idx]);
    }
}

/* Quick sort (unstable, average O(n log n)) */
static size_t partition(int *a, size_t low, size_t high) {
    int pivot = a[high];
    size_t i = low;
    for (size_t j = low; j < high; ++j) {
        if (a[j] <= pivot) {
            swap(&a[i], &a[j]);
            ++i;
        }
    }
    swap(&a[i], &a[high]);
    return i;
}
static void quick_sort_rec(int *a, size_t low, size_t high) {
    if (low >= high) return;
    size_t p = partition(a, low, high);
    if (p > 0) quick_sort_rec(a, low, p - 1);
    quick_sort_rec(a, p + 1, high);
}
static void quick_sort(int *a, size_t n) {
    if (n > 0) quick_sort_rec(a, 0, n - 1);
}

/* Merge sort (stable, O(n log n)) */
static void merge(int *a, int *tmp, size_t l, size_t m, size_t r) {
    size_t i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else              tmp[k++] = a[j++];
    }
    while (i <= m) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (size_t t = l; t <= r; ++t) a[t] = tmp[t];
}
static void merge_rec(int *a, int *tmp, size_t l, size_t r) {
    if (l >= r) return;
    size_t m = l + (r - l) / 2;
    merge_rec(a, tmp, l, m);
    merge_rec(a, tmp, m + 1, r);
    merge(a, tmp, l, m, r);
}
static void merge_sort(int *a, size_t n) {
    if (n < 2) return;
    int *tmp = (int *)xmalloc(sizeof(int) * n);
    merge_rec(a, tmp, 0, n - 1);
    free(tmp);
}

/* Heap sort (unstable, O(n log n)) */
static void heapify(int *a, size_t n, size_t i) {
    size_t largest = i, l = 2*i + 1, r = 2*i + 2;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i) {
        swap(&a[i], &a[largest]);
        heapify(a, n, largest);
    }
}
static void heap_sort(int *a, size_t n) {
    if (n < 2) return;
    for (long long i = (long long)n/2 - 1; i >= 0; --i) heapify(a, n, (size_t)i);
    for (size_t i = n - 1; i > 0; --i) {
        swap(&a[0], &a[i]);
        heapify(a, i, 0);
    }
}

/* Counting sort (stable, O(n + k)) for NON-NEGATIVE ints */
static int max_value(const int *a, size_t n) {
    int mx = 0;
    for (size_t i = 0; i < n; ++i) if (a[i] > mx) mx = a[i];
    return mx;
}
static void counting_sort_nonneg(int *a, size_t n) {
    if (n == 0) return;
    for (size_t i = 0; i < n; ++i) if (a[i] < 0) die("counting sort requires non-negative integers");
    int mx = max_value(a, n);
    size_t k = (size_t)mx + 1;
    int *cnt = (int *)calloc(k, sizeof(int));
    if (!cnt) die("out of memory in counting sort");
    for (size_t i = 0; i < n; ++i) cnt[a[i]]++;
    for (size_t i = 1; i < k; ++i) cnt[i] += cnt[i-1];
    int *out = (int *)xmalloc(sizeof(int) * n);
    for (long long i = (long long)n - 1; i >= 0; --i) {
        int v = a[i];
        out[--cnt[v]] = v;
    }
    for (size_t i = 0; i < n; ++i) a[i] = out[i];
    free(out);
    free(cnt);
}

/* Radix sort (LSD, base 10) for NON-NEGATIVE ints */
static void radix_sort_lsd_base10(int *a, size_t n) {
    if (n == 0) return;
    for (size_t i = 0; i < n; ++i) if (a[i] < 0) die("radix sort requires non-negative integers");

    int *out = (int *)xmalloc(sizeof(int) * n);
    int maxv = max_value(a, n);
    int exp = 1; /* 1, 10, 100, ... */
    while (maxv / exp > 0) {
        int cnt[10] = {0};
        for (size_t i = 0; i < n; ++i) cnt[(a[i] / exp) % 10]++;
        for (int i = 1; i < 10; ++i) cnt[i] += cnt[i-1];
        for (long long i = (long long)n - 1; i >= 0; --i) {
            int d = (a[i] / exp) % 10;
            out[--cnt[d]] = a[i];
        }
        for (size_t i = 0; i < n; ++i) a[i] = out[i];
        exp *= 10;
    }
    free(out);
}

/* ============================================================
   CLI parsing & main
   ============================================================ */

typedef enum {
    ALGO_QUICK, ALGO_MERGE, ALGO_HEAP, ALGO_INSERTION, ALGO_SELECTION, ALGO_COUNTING, ALGO_RADIX
} algo_t;

static const char *algo_name(algo_t a) {
    switch (a) {
        case ALGO_QUICK:     return "quick";
        case ALGO_MERGE:     return "merge";
        case ALGO_HEAP:      return "heap";
        case ALGO_INSERTION: return "insertion";
        case ALGO_SELECTION: return "selection";
        case ALGO_COUNTING:  return "counting";
        case ALGO_RADIX:     return "radix";
        default:             return "?";
    }
}

static void usage(const char *prog) {
    fprintf(stderr,
        "Usage: %s --algo <quick|merge|heap|insertion|selection|counting|radix>\n"
        "          [--stdin] [--size N] [--seed S] [--print] [--verify]\n"
        "\n"
        "Examples:\n"
        "  echo \"5 4 2 9 1 5\" | %s --algo quick --stdin --print --verify\n"
        "  %s --algo heap --size 100000 --verify\n"
        "Notes:\n"
        "  * counting/radix require NON-NEGATIVE integers.\n", prog, prog, prog);
}

int main(int argc, char **argv) {
    if (argc < 3) { usage(argv[0]); return 1; }

    bool from_stdin = false, do_print = false, do_verify = false;
    size_t n = 0;
    unsigned int seed = (unsigned int)time(NULL);
    algo_t algo = ALGO_QUICK;
    bool algo_set = false;

    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "--algo") && i + 1 < argc) {
            ++i;
            if      (!strcmp(argv[i], "quick"))     algo = ALGO_QUICK;
            else if (!strcmp(argv[i], "merge"))     algo = ALGO_MERGE;
            else if (!strcmp(argv[i], "heap"))      algo = ALGO_HEAP;
            else if (!strcmp(argv[i], "insertion")) algo = ALGO_INSERTION;
            else if (!strcmp(argv[i], "selection")) algo = ALGO_SELECTION;
            else if (!strcmp(argv[i], "counting"))  algo = ALGO_COUNTING;
            else if (!strcmp(argv[i], "radix"))     algo = ALGO_RADIX;
            else die("unknown --algo");
            algo_set = true;
        } else if (!strcmp(argv[i], "--stdin")) {
            from_stdin = true;
        } else if (!strcmp(argv[i], "--size") && i + 1 < argc) {
            ++i; n = (size_t)strtoull(argv[i], NULL, 10);
            if (n > ARRAYLEN_MAX) die("size too large");
        } else if (!strcmp(argv[i], "--seed") && i + 1 < argc) {
            ++i; seed = (unsigned int)strtoul(argv[i], NULL, 10);
        } else if (!strcmp(argv[i], "--print")) {
            do_print = true;
        } else if (!strcmp(argv[i], "--verify")) {
            do_verify = true;
        } else {
            usage(argv[0]);
            return 1;
        }
    }

    if (!algo_set) die("please set --algo");
    if (!from_stdin && n == 0) die("provide --stdin or --size N");

    int *a = NULL;
    size_t count = 0;

    if (from_stdin) {
        /* read unknown count from stdin */
        size_t cap = 1024;
        a = (int *)xmalloc(sizeof(int) * cap);
        int v;
        while (scanf("%d", &v) == 1) {
            if (count == cap) {
                cap = cap * 2;
                if (cap > ARRAYLEN_MAX) die("too many numbers from stdin");
                a = (int *)realloc(a, sizeof(int) * cap);
                if (!a) die("out of memory");
            }
            a[count++] = v;
        }
        if (count == 0) die("no integers read from stdin");
    } else {
        /* generate random data (can include negatives except for counting/radix) */
        a = (int *)xmalloc(sizeof(int) * n);
        srand(seed);
        for (size_t i = 0; i < n; ++i) {
            int val = rand(); /* 0..RAND_MAX */
            /* mix negatives for general algos; restrict if counting/radix */
            if (algo == ALGO_COUNTING || algo == ALGO_RADIX) {
                a[i] = val % 100000; /* 0..99999 */
            } else {
                /* spread around signed range: */
                a[i] = (int)((val % 200000) - 100000);
            }
        }
        count = n;
    }

    long long t0 = now_ns();

    switch (algo) {
        case ALGO_QUICK:     quick_sort(a, count);            break;
        case ALGO_MERGE:     merge_sort(a, count);            break;
        case ALGO_HEAP:      heap_sort(a, count);             break;
        case ALGO_INSERTION: insertion_sort(a, count);        break;
        case ALGO_SELECTION: selection_sort(a, count);        break;
        case ALGO_COUNTING:  counting_sort_nonneg(a, count);  break;
        case ALGO_RADIX:     radix_sort_lsd_base10(a, count); break;
        default: die("unhandled algo");
    }

    long long t1 = now_ns();

    if (do_verify) {
        if (!is_sorted(a, count)) {
            fprintf(stderr, "[VERIFY] FAILED: array is not sorted!\n");
            free(a);
            return 2;
        } else {
            fprintf(stderr, "[VERIFY] OK: array is sorted.\n");
        }
    }

    if (do_print) {
        print_array(a, count);
    }

    double ms = (double)(t1 - t0) / 1e6;
    fprintf(stderr, "[%s] n=%zu  time=%.3f ms\n", algo_name(algo), count, ms);

    free(a);
    return 0;
}
