#ifndef _ISHELL_H_
#define _ISHELL_H_

class IShell: public IUnknown
{
public:
  virtual int AllocateMemory(int Size, void** ppBuffer); 
  virtual int CreateMsg(int Base, int Id, int Size, void **ppMsg); 
  virtual bool CompareUUID(UUID* pIID1, UUID* pIID2); 
  virtual int FreeMsg(void** ppMsg);  
  virtual int CreateInstance(UUID* pCid, UUID* pIid, void** ppInterfacePointer);
  virtual int FreeMemory(void** ppBuffer);
  virtual int MarkInterfacesInMsg(void** ppMsg, void** ppInterfacePointer);
  virtual int ReallocateMemory(int Size, void** ppBuffer);
  virtual int ReleaseInterfacesInMsg(void** ppMsg);
  virtual bool IsKindOfInterface(IUnknown* pInterface, UUID* pIId);
  virtual int InvalidateCallbackInterface(IUnknown* pICB);
  virtual int GetCallerExecutionShell(IUnknown** ppIExecutionShell);
};

#endif
