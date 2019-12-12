#ifndef _REGISTRY_ERROR_H_
#define _REGISTRY_ERROR_H_

/**
 * @defgroup RegistryErrorCodes_G Registry Operation Error Codes
 * @{
 *
 * @par Overview
 * registry_interface_errorCodes.idl lists all the User Domain Error Codes
 * that all the Registry operations can return.
 *
 * @par Description
 * registry_interface_errorCodes.idl lists all the User Domain Error Codes
 * that all the Registry operations can return. These are returned in the normal
 * RVoid UE value and can be filtered out with the OPA_UED()-macro in opa_ue.h,
 * as for any other OPA-application.
 *
 * @par Related pages
 * - @ref IRegistry_G
 * - @ref IRegistryKey_G
 * - @ref IRegistryAccess_G
 */

/**
 * User-domain error codes for Registry operations. Not all apply to any
 * given interface. Also, not all semantic meanings (below) defined for an
 * error code necessarily apply identically to all interfaces were it is used.
 */
typedef enum
{
  /**
   * Unknown error. If this code is returned the operation has failed due
   * to abnormal run-time circumstances or internal errors
   * ("// this should not happen").
   */
  REGISTRY_UED_UNSPECIFIED,
  /**
   * The transaction is either not begun, not accepting this operation or
   * the transaction has been closed with open keys.
   */
  REGISTRY_UED_TRANSACTION_INVALID,
  /**
   * The transaction contains to much uncommited data, no further operations
   * can be handled.
   */
  REGISTRY_UED_TRANSACTION_OVERFLOW,
  /**
   * The key (or path) is invalid or otherwise obviously illegal. It can contain
   * illegal characters or be otherwise syntactically invalid.
   */
  REGISTRY_UED_KEY_INVALID,
  /**
   * The key has been set to an invalid state as the transaction it operated under
   * is no longer open or the key (path) once opened does no longer exist.
   */
  REGISTRY_UED_KEY_STATE_INVALID,
  /**
   * The key path is of to great depth.
   * @see IRegistryKey::REG_MAX_KEY_DEPTH
   */
  REGISTRY_UED_KEY_DEPTH,
  /**
   * The key name (or the key path contains a sub-key name that) is longer than
   * allowed.
   * @see IRegistryKey::REG_MAX_KEY_NAME
   */
  REGISTRY_UED_KEY_NAME_LENGTH,
  /**
   * The key path does not evaluate to an existing key.
   */
  REGISTRY_UED_KEY_NOT_FOUND,
  /**
   * The value name is invalid or otherwise obviously illegal. It can contain
   * illegal characters or be otherwise syntactically invalid.
   */
  REGISTRY_UED_VALUE_NAME_INVALID,
  /**
   * The value name is longer than allowed.
   * @see IRegistryKey::REG_MAX_VALUE_NAME
   */
  REGISTRY_UED_VALUE_NAME_LENGTH,
  /**
   * The (absolute) value path was malformed or otherwise invalid.
   */
  REGISTRY_UED_VALUE_PATH_INVALID,
  /**
   * The value name does not evaluate to an existing value.
   */
  REGISTRY_UED_VALUE_NOT_FOUND,
  /**
   * The item changed is marked read-only or the transaction allows only read
   * operations.
   */
  REGISTRY_UED_READ_ONLY,
  /**
   * The enumeration has reached the end (last item).
   */
  REGISTRY_UED_ENUM_DONE,
  /**
   * The actual type of the value was not that which was expected by the read
   * operation.
   */
  REGISTRY_UED_UNEXPECTED_TYPE,
  /**
   * The buffer provided for holding the data of the value read couldn't hold
   * the actual data, or (on writes) the buffer is to large for the value type.
   */
  REGISTRY_UED_BAD_SIZE,
  /**
   * The size of the actual binary data differed from that expected from the
   * binary buffer size or the claimed size does not fit the value type.
   */
  REGISTRY_UED_UNEXPECTED_SIZE,
  /**
   * The operation could not complete due to an underlaying I/O error. This
   * could mean out-of-space or similar.
   */
  REGISTRY_UED_IO_ERROR,

 /**
   * The operation is not supported. This could for instance mean that the
   * interface pointer on which a method call was executed didn't have support
   * for the method in question.
   */
  REGISTRY_UED_UNSUPPORTED,

  /**
   * Writing the value to the Registry failed due to that the value to be written
   * was not approved by the registered validators for the given key.
   */
  REGISTRY_UED_VALIDATION_FAILED,
  
  /**
   * The validation method failed due to some internal error.
   * 
   */
  REGISTRY_UED_VALIDATION_ERROR,

  /**
   * The supplied validator name does not have the correct form, which is
   * "$#CID-wihout-hyphens".
   */
  REGISTRY_UED_VALIDATION_NAME_INVALID,

  /**
   * The operation failed due to some very unexpected
   * run-time error.
   */
  REGISTRY_UED_VALIDATION_UNSPECIFIED,

  /**
   * The specified validator name does not evaluate to an existing
   * validator.
   */
  REGISTRY_UED_VALIDATION_VALIDATOR_NOT_FOUND,

  /**
   * The provided CID is in some way incorrect.
   */
  REGISTRY_UED_VALIDATION_INVALID_CID

} Registry_Ued_ErrorCode_t;

#endif

