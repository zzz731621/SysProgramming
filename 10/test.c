#include <stdio.h>

// 聲明函數
void mylib( void );

int main( void ) {
    mylib();
    return 0;
} // int


// 編譯測試文件時要用"-l mylib.a"來鏈結靜態庫，名稱不用包括開頭的lib和結尾的.a
// 並且要用"-L 路徑"來指定庫所在位置
// gcc test.c -lmylib.a -L .