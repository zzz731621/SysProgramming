#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

int main( int argc, char *argv[] ) {
    int ret;
    DIR *dp;

    // 用來接收readdir回傳的值
    struct dirent *dir;

    if ( argc != 2 ) {
        printf( "Usage:%s <name file> \n", argv[0] );
        return -1;
    } // if

    // 回傳一個DIR類型的指標
    // 若開啟失敗會為NULL
    dp = opendir( argv[1] );
    if ( dp ==  NULL ) {
        printf( "opendir error!\n" );
        return -2;
    } // if



    // 將路徑下的所有文件印出來
    // 這個路徑下雖然只能看到a.c
    // 但是還有"."和".."，分別代表當前路徑和上一層路徑
    while ( 1 ) {
        dir = readdir( dp );
        if ( dir == NULL ) {
            break;
        } // if

        // 印出文件名稱
        printf( "Filename is : %s\n", dir->d_name );
    } // while

    closedir( dp );
    return 0;
} // int