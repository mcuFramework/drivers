/**
 * Copyright (c) 2020 ZxyKira
 * All rights reserved.
 * 
 * SPDX-License-Identifier: MIT
 */
#ifndef DRIVER_BCBBF717_2A77_4A94_90C7_4B489C0F36B3
#define DRIVER_BCBBF717_2A77_4A94_90C7_4B489C0F36B3

/* ****************************************************************************************
 * Include
 */  

//-----------------------------------------------------------------------------------------
#include "mcuf.h"

//-----------------------------------------------------------------------------------------

/* ****************************************************************************************
 * Namespace
 */  
namespace driver::wirelesstag{
  class WT32ETH01;
}


/* ****************************************************************************************
 * Class/Interface/Struct/Enum
 */  
class driver::wirelesstag::WT32ETH01 extends mcuf::io::RingBuffer implements
  public mcuf::io::InputStream,
  public mcuf::io::OutputStream,
  public hal::serial::SerialPortEvent{

  /* **************************************************************************************
   * Enum ConnectType
   */
  public:

    /**
     * @brief 
     * 
     */
    enum struct ConnectType : char{
      TCP,
      UDP
    };

  /* **************************************************************************************
   * Variable <Public>
   */

  /* **************************************************************************************
   * Variable <Protected>
   */

  /* **************************************************************************************
   * Variable <Private>
   */
  private:

  /* **************************************************************************************
   * Abstract method <Public>
   */

  /* **************************************************************************************
   * Abstract method <Protected>
   */

  /* **************************************************************************************
   * Construct Method
   */
  public: 

    /**
     * @brief Construct a new WT32ETH01 object
     * 
     * @param serialPort 
     * @param enablePin 
     * @param bufferSize 
     */
    WT32ETH01(hal::serial::SerialPort& serialPort, hal::general::GeneralPin& enablePin, uint32_t bufferSize);

    /**
     * @brief Destroy the WT32ETH01 object
     * 
     */
    virtual ~WT32ETH01(void) override;

  /* **************************************************************************************
   * Operator Method
   */

  /* **************************************************************************************
   * Public Method <Static>
   */

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::InputStream
   */
  public:
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool abortRead(void) override;  
    
    /**
     * @brief 
     * 
     * @return true is busy.
     * @return false isn't busy.
     */
    virtual bool readBusy(void) override;
    
    /**
     * @brief nonblocking
     * 
     * @param byteBuffer 
     * @param attachment 
     * @param handler 
     * @return true successful.
     * @return false fail.
     */
    virtual bool read(mcuf::io::ByteBuffer& byteBuffer, 
                      void* attachment,
                      mcuf::io::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool read(mcuf::io::ByteBuffer& byteBuffer, mcuf::io::Future& future) override;

    /**
     * @brief 
     * 
     * @param value 
     * @param attachment 
     * @param handler 
     * @return true 
     * @return false 
     */
    virtual bool skip(int value, 
                      void* attachment,
                      mcuf::io::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief 
     * 
     * @param value 
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool skip(int value, mcuf::io::Future& future) override;

  /* **************************************************************************************
   * Public Method <Override> - mcuf::io::OutputStream
   */
  public:
    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    virtual bool abortWrite(void) override;
    
    /**
     * @brief 
     * 
     * @return true is busy.
     * @return false isn't busy.
     */
    virtual bool writeBusy(void) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @param attachment 
     * @param handler 
     * @return true successful.
     * @return false fail.
     */
    virtual bool write(mcuf::io::ByteBuffer& byteBuffer, 
                      void* attachment,
                      mcuf::io::CompletionHandler<int, void*>* handler) override;

    /**
     * @brief 
     * 
     * @param byteBuffer 
     * @param future 
     * @return true 
     * @return false 
     */
    virtual bool write(mcuf::io::ByteBuffer& byteBuffer, mcuf::io::Future& future) override;

  /* **************************************************************************************
   * Public Method <Override> - hal::serial::SerialPortEvent
   */
  public:
    /**
     * @brief 
     * 
     * @param status handle status
     * @param result 0 = successful, other = remaining byte count.
     * @param attachment user data
     */
    virtual void onSerialPortEvent(hal::serial::SerialPortStatus status, 
                                   int result,
                                   void* attachment) override;
                      
  /* **************************************************************************************
   * Public Method
   */
  public:

    /**
     * @brief Get the Local Address object
     * 
     * @return mcuf::net::SocketAddress 
     */
    mcuf::net::SocketAddress getLocalAddress(void);

    /**
     * @brief Get the Remode Address object
     * 
     * @return mcuf::net::SocketAddress 
     */
    mcuf::net::SocketAddress getRemodeAddress(void);

    /**
     * @brief Get the Mac Address object
     * 
     * @return mcuf::net::MediaAccessControlAddress 
     */
    mcuf::net::MediaAccessControlAddress getMacAddress(void);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool isConnect(void);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool disconnect(void);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool init(void);

    /**
     * @brief 
     * 
     * @return true 
     * @return false 
     */
    bool reset(void);

    /**
     * @brief 
     * 
     * @param type 
     * @param remoteAddress 
     * @param future 
     * @return true 
     * @return false 
     */
    bool connect(ConnectType type, mcuf::net::SocketAddress remoteAddress, mcuf::io::Future* future);

    /**
     * @brief 
     * 
     * @param type 
     * @param remoteAddress 
     * @param destPort 
     * @param future 
     * @return true 
     * @return false 
     */
    bool listen(ConnectType type, mcuf::net::SocketAddress remoteAddress, uint16_t destPort, mcuf::io::Future* future);

  /* **************************************************************************************
   * Protected Method <Static>
   */

  /* **************************************************************************************
   * Protected Method <Override>
   */

  /* **************************************************************************************
   * Protected Method
   */

  /* **************************************************************************************
   * Private Method <Static>
   */

  /* **************************************************************************************
   * Private Method <Override>
   */

  /* **************************************************************************************
   * Private Method
   */
  private:
    
    /**
     * @brief 
     * 
     */
    void disableEcho(void);
    
    /**
     * @brief 
     * 
     */
    void waitStandby(void);

    /**
     * @brief 
     * 
     */
    void updateAddress(void);
};

/* ****************************************************************************************
 * End of file
 */ 

#endif /* DRIVER_BCBBF717_2A77_4A94_90C7_4B489C0F36B3 */
