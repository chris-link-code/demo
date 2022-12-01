#include <stdio.h>
#include <time.h>
#include <sys/time.h>

#include "md5.h"

long long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL); // get current time
    long long milliseconds = te.tv_sec * 1000LL + te.tv_usec / 1000; // calculate milliseconds
    // printf("milliseconds: %lld\n", milliseconds);
    return milliseconds;
}


int main() {
    printf("Hello, World!\n");

    int value = 10;
    int *p;              // 定义指针变量
    p = &value;

    printf("value 变量的地址： %p\n", p);
    printf("value 变量的值： %d\n", *p);
    printf("value 变量的值： %d\n", value);

    /**
        预定义宏
        ANSI C 定义了许多宏。在编程中您可以使用这些宏，但是不能直接修改这些预定义的宏。
        __DATE__	当前日期，一个以 "MMM DD YYYY" 格式表示的字符常量。
        __TIME__	当前时间，一个以 "HH:MM:SS" 格式表示的字符常量。
        __FILE__	这会包含当前文件名，一个字符串常量。
        __LINE__	这会包含当前行号，一个十进制常量。
        __STDC__	当编译器以 ANSI 标准编译时，则定义为 1。
    */
    printf("File :%s\n", __FILE__);
    printf("Date :%s\n", __DATE__);
    printf("Time :%s\n", __TIME__);
    printf("Line :%d\n", __LINE__);
    printf("ANSI :%d\n", __STDC__);

    int a = 0;
    for (int i = 0; i < 10; ++i) {
        a += i;
    }
    printf("a is %d", a);


    int arr[] = {10, 100, 200};
    int const MAX = 5;
    for (int i = 0; i < MAX; i++) {
        printf("Value of arr[%d] = %d\n", i, arr[i]);
    }
    int *p_arr[MAX];
    for (int i = 0; i < MAX; i++) {
        p_arr[i] = &arr[i]; /* 赋值为整数的地址 */
    }
    for (int i = 0; i < MAX; i++) {
        printf("Value of arr[%d] = %d, pointer is %d\n", i, *p_arr[i], p_arr[i]);
    }

    printf("\n================== MD5 Message-Digest Algorithm ==================\n\n");
    printf("[INPUT] Enter the filepath: ");

    printf("Time :%s\n", __TIME__);

    long start = current_timestamp();

    // 输入文件路径
//    char filepath[256] = "/Users/chris/Movies/player.mkv";
    char filepath[256] = "C:/File/temporary/s.rmvb";
    //scanf("%s", filepath);

    // 128位结果
    uint8_t result[16];
    int i;

    // 返回值不等于1表示有错误
    if (MD5(filepath, result) == 1) {
        printf("\n[INFO] The result is: ");

        //将字节通过无符号十六进制输出
        for (i = 0; i < 16; i++) {
            printf("%2.2x", result[i]);
        }
        printf("\n");
    }

    printf("Time :%s\n", __TIME__);
    long end = current_timestamp();
    printf("end %d", (end - start));
    //system("pause");
    return 0;
}