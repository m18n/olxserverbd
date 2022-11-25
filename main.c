#include"olxserverdb.h"
int main(){
    printf("HELLO SERVER START BD\n");
    OlxDbConnect();
    sv_server_t serv;
    sv_ServerInit(&serv,9998,10);
    InitREQPack(&serv);
    sv_ServerStart(&serv,sizeof(dbclient_t),CreateDBClient,ClearDBClient);
   
    return 0;
}