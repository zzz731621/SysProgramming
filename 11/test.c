#include <stdio.h>

// 聲明函數
void mylib( void );

int main( void ) {
    mylib();
    return 0;
} // int

// 跟靜態庫一樣
// 編譯測試文件時要用"-l mylib.a"，名稱不用包括開頭的lib和結尾的.a
// 並且要用"-L 路徑"來指定庫所在位置
// gcc test.c -lmylib.a -L .
// 但運行時會出錯，因為系統默認會去/lib和/usr/lib去找庫文件
// 所以可以透過新增環境變數"export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/庫所在位置"，但只對當前terminal有效
// 以及可以直接將剛剛生成的動態庫複製到/lib和/usr/lib
// 或是直接去修改/etc/ld.so.conf，在裡面加入動態庫的位置，然後使用ldconfig更新，必須要用root權限