#include "helpers.h"

#define PORT 6969
#define HOST "localhost"

int connectClient(int port, char * host);


/**
 * Connects a client to a server pointed by host at port.
 *
 * Creates a socket and tries to connect to the server with the given hostname at the given port.
 *
 * @param port port of the server.
 * @param host hostname of the server.
 * @return socket file descriptor on sucess, -1 if failed.
 */
int connectClient(int port, char *host){
    int cSocket;
    struct hostent *hp;
    struct sockaddr_in cAddr;

    if ((hp = gethostbyname(host)) == NULL)
        return -1; 
    bzero(&cAddr, sizeof(cAddr));
    cAddr.sin_family      = AF_INET;
    cAddr.sin_port        = htons(port);
    bcopy((char *) hp->h_addr, 
          (char *) &cAddr.sin_addr.s_addr, hp->h_length);

    /**
     * Your code here
     */
    
    return -1; //delete this line when you start your implementation

    return cSocket;

}

int main(int argc, char**argv){

    char buf[1024];
    int cSocket, bytesRead;

    if ((argc != 2) || (strspn(argv[1],"0123456789") != strlen(argv[1]))){
        fprintf(stderr, "Usage: %s <Milliseconds>\n", argv[0]);
	    exit(1);
    }

    cSocket = connectClient(PORT,HOST);
    assert(cSocket>-1);

    /**
     * Your code here
     */

    return -1; //delete this line when you start your implementation

    assert(close(cSocket)==0);
    return 0;

}