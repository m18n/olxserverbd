#include"olxusersdb.h"
cl_client_t cl_olxusersdb;

void CreateRES_olxusersdb_auth(RES_olxusersdb_auth_t* auth){
    cl_CreatePackRes(&auth->pack);
    auth->pack.GetJsonPack=RES_olxusersdb_auth_getjson;
    auth->pack.idpack=1;
}
cl_json_construct_t RES_olxusersdb_auth_getjson(RES_olxusersdb_auth_t* auth){
    cl_json_construct_t json;
    cl_CreateJson_Construct(&json);
    cl_json_item_t authcode;
    cl_CreateJson_Item(&authcode);
    cl_json_item_setname(&authcode,"authcode");
    cl_json_item_setstrvalue(&authcode,auth->authcode);
    cl_json_construct_addelement(&json,authcode);
    return json;
}
void CreateRES_olxusersdb_checkauth(RES_olxusersdb_checkauth_t* setdb){
    cl_CreatePackRes(&setdb->pack);
    setdb->pack.GetJsonPack=RES_olxusersdb_checkauth_getjson;
    setdb->pack.idpack=3;
}
cl_json_construct_t RES_olxusersdb_checkauth_getjson(RES_olxusersdb_checkauth_t* auth){
    cl_json_construct_t json;
    cl_CreateJson_Construct(&json);
    cl_json_item_t name;
    cl_CreateJson_Item(&name);
    cl_json_item_setname(&name,"name");
    cl_json_item_setstrvalue(&name,auth->name);
    cl_json_construct_addelement(&json,name);
    cl_json_item_t password;
    cl_CreateJson_Item(&password);
    cl_json_item_setname(&password,"password");
    cl_json_item_setstrvalue(&password,auth->password);
    cl_json_construct_addelement(&json,password);
    return json;
}
void CreateREQ_olxusersdb_status(REQ_olxusersdb_status_t* status){
    cl_CreatePackReq(&status->pack);
    status->pack.JsonToObject=REQ_olxusersdb_status_jsontoobject;
    status->pack.ProcessPack=REQ_olxusersdb_status_process;
    status->code=-1;
}
bool REQ_olxusersdb_status_jsontoobject(REQ_olxusersdb_status_t* status,json_value* values){
    json_object_entry* jcode=cl_GetNameKey(values,"code");
    if(jcode!=NULL&&jcode->value->type==json_integer){
        status->code=jcode->value->u.integer;
        return true;
    }
    return false;
}
void REQ_olxusersdb_status_process(REQ_olxusersdb_status_t* status){
    printf("STATUS: %d\n",status->code);
}
void Init_olxusersdb_REQPack(){
    cl_client_adduserpacks(&cl_olxusersdb,CreateREQ_olxusersdb_status,sizeof(REQ_olxusersdb_status_t),2);
}
void R_setdb(REQ_olxusersdb_status_t *status,void* data){
    if(status->code==STATUS_OK){
        printf("GOOD DATABASE\n");
    }else if(status->code==1){
        printf("ERROR FOUND DATABASE\n");
    }
}
void R_auth(REQ_olxusersdb_status_t *status,void* data){
    if(status->code==STATUS_OK){
        RES_olxusersdb_checkauth_t checkauth;
        CreateRES_olxusersdb_checkauth(&checkauth);
        strcpy(checkauth.name,"misha");
        strcpy(checkauth.password,"123");
        cl_SendPack(&cl_olxusersdb,&checkauth,R_setdb,NULL);
        printf("GOOD AUTH\n");
    }
}
void OlxUsersDbConnect(){
    cl_InitClient(&cl_olxusersdb);
    Init_olxusersdb_REQPack();
    if(cl_ClientConnect(&cl_olxusersdb,"192.168.0.105",9997)==0){
        printf("CONNECT OLX DB\n");
        RES_olxusersdb_auth_t authdb;
        CreateRES_olxusersdb_auth(&authdb);
        strcpy(&authdb.authcode,"niger");
        cl_SendPack(&cl_olxusersdb,&authdb,R_auth,NULL);
    }
}