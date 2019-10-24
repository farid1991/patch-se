#ifndef _IREGISTRYMANAGER_H_
#define _IREGISTRYMANAGER_H_

//UUID CID_CRegistryManager = {0x84, 0xA2, 0x98, 0x5A, 0x91, 0x3E, 0x4B, 0x7E, 0xBE, 0xB3, 0x7E, 0xFC, 0xFC, 0xF0, 0xB0, 0xEB};
//UUID IID_IRegistryManager = {0x42, 0x71, 0xC7, 0x45, 0xF, 0x21, 0x46, 0xB7, 0x9A, 0x29, 0x99, 0xF4, 0x21, 0x6A, 0x26, 0x2E};

typedef enum
{
  REGISTRY_UED_UNSPECIFIED,
  REGISTRY_UED_TRANSACTION_INVALID,
  REGISTRY_UED_TRANSACTION_OVERFLOW,
  REGISTRY_UED_KEY_INVALID,
  REGISTRY_UED_KEY_STATE_INVALID,
  REGISTRY_UED_KEY_DEPTH,
  REGISTRY_UED_KEY_NAME_LENGTH,
  REGISTRY_UED_KEY_NOT_FOUND,
  REGISTRY_UED_VALUE_NAME_INVALID,
  REGISTRY_UED_VALUE_NAME_LENGTH,
  REGISTRY_UED_VALUE_PATH_INVALID,
  REGISTRY_UED_VALUE_NOT_FOUND,
  REGISTRY_UED_READ_ONLY,
  REGISTRY_UED_ENUM_DONE,
  REGISTRY_UED_UNEXPECTED_TYPE,
  REGISTRY_UED_BAD_SIZE,
  REGISTRY_UED_UNEXPECTED_SIZE,
  REGISTRY_UED_IO_ERROR,
  REGISTRY_UED_UNSUPPORTED,
  REGISTRY_UED_VALIDATION_FAILED,
  REGISTRY_UED_VALIDATION_ERROR,
  REGISTRY_UED_VALIDATION_NAME_INVALID,
  REGISTRY_UED_VALIDATION_UNSPECIFIED,
  REGISTRY_UED_VALIDATION_VALIDATOR_NOT_FOUND,
  REGISTRY_UED_VALIDATION_INVALID_CID
}Registry_Ued_ErrorCode_t;

typedef enum
{
  Reg_RegistryTransactionClass_AutoCommit,
  Reg_RegistryTransactionClass_Full,
  Reg_RegistryTransactionClass_ReadOnly
}Reg_RegistryTransactionClass_t;

typedef enum
{
  Reg_RegValueType_Unspecified, ///< No data type specified.
  Reg_RegValueType_UInt,    ///< Unsigned integer value.
  Reg_RegValueType_String,  ///< 'char' (null terminated) string value.
  Reg_RegValueType_WString, ///< 'wchar' (null terminated) string value.
  Reg_RegValueType_Binary   ///< Binary/unformatted value, sized in bytes.
}Reg_RegValueType_t;

typedef struct
{
  Reg_RegValueType_t valueType; ///< The (data) type of the Value.
  int dataSize; ///< The size (in bytes) of the data (strings: incl. nullt.).
}RegKey_ValueInfo_t;

class IRegistryKey: public IUnknown
{
public:
  virtual int EnumSubkeys(char* pKeyName);
  virtual int EnumValues(char* pValueName);
  virtual int CreateSubkey(char* keyName, bool open);
  virtual int OpenSubkey(char* subkeyName);
  virtual int DeleteSubkey(char* keyName);
  virtual int RenameSubkey(char* keyName, char* newKeyName);
  virtual int GetValue(char* valueName, Reg_RegValueType_t valueType, int dataSize, void* pData, RegKey_ValueInfo_t* pValueInfo);
  virtual int SetValue(char* valueName, Reg_RegValueType_t valueType, int dataSize, void* pData);
  virtual int DeleteValue(char* valueName);
  virtual int RenameValue(char* valueName, char* newValueName);
  virtual int RestateValue(char* valueName);
  virtual int GetValueInfo(char* valueName, RegKey_ValueInfo_t* pValueInfo);
  virtual int GetKeyPath(int bufferSize, char* pKeyPath);
};

class IRegistry: public IUnknown
{
public:
  virtual int BeginTransaction(Reg_RegistryTransactionClass_t transactionClass);
  virtual int EndTransaction(bool commitChanges);
  virtual int FlushTransaction(bool commitChanges);
  virtual int OpenKey(char* keyPath, IRegistryKey** ppIRegistryKey);
  virtual int CreateKey(char* keyPath, IRegistryKey** ppIRegistryKey);
  virtual int EnableValidatingKeys(void);
  virtual int DisableValidatingKeys(void);
};

class IRegistryAccess: public IUnknown
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

class IRegistryManager: public IUnknown
{
public:
  virtual int CreateRegistry(IRegistry** pIRegistry);
  virtual int CreateRegistryAccess(IRegistryAccess** pIRegistryAccess);
  virtual int CreateRegistryNotificationsProvider(IUnknown** pIRegistryNotificationsProvider);
};

#endif
