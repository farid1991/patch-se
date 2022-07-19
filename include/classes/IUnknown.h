#ifndef _IUNKNOWN_H_
#define _IUNKNOWN_H_

class IUnknown
{
public:
  virtual void *pguid();
  virtual void *QueryInterface(PUUID iid, void **pInterface);
  virtual void *AddRef();
  virtual void *Release();
};

class IShell : public IUnknown
{
public:
  virtual int AllocateMemory(uint32_t Size, void **pBuffer);
  virtual int CreateMsg();
  virtual int CompareUUID(PUUID iid1, PUUID iid2);
  virtual int FreeMsg();
  virtual int CreateInstance(PUUID cid, PUUID iid, void **ppInterface);
  virtual int FreeMemory(void **ppBuffer);
  virtual int MarkInterfacesInMsg();
  virtual int ReallocateMemory();
  virtual int ReleaseInterfacesInMsg();
  virtual int IsKindOfInterface();
  virtual int InvalidateCallbackInterface();
  virtual int GetCallerExecutionShell(IUnknown** ppIExecutionShell);
};

#endif
