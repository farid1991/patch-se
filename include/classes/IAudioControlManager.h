#ifndef _IAUDIOCONTROLMANAGER_H_
#define _IAUDIOCONTROLMANAGER_H_

#include "..\\include\types\AudioControl_types.h"

const UUID CID_CAudioControlManager = {0xE2, 0x0, 0x10, 0x71, 0x81, 0xD3, 0x43, 0xC3, 0xAB, 0xEA, 0xD4, 0xF4, 0xEB, 0x67, 0xC8, 0x93};
const UUID IID_IAudioControlManager = {0x78, 0xE, 0x15, 0xD9, 0x40, 0xF5, 0x4F, 0x99, 0xAF, 0x93, 0x38, 0x3B, 0x38, 0x7F, 0xA7, 0xED};

class IAudioControl: public IRoot
{
public:
  virtual int unk_0x10();
  virtual int unk_0x14();
  virtual int unk_0x18();
  virtual int unk_0x1C();
  virtual int Accessory_Update(int accessoryHandle, TAudioControl_AccessoryClass accessoryClass, TAudioControl_AccessoryId accessoryId); //0x20
  virtual int Accessory_CallVolume_Set2(int accessoryHandle, char callVolume); //0x24
  virtual int Accessory_SubscribeToEvents(IRoot* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_AccessoryEvents events, int* pSubscriptionHandle); //0x28
  virtual int Subscribe(IRoot* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_Events events, int* pSubscriptionHandle); //0x2C
  virtual int Accessory_GetCurrent(TAudioControl_AccessoryClass* pAccessoryClass, TAudioControl_AccessoryId* pAccessoryId, int* pAccessoryHandle); //0x30
  virtual int Accessory_UnsubscribeToEvents(int subscriptionHandle); //0x34
  virtual int Unsubscribe(int subscriptionHandle); //0x38
  virtual int Ringer_Play(IRoot* pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, wchar_t* pFilePath, bool, bool followSilentMode, bool unk1, bool unk2, bool volumeOverride, char overrideVolume, int* pRingerHandle); //0x3C
  virtual int Ringer_Play2(IRoot* pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, wchar_t* pFilePath, wchar_t* pIlluminationFileName, bool preview, bool followSilentMode, bool volumeOverride, char overrideVolume, int* pRingerHandle); //0x40
  virtual int Ringer_Stop(int ringerHandle, bool fadeDownBeforeStop); //0x44
  virtual int Ringer_Pause(int ringerHandle); //0x48
  virtual int Ringer_Resume(int ringerHandle); //0x4C
  virtual int Notification_Play(IRoot* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_Notification notification, bool preview, int* pNotificationHandle); //0x50
  virtual int Notification_PlayFile(IRoot* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_Notification notification, wchar_t* pFilePath, bool preview, int* pNotificationHandle); //0x54
  virtual int Notification_PlayFile2(IRoot* pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, TAudioControl_Notification notification, wchar_t* pFilePath, bool preview, int* pNotificationHandle); //0x58
  virtual int Notification_PlayFile3(IRoot* pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, TAudioControl_Notification notification, wchar_t* pFilePath, bool preview, int* unk, int* pNotificationHandle); //0x5C
  virtual int Notification_Stop(int notificationHandle); //0x60
  virtual int Alarm_Play(IRoot* pICBAudioControl, u16 msgBase, int clientData, wchar_t* pFilePath, bool preview, bool followSilentMode, int* pAlarmHandle); //0x64 // 15176D72
  virtual int Alarm_Stop(int alarmHandle); //0x68
  virtual int Play2(IRoot* pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, wchar_t* pFilePath, bool repeat, bool followSilentMode, int* pPlayHandle); //0x6C
  virtual int Stop(int playHandle); //0x70
  virtual int unk_0x74(); //0x74
  virtual int unk_0x78(); //0x78
  virtual int Tone_Play2(IRoot* pICBAudioControl, u16 msgBase, int clientData, int sessionHandle, TAudioControl_Tone tone, bool followSilentMode, TAudioControl_ToneRedirection toneRedirection, int time_duration, int* pToneHandle); //0x7C
  virtual int Tone_Stop(int toneHandle); //0x80
  virtual int KeySound_Extended_Play(IRoot* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_KeySound keySound, int time_duration, int* pToneHandle); //0x84
  virtual int KeySound_Extended_Stop(int toneHandle); //0x88
  virtual int ServiceMenu_SpeakerTest_Play(IRoot* pICBAudioControl, u16 msgBase, int clientData, wchar_t* pFilePath, TAudioControl_SpeakerType speakerType, int* pChannelHandle); //0x8C
  virtual int ServiceMenu_SpeakerTest_Stop(int channelHandle); //0x90
  virtual int IsAudioPlaying(bool* pAudioPlaying, TAudioControl_VolumeType* pVolumeType); //0x94
  virtual int IsVibratorRunning(bool* pVibratorRunning); //0x98
  virtual int AudioChannel_Open2(IRoot* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_ChannelType channelType, TAudioChannelSampleRate sampleRate, TMultimediaAudioOutput audioOutput, bool followSilentMode, int timeToWait, int sessionHandle, TAudioControl_AudioFormat audioFormat, int* pChannelHandle); //0x9C
  virtual int unk_0xA0(); //0xA0
  virtual int AudioChannel_Close(int channelHandle); //0xA4
  virtual int unk_0xA8(); //0xA8
  virtual int unk_0xAC(); //0xAC
  virtual int AudioSession_Begin2(IRoot* pICBAudioControl, u16 msgBase, int clientData, TAudioControl_SessionType sessionType, int* pSessionHandle); //0xB0
  virtual int AudioSession_End(int sessionHandle); //0xB4
  virtual int unk_0xB8(); //0xB8
  virtual int Volume_Set(TAudioControl_VolumeType volumeType, char pVolume); //0xBC
  virtual int Volume_Get(TAudioControl_VolumeType volumeType, char* pVolume); //0xC0
  virtual int ChannelVolume_Fade(int channelHandle, TAudioControl_FadeDirection fadeDirection, TAudioControl_FadeReason fadeReason); //0xC4
  virtual int ChannelVolume_Set2(int channelHandle, char relVolume); //0xC8
  virtual int ChannelVolume_Set(int channelHandle, char volume); //0xCC
  virtual int ChannelVolume_Get(int channelHandle, char* pVolume);
  virtual int IncreaseVolume(TAudioControl_VolumeType volumeType, char* pNewVolume);
  virtual int DecreaseVolume(TAudioControl_VolumeType volumeType, char* pNewVolume);
  virtual int unk_0xDC();
  virtual int IncreasingRing_Set(bool increasingRingEnabled); //0xE0
  virtual int IncreasingRing_Get(bool* pIncreasingRingEnabled); //0xE4
  virtual int MicrophoneMute_Set(bool muteOn); //0xE8
  virtual int MicrophoneMute_Get(bool* pMuteOn); //0xEC
  virtual int unk_0xF0();
  virtual int EqualizerGain_Set(int sessionHandle, TAudioControl_EqualizerBand equalizerBand, TAudioControl_EqualizerGain equalizerGain);
  virtual int EqualizerGain_Get(int sessionHandle, TAudioControl_EqualizerBand equalizerBand, TAudioControl_EqualizerGain* pEqualizerGain);
  virtual int unk_0xFC();
  virtual int unk_0x100();
  virtual int unk_0x104();
  virtual int unk_0x108();
  virtual int unk_0x10C();
  virtual int unk_0x110();
  virtual int unk_0x114();
  virtual int unk_0x118();
  virtual int unk_0x11C();
  virtual int unk_0x120();
  virtual int unk_0x124();
  virtual int unk_0x128();
  virtual int unk_0x12C();
  virtual int unk_0x130();
  virtual int unk_0x134();
  virtual int unk_0x138();
  virtual int unk_0x13C();
  virtual int unk_0x140();
  virtual int unk_0x144();
  virtual int unk_0x148();
  virtual int unk_0x14C();
  virtual int unk_0x150();
  virtual int EqualizerCenterFreq_Get(int sessionHandle, TAudioControl_EqualizerBand  equalizerBand, int* pEqualizerCenterFreq); //0x154
  virtual int DebugMenu_GetString(TAudioControl_DebugMenuString* pBuffer); //0x158
  virtual int AudioRouting_Get(TAudioControl_AudioRouting* pAudioRouting); //0x15C
  virtual int SpeakerPhone_Set(int sessionHandle, bool speakerPhoneEnabled); //0x160
  virtual int SpeakerPhone_Set2(int sessionHandle, TAudioControl_SpeakerMode speakerMode); //0x164
  virtual int SpeakerPhone_Get(int sessionHandle, bool* pSpeakerPhoneEnabled); //0x168
  virtual int ComfortToneStandard_Set(TAudioControl_ComfortToneStandard comfortToneStandard); //0x16C
  virtual int SilentMode_Set(bool silentModeEnabled); //0x170
  virtual int SilentMode_Get(bool* silentModeEnabled); //0x174
  virtual int TTYMode_Set(TAudioControl_TTYMode TTYMode); //0x178
  virtual int TTYMode_Get(TAudioControl_TTYMode* pTTYMode); //0x17C
  virtual int HACMode_Set(TAudioControl_HACMode HACMode); //0x180
  virtual int HACMode_Get(TAudioControl_HACMode* pHACMode); //0x184
  virtual int VibratorState_Set(TAudioControl_VibratorState vibratorState); //0x188
  virtual int VibratorState_Get(TAudioControl_VibratorState* pVibratorState); //0x18C
  virtual int Vibrator_Start(int period, int dutyCycle, int duration); //0x190
  virtual int Vibrator_Stop(void); //0x194
  virtual int Callstate_Set(TAudioControl_CallType callType, TAudioControl_CallState callState); //0x198
  virtual int unk_0x19C(); //0x19C
  virtual int Camera_FollowSilentMode_Set(bool followSilentMode); //0x1A0
  virtual int Camera_FollowSilentMode_Get(bool* pFollowSilentMode); //0x1A4
  virtual int AudioFocus_Request(int sessionHandle); //0x1A8
  virtual int LightPlayer_Enable(int sessionHandle, bool enable); //0x1AC
  virtual int AudioChannel_Mute(int channelHandle, bool mute); //0x1B0
  virtual int AudioChannel_ConnectToDevice(int channelHandle); //0x1B4
  virtual int AudioChannel_Disconnect(int channelHandle); //0x1B8
  virtual int AudioVisualizer_Enable(int channelHandle, bool enable); //0x1BC
};

class IAudioControlManager: public IRoot
{
public:
  virtual int CreateAudioControl(IAudioControl** ppIAudioControl);
};

#endif
