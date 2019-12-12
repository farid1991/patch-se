#ifndef _ISOCKETS_H_
#define _ISOCKETS_H_

static const UUID CID_CSocketManager = {0x71, 0xBC, 0xD4, 0x92, 0xA9, 0xA7, 0x40, 0x47, 0x8E, 0x18, 0x66, 0x2F, 0x8F, 0x41, 0xAA, 0x0D};
//db3210/db3200
static const UUID IID_ISocketManager = {0xB6, 0x09, 0x50, 0xA3, 0x60, 0x09, 0x4D, 0x2E, 0x87, 0x73, 0xA9, 0x7B, 0x7B, 0x3E, 0x5A, 0x9D};
//db3150
static const UUID IID_ISocketManager3150 = {0xB0, 0xA5, 0x48, 0xC2, 0x98, 0xB9, 0x42, 0xEC, 0xA4, 0xBF, 0x8C, 0x07, 0xBC, 0x38, 0xAA, 0x97};
//db2020. ��������� ����� - ISocketManager_CreateSocketUserAgent
static const UUID IID_ISocketManager2020 = {0x30, 0x0C, 0x3D, 0x0B, 0x99, 0x6F, 0x44, 0x63, 0x90, 0x53, 0xFE, 0x7E, 0x54, 0x55, 0x22, 0x87};
//db2010. ��������� ����� - ISocketManager_CreateSocketUserAgent
static const UUID IID_ISocketManager2010 = {0x38, 0x0A, 0x7D, 0x81, 0x02, 0xC7, 0x49, 0x71, 0x81, 0x2B, 0x9D, 0x7C, 0x74, 0xE5, 0x0F, 0xBE};

//a2
static UUID IID_ICBSocket = {0x9E, 0xAA, 0xFF, 0x26, 0x12, 0xD9, 0x49, 0xB2, 0x92, 0xBD, 0x89, 0xFE, 0xF2, 0x8C, 2, 0x70};
//db2020
static UUID IID_ICBSocket2020 = {0xD8, 0xD7, 0x4D, 0xB6, 0xC8, 0x3E, 0x41, 0x35, 0xBA, 0x32, 9, 0x70, 0x72, 0x85, 3, 0x2D};

static UUID IID_IAsyncHostNameResolver = {0xCE, 0x94, 0x96, 0x77, 0x0B, 0x6E, 0x45, 0x1B, 0x91, 0xA5, 0x0E, 0x23, 0xF5, 0x9B, 0xCE, 0x87};
static UUID IID_ICBAsyncHostNameResolver = {0x4D, 0x5D, 0x80, 0xB7, 0xD8, 0x9F, 0x40, 0xEA, 0x8C, 0x21, 0x9D, 0x75, 0x22, 0xD9, 0x48, 0x6B};


class ISocketManager;
class ISocket;
class ICBSocket;
class IHostNameResolver;
class ISocketUtility;
class ITransportLayerSecurityAgent;
class ISocketUserAgent;
class IAsyncHostNameResolver;
class ICBAsyncHostNameResolver;


#define EWOULDBLOCK                             0x80000002
#define EBADF                                   0x80200403

#define SOCKET_UED_BAD_FILE                     0x80000001
#define SOCKET_UED_NO_MEMORY                    0x80000003
#define SOCKET_UED_OPERATION_NOT_SUPPORTED      0x80000010
#define SOCKET_UED_ADDRESS_FAMILY_NOT_SUPPORTED	0x80000012
#define SOCKET_UED_ADDRESS_NOT_AVAILABLE        0x80000014
#define SOCKET_UED_NETWORK_UNREACHABLE          0x80000016
#define SOCKET_UED_CONNECTION_RESET             0x80000019
#define SOCKET_UED_ALREADY_CONNECTED            0x8000001A
#define SOCKET_UED_TIMEOUT                      0x8000001D
#define SOCKET_UED_CONNECTION_REFUSED           0x8000001E
#define SOCKET_UED_HOST_UNREACHABLE             0x80000020
#define SOCKET_UED_ALREADY                      0x80000021
#define SOCKET_UED_IN_PROGRESS                  0x80000022

#define SOCKET_EVENT_READ           0x1
#define SOCKET_EVENT_WRITE          0x2
#define SOCKET_EVENT_ACCEPT         0x8
#define SOCKET_EVENT_CONNECT        0x10
#define SOCKET_EVENT_CLOSE          0x20
//#define SOCKET_EVENT_SECURE_CONNECT 0x4 || 0x40
//#define SOCKET_EVENT_OUTOFBOUND     0x4 || 0x40

#define OPTION_LEVEL_IPV4    0x0
#define OPTION_LEVEL_SOCKET  0x1
#define OPTION_LEVEL_TCP     0x6

#ifndef WIN32
#define SO_BROADCAST         0x0
#define SO_ACCEPTCONN        0x2
#define SO_LINGER            0x5
#define SO_SNDBUF            0x7
#define SO_RCVBUF            0x8
#define SO_ERROR             0x9
#define SO_TYPE              0xA
#define SO_RCVLOWAT          0xD
#define SO_SNDLOWAT          0xE
#define SO_RCVTIMEO          0xF
#define SO_SNDTIMEO          0x10
#define SO_KEEPALIVE         0x15
#define TCP_NODELAY          0x12D
#define TCP_KEEPIDLE         0x135
#define TCP_KEEPINTVL        0x136
#define TCP_KEEPCNT          0x137
#else
#define SO_SNDBUF       0x1001          /* send buffer size */
#define SO_RCVBUF       0x1002          /* receive buffer size */
#define SO_SNDLOWAT     0x1003          /* send low-water mark */
#define SO_RCVLOWAT     0x1004          /* receive low-water mark */
#define SO_SNDTIMEO     0x1005          /* send timeout */
#define SO_RCVTIMEO     0x1006          /* receive timeout */
#define SO_ERROR        0x1007          /* get error status and clear */
#define SO_TYPE         0x1008          /* get socket type */
#endif


typedef struct in_addr
{
  unsigned char s_addr[4];
} IN_ADR;


typedef struct in6_addr
{
  unsigned char s_addr[16];
} IN6_ADR;


struct sockaddr
{
  unsigned char   sin_length;
  unsigned char   sin_family;
  unsigned char   sin_zero[30];
};

struct sockaddr_in
{
  unsigned char       sin_length;     // ������ ���������
  unsigned char       sin_family;     // ��������� �������
  unsigned short int  sin_port;       // ����� �����
  in_addr             sin_addr;       // IP4-�����
  unsigned char       sin_zero[8];    // "����������" �� ������� ��������� sockaddr
};

struct sockaddr_in6
{
  unsigned char     sin_length;     // ������ ���������
  unsigned char     sin_family;     // ��������� �������
  unsigned short    sin6_port;      // ����� �����
  unsigned long     sin6_flowinfo;
  in6_addr          sin6_addr;      // IP6-�����
  unsigned long     sin6_scope_id;  // "����������" �� ������� ��������� sockaddr
};


struct sockaddr_short
{
  unsigned char     sin_length;     // ������ ���������
  unsigned char     sin_family;     // ��������� �������
  union
  {
    in_addr         sin_addr;       // IP4-�����
    in6_addr        sin6_addr;      // IP6-�����
  };
};


struct linger
{
  unsigned long     l_onoff;
  unsigned long     l_linger;
};


enum Socket_Type
{
  SOCK_STREAM = 1,
  SOCK_DGRAM = 2,
  SOCK_RAW = 3
};


enum Address_Family
{
  AF_UNSPEC = 0,
  AF_UNIX = 1,
  AF_INET = 2,
  AF_INET6 = 3,
};

typedef struct addrinfo
{
  int               ai_flags;
  int               ai_family;
  int               ai_socktype;
  int               ai_protocol;
  int               ai_addrlen;
  char*             ai_canonname;
  union
  {
    sockaddr_in*    ai_addr;
    sockaddr_in6*   ai6_addr;
  };
  addrinfo*         ai_next;
  int               unk;
} ADDRINFO, *PADDRINFO;


class ICBSocket : public IRoot
{
public:
  virtual void OnOutOfBandData(int Error, ISocket* pISocket, void* ClientData) = NULL;
  virtual void OnAccept(int Error, ISocket* pISocket, void* ClientData) = NULL;
  virtual void OnConnect(int Error, ISocket* pISocket, void* ClientData) = NULL;
  virtual void OnClose(int Error, ISocket* pISocket, void* ClientData) = NULL;
  virtual void OnSend(int Error, ISocket* pISocket, void* ClientData) = NULL;
  virtual void OnSecureConnect(int Error, ISocket* pISocket, void* ClientData) = NULL;
  virtual void OnReceive(int Error, int unk, int BufferLength, void* ClientData) = NULL;
};


class ICBAsyncHostNameResolver: public IRoot
{
public:
  virtual int method1();
  virtual int OnGetAddressInfo(int error, ADDRINFO* pResult, void* ClientData);
};

class IAsyncHostNameResolver: public IRoot
{
public:
  virtual int method1();
  virtual int GetAddressInfo(ICBAsyncHostNameResolver* pICBAsyncHostNameResolver, int unk1, void* ClientData, char* pNodeName, char* port, ADDRINFO* pHints, int unk2);
  virtual int method3();
};

class ISocketUserAgent: public IRoot
{
public:
  virtual int GetPort(wchar_t port); //??
  virtual int SetSocket(ISocket* pISocket);
  virtual int RemoveSocket(ISocket* pISocket);
  virtual int Select(ISocket* pISocket);
};

class ITransportLayerSecurityAgent: public IRoot
{
public:
  virtual int PinRespond();
  virtual int ClientAuthenticateRespond();
  virtual int ServerAuthenticateRespond();
  virtual int GetSecureConnectionInfo();
};

#ifdef DB2020
class ISocketUtility2020: public IRoot
{
public:
  virtual int NetworkToHost16(wchar_t nPortNetworkOrder, wchar_t* nPortHostOrder);
  virtual int NetworkToHost32(int IPNetworkOrder, int* IPHostOrder);
  virtual int HostToNetwork16(wchar_t nPortHostOrder, wchar_t* nPortNetworkOrder);
  virtual int HostToNetwork32(int IPHostOrder, int* IPNetworkOrder);
  virtual int method5();
  virtual int inet_ntop();
  virtual int MakeSocketIpv4Address(in_addr* sin_addr, wchar_t nPortNetworkOrder, sockaddr* socketAddress);
  virtual int MakeSocketIpv6Address(in6_addr* sin_addr, wchar_t nPortNetworkOrder, unsigned long sin6_flowinfo, unsigned long sin6_scope_id, sockaddr* socketAddress);
  virtual int MakeSocketAddress(sockaddr_short* sockAddress, wchar_t nPortNetworkOrder, sockaddr* socketAddress);
};

#else

class ISocketUtility: public IRoot
{
public:
  virtual int NetworkToHost16(wchar_t nPortNetworkOrder, wchar_t* nPortHostOrder);
  virtual int NetworkToHost32(int IPNetworkOrder, int* IPHostOrder);
  virtual int HostToNetwork16(wchar_t nPortHostOrder, wchar_t* nPortNetworkOrder);
  virtual int HostToNetwork32(int IPHostOrder, int* IPNetworkOrder);
  virtual int method5();
  virtual int inet_ntop();
  virtual int Host_GetNetworkAddress(int IPHostOrder, int* NetworkAddress);
  virtual int MakeSocketIpv4Address(in_addr* sin_addr, wchar_t nPortNetworkOrder, sockaddr* socketAddress);
  virtual int MakeSocketIpv6Address(in6_addr* sin_addr, wchar_t nPortNetworkOrder, unsigned long sin6_flowinfo, unsigned long sin6_scope_id, sockaddr* socketAddress);
  virtual int MakeSocketAddress(sockaddr_short* sockAddress, wchar_t nPortNetworkOrder, sockaddr* socketAddress);
};
#endif


class IHostNameResolver: public IRoot
{
public:
  virtual int method1(sockaddr_short* socketAddress);
  virtual int method2(char* pNodeName);
  virtual int method3(char* pNodeName, int unk);
  virtual int SetHostXXX(char* pNodeName);
  virtual int GetHostXXX(char* pNodeName);
  virtual int GetFirstHost(char* pNodeName);
  virtual int GetLastHost(char* pNodeName);
  virtual int GetFirstAddress(sockaddr_short* socketAddress);
  virtual int GetLastAddress(sockaddr_short* socketAddress);
  virtual int method10();
  virtual int GetAddressInfo(const char* pNodeName, const char* pPortNum, ADDRINFO* pHints, PADDRINFO* pResult);
  virtual int FreeAddressInfo(addrinfo* ai);
};


#ifdef DB2020
class ISocket2020: public IRoot
{
public:
  virtual int Open(Address_Family af, Socket_Type type, int protocol);
  virtual int Close();
  virtual int Accept();
  virtual int RegisterForEvents(ICBSocket* pICBSocket, int MsgBase, void* ClientData, int events); //������ ���������� (NULL/*pICBSocket?*/, FASTTRACK_APPLICATION_MSGBASE_SOCKET, 0, SOCKET_EVENT_READ | SOCKET_EVENT_WRITE | SOCKET_EVENT_CONNECT | SOCKET_EVENT_CLOSE )
  virtual int Bind(sockaddr* addr);
  virtual int Connect(sockaddr* addr);
  virtual int F_GETFL();
  virtual int F_SETFL(int unk);
  virtual int method1();
  virtual int getpeername();
  virtual int GetLocalAddress(sockaddr* addr);
  virtual int GetOption(int level, int optname, char* optval, int optlen);
  virtual int SetOption(int level, int optname, char* optval, int optlen);
  virtual int Listen();
  virtual int Read(int buf_size, char* buf, int* readen_len);
  virtual int Receive(int flags, int buf_size, char* buf, int* received_len);
  virtual int ReceiveFrom(int flags, sockaddr* socketAddress, int buf_size, char* buf, int* received_len);
  virtual int recvmsg();
  virtual int Send(int flags, int buf_size, char* buf, int* sent_len);
  virtual int sendmsg();
  virtual int SendTo(int flags, sockaddr* socketAddress, int buf_size, char* buf, int* sent_len);
  virtual int Shutdown(int how);
  virtual int Write(int buf_size, char* buf, int* sent_len);
  virtual int SecureConnect(wchar_t* pNodeName, wchar_t port);
  virtual int method2();
  virtual int method3();
  virtual int method4();
};
#else
class ISocket: public IRoot
{
public:
  virtual int Open(Address_Family af, Socket_Type type, int protocol);
  virtual int Close();
  virtual int Accept();
  virtual int Bind(sockaddr* addr);
  virtual int Connect(sockaddr* addr);
  virtual int F_GETFL();
  virtual int F_SETFL(int unk);
  virtual int getpeername();
  virtual int GetLocalAddress(sockaddr* addr);
  virtual int GetOption(int level, int optname, char* optval, int optlen);
  virtual int SetOption(int level, int optname, char* optval, int optlen);
  virtual int Listen();
  virtual int Shutdown(int how);
  virtual int method1();
  virtual int method2();
  virtual int RegisterForEvents(ICBSocket* pICBSocket, int MsgBase, void* ClientData, int events); //������ ���������� (NULL/*pICBSocket?*/, FASTTRACK_APPLICATION_MSGBASE_SOCKET, 0, SOCKET_EVENT_READ | SOCKET_EVENT_WRITE | SOCKET_EVENT_CONNECT | SOCKET_EVENT_CLOSE )
  virtual int Read(int buf_size, char* buf, int* readen_len);
  virtual int Receive(int flags, int buf_size, char* buf, int* received_len);
  virtual int ReceiveFrom(int flags, sockaddr* socketAddress, int buf_size, char* buf, int* received_len);
  virtual int recvmsg();
  virtual int Send(int flags, int buf_size, char* buf, int* sent_len);
  virtual int sendmsg();
  virtual int SendTo(int flags, sockaddr* socketAddress, int buf_size, char* buf, int* sent_len);
  virtual int Write(int buf_size, char* buf, int* sent_len);
  virtual int SecureConnect(wchar_t* pNodeName, wchar_t port);
  virtual int method4();
  virtual int method5();
};
#endif

class ISocketManager: public IRoot
{
public:
  virtual int CreateSocket(ISocket** ppISocket);
  virtual int CreateHostNameResolver(IHostNameResolver** ppIHostNameResolver);
  virtual int CreateSocketUtility(ISocketUtility** ppISocketUtility);
  virtual int method3();
  virtual int method4();
  virtual int CreateTransportLayerSecurityAgent(ITransportLayerSecurityAgent** ppITransportLayerSecurityAgent);
  virtual int CreateSocketUserAgent(wchar_t port, ISocketUserAgent** ppISocketUserAgent);
  virtual int CreateZeroCopySocketController(IRoot** ppIZeroCopySocketController);
  virtual int CreateZeroCopySecureSocketController(IRoot** ppIZeroCopySecureSocketController);
};

#endif
