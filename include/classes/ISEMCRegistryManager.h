#ifndef _ISEMCREGISTRYMANAGER_H_
#define _ISEMCREGISTRYMANAGER_H_

#include "..\types\Basic_types.h"
#include "..\types\IRegistry_types.h"

// UUID IID_ISEMCRegistryManager = {0x42, 0x71, 0xC7, 0x45, 0x0F, 0x21, 0x46, 0xB7, 0x9A, 0x29, 0x99, 0xF4, 0x21, 0x6A, 0x26, 0x2E};
// UUID CID_CSEMCRegistryManager = {0x84, 0xA2, 0x98, 0x5A, 0x91, 0x3E, 0x4B, 0x7E, 0xBE, 0xB3, 0x7E, 0xFC, 0xFC, 0xF0, 0xB0, 0xEB};

class IRegistryValidator : public IUnknown
{
public:
  virtual int ValidateValue(TAscii *parentKeyPath,
                            TAscii *valueName,
                            Reg_RegValueType_t valueType,
                            TUnsigned dataSize,
                            TVoid *pData,
                            Reg_ValidationResult_t *pResult);
};

class IRegistryKey : public IUnknown
{
public:
  virtual int EnumSubkeys(Reg_KeyName_t *pKeyName);
  virtual int EnumValues(Reg_ValueName_t *pValueName);
  virtual int CreateSubkey(TAscii *keyName, TBool open);
  virtual int OpenSubkey(TAscii *subkeyName);
  virtual int DeleteSubkey(TAscii *keyName);
  virtual int RenameSubkey(TAscii *keyName, TAscii *newKeyName);
  virtual int GetValue(TAscii *valueName,
                       Reg_RegValueType_t valueType,
                       TUnsigned dataSize,
                       TVoid *pData,
                       RegKey_ValueInfo_t *pValueInfo);
  virtual int SetValue(TAscii *valueName,
                       Reg_RegValueType_t valueType,
                       TUnsigned dataSize, // may be 0 for strings and fixed-size types
                       TVoid *pData);
  virtual int DeleteValue(TAscii *valueName);
  virtual int RenameValue(TAscii *valueName, TAscii *newValueName);
  virtual int RestateValue(TAscii *valueName);
  virtual int GetValueInfo(TAscii *valueName, RegKey_ValueInfo_t *pValueInfo);
  virtual int GetKeyPath(TUnsigned bufferSize, TAscii *pKeyPath);
};
class IRegistryValidatingKey : public IRegistryKey
{
public:
  virtual int HasValidator(TBool *pResult);
  virtual int ListValidators(Reg_ValueName_t *pValidatorName);
  virtual int AddNonPersistentValidator(TUuid *pCid);
  virtual int AddValidator(TUuid *pCid);
  virtual int RemoveValidator(TUuid *pCid);
  virtual int ClearValidators(void);
};

class IRegistryAccess : public IUnknown
{
public:
  virtual int ReadUnsignedInt(TAscii *absoluteValuePath, TUnsigned *pUnsigned);
  virtual int ReadString(TAscii *absoluteValuePath, TUnsigned maxLength, TAscii *stringBuffer, TUnsigned *pActualLength);
  virtual int ReadWString(TAscii *absoluteValuePath, TUnsigned maxLength, TChar *stringBuffer, TUnsigned *pActualLength);
  virtual int ReadBinary(TAscii *absoluteValuePath, TUnsigned dataSize, TVoid *pData, TUnsigned *pActualSize);
  virtual int WriteUnsignedInt(TAscii *absoluteValuePath, TUnsigned value);
  virtual int WriteString(TAscii *absoluteValuePath, TAscii *strVal);
  virtual int WriteWString(TAscii *absoluteValuePath, TChar *strVal);
  virtual int WriteBinary(TAscii *absoluteValuePath, TVoid *pData, TUnsigned dataSize);
  virtual int EnableValidation(void);
  virtual int DisableValidation(void);
};

class IRegistry : public IUnknown
{
public:
  virtual int BeginTransaction(Reg_RegistryTransactionClass_t transactionClass);
  virtual int EndTransaction(TBool commitChanges);
  virtual int FlushTransaction(TBool commitChanges);
  virtual int OpenKey(TAscii *keyPath, IRegistryKey **ppIRegistryKey);
  virtual int CreateKey(TAscii *keyPath, IRegistryKey **ppIRegistryKey);
  virtual int EnableValidatingKeys(void);
  virtual int DisableValidatingKeys(void);
};

class ISEMCRegistryManager : public IUnknown
{
public:
  virtual int CreateRegistry(IRegistry **ppIRegistry);
  virtual int CreateRegistryAccess(IRegistryAccess **ppIRegistryAccess);
  virtual int CreateRegistryNotificationsProvider(IUnknown **ppIRegistryNotificationsProvider);
};

#endif
