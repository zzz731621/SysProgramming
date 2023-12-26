#include <stdio.h>

void mylib( void ) {
    printf( "This is mylib!\n" );
} // void


// 要先編譯成.o文件
// 命令為"gcc -c -fpic mylib.c"
// 之後同樣使用gcc命令來生成動態庫lib開頭.so結尾
// 命令為"gcc -shared -o libmylib.so mylib.o"，就會生成動態庫