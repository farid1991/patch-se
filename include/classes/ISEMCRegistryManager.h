#ifndef _IREGISTRYMANAGER_H_
#define _IREGISTRYMANAGER_H_

const UUID CID_CRegistryManager = {0x84, 0xA2, 0x98, 0x5A, 0x91, 0x3E, 0x4B, 0x7E, 0xBE, 0xB3, 0x7E, 0xFC, 0xFC, 0xF0, 0xB0, 0xEB};
const UUID IID_IRegistryManager = {0x42, 0x71, 0xC7, 0x45, 0xF, 0x21, 0x46, 0xB7, 0x9A, 0x29, 0x99, 0xF4, 0x21, 0x6A, 0x26, 0x2E};

#include "..\\include\types\registry_interface_errors.h"

typedef enum
{
  Reg_RegistryTransactionClass_AutoCommit,
  Reg_RegistryTransactionClass_Full,
  Reg_RegistryTransactionClass_ReadOnly
}Reg_RegistryTransactionClass_t;

typedef enum
{
  Reg_RegValueType_Unspecified, ///< No data type specified.
  Reg_RegValueType_UInt,        ///< Unsigned integer value.
  Reg_RegValueType_String,      ///< 'char' (null terminated) string value.
  Reg_RegValueType_WString,     ///< 'wchar' (null terminated) string value.
  Reg_RegValueType_Binary       ///< Binary/unformatted value, sized in bytes.
}Reg_RegValueType_t;

typedef struct
{
  Reg_RegValueType_t valueType; ///< The (data) type of the Value.
  TUnsigned dataSize;           ///< The size (in bytes) of the data (strings: incl. nullt.).
} RegKey_ValueInfo_t;

typedef enum
{
  /**
   * Changes affecting a single key and it's directly connected values.
   */
  Reg_RegistrySubscriptionClass_Key,
  /**
   * Changes affecting a single key, it's values and the contents of its complete subtree.
   */
  Reg_RegistrySubscriptionClass_RecursiveKey,
  /**
   * Changes affecting a single value.
   */
  Reg_RegistrySubscriptionClass_Value
} Reg_RegistrySubscriptionClass_t;


class IRegistryNotificationsProvider : public IRoot
{
public:
  virtual int SubscribeToNotifications(IRoot* pICBRegistryNotificationsProvider,
                                       TMsgBase msgBase,
                                       TClientData clientData,
                                       TAscii* subscriptionPath,
                                       Reg_RegistrySubscriptionClass_t subscriptionType,
                                       THnd* pSubscription);

  virtual int UnsubscribeToNotifications( THnd subscription );
};

class IRegistryKey: public IRoot
{
public:
  virtual int EnumSubkeys( TAscii* pKeyName );
  virtual int EnumValues( TAscii* pValueName );
  virtual int CreateSubkey( TAscii* keyName, TBool open );
  virtual int OpenSubkey( TAscii* subkeyName );
  virtual int DeleteSubkey( TAscii* keyName );
  virtual int RenameSubkey( TAscii* keyName, TAscii* newKeyName);
  
  virtual int GetValue(TAscii* valueName, 
                       Reg_RegValueType_t valueType, 
                       TUnsigned dataSize, 
                       void* pData, 
                       RegKey_ValueInfo_t* pValueInfo);
  
  virtual int SetValue( TAscii* valueName, 
                       Reg_RegValueType_t valueType, 
                       TUnsigned dataSize, 
                       void* pData);
  
  virtual int DeleteValue( TAscii* valueName);
  virtual int RenameValue( TAscii* valueName, char* newValueName );
  virtual int RestateValue( TAscii* valueName );
  virtual int GetValueInfo( TAscii* valueName, RegKey_ValueInfo_t* pValueInfo );
  virtual int GetKeyPath( TUnsigned bufferSize, TAscii* pKeyPath );
};

class IRegistryAccess: public IRoot
{
public:
  virtual int ReadUnsignedInt(char* absoluteValuePath, int* pUnsigned);
  virtual int ReadString(char* absoluteValuePath, int maxLength, char* stringBuffer, int* pActualLength);
  virtual int ReadWString(char* absoluteValuePath, int maxLength, wchar_t* stringBuffer, int* pActualLength);
  virtual int ReadBinary(char* absoluteValuePath, int dataSize, void* pData, int* pActualSize);
  virtual int WriteUnsignedInt(char* absoluteValuePath, int value);
  virtual int WriteString(char* absoluteValuePath, char* strVal);
  virtual int WriteWString(char* absoluteValuePath, wchar_t* strVal);
  virtual int WriteBinary(char* absoluteValuePath, void* pData, int dataSize);
  virtual int EnableValidation(void);
  virtual int DisableValidation(void);
};

class IRegistry: public IRoot
{
public:
  virtual int BeginTransaction(Reg_RegistryTransactionClass_t transactionClass);
  virtual int EndTransaction( TBool commitChanges );
  virtual int FlushTransaction( TBool commitChanges );
  virtual int OpenKey(char* keyPath, IRegistryKey** ppIRegistryKey);
  virtual int CreateKey(char* keyPath, IRegistryKey** ppIRegistryKey);
  virtual int EnableValidatingKeys(void);
  virtual int DisableValidatingKeys(void);
};

class ISEMCRegistryManager: public IRoot
{
public:
  virtual int CreateRegistry(IRegistry** ppIRegistry);
  virtual int CreateRegistryAccess(IRegistryAccess** ppIRegistryAccess);
  virtual int CreateRegistryNotificationsProvider(IRegistryNotificationsProvider** ppIRegistryNotificationsProvider);
};

#endif
