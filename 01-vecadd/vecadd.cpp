#include <hip/hip_runtime.h>
#include <cstdio>
#include <vector>

#define HIP_CHECK(cmd)                                                                  \
    do {                                                                                \
        hipError_t e = (cmd);                                                           \
        if (e != hipSuccess) {                                                          \
            printf("Erreur HIP : %s (ligne %d)\n", hipGetErrorString(e), __LINE__);     \
            return 1;                                                                   \
        }                                                                               \
    } while (0)

// Le kernel : chaque thread additionne un élément
__global__ void vecadd(const float* a, const float* b, float* c, int n) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n) {
        c[i] = a[i] + b[i];
    }
}

int main() {
    const int n = 1 << 20;  // ~1 millions d'éléments
    size_t bytes = n * sizeof(float);

    std::vector<float> a(n, 1.0f);
    std::vector<float> b(n, 2.0f);
    std::vector<float> c(n, 0.0f);

    // Pointeurs vers la mémoire du GPU
    float *da, *db, *dc;
    HIP_CHECK(hipMalloc(&da, bytes));
    HIP_CHECK(hipMalloc(&db, bytes));
    HIP_CHECK(hipMalloc(&dc, bytes));

    HIP_CHECK(hipMemcpy(da, a.data(), bytes, hipMemcpyHostToDevice));
    HIP_CHECK(hipMemcpy(db, b.data(), bytes, hipMemcpyHostToDevice));

    int threads = 256;      // threads par bloc
    int blocks = (n + threads - 1) / threads;
    vecadd<<<blocks, threads>>>(da, db, dc, n);
    HIP_CHECK(hipGetLastError());

    HIP_CHECK(hipMemcpy(c.data(), dc, bytes, hipMemcpyDeviceToHost));

    int errors = 0;
    for (int i = 0; i < n; i++) {
        if (c[i] != 3.0f) {
            errors++;
        }
    }

    if (errors == 0) {
        printf("OK : %d éléments corrects\n", n);
    } else {
        printf("%derreurs\n", errors);
    }

    HIP_CHECK(hipFree(da));
    HIP_CHECK(hipFree(db));
    HIP_CHECK(hipFree(dc));
}