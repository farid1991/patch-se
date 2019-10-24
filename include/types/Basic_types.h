#ifndef __BASIC_TYPES_H__
#define __BASIC_TYPES_H__

/**
  * Signed integer number. The size of this type is platform-
  * and compiler-specific but is at least 32 bits.
  */
typedef long TSigned;

/**
  * Unsigned integer number. The size of this type is platform-
  * and compiler-specific but is at least 32 bits.
  */
typedef unsigned long TUnsigned;

/**
  * The smallest floating point type. The size of this type
  * is platform- and compiler-specific.
  *
  * When mapped to C or C++, TFloat will be mapped to C/C++ fundamental type 
  * float. 
  */
typedef float TFloat;

/**
  * The largest floating point type. The size of this type
  * is platform- and compiler-specific.
  * The precision of this type is at least as good as TFloat.
  *
  * When mapped to C or C++, TDouble will be mapped to C/C++ fundamental type 
  * double. 
  */
typedef double TDouble;

/**
  * Number representing the Boolean true and false values.
  */
typedef bool TBool;

/**
  * Integer number representing character ranging according
  * to the selected character representation.
  * 0 <= TChar <= TCHAR_MAX.
  *
  * Unless otherwise stated, the format of the selected character
  * representation is UCS-2 (ISO/IEC 10646).
  */
typedef wchar_t TChar;

/**
  * A constant holding the maximum value a TChar can have.
  */
const TChar TCHAR_MAX = 0xFFFF;

/**
  * Type used to represent ASCII (ISO 8859-1, ISO Latin-1) characters. 
  * 0 <= TAscii <= TASCII_MAX.
  */
typedef char TAscii;

/**
  * A constant holding the maximum value a TAscii can have.
  */
const TAscii TASCII_MAX = 0xFF;

/**
  * Reference representing an indirection to a physical address.
  */
typedef unsigned long THnd;

/**
  * When used as a method return type, TVoid specifies that the method does not 
  * return a value. 
  * When used in the declaration of a pointer, TVoid specifies that the pointer is "universal".
  * A TVoid pointer can be converted into any other type of data pointer.
  */
typedef void TVoid;

/**
  * Signed integer (32 bit representation). FSINT32_MIN <= FSint32 <= FSINT32_MAX.
  */
typedef long FSint32;

/**
  * A constant holding the maximum value an FSint32 can have.
  */
const FSint32 FSINT32_MAX = 0x7FFFFFFF;

/**
  * A constant holding the minimum value an FSint32 can have.
  */
const FSint32 FSINT32_MIN = -FSINT32_MAX - 1;

/**
  * Signed integer (16 bit representation). FSINT16_MIN <= FSint16 <= FSINT16_MAX.
  */
typedef short FSint16;

/**
  * A constant holding the maximum value an FSint16 can have.
  */
const FSint16 FSINT16_MAX = 0x7FFF;

/**
  * A constant holding the minimum value an FSint16 can have.
  */
const FSint16 FSINT16_MIN = -FSINT16_MAX - 1;

/**
  * Signed integer (8 bit representation). FSINT8_MIN <= FSint8 <= FSINT8_MAX.
  */
typedef char FSint8;

/**
  * A constant holding the maximum value an FSint8 can have.
  */
const FSint8 FSINT8_MAX = 0x7F;

/**
  * A constant holding the minimum value an FSint8 can have.
  */
//const FSint8 FSINT8_MIN = -FSINT8_MAX - 1;

/**
  * Unsigned integer (32 bit representation). 0 <= FUint32 <= FUINT32_MAX.
  */
typedef unsigned long FUint32;

/**
  * A constant holding the maximum value an FUint32 can have.
  */
const FUint32 FUINT32_MAX = 0xFFFFFFFF;

/**
  * Unsigned integer (16 bit representation). 0 <= FUint16 <= FUINT16_MAX.
  */
typedef unsigned short FUint16;

/**
  * A constant holding the maximum value an FUint16 can have.
  */
const FUint16 FUINT16_MAX = 0xFFFF;

/**
  * Unsigned integer (8 bit representation). 0 <= FUint8 <= FUINT8_MAX.
  */
typedef unsigned char FUint8;

/**
  * A constant holding the maximum value an FUint8 can have.
  */
const FUint8 FUINT8_MAX = 0xFF;

/**
  * Return type for methods that do not return any value when the service
  * runs to a successful completion. This type contains error information in
  * case the service fails.
  */ 
typedef TSigned RVoid;

/**
  * Return type for methods that return a Boolean result when the service
  * runs to a successful completion. This type contains error information in
  * case the service fails. Value 0 represents false, value 1 represents
  * true, while other values represent failure.
  */ 
typedef TSigned RBool;

/**
  * Return type for methods that return a selector (one out of many)
  * result when the service runs to a successful completion. This type contains 
  * error information in case the service fails. 
  * The range is limited to 16 bits and is intended for results indicating
  * which of several options that have been chosen.
  */ 
typedef TSigned RSel;

/**
  * Unique identifier for Interface and Component Id:s.
  *
  * @brief Unique identifier for Interface and Component Id:s.
  *
  * @param Uuid 16 bytes that are assumed to be globally (world-wide) unique.
  */
typedef struct
{
  FUint8 Uuid[16];
}
TUuid;

#endif
