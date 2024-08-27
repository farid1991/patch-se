#ifndef _Main_H_
#define _Main_H_

#define MAX_NAME_LEN 50

#define SAVE_BMP 0
#define SAVE_PNG 1

extern "C"
{
  char *keyhandler_get_key(int key);
  char *keyhandler_get_action(int action);
  void keyhandler_action(int key, int unk1, int action);

  int fflush(int file);
};

#endif
