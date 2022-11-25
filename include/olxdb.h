#pragma once
#include"../client/include/client.h"
extern cl_client_t cl_olxdb;
void OlxDbConnect();

typedef struct RES_olxdb_auth{
    cl_packres_t pack;
    char authcode[200];
}RES_olxdb_auth_t;
void CreateRES_olxdb_auth(RES_olxdb_auth_t* auth);
cl_json_construct_t RES_olxdb_auth_getjson(RES_olxdb_auth_t* auth);
typedef struct REQ_olxdb_status{   
    cl_packreq_t pack;
    int code;
}REQ_olxdb_status_t;
void CreateREQ_olxdb_status(REQ_olxdb_status_t* status);
bool REQ_olxdb_status_jsontoobject(REQ_olxdb_status_t* status,json_value* values);
void REQ_olxdb_status_process(REQ_olxdb_status_t* status);
void Init_olxdb_REQPack();