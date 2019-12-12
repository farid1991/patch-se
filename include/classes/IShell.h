#ifndef _ISHELL_H_
#define _ISHELL_H_

#include "..\\include\types\OPA_types.h"

class IShell: public IRoot
{
public:
  /**
  * This method allocates memory from the system heap. 
  *
  * @brief Allocates memory blocks on the heap.
  *
  * @param Size       The number of bytes to be allocated.
  * @param ppBuffer   Pointer to a pointer to the allocated memory block. 
  *
  * @return This method returns an RVoid status code.
  *
  * @see ::FreeMemory
  */
  virtual int AllocateMemory(int Size, void** ppBuffer); 
  
  /**
  * Creates an OPA message to be sent between execution contexts.
  * After a message is received the message should be freed
  * (with <link target="IShell::FreeMsg">FreeMsg</link>) as soon as possible.
  *
  * To avoid running out of resources it is recommended to copy any data,
  * that is received in a message and is to be kept, to either static allocated memory or
  * memory allocated with the <link target="IShell::AllocateMemory">AllocateMemory</link> method.
  *
  * @brief Creates an OPA message to be sent between execution contexts.
  *
  * @param Base   The message base.
  * @param Id     The message id.
  * @param Size   Size of the user defined message. The size must be at least sizeof(TMsgHdr).
  *               The max size of OPA message depends on platform configuration.
  * @param ppMsg  Pointer to a pointer to the allocated message.
  *
  * @return This method returns an RVoid status code.
  *
  * @see ::FreeMsg, IMessageManager::GetMsg, IMessageManager::SendMsgToApp
  */  
  virtual int CreateMsg(TMsgBase Base, TMsgId Id, TSize Size, TMsg **ppMsg); 
  
  /**
  * Compares if two UUIDs are identical.
  *
  * @brief Compares if two UUIDs are identical.
  * @param pIID1 The first UUID.
  * @param pIID2 The second UUID.
  * @return This method returns an RBool status code.
  */  
  virtual int CompareUUID(UUID* pIID1, UUID* pIID2);
  
  /**
  * Frees an OPA message sent between execution contexts. This method should be used to 
  * free the memory belonging to the message.
  *
  * @brief Frees an OPA message sent between execution contexts.
  * @param ppMsg Pointer to pointer to the message that will be freed. The
  *              message pointer is set to NULL, to avoid unintentional usage 
  *              of a freed message.
  *              If (*ppMsg) is NULL, then this method returns successfully
  *              with no action.
  * @return This method returns an RVoid status code.
  * @see ::CreateMsg, IMessageManager::GetMsg, IMessageManager::SendMsgToApp
  */
  virtual int FreeMsg( TMsg** ppMsg ); 
  
  /**
  * Creates an instance of an OPA component or other ECM component.
  *
  * @brief Creates an instance of an ECM component.
  *
  * @param pCid                 The class identifier of the requested component.
  * @param pIid                 The interface identifier of the requested interface.
  * @param ppInterfacePointer   Pointer referring to the requested interface 
  *                             in an instance of the requested component.
  *
  * @return This method returns an RVoid status code.
  */
  virtual int CreateInstance(UUID* pCID, UUID* pIID, void** ppInterfacePointer);
  
  /**
  * This method frees heap memory, that previously has been allocated by 
  * AllocateMemory. The method is NULL safe, i.e. it's possible to call the 
  * method with *ppBuffer set to NULL.
  *
  * @brief This method frees heap memory.
  * @param ppBuffer Pointer to pointer to the memory to be freed. The
  *        memory pointer is set to NULL, to avoid unintentional usage 
  *        of freed memory.
  *        If (*ppBuffer) is NULL, then this method returns successfully
  *        with no action.
  * @return This method returns an RVoid status code.    
  * @see ::AllocateMemory
  */
  virtual int FreeMemory( TVoid** ppBuffer );
  
  /**
  * This method prepares a message, created by CreateMsg by marking a parameter
  * as being an interface reference.
  *
  * @brief This method marks interface references in a message.
  *
  * @param ppMsg                Pointer to a pointer to the message.
  * @param ppInterfacePointer   Pointer to a pointer to the interface reference in the message
  *
  * @return This method returns an RVoid status code.
  *
  * @see ::CreateMsg
  */
  virtual int MarkInterfacesInMsg( TMsg** ppMsg, IRoot** ppInterfacePointer );
  
  /**
  * This method changes the size of an allocated memory block. The memory must
  * have been allocated by a previous call to AllocateMemory or ReallocateMemory.
  *
  * The buffer contents will be unchanged up to the lesser of the new and old sizes.
  * If necessary, the content is copied to a new memory space.
  *
  * If there is not enough available memory to expand the block to the given size,
  * the original block is unchanged.
  *
  * If the Size is zero and the *ppBuffer argument is not NULL,
  * the original block is freed and the *ppBuffer is set to NULL.
  * If the *ppBuffer argument is NULL and the Size is not zero
  * a new memory block is allocated.
  *
  * @brief Reallocate memory blocks.
  *
  * @param Size       Specifies the new size of the block, in bytes.
  * @param ppBuffer   Pointer to a pointer to the (re)allocated memory.
  *
  * @return This method returns an RVoid status code.
  *
  * @see ::AllocateMemory
  */ 
  virtual int ReallocateMemory(TUnsigned Size, TVoid** ppBuffer);
  
  /**
  * This method releases all interfaces in a message that has previously been marked by MarkInterfacesInMsg.
  *
  * @brief This method releases all interfaces in a message.
  * @param ppMsg Pointer to a pointer to the message.
  * @return This method returns an RVoid status code.    
  * @see ::CreateMsg
  */
  virtual int ReleaseInterfacesInMsg(TMsg** ppMsg);
  
  /**
  * Tests the interface to see if it is an interface with the specified 
  * UUID or an interface derived from an interface with the specified 
  * UUID. Check result of method by first call OPA_SUCCESS or OPA_FAILURE and 
  * then call macro OPA_BOOL.
  *
  * @brief Tests if the interface is an interface of the specified UUID.
  *
  * @param pInterface   Interface to test.
  * @param pIId         Interface UUID.
  *
  * @return This method returns an RBool status code.
  */  
  virtual int IsKindOfInterface(IRoot* pInterface, UUID* pIId);
  
  /**
    * This method is used to remove all sessions which have pICB as callback interface pointer. 
    * InvalidateCallbackInterface is typically called from the destructor in an application
    * implementing a callback interface in order to end all services, including asynchronous services
    * which are not possible to end with other methods. These calls are automatically generated by the EIDL compiler
    * and shall normally not be added manually. 
    * Note that this method does not unsubscribe for events, i.e. the application still needs to call
    * unsubscribe for all started subscriptions.
    *
    * @brief  Removes all sessions with a specific callback interface pointer.
    * @param  pICB       Pointer to the callback interface for which all sessions shall be removed.
    * @return This method returns an RVoid status code.
    */
  virtual int InvalidateCallbackInterface(IRoot* pICB);
  
  /**
    * Returns a pointer to the execution shell that belongs to the calling 
    * execution context.
    *
    * @brief  Returns the execution shell interface of an execution context.
    * @param  ppIExecutionShell    Pointer to a pointer to the execution shell.
    *                              If (*ppIExecutionShell) is not NULL, then the current
    *                              interface will be released before the execution shell is stored.
    *                              The application must release the interface after use by calling
    *                              <link target="IRoot::Release">IExecutionShell::Release</link>.
    *                              It is not allowed to set this parameter to NULL.
    *                              
    * @return This method returns an RVoid status code.
    */
  virtual int GetCallerExecutionShell(IRoot** ppIExecutionShell);
};

#endif
