
#pragma once

#include <windows.h>

//	设备类型
enum enIKCDevs
{
	IKC_DEV_ZLG = 0,
	IKC_DEV_PEAK,
	IKC_DEV_KVASER,
	IKC_DEV_ZLG_E,
	IKC_PCI9840_ZLG,
};

//	状态码
enum enIKSCode
{
	IKS_ERROR_OK = 0,	//	正常
	IKS_ERROR_INIT,		//	初始化失败
	IKS_ERROR_UNINIT,	//	卸载失败
	IKS_ERROR_RESET,	//	复位失败
	IKS_ERROR_OPEN,		//	打开失败
	IKS_ERROR_READ,		//	接收失败
	IKS_ERROR_WRITE,	//	发送失败
	IKS_ERROR_CLOSE,	//	关闭失败
	IKS_ERROR_STATE,	//	错误状态
};

// PCAN错误码
// Represent the PCAN error and status codes 
//
#define PCAN_ERROR_OK            0x00000  // No error 
#define PCAN_ERROR_XMTFULL       0x00001  // Transmit buffer in CAN controller is full
#define PCAN_ERROR_OVERRUN       0x00002  // CAN controller was read too late
#define PCAN_ERROR_BUSLIGHT      0x00004  // Bus error: an error counter reached the 'light' limit
#define PCAN_ERROR_BUSHEAVY      0x00008  // Bus error: an error counter reached the 'heavy' limit
#define PCAN_ERROR_BUSOFF        0x00010  // Bus error: the CAN controller is in bus-off state
#define PCAN_ERROR_ANYBUSERR     (PCAN_ERROR_BUSLIGHT | PCAN_ERROR_BUSHEAVY | PCAN_ERROR_BUSOFF) // Mask for all bus errors
#define PCAN_ERROR_QRCVEMPTY     0x00020  // Receive queue is empty
#define PCAN_ERROR_QOVERRUN      0x00040  // Receive queue was read too late
#define PCAN_ERROR_QXMTFULL      0x00080  // Transmit queue is full
#define PCAN_ERROR_REGTEST       0x00100  // Test of the CAN controller hardware registers failed (no hardware found)
#define PCAN_ERROR_NODRIVER      0x00200  // Driver not loaded
#define PCAN_ERROR_HWINUSE       0x00400  // Hardware already in use by a Net
#define PCAN_ERROR_NETINUSE      0x00800  // A Client is already connected to the Net
#define PCAN_ERROR_ILLHW         0x01400  // Hardware handle is invalid
#define PCAN_ERROR_ILLNET        0x01800  // Net handle is invalid
#define PCAN_ERROR_ILLCLIENT     0x01C00  // Client handle is invalid
#define PCAN_ERROR_ILLHANDLE     (PCAN_ERROR_ILLHW | PCAN_ERROR_ILLNET | PCAN_ERROR_ILLCLIENT)  // Mask for all handle errors
#define PCAN_ERROR_RESOURCE      0x02000  // Resource (FIFO, Client, timeout) cannot be created
#define PCAN_ERROR_ILLPARAMTYPE  0x04000  // Invalid parameter
#define PCAN_ERROR_ILLPARAMVAL   0x08000  // Invalid parameter value
#define PCAN_ERROR_UNKNOWN       0x10000  // Unknow error
#define PCAN_ERROR_ILLDATA       0x20000  // Invalid data, function, or action
#define PCAN_ERROR_INITIALIZE    0x40000  // Channel is not initialized
#define PCAN_ERROR_ILLOPERATION  0x80000  // Invalid operation

//ZLGCAN错误码
//CAN错误码
#define	ERR_CAN_OVERFLOW			0x0001	//CAN控制器内部FIFO溢出
#define	ERR_CAN_ERRALARM			0x0002	//CAN控制器错误报警
#define	ERR_CAN_PASSIVE				0x0004	//CAN控制器消极错误
#define	ERR_CAN_LOSE				0x0008	//CAN控制器仲裁丢失
#define	ERR_CAN_BUSERR				0x0010	//CAN控制器总线错误
#define ERR_CAN_BUSOFF				0x0020 //总线关闭错误
//通用错误码
#define	ERR_DEVICEOPENED			0x0100	//设备已经打开
#define	ERR_DEVICEOPEN				0x0200	//打开设备错误
#define	ERR_DEVICENOTOPEN			0x0400	//设备没有打开
#define	ERR_BUFFEROVERFLOW			0x0800	//缓冲区溢出
#define	ERR_DEVICENOTEXIST			0x1000	//此设备不存在
#define	ERR_LOADKERNELDLL			0x2000	//装载动态库失败
#define ERR_CMDFAILED				0x4000	//执行命令失败错误码
#define	ERR_BUFFERCREATE			0x8000	//内存不足

//定义ZLGCAN控制器状态的数据类型。
typedef struct _ZLG_CAN_STATUS{
	UCHAR	ErrInterrupt;
	UCHAR	regMode;
	UCHAR	regStatus;
	UCHAR	regALCapture;
	UCHAR	regECCapture;
	UCHAR	regEWLimit;
	UCHAR	regRECounter;
	UCHAR	regTECounter;
	DWORD	Reserved;
}ZLG_CAN_STATUS, *PZLG_CAN_STATUS;

//	邮箱
enum enIKCMailbox    //过滤发送信息到的邮箱
{
	IKC_MAILBOXOTHER = 0,   //不在其他过滤邮箱的信息全部在此
	IKC_MAILBOX0,
	IKC_MAILBOX1,
	IKC_MAILBOX2,
	IKC_MAILBOX3,
	IKC_MAILBOX4,
	IKC_MAILBOX5,
	IKC_MAILBOX6,
	IKC_MAILBOX7,
	IKC_MAILBOX8,
	IKC_MAILBOX9,
	IKC_MAILBOXMAX,
};

//	通道
enum enIKCChannel
{
	IKC_CH1 = 0,
	IKC_CH2,
	IKC_CH3,
	IKC_CH4,
	IKC_CH5,
	IKC_CH6,
	IKC_CH7,
	IKC_CH8,
	IKC_CH_MAX,
};

//	波特率
enum enIKCBtr
{
	IKC_BAUD_125K = 0,
	IKC_BAUD_250K,
	IKC_BAUD_500K,
	IKC_BAUD_MAX,
};

typedef struct stCanIdPdf1
{
	UINT32 SA : 8;		// 0-7
	UINT32 DA : 8;		// 8-15
	UINT32 PF : 8;		// 16-23
	UINT32 DP : 1;		// 24
	UINT32 R : 1;		// 25
	UINT32 PRIO : 3;	// 26-28
	UINT32 AAM : 1;		// 29
	UINT32 AME : 1;		// 30
	UINT32 IDE : 1;		// 31
}ST_CAN_ID_PDF1;

typedef union unCanMsgId
{
	UINT32 all;
	ST_CAN_ID_PDF1 stPdf1;
}UN_CAN_J1939_ID;

typedef struct stCanTimestamp
{
	INT64 nTimes;
}ST_CAN_TIMESTAMP;

typedef struct stCanFrameInfo
{
	UINT16 uiDLC : 4;			//	Data Length Code
	UINT16 uiReserved2 : 6;		//	10
	UINT16 uiSendType : 4;		//	信息帧发送类型（(0-3)为了自测可以设置自收自发2
	UINT16 bRTR : 1;			//	Remote Transmission Request
	UINT16 bEFF : 1;			//	Standard Frame Format or Extended Frame Format
}ST_CAN_FRAME_INFO;

typedef union unCanFrameData
{
	BYTE abyData[8];
	WORD awdData[4];
	UINT32 auiData[2];
	UINT64 uiData;
}UN_CAN_FRAME_DATA;

//	CAN报文
typedef struct stCanFrame 
{
	union {
		UN_CAN_J1939_ID unId;
		UINT32 nId;
	};
	ST_CAN_FRAME_INFO	stFrameInfo;
	UN_CAN_FRAME_DATA	unData;
	ST_CAN_TIMESTAMP	stTimes;
}ST_CAN_FRAME;


class IKlCanServe
{
public:

	// 初始化接口
	virtual bool IKS_CreateCANHanle (enIKCDevs eDev) = 0;

	//	CAN设备初始化
	virtual enIKSCode IKS_Init() = 0;
	//	CAN设备初始化卸载
	virtual enIKSCode IKS_Uninit() = 0;
	//	CAN设备复位	
	virtual enIKSCode IKS_Reset() = 0;

	//	打开CAN设备
	virtual enIKSCode IKS_Open(enIKCChannel eCan, enIKCBtr eBtr) = 0;
	//	关闭CAN设备	
	virtual enIKSCode IKS_Close(enIKCChannel eCan) = 0;
	//	CAN设备是否打开
	virtual bool IKS_IsOpened(enIKCChannel eCan) = 0;
	//	获取CAN状态
	virtual DWORD IKS_GetState(int nInd, enIKCChannel eCan) = 0;
	virtual enIKSCode IKS_GetZLGState(enIKCDevs eDev, enIKCChannel eCan, ZLG_CAN_STATUS *vStatus) = 0;

	//	CAN邮箱配置
	//	设置单独标准帧ID配置
	virtual void IKS_SetCanStdIndividual(enIKCChannel eCan, enIKCMailbox eMailbox, UINT32 uiID) = 0;
	//	设置标准帧ID组配置
	virtual void IKS_SetCanStdGroup(enIKCChannel eCan, enIKCMailbox eMailbox, UINT32 uiIDBegin , UINT32 uiIDEnd) = 0;
	//	设置单独扩展帧ID配置
	virtual void IKS_SetCanExtIndividual(enIKCChannel eCan, enIKCMailbox eMailbox, UINT32 uiID) = 0;
	//	设置扩展帧ID组配置
	virtual void IKS_SetCanExtGroup(enIKCChannel eCan, enIKCMailbox eMailbox, UINT32 uiIDBegin , UINT32 uiIDEnd) = 0;

	//	非邮箱读
	//	接收CAN消息（读一个报文）
	virtual enIKSCode IKS_Read(enIKCChannel eCan, stCanFrame *pCanFrame) = 0;
	//	接收CAN消息（读多个报文）
	virtual enIKSCode IKS_Reads(enIKCChannel eCan, stCanFrame *pCanFrame, int nLen, int *pLen) = 0;

	//	发送CAN消息
	virtual enIKSCode IKS_Write(enIKCChannel eCan, stCanFrame *pCanFrame) = 0;
	//	线程中发送CAN消息
	virtual enIKSCode IKS_Write_Tack(enIKCChannel eCan, stCanFrame *pCanFrame) = 0;			

	//	清除邮箱配置
	virtual void IKS_ClearCanId(enIKCChannel eCan, enIKCMailbox eMailbox, bool bisEFF, bool bisGroup) = 0;
	virtual void IKS_ClearCanIdAll() = 0;

	//	接收过滤到邮箱的CAN消息（读一个报文）
	virtual enIKSCode IKS_ReadMailbox(enIKCChannel eCan, enIKCMailbox eMailbox, stCanFrame *pCanFrame) = 0;
	//	接收过滤到邮箱的CAN消息（读多个报文）
	virtual enIKSCode IKS_ReadsMailbox(enIKCChannel eCan, enIKCMailbox eMailbox, stCanFrame *pCanFrame, int nLen, int *pLen) = 0;

	//	清除CAN发送缓冲区
	virtual void IKS_ClearTxQueue() = 0;
	//	清除CAN接收缓冲区
	virtual void IKS_ClearRxQueue() = 0;

	//	获得CAN发送缓冲区长度
	virtual int IKS_GetTxQueueSize() = 0;
	//	获得CAN接收缓冲区长度
	virtual int IKS_GetRxQueueSize() = 0;

	//	获得CAN缓冲区长度
	virtual int IKS_GetRxMailQueueSize(enIKCMailbox eMailbox) = 0;

	//	获得CAN缓冲区长度
	virtual int IKS_GetLibVersion() = 0;

protected:
private:
};
