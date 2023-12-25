#include <stdio.h>

void mylib( void ) {
    printf( "This is mylib!\n" );
} // void


// 要先編譯成.o文件
// 在來使用ar命令來製作出靜態庫lib.a，以lib開頭.a結尾
// 命令為"ar cr libmylib.a mylib.o"