/*
;G502 SW-R1FA037
;add digital key's management to the SMS list
;1:next
;2:reply
;3:previous
;4:previous 4 items
;5:view
;6:next 4 items
;7:previous 20 items
;8:forward
;9:next 20 items
;*:go to the first
;#:go to the last
;(c) rong862
;(e) farid
*/

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#define IPTVARNAME "sms"

typedef struct
{
  DISP_OBJ_ONKEY_METHOD oldOnKey;
  DISP_OBJ_ONKEY_METHOD oldOnKey1;
}NUMKEY;

__thumb void * malloc (int size)
{
  return(memalloc(0xFFFFFFFF,size,1,5,IPTVARNAME,0));
}

__thumb void mfree (void * mem)
{
  if (mem) memfree(0, mem,IPTVARNAME,0);
}

void myOnKey(DISP_OBJ *disp, int key, int unk, int repeat_num, int mode)
{
  NUMKEY *nkey = (NUMKEY*)get_envp(get_bid(current_process()),IPTVARNAME);
  
  GUI_LIST *menu = (GUI_LIST*) DispObject_GetGUI(disp);
  int cur = ListMenu_GetSelectedItem(menu);
  if (key == KEY_1 && mode == KBD_SHORT_PRESS)//1
  {
   if(cur > 0) ListMenu_SetCursorToItem(menu,cur - 1);
   else ListMenu_SetCursorToItem(menu,ListMenu_GetItemCount(menu));
  }
  else if (key == KEY_2 && mode == KBD_SHORT_PRESS)//2
  {
    GUIObject_SoftKeys_ExecuteAction(menu,ACTION_REPLY);
  }
  if (key == KEY_3 && mode == KBD_SHORT_PRESS)//3
  {
   if(cur < ListMenu_GetItemCount(menu) - 1) ListMenu_SetCursorToItem(menu,cur + 1);
   else ListMenu_SetCursorToItem(menu,0);
  }
  else if (key == KEY_4 && mode == KBD_SHORT_PRESS)//4
  {
    if(cur > 3) ListMenu_SetCursorToItem(menu,cur - 4);
  }
  else if (key == KEY_5 && mode == KBD_SHORT_PRESS)//5
  {
    GUIObject_SoftKeys_ExecuteAction(menu,ACTION_VIEW);
  }
  else if (key == KEY_6 && mode == KBD_SHORT_PRESS)//6
  {
    if(cur < ListMenu_GetItemCount(menu)-4) ListMenu_SetCursorToItem(menu,cur + 4);
  }
  else if (key == KEY_7 && mode == KBD_SHORT_PRESS)//7
  {
    if(cur > 19) ListMenu_SetCursorToItem(menu,cur - 20);
   else ListMenu_SetCursorToItem(menu,0);
  }
  else if(key == KEY_8 && mode == KBD_SHORT_PRESS)//8
  {
    GUIObject_SoftKeys_ExecuteAction(menu,ACTION_FORWARD);
  }
  else if (key == KEY_9 && mode == KBD_SHORT_PRESS)//9
  {
    if(cur < ListMenu_GetItemCount(menu) - 20) ListMenu_SetCursorToItem(menu,cur + 20);
    else ListMenu_SetCursorToItem(menu,ListMenu_GetItemCount(menu));
  }
  else if (key == KEY_STAR && mode == KBD_SHORT_PRESS)//*
  {
    ListMenu_SetCursorToItem(menu,0);
  }
  else if (key == KEY_DIEZ && mode == KBD_SHORT_PRESS)//#
  {
    ListMenu_SetCursorToItem(menu,ListMenu_GetItemCount(menu));
  }
  else nkey->oldOnKey(disp,key,unk,repeat_num,mode);
}

extern "C"
void SetNewKey(GUI * sms)
{
  DISP_OBJ *disp = GUIObject_GetDispObject(sms);
  NUMKEY *nkey = (NUMKEY*)get_envp(get_bid(current_process()),IPTVARNAME);
  if(nkey) mfree(nkey);

  nkey = (NUMKEY*)malloc(sizeof(NUMKEY));
  memset(nkey,0,sizeof(NUMKEY));
  set_envp(get_bid(current_process()),IPTVARNAME,(OSADDRESS)nkey);
  
  nkey->oldOnKey=DispObject_GetOnKey(disp);
  DISP_DESC_SetOnKey(DispObject_GetDESC(disp),myOnKey);
}
