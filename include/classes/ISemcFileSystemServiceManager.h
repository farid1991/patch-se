#ifndef _ISEMCFILESYSTEMSERVICEMANAGER_H_
#define _ISEMCFILESYSTEMSERVICEMANAGER_H_

//UUID CID_CSemcFileSystemServiceManager = {0x2D, 0xDF, 0x30, 0x46, 0xDE, 0xDA, 0x4C, 0x45, 0xBD, 0x8F, 0x37, 0x6F, 0x27, 0x34, 0x6B, 0x1D};
//UUID IID_ISemcFileSystemServiceManager = {0x59, 0xC7, 0x50, 0xD4, 0x23, 0x1A, 0x11, 0xDE, 0x8C, 0x30, 0x08, 0x00, 0x20, 0x0C, 0x9A, 0x66};

typedef enum
{
  UNKNOWN1,
  UNKNOWN1,
  FORMATTING_CARD
}TFileSystemServiceVolumeID;

class ISemcFileSystemFormattingService: public IRoot
{
public:
  virtual int FormatVolume(IRoot* pICBSemcFileSystemFormattingService, u16 MsgBase, int ClientData, TFileSystemServiceVolumeID VolumeID);
  virtual int RegisterForFormatEvent(IRoot* pICBSemcFileSystemFormattingService, u16 MsgBase, int ClientData, int* phSubscription);
  virtual int DeregisterForFormatEvent(int hSubscription);
};

class ISemcFileSystemServiceManager: public IRoot
{
public:
  virtual int FileSystemFormattingService(ISemcFileSystemFormattingService** ppISemcFileSystemFormattingService);
};

#endif
