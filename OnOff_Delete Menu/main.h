extern "C"
{
  int pg_Generic_Delete(void *mess, BOOK *bk);
  int pg_MarkSeveral_Delete(void *mess, BOOK *bk);
  int pg_Directory_Delete(void *mess, BOOK *bk);
};

#define PATCH_ONOFF_ID L"DeleteProtection_Id"

#define INTERNAL_VAR "DeLeTe_Function"
#define FREE_GUI(a) if (a) a=GUIObject_Destroy(a)

typedef struct 
{
  int gen_del;
  int mar_del;
  int dir_del;
  int del_pas;
}DeLeTe_Function;

typedef struct
{
  int gen_del;
  int mar_del;
  int dir_del;
}DeLeTe_File_Function;

typedef struct _MyBOOK : BOOK
{
  int item_ID;
  GUI_LIST* list_menu;
}MyBOOK;
