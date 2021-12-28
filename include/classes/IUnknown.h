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
  virtual int method1();
  virtual int method2();
  virtual int method3();
  virtual int IShell_CreateInstance(PUUID cid, PUUID iid, void **pInterface);
};

#endif
