#include "..\\include\Types.h"
#include "..\\include\Function.h"

struct GET_SIGNAL_QUALITY_SIGNAL
{
  SIGSELECT signo;
  int null;
  char unk_er;
  char rssi;
  char ber;
  char error_cause;
};

union SIGNAL
{
  SIGSELECT signo;
  struct GET_SIGNAL_QUALITY_SIGNAL hsig;
};

int GetSignalQuality_dll( char * rssi, char * ber )
{
  static const SIGSELECT sg[]={1,GetSignalQuality_Receive_SignalID};
  char res=0;
  PROCESS pid;
  
  hunt("LNH_ACC_SIDE/SL_Process",0,&pid,0);
  union SIGNAL * mem = alloc(8,GetSignalQuality_Send_SignalID);
  mem->hsig.null=0;
  send(&mem,pid);
  union SIGNAL * rec_buf = receive(sg);
  if (rec_buf->signo==GetSignalQuality_Receive_SignalID)
  {
    rssi[0]=rec_buf->hsig.rssi;
    ber[0]=rec_buf->hsig.ber;
    res=rec_buf->hsig.unk_er;
  }
  free_buf(&rec_buf);
  return(res);
}
