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
    struct msgbuff sendbuff, recvbuff;
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

    

    sendbuff.type = 1;


    while ( strcmp( sendbuff.text, "quit\n" ) != 0 ) {
        memset( sendbuff.text, 0, 128 );
        // 表示從使用者鍵盤中讀資料，讀128bytes到sendbuff.text中
        fgets( sendbuff.text, 128, stdin );

        // 傳送數據到msg中
        // 第一個參數代表msg的id
        // 第二個參數代表一種struct，內容必須要有一個long型別的變數代表數據類型，還有要傳送的內容
        // 第三個參數是要傳送的內容大小( 不包含long )
        // 第四個參數則是傳送數據的模式，0代表阻塞模式，IPC_NOWAIT代表沒有傳送數據函數也會返回
        msgsnd( msgid, ( void * )&sendbuff, strlen( sendbuff.text ), 0 );
        printf( "text is %s\n", sendbuff.text );

    } // while

    
    msgctl( msgid, IPC_RMID, NULL );
    
    return 0;
} // int