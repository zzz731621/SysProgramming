#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <signal.h>
#include <string.h>

struct msgbuff {
    long type;
    char text[128];
};

int main( int argc, char *argv[] ) {
    int msgid;
    int readret;
    struct msgbuff recvbuff;
    key_t key;


    key = ftok( "./a.c", 'a' );

    // 創建message queue
    // 第一個參數為key，IPC_PRIVATE是0，也可以使用ftok和shm一樣的用法 
    // 第二個參數為權限
    msgid = msgget( key, 0777 | IPC_CREAT );
    if ( msgid == -1 ) {
        perror( "create message queue failure!\n" );
        return -1;
    } // if
    printf( "create message queue success msgid = %d\n", msgid );

    

    recvbuff.type = 1;


    while ( strcmp( recvbuff.text, "quit\n" ) != 0 ) {
        memset( recvbuff.text, 0, 128 );

        // 從msg中讀取數據
        // 第一個參數代表msg的id
        // 第二個參數代表一種struct，內容必須要有一個long型別的變數代表數據類型，還有要傳送的內容
        // 第三個參數是要讀取的內容大小( 不包含long )
        // 第四個參數用來過濾數據，0代表讀取msg中的第一個數據，大於0代表讀取msg中的第一個類型為msgtyp的數據，小於0代表讀取msg中的第一個類型小於等於msgtyp的數據
        // 第五個參數則是讀取數據的模式，0代表阻塞模式，IPC_NOWAIT代表沒有傳送數據函數也會返回
        msgrcv( msgid, ( void * )&recvbuff, 128, 0, 0 );
        printf( "msg type is %ld, test is %s\n", recvbuff.type, recvbuff.text );
    } // while


    return 0;
} // int