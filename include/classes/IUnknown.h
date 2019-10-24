#ifndef _IUNKNOWN_H_
#define _IUNKNOWN_H_

class IUnknown
{
public:
  virtual void* pguid();
  virtual void* QueryInterface(PUUID iid, void** pInterface);
  virtual void* AddRef();
  virtual void* Release();
};

#endif
