#pragma once
#include"../client/include/client.h"
extern cl_client_t cl_olxdb;

#define STATUS_OK 102
#define STATUS_NOT_AUTH 101
typedef struct RES_olxdb_auth{
    cl_packres_t pack;
    char authcode[200];
}RES_olxdb_auth_t;
void CreateRES_olxdb_auth(RES_olxdb_auth_t* auth);
cl_json_construct_t RES_olxdb_auth_getjson(RES_olxdb_auth_t* auth);
typedef struct RES_olxdb_setdb{
    cl_packres_t pack;
    char database[100];
}RES_olxdb_setdb_t;
void CreateRES_olxdb_setdb(RES_olxdb_setdb_t* setdb);
cl_json_construct_t RES_olxdb_setdb_getjson(RES_olxdb_setdb_t* setdb);
typedef struct REQ_olxdb_status{   
    cl_packreq_t pack;
    int code;
}REQ_olxdb_status_t;
void CreateREQ_olxdb_status(REQ_olxdb_status_t* status);
bool REQ_olxdb_status_jsontoobject(REQ_olxdb_status_t* status,json_value* values);
void REQ_olxdb_status_process(REQ_olxdb_status_t* status);
void R_setdb(REQ_olxdb_status_t *status,void* data);
void R_auth(REQ_olxdb_status_t *status,void* data);
void OlxDbConnect();
void Init_olxdb_REQPack();