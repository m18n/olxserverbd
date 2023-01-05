#pragma once
#include"../client/include/client.h"
extern cl_client_t cl_olxusersdb;

#define STATUS_OK 102
#define STATUS_NOT_AUTH 101
typedef struct RES_olxusersdb_auth{
    cl_packres_t pack;
    char authcode[200];
}RES_olxusersdb_auth_t;
void CreateRES_olxusersdb_auth(RES_olxusersdb_auth_t* auth);
cl_json_construct_t RES_olxusersdb_auth_getjson(RES_olxusersdb_auth_t* auth);
typedef struct RES_olxusersdb_checkauth{
    cl_packres_t pack;
    char name[100];
    char password[20];
}RES_olxusersdb_checkauth_t;
void CreateRES_olxusersdb_checkauth(RES_olxusersdb_checkauth_t* setdb);
cl_json_construct_t RES_olxusersdb_checkauth_getjson(RES_olxusersdb_checkauth_t* setdb);
typedef struct REQ_olxusersdb_status{   
    cl_packreq_t pack;
    int code;
}REQ_olxusersdb_status_t;
void CreateREQ_olxusersdb_status(REQ_olxusersdb_status_t* status);
bool REQ_olxusersdb_status_jsontoobject(REQ_olxusersdb_status_t* status,json_value* values);
void REQ_olxusersdb_status_process(REQ_olxusersdb_status_t* status);
void R_setdb(REQ_olxusersdb_status_t *status,void* data);
void R_auth(REQ_olxusersdb_status_t *status,void* data);
void OlxUsersDbConnect();
void Init_olxusersdb_REQPack();