#ifndef _IUNKNOWN_H_
#define _IUNKNOWN_H_

#include "..\\include\types\Basic_types.h"
#include "..\\include\types\OPA_Types.h"

#define E_NOTIMPL                   0x80004001  /*microsoft*/
#define E_NOINTERFACE               0x80080800
#define E_FAIL                      0x80004005  /*microsoft*/
#define CLASS_E_NOAGGREGATION       0x80040110  /*microsoft*/
#define CLASS_E_CLASSNOTAVAILABLE   0x80040111  /*microsoft*/
#define SELFREG_E_CLASS             0x80040201  /*microsoft*/
#define E_OUTOFMEMORY               0x8007000E  /*microsoft*/
#define S_OK                        0
#define S_FALSE                     1

class IRoot
{
public:
  virtual RVoid pguid();
  virtual RVoid QueryInterface(PUUID pIID, TVoid** ppInterface);
  
  /**
    * Whenever an interface pointer is duplicated in any form, this method 
    * shall be called.
    *
    * @brief          Increases the component interface reference counter.
    * @return         This method returns an RVoid status code.
    */
  virtual RVoid AddRef();
  
  /**
    * Whenever an interface pointer is becoming unreferenced, this method
    * shall be called.
    *
    * If the reference counter reaches 0 as a result of the call, the component
    * instance is deallocated.
    *
    * @brief          Decreases the component interface reference counter.
    * @return         This method returns an RVoid status code.
    */
  virtual RVoid Release();
};

typedef FUint32 TUIHash;

class IUIRoot : public IRoot
{
public:
  /**
   * Get a hash value of the component, can be used to compare two interfaces
   * to see if they belong to the same component
   */
  virtual int GetComponentHash( TUIHash* pHash );
};

#endif
