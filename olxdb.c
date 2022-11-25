#include"olxdb.h"
cl_client_t cl_olxdb;
void OlxDbConnect(){
    cl_InitClient(&cl_olxdb);
    Init_olxdb_REQPack();
    if(cl_ClientConnect(&cl_olxdb,"192.168.0.105",9997)==0){
        printf("CONNECT OLX DB\n");
        RES_olxdb_auth_t authdb;
        CreateRES_olxdb_auth(&authdb);
        strcpy(&authdb.authcode,"niger");
        cl_SendPack(&cl_olxdb,&authdb,NULL,NULL);
    }
}
void CreateRES_olxdb_auth(RES_olxdb_auth_t* auth){
    cl_CreatePackRes(&auth->pack);
    auth->pack.GetJsonPack=RES_olxdb_auth_getjson;
    auth->pack.idpack=1;
}
cl_json_construct_t RES_olxdb_auth_getjson(RES_olxdb_auth_t* auth){
    cl_json_construct_t json;
    cl_CreateJson_Construct(&json);
    cl_json_item_t authcode;
    cl_CreateJson_Item(&authcode);
    cl_json_item_setname(&authcode,"authcode");
    cl_json_item_setstrvalue(&authcode,auth->authcode);
    cl_json_construct_addelement(&json,authcode);
    return json;
}
void CreateREQ_olxdb_status(REQ_olxdb_status_t* status){
    cl_CreatePackReq(&status->pack);
    status->pack.JsonToObject=REQ_olxdb_status_jsontoobject;
    status->pack.ProcessPack=REQ_olxdb_status_process;
    status->code=-1;
}
bool REQ_olxdb_status_jsontoobject(REQ_olxdb_status_t* status,json_value* values){
    json_object_entry* jcode=cl_GetNameKey(values,"code");
    if(jcode!=NULL&&jcode->value->type==json_integer){
        status->code=jcode->value->u.integer;
        return true;
    }
    return false;
}
void REQ_olxdb_status_process(REQ_olxdb_status_t* status){
    printf("STATUS: %d\n",status->code);
}
void Init_olxdb_REQPack(){
    cl_client_adduserpacks(&cl_olxdb,CreateREQ_olxdb_status,sizeof(REQ_olxdb_status_t),2);
}