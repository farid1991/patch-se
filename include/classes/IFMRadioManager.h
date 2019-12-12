#ifndef _IFMRADIOMANAGER_H_
#define _IFMRADIOMANAGER_H_

#include "..\\include\types\Basic_types.h"
#include "..\\include\types\FMRadio_types.h"
#include "..\\include\types\OPA_types.h"

/**
 * Callback interfaces for FM Radio driver
 */
class ICBFMRadio : IRoot 
{
public:
  virtual void OnSearchFrequencyFinished(FUint16 frequency, FUint16 programIdentifier);
  virtual void OnAutoStoreFinished(FmRadio_ProgramInfo_t* channelList, FUint8 nbrChannelsFound);
  virtual void OnErrorOccured( FMRadio_ErrorCode_t errorCode_p );
  virtual void OnStereoReceptionChanged( bool stereoOn );
  virtual void OnReceptionLevelChanged( FUint8 level );
  virtual void OnRDSstatusChanged( bool RDSstatus );
  virtual void OnTPstatusChanged( bool TPstatus);
  virtual void OnAFSwitchFrequency( FUint16 frequency);
  virtual void OnAFUpdate(void);
  virtual void OnAFUpdateFinished(void);
  virtual void OnTASwitchFrequency( FUint16 frequency );
  virtual void OnTAEndTransmission( void );
  virtual void OnPSNameChanged( void );
  virtual void OnPISearch( void );
  virtual void OnPISearchFinished( FUint16 frequency,  FUint16 programInformation);
  virtual void OnPIFound( FUint16 frequency,  FUint16 programInformation);
};

class IFMRadio: public IRoot
{
public:
  /**
   * Method to enable/disable amplifier for internal antenna.
   *
   * @param[in] enable  True to enable amplifier..
   */
  virtual int EnableAntennaAmplifier( TBool enable );
  
  /**
   * Method called to subscribe to the FM Radio driver in order to receive 
   * messages.
   *
   * @param[in]  pICBFMRadio          Reference to the callback interface.
   * @param[in]  msgBase              Needed for callback interface.
   * @param[in]  clientData           Needed for callback interface.
   * @param[out] pSubscriptionHandle  Handle for the current subscription. The 
   *                                  parameter is a reference and must not be 
   *                                  NULL.
   */
  virtual int SubscribeToFMRadio(ICBFMRadio* pICBFMRadio, 
                                 TMsgBase    msgBase,
                                 TClientData clientData,
                                 THnd*       pSubscriptionHandle);
  
  /**
   * Method called to unsubscribe from the FM Radio driver.
   *
   * @param[in] subscriptionHandle  Handle which identifies the subscription.      
   */
  virtual int UnsubscribeToFMRadio( THnd subscriptionHandle);
  
  /**
   * Rerieves the current supported functionality (mostly RDS related)
   *
   * @param[out] pSupportedFunctionality  Bitfield stating supported functionality. 
   *                                      The parameter is a reference and must not 
   *                                      be NULL.
   */
  virtual int GetSupportedFunctionality( FMRadio_FunctionalityBitfield_t *pSupportedFunctionality);
  
  /**
   * Method to set the FM Radio chip in different modes
   *
   * @param[in] mode  The mode to set the FM Radio chip in.
   */
  virtual int SetPowerMode( FMRadio_PowerMode_t Mode);
  
  /**
   * Method to get the current frequency band
   *
   * @param[out] pBand  Stating if it is a Japanese or European FM radio 
   *                    band currently set. The parameter is a reference
   *                    and must not be NULL.
   */
  virtual int GetFrequencyBand( FMRadio_FrequencyBand_t* pBand );
  
  /**
   * Method to set the current frequency band
   *
   * @param[in] band  Stating if a Japanese or European band shall be set
   */
  virtual int SetFrequencyBand( FMRadio_FrequencyBand_t Band );
  
  /**
   * Method to set the frequency precision used by client
   * NB! This must be done before any frequency is set!
   *
   * @param[in] precision  Set if we are using 10kHz or 100kHz(default) precision
   */
  virtual int SetFrequencyPrecision( FMRadio_FrequencyPrecision_t precision );
  
  /**
   * Method to set a specified program. If PI available, it overrides 
   * frequency.
   *
   * @param[in] frequency          The selected frequency (in 100 kHz)
   * @param[in] programIdentifier  The PI code (Zero if not available)
   */
  virtual int SetProgram( FUint16 frequency, FUint16 programIdentifier );
  
  /**
   * Method to get the current program. Waits with the answer until chip
   * sets LD (Lock Detect), otherwise a wrong frequency may be read.
   *
   * @param[out] pFrequency          The frequency (in 100 kHz).The parameter 
   *                                 is a reference and must not be NULL.
   * @param[out] pProgramIdentifier  The PI code (Zero if not available). The 
   *                                 parameter is a reference and must not be 
   *                                 NULL.
   */
  virtual int GetProgram( FUint16* pFrequency, FUint16* pProgramIdentifier );
  
  /**
   * Method to start an automatic search for a channel.
   *
   * @param[in] direction  Specifies the search direction (Up/Down)
   */
  virtual int SearchFrequency( FMRadio_Search_Direction_t direction );
  
  /**
   * Method to stop an ongoing search frequency
   */
  virtual int StopSearchFrequency(void);
  
  /**
   * Method to start an automatic store of the strongest channels in a list.
   * 
   * @param[in] listSize  Number of program positions in the list
   */
  virtual int StartAutoStore( FUint8 listSize );
  
  /**
   * Method to stop an ongoing AutoStore.
   */
  virtual int StopAutoStore(void);
  
  /**
   * Method to Mute/Unmute the radio.
   *
   * @param[in] muteMode  SoftMute (NOT SUPPORTED)/HardMute. Hardmute is always 
   *                      set, no matter what the input is.
   * @param[in] mute      TRUE = Mute on, FALSE = Mute off.
   */
  virtual int Mute( FMRadio_MuteOption_t muteMode, TBool mute );
  
  /**
   * Method to force mono sound.
   *
   * @param[in] forceMono  TRUE = mono, FALSE = stereo if stereo reception 
   *                       available.
   */
  virtual int ForceMono( TBool forceMono);
  
  /**
    * Method to get Stereo/Mono indication
    *
    * @param[out] pStereoOn  True = Stereo, False = Mono. The parameter
    *                        is a reference and must not be NULL. 
    */
  virtual int GetStereoReception( TBool* pStereoOn);
  
  /**
   * Method to activate RDS functionality
   *
   * @param[in] RDSFlags  Shows which features that is activated (AF|TA|PTY etc).
   */
  virtual int ActivateRDSFunctionality( FMRadio_RDSFlag_Bitfield_t RDSFlags);
  
  /**
    * Method to get the Program Service Name (RDS data of characters with coding 
    * of the station name)
    *
    * @param[out] pPSNameBuffer  The buffer to save the PS name in (characters in 
    *                            unicode). The parameter is a reference and must 
    *                            not be NULL.
    * @param[in]  bufferSize     The byte size of the buffer
    */
  virtual int GetPSName( TChar* pPSNameBuffer, FUint8 bufferSize); 
  
  /**
    * Method to stop AF update or PI Search
    */
  virtual int StopAFupdateAndPIsearch(void);
  
  /**
    * Method to trigger to send a callback event as soon as RDS-data has arrived.
    */
  virtual int CheckRDSstatus(void);
  
  virtual int GetTPstatus( TBool *pTPstatus);
};


class IFMRadioManager: public IRoot
{
public:
  /**
  * Method to create an instance of the FM Radio server
  *
  * @param ppIFMRadio  Pointer to the interface. The  parameter 
  *                         is a reference and must not be NULL.
  */
  virtual int CreateFMRadio( IFMRadio** ppIFMRadio);
};

#endif
