#ifndef __UISOFTKEY_TYPES_H__
#define __UISOFTKEY_TYPES_H__

typedef enum
{
  UNDEFINED_SOFTKEY = -1,   // See documentation for CreateSoftkey
  ABORT_SOFTKEY = 4011,     // Predefined softkey for abort
  ACCEPT_SOFTKEY,           // Predefined master softkey for the accept family: ok, save, done, continue...
  ADD_SOFTKEY,              // Predefined softkey for add
  ADDITEM_SOFTKEY,          // Predefined softkey for add item
  CANCEL_SOFTKEY,           // Predefined softkey for cancel
  CHECK_SOFTKEY,            // Predefined softkey for check
  CONTINUE_SOFTKEY,         // Predefined softkey for continue
  CREATE_MORELIST_SOFTKEY,  // Predefined softkey for create more list
  DESTROY_MORELIST_SOFTKEY, // Predefined softkey for destroy more list
  DELETE_SOFTKEY,           // Predefined softkey for delete
  DONE_SOFTKEY,             // Predefined softkey for done
  EDIT_SOFTKEY,             // Predefined softkey for edit
  HELP_SOFTKEY,             // Predefined softkey for help
  HYPERLINK_SOFTKEY,        // Predefined softkey for hyperlink
  INFO_SOFTKEY,             // Predefined softkey for info
  INPUT_EMPTY_SOFTKEY,      // Predefined softkey for empty input
  INPUT_NOT_EMPTY_SOFTKEY,  // Predefined softkey for not empty input
  KEYLOCK_SOFTKEY,          // Predefined softkey for key lock
  MARKSEVERAL_SOFTKEY,      // Predefined softkey for abort
  NO_SOFTKEY,               // Predefined softkey for no
  OK_SOFTKEY,               // Predefined softkey for OK
  PREVIOUS_SOFTKEY,         // Predefined softkey for previous
  SAVE_SOFTKEY,             // Predefined softkey for save
  SELECT_SOFTKEY,           // Predefined softkey for select
  UNCHECK_SOFTKEY,          // Predefined softkey for uncheck
  UNMARK_ALL_SOFTKEY,       // Predefined softkey for unmark all
  YES_SOFTKEY,              // Predefined softkey for yes
  LAST_SOFTKEY              // Last softkey
} TUIPredefinedSoftkey;


/**
 * Softkey action types
 * Softkey action can be set on:
 * Disp object - Actions visible to current object. Can be owned by application or default.
 * Book        - Actions visible to all objects owned by the application, e.g. CANCEL_ACTION
 * system      - Actions visible to all objects, regardless application, e.g. END_CALL_ACTION
 */
typedef enum
{
  UI_SOFTKEYS_OBJECT_SOFTKEY_ACTION,      // Actions visible to current object. Can be owned by application or default.
  UI_SOFTKEYS_APPLICATION_SOFTKEY_ACTION, // Actions visible to all objects owned by the application, e.g. CANCEL_ACTION
  UI_SOFTKEYS_SYSTEM_SOFTKEY_ACTION,       // Actions visible to all objects, regardless application, e.g. END_CALL_ACTION
  UI_SOFTKEYS_SYSTEM_LAST
} UI_SOFTKEYS_Softkey_Action_t;


/*
 * Layout types for softkey buttons used 
 * for clients that not use generic algoritm for placing softkey
 * actions
 *
 * UISOFTKEYS_Button_Layout_Left_Right_Two_Buttons:
 * used when having only two actions
 * 1st action will be placed on the left softkey
 * and 2nd action will be placed on the right softkey
 * 
 * -------           -------
 * | 1st |           | 2nd  |
 * |     |           |      |
 * -------           -------
 * 
 * UISOFTKEYS_Button_Layout_Center_Right_Two_Buttons:
 * used when having only two actions
 * 1st action will be placed on the center softkey
 * and 2nd action will be placed on the right softkey
 * 
 *         -------   -------
 *         | 1st |   | 2nd  |
 *         |     |   |      |
 *         -------   -------
 */
typedef enum
{
  UISOFTKEYS_Button_Layout_Default,
  UISOFTKEYS_Button_Layout_Left_Right_Two_Buttons,
  UISOFTKEYS_Button_Layout_Center_Right_Two_Buttons, 
  UISOFTKEYS_Button_Layout_Last
} UISOFTKEYS_Button_Layout_t;

#endif
