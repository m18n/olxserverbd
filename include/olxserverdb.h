#pragma once
#include"../server/include/server.h"
#include"olxdb.h"
typedef struct dbclient{
    sv_user_t client;
    bool auth;
}dbclient_t;
void CreateDBClient(dbclient_t* db);
void ClearDBClient(dbclient_t* db);
typedef struct RES_status{
    sv_packres_t pack;
    int code;
}RES_status_t;
void CreateRES_status(RES_status_t* status);
sv_json_construct_t RES_status_getjson(RES_status_t* pk);
typedef struct REQ_auth{
    sv_packreq_t pack;
    char authcode[200];
}REQ_auth_t;
void CreateREQ_auth(REQ_auth_t* auth);
bool REQ_auth_jsontoobject(REQ_auth_t* auth,json_value* values);
void REQ_auth_process(REQ_auth_t* auth,sv_user_t* user);

typedef struct REQ_authclient{
    sv_packreq_t pack;
    char name[100];
    char password[20];
}REQ_authclient_t;
void CreateREQ_authclient(REQ_authclient_t* auth);
bool REQ_authclient_jsontoobject(REQ_authclient_t* auth,json_value* values);
void REQ_authclient_process(REQ_authclient_t* auth,sv_user_t* user);

void InitREQPack(sv_server_t* server);