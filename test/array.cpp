#include "common.h"

int main () {
    int *array = new int[50]; // 分配200个字节的内存

    int **a2d = new int *[50];  // 分配200个字节的内存，50个指针
    // 可以遍历并设置每一个指针指向的数组
    for (int i = 0; i < 50; i++) {
        a2d[i] = new int[50];
    }
    // delete
    for (int i = 0; i < 50; i++) {
        delete[] a2d[i];
    }
    delete[] a2d;

    int ***a3d = new int **[50];
    for (int i = 0; i < 50; i++) {
        a3d[i] = new int *[50];
        for (int j = 0; j < 50; j++) {
            a3d[i][j] = new int[50];
        }
    }

    // 访问
    a3d[0][0][0] = 0;
    // a3d[0] 指针的指针的数组
    // a3d[0][0] 指针的数组
    // a3d[0][0][0] 整数

    //delete
    for (int i = 0; i < 50; i++) {

        for (int j = 0; j < 50; j++) {
            delete[] a3d[i][j];
        }
        delete[] a3d[i];
    }

    return 0;
}