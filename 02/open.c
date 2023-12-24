#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main( int argc, char *argv[] ) {
    
    int fd;
    // 第二個參數為flag
    // O_CREAT代表創建一個文件，O_RDWR代表給他可讀可寫的權限
    // 0666就代表對應可讀可寫的8進位數字
    // 用3個bit來表示，001代表可執行，100代表可讀，010代表可寫，可讀可寫就為110
    // 而最左邊的6代表目前檔案擁有者的權限
    // 中間的代表與檔案擁有者同一個用戶組的權限
    // 右邊表示其他用戶組的權限
    // 三個都為可讀可寫就是666
    // 而系統會對使用者創建的檔案做處理
    // 權限會與mask做邏輯運算
    // mode & ~( umask )
    // 輸入umask可以查看是多少 ，輸入後查看為002
    // 所以結果等於 0666 & 0775
    // 最後等於0664，也就是-rw-rw-r--
    // 數字前面的0代表8進位
    fd = open( "a.c", O_CREAT | O_RDWR, 0666 );

    // open函數可以有2個或3個參數，只有當第二個參數有某些值時、例如O_CREAT，才會需要第三個
    if ( fd == -1 ) {
        perror( "open file error!\n" );
    } // if
    printf( "fd is : %d\n", fd );

    return 0;
} // int