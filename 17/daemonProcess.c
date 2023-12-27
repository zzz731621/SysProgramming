#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>

int main( int argc, char *argv[] ) {
    pid_t pid;



    // daemon process是運行在後台，且不跟任何控制終端關聯的process
    // 有兩個基本要求，1. 必須為init process的children process 2. 不跟控制終端關聯
    // 所以可以使用fork創建一個process，然後讓parent process使用exit直接退出
    // 再來調用setsid，使該process擺脫原本從parent process複製的process group和session和控制終端
    // 並創建一個新的session使該process成為session的leader

    // 一個session可包含多個process group，一個process group可以包含多個process
    // 每個session/PG都會有一個leader，通常是該群集中第一個process
    // 每個session/PG都會有一個id，由該群集中第一個process的PID決定
    // 每個session可以配給一個terminal
    // 一個session中，terminal會被attach到其中一個process group
    // 被attach terminal的process group給名詞叫foreground process group
    // 其他的對應為background process group

    pid = fork();

    // 若創建失敗則回傳-1
    if ( pid < 0 ) {
        printf( "fork error" );
    } // if


    // 在parent process中會回傳children process的pid
    if ( pid > 0 ) {
        // 讓parent process直接退出
        exit( 0 );
    } // if
    

    // 在children process中會回傳0
    if ( pid == 0 ) {
        // 使children process擺脫從parent process複製的控制終端、pg和session
        setsid();



        /* 以下步驟都不一定要執行也可以創建一個daemon process */

        // 移動目錄到根目錄，避免在usb或掛載的資料夾中執行
        chdir( "/" );

        // 設置umask為0，使程式更靈活，不會受到權限限制
        // 一般來說為022或002，保護user創建的文件，來限制相同用戶組或其他用戶組的寫權限
        umask( 0 );

        // 關閉為0 1 2的三個fd，來減少資源使用
        close( 0 );
        close( 1 );
        close( 2 );

        /* 以上步驟都不一定要執行也可以創建一個daemon process */


        // 要執行任務的code
        while ( 1 );

        // 執行後可以發現，即使有一個無限循環的while，也不會佔用我們的終端
        // 可以使用ps aux去找，也可以看到他正在執行
    } // if



    return 0;
} // int