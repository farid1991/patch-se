#ifndef __REGISTRY_TYPES_H__
#define __REGISTRY_TYPES_H__

/**
 * Value type of registry entry. These are the value types/classes that the
 * Registry can hold.
 *
 * @note TBI: Add fixed size type (16 bytes) for UUIDs?
 */
typedef enum
{
  Reg_RegValueType_Unspecified, ///< No data type specified.
  Reg_RegValueType_UInt,        ///< Unsigned integer value.
  Reg_RegValueType_String,      ///< 'char' (null terminated) string value.
  Reg_RegValueType_WString,     ///< 'wchar' (null terminated) string value.
  Reg_RegValueType_Binary       ///< Binary/unformatted value, sized in bytes.
} Reg_RegValueType_t;

/**
 * Max size of the Reg_RegValueType_Binary value type.
 */
const TUnsigned REG_MAX_BINARY_SIZE = 1024;

/**
 * Max length of the Reg_RegValueType_String value type, in characters, excluding
 * the null terminator (i.e. strlen-compatible).
 */
const TUnsigned REG_MAX_STRING_LENGTH = (REG_MAX_BINARY_SIZE - 1);

/**
 * Max length of the Reg_RegValueType_WString value type, in characters, excluding
 * the null terminator (i.e. wstrlen-compatible).
 */
const TUnsigned REG_MAX_WSTRING_LENGTH = ((REG_MAX_BINARY_SIZE / 2) - 1);

/**
 * Maximum length of a key name in characters (excl. null terminator).
 */
const TUnsigned REG_MAX_KEY_NAME = 35;

/**
 * Type for key name entries. The name must be null terminated.
 */
typedef TAscii Reg_KeyName_t[REG_MAX_KEY_NAME + 1];

/**
 * Maximum length of a value name in characters (excl. null terminator).
 */
const TUnsigned REG_MAX_VALUE_NAME = 35;

/**
 * Type for value name entries. The name must be null terminated.
 */
typedef TAscii Reg_ValueName_t[REG_MAX_VALUE_NAME + 1];

/**
 * The deepest allowable sub-key chain. Example, "/first/second/third" has a depth
 * of three. A key's values are considered to have the same depth as their parent.
 */
const TUnsigned REG_MAX_KEY_DEPTH = 8;

/**
 * Type describing the properties of a value entry.
 *
 * @note TBD: Add Flags describing various properties of a Value. These would e.g.
 * describe setting and customization-related properties as: "changed by user",
 * "customized", "user lock" et cetera. Type would prob. be TUnsigned.
 */
typedef struct
{
  Reg_RegValueType_t valueType; ///< The (data) type of the Value.
  TUnsigned dataSize;           ///< The size (in bytes) of the data (strings: incl. nullt.).
} RegKey_ValueInfo_t;

/**
 * This enum describes the various classes of transactions
 * available for registry operations.
 */
typedef enum
{
  Reg_RegistryTransactionClass_AutoCommit,
  Reg_RegistryTransactionClass_Full,
  Reg_RegistryTransactionClass_ReadOnly
} Reg_RegistryTransactionClass_t;

/**
 * Return type of the validation function defined in this interface.
 *
 */
typedef enum
{
  Reg_ValidationResult_Passed, ///< The value is valid and OK to write.
  Reg_ValidationResult_Failed, ///< The value is invalid.
  Reg_ValidationResult_Error   ///< The validation caused an error.
} Reg_ValidationResult_t;

#endif
