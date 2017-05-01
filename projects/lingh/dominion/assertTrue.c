#include "assertTrue.h"

int assertTrue(int a, int b) {
    if (a == b) {
        printf("PASS\n");
        return 1;
    } else {
        printf("FAIL\n");
        return 0;
    }
}
