#include "helpers.h"

#define PORT 6969

void *clientHandler(void *cSocket);
int startListen(int port);

/**
 * Handle client request.
 *
 * Handles a client request by simulating an I/O request.
 * Reads the milliseconds passed by the client and sleeps for that ammount of time.
 * Upon waking up, writes back to the client to signal that the request is finished.
 *
 * @param pcSocket pointer (of type void to appease pthread create) to a clientsocket.
 * @return NULL.
 */
void *clientHandler(void *pcSocket){
    char buffer[1024];
    int rc;
    int cSocket = *(int *)pcSocket;
    if((rc = read((int)cSocket,buffer,sizeof(buffer)) == -1)){
        perror("Server read");
        close(cSocket);
        return NULL;
    }

    if (strspn(buffer,"0123456789") != strlen(buffer)){
        perror("Not a number");
        close(cSocket);
        return NULL;
    }

    long time = atol(buffer);
    printf("now serving client %d\n",cSocket);
    fflush(stdout);
    msleep(time);
    printf("Finshed working with client %d\n",cSocket);
    fflush(stdout);
    sprintf(buffer,"Finished %d",cSocket);
    write(cSocket,buffer,12);
    close(cSocket);
    memset(buffer,0,sizeof(buffer));
    return NULL;
}



/**
 * Create a server connection.
 *
 * Creates a socket and prepares it to start listening for incomming connections.
 *
 * @param port port that is prepared to listen to connections.
 * @return socket file descriptor on sucess, -1 if failed.
 */
int startListen(int port){
    int sSocket;
    struct sockaddr_in sAddr;

    bzero(&sAddr, sizeof(sAddr));
    sAddr.sin_family      = AF_INET;
    sAddr.sin_port        = htons(port);
    sAddr.sin_addr.s_addr = INADDR_ANY;

    /**
     * Your code here
     */

    return -1; //delete this line when you start your implementation

    return sSocket;

}


int main(int argc, char**argv){

    printf("Opening socket\n");
    int sSocket = startListen(PORT);
    assert(sSocket>-1);

    /**
     * Your code here
     */

    return 0;    

}