#ifndef PUBLIC_H
#define PUBLIC_H

//版本：V1.0

//#pragma warning (disable : 4996)

#include <windows.h>
#include <QtGui>
#include <QString>
#include <QThread>
#include <QReadWriteLock>
#include <QWaitCondition>
#include <QDateTime>
#include <QVector>
#include <QMap>
#include <QDebug>
#include <QSplitter>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QProcess>
#include <QMessageBox>
#include <QCloseEvent>
#include <QDesktopWidget>
#include <QAction> 
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QPushButton>  
#include <QCursor>  
#include <QKeySequence>
#include <QStatusBar>
#include <QScroller>
#include <QScrollArea>
#include <QScrollBar>
#include <QTableWidget>
#include <QTableView>
#include <QTableWidgetItem>
#include <QDial>

//#define USE_LOCAL_FONT      //定义是否使用本地语言（微软雅黑）


#ifdef USE_LOCAL_FONT
extern bool _USE_LOCAL_FONT;      //定义是否使用本地语言（微软雅黑）
//加载本地字体
QString loadFontFamilyFromTTF();
#endif

#include "aboutdialog.h"

//#include "qwt/qwt.h"

#include <qpainter.h>
//#include <qwt_dial_needle.h>
//#include <qwt_round_scale_draw.h>
#include <qstring.h>
//#include <qwt_dial.h>

#include "./CAN/klCanFactory.h"
#include "./CAN/IKlCanServe.h"
#include "./CAN/IKlCanBase.h"

#include "QRoundProgressBar.h"



typedef unsigned long  _UL;
typedef unsigned short _US;
typedef unsigned char  _UC;

//#define QString_C(txt)  QString::fromLocal8Bit(txt)     //中文显示，防止乱码
#define QString_C(txt)  QStringLiteral(txt)     //中文显示，防止乱码
//#define QString_C(txt)  QObject::tr(txt)     //中文显示，防止乱码

#define BAT_MAX_NUM			6
#define BMS_BSU_NUMBER      32      //32个BSU
#define BMS_BTS_NUMBER      25      //25个BTS
#define BMS_ALARM_TYPE      32      //32类告警
#define BMS_BAT_NUMBER      16      //16组电池
#define BSU_MAX_NUM			32
#define CELL_MAX_NUM		300
#define BSU_CELL_NUM		64
#define BAT_CELL_NUM		300
#define	BSU_TEMP_NUM		64

// 数据页定义
#define J1939_DP0			0x00000000			//第0页
#define J1939_DP1			0x01000000			//第1页

// 优先级定义
#define J1939_PRIOR7		0x1C000000			//最低优先级
#define J1939_PRIOR6		0x18000000			//第6级优先级
#define J1939_PRIOR5		0x14000000			//第5级优先级
#define J1939_PRIOR4		0x10000000			//第4级优先级
#define J1939_PRIOR3		0x0C000000			//第3优先级
#define J1939_PRIOR2		0x08000000			//第2级优先级
#define J1939_PRIOR1		0x04000000			//第1级优先级
#define J1939_PRIOR0		0x00000000			//最高优先级

#define J1939_PRIOR_MASK	0x1C000000

// 其他字段
#define J1939_DA(DestAddr)		((UINT32)(DestAddr) << 8)	
#define	J1939_SA(SrcAddr)		((UINT32)(SrcAddr))
#define J1939_PF(pf)			((UINT32)(pf) << 16)
#define J1939_PS(ps)			((UINT32)(ps) << 8)

#define J1939_PGN(pgn)			((UINT32)(pgn) << 8)


#define J1939_GET_PF(id)		((BYTE)((id) >> 16))
#define J1939_GET_DA(id)		((BYTE)((id) >> 8))
#define J1939_GET_PS(id)		((BYTE)((id) >> 8))
#define J1939_GET_SA(id)		((BYTE)(id))

#define BMU_DADDR			J1939_DA(0xF4)
#define	BMU_SADDR			J1939_SA(0xF4)
#define BROADCAST_DADDR		J1939_DA(0x80)

#define BMS_ITEM_OF(ArrayName)	(sizeof(ArrayName) / sizeof(ArrayName[0]))
/*
	映射关系配置
*/
#define PT_ONE_BYTE		0x00010000		//每个VID对应一个字节
#define PT_TWO_BYTE		0x00020000		//每个VID对应两个字节
#define PT_BYTE_MASK	0x00030000

#define PT_SAVE_ON_SET	0x00040000		//当设置时需要保存到EEPROM

#define PT_NO_NARROW	0x00000000		/*无缩放*/
#define PT_NARROW10		0x01000000		/*缩小10倍*/
#define PT_NARROW20		0x02000000		/*缩小20倍*/
#define PT_NARROW100	0x03000000		/*缩小100倍*/
#define	PT_NARROW32		0x04000000		/*缩小32倍*/
//#define	PT_NARROW3P2	0x06000000		/*缩小3.2倍*/
#define	PT_NARROW4		0x07000000		/*缩小4倍*/
#define PT_NARROW2		0x05000000		/*缩小2倍*/
#define PT_ENLARG2		0x08000000		/*放大2倍*/
#define PT_ENLARG10		0x09000000		/*放大10倍*/
#define PT_ENLARG20		0x0A000000		/*放大20倍*/
//#define	PT_ENLARG2P5	0x0A000000		/*放大2.5倍*/
#define PT_NARROW_MASK	0x0F000000

#define PT_NO_OFFSET	0x00000000		/*无偏移*/
#define PT_OFFSET40		0x10000000		/*零点上移40*/
#define PT_OFFSET400	0x20000000		/*零点上移400*/
#define PT_OFFSET800	0x30000000		/*零点上移400*/
#define PT_OFFSET1600	0x40000000		/*零点上移1600*/
#define PT_OFFSET16K	0x50000000		/*零点上移16000*/
#define PT_OFFSET5K		0x60000000		/*零点上移5000*/
#define PT_OFFSET_MASK	0xF0000000

// 保留字节，CAN数据域中填固定字节
#define PT_SEND_NN_FLAG			0xFFFEFF
#define PT_RESERVED_NN(HexByte)	(0xFFFEFF00 | (HexByte))

// 保留字节，CAN数据域中填0
#define PT_RESERVED_00	0xFFFFFFF0
// 保留字节，CAN数据域中填FF
#define PT_RESERVED_FF	0xFFFFFFF1
// 接收帧中不关心的字节
#define PT_IGNORE		0xFFFFFFF2
// 结束
#define PT_VID_END		0xFFFFFFFF

// 在CAN通信中，PID加上一个偏移量，将VID和PID整合在一起
// 小于此值的为VID，大于等于此值的为PID
#define PID_TO_VID_OFFSET		0xF000
#define PID_TO_VID(pid)			((pid) + PID_TO_VID_OFFSET)
#define VID_TO_PID(vid)			((vid) - PID_TO_VID_OFFSET)


// BSU
#define VID_BSU_NUM				32
#define VID_BSU_CELL_NUM		64

#define VID_BSU_HEAD_START		0x1000
#define VID_BSU_HEAD_SIZE		256		// 0x0100

#define VID_BSU_CELL_START		0x1100
#define VID_BSU_CELL_SIZE		16

#define VID_BSU_SIZE			(VID_BSU_HEAD_SIZE + VID_BSU_CELL_SIZE * VID_BSU_CELL_NUM)	//	1280, 0x0500

#define VID_BSU_TOTAL_SIZE		(VID_BSU_SIZE * VID_BSU_NUM)		// 40K = 0xA000


// BAT
#define VID_BAT_HEAD_START		0xB000
#define VID_BAT_HEAD_SIZE		256

#define VID_BAT_CELL_START		(VID_BAT_HEAD_START + VID_BAT_HEAD_SIZE)
#define VID_BAT_CELL_SIZE		256

#define VID_BAT_SIZE			512		// 0x0200
#define VID_BAT_NUM				16
#define VID_BAT_TOTAL_SIZE		(VID_BAT_SIZE * VID_BAT_NUM)		// 8K

// VCU
#define VID_VCU_START			(VID_BAT_HEAD_START + VID_BAT_TOTAL_SIZE)	// 0xD000 = 52K
#define VID_VCU_SIZE			1024	// 0x0400

// CHARGER
#define VID_CHR_START			(VID_VCU_START + VID_VCU_SIZE)			// 0xD400
#define VID_CHR_SIZE			1024	// 0x0400


/************************************************************************/
//
// PID地址分配
//
/************************************************************************/
#define PID_SYS_START				0
#define PID_SYS_SIZE				256

#define PID_BSU_START				(PID_SYS_START + PID_SYS_SIZE)			// 256
#define PID_BSU_SIZE				16
#define PID_BSU_NUM					32
#define PID_BSU_TOTAL_SIZE			(PID_BSU_SIZE * PID_BSU_NUM)			// 512个

#define PID_ALM_START				(PID_BSU_START + PID_BSU_TOTAL_SIZE)	// 768
#define PID_ALM_SIZE				16
#define PID_ALM_NUM					32
#define PID_ALM_TOTAL_SIZE			(PID_ALM_SIZE * PID_ALM_NUM)			// 512个

#define PID_BAT_START				(PID_ALM_START + PID_ALM_TOTAL_SIZE)	// 1280
#define PID_BAT_SIZE				16
#define PID_BAT_NUM					16
#define PID_BAT_TOTAL_SIZE			(PID_BAT_SIZE * PID_BAT_NUM)			// 256个

#define PID_TOTAL_SIZE				(PID_SYS_SIZE + PID_BSU_TOTAL_SIZE \
	+ PID_ALM_TOTAL_SIZE + PID_BAT_TOTAL_SIZE)	// 1.5K

#define PID_CAL_START				0x0D00//校准数据偏移量

#define PID_BYTE_START				0x0E00//字符数据偏移量

enum enParameterDisplayFormat           //参数显示格式
{
    PDF_Decimal,                           /* The data will display in decimal */
    PDF_Hex,
    PDF_Enum,
    PDF_Asterrisk,                         /*****/
    PDF_Bottom,
    PDF_IP,
    PDF_MAC,
    PDF_PASSWORD
};

enum enDispItemSIdType                  //显示项目SID类型
{
	DT_VID_VidSys = 0,
	DT_VID_VidBsu ,
	DT_VID_VidBsuCell ,
	DT_VID_VidBsuBat ,
	DT_VID_VidBsuVcu ,
	DT_VID_VidBsuChr ,
	DT_PID_PidSys ,
	DT_PID_PidBsu ,
	DT_PID_PidAlarm ,
	DT_PID_PidBat
};

enum enItemDispFormat                   //项目显示格式
{
	DF_INTX = 0,
	DF_INTX10,
	DF_UINTX,
	DF_F0X1,
	DF_F0X2,
	DF_POSI,
	DF_HEX4,
	DF_STATE,
	DF_RELAY,
	DF_PRE,
	DF_CURR,
	DF_COMM,
	DF_CHRSTATE,
	DF_WKMODE,
	DF_MAX_NUM
};

enum enItemDispUint                     //项目显示单位
{
	DU_NULL = 0,
	DU_MV,
	DU_V,
	DU_MA,
	DU_A,
	DU_AH,
	DU_TEMP,
	DU_PER,
	DU_POSI,
	DU_RELAY,
	DU_RES,
	DU_RATE,
	DU_PRE,
	DU_SEC,
	DU_MAX_NUM
};

enum enParabmsVidSys                    //bms VID系统参数
{
    VID_SYS_NOT_USED                    , // [ vid = 00000 ] 保留备用
    VID_SYS_HW_VER                      , // [ vid = 00001 ] CPU板硬件版本
    VID_SYS_BASE_BOARD_VER              , // [ vid = 00002 ] 底板硬件版本  [ 0=无底板 ]
    VID_SYS_SW_VER                      , // [ vid = 00003 ] 软件版本
    VID_SYS_LIB_VER                     , // [ vid = 00004 ] 驱动库版本
    VID_SYS_DISP_VER                    , // [ vid = 00005 ] 显示版本
    VID_SYS_SW_SUB_VER                  , // [ vid = 00006 ] 其他版本(预留)
    VID_SYS_TM_YEAR                     , // [ vid = 00007 ] 系统时间：年
    VID_SYS_TM_MONTH                    , // [ vid = 00008 ] 月
    VID_SYS_TM_DAY                      , // [ vid = 00009 ] 日
    VID_SYS_TM_HOUR                     , // [ vid = 00010 ] 时
    VID_SYS_TM_MIN                      , // [ vid = 00011 ] 分
    VID_SYS_TM_SEC                      , // [ vid = 00012 ] 秒
    VID_SYS_XX                          , // [ vid = 00013 ]
    VID_SYS_YY                          , // [ vid = 00014 ]
    VID_SYS_ZZ                          , // [ vid = 00015 ]
    VID_SYS_XYZ                         , // [ vid = 00016 ]
    VID_SYS_MAX_PERIOD                  , // [ vid = 00017 ] 主循环最长周期  [ mS ]
    VID_SYS_LAST_ERR_NO                 , // [ vid = 00018 ] 最后错误码  [ BMU自身错误代码 ]
    VID_SYS_WORK_MODE                   , // [ vid = 00019 ] 系统工作模式  [ 0=正常工作，1=工装模式 ]
    VID_SYS_ACC_STATUS                  , // [ vid = 00020 ] ACC信号输入状态
    VID_SYS_TO_SUICIDE                  , // [ vid = 00021 ] 系统准备自杀式断电
    VID_SYS_VOLT                        , // [ vid = 00022 ] 系统综合电压
    VID_SYS_CURR                        , // [ vid = 00023 ] 系统综合电流
    VID_SYS_TEMP                        , // [ vid = 00024 ] 系统综合温度
    VID_SYS_SOC                         , // [ vid = 00025 ] 系统综合SOC
    VID_SYS_BOOT_VER                    , // [ vid = 00026 ] BOOT版本
    VID_SYS_RESERVED2                   , // [ vid = 00027 ] 预留2
    VID_SYS_RESERVED3                   , // [ vid = 00028 ] 预留3
    VID_SYS_RESERVED4                   , // [ vid = 00029 ] 预留4
    VID_SYS_ACTV_ALM_NUM                , // [ vid = 00030 ] 活动告警总数
    VID_SYS_HIST_ALM_NUM                , // [ vid = 00031 ] 历史告警总数
    VID_SYS_ALM_L1_NUM                  , // [ vid = 00032 ] 一级活动告警总数
    VID_SYS_ALM_L2_NUM                  , // [ vid = 00033 ] 二级活动告警总数
    VID_SYS_ALM_L3_NUM                  , // [ vid = 00034 ] 三级活动告警总数
    VID_SYS_ALM_L4_NUM                  , // [ vid = 00035 ] 四级活动告警总数
    VID_SYS_RUN_STATUS                  , // [ vid = 00036 ] 系统运行状态
    VID_SYS_DI1_STATUS                  , // [ vid = 00037 ] DI输入状态  [ 0=断开，1=闭合 ]
    VID_SYS_DI2_STATUS                  , // [ vid = 00038 ]
    VID_SYS_DI3_STATUS                  , // [ vid = 00039 ]
    VID_SYS_DI4_STATUS                  , // [ vid = 00040 ]
    VID_SYS_DI5_STATUS                  , // [ vid = 00041 ]
    VID_SYS_DI6_STATUS                  , // [ vid = 00042 ]
    VID_SYS_DI7_STATUS                  , // [ vid = 00043 ]
    VID_SYS_DI8_STATUS                  , // [ vid = 00044 ]
    VID_SYS_RELAY1_STATUS               , // [ vid = 00045 ] 继电器输出状态  [ 0=断开，1=闭合 ]
    VID_SYS_RELAY2_STATUS               , // [ vid = 00046 ]
    VID_SYS_RELAY3_STATUS               , // [ vid = 00047 ]
    VID_SYS_RELAY4_STATUS               , // [ vid = 00048 ]
    VID_SYS_RELAY5_STATUS               , // [ vid = 00049 ]
    VID_SYS_RELAY6_STATUS               , // [ vid = 00050 ]
    VID_SYS_RELAY7_STATUS               , // [ vid = 00051 ]
    VID_SYS_RELAY8_STATUS               , // [ vid = 00052 ] 风扇控制状态
    VID_SYS_RELAY1_REASON               , // [ vid = 00053 ] 继电器断开原因  [ 0=闭合，1=告警关联，其他：原因 ]
    VID_SYS_RELAY2_REASON               , // [ vid = 00054 ]
    VID_SYS_RELAY3_REASON               , // [ vid = 00055 ]
    VID_SYS_RELAY4_REASON               , // [ vid = 00056 ]
    VID_SYS_RELAY5_REASON               , // [ vid = 00057 ]
    VID_SYS_RELAY6_REASON               , // [ vid = 00058 ]
    VID_SYS_RELAY7_REASON               , // [ vid = 00059 ]
    VID_SYS_RELAY8_REASON               , // [ vid = 00060 ]
    VID_SYS_AD_CODE1                    , // [ vid = 00061 ] AD通道码值: 绝缘采集地
    VID_SYS_AD_CODE2                    , // [ vid = 00062 ] 预充电压
    VID_SYS_AD_CODE3                    , // [ vid = 00063 ] 电池母线总电压
    VID_SYS_AD_CODE4                    , // [ vid = 00064 ] 负母线电压
    VID_SYS_AD_CODE5                    , // [ vid = 00065 ] 母线总电压2
    VID_SYS_AD_CODE6                    , // [ vid = 00066 ] 负母线电压2
    VID_SYS_AD_CODE7                    , // [ vid = 00067 ] 霍尔电流
    VID_SYS_AD_CODE8                    , // [ vid = 00068 ] 分流器电流
    VID_SYS_BUS_VOLT                    , // [ vid = 00069 ] 电池母线总电压  [ 0.1V ]
    VID_SYS_PBUS_VOLT                   , // [ vid = 00070 ] 正母线电压  [ 0.1V ]
    VID_SYS_NBUS_VOLT                   , // [ vid = 00071 ] 负母线电压  [ 0.1V ]
    VID_SYS_PBUS_RES                    , // [ vid = 00072 ] 正母线电阻  [ 0.1KΩ ]
    VID_SYS_NBUS_RES                    , // [ vid = 00073 ] 负母线电阻  [ 0.1KΩ ]
    VID_SYS_LEAK_CURR                   , // [ vid = 00074 ] 系统漏电流  [ 0.1mA ]
    VID_SYS_PRE_BUS_VOLT                , // [ vid = 00075 ] 预充电压  [ 0.1V ]
    VID_SYS_CURR1_VOLT                  , // [ vid = 00076 ] 电流通道1的电压  [ mV ]
    VID_SYS_CURR2_VOLT                  , // [ vid = 00077 ] 电流通道2的电压  [ mV ]
    VID_SYS_CURR1                       , // [ vid = 00078 ] 电流通道1的电流  [ 0.1A ]
    VID_SYS_CURR2                       , // [ vid = 00079 ] 电流通道2的电流  [ 0.1A ]
    VID_SYS_POWER_VOLT                  , // [ vid = 00080 ] 工作电源电压  [ 0.1V ]
    VID_SYS_BOARD_TEMP                  , // [ vid = 00081 ] 板上温度  [ 0.1℃ ]
    VID_SYS_OUT_TEMP                    , // [ vid = 00082 ] 外部温度传感器温度 [ 0.1℃ ]
    VID_SYS_LEM_VOLT2                   , // [ vid = 00083 ] LEM通道2电压
    VID_SYS_LEM_CURR                    , // [ vid = 00084 ] LEM计算出的电流  [ 0.1A ]
    VID_SYS_LEM_CODE                    , // [ vid = 00085 ] LEM通道码值
    VID_SYS_ONLINE_BSU_NUM              , // [ vid = 00086 ] 在线BSU个数
    VID_SYS_RATED_VOLT                  , // [ vid = 00087 ] 电池额定电压  [ V ]
    VID_SYS_LIFE                        , // [ vid = 00088 ] 生命信息
    VID_SYS_SUPER                       , // [ vid = 00089 ] 超级控制命令
    VID_SYS_PRECHARGE_FAIL              , // [ vid = 00090 ] 预充失败状态  [ 0=正常，1=失败 ]
    VID_SYS_MAX_VOLT                    , // [ vid = 00091 ] 最高电压值  [ mV ]
    VID_SYS_MAXV_POSI                   , // [ vid = 00092 ] 最高电压位置
    VID_SYS_MIN_VOLT                    , // [ vid = 00093 ] 最低电压值  [ mV ]
    VID_SYS_MINV_POSI                   , // [ vid = 00094 ] 最低电压位置
    VID_SYS_MAX_TEMP                    , // [ vid = 00095 ] 最高温度值  [ 0.1℃ ]
    VID_SYS_MAXT_POSI                   , // [ vid = 00096 ] 最高温度位置
    VID_SYS_MIN_TEMP                    , // [ vid = 00097 ] 最低温度值  [ 0.1℃ ]
    VID_SYS_MINT_POSI                   , // [ vid = 00098 ] 最低温度位置
    VID_JYM_STATUS                      , // [ vid = 00099 ] 绝缘模块运行状态
    VID_JYM_OFFLINE                     , // [ vid = 00100 ] 绝缘模块离线状态  [ 0=在线，1=离线 ]
    VID_JYM_OPEN_BAT_VOLT               , // [ vid = 00101 ] 电桥断开时电池总电压  [ 0.1V ]
    VID_JYM_OPEN_NBUS_VOLT              , // [ vid = 00102 ] 电桥断开时负母线电压  [ 0.1V ]
    VID_JYM_CLOSE_UP_NBUS_VOLT          , // [ vid = 00103 ] 上桥闭合时负母线电压  [ 0.1V ]
    VID_JYM_CLOSE_DN_NBUS_VOLT          , // [ vid = 00104 ] 下桥闭合时负母线电压  [ 0.1V ]
    VID_SYS_NBUS_VOLT_FINAL             , // [ vid = 00105 ] 根据两档计算出的实时负母线电压  [ 0.1V ]
    VID_SYS_BUS_VOLT1                   , // [ vid = 00106 ] 电池总压1
    VID_SYS_SLW_BUS_VOLT                , // [ vid = 00107 ] 慢充电压  [ 0.1V ]
    VID_SYS_NBUS_VOLT1                  , // [ vid = 00108 ] 负母线电压1
    VID_SYS_FST_BUS_VOLT                , // [ vid = 00109 ] 快充电压  [ 0.1V ]
    VID_GPRS_CONTROL                    , // [ vid = 00110 ] GPRS控制
    VID_GPRS_RUN_STATUS                 , // [ vid = 00111 ] GPRS运行状态
    VID_GPRS_SIG_STRENGTH               , // [ vid = 00112 ] GPRS信号强度
    VID_GPRS_CONNECT_STEP               , // [ vid = 00113 ] GPRS连接步骤
    VID_GPRS_ONLINE_TIME                , // [ vid = 00114 ] GPRS在线时间  [ Min ]
    VID_GPRS_SEND_NUM                   , // [ vid = 00115 ] GPRS发送数据包数目
    VID_GPRS_RECV_OK_NUM                , // [ vid = 00116 ] GPRS接收到OK的数目
    VID_GPRS_FLOW_COUNT_HI              , // [ vid = 00117 ] GPRS流量高字节
    VID_GPRS_FLOW_COUNT_LO              , // [ vid = 00118 ] GPRS流量低字节
    VID_GPRS_IMEI1                      , // [ vid = 00119 ] GPRS模块IMEI字符串
    VID_GPRS_IMEI2                      , // [ vid = 00120 ] GPRS模块IMEI字符串
    VID_GPRS_IMEI3                      , // [ vid = 00121 ] GPRS模块IMEI字符串
    VID_GPRS_IMEI4                      , // [ vid = 00122 ] GPRS模块IMEI字符串
    VID_GPRS_IMEI5                      , // [ vid = 00123 ] GPRS模块IMEI字符串
    VID_GPRS_IMEI6                      , // [ vid = 00124 ] GPRS模块IMEI字符串
    VID_GPRS_IMEI7                      , // [ vid = 00125 ] GPRS模块IMEI字符串
    VID_GPRS_IMEI8                      , // [ vid = 00126 ] GPRS模块IMEI字符串
    VID_GPRS_CCID1                      , // [ vid = 00127 ] SIM卡CCID字符串
    VID_GPRS_CCID2                      , // [ vid = 00128 ] SIM卡CCID字符串
    VID_GPRS_CCID3                      , // [ vid = 00129 ] SIM卡CCID字符串
    VID_GPRS_CCID4                      , // [ vid = 00130 ] SIM卡CCID字符串
    VID_GPRS_CCID5                      , // [ vid = 00131 ] SIM卡CCID字符串
    VID_GPRS_CCID6                      , // [ vid = 00132 ] SIM卡CCID字符串
    VID_GPRS_CCID7                      , // [ vid = 00133 ] SIM卡CCID字符串
    VID_GPRS_CCID8                      , // [ vid = 00134 ] SIM卡CCID字符串
    VID_GPRS_CCID9                      , // [ vid = 00135 ] SIM卡CCID字符串
    VID_GPRS_CCID10                     , // [ vid = 00136 ] SIM卡CCID字符串
    VID_GPRS_RESERVED1                  , // [ vid = 00137 ] 保留1
    VID_GPRS_ENABLE                     , // [ vid = 00138 ] GPRS 使能开关
    VID_GPRS_ERR_COUNT                  , // [ vid = 00139 ] GPRS 错误计数
    VID_GPRS_RESERVED4                  , // [ vid = 00140 ] 保留4
    VID_SYS_ALLOW_DSCH_CURR             , // [ vid = 00141 ] 最大允许放电电流  [ 0.1A ]
    VID_SYS_ALLOW_CHRG_CURR             , // [ vid = 00142 ] 最大允许充电电流  [ 0.1A ]
    VID_SYS_BAT_STATE                   , // [ vid = 00143 ] 系统状态  [ 4个等级 ]
    VID_SYS_BAT_FAULT1                  , // [ vid = 00144 ] 系统故障代码1
    VID_SYS_BAT_FAULT2                  , // [ vid = 00145 ] 系统故障代码2
    VID_SYS_BAT_FAULT3                  , // [ vid = 00146 ] 系统故障代码3
    VID_SYS_BAT_FAULT4                  , // [ vid = 00147 ] 系统故障代码4
    VID_SYS_FAULT                       , // [ vid = 00148 ] 接触器故障代码
    VID_SYS_HVREL_CMD                   , // [ vid = 00149 ] 高压继电器控制命令
    VID_SYS_USER_SET_SOC                , // [ vid = 00150 ] 用户手动设置SOC的值
    VID_SYS_DEBUG_VAR1                  , // [ vid = 00151 ] 调试变量1
    VID_SYS_DEBUG_VAR2                  , // [ vid = 00152 ] 调试变量2
    VID_SYS_DEBUG_VAR3                  , // [ vid = 00153 ] 调试变量3
    VID_SYS_DEBUG_VAR4                  , // [ vid = 00154 ] 调试变量4
    VID_SYS_DEBUG_VAR5                  , // [ vid = 00155 ] 调试变量5
    VID_SYS_DEBUG_VAR6                  , // [ vid = 00156 ] 调试变量6
    VID_SYS_DEBUG_VAR7                  , // [ vid = 00157 ] 调试变量7
    VID_SYS_DEBUG_VAR8                  , // [ vid = 00158 ] 调试变量8
    VID_SYS_ALLOW_DSCH_POWER            , // [ vid = 00159 ] 最大允许放电功率  [ 0.1kW ]
    VID_SYS_ALLOW_CHRG_POWER            , // [ vid = 00160 ] 最大允许充电功率  [ 0.1kW ]
    VID_SYS_CMD                         , // [ vid = 00161 ] 控制命令
    VID_SYS_SUPER_GPRS                  , // [ vid = 00162 ] GPRS控制命令
    VID_SYS_RELAY_PRE                   , // [ vid = 00163 ] 预充继电器定义  [ 0：无 其他：对应继电器号 ]
    VID_SYS_RELAY_MAIN                  , // [ vid = 00164 ] 主继电器定义  [ 0：无 其他：对应继电器号 ]
    VID_SYS_RELAY_CHA                   , // [ vid = 00165 ] 充电继电器定义(车载)  [ 0：无 其他：对应继电器号 ]
    VID_SYS_RELAY_NEGA                  , // [ vid = 00166 ] 总负继电器定义  [ 0：无 其他：对应继电器号 ]
    VID_SYS_RELAY_OUT                   , // [ vid = 00167 ] 外部继电器定义  [ 0：无 其他：对应继电器号 ]
    VID_SYS_RELAY_HOT                   , // [ vid = 00168 ] BMU加热继电器定义  [ 0：无 其他：对应继电器号 ]
    VID_SYS_RELAY_BSU                   , // [ vid = 00169 ] BSU电源继电器定义  [ 0：无 其他：对应继电器号 ]
    VID_SYS_RELAY_BMU                   , // [ vid = 00170 ] BMU休眠继电器定义  [ 0：无 其他：对应继电器号 ]
    VID_SYS_RELAY_AUX_FAIL              , // [ vid = 00171 ] 辅助触点错误状态  [ 0=正常，1=错误 ]
    VID_SYS_MAX_TEMP_SHADOW             , // [ vid = 00172 ] 最高温度值-影子  [ 0.1℃ ]
    VID_SYS_MAXT_POSI_SHADOW            , // [ vid = 00173 ] 最高温度位置-影子
    VID_SYS_MIN_TEMP_SHADOW             , // [ vid = 00174 ] 最低温度值-影子  [ 0.1℃ ]
    VID_SYS_MINT_POSI_SHADOW            , // [ vid = 00175 ] 最低温度位置-影子
    VID_SYS_MAX_VOLT_SHADOW             , // [ vid = 00176 ] 最高电压值-影子  [ mV ]
    VID_SYS_MAXV_POSI_SHADOW            , // [ vid = 00177 ] 最高电压位置-影子
    VID_SYS_MIN_VOLT_SHADOW             , // [ vid = 00178 ] 最低电压值-影子  [ mV ]
    VID_SYS_MINV_POSI_SHADOW            , // [ vid = 00179 ] 最低电压位置-影子
    VID_SYS_RUN_PERIOD                  , // [ vid = 00180 ] 本圈周期  [ mS ]
    VID_SYS_CAN_SELF_TEST_RESULT        , // [ vid = 00181 ] CAN自测试结果  [ 0-未开始；1-正常；2+故障 ]
    VID_SYS_USB_STATE                   , // [ vid = 00182 ] USB状态  [ 0：无 ]
    VID_SYS_OUT_TEMP2_CODE              , // [ vid = 00183 ] 外部温度2测量的码值
    VID_SYS_OUT_TEMP2_VOLT              , // [ vid = 00184 ] 外部温度2测量的电压 [ mV ]
    VID_SYS_OUT_TEMP2                   , // [ vid = 00185 ] 外部温度2传感器温度 [ 0.1℃ ]
    VID_SYS_CP_AMPLITUDE                , // [ vid = 00186 ] CP输入幅值 [ 0.1V ]
    VID_SYS_CP_PWM_FREQ                 , // [ vid = 00187 ] CP输入PWM频率  [ Hz ]
    VID_SYS_CP_PWM_DUTY_RATIO           , // [ vid = 00188 ] CP输入PWM占空比  [ 0.1% ]
    VID_SYS_RELAY_FAN                   , // [ vid = 00189 ] BMU控制风扇继电器定义  [ 0：无 其他：对应继电器号 ]
    VID_SYS_VCU_MAIN_RELAY_CMD          , // [ vid = 00190 ] VCU发给BMS控制主继电器的命令  [ 0：闭合 1：断开 ]
    VID_SYS_BSU_RELAY_STATUS            , // [ vid = 00191 ] BSU电源继电器状态  [ 0：闭合 1：断开 ]
    VID_SYS_LOW_VOLT_STATUS             , // [ vid = 00192 ] 工作电压太低 [ 0=正常, 1=工作电压太低 ]
    VID_SYS_RESERVED26                  , // [ vid = 00193 ] 预留26
    VID_SYS_VCU_COMM_FAIL               , // [ vid = 00194 ] VCU通信超时
    VID_SYS_HVREL_FAIL                  , // [ vid = 00195 ] BMU高压故障
    VID_SYS_MAXV_NO                     , // [ vid = 00196 ] 最高电压单体序号
    VID_SYS_MINV_NO                     , // [ vid = 00197 ] 最低电压单体序号
    VID_SYS_MAXT_NO                     , // [ vid = 00198 ] 最高温度单体序号
    VID_SYS_MINT_NO                     , // [ vid = 00199 ] 最低温度单体序号
    VID_SYS_MINUS_CURR                  , // [ vid = 00200 ] 负电流（充电为负，放电为正）
    VID_SYS_AUX_FAIL_VID                , // [ vid = 00201 ] 辅助
    VID_SYS_MAIN_POS_OPEN               , // [ vid = 00202 ] 总正继电器开路
    VID_SYS_MAIN_POS_SHORT              , // [ vid = 00203 ] 总正继电器粘连
    VID_SYS_MAIN_NEG_OPEN               , // [ vid = 00204 ] 总负继电器开路
    VID_SYS_MAIN_NEG_SHORT              , // [ vid = 00205 ] 总负继电器粘连

    VID_SYS_DSW1_VOLT                   , // [ vid = 00206 ] DSW1电压
    VID_SYS_DSW2_VOLT                   , // [ vid = 00207 ]
    VID_SYS_DSW3_VOLT                   , // [ vid = 00208 ]
    VID_SYS_DSW4_VOLT                   , // [ vid = 00209 ]

    VID_SYS_CC_VOLT                     , // [ vid = 00210 ] 充电CC电压
    VID_SYS_CC2_VOLT                    , // [ vid = 00211 ] 充电CC2电压
    VID_SYS_CP_VOLT                     , // [ vid = 00212 ] 充电CP电压
    VID_SYS_HALL_BREAK                  , // [ vid = 00213 ] 霍尔断线状态

    VID_SYS_PWR_CODE                    , // [ vid = 00214 ]
    VID_SYS_CC_CODE                     , // [ vid = 00215 ]
    VID_SYS_CC2_CODE                    , // [ vid = 00216 ]
    VID_SYS_CP_CODE                     , // [ vid = 00217 ]
    VID_SYS_CC_RESISTANCE               , // [ vid = 00218 ] CC的电阻 [ Ω ]
    VID_SYS_CC2_RESISTANCE              , // [ vid = 00219 ] CC2的电阻 [ Ω ]
    VID_SYS_BAL_ACTIVE_MODE             , // [ vid = 00220 ] 主动均衡工作模式 （静止，放电，充电）
    VID_SYS_BAL_ACTIVE_DISH_NUM         , // [ vid = 00221 ] 主动均衡放电模块数
    VID_SYS_BAL_ACTIVE_CHRG_NUM         , // [ vid = 00222 ] 主动均衡充电模块数
    VID_SYS_READY_TO_CUT                , // [ vid = 00223 ] 取消
    VID_SYS_PARA_FLAG                   , // [ vid = 00224 ] 参数标志 [ 1=FLASH, 2=EEPROM, 3=配置版本不匹配，4=默认参数中配置，5=EEPROM坏 ]
    VID_SYS_ORIGINAL_CURR               , // [ vid = 00225 ] 原始电流（未清零的电流）	[ 0.1A ]
    VID_SYS_FAST_CURR                   , // [ vid = 00226 ] 快速电流（无滤波） [ 0.1A ]
    VID_SYS_RESERVED227                 , // [ vid = 00227 ]
    VID_SYS_RESERVED228                 , // [ vid = 00228 ]
    VID_SYS_RESERVED229                 , // [ vid = 00229 ]
    VID_SYS_RESERVED230                 , // [ vid = 00230 ]
    VID_SYS_RESERVED231                 , // [ vid = 00231 ]
    VID_SYS_RESERVED232                 , // [ vid = 00232 ]
    VID_SYS_RESERVED233                 , // [ vid = 00233 ]
    VID_SYS_RESERVED234                 , // [ vid = 00234 ]
    VID_SYS_RESERVED235                 , // [ vid = 00235 ]
    VID_SYS_RESERVED236                 , // [ vid = 00236 ]
    VID_SYS_RESERVED237                 , // [ vid = 00237 ]
    VID_SYS_RESERVED238                 , // [ vid = 00238 ]
    VID_SYS_RESERVED239                 , // [ vid = 00239 ]
    VID_SYS_RESERVED240                 , // [ vid = 00240 ]
    VID_SYS_RESERVED241                 , // [ vid = 00241 ]
    VID_SYS_RESERVED242                 , // [ vid = 00242 ]
    VID_SYS_RESERVED243                 , // [ vid = 00243 ]
    VID_SYS_RESERVED244                 , // [ vid = 00244 ]
    VID_SYS_RESERVED245                 , // [ vid = 00245 ]
    VID_SYS_RESERVED246                 , // [ vid = 00246 ]
    VID_SYS_RESERVED247                 , // [ vid = 00247 ]
    VID_SYS_RESERVED248                 , // [ vid = 00248 ]
    VID_SYS_RESERVED249                 , // [ vid = 00249 ]
    VID_SYS_RESERVED250                 , // [ vid = 00250 ]
    VID_SYS_RESERVED251                 , // [ vid = 00251 ]
    VID_SYS_RESERVED252                 , // [ vid = 00252 ]
    VID_SYS_RESERVED253                 , // [ vid = 00253 ]
//    VID_SYS_RESERVED254                 , // [ vid = 00254 ]
//    VID_SYS_RESERVED255                 , // [ vid = 00255 ]

    VID_SYS_GZ_TEST_1							,	// 工装测试专用VID1
    VID_SYS_GZ_TEST_2							,	// 工装测试专用VID2

    VID_SYS_VMAX01_VOLT                          , //
    VID_SYS_VMAX01_POSI                          , //
    VID_SYS_VMAX02_VOLT                          , //
    VID_SYS_VMAX02_POSI                          , //
    VID_SYS_VMAX03_VOLT                          , //
    VID_SYS_VMAX03_POSI                          , //
    VID_SYS_VMAX04_VOLT                          , //
    VID_SYS_VMAX04_POSI                          , //
    VID_SYS_VMAX05_VOLT                          , //
    VID_SYS_VMAX05_POSI                          , //
    VID_SYS_VMAX06_VOLT                          , //
    VID_SYS_VMAX06_POSI                          , //
    VID_SYS_VMAX07_VOLT                          , //
    VID_SYS_VMAX07_POSI                          , //
    VID_SYS_VMAX08_VOLT                          , //
    VID_SYS_VMAX08_POSI                          , //
    VID_SYS_VMAX09_VOLT                          , //
    VID_SYS_VMAX09_POSI                          , //
    VID_SYS_VMAX10_VOLT                          , //
    VID_SYS_VMAX10_POSI                          , //
    VID_SYS_VMIN01_VOLT                          , //
    VID_SYS_VMIN01_POSI                          , //
    VID_SYS_VMIN02_VOLT                          , //
    VID_SYS_VMIN02_POSI                          , //
    VID_SYS_VMIN03_VOLT                          , //
    VID_SYS_VMIN03_POSI                          , //
    VID_SYS_VMIN04_VOLT                          , //
    VID_SYS_VMIN04_POSI                          , //
    VID_SYS_VMIN05_VOLT                          , //
    VID_SYS_VMIN05_POSI                          , //
    VID_SYS_VMIN06_VOLT                          , //
    VID_SYS_VMIN06_POSI                          , //
    VID_SYS_VMIN07_VOLT                          , //
    VID_SYS_VMIN07_POSI                          , //
    VID_SYS_VMIN08_VOLT                          , //
    VID_SYS_VMIN08_POSI                          , //
    VID_SYS_VMIN09_VOLT                          , //
    VID_SYS_VMIN09_POSI                          , //
    VID_SYS_VMIN10_VOLT                          , //
    VID_SYS_VMIN10_POSI                          , //
    VID_SYS_TMAX01_TEMP                          , //
    VID_SYS_TMAX01_POSI                          , //
    VID_SYS_TMAX02_TEMP                          , //
    VID_SYS_TMAX02_POSI                          , //
    VID_SYS_TMAX03_TEMP                          , //
    VID_SYS_TMAX03_POSI                          , //
    VID_SYS_TMAX04_TEMP                          , //
    VID_SYS_TMAX04_POSI                          , //
    VID_SYS_TMAX05_TEMP                          , //
    VID_SYS_TMAX05_POSI                          , //
    VID_SYS_TMAX06_TEMP                          , //
    VID_SYS_TMAX06_POSI                          , //
    VID_SYS_TMAX07_TEMP                          , //
    VID_SYS_TMAX07_POSI                          , //
    VID_SYS_TMAX08_TEMP                          , //
    VID_SYS_TMAX08_POSI                          , //
    VID_SYS_TMAX09_TEMP                          , //
    VID_SYS_TMAX09_POSI                          , //
    VID_SYS_TMAX10_TEMP                          , //
    VID_SYS_TMAX10_POSI                          , //
    VID_SYS_TMIN01_TEMP                          , //
    VID_SYS_TMIN01_POSI                          , //
    VID_SYS_TMIN02_TEMP                          , //
    VID_SYS_TMIN02_POSI                          , //
    VID_SYS_TMIN03_TEMP                          , //
    VID_SYS_TMIN03_POSI                          , //
    VID_SYS_TMIN04_TEMP                          , //
    VID_SYS_TMIN04_POSI                          , //
    VID_SYS_TMIN05_TEMP                          , //
    VID_SYS_TMIN05_POSI                          , //
    VID_SYS_TMIN06_TEMP                          , //
    VID_SYS_TMIN06_POSI                          , //
    VID_SYS_TMIN07_TEMP                          , //
    VID_SYS_TMIN07_POSI                          , //
    VID_SYS_TMIN08_TEMP                          , //
    VID_SYS_TMIN08_POSI                          , //
    VID_SYS_TMIN09_TEMP                          , //
    VID_SYS_TMIN09_POSI                          , //
    VID_SYS_TMIN10_TEMP                          , //
    VID_SYS_TMIN10_POSI                          , //

    VID_SYS_MAX_NUM  =  0xFFF                     // [ vid = 00336 ] 本类设备VID个数  [ 256 + 80  ]

};

enum enParabmsVidBsu                            //BSU VID参数     起始0x1000
{
    VID_BSU_ADDR                                 , // [ vid = 04096 ] 该BSU的地址
    VID_BSU_POSI                                 , // [ vid = 04097 ] BSU位置信息
    VID_BSU_SW_VER                               , // [ vid = 04098 ] BSU软件版本号
    VID_BSU_RUN_STATUS                           , // [ vid = 04099 ] BSU运行状态
    VID_BSU_OFFLINE_STATUS                       , // [ vid = 04100 ] BSU离线状态  [ 0=在线，1=离线 ]
    VID_BSU_TOTAL_VOLT                           , // [ vid = 04101 ] 所有CELL的总电压  [ 10mV ]
    VID_BSU_CURR                                 , // [ vid = 04102 ] BSU采集电流  [ 0.1A ]
    VID_BSU_START_CELL_INDEX                     , // [ vid = 04103 ] 第一个单体在电池组中的序号
    VID_BSU_BAL_CMD                              , // [ vid = 04104 ] 均衡命令：开启、关闭
    VID_BSU_BAL_NO_SET                           , // [ vid = 04105 ] 设置的均衡序号
    VID_BSU_BAL_CURR_SET                         , // [ vid = 04106 ] 设置的均衡电流  [ 0.1A ]
    VID_BSU_CHN1_VOLT                            , // [ vid = 04107 ] 电流通道1的电压  [ mV ]
    VID_BSU_CHN2_VOLT                            , // [ vid = 04108 ] 电流通道2的电压  [ mV ]
    VID_BSU_BAL1_NO                              , // [ vid = 04109 ] 第1路实际均衡序号
    VID_BSU_BAL1_CURR                            , // [ vid = 04110 ] 第1路实际均衡电流  [ 0.1A ]
    VID_BSU_BAL2_NO                              , // [ vid = 04111 ] 第2路实际均衡序号
    VID_BSU_BAL2_CURR                            , // [ vid = 04112 ] 第2路实际均衡电流  [ 0.1A ]
    VID_BSU_FAN_CMD                              , // [ vid = 04113 ] 风扇命令  [ 0=关闭，1=开启 ]
    VID_BSU_HOT_CMD                              , // [ vid = 04114 ] 加热命令  [ 0=关闭，1=开启 ]
    VID_BSU_FAN_STATUS                           , // [ vid = 04115 ] 风扇状态  [ 0=关闭，1=开启 ]
    VID_BSU_HOT_STATUS                           , // [ vid = 04116 ] 加热状态  [ 0=关闭，1=开启 ]
    VID_BSU_BAL_FAIL                             , // [ vid = 04117 ] 均衡故障
    VID_BSU_DI1_STATUS                           , // [ vid = 04118 ] 干接点输入1状态
    VID_BSU_DI2_STATUS                           , // [ vid = 04119 ] 干接点输入2状态
    VID_BSU_BTS_DI1_STATUS                       , // [ vid = 04120 ] BTS的SW1状态  [ 0=无输入信号，1=有输入信号 ]
    VID_BSU_BTS_DI2_STATUS                       , // [ vid = 04121 ] BTS的SW2状态  [ 0=无输入信号，1=有输入信号 ]
    VID_BSU_HEAD_MAX_NUM                           // [ vid = 04122 ] 本类设备VID个数  [ 26 ]
};

enum enParabmsVidBsuCell                        //BSU 电池VID参数   起始0x1100
{
    VID_BSU_CELL_POSI                            , // [ vid = 04352 ] 位置信息  [ 包含所在电池、BSU等信息 ]
    VID_BSU_CELL_UNIQUE_NO                       , // [ vid = 04353 ] 在整个电池组中的序号  [ 从1开始 ]
    VID_BSU_CELL_VOLT                            , // [ vid = 04354 ] 单体电压  [ mV ]
    VID_BSU_CELL_TEMP                            , // [ vid = 04355 ] 单体温度  [ 0.1℃ ]
    VID_BSU_CELL_BAL_CURR                        , // [ vid = 04356 ] 均衡电流  [ mA ]
    VID_BSU_CELL_BAL_CAPA                        , // [ vid = 04357 ] 均衡容量  [ 0.1AH ]
    VID_BSU_CELL_CMD                             , // [ vid = 04358 ] 命令参数
    VID_BSU_CELL_STATUS                          , // [ vid = 04359 ] 状态(复用)
    VID_BSU_CELL_BAR_R                           , // [ vid = 04360 ] 铜排电阻  [ 10uΩ ]
    VID_BSU_CELL_VOLT_ORG                        , // [ vid = 04361 ] 单体电压(BSU原始值)  [ mV ]
    VID_BSU_CELL_TEMP_BSU                        , // [ vid = 04362 ] BSU上报温度  [ 0.1℃ ]
    VID_BSU_CELL_MAX_NUM                           // [ vid = 04363 ] 本类设备VID个数  [ 11 ]
};

enum enParabmsVidBat                            //电池包VID参数  起始0xB000
{
    VID_BAT_TOTAL_VOLT                           , // [ vid = 45056 ] 电池总电压  [ 0.1V ]
    VID_BAT_CURR                                 , // [ vid = 45057 ] 电池电流  [ 0.1A ]
    VID_BAT_SOC                                  , // [ vid = 45058 ] SOC  [ .001 ]
    VID_BAT_SOH                                  , // [ vid = 45059 ] SOH
    VID_BAT_CELL_NUM                             , // [ vid = 45060 ] 有效电池串数
    VID_BAT_AVG_VOLT                             , // [ vid = 45061 ] 平均电压  [ mV ]
    VID_BAT_TEMP_NUM                             , // [ vid = 45062 ] 有效温度个数
    VID_BAT_AVG_TEMP                             , // [ vid = 45063 ] 平均温度  [ ℃ ]
    VID_BAT_TOTAL_CHRG_SOC                       , // [ vid = 45064 ] 总充电容量
    VID_BAT_TOTAL_DSCH_SOC                       , // [ vid = 45065 ] 总放电容量
    VID_BAT_CYCLE_TIMES                          , // [ vid = 45066 ] 循环次数
    VID_BAT_SOC_RUNTIME                          , // [ vid = 45067 ] 运行过程中未被修正过的SOC
    VID_BAT_SOC_BEFORE                           , // [ vid = 45068 ] 蓄电池充电前SOC
    VID_BAT_USER_SET_SOC                         , // [ vid = 45069 ] 用户手动设置SOC
    VID_BAT_XXXX                                 , // [ vid = 45070 ]
    VID_BAT_YYYY                                 , // [ vid = 45071 ]
    VID_BAT_ZZZZ                                 , // [ vid = 45072 ]
    VID_BAT_XYZ                                  , // [ vid = 45073 ]
    VID_BAT_VMAX01_VOLT                          , // [ vid = 45074 ]
    VID_BAT_VMAX01_POSI                          , // [ vid = 45075 ]
    VID_BAT_VMAX01_NO                            , // [ vid = 45076 ]
    VID_BAT_VMAX02_VOLT                          , // [ vid = 45077 ]
    VID_BAT_VMAX02_POSI                          , // [ vid = 45078 ]
    VID_BAT_VMAX02_NO                            , // [ vid = 45079 ]
    VID_BAT_VMAX03_VOLT                          , // [ vid = 45080 ]
    VID_BAT_VMAX03_POSI                          , // [ vid = 45081 ]
    VID_BAT_VMAX03_NO                            , // [ vid = 45082 ]
    VID_BAT_VMAX04_VOLT                          , // [ vid = 45083 ]
    VID_BAT_VMAX04_POSI                          , // [ vid = 45084 ]
    VID_BAT_VMAX04_NO                            , // [ vid = 45085 ]
    VID_BAT_VMAX05_VOLT                          , // [ vid = 45086 ]
    VID_BAT_VMAX05_POSI                          , // [ vid = 45087 ]
    VID_BAT_VMAX05_NO                            , // [ vid = 45088 ]
    VID_BAT_VMAX06_VOLT                          , // [ vid = 45089 ]
    VID_BAT_VMAX06_POSI                          , // [ vid = 45090 ]
    VID_BAT_VMAX06_NO                            , // [ vid = 45091 ]
    VID_BAT_VMAX07_VOLT                          , // [ vid = 45092 ]
    VID_BAT_VMAX07_POSI                          , // [ vid = 45093 ]
    VID_BAT_VMAX07_NO                            , // [ vid = 45094 ]
    VID_BAT_VMAX08_VOLT                          , // [ vid = 45095 ]
    VID_BAT_VMAX08_POSI                          , // [ vid = 45096 ]
    VID_BAT_VMAX08_NO                            , // [ vid = 45097 ]
    VID_BAT_VMAX09_VOLT                          , // [ vid = 45098 ]
    VID_BAT_VMAX09_POSI                          , // [ vid = 45099 ]
    VID_BAT_VMAX09_NO                            , // [ vid = 45100 ]
    VID_BAT_VMAX10_VOLT                          , // [ vid = 45101 ]
    VID_BAT_VMAX10_POSI                          , // [ vid = 45102 ]
    VID_BAT_VMAX10_NO                            , // [ vid = 45103 ]
    VID_BAT_VMIN01_VOLT                          , // [ vid = 45104 ]
    VID_BAT_VMIN01_POSI                          , // [ vid = 45105 ]
    VID_BAT_VMIN01_NO                            , // [ vid = 45106 ]
    VID_BAT_VMIN02_VOLT                          , // [ vid = 45107 ]
    VID_BAT_VMIN02_POSI                          , // [ vid = 45108 ]
    VID_BAT_VMIN02_NO                            , // [ vid = 45109 ]
    VID_BAT_VMIN03_VOLT                          , // [ vid = 45110 ]
    VID_BAT_VMIN03_POSI                          , // [ vid = 45111 ]
    VID_BAT_VMIN03_NO                            , // [ vid = 45112 ]
    VID_BAT_VMIN04_VOLT                          , // [ vid = 45113 ]
    VID_BAT_VMIN04_POSI                          , // [ vid = 45114 ]
    VID_BAT_VMIN04_NO                            , // [ vid = 45115 ]
    VID_BAT_VMIN05_VOLT                          , // [ vid = 45116 ]
    VID_BAT_VMIN05_POSI                          , // [ vid = 45117 ]
    VID_BAT_VMIN05_NO                            , // [ vid = 45118 ]
    VID_BAT_VMIN06_VOLT                          , // [ vid = 45119 ]
    VID_BAT_VMIN06_POSI                          , // [ vid = 45120 ]
    VID_BAT_VMIN06_NO                            , // [ vid = 45121 ]
    VID_BAT_VMIN07_VOLT                          , // [ vid = 45122 ]
    VID_BAT_VMIN07_POSI                          , // [ vid = 45123 ]
    VID_BAT_VMIN07_NO                            , // [ vid = 45124 ]
    VID_BAT_VMIN08_VOLT                          , // [ vid = 45125 ]
    VID_BAT_VMIN08_POSI                          , // [ vid = 45126 ]
    VID_BAT_VMIN08_NO                            , // [ vid = 45127 ]
    VID_BAT_VMIN09_VOLT                          , // [ vid = 45128 ]
    VID_BAT_VMIN09_POSI                          , // [ vid = 45129 ]
    VID_BAT_VMIN09_NO                            , // [ vid = 45130 ]
    VID_BAT_VMIN10_VOLT                          , // [ vid = 45131 ]
    VID_BAT_VMIN10_POSI                          , // [ vid = 45132 ]
    VID_BAT_VMIN10_NO                            , // [ vid = 45133 ]
    VID_BAT_TMAX01_TEMP                          , // [ vid = 45134 ]
    VID_BAT_TMAX01_POSI                          , // [ vid = 45135 ]
    VID_BAT_TMAX01_NO                            , // [ vid = 45136 ]
    VID_BAT_TMAX02_TEMP                          , // [ vid = 45137 ]
    VID_BAT_TMAX02_POSI                          , // [ vid = 45138 ]
    VID_BAT_TMAX02_NO                            , // [ vid = 45139 ]
    VID_BAT_TMAX03_TEMP                          , // [ vid = 45140 ]
    VID_BAT_TMAX03_POSI                          , // [ vid = 45141 ]
    VID_BAT_TMAX03_NO                            , // [ vid = 45142 ]
    VID_BAT_TMAX04_TEMP                          , // [ vid = 45143 ]
    VID_BAT_TMAX04_POSI                          , // [ vid = 45144 ]
    VID_BAT_TMAX04_NO                            , // [ vid = 45145 ]
    VID_BAT_TMAX05_TEMP                          , // [ vid = 45146 ]
    VID_BAT_TMAX05_POSI                          , // [ vid = 45147 ]
    VID_BAT_TMAX05_NO                            , // [ vid = 45148 ]
    VID_BAT_TMAX06_TEMP                          , // [ vid = 45149 ]
    VID_BAT_TMAX06_POSI                          , // [ vid = 45150 ]
    VID_BAT_TMAX06_NO                            , // [ vid = 45151 ]
    VID_BAT_TMAX07_TEMP                          , // [ vid = 45152 ]
    VID_BAT_TMAX07_POSI                          , // [ vid = 45153 ]
    VID_BAT_TMAX07_NO                            , // [ vid = 45154 ]
    VID_BAT_TMAX08_TEMP                          , // [ vid = 45155 ]
    VID_BAT_TMAX08_POSI                          , // [ vid = 45156 ]
    VID_BAT_TMAX08_NO                            , // [ vid = 45157 ]
    VID_BAT_TMAX09_TEMP                          , // [ vid = 45158 ]
    VID_BAT_TMAX09_POSI                          , // [ vid = 45159 ]
    VID_BAT_TMAX09_NO                            , // [ vid = 45160 ]
    VID_BAT_TMAX10_TEMP                          , // [ vid = 45161 ]
    VID_BAT_TMAX10_POSI                          , // [ vid = 45162 ]
    VID_BAT_TMAX10_NO                            , // [ vid = 45163 ]
    VID_BAT_TMIN01_TEMP                          , // [ vid = 45164 ]
    VID_BAT_TMIN01_POSI                          , // [ vid = 45165 ]
    VID_BAT_TMIN01_NO                            , // [ vid = 45166 ]
    VID_BAT_TMIN02_TEMP                          , // [ vid = 45167 ]
    VID_BAT_TMIN02_POSI                          , // [ vid = 45168 ]
    VID_BAT_TMIN02_NO                            , // [ vid = 45169 ]
    VID_BAT_TMIN03_TEMP                          , // [ vid = 45170 ]
    VID_BAT_TMIN03_POSI                          , // [ vid = 45171 ]
    VID_BAT_TMIN03_NO                            , // [ vid = 45172 ]
    VID_BAT_TMIN04_TEMP                          , // [ vid = 45173 ]
    VID_BAT_TMIN04_POSI                          , // [ vid = 45174 ]
    VID_BAT_TMIN04_NO                            , // [ vid = 45175 ]
    VID_BAT_TMIN05_TEMP                          , // [ vid = 45176 ]
    VID_BAT_TMIN05_POSI                          , // [ vid = 45177 ]
    VID_BAT_TMIN05_NO                            , // [ vid = 45178 ]
    VID_BAT_TMIN06_TEMP                          , // [ vid = 45179 ]
    VID_BAT_TMIN06_POSI                          , // [ vid = 45180 ]
    VID_BAT_TMIN06_NO                            , // [ vid = 45181 ]
    VID_BAT_TMIN07_TEMP                          , // [ vid = 45182 ]
    VID_BAT_TMIN07_POSI                          , // [ vid = 45183 ]
    VID_BAT_TMIN07_NO                            , // [ vid = 45184 ]
    VID_BAT_TMIN08_TEMP                          , // [ vid = 45185 ]
    VID_BAT_TMIN08_POSI                          , // [ vid = 45186 ]
    VID_BAT_TMIN08_NO                            , // [ vid = 45187 ]
    VID_BAT_TMIN09_TEMP                          , // [ vid = 45188 ]
    VID_BAT_TMIN09_POSI                          , // [ vid = 45189 ]
    VID_BAT_TMIN09_NO                            , // [ vid = 45190 ]
    VID_BAT_TMIN10_TEMP                          , // [ vid = 45191 ]
    VID_BAT_TMIN10_POSI                          , // [ vid = 45192 ]
    VID_BAT_TMIN10_NO                            , // [ vid = 45193 ]
    VID_BAT_PRE_STATE                            , // [ vid = 45194 ] 预充状态  [ 0：初始化，1：开始预充，2：预充中，3：环流，4：预充完成，5预充失败 ]
    VID_BAT_PRE_COUNTER                          , // [ vid = 45195 ] 预充时间  [ 实际时间是 * 150ms ]
    VID_BAT_PRE_FILTER                           , // [ vid = 45196 ] 预充滤波次数
    VID_BAT_PRE_ENABLE                           , // [ vid = 45197 ] 预充使能  [ 0：禁止预充，1：预充有效 ]
    VID_BAT_RATED_VOLT                           , // [ vid = 45198 ] 电池组额定电压  [ 0.1V ]
    VID_BAT_RATED_POWER                          , // [ vid = 45199 ] 电池组额定功率  [ 0.1kW ]
    VID_BAT_RESERVED7                            , // [ vid = 45200 ] 预留
    VID_BAT_RESERVED8                            , // [ vid = 45201 ] 预留
    VID_BAT_RESERVED9                            , // [ vid = 45202 ] 预留
    VID_BAT_RESERVED10                           , // [ vid = 45203 ] 预留
    VID_BAT_MAX_NUM                                // [ vid = 45204 ] 本类设备VID个数  [ 148 ]
};

enum enParabmsVidVcu                            //vcu VID参数     起始0xD000
{
    VID_VCU_YT_VOLT                              , // [ vid = 53248 ]
    VID_VCU_YT_CURR                              , // [ vid = 53249 ]
    VID_VCU_YT_SOC                               , // [ vid = 53250 ]
    VID_VCU_YT_STATUS                            , // [ vid = 53251 ]
    VID_VCU_YT_CNT                               , // [ vid = 53252 ]
    VID_VCU_YT_ERR_CODE                          , // [ vid = 53253 ]
    VID_VCU_YT_MAX_VOLT                          , // [ vid = 53254 ]
    VID_VCU_YT_MIN_VOLT                          , // [ vid = 53255 ]
    VID_VCU_YT_AVG_VOLT                          , // [ vid = 53256 ]
    VID_VCU_YT_MAXV_NO                           , // [ vid = 53257 ]
    VID_VCU_YT_MINV_NO                           , // [ vid = 53258 ]
    VID_VCU_YT_MAXT_NO                           , // [ vid = 53259 ]
    VID_VCU_YT_MINT_NO                           , // [ vid = 53260 ]
    VID_VCU_YT_CHRG_CURR_LMT                     , // [ vid = 53261 ]
    VID_VCU_YT_DSCH_CURR_LMT                     , // [ vid = 53262 ]
    VID_VCU_YT_CELLN0_VOLT                       , // [ vid = 53263 ]
    VID_VCU_YT_CELLN1_VOLT                       , // [ vid = 53264 ]
    VID_VCU_YT_CELLN2_VOLT                       , // [ vid = 53265 ]
    VID_VCU_YT_CELLN0_NO                         , // [ vid = 53266 ]
    VID_VCU_YT_CELLN1_NO                         , // [ vid = 53267 ]
    VID_VCU_YT_CELLN2_NO                         , // [ vid = 53268 ]
    VID_VCU_YT_HW_VER                            , // [ vid = 53269 ]
    VID_VCU_YT_SW_VER                            , // [ vid = 53270 ]
    VID_VCU_YT_SW_DATE                           , // [ vid = 53271 ]
    VID_VCU_XX                                   , // [ vid = 53272 ]
    VID_VCU_YY                                   , // [ vid = 53273 ]
    VID_VCU_ZZ                                   , // [ vid = 53274 ]
    VID_VCU_VIN1                                 , // [ vid = 53275 ] 整车识别码
    VID_VCU_VIN2                                 , // [ vid = 53276 ]
    VID_VCU_VIN3                                 , // [ vid = 53277 ]
    VID_VCU_VIN4                                 , // [ vid = 53278 ]
    VID_VCU_VIN5                                 , // [ vid = 53279 ]
    VID_VCU_VIN6                                 , // [ vid = 53280 ]
    VID_VCU_VIN7                                 , // [ vid = 53281 ]
    VID_VCU_VIN8                                 , // [ vid = 53282 ]
    VID_VCU_VIN9                                 , // [ vid = 53283 ]
    VID_VCU_VIN10                                , // [ vid = 53284 ]
    VID_VCU_WZL_BMS_STATUS                       , // [ vid = 53285 ] BMS基本状态
    VID_VCU_WZL_HVRLY_STATUS                     , // [ vid = 53286 ] 高压继电器及漏电状态
    VID_VCU_WZL_ALLOW_MAX_TEMP                   , // [ vid = 53287 ] 电池组允许最高温度
    VID_VCU_WZL_ALLOW_MIN_TEMP                   , // [ vid = 53288 ] 电池组允许最低温度
    VID_VCU_WZL_ALLOW_MIN_SOC                    , // [ vid = 53289 ] 电池组允许最低SOC
    VID_VCU_WZL_ALLOW_DSCH_CURR                  , // [ vid = 53290 ] 最大允许放电电流
    VID_VCU_WZL_ALLOW_CHRG_CURR                  , // [ vid = 53291 ] 最大允许充电电流
    VID_VCU_WZL_BMS_FAULT                        , // [ vid = 53292 ] 电池组系统故障信息
    VID_VCU_WZL_OUT_CHRG_TIME                    , // [ vid = 53293 ] 外接充电间隔时间累计
    VID_VCU_WZL_CHRG_CTRL1                       , // [ vid = 53294 ] 整车充电控制(巡航)
    VID_VCU_WZL_CHRG_CTRL2                       , // [ vid = 53295 ] 整车充电控制(刹车)
    VID_VCU_WZL_CHRG_CTRL3                       , // [ vid = 53296 ] 整车充电控制(辅助电机)
    VID_VCU_WZL_DSCH_CMD                         , // [ vid = 53297 ] 高速放电请求指令
    VID_VCU_WZL_LIFE                             , // [ vid = 53298 ] 生命(心跳)信号
    VID_VCU_WZL_BMS_VER                          , // [ vid = 53299 ] 版本号
    VID_VCU_WZL_POSI1                            , // [ vid = 53300 ] 温度/单体所在位置
    VID_VCU_WZL_POSI2                            , // [ vid = 53301 ]
    VID_VCU_WZL_POSI3                            , // [ vid = 53302 ]
    VID_VCU_WZL_POSI4                            , // [ vid = 53303 ]
    VID_VCU_RELAY_REQ                            , // [ vid = 53304 ] VCU控制主继电器请求  [ 0：BMS控制，1：断开主继电器 ]
    VID_VCU_RESERVED1                            , // [ vid = 53305 ]
    VID_VCU_RESERVED2                            , // [ vid = 53306 ]
    VID_VCU_RESERVED3                            , // [ vid = 53307 ]
    VID_VCU_RESERVED4                            , // [ vid = 53308 ]
    VID_VCU_RESERVED5                            , // [ vid = 53309 ]
    VID_VCU_RESERVED6                            , // [ vid = 53310 ]
    VID_VCU_RESERVED7                            , // [ vid = 53311 ]
    VID_VCU_RESERVED8                            , // [ vid = 53312 ]
    VID_VCU_RESERVED9                            , // [ vid = 53313 ]
    VID_VCU_RESERVED10                           , // [ vid = 53314 ]
    VID_VCU_RESERVED11                           , // [ vid = 53315 ]
    VID_VCU_RESERVED12                           , // [ vid = 53316 ]
    VID_VCU_RESERVED13                           , // [ vid = 53317 ]
    VID_VCU_RESERVED14                           , // [ vid = 53318 ]
    VID_VCU_RESERVED15                           , // [ vid = 53319 ]
    VID_VCU_RESERVED16                           , // [ vid = 53320 ]
    VID_VCU_RESERVED17                           , // [ vid = 53321 ]
    VID_VCU_RESERVED18                           , // [ vid = 53322 ]
    VID_VCU_RESERVED19                           , // [ vid = 53323 ]
    VID_VCU_RESERVED20                           , // [ vid = 53324 ]
    VID_VCU_RESERVED21                           , // [ vid = 53325 ]
    VID_VCU_RESERVED22                           , // [ vid = 53326 ]
    VID_VCU_RESERVED23                           , // [ vid = 53327 ]
    VID_VCU_RESERVED24                           , // [ vid = 53328 ]
    VID_VCU_RESERVED25                           , // [ vid = 53329 ]
    VID_VCU_RESERVED26                           , // [ vid = 53330 ]
    VID_VCU_RESERVED27                           , // [ vid = 53331 ]
    VID_VCU_RESERVED28                           , // [ vid = 53332 ]
    VID_VCU_RESERVED29                           , // [ vid = 53333 ]
    VID_VCU_RESERVED30                           , // [ vid = 53334 ]
    VID_VCU_RESERVED31                           , // [ vid = 53335 ]
    VID_VCU_RESERVED32                           , // [ vid = 53336 ]
    VID_VCU_RESERVED33                           , // [ vid = 53337 ]
    VID_VCU_RESERVED34                           , // [ vid = 53338 ]
    VID_VCU_RESERVED35                           , // [ vid = 53339 ]
    VID_VCU_RESERVED36                           , // [ vid = 53340 ]
    VID_VCU_RESERVED37                           , // [ vid = 53341 ]
    VID_VCU_RESERVED38                           , // [ vid = 53342 ]
    VID_VCU_RESERVED39                           , // [ vid = 53343 ]
    VID_VCU_RESERVED40                           , // [ vid = 53344 ]
    VID_VCU_MAX_NUM = 256                          // [ vid = 53345 ] 本类设备VID个数  [ 97 ]
};

enum enParabmsVidChr                            //充电VID参数   起始0xD400
{
    VID_CHR_ONLINE                               , // [ vid = 54272 ] 充电机在线状态
    VID_CHR_STATE                                , // [ vid = 54273 ] 充电机状态
    VID_CHR_CTRL                                 , // [ vid = 54274 ] 充电机控制命令
    VID_CHR_STEP                                 , // [ vid = 54275 ] 充电阶段
    VID_CHR_ALARM                                , // [ vid = 54276 ] 充电机故障代码
    VID_CHR_VOLT_OUTPUT                          , // [ vid = 54277 ] 充电电压 - 充电机输出值
    VID_CHR_CURR_OUTPUT                          , // [ vid = 54278 ] 充电电流 - 充电机输出值
    VID_CHR_VOLT_REQUEST                         , // [ vid = 54279 ] 充电电压 - 请求值
    VID_CHR_CURR_REQUEST                         , // [ vid = 54280 ] 充电电流 - 请求值
    VID_CHR_CC                                   , // [ vid = 54281 ] 充电机CC  [ 0:未连接 1：连接 ]
    VID_CHR_RELAY_STATE                          , // [ vid = 54282 ] 充电继电器状态  [ 0：断开 1：闭合 ]
    VID_CHR_TYPE                                 , // [ vid = 54283 ] 充电机类型
    VID_CHR_CHARGING                             , // [ vid = 54284 ]
    VID_CHR_RESERVED2                            , // [ vid = 54285 ]
    VID_CHR_RESERVED3                            , // [ vid = 54286 ]
    VID_CHR_RESERVED4                            , // [ vid = 54287 ]
    VID_CHR_RESERVED5                            , // [ vid = 54288 ]
    VID_CHR_RESERVED6                            , // [ vid = 54289 ]
    VID_CHR_RESERVED7                            , // [ vid = 54290 ]
    VID_CHR_RESERVED8                            , // [ vid = 54291 ]
    VID_CHR_RESERVED9                            , // [ vid = 54292 ]
    VID_CHR_CURR_REQUEST_TMP                     , // [ vid = 54293 ] 充电电流 - 实际请求值
    VID_CHR_CC2		                             , // [ vid = 54294 ] 充电机CC2  [ 0:未连接 1：连接 ]
    VID_CHR_RESERVED12                           , // [ vid = 54295 ]
    VID_CHR_MAX_NUM                                // [ vid = 54296 ]本类设备VID个数  [ 24 ]
};

enum enParabmsPidSys                                //系统PID参数   起始0xF000
{
    PID_START                                        , // [ vid = 0xF000 ] ( 0 )开始  [ 不用 ]
    PID_SYS_BAT_NUM                                  , // [ vid = 0xF001 ] ( 1 )电池组数
    PID_SYS_BSU_NUM                                  , // [ vid = 0xF002 ] ( 2 )每组电池的BSU个数
    PID_SYS_CFG_VER                                  , // [ vid = 0xF003 ] ( 3 )配置文件版本

    PID_SYS_LEM_HALL_TYPE                            , // [ vid = 0xF004 ] ( 4 )LEM霍尔类型  [ 18, 24, … ]
    PID_SYS_BMU_ADDR                                 , // [ vid = 0xF005 ] ( 5 )后台通信地址
    PID_SYS_BMU_BAUD                                 , // [ vid = 0xF006 ] ( 6 )后台通信波特率  [ 0=9600,1=19200,2=... ]

    PID_SYS_HCU_TYPE                                 , // [ vid = 0xF007 ] ( 7 )后台HCU协议类型
    PID_SYS_CHR_TYPE_ON_BOARD                        , // [ vid = 0xF008 ] ( 8 )车载充电机类型

    PID_SYS_BMU_TYPE                                 , // [ vid = 0xF009 ] ( 9 )BMU类型  [ 0=主控器，1=LCD显示屏 ]
    PID_SYS_BSU_TYPE                                 , // [ vid = 0xF00A ] ( 10 )BSU类型  [ 0=12S，1=30S,  ]

    PID_SYS_RUN_HOUR                                 , // [ vid = 0xF00B ] ( 11 )累计运行时间  [ H ]
    PID_SYS_LAST_PWR_OFF_MD                          , // [ vid = 0xF00C ] ( 12 )上次关机时刻月日  [ 记录上次关机绝对时间 ]
    PID_SYS_LAST_PWR_OFF_HM                          , // [ vid = 0xF00D ] ( 13 )上次关机时刻时分  [ 记录上次关机绝对时间 ]

    PID_SYS_ALARM_QUIET                              , // [ vid = 0xF00E ] ( 14 )告警消音控制  [ 0=告警消音,1=不消音 ]
    PID_SYS_BMU_FAULT                                , // [ vid = 0xF00F ] ( 15 )BMU自身故障代码  [ 每一位代表一种故障 ]

    PID_SYS_CURR_SENSOR_TYPE                         , // [ vid = 0xF010 ] ( 16 )电流传感器类型  [ 0=霍尔，1=分流器 ]
    PID_SYS_HALL_RATED_CURR                          , // [ vid = 0xF011 ] ( 17 )霍尔额定电流  [ A ]
    PID_SYS_HALL_RATED_VOLT                          , // [ vid = 0xF012 ] ( 18 )霍尔额定电压  [ mV ]
    PID_SYS_HALL_ZERO                                , // [ vid = 0xF013 ] ( 19 )霍尔零点即实际电流为0时霍尔显示值  [ 0.1A ]
    PID_SYS_HALL_POSI                                , // [ vid = 0xF014 ] ( 20 )霍尔传感器位置  [ 0=BMU,99=绝缘模块 ]
    PID_SYS_SHUNT_RATED_CURR                         , // [ vid = 0xF015 ] ( 21 )分流器额定电流  [ A ]
    PID_SYS_SHUNT_RATED_VOLT                         , // [ vid = 0xF016 ] ( 22 )分流器额定电压  [ mV ]

    PID_SYS_RELAY1_CTRL_TYPE                         , // [ vid = 0xF017 ] ( 23 )继电器1控制类型  [ 0=与告警无关 ]
    PID_SYS_RELAY2_CTRL_TYPE                         , // [ vid = 0xF018 ] ( 24 )继电器2控制类型  [ 1=仅当有告警时断开 ]
    PID_SYS_RELAY3_CTRL_TYPE                         , // [ vid = 0xF019 ] ( 25 )继电器3控制类型  [ 2=仅当无告警时闭合 ]
    PID_SYS_RELAY4_CTRL_TYPE                         , // [ vid = 0xF01A ] ( 26 )继电器4控制类型  [ 3=与告警强关联 ]
    PID_SYS_RELAY5_CTRL_TYPE                         , // [ vid = 0xF01B ] ( 27 )继电器5控制类型
    PID_SYS_RELAY6_CTRL_TYPE                         , // [ vid = 0xF01C ] ( 28 )继电器6控制类型
    PID_SYS_RELAY7_CTRL_TYPE                         , // [ vid = 0xF01D ] ( 29 )继电器7控制类型
    PID_SYS_RELAY8_CTRL_TYPE                         , // [ vid = 0xF01E ] ( 30 )继电器8控制类型

    PID_SYS_FAN_START_TEMP                           , // [ vid = 0xF01F ] ( 31 )风扇启动温度  [ ℃ ]
    PID_SYS_FAN_STOP_TEMP                            , // [ vid = 0xF020 ] ( 32 )风扇关闭温度  [ ℃ ]
    PID_SYS_FAN_START_DIFF                           , // [ vid = 0xF021 ] ( 33 )风扇启动温差  [ ℃ ]
    PID_SYS_FAN_STOP_DIFF                            , // [ vid = 0xF022 ] ( 34 )风扇关闭温差  [ ℃ ]
    PID_SYS_HOT_START_TEMP                           , // [ vid = 0xF023 ] ( 35 )加热启动温度  [ ℃ ]
    PID_SYS_HOT_STOP_TEMP                            , // [ vid = 0xF024 ] ( 36 )加热关闭温度  [ ℃ ]

    PID_SYS_OPEN_VOLT_SOC_ENABLE                     , // [ vid = 0xF025 ] ( 37 )开路电压设置SOC开关  [ 0=关闭，1=打开 ]
    PID_SYS_OCV_TEMP_UP                              , // [ vid = 0xF026 ] ( 38 )开路电压有效温度上限  [ ℃ ]
    PID_SYS_OCV_TEMP_DOWN                            , // [ vid = 0xF027 ] ( 39 )开路电压有效温度下限  [ ℃ ]
    PID_SYS_00SOC_VOLT                               , // [ vid = 0xF028 ] ( 40 )SOC=0%时的开路电压  [ mV ]
    PID_SYS_10SOC_VOLT                               , // [ vid = 0xF029 ] ( 41 )SOC=10%时的开路电压  [ mV ]
    PID_SYS_20SOC_VOLT                               , // [ vid = 0xF02A ] ( 42 )SOC=20%时的开路电压  [ mV ]
    PID_SYS_30SOC_VOLT                               , // [ vid = 0xF02B ] ( 43 )SOC=30%时的开路电压  [ mV ]
    PID_SYS_40SOC_VOLT                               , // [ vid = 0xF02C ] ( 44 )SOC=40%时的开路电压  [ mV ]
    PID_SYS_50SOC_VOLT                               , // [ vid = 0xF02D ] ( 45 )SOC=50%时的开路电压  [ mV ]
    PID_SYS_60SOC_VOLT                               , // [ vid = 0xF02E ] ( 46 )SOC=60%时的开路电压  [ mV ]
    PID_SYS_70SOC_VOLT                               , // [ vid = 0xF02F ] ( 47 )SOC=70%时的开路电压  [ mV ]
    PID_SYS_80SOC_VOLT                               , // [ vid = 0xF030 ] ( 48 )SOC=80%时的开路电压  [ mV ]
    PID_SYS_90SOC_VOLT                               , // [ vid = 0xF031 ] ( 49 )SOC=90%时的开路电压  [ mV ]
    PID_SYS_100SOC_VOLT                              , // [ vid = 0xF032 ] ( 50 )SOC=100%时的开路电压  [ mV ]

    PID_SYS_BAL_MODE                                 , // [ vid = 0xF033 ] ( 51 )均衡模式  [ 0=主动均衡，1=被动均衡 ]
    PID_SYS_BAL_CURR                                 , // [ vid = 0xF034 ] ( 52 )电池均衡电流设置值  [ mA ]
    PID_SYS_BAL_START_VOLT                           , // [ vid = 0xF035 ] ( 53 )电池均衡启动压差  [ mV ]
    PID_SYS_BAL_START_CAPA                           , // [ vid = 0xF036 ] ( 54 )电池均衡启动容量差值  [ 0.1AH ]
    PID_SYS_BAL_PROT_VOLT_UP                         , // [ vid = 0xF037 ] ( 55 )均衡保护电压上限  [ mV ]
    PID_SYS_BAL_PROT_VOLT_DN                         , // [ vid = 0xF038 ] ( 56 )均衡保护电压下限  [ mV ]
    PID_SYS_BAL_TIME_ACTIVE                          , // [ vid = 0xF039 ] ( 57 )主动均衡时间  [ S ]
    PID_SYS_BAL_TIME_PASSIVE                         , // [ vid = 0xF03A ] ( 58 )被动均衡时间  [ S ]
    PID_SYS_BAL_DURATION_PASSIVE                     , // [ vid = 0xF03B ] ( 59 )被动均衡持续时间  [ ms ]
    PID_SYS_BAL_START_VOLT_PASSIVE                   , // [ vid = 0xF03C ] ( 60 )被动均衡启动电压  [ mv ]
    PID_SYS_BAL_START_VOLT_ACTIVE                    , // [ vid = 0xF03D ] ( 61 )主动均衡启动压差  [ mv ]
    PID_SYS_BAL_PHASE_ACTIVE                         , // [ vid = 0xF03E ] ( 62 )主动均衡阶段  [ 0：全程开启均衡 1：充电时开启均衡 ]
    PID_SYS_BAL_MODE_ACTIVE                          , // [ vid = 0xF03F ] ( 63 )主动均衡模式  [ 0：正常模式 1：测试模式(充电时，只开放电均衡；放电时，只开充电均衡) ]
    PID_SYS_BAL_RESERVED3                            , // [ vid = 0xF040 ] ( 64 )
    PID_SYS_BAL_RESERVED4                            , // [ vid = 0xF041 ] ( 65 )

    PID_SYS_SOC_AUTOSET                              , // [ vid = 0xF042 ] ( 66 )自动设置SOC开关  [ 0=关闭，1=打开 ]
    PID_SYS_SOC_SET_UP                               , // [ vid = 0xF043 ] ( 67 )运行过程中SOC修正值上限
    PID_SYS_SOC_UPSET_DELAY                          , // [ vid = 0xF044 ] ( 68 )上置位SOC延时
    PID_SYS_SOC_DNSET_DELAY                          , // [ vid = 0xF045 ] ( 69 )下置位SOC延时
    PID_SYS_0CURR_SET_TIME                           , // [ vid = 0xF046 ] ( 70 )0电流持续延时设置SOC  [ H ]

    PID_GPRS_MODULE_TYPE                             , // [ vid = 0xF047 ] ( 71 )GPRS模块类型  [ 0=WISOM228,1=M10 ]
    PID_GPRS_PROVIDER                                , // [ vid = 0xF048 ] ( 72 )GPRS供应商  [ 0=关闭,1=移动,2=联通,3=电信 ]
    PID_GPRS_IP1                                     , // [ vid = 0xF049 ] ( 73 )GPRS IP地址1
    PID_GPRS_IP2                                     , // [ vid = 0xF04A ] ( 74 )GPRS IP地址2
    PID_GPRS_IP3                                     , // [ vid = 0xF04B ] ( 75 )GPRS IP地址3
    PID_GPRS_IP4                                     , // [ vid = 0xF04C ] ( 76 )GPRS IP地址4
    PID_GPRS_PORT                                    , // [ vid = 0xF04D ] ( 77 )GPRS端口号
    PID_GPRS_CONN_TIMEOUT                            , // [ vid = 0xF04E ] ( 78 )GPRS连接超时时间  [ S ]
    PID_GPRS_SEND_INTV                               , // [ vid = 0xF04F ] ( 79 )GPRS发送时间最小间隔  [ S ]
    PID_GPRS_PACK2_TIME                              , // [ vid = 0xF050 ] ( 80 )GPRS第2类数据发送间隔  [ 0.1S ]
    PID_GPRS_PACK3_TIME                              , // [ vid = 0xF051 ] ( 81 )GPRS第3类数据发送间隔  [ 0.1S ]
    PID_GPRS_PACK4_TIME                              , // [ vid = 0xF052 ] ( 82 )GPRS第4类数据发送间隔  [ 0.1S ]
    PID_GPRS_PACK5_TIME                              , // [ vid = 0xF053 ] ( 83 )GPRS第5类数据发送间隔  [ 0.1S ]
    PID_GPRS_RECV_TIMEOUT                            , // [ vid = 0xF054 ] ( 84 )GPRS接收OK超时时间  [ S ]
    PID_GPRS_SAVE_MODE                               , // [ vid = 0xF055 ] ( 85 )GPRS节省流量模式  [ 0=禁止，1=使能 ]
    PID_GPRS_ENABLE                              	 , // [ vid = 0xF056 ] ( 86 )GPRS使能开关 [ 0=禁止，1=使能 ]

    PID_SYS_BIU_POSI                                 , // [ vid = 0xF057 ] ( 87 )绝缘模块位置  [ 0=BMU,99=绝缘模块 ]
    PID_SYS_JY_ENABLE                                , // [ vid = 0xF058 ] ( 88 )绝缘检测使能  [ 0=禁止，1=使能 ]
    PID_SYS_JY_SPEED                                 , // [ vid = 0xF059 ] ( 89 )绝缘功能运行速度  [ 投切后等待次数 ]
    PID_SYS_JY_RESERVED                              , // [ vid = 0xF05A ] ( 90 )绝缘备用参数

    PID_BAT_TYPE                                     , // [ vid = 0xF05B ] ( 91 )电池类型
    PID_BAT_CHRG_COEF                                , // [ vid = 0xF05C ] ( 92 )充电系数  [ % ]
    PID_BAT_DSCH_COEF                                , // [ vid = 0xF05D ] ( 93 )放电系数  [ % ]
    PID_BAT_RATED_CAPA                               , // [ vid = 0xF05E ] ( 94 )电池额定容量  [ AH ]
    PID_BAT_CELL_RATED_VOLT                          , // [ vid = 0xF05F ] ( 95 )单体额定电压  [ mV ]

    PID_SYS_MAX_CHRG_VOLT                            , // [ vid = 0xF060 ] ( 96 )充电机最大电压  [ V ]
    PID_SYS_MAX_FAST_CHRG_CURR                       , // [ vid = 0xF061 ] ( 97 )电池允许最大充电电流(快充) [ A ]
    PID_SYS_MAX_SLOW_CHRG_CURR                       , // [ vid = 0xF062 ] ( 98 )电池允许最大充电电流(慢充) [ A ]
    PID_SYS_MAX_CELL_CHRG_VOLT                       , // [ vid = 0xF063 ] ( 99 )单体最高允许充电电压  [1-4:告警点，其他： mV ]
    PID_SYS_CHRG_END_CURR                            , // [ vid = 0xF064 ] ( 100 )充电机最小充电电流（充电完成电流）  [ A ]
    PID_SYS_MIN_CELL_CHRG_VOLT                       , // [ vid = 0xF065 ] ( 101 )单体最低允许充电电压  [1-4:告警点，其他： mV ]
    PID_SYS_CHRG_HEAT_CURR                           , // [ vid = 0xF066 ] ( 102 )充电加热请求电流 [ A ]
    PID_SYS_CHRG_HEAT_VOLT	                         , // [ vid = 0xF067 ] ( 103 )充电加热请求电压 [ V ] [ 0=电池电压，其他=配置电压 ]

    PID_SYS_SOC                                      , // [ vid = 0xF068 ] ( 104 )系统SOC
    PID_SYS_SOH                                      , // [ vid = 0xF069 ] ( 105 )系统SOH
    PID_SYS_PERIOD_CHRG_TIME                         , // [ vid = 0xF06A ] ( 106 )间歇式充电时间  [ S ]
    PID_SYS_DORMANT_TIME                             , // [ vid = 0xF06B ] ( 107 )休眠时间  [ S ]
    PID_SYS_SELF_CONSUME                             , // [ vid = 0xF06C ] ( 108 )系统自耗电  [ 0.1A ]
    PID_SYS_SELF_CONSUME_SOC                         , // [ vid = 0xF06D ] ( 109 )系统自耗电是否参与SOC计算  [ 0=关闭，1=打开 ]

    PID_SYS_ALARM_RUN_START                          , // [ vid = 0xF06E ] ( 110 )告警模块开始工作时间  [ S，前N秒不处理告警 ]
    PID_SYS_HALL_DIRECTION                           , // [ vid = 0xF06F ] ( 111 )霍尔方向  [ 0：对着充电方向（充电为正，放电为负），1：对着放电方向（放电为正，充电为负） ]

    PID_SYS_PRECHARGE_MODE                           , // [ vid = 0xF070 ] ( 112 )预充时间  [ 0.1S，0=不预充，N=最大预充时间 ]
    PID_SYS_PRECHARGE_VOLT_RATE                      , // [ vid = 0xF071 ] ( 113 )预充电压百分比  [ % ]
    PID_SYS_PRECHARGE_END_CURR                       , // [ vid = 0xF072 ] ( 114 )预充结束电流  [ 0.1A ]
    PID_SYS_BATT_RATED_ENERGY                        , // [ vid = 0xF073 ] ( 115 )蓄电池标称总能量  [ 0.1KWH ]
    PID_SYS_CELL_MAX_CHRG_VOLT                       , // [ vid = 0xF074 ] ( 116 )单体最高允许充电电压  [ mV ]

    PID_SYS_FORCE_CHRG_INPUT                         , // [ vid = 0xF075 ] ( 117 )强充输入干接点  [ 0=无强充，1~3=输入干接点，11~13=输入常闭 ]

    PID_SYS_RELAY_1                                  , // [ vid = 0xF076 ] ( 118 )K1继电器功能定义（CPU板上）  [ 1：预充继电器 ]
    PID_SYS_RELAY_2                                  , // [ vid = 0xF077 ] ( 119 )K2继电器功能定义（CPU板上）  [ 2：总正（主）继电器 ]
    PID_SYS_RELAY_3                                  , // [ vid = 0xF078 ] ( 120 )K3继电器功能定义（CPU板上）  [ 3：充电继电器 ]
    PID_SYS_RELAY_4                                  , // [ vid = 0xF079 ] ( 121 )K4继电器功能定义（低板上）  [ 4：外部继电器 ]
    PID_SYS_RELAY_5                                  , // [ vid = 0xF07A ] ( 122 )K5继电器功能定义（低板上）  [ 5：加热继电器 ]
    PID_SYS_RELAY_6                                  , // [ vid = 0xF07B ] ( 123 )K6继电器功能定义（低板上）  [ 6：总负继电器 ]
    PID_SYS_RELAY_7                                  , // [ vid = 0xF07C ] ( 124 )K7继电器功能定义（低板上）  [ 7：休眠（控制BSU电源） ]
    PID_SYS_RELAY_8                                  , // [ vid = 0xF07D ] ( 125 )K8继电器功能定义（低板上）  [ 8: 主控器电源 ]
    PID_SYS_RELAY_9                                  , // [ vid = 0xF07E ] ( 126 )K9继电器功能定义（BSU上风扇）  [ 9：BSU预充继电器 ]
    PID_SYS_RELAY_10                                 , // [ vid = 0xF07F ] ( 127 )K10继电器功能定义（BSU上加热）  [ 10：BSU主继电器 11：主控器风扇 ]

    PID_SYS_CHRG_INTERLOCK                           , // [ vid = 0xF080 ] ( 128 )充放电互锁  [ 0：互锁，1：不互锁，充电时断开放电回路 ]
    PID_SYS_RELAY_RESET                              , // [ vid = 0xF081 ] ( 129 )告警恢复是是否恢复继电器  [ 0：不回复，1：恢复 ]

    PID_SYS_RUN_RANGE                                , // [ vid = 0xF082 ] ( 130 )主控器使用的环境（车上，储能的继电器控制方式不同）  [ 0：纯电动 1：混合动力 2：储能系统 ]
    PID_SYS_CHR_TYPE_OFF_BOARD                       , // [ vid = 0xF083 ] ( 131 )非车载充电机  [ 3=国标；4=普天 ]
    PID_SYS_BASE_BOARD_VER                           , // [ vid = 0xF084 ] ( 132 )强制设置底板版本  [ 0:不设置 ]

    PID_SYS_CHR_ON_TRICKLE_TIME                      , // [ vid = 0xF085 ] ( 133 )交流充电机 Trickle间隔  [ 1S ]
    PID_SYS_CHR_ON_CURR_COE                          , // [ vid = 0xF086 ] ( 134 )交流充电机 电流下降的系数  [ % ]
    PID_SYS_CHR_CC_POS                               , // [ vid = 0xF087 ] ( 135 )充电机CC2 所在的位置  [ 0:电源端子，1-3：D1-D3 9:BMU-J9端子]

    PID_SYS_HOT_PHASE                                , // [ vid = 0xF088 ] ( 136 )加热管理  [ 0:全程加热 1：充电时加热 ]
    PID_SYS_AUX_POS                                  , // [ vid = 0xF089 ] ( 137 )主继电器辅助触点 所在的位置  [ 0:无辅助触点，1-3：D1-D3 ]
    PID_SYS_POWER_OFF_INPUT                          , // [ vid = 0xF08A ] ( 138 )手动关机输入干接点  [ 0=无强充，1~3=输入干接点，11~13=输入常闭 ]
    PID_SYS_ISO_MODE                                 , // [ vid = 0xF08B ] ( 139 )绝缘监测设置  [ 0：全程检测 1：充电时不检测 ]
    PID_SYS_OUT_RELAY_TYPE                           , // [ vid = 0xF08C ] ( 140 )外部继电器控制逻辑  [ 1=新大洋；2=珠海嘉德 ]
    PID_SYS_PRE_MIN_TIME                             , // [ vid = 0xF08D ] ( 141 )预充最小时间  [ 0.01S ] 未用
    PID_SYS_SAMPLE_ACCURACY                          , // [ vid = 0xF08E ] ( 142 )BSU单体电压采样精度  [ 1mV ]
    PID_SYS_CELL_SEQUENCE                            , // [ vid = 0xF08F ] ( 143 )单体电池序号  [ 0：科列定义（单体序号从总正开始）1：单体序号从总负开始 ]
    PID_SYS_LOG_TIME                                 , // [ vid = 0xF090 ] ( 144 )内部存储保存电池数据间隔  [ 1S ]
    PID_SYS_LOG_ENABLE                               , // [ vid = 0xF091 ] ( 145 )内部存储使能
    PID_SYS_FAN_PWM_FREQ                             , // [ vid = 0xF092 ] ( 146 )风扇PWM频率  [ Hz ]
    PID_SYS_RESERVED12                               , // [ vid = 0xF093 ] ( 147 )预留
    PID_SYS_CHR_MIN_CURR                             , // [ vid = 0xF094 ] ( 148 )充电机最小充电电流（充电完成电流）  [ A ]
    PID_SYS_CONSTANT_MODE                            , // [ vid = 0xF095 ] ( 149 )预留(宇通显示屏)
    PID_SYS_DSCH_POWER_LV1                           , // [ vid = 0xF096 ] ( 150 )1级放电功率
    PID_SYS_DSCH_POWER_LV2                           , // [ vid = 0xF097 ] ( 151 )2级放电功率
    PID_SYS_DSCH_POWER_LV3                           , // [ vid = 0xF098 ] ( 152 )3级放电功率
    PID_SYS_DSCH_POWER_LV4                           , // [ vid = 0xF099 ] ( 153 )4级放电功率
    PID_SYS_CHRG_POWER_LV1                           , // [ vid = 0xF09A ] ( 154 )1级充电功率
    PID_SYS_CHRG_POWER_LV2                           , // [ vid = 0xF09B ] ( 155 )2级充电功率
    PID_SYS_CHRG_POWER_LV3                           , // [ vid = 0xF09C ] ( 156 )3级充电功率
    PID_SYS_CHRG_POWER_LV4                           , // [ vid = 0xF09D ] ( 157 )4级充电功率
    PID_CHRG_CONSTANT_MODE                           , // [ vid = 0xF09E ] ( 158 )非车载充电恒压控制方式(更改后需要重启生效)  [ 0:BMS发恒压命令，充电机控制恒压 1：BMS控制恒压 ]
    PID_CHRG_ON_BOARD_CHANNEL                        , // [ vid = 0xF09F ] ( 159 )车载充电机所在CAN的通道  [ 0,1,2:在CAN2上 3:在CAN3上 ]
    PID_SYS_RESERVED25                               , // [ vid = 0xF0A0 ] ( 160 )预留
    PID_SYS_RELAY_CURR                               , // [ vid = 0xF0A1 ] ( 161 )继电器保护是否和电流有关联  [ 0:继电器切断和电流有关系 1:和电流无关 ]
    PID_SYS_SLEEP_ENABLE                             , // [ vid = 0xF0A2 ] ( 162 )BMU休眠功能使能（BMU控制BSU电源）  [ 0=禁止，1=使能 ]
    PID_SYS_BTS_NUM                                  , // [ vid = 0xF0A3 ] ( 163 )温度采集模块个数
    PID_SYS_BACKLIGHT_TIME                           , // [ vid = 0xF0A4 ] ( 164 )LCD显示屏关闭背光时间  [ 秒.0=不关闭 ]
    PID_SYS_CHECK_HV_ENABLE                          , // [ vid = 0xF0A5 ] ( 165 )高压自检使能开关  [ 0=禁止，1=使能 ]
    PID_SYS_POWER_CTRL_TYPE                          , // [ vid = 0xF0A6 ] ( 166 )功率控制类型  [0=简易，1=详细]
    PID_SYS_MAIN_POS_DI                              , // [ vid = 0xF0A7 ] ( 167 )总正继电器回采DI
    PID_SYS_MAIN_NEG_DI                              , // [ vid = 0xF0A8 ] ( 168 )总负继电器回采DI
    PID_SYS_RESERVED34                               , // [ vid = 0xF0A9 ] ( 169 )预留
    PID_SYS_RESERVED35                               , // [ vid = 0xF0AA ] ( 170 )预留
    PID_SYS_RESERVED36                               , // [ vid = 0xF0AB ] ( 171 )预留
    PID_SYS_RESERVED37                               , // [ vid = 0xF0AC ] ( 172 )预留
    PID_SYS_RESERVED38                               , // [ vid = 0xF0AD ] ( 173 )预留
    PID_SYS_RESERVED39                               , // [ vid = 0xF0AE ] ( 174 )预留
    PID_SYS_RESERVED40                               , // [ vid = 0xF0AF ] ( 175 )预留
    PID_SYS_RESERVED41                               , // [ vid = 0xF0B0 ] ( 176 )预留
    PID_SYS_RESERVED42                               , // [ vid = 0xF0B1 ] ( 177 )预留
    PID_SYS_RESERVED43                               , // [ vid = 0xF0B2 ] ( 178 )预留
    PID_SYS_RESERVED44                               , // [ vid = 0xF0B3 ] ( 179 )预留
    PID_SYS_RESERVED45                               , // [ vid = 0xF0B4 ] ( 180 )预留
    PID_SYS_RESERVED46                               , // [ vid = 0xF0B5 ] ( 181 )预留
    PID_SYS_RESERVED47                               , // [ vid = 0xF0B6 ] ( 182 )预留
    PID_SYS_RESERVED48                               , // [ vid = 0xF0B7 ] ( 183 )预留
    PID_SYS_RESERVED49                               , // [ vid = 0xF0B8 ] ( 184 )预留
    PID_SYS_RESERVED50                               , // [ vid = 0xF0B9 ] ( 185 )预留
    PID_SYS_RESERVED51                               , // [ vid = 0xF0BA ] ( 186 )预留
    PID_SYS_RESERVED52                               , // [ vid = 0xF0BB ] ( 187 )预留
    PID_SYS_RESERVED53                               , // [ vid = 0xF0BC ] ( 188 )预留
    PID_SYS_RESERVED54                               , // [ vid = 0xF0BD ] ( 189 )预留
    PID_SYS_RESERVED55                               , // [ vid = 0xF0BE ] ( 190 )预留
    PID_SYS_RESERVED56                               , // [ vid = 0xF0BF ] ( 191 )预留
    PID_SYS_RESERVED57                               , // [ vid = 0xF0C0 ] ( 192 )预留
    PID_SYS_RESERVED58                               , // [ vid = 0xF0C1 ] ( 193 )预留
    PID_SYS_RESERVED59                               , // [ vid = 0xF0C2 ] ( 194 )预留
    PID_SYS_RESERVED60                               , // [ vid = 0xF0C3 ] ( 195 )预留
    PID_SYS_RESERVED61                               , // [ vid = 0xF0C4 ] ( 196 )预留
    PID_SYS_RESERVED62                               , // [ vid = 0xF0C5 ] ( 197 )预留
    PID_SYS_RESERVED63                               , // [ vid = 0xF0C6 ] ( 198 )预留
    PID_SYS_RESERVED64                               , // [ vid = 0xF0C7 ] ( 199 )预留
    PID_SYS_RESERVED65                               , // [ vid = 0xF0C8 ] ( 200 )预留
    PID_SYS_RESERVED66                               , // [ vid = 0xF0C9 ] ( 201 )预留
    PID_SYS_RESERVED67                               , // [ vid = 0xF0CA ] ( 202 )预留
    PID_SYS_RESERVED68                               , // [ vid = 0xF0CB ] ( 203 )预留
    PID_SYS_RESERVED69                               , // [ vid = 0xF0CC ] ( 204 )预留
    PID_SYS_RESERVED70                               , // [ vid = 0xF0CD ] ( 205 )预留
    PID_SYS_RESERVED71                               , // [ vid = 0xF0CE ] ( 206 )预留
    PID_SYS_RESERVED72                               , // [ vid = 0xF0CF ] ( 207 )预留
    PID_SYS_RESERVED73                               , // [ vid = 0xF0D0 ] ( 208 )预留
    PID_SYS_RESERVED74                               , // [ vid = 0xF0D1 ] ( 209 )预留
    PID_SYS_RESERVED75                               , // [ vid = 0xF0D2 ] ( 210 )预留
    PID_SYS_RESERVED76                               , // [ vid = 0xF0D3 ] ( 211 )预留
    PID_SYS_RESERVED77                               , // [ vid = 0xF0D4 ] ( 212 )预留
    PID_SYS_RESERVED78                               , // [ vid = 0xF0D5 ] ( 213 )预留
    PID_SYS_RESERVED79                               , // [ vid = 0xF0D6 ] ( 214 )预留
    PID_SYS_RESERVED80                               , // [ vid = 0xF0D7 ] ( 215 )预留
    PID_SYS_RESERVED81                               , // [ vid = 0xF0D8 ] ( 216 )预留
    PID_SYS_RESERVED82                               , // [ vid = 0xF0D9 ] ( 217 )预留
    PID_SYS_RESERVED83                               , // [ vid = 0xF0DA ] ( 218 )预留
    PID_SYS_RESERVED84                               , // [ vid = 0xF0DB ] ( 219 )预留
    PID_SYS_RESERVED85                               , // [ vid = 0xF0DC ] ( 220 )预留
    PID_SYS_RESERVED86                               , // [ vid = 0xF0DD ] ( 221 )预留
    PID_SYS_RESERVED87                               , // [ vid = 0xF0DE ] ( 222 )预留
    PID_SYS_RESERVED88                               , // [ vid = 0xF0DF ] ( 223 )预留
    PID_SYS_RESERVED89                               , // [ vid = 0xF0E0 ] ( 224 )预留
    PID_SYS_RESERVED90                               , // [ vid = 0xF0E1 ] ( 225 )预留
    PID_SYS_RESERVED91                               , // [ vid = 0xF0E2 ] ( 226 )预留
    PID_SYS_RESERVED92                               , // [ vid = 0xF0E3 ] ( 227 )预留
    PID_SYS_RESERVED93                               , // [ vid = 0xF0E4 ] ( 228 )预留
    PID_SYS_RESERVED94                               , // [ vid = 0xF0E5 ] ( 229 )预留
    PID_SYS_RESERVED95                               , // [ vid = 0xF0E6 ] ( 230 )预留
    PID_SYS_RESERVED96                               , // [ vid = 0xF0E7 ] ( 231 )预留
    PID_SYS_RESERVED97                               , // [ vid = 0xF0E8 ] ( 232 )预留
    PID_SYS_RESERVED98                               , // [ vid = 0xF0E9 ] ( 233 )预留
    PID_SYS_RESERVED99                               , // [ vid = 0xF0EA ] ( 234 )预留
    PID_SYS_RESERVED100                              , // [ vid = 0xF0EB ] ( 235 )预留
    PID_SYS_RESERVED101                              , // [ vid = 0xF0EC ] ( 236 )预留
    PID_SYS_RESERVED102                              , // [ vid = 0xF0ED ] ( 237 )预留
    PID_SYS_RESERVED103                              , // [ vid = 0xF0EE ] ( 238 )预留
    PID_SYS_TEMP1                                    , // [ vid = 0xF0EF ] ( 239 )用作非标版本临时补救措施用
    PID_SYS_TEMP2                                    , // [ vid = 0xF0F0 ] ( 240 )用作非标版本临时补救措施用
    PID_SYS_TEMP3                                    , // [ vid = 0xF0F1 ] ( 241 )用作非标版本临时补救措施用
    PID_SYS_TEMP4                                    , // [ vid = 0xF0F2 ] ( 242 )用作非标版本临时补救措施用
    PID_SYS_TEMP5                                    , // [ vid = 0xF0F3 ] ( 243 )用作非标版本临时补救措施用
    PID_SYS_TEMP6                                    , // [ vid = 0xF0F4 ] ( 244 )用作非标版本临时补救措施用
    PID_SYS_TEMP7                                    , // [ vid = 0xF0F5 ] ( 245 )用作非标版本临时补救措施用
    PID_SYS_TEMP8                                    , // [ vid = 0xF0F6 ] ( 246 )用作非标版本临时补救措施用
    PID_SYS_TEMP9                                    , // [ vid = 0xF0F7 ] ( 247 )用作非标版本临时补救措施用
    PID_SYS_TEMP10                                   , // [ vid = 0xF0F8 ] ( 248 )用作非标版本临时补救措施用
    PID_SYS_TEMP11                                   , // [ vid = 0xF0F9 ] ( 249 )用作非标版本临时补救措施用
    PID_SYS_TEMP12                                   , // [ vid = 0xF0FA ] ( 250 )用作非标版本临时补救措施用
    PID_SYS_TEMP13                                   , // [ vid = 0xF0FB ] ( 251 )用作非标版本临时补救措施用
    PID_SYS_TEMP14                                   , // [ vid = 0xF0FC ] ( 252 )用作非标版本临时补救措施用
    PID_SYS_TEMP15                                   , // [ vid = 0xF0FD ] ( 253 )用作非标版本临时补救措施用
    PID_SYS_TEMP16                                   , // [ vid = 0xF0FE ] ( 254 )用作非标版本临时补救措施用
    PID_SYS_TEMP255									 , // [ vid = 0xF0FF ] ( 255 )备用

    PID_SYS_MAX_NUM                                    // [ vid = 0xF100 ]( 256 )系统参数最大PID  [ 256 ]
};

enum enBytePid                                      //字节PID
{
    PID_BYTE_RESERVED_00							, // [ vid = 0xFE00 ] ( 3584 )
    PID_BYTE_VIN_01									, // [ vid = 0xFE01 ] ( 3585 ) 车辆VIN
    PID_BYTE_VIN_02									, // [ vid = 0xFE02 ] ( 3586 )
    PID_BYTE_VIN_03									, // [ vid = 0xFE03 ] ( 3587 )
    PID_BYTE_VIN_04									, // [ vid = 0xFE04 ] ( 3588 )
    PID_BYTE_VIN_05									, // [ vid = 0xFE05 ] ( 3589 )
    PID_BYTE_VIN_06									, // [ vid = 0xFE06 ] ( 3590 )
    PID_BYTE_VIN_07									, // [ vid = 0xFE07 ] ( 3591 )
    PID_BYTE_VIN_08									, // [ vid = 0xFE08 ] ( 3592 )
    PID_BYTE_VIN_09									, // [ vid = 0xFE09 ] ( 3593 )
    PID_BYTE_VIN_10									, // [ vid = 0xFE0A ] ( 3594 )
    PID_BYTE_VIN_11									, // [ vid = 0xFE0B ] ( 3595 )
    PID_BYTE_VIN_12									, // [ vid = 0xFE0C ] ( 3596 )
    PID_BYTE_VIN_13									, // [ vid = 0xFE0D ] ( 3597 )
    PID_BYTE_VIN_14									, // [ vid = 0xFE0E ] ( 3598 )
    PID_BYTE_VIN_15									, // [ vid = 0xFE0F ] ( 3599 )
    PID_BYTE_VIN_16									, // [ vid = 0xFE10 ] ( 3600 )
    PID_BYTE_VIN_17									, // [ vid = 0xFE11 ] ( 3601 )

    PID_BYTE_RESERVED_18							, // [ vid = 0xFE12 ] ( 3602 )
    PID_BYTE_RESERVED_19							, // [ vid = 0xFE13 ] ( 3603 )
    PID_BYTE_RESERVED_20							, // [ vid = 0xFE14 ] ( 3604 )

    PID_BYTE_BMU_NAME_01                            , // [ vid = 0xFE15 ] ( 3605 ) 设备名称
    PID_BYTE_BMU_NAME_02                        	, // [ vid = 0xFE16 ] ( 3606 )
    PID_BYTE_BMU_NAME_03                    		, // [ vid = 0xFE17 ] ( 3607 )
    PID_BYTE_BMU_NAME_04                			, // [ vid = 0xFE18 ] ( 3608 )
    PID_BYTE_BMU_NAME_05            				, // [ vid = 0xFE19 ] ( 3609 )
    PID_BYTE_BMU_NAME_06        					, // [ vid = 0xFE1A ] ( 3610 )
    PID_BYTE_BMU_NAME_07    						, // [ vid = 0xFE1B ] ( 3611 )
    PID_BYTE_BMU_NAME_08							, // [ vid = 0xFE1C ] ( 3612 )
    PID_BYTE_BMU_NAME_09                            , // [ vid = 0xFE1D ] ( 3613 )
    PID_BYTE_BMU_NAME_10                        	, // [ vid = 0xFE1E ] ( 3614 )

    PID_BYTE_BMU_LABEL_01                   		, // [ vid = 0xFE1F ] ( 3615 ) 设备条码标签
    PID_BYTE_BMU_LABEL_02               			, // [ vid = 0xFE20 ] ( 3616 )
    PID_BYTE_BMU_LABEL_03           				, // [ vid = 0xFE21 ] ( 3617 )
    PID_BYTE_BMU_LABEL_04       					, // [ vid = 0xFE22 ] ( 3618 )
    PID_BYTE_BMU_LABEL_05   						, // [ vid = 0xFE23 ] ( 3619 )
    PID_BYTE_BMU_LABEL_06							, // [ vid = 0xFE24 ] ( 3620 )
    PID_BYTE_BMU_LABEL_07                           , // [ vid = 0xFE25 ] ( 3621 )
    PID_BYTE_BMU_LABEL_08                       	, // [ vid = 0xFE26 ] ( 3622 )
    PID_BYTE_BMU_LABEL_09                   		, // [ vid = 0xFE27 ] ( 3623 )
    PID_BYTE_BMU_LABEL_10               			, // [ vid = 0xFE28 ] ( 3624 )
    PID_BYTE_BMU_LABEL_11           				, // [ vid = 0xFE29 ] ( 3625 )
    PID_BYTE_BMU_LABEL_12       					, // [ vid = 0xFE2A ] ( 3626 )
    PID_BYTE_BMU_LABEL_13   						, // [ vid = 0xFE2B ] ( 3627 )
    PID_BYTE_BMU_LABEL_14							, // [ vid = 0xFE2C ] ( 3628 )
    PID_BYTE_BMU_LABEL_15                           , // [ vid = 0xFE2D ] ( 3629 )
    PID_BYTE_BMU_LABEL_16                       	, // [ vid = 0xFE2E ] ( 3630 )
    PID_BYTE_BMU_LABEL_17                   		, // [ vid = 0xFE2F ] ( 3631 )
    PID_BYTE_BMU_LABEL_18               			, // [ vid = 0xFE30 ] ( 3632 )
    PID_BYTE_BMU_LABEL_19           				, // [ vid = 0xFE31 ] ( 3633 )
    PID_BYTE_BMU_LABEL_20       					, // [ vid = 0xFE32 ] ( 3634 )

    PID_BYTE_BMU_YEAR								, // [ vid = 0xFE33 ] ( 3635 ) 生产年份, 15 = 2015年
    PID_BYTE_BMU_MONTH								, // [ vid = 0xFE34 ] ( 3636 ) 生产月份 [1~12]
    PID_BYTE_BMU_DAY								, // [ vid = 0xFE35 ] ( 3637 ) 生产日期 [1~31]

    PID_BYTE_RESERVED_54							, // [ vid = 0xFE36 ] ( 3638 )
    PID_BYTE_RESERVED_55							, // [ vid = 0xFE37 ] ( 3639 )
    PID_BYTE_RESERVED_56							, // [ vid = 0xFE38 ] ( 3640 )
    PID_BYTE_RESERVED_57							, // [ vid = 0xFE39 ] ( 3641 )
    PID_BYTE_RESERVED_58							, // [ vid = 0xFE3A ] ( 3642 )
    PID_BYTE_RESERVED_59							, // [ vid = 0xFE3B ] ( 3643 )
    PID_BYTE_RESERVED_60							, // [ vid = 0xFE3C ] ( 3644 )
    PID_BYTE_RESERVED_61							, // [ vid = 0xFE3D ] ( 3645 )
    PID_BYTE_RESERVED_62							, // [ vid = 0xFE3E ] ( 3646 )
    PID_BYTE_RESERVED_63							, // [ vid = 0xFE3F ] ( 3647 )

    PID_BYTE_RESERVED_64							, // [ vid = 0xFE40 ] ( 3648 ) 第二页开始
    PID_BYTE_RESERVED_65							, // [ vid = 0xFE41 ] ( 3649 )
    PID_BYTE_RESERVED_66							, // [ vid = 0xFE42 ] ( 3650 )
    PID_BYTE_RESERVED_67							, // [ vid = 0xFE43 ] ( 3651 )
    PID_BYTE_RESERVED_68							, // [ vid = 0xFE44 ] ( 3652 )

    PID_BYTE_MAX_NUM = 256					// 字节型参数最大个数

};

enum enParabmsPidBsu    //BSU PID参数
{
    PID_BSU_CELL_NUM        ,// ( 256 + BSU No. * 16 ) 采集的电池节数
    PID_BSU_TEMP_NUM        ,// ( 257 + BSU No. * 16 ) 采集的温度路数
    PID_BSU_CHN_CFG1        ,// ( 258 + BSU No. * 16 ) 采集通道配置1
    PID_BSU_CHN_CFG2        ,// ( 259 + BSU No. * 16 ) 采集通道配置2
    PID_BSU_CHN_CFG3        ,// ( 260 + BSU No. * 16 ) 采集通道配置3
    PID_BSU_CHN_CFG4        ,// ( 261 + BSU No. * 16 ) 采集通道配置4
    //	PID_BSU_ADDRESS		,// 地址
    PID_BSU_BTS_TEMP_NUM	,// ( 262 + BSU No. * 16 ) 温度采集盒中使用的温度路数
    PID_BSU_PACK_NO         ,// ( 263 + BSU No. * 16 ) 所在PACK箱号
    PID_BSU_DI_DO_CFG       ,// ( 264 + BSU No. * 16 ) 干接点配置
    PID_BSU_TEMP_CFG1       ,// ( 265 + BSU No. * 16 ) 温度配置1	环境温度
    PID_BSU_TEMP_CFG2       ,//	( 266 + BSU No. * 16 ) 温度配置2	极柱温度
    PID_BSU_BAR_CFG1        ,//	( 267 + BSU No. * 16 ) 铜排电阻配置1
    PID_BSU_BAR_CFG2        ,//	( 268 + BSU No. * 16 ) 保留2
    PID_BSU_BAR_CFG3        ,//	( 269 + BSU No. * 16 ) 保留3
    PID_BSU_BAR_CFG4        ,//	( 270 + BSU No. * 16 ) 保留4
    PID_BSU_RESERVE5        ,//	( 271 + BSU No. * 16 ) 保留5
    PID_BSU_MAX_NUM
};

enum enParabmsPidAlarm      //告警PID参数
{
    PID_ALM_0               ,// ( 768 + ALM No. * 16 )
    PID_ALM_1               ,// ( 769 + ALM No. * 16 )
    PID_ALM_2               ,// ( 770 + ALM No. * 16 )
    PID_ALM_3               ,// ( 771 + ALM No. * 16 )
    PID_ALM_4               ,// ( 772 + ALM No. * 16 )
    PID_ALM_5               ,// ( 773 + ALM No. * 16 )
    PID_ALM_6               ,// ( 774 + ALM No. * 16 )
    PID_ALM_7               ,// ( 775 + ALM No. * 16 )
    PID_ALM_8               ,// ( 776 + ALM No. * 16 )
    PID_ALM_9               ,// ( 777 + ALM No. * 16 )
    PID_ALM_10              ,// ( 778 + ALM No. * 16 )
    PID_ALM_11              ,// ( 779 + ALM No. * 16 )
    PID_ALM_12              ,// ( 780 + ALM No. * 16 )
    PID_ALM_13              ,// ( 781 + ALM No. * 16 )
    PID_ALM_14              ,// ( 782 + ALM No. * 16 )
    PID_ALM_15              ,// ( 783 + ALM No. * 16 )
    PID_ALM_MAX_NUM
};

enum enAlarmPara            //告警参数
{
	ALM_PARA_LEVEL1                                  , // 一级告警点  [ 最严重 ]
	ALM_PARA_LEVEL2                                  , // 二级告警点
	ALM_PARA_LEVEL3                                  , // 三级告警点
	ALM_PARA_LEVEL4                                  , // 四级告警点  [ 最轻微 ]
	ALM_PARA_RELAY1                                  , // 一级告警关联继电器
	ALM_PARA_RELAY2                                  , // 二级告警关联继电器
	ALM_PARA_DELAY                                   , // 继电器动作延时  [ 产生告警后延时切断 ]
	ALM_PARA_FILTER_TIMES                            , // 告警滤波次数  [ 告警确认次数 ]
	ALM_PARA_SYS_LEVEL                               , // 系统级别
	ALM_PARA_DIS_LEVEL                               , // 显示级别
	ALM_PARA_MAX_NUM                                  // 最大告警参数  [ 10 ]
};

enum enAlarmId              //告警ID
{
	ALM_CELL_OV                                      , // 单体过压  [ OVER_VOLT ]
	ALM_CELL_UV                                      , // 单体欠压  [ UNDER_VOLT ]
	ALM_CELL_OT                                      , // 电池高温  [ OVER_TEMP ]
	ALM_CELL_UT                                      , // 电池低温  [ UNDER_TEMP ]
	ALM_CELL_LBK                                     , // 单体电压断线  [ LINE_BREAK ]
	ALM_CELL_TBK                                     , // 单体温度断线  [ TEMP_BREAK ]
	ALM_BATT_DV                                      , // 单体压差过大  [ DIFF_VOLT ]
	ALM_BATT_DT                                      , // 电池温差过大  [ DIFF_TEMP ]
	ALM_BATT_OV                                      , // 整组过压  [ OVER_VOLT ]
	ALM_BATT_UV                                      , // 整组欠压  [ UNDER_VOLT ]
	ALM_BATT_OC                                      , // 电池组SOC过高  [ OVER_SOC ]
	ALM_BATT_UC                                      , // 电池组SOC过低  [ UNDER_SOC ]
	ALM_CHRG_OCS                                     , // 稳态充电过流  [ S=Steady state稳态 ]
	ALM_DSCH_OCS                                     , // 稳态放电过流
	ALM_CHRG_OCT                                     , // 瞬态充电过流  [ T=transient瞬态 ]
	ALM_DSCH_OCT                                     , // 瞬态放电过流
	ALM_BSU_OFFLINE                                  , // BSU离线
	ALM_BSU_FAULT                                    , // BSU故障
	ALM_LEAK_OC                                      , // 漏电流超限
	ALM_PRECHRG_FAIL                                 , // 预充失败
	ALM_AUX_FAIL                                     , // 主继电器辅助触点失败
	ALM_BMU_FAIL                                     , // BMU内部错误
	ALM_VCU_OFFLINE                                  , // VCU通信错误
	ALM_HVREL_FAIL                                   , // 电池高压异常
	ALM_HALL_BREAK                                   , // 霍尔断线
	ALM_RESERVED25                                   , // 预留告警
	ALM_RESERVED26                                   , // 预留告警
	ALM_RESERVED27                                   , // 预留告警
	ALM_RESERVED28                                   , // 预留告警
	ALM_RESERVED29                                   , // 预留告警
	ALM_RESERVED30                                   , // 预留告警
	ALM_RESERVED31                                   , // 预留告警
	ALM_MAX_NUM                                       // 最大告警数量  [ 25 ]
};

enum enParabmsPidBat    //电池包PID参数
{
    PID_BAT_SOC			,// ( 1280 + BAT No. * 16 ) 电池组的SOC
    PID_BAT_SOH			,// ( 1281 + BAT No. * 16 ) 电池组的SOH
    PID_BAT_CHRG_SOC	,//	( 1282 + BAT No. * 16 ) 电池组累计充电SOC
    PID_BAT_DSCH_SOC	,//	( 1283 + BAT No. * 16 ) 电池组累计放电SOC
    PID_BAT_CYCLE_TIMES	,//	( 1284 + BAT No. * 16 ) 电池组循环次数
    PID_BAT_HALL_ZERO	,// ( 1285 + BAT No. * 16 ) 每组电池需要一个霍尔零点，单位0.1A
    PID_BAT_RESERVE1	,//	( 1286 + BAT No. * 16 ) 保留1
    PID_BAT_RESERVE2	,//	( 1287 + BAT No. * 16 ) 保留2
    PID_BAT_RESERVE3	,//	( 1288 + BAT No. * 16 ) 保留3
    PID_BAT_RESERVE4	,//	( 1289 + BAT No. * 16 ) 保留4
    PID_BAT_RESERVE5	,//	( 1290 + BAT No. * 16 ) 保留5
    PID_BAT_RESERVE6	,//	( 1291 + BAT No. * 16 ) 保留6
    PID_BAT_RESERVE7	,//	( 1292 + BAT No. * 16 ) 保留7
    PID_BAT_RESERVE8	,//	( 1293 + BAT No. * 16 ) 保留8
    PID_BAT_RESERVE9	,//	( 1294 + BAT No. * 16 ) 保留9
    PID_BAT_RESERVE10	,//	( 1295 + BAT No. * 16 ) 保留10
    PID_BAT_MAX_NUM	//
};

enum enBSU02Bid
{
	BID_BSU02_VOLT1					, // 单体电压1
	BID_BSU02_VOLT2					, // 单体电压2
	BID_BSU02_VOLT3					, // 单体电压3
	BID_BSU02_VOLT4					, // 单体电压4
	BID_BSU02_VOLT5					, // 单体电压5
	BID_BSU02_VOLT6					, // 单体电压6
	BID_BSU02_VOLT7					, // 单体电压7
	BID_BSU02_VOLT8					, // 单体电压8
	BID_BSU02_VOLT9					, // 单体电压9
	BID_BSU02_VOLT10				, // 单体电压10
	BID_BSU02_VOLT11				, // 单体电压11
	BID_BSU02_VOLT12				, // 单体电压12
    BID_BSU02_VOLT13				, // 单体电压1
    BID_BSU02_VOLT14				, // 单体电压2
    BID_BSU02_VOLT15				, // 单体电压3
    BID_BSU02_VOLT16				, // 单体电压4
    BID_BSU02_VOLT17				, // 单体电压5
    BID_BSU02_VOLT18				, // 单体电压6
    BID_BSU02_VOLT19				, // 单体电压7
    BID_BSU02_VOLT20				, // 单体电压8
    BID_BSU02_VOLT21				, // 单体电压9
	BID_BSU02_VOLT22				, // 单体电压10
	BID_BSU02_VOLT23				, // 单体电压11
	BID_BSU02_VOLT24				, // 单体电压12
    BID_BSU02_VOLT25				, // 单体电压1
    BID_BSU02_VOLT26				, // 单体电压2
    BID_BSU02_VOLT27				, // 单体电压3
    BID_BSU02_VOLT28				, // 单体电压4
    BID_BSU02_VOLT29				, // 单体电压5
    BID_BSU02_VOLT30				, // 单体电压6

	BID_BSU02_VOLT31				, // 单体电压11
	BID_BSU02_VOLT32				, // 单体电压12
    BID_BSU02_VOLT33				, // 单体电压1
    BID_BSU02_VOLT34				, // 单体电压2
    BID_BSU02_VOLT35				, // 单体电压3
    BID_BSU02_VOLT36				, // 单体电压4
    BID_BSU02_VOLT37				, // 单体电压5
    BID_BSU02_VOLT38				, // 单体电压6
    BID_BSU02_VOLT39				, // 单体电压7
    BID_BSU02_VOLT40				, // 单体电压8
    BID_BSU02_VOLT41				, // 单体电压9
	BID_BSU02_VOLT42				, // 单体电压10
	BID_BSU02_VOLT43				, // 单体电压11
	BID_BSU02_VOLT44				, // 单体电压12
    BID_BSU02_VOLT45				, // 单体电压1
    BID_BSU02_VOLT46				, // 单体电压2
    BID_BSU02_VOLT47				, // 单体电压3
    BID_BSU02_VOLT48				, // 单体电压4
    BID_BSU02_VOLT49				, // 单体电压4
	BID_BSU02_VOLT50				, // 单体电压10
	BID_BSU02_VOLT51				, // 单体电压11
	BID_BSU02_VOLT52				, // 单体电压12
    BID_BSU02_VOLT53				, // 单体电压1
    BID_BSU02_VOLT54				, // 单体电压2
    BID_BSU02_VOLT55				, // 单体电压3
    BID_BSU02_VOLT56				, // 单体电压4
    BID_BSU02_VOLT57				, // 单体电压5
    BID_BSU02_VOLT58				, // 单体电压6
    BID_BSU02_VOLT59				, // 单体电压7
    BID_BSU02_VOLT60				, // 单体电压8
    BID_BSU02_VOLT61				, // 单体电压9
	BID_BSU02_VOLT62				, // 单体电压10
	BID_BSU02_VOLT63				, // 单体电压11
	BID_BSU02_VOLT64				, // 单体电压12

	BID_BSU02_LEAK_VOLT				, // 漏电流电压值
	BID_BSU02_HALL_VOLT				, // 电流电压值
	BID_BSU02_BAL_NO				, // 均衡号
	BID_BSU02_BAL_CURR				, // 均衡电流
	BID_BSU02_TEMP1					, // 单体温度1
	BID_BSU02_TEMP2					, // 单体温度2
	BID_BSU02_TEMP3					, // 单体温度3
	BID_BSU02_TEMP4					, // 单体温度1
	BID_BSU02_TEMP5					, // 单体温度2
	BID_BSU02_TEMP6					, // 单体温度2
	BID_BSU02_TEMP7					, // 单体温度3
	BID_BSU02_TEMP8					, // 单体温度1
	BID_BSU02_TEMP9					, // 单体温度2
    BID_BSU02_TEMP10				, // 单体温度3
    BID_BSU02_TEMP11				, // 单体温度1
    BID_BSU02_TEMP12				, // 单体温度2
    BID_BSU02_TEMP13				, // 单体温度3
    BID_BSU02_TEMP14				, // 单体温度1
    BID_BSU02_TEMP15				, // 单体温度2
    BID_BSU02_TEMP16				, // 单体温度1
    BID_BSU02_TEMP17				, // 单体温度2
    BID_BSU02_TEMP18				, // 单体温度3
    BID_BSU02_TEMP19				, // 单体温度1
    BID_BSU02_TEMP20				, // 单体温度2
	BID_BSU02_STATE					, // 状态
	BID_BSU02_SWVER					, // 软件版本号
	BID_BSU02_COUNT					, // 软件版本号
	BID_BSU02_VOLT1_COE				, // 校准系数1
	BID_BSU02_VOLT2_COE				, // 校准系数2
	BID_BSU02_VOLT3_COE				, // 校准系数3
	BID_BSU02_VOLT4_COE				, // 校准系数4
	BID_BSU02_VOLT5_COE				, // 校准系数5
	BID_BSU02_VOLT6_COE				, // 校准系数6
	BID_BSU02_VOLT7_COE				, // 校准系数7
	BID_BSU02_VOLT8_COE				, // 校准系数8
	BID_BSU02_VOLT9_COE				, // 校准系数9
	BID_BSU02_VOLT10_COE			, // 校准系数10
	BID_BSU02_VOLT11_COE			, // 校准系数11
	BID_BSU02_VOLT12_COE			, // 校准系数12
	BID_BSU02_LEAK_ZERO				, // 漏电流零点
	BID_BSU02_HALL_ZERO				, // 电流零点
	BID_BSU02_SECOND				, // 秒数计数
	BID_BSU02_AH1					, // 每秒积分
	BID_BSU02_AH2					, // 每秒积分
	BID_BSU02_MAX_NUM
};

enum enBTSBid
{
    BID_BTS_TEMP1               , // 温度1
    BID_BTS_TEMP2               , // 温度2
    BID_BTS_TEMP3               , // 温度3
    BID_BTS_TEMP4               , // 温度4
    BID_BTS_TEMP5               , // 温度5
    BID_BTS_TEMP6               , // 温度6
    BID_BTS_TEMP7               , // 温度7
    BID_BTS_TEMP8               , // 温度8
    BID_BTS_TEMP9               , // 温度9
    BID_BTS_TEMP10				, // 温度10
    BID_BTS_TEMP11				, // 温度11
    BID_BTS_TEMP12				, // 温度12
    BID_BTS_TEMP13				, // 温度13
    BID_BTS_TEMP14				, // 温度14
    BID_BTS_TEMP15				, // 温度15
    BID_BTS_TEMP16				, // 温度16
    BID_BTS_TEMP17				, // 温度17
    BID_BTS_TEMP18				, // 温度18
    BID_BTS_TEMP19				, // 温度19
    BID_BTS_TEMP20				, // 温度20
    BID_BTS_TEMP21				, // 温度21
    BID_BTS_TEMP22				, // 温度22
    BID_BTS_TEMP23				, // 温度23
    BID_BTS_TEMP24				, // 温度24
    BID_BTS_TEMP25				, // 温度25
    BID_BTS_TEMP26				, // 温度26
    BID_BTS_TEMP27				, // 温度27
    BID_BTS_TEMP28				, // 温度28
    BID_BTS_TEMP29				, // 温度29
    BID_BTS_TEMP30				, // 温度30
    BID_BTS_TEMP31				, // 温度31
    BID_BTS_TEMP32				, // 温度32
    BID_BTS_TEMP33				, // 温度33
    BID_BTS_TEMP34				, // 温度34
    BID_BTS_TEMP35				, // 温度35
    BID_BTS_TEMP36				, // 温度36
    BID_BTS_TEMP37				, // 温度37
    BID_BTS_TEMP38				, // 温度38
    BID_BTS_TEMP39				, // 温度39
    BID_BTS_TEMP40				, // 温度40

    BID_BTS_INSIDE_TEMP         , // 内部温度
    BID_BTS_BEAT                , // 心跳值

    BID_BTS_DEV_TYPE            , // 设备类型
    BID_BTS_SOFT_VER            , // 软件版本
    BID_BTS_PRO_VER             , // 协议版本

    BID_BTS_MAX_NUM
};

#define BID_BSU_START		0
#define BID_BSU_SIZE		BID_BSU02_MAX_NUM
#define BID_MAKE_BSU_BID(nBsu, bid)	\
    (BID_BSU_START + BID_BSU02_MAX_NUM * (nBsu) + (bid))

enum enCurrentTree      //当前树图选项
{
	DW_BMU_TREESTART,
	DW_BMU_PID_ALM	,
	DW_ALM_ACTIVE,
	DW_ALM_HISTORY, 
	DW_BMU_PID_SYS,
	DW_BMU_VID_SYS,
	DW_BSU_PID,
	DW_BSU_VID_BSU,
	DW_BSU_VID_CELL,
    DW_BAT,
    DW_BTS
};

enum enCurrentPage      //当前页
{
 DW_BMU_BAT_TOTAL,
 DW_BMU_PAGESTART,
 DW_BAT_VID,
 DW_BAT_PID,
 DW_BMU_ADVANCE,
 DW_BMU_CHARGE,
 DW_BMU_MODULE,
 DW_BMU_RATED	,
 DW_BMU_SYS	,
 DW_BMU_TEST,
 DW_BMU_CALIB,
 DW_BMU_RUN,
 DW_BMU_BSU_SET,
 DW_BMU_MAINTAIN,
 DW_BMU_PAGENUM
};

////////////////////Operate///////操作记录
enum enOperateLog
{
	OL_LOGIN,
	OL_CAN_OPEN,
	OL_CAN_RESERT,
	OL_CAN_CLOSE,
	OL_LOG_NUM
};

////////////////Alarm
// 最大告警级别
#define MAX_ALARM_LEVEL		4

// 告警名称最大长度
#define ALM_NAME_STR_LEN			12
#define ALM_FULL_NAME_STR_LEN		17

#define ALM_TIME_STRING_LEN			(sizeof("2012-01-23 12:34:56") - 1)

// 最大当前告警数量
#define MAX_ACTV_ALM_NUM			50

// 最大历史告警数量
#define MAX_HIST_ALM_NUM			60

// 历史告警保存在EEPROM的位置
#define EEP_HIST_ALM_FLAG_POS		6
#define EEP_HIST_ALM_FLAG_VAL		0x55AA

// 长度只需要一个字节
#define EEP_POS_HIST_ALM_NUM		8
#define EEP_POS_HIST_ALM_TAIL		9

#define EEP_POS_HIST_ALM_START		0x3000


// 告警代码

/************************************************************************/
// 定义如下：
//		aaaaaaaa vvvv tttt pppppppp pppppppp
//	其中：
//		a	8位，表示告警类型，最多可表示256种不同的告警
//		v	4位，表示告警值（告警级别）
//		t	4位，表示设备类型，0-Sys, 1-Bat, 2-Cell, 3-BSU
//		p	16位，表示设备位置：参见ST_BSU_CELL_POSITION
//
//////////////////////////////////////////////////////////////////////////
//	系统类	aaaaaaaa vvvv 0000 0000 0000 00000000 
//	电池类  aaaaaaaa vvvv 0001 batt bsubsu cccccc
//	单体类	aaaaaaaa vvvv 0010 batt bsubsu cccccc
//	BSU类	aaaaaaaa vvvv 0011 batt bsubsu cccccc
/************************************************************************/
typedef UINT32 ALARM_CODE;

enum enAlarmEquipType           //告警配置类型
{
	AET_SYS,
	AET_BAT,
	AET_BSU,
	AET_CELL,
	AET_BREAK,
};

typedef struct stAlarmCode      //告警代码结构体
{
	// 结构体定义中，前面是低位，后面是高位（小端模式）
	UINT16 uiEquipPosi;
	UINT16 uiEquipType	: 4;
	UINT16 uiAlarmLevel	: 4;
	UINT16 uiAlarmId	: 8;
}ST_ALARM_CODE;

typedef union unAlarmCode       //告警代码内联体
{
	ST_ALARM_CODE stBit;
	UINT32 uiAll;
}UN_ALARM_CODE;

// 告警时间

#define ALARM_TIME_YEAR_FROM	2000    //开始时间2000年

typedef struct stAlarmTime  //告警时间结构体
{
	UINT16 Year		: 6;	// 从2000年开始算，可表示2000~2064年
	UINT16 Month	: 4;	// 1-12月
	UINT16 Day		: 5;	// 1-31
	UINT16 Hour		: 5;	// 0-23
	UINT16 Min		: 6;	// 0-59
	UINT16 Sec		: 6;	// 0-59
}ST_ALARM_TIME;


// 当前告警
typedef struct stActiveAlarm_t
{
	ALARM_CODE	uiAlarmCode;
	ST_ALARM_TIME stStartTime;			/*告警出现的时间*/
}ST_ACTV_ALARM;

// 历史告警
typedef struct stHistAlarm_t
{
	ALARM_CODE	uiAlarmCode;
	ST_ALARM_TIME stStartTime;			/*告警出现的时间*/
	ST_ALARM_TIME stEndTime;			/*告警结束的时间*/
}ST_HIST_ALARM;


// 当前告警记录
typedef struct stActvAlmRecord
{
	ST_ACTV_ALARM stAlm;
    UINT16 uiPrev;          //上一个
    UINT16 uiNext;          //下一个
}ST_ACTV_ALM_RECORD;

// 所有当前告警
typedef struct stAllActvAlm
{
	// 第0个元素用于链表头结点
	ST_ACTV_ALM_RECORD astAlarms[MAX_ACTV_ALM_NUM + 1];

	UINT16 uiFree;
	UINT16 uiNum;
}ST_ALL_ACTV_ALM;

// 所有历史告警
typedef struct stAllHistAlm
{
	ST_HIST_ALARM astAlarms[MAX_HIST_ALM_NUM];
	UINT16 uiNum;		// 总共有多少条
	UINT16 uiTail;		// 最后一条的位置，即最新的一条

}ST_ALL_HIST_ALM;


typedef struct stAlarmData
{
	UINT16 uiLevel		: 4;
	UINT16 uiTimes		: 8;
	UINT16 uiOldLevel	: 4;
}ST_ALARM_DATA;


// 告警配置

typedef enum enAlarmMode
{
	OVER_TEST,
	UNDER_TEST,
	DIFF_TEST,
	BOOL_TEST

}EN_ALARM_MODE;

enum enParaType     //参数类型
{
    PARA_NORMAL,    //普通参数
    PARA_X10,       //10倍参数
};

typedef struct stAlarmConfig    //告警配置结构体
{
    UINT16 vid1;			//要判断的信号VID
    UINT16 vid2;            //告警标准VID

	UINT8 uiAlmId;			//告警ID
	UINT8 uiAlmMode;		//告警方式

	UINT8 uiParaType;

}ST_ALARM_CONFIG;

#define	SYS_ALARM_NUM			8		/*系统相关的告警数量*/
#define	BAT_ALARM_NUM			14		/*电池组相关的告警数量*/
#define	CELL_ALARM_NUM			4		/*单体电池相关的告警数量*/
#define	BREAK_ALARM_NUM			2
#define	BSU_ALARM_NUM			2		/*采集模块相关的告警数量*/

// !!告警名称字符数最多为 ALM_NAME_STR_LEN(12)!!

/////////////////Alarm

/*======================================================================*/
// 数据类型定义
/*======================================================================*/

//typedef struct stBytes
//{
//#if CPU_ENDIAN == BIG_ENDIAN
//	UINT8 uiHiByte;
//	UINT8 uiLoByte;
//#else
//	UINT8 uiLoByte;
//	UINT8 uiHiByte;
//#endif
//}ST_BYTES;


typedef union unDbData
{
	/*unDbData()
	{
	uiData = 0xFFFF;
	}*/
	INT16 siData;
	UINT16 uiData;
	//ST_BYTES stBytes;
}UN_DB_DATA;

typedef UN_DB_DATA UNIONINT;
typedef UN_DB_DATA DB_VALUE_T;

/************************************************************************/
//
// CELL位置信息
//
/************************************************************************/

typedef struct stBsuCellPosition_t
{
	UINT16 uiCellNo		: 6;	// 单体在BSU中的序号：0~63
	UINT16 uiBsuNo		: 6;	// 单体所在箱号：0~BSU_MAX_NUM-1
	UINT16 uiBatNo		: 4;	// 单体所在电池组的编号: 0~BAT_MAX_NUM-1
}ST_BSU_CELL_POSITION;

typedef union unBsuCellPosition_t
{
	ST_BSU_CELL_POSITION stBit;
	UINT16 uiAll;
}UN_BSU_CELL_POSITION;


/************************************************************************/
//
// CELL状态信息
//
/************************************************************************/

typedef struct stBsuCellStatus_t
{
	UINT16 uiVbkCount		: 6;	// 电压断线计数
	UINT16 uiVoltBreak		: 1;	// 电压断线
	UINT16 uiVbkChange		: 1;	// 电压断线状态变化

	UINT16 uiTbkCount		: 6;	// 温度断线计数
	UINT16 uiTempBreak		: 1;	// 温度断线
	UINT16 uiTbkChange		: 1;	// 温度断线状态变化
}ST_BSU_CELL_STATUS;

typedef union unBsuCellStatus_t
{
	ST_BSU_CELL_STATUS stBit;
	UINT16 uiAll;
}UN_BSU_CELL_STATUS;

//*****************BSU数据****************
typedef struct stBsu02Data
{
	DB_VALUE_T aatBsu02Data[BID_BSU02_MAX_NUM];
}ST_BSU02_DATA;

typedef struct stBsu02AllData
{
	ST_BSU02_DATA aatBsu02AllData[BMS_BSU_NUMBER];
}ST_BSU02_ALL_DATA;

typedef union unBsu02Data
{
	DB_VALUE_T atArrayData[BMS_BSU_NUMBER * BID_BSU02_MAX_NUM];
	ST_BSU02_ALL_DATA stStructData;
}UN_BSU02_DATA;
//*****************BSU数据****************

//*****************BTS数据****************
typedef struct stBtsData
{
    DB_VALUE_T aatBtsData[BID_BTS_MAX_NUM];
}ST_BTS_DATA;

typedef struct stBtsAllData
{
    ST_BTS_DATA aatBtsAllData[BMS_BTS_NUMBER];
}ST_BTS_ALL_DATA;

typedef union unBtsData
{
    DB_VALUE_T atArrayData[BMS_BTS_NUMBER * BID_BTS_MAX_NUM];
    ST_BTS_ALL_DATA stStructData;
}UN_BTS_DATA;
//*****************BTS数据****************

typedef struct stCanJ1939Packet
{
	UINT32 uiFrameId;
	UINT32 auiVidCfg[8];
	BOOL bNetworkOrder;		// 网络字节序，即大端模式，先传高字节
	UINT16 uiSendPeriod;	// 发送周期，单位ms
}ST_CAN_J1939_PACKET;

struct tagSystemTime
{
    _US m_usYear;
    _US m_usMonth;
    _US m_usDay;
    _US m_usHour;
    _US m_usMinute;
    _US m_usSecond;
    _US m_usMsec;
};

typedef struct stControlString 
{
	int idDB;
	QLineEdit* idLineEdit;
}ST_CONTROL_STRING;

typedef struct stControlStringEx 
{
	int idDB;
	QLineEdit* idLineEdit;
	int idFormat;
	int idType;
	int idUnit;
}ST_CONTROL_STRING_EX;

struct tagCanUnitRealData    //发送或者接受的详细帧信息
{
	UINT32 m_uBMUId ;         //帧ID
	BYTE m_BData[8];     //8个字节数据
	int m_bSendOrRece;   //是发送帧还是接收帧  true是发送帧，false是接收帧
};

struct tagCanBMSVidSys
{
	tagCanBMSVidSys()
	{
		for (int i = 0 ; i < VID_SYS_MAX_NUM ; i++)
		{
			m_usBmsVidSys[i] = 0;
		}
	}

    void re_tagCanBMSVidSys()
    {
        for (int i = 0 ; i < VID_SYS_MAX_NUM ; i++)
        {
            m_usBmsVidSys[i] = 0;
        }
    }

	_US  m_usBmsVidSys[VID_SYS_MAX_NUM];                //值
};

struct tagCanBMSVidBsuCell
{
	tagCanBMSVidBsuCell()
	{
		for (int i = 0 ; i < VID_BSU_CELL_MAX_NUM ; i++)
		{
			m_usBmsVidBsuCell[i] = 0;
		}
	}

    void re_tagCanBMSVidBsuCell()
    {
        for (int i = 0 ; i < VID_BSU_CELL_MAX_NUM ; i++)
        {
            m_usBmsVidBsuCell[i] = 0;
        }
    }

	_US  m_usBmsVidBsuCell[VID_BSU_CELL_MAX_NUM];                //值
};

struct tagCanBMSVidBsu
{
	tagCanBMSVidBsu()
	{
		for (int i = 0 ; i < VID_BSU_HEAD_MAX_NUM ; i++)
		{
			m_usBmsVidBsu[i] = 0;
		}
	}

    void re_tagCanBMSVidBsu()
    {
        for (int i = 0 ; i < VID_BSU_HEAD_MAX_NUM ; i++)
        {
            m_usBmsVidBsu[i] = 0;
        }
    }

	_US  m_usBmsVidBsu[VID_BSU_HEAD_MAX_NUM];                //值
	tagCanBMSVidBsuCell  m_tagBmsVidBsuCell[VID_BSU_CELL_NUM];
};

struct tagCanBMSVidBat
{
	tagCanBMSVidBat()
	{
		for (int i = 0 ; i < BAT_CELL_NUM ; i++)
		{
			if (i<VID_BAT_MAX_NUM)
			{
				m_usBmsVidBat[i] = 0;
			}
			m_usBmsVidBatCell[i] = 0;
		}
	}
	_US  m_usBmsVidBat[VID_BAT_MAX_NUM];                //值
	_US m_usBmsVidBatCell[BAT_CELL_NUM];
};

struct tagCanBMSVidVcu
{
	tagCanBMSVidVcu()
	{
		for (int i = 0 ; i < VID_VCU_MAX_NUM ; i++)
		{
			m_usBmsVidVcu[i] = 0;
		}
	}
	_US  m_usBmsVidVcu[VID_VCU_MAX_NUM];                //值
};

struct tagCanBMSVidChr
{
	tagCanBMSVidChr()
	{
		for (int i = 0 ; i < VID_CHR_MAX_NUM ; i++)
		{
			m_usBmsVidChr[i] = 0;
		}
	}
	_US  m_usBmsVidChr[VID_CHR_MAX_NUM];                //值
};

struct tagCanBMSPidSys
{
	tagCanBMSPidSys()
	{
		for (int i = 0 ; i < PID_SYS_MAX_NUM ; i++)
		{
			m_usBmsPidSys[i] = 0;
		}
	}
	_US  m_usBmsPidSys[PID_SYS_MAX_NUM];                //值
};

struct tagCanBMSPidBsu
{
	tagCanBMSPidBsu()
	{
		for (int j = 0 ;  j < BMS_BSU_NUMBER ; j++)
		{		
			for (int i = 0 ; i < PID_BSU_MAX_NUM ; i++)
			{
                if ((i >= 2 && i <= 5) || (i >= 9 && i <= 10))
                {
                    m_usBmsPidBsu[j][i] = 0xFFFF;//电压和温度配置通道需初始化为0xFFFF
                }
                else
                {
                    m_usBmsPidBsu[j][i] = 0;
                }
			}
		}
	}    
	_US  m_usBmsPidBsu[BMS_BSU_NUMBER][PID_BSU_MAX_NUM];                //值
};

struct tagCanBMSPidAlarm
{
	tagCanBMSPidAlarm()
	{
		for (int j = 0 ;  j < ALM_MAX_NUM ; j++)
		{		
			for (int i = 0 ; i < ALM_PARA_MAX_NUM ; i++)
			{
				m_usBmsPidAlarm[j][i] = 0;
			}
		}
	}
	_US  m_usBmsPidAlarm[ALM_MAX_NUM][ALM_PARA_MAX_NUM];                //值
};

struct tagCanBMSPidBat
{
	tagCanBMSPidBat()
	{
		for (int j = 0 ;  j < BMS_BAT_NUMBER ; j++)
		{		
			for (int i = 0 ; i < PID_BAT_MAX_NUM ; i++)
			{
				m_usBmsPidBat[j][i] = 0;
			}
		}
	}
	_US  m_usBmsPidBat[BMS_BAT_NUMBER][PID_BAT_MAX_NUM];                //值
};

struct tagCanBMSVid
{
	tagCanBMSVidSys  m_tagBmsVidSys;
	tagCanBMSVidBsu  m_tagBmsVidBsu[VID_BSU_NUM];	
    tagCanBMSVidBat  m_tagBmsVidBat[BAT_MAX_NUM];
    tagCanBMSVidVcu  m_tagBmsVidVcu;
    tagCanBMSVidChr  m_tagBmsVidChr;
};

struct tagCanBMSPid
{
	tagCanBMSPidSys  m_tagBmsPidSys;
	tagCanBMSPidBsu  m_tagBmsPidBsu;
	tagCanBMSPidAlarm  m_tagBmsPidAlarm;
	tagCanBMSPidBat  m_tagBmsPidBat;
};

struct tagCanBMS
{
	tagCanBMS()
	{
		m_bisBMUConnect = false;
		m_iCommunite = 0;
		for (int i = 0 ; i < PID_BYTE_MAX_NUM ; i ++)
		{
			m_abyBytePara[i] = 0;
		}
		for (int k = 0 ; k < BMS_BSU_NUMBER * BID_BSU02_MAX_NUM ; k++)
		{
			m_unBSU02Data.atArrayData[k].uiData = 0;
		}
        for (int l = 0 ; l < BMS_BTS_NUMBER * BID_BTS_MAX_NUM ; l++)
        {
            m_unBTSData.atArrayData[l].uiData = 0;
        }
	}
    int m_iCommunite;               //记录通讯出错次数，5次表示通讯断
    bool m_bisBMUConnect;           //记录通讯连接状态
	tagCanBMSVid m_tagBmsVid;
	tagCanBMSPid m_tagBmsPid;
	UN_BSU02_DATA m_unBSU02Data;
    UN_BTS_DATA m_unBTSData;
	BYTE m_abyBytePara[PID_BYTE_MAX_NUM];

    //本地计算最高最低电压和温度
    int m_nMaxCell, m_nMinCell, m_nMaxTemp, m_nMinTemp;
    int m_nCellDiff, m_nTempDiff;
    UN_BSU_CELL_POSITION m_unMaxVPosi;
    UN_BSU_CELL_POSITION m_unMinVPosi;
    UN_BSU_CELL_POSITION m_unMaxTPosi;
    UN_BSU_CELL_POSITION m_unMinTPosi;

    //VID
    _US get_usBmsVidSys(int vid_sys_para)//获取系统vid参数
    {
        return m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[vid_sys_para];
    }

    void set_usBmsVidSys(_US BmsVidSys, int vid_sys_para)//设置系统vid参数
    {
        m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[vid_sys_para] = BmsVidSys;
    }

    _US get_usBmsVidBsuHead(int vid_bsu_num, int vid_bsu_head_para)//获取从控基础vid参数
    {
        return m_tagBmsVid.m_tagBmsVidBsu[vid_bsu_num].m_usBmsVidBsu[vid_bsu_head_para];
    }

    void set_usBmsVidBsuHead(_US BmsVidBsuHead, int vid_bsu_num, int vid_bsu_head_para)//设置从控基础vid参数
    {
        m_tagBmsVid.m_tagBmsVidBsu[vid_bsu_num].m_usBmsVidBsu[vid_bsu_head_para] = BmsVidBsuHead;
    }

    _US get_usBmsVidBsuCell(int vid_bsu_num, int vid_bsu_cell_num, int vid_bsu_cell_para)//获取从控单体vid参数
    {
        return m_tagBmsVid.m_tagBmsVidBsu[vid_bsu_num].m_tagBmsVidBsuCell[vid_bsu_cell_num].m_usBmsVidBsuCell[vid_bsu_cell_para];
    }

    void set_usBmsVidBsuCell(_US BmsVidBsuCell, int vid_bsu_num, int vid_bsu_cell_num, int vid_bsu_cell_para)//设置从控单体vid参数
    {
        m_tagBmsVid.m_tagBmsVidBsu[vid_bsu_num].m_tagBmsVidBsuCell[vid_bsu_cell_num].m_usBmsVidBsuCell[vid_bsu_cell_para] = BmsVidBsuCell;
    }

    _US get_usBmsVidBat(int bat_num, int vid_bat_para)//获取电池组vid参数
    {
        return m_tagBmsVid.m_tagBmsVidBat[bat_num].m_usBmsVidBat[vid_bat_para];
    }

    void set_usBmsVidBat(_US BmsVidBat, int bat_num, int vid_bat_para)//设置电池组vid参数
    {
        m_tagBmsVid.m_tagBmsVidBat[bat_num].m_usBmsVidBat[vid_bat_para] = BmsVidBat;
    }

    _US get_usBmsVidBatCell(int bat_num, int bat_cell_num)//获取电池组单体
    {
        return m_tagBmsVid.m_tagBmsVidBat[bat_num].m_usBmsVidBatCell[bat_cell_num];
    }

    void set_usBmsVidBatCell(_US BmsVidBatCell, int bat_num, int bat_cell_num)//设置电池组单体
    {
        m_tagBmsVid.m_tagBmsVidBat[bat_num].m_usBmsVidBatCell[bat_cell_num] = BmsVidBatCell;
    }

    _US get_usBmsVidVcu(int vid_vcu_para)//获取整车控制器vid参数
    {
        return m_tagBmsVid.m_tagBmsVidVcu.m_usBmsVidVcu[vid_vcu_para];
    }

    void set_usBmsVidVcu(_US BmsVidVcu, int vid_vcu_para)//设置整车控制器vid参数
    {
        m_tagBmsVid.m_tagBmsVidVcu.m_usBmsVidVcu[vid_vcu_para] = BmsVidVcu;
    }

    _US get_usBmsVidChr(int vid_chr_para)//获取字符型vid参数
    {
        return m_tagBmsVid.m_tagBmsVidChr.m_usBmsVidChr[vid_chr_para];
    }

    void set_usBmsVidChr(_US BmsVidChr, int vid_chr_para)//设置字符型vid参数
    {
        m_tagBmsVid.m_tagBmsVidChr.m_usBmsVidChr[vid_chr_para] = BmsVidChr;
    }

    //PID
    _US get_usBmsPidSys(int pid_sys_para)//获取系统pid参数
    {
        return m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[pid_sys_para];
    }

    void set_usBmsPidSys(_US BmsPidSys, int pid_sys_para)//设置系统pid参数
    {
        m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[pid_sys_para] = BmsPidSys;
    }

    _US get_usBmsPidBsu(int bsu_num, int pid_bsu_para)//获取从控pid参数
    {
        return m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[bsu_num][pid_bsu_para];
    }

    void set_usBmsPidBsu(_US BmsPidBsu, int bsu_num, int pid_bsu_para)//设置从控pid参数
    {
        m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[bsu_num][pid_bsu_para] = BmsPidBsu;
    }

    _US get_usBmsPidAlarm(int alm_num, int pid_alm_para)//获取告警pid参数
    {
        return m_tagBmsPid.m_tagBmsPidAlarm.m_usBmsPidAlarm[alm_num][pid_alm_para];
    }

    void set_usBmsPidAlarm(_US BmsPidAlarm, int alm_num, int pid_alm_para)//设置告警pid参数
    {
        m_tagBmsPid.m_tagBmsPidAlarm.m_usBmsPidAlarm[alm_num][pid_alm_para] = BmsPidAlarm;
    }

    _US get_usBmsPidBat(int bat_num, int pid_bat_para)//获取电池组pid参数
    {
        return m_tagBmsPid.m_tagBmsPidBat.m_usBmsPidBat[bat_num][pid_bat_para];
    }

    void set_usBmsPidBat(_US BmsPidBat, int bat_num, int pid_bat_para)//设置电池组pid参数
    {
        m_tagBmsPid.m_tagBmsPidBat.m_usBmsPidBat[bat_num][pid_bat_para] = BmsPidBat;
    }

    //BSU02
    DB_VALUE_T get_atArrayData(int bid)//获取bsu02所以参数数组数据
    {
        return m_unBSU02Data.atArrayData[bid];
    }

    void set_atArrayData(DB_VALUE_T ArrayData, int bid)//设置bsu02所以参数数组数据
    {
        m_unBSU02Data.atArrayData[bid] = ArrayData;
    }

    DB_VALUE_T get_stBsu02Data(int bsu_num, int bid_bsu02_para)////获取bsu02的bid参数
    {
        return m_unBSU02Data.stStructData.aatBsu02AllData[bsu_num].aatBsu02Data[bid_bsu02_para];
    }

    void set_stBsu02Data(DB_VALUE_T Bsu02Data, int bsu_num, int bid_bsu02_para)////获取bsu02的bid参数
    {
        m_unBSU02Data.stStructData.aatBsu02AllData[bsu_num].aatBsu02Data[bid_bsu02_para] = Bsu02Data;
    }
};

struct tagCanSend
{
	tagCanSend()
	{
		m_SendNum = 0;
	}
	stCanFrame m_stCanFrame;
	int m_SendNum;                 //发送几次，为-1表示循环一直发	
};



extern stControlStringEx g_stParabmsVidSys[VID_SYS_MAX_NUM];
extern QString GetLocalTime(tagSystemTime *st);
extern QString GetstrTime();
extern QString TakeOutReturn(QString str);
extern QString GetWorkPath(void);
extern QString GetFileName(QString strExp);
extern bool GetDataBit(_US usData, _US usPos);   //计算usData的第usPos位是0还是1
extern float StrToF(QString str);
extern int HexStrToI(QString str);
extern QString FloatToStr(enParameterDisplayFormat disFormat, float fData, int iNumOfZero);
extern bool FindFile(QString path);
extern void AutoRemoveFaultFiles(void);
extern void AutoRemoveRunParaFiles(void);
#endif // PUBLIC_H
