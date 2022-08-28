#ifndef PUBLIC_H
#define PUBLIC_H

//�汾��V1.0

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

//#define USE_LOCAL_FONT      //�����Ƿ�ʹ�ñ������ԣ�΢���źڣ�


#ifdef USE_LOCAL_FONT
extern bool _USE_LOCAL_FONT;      //�����Ƿ�ʹ�ñ������ԣ�΢���źڣ�
//���ر�������
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

//#define QString_C(txt)  QString::fromLocal8Bit(txt)     //������ʾ����ֹ����
#define QString_C(txt)  QStringLiteral(txt)     //������ʾ����ֹ����
//#define QString_C(txt)  QObject::tr(txt)     //������ʾ����ֹ����

#define BAT_MAX_NUM			6
#define BMS_BSU_NUMBER      32      //32��BSU
#define BMS_BTS_NUMBER      25      //25��BTS
#define BMS_ALARM_TYPE      32      //32��澯
#define BMS_BAT_NUMBER      16      //16����
#define BSU_MAX_NUM			32
#define CELL_MAX_NUM		300
#define BSU_CELL_NUM		64
#define BAT_CELL_NUM		300
#define	BSU_TEMP_NUM		64

// ����ҳ����
#define J1939_DP0			0x00000000			//��0ҳ
#define J1939_DP1			0x01000000			//��1ҳ

// ���ȼ�����
#define J1939_PRIOR7		0x1C000000			//������ȼ�
#define J1939_PRIOR6		0x18000000			//��6�����ȼ�
#define J1939_PRIOR5		0x14000000			//��5�����ȼ�
#define J1939_PRIOR4		0x10000000			//��4�����ȼ�
#define J1939_PRIOR3		0x0C000000			//��3���ȼ�
#define J1939_PRIOR2		0x08000000			//��2�����ȼ�
#define J1939_PRIOR1		0x04000000			//��1�����ȼ�
#define J1939_PRIOR0		0x00000000			//������ȼ�

#define J1939_PRIOR_MASK	0x1C000000

// �����ֶ�
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
	ӳ���ϵ����
*/
#define PT_ONE_BYTE		0x00010000		//ÿ��VID��Ӧһ���ֽ�
#define PT_TWO_BYTE		0x00020000		//ÿ��VID��Ӧ�����ֽ�
#define PT_BYTE_MASK	0x00030000

#define PT_SAVE_ON_SET	0x00040000		//������ʱ��Ҫ���浽EEPROM

#define PT_NO_NARROW	0x00000000		/*������*/
#define PT_NARROW10		0x01000000		/*��С10��*/
#define PT_NARROW20		0x02000000		/*��С20��*/
#define PT_NARROW100	0x03000000		/*��С100��*/
#define	PT_NARROW32		0x04000000		/*��С32��*/
//#define	PT_NARROW3P2	0x06000000		/*��С3.2��*/
#define	PT_NARROW4		0x07000000		/*��С4��*/
#define PT_NARROW2		0x05000000		/*��С2��*/
#define PT_ENLARG2		0x08000000		/*�Ŵ�2��*/
#define PT_ENLARG10		0x09000000		/*�Ŵ�10��*/
#define PT_ENLARG20		0x0A000000		/*�Ŵ�20��*/
//#define	PT_ENLARG2P5	0x0A000000		/*�Ŵ�2.5��*/
#define PT_NARROW_MASK	0x0F000000

#define PT_NO_OFFSET	0x00000000		/*��ƫ��*/
#define PT_OFFSET40		0x10000000		/*�������40*/
#define PT_OFFSET400	0x20000000		/*�������400*/
#define PT_OFFSET800	0x30000000		/*�������400*/
#define PT_OFFSET1600	0x40000000		/*�������1600*/
#define PT_OFFSET16K	0x50000000		/*�������16000*/
#define PT_OFFSET5K		0x60000000		/*�������5000*/
#define PT_OFFSET_MASK	0xF0000000

// �����ֽڣ�CAN����������̶��ֽ�
#define PT_SEND_NN_FLAG			0xFFFEFF
#define PT_RESERVED_NN(HexByte)	(0xFFFEFF00 | (HexByte))

// �����ֽڣ�CAN����������0
#define PT_RESERVED_00	0xFFFFFFF0
// �����ֽڣ�CAN����������FF
#define PT_RESERVED_FF	0xFFFFFFF1
// ����֡�в����ĵ��ֽ�
#define PT_IGNORE		0xFFFFFFF2
// ����
#define PT_VID_END		0xFFFFFFFF

// ��CANͨ���У�PID����һ��ƫ��������VID��PID������һ��
// С�ڴ�ֵ��ΪVID�����ڵ��ڴ�ֵ��ΪPID
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
// PID��ַ����
//
/************************************************************************/
#define PID_SYS_START				0
#define PID_SYS_SIZE				256

#define PID_BSU_START				(PID_SYS_START + PID_SYS_SIZE)			// 256
#define PID_BSU_SIZE				16
#define PID_BSU_NUM					32
#define PID_BSU_TOTAL_SIZE			(PID_BSU_SIZE * PID_BSU_NUM)			// 512��

#define PID_ALM_START				(PID_BSU_START + PID_BSU_TOTAL_SIZE)	// 768
#define PID_ALM_SIZE				16
#define PID_ALM_NUM					32
#define PID_ALM_TOTAL_SIZE			(PID_ALM_SIZE * PID_ALM_NUM)			// 512��

#define PID_BAT_START				(PID_ALM_START + PID_ALM_TOTAL_SIZE)	// 1280
#define PID_BAT_SIZE				16
#define PID_BAT_NUM					16
#define PID_BAT_TOTAL_SIZE			(PID_BAT_SIZE * PID_BAT_NUM)			// 256��

#define PID_TOTAL_SIZE				(PID_SYS_SIZE + PID_BSU_TOTAL_SIZE \
	+ PID_ALM_TOTAL_SIZE + PID_BAT_TOTAL_SIZE)	// 1.5K

#define PID_CAL_START				0x0D00//У׼����ƫ����

#define PID_BYTE_START				0x0E00//�ַ�����ƫ����

enum enParameterDisplayFormat           //������ʾ��ʽ
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

enum enDispItemSIdType                  //��ʾ��ĿSID����
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

enum enItemDispFormat                   //��Ŀ��ʾ��ʽ
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

enum enItemDispUint                     //��Ŀ��ʾ��λ
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

enum enParabmsVidSys                    //bms VIDϵͳ����
{
    VID_SYS_NOT_USED                    , // [ vid = 00000 ] ��������
    VID_SYS_HW_VER                      , // [ vid = 00001 ] CPU��Ӳ���汾
    VID_SYS_BASE_BOARD_VER              , // [ vid = 00002 ] �װ�Ӳ���汾  [ 0=�޵װ� ]
    VID_SYS_SW_VER                      , // [ vid = 00003 ] ����汾
    VID_SYS_LIB_VER                     , // [ vid = 00004 ] ������汾
    VID_SYS_DISP_VER                    , // [ vid = 00005 ] ��ʾ�汾
    VID_SYS_SW_SUB_VER                  , // [ vid = 00006 ] �����汾(Ԥ��)
    VID_SYS_TM_YEAR                     , // [ vid = 00007 ] ϵͳʱ�䣺��
    VID_SYS_TM_MONTH                    , // [ vid = 00008 ] ��
    VID_SYS_TM_DAY                      , // [ vid = 00009 ] ��
    VID_SYS_TM_HOUR                     , // [ vid = 00010 ] ʱ
    VID_SYS_TM_MIN                      , // [ vid = 00011 ] ��
    VID_SYS_TM_SEC                      , // [ vid = 00012 ] ��
    VID_SYS_XX                          , // [ vid = 00013 ]
    VID_SYS_YY                          , // [ vid = 00014 ]
    VID_SYS_ZZ                          , // [ vid = 00015 ]
    VID_SYS_XYZ                         , // [ vid = 00016 ]
    VID_SYS_MAX_PERIOD                  , // [ vid = 00017 ] ��ѭ�������  [ mS ]
    VID_SYS_LAST_ERR_NO                 , // [ vid = 00018 ] ��������  [ BMU���������� ]
    VID_SYS_WORK_MODE                   , // [ vid = 00019 ] ϵͳ����ģʽ  [ 0=����������1=��װģʽ ]
    VID_SYS_ACC_STATUS                  , // [ vid = 00020 ] ACC�ź�����״̬
    VID_SYS_TO_SUICIDE                  , // [ vid = 00021 ] ϵͳ׼����ɱʽ�ϵ�
    VID_SYS_VOLT                        , // [ vid = 00022 ] ϵͳ�ۺϵ�ѹ
    VID_SYS_CURR                        , // [ vid = 00023 ] ϵͳ�ۺϵ���
    VID_SYS_TEMP                        , // [ vid = 00024 ] ϵͳ�ۺ��¶�
    VID_SYS_SOC                         , // [ vid = 00025 ] ϵͳ�ۺ�SOC
    VID_SYS_BOOT_VER                    , // [ vid = 00026 ] BOOT�汾
    VID_SYS_RESERVED2                   , // [ vid = 00027 ] Ԥ��2
    VID_SYS_RESERVED3                   , // [ vid = 00028 ] Ԥ��3
    VID_SYS_RESERVED4                   , // [ vid = 00029 ] Ԥ��4
    VID_SYS_ACTV_ALM_NUM                , // [ vid = 00030 ] ��澯����
    VID_SYS_HIST_ALM_NUM                , // [ vid = 00031 ] ��ʷ�澯����
    VID_SYS_ALM_L1_NUM                  , // [ vid = 00032 ] һ����澯����
    VID_SYS_ALM_L2_NUM                  , // [ vid = 00033 ] ������澯����
    VID_SYS_ALM_L3_NUM                  , // [ vid = 00034 ] ������澯����
    VID_SYS_ALM_L4_NUM                  , // [ vid = 00035 ] �ļ���澯����
    VID_SYS_RUN_STATUS                  , // [ vid = 00036 ] ϵͳ����״̬
    VID_SYS_DI1_STATUS                  , // [ vid = 00037 ] DI����״̬  [ 0=�Ͽ���1=�պ� ]
    VID_SYS_DI2_STATUS                  , // [ vid = 00038 ]
    VID_SYS_DI3_STATUS                  , // [ vid = 00039 ]
    VID_SYS_DI4_STATUS                  , // [ vid = 00040 ]
    VID_SYS_DI5_STATUS                  , // [ vid = 00041 ]
    VID_SYS_DI6_STATUS                  , // [ vid = 00042 ]
    VID_SYS_DI7_STATUS                  , // [ vid = 00043 ]
    VID_SYS_DI8_STATUS                  , // [ vid = 00044 ]
    VID_SYS_RELAY1_STATUS               , // [ vid = 00045 ] �̵������״̬  [ 0=�Ͽ���1=�պ� ]
    VID_SYS_RELAY2_STATUS               , // [ vid = 00046 ]
    VID_SYS_RELAY3_STATUS               , // [ vid = 00047 ]
    VID_SYS_RELAY4_STATUS               , // [ vid = 00048 ]
    VID_SYS_RELAY5_STATUS               , // [ vid = 00049 ]
    VID_SYS_RELAY6_STATUS               , // [ vid = 00050 ]
    VID_SYS_RELAY7_STATUS               , // [ vid = 00051 ]
    VID_SYS_RELAY8_STATUS               , // [ vid = 00052 ] ���ȿ���״̬
    VID_SYS_RELAY1_REASON               , // [ vid = 00053 ] �̵����Ͽ�ԭ��  [ 0=�պϣ�1=�澯������������ԭ�� ]
    VID_SYS_RELAY2_REASON               , // [ vid = 00054 ]
    VID_SYS_RELAY3_REASON               , // [ vid = 00055 ]
    VID_SYS_RELAY4_REASON               , // [ vid = 00056 ]
    VID_SYS_RELAY5_REASON               , // [ vid = 00057 ]
    VID_SYS_RELAY6_REASON               , // [ vid = 00058 ]
    VID_SYS_RELAY7_REASON               , // [ vid = 00059 ]
    VID_SYS_RELAY8_REASON               , // [ vid = 00060 ]
    VID_SYS_AD_CODE1                    , // [ vid = 00061 ] ADͨ����ֵ: ��Ե�ɼ���
    VID_SYS_AD_CODE2                    , // [ vid = 00062 ] Ԥ���ѹ
    VID_SYS_AD_CODE3                    , // [ vid = 00063 ] ���ĸ���ܵ�ѹ
    VID_SYS_AD_CODE4                    , // [ vid = 00064 ] ��ĸ�ߵ�ѹ
    VID_SYS_AD_CODE5                    , // [ vid = 00065 ] ĸ���ܵ�ѹ2
    VID_SYS_AD_CODE6                    , // [ vid = 00066 ] ��ĸ�ߵ�ѹ2
    VID_SYS_AD_CODE7                    , // [ vid = 00067 ] ��������
    VID_SYS_AD_CODE8                    , // [ vid = 00068 ] ����������
    VID_SYS_BUS_VOLT                    , // [ vid = 00069 ] ���ĸ���ܵ�ѹ  [ 0.1V ]
    VID_SYS_PBUS_VOLT                   , // [ vid = 00070 ] ��ĸ�ߵ�ѹ  [ 0.1V ]
    VID_SYS_NBUS_VOLT                   , // [ vid = 00071 ] ��ĸ�ߵ�ѹ  [ 0.1V ]
    VID_SYS_PBUS_RES                    , // [ vid = 00072 ] ��ĸ�ߵ���  [ 0.1K�� ]
    VID_SYS_NBUS_RES                    , // [ vid = 00073 ] ��ĸ�ߵ���  [ 0.1K�� ]
    VID_SYS_LEAK_CURR                   , // [ vid = 00074 ] ϵͳ©����  [ 0.1mA ]
    VID_SYS_PRE_BUS_VOLT                , // [ vid = 00075 ] Ԥ���ѹ  [ 0.1V ]
    VID_SYS_CURR1_VOLT                  , // [ vid = 00076 ] ����ͨ��1�ĵ�ѹ  [ mV ]
    VID_SYS_CURR2_VOLT                  , // [ vid = 00077 ] ����ͨ��2�ĵ�ѹ  [ mV ]
    VID_SYS_CURR1                       , // [ vid = 00078 ] ����ͨ��1�ĵ���  [ 0.1A ]
    VID_SYS_CURR2                       , // [ vid = 00079 ] ����ͨ��2�ĵ���  [ 0.1A ]
    VID_SYS_POWER_VOLT                  , // [ vid = 00080 ] ������Դ��ѹ  [ 0.1V ]
    VID_SYS_BOARD_TEMP                  , // [ vid = 00081 ] �����¶�  [ 0.1�� ]
    VID_SYS_OUT_TEMP                    , // [ vid = 00082 ] �ⲿ�¶ȴ������¶� [ 0.1�� ]
    VID_SYS_LEM_VOLT2                   , // [ vid = 00083 ] LEMͨ��2��ѹ
    VID_SYS_LEM_CURR                    , // [ vid = 00084 ] LEM������ĵ���  [ 0.1A ]
    VID_SYS_LEM_CODE                    , // [ vid = 00085 ] LEMͨ����ֵ
    VID_SYS_ONLINE_BSU_NUM              , // [ vid = 00086 ] ����BSU����
    VID_SYS_RATED_VOLT                  , // [ vid = 00087 ] ��ض��ѹ  [ V ]
    VID_SYS_LIFE                        , // [ vid = 00088 ] ������Ϣ
    VID_SYS_SUPER                       , // [ vid = 00089 ] ������������
    VID_SYS_PRECHARGE_FAIL              , // [ vid = 00090 ] Ԥ��ʧ��״̬  [ 0=������1=ʧ�� ]
    VID_SYS_MAX_VOLT                    , // [ vid = 00091 ] ��ߵ�ѹֵ  [ mV ]
    VID_SYS_MAXV_POSI                   , // [ vid = 00092 ] ��ߵ�ѹλ��
    VID_SYS_MIN_VOLT                    , // [ vid = 00093 ] ��͵�ѹֵ  [ mV ]
    VID_SYS_MINV_POSI                   , // [ vid = 00094 ] ��͵�ѹλ��
    VID_SYS_MAX_TEMP                    , // [ vid = 00095 ] ����¶�ֵ  [ 0.1�� ]
    VID_SYS_MAXT_POSI                   , // [ vid = 00096 ] ����¶�λ��
    VID_SYS_MIN_TEMP                    , // [ vid = 00097 ] ����¶�ֵ  [ 0.1�� ]
    VID_SYS_MINT_POSI                   , // [ vid = 00098 ] ����¶�λ��
    VID_JYM_STATUS                      , // [ vid = 00099 ] ��Եģ������״̬
    VID_JYM_OFFLINE                     , // [ vid = 00100 ] ��Եģ������״̬  [ 0=���ߣ�1=���� ]
    VID_JYM_OPEN_BAT_VOLT               , // [ vid = 00101 ] ���ŶϿ�ʱ����ܵ�ѹ  [ 0.1V ]
    VID_JYM_OPEN_NBUS_VOLT              , // [ vid = 00102 ] ���ŶϿ�ʱ��ĸ�ߵ�ѹ  [ 0.1V ]
    VID_JYM_CLOSE_UP_NBUS_VOLT          , // [ vid = 00103 ] ���űպ�ʱ��ĸ�ߵ�ѹ  [ 0.1V ]
    VID_JYM_CLOSE_DN_NBUS_VOLT          , // [ vid = 00104 ] ���űպ�ʱ��ĸ�ߵ�ѹ  [ 0.1V ]
    VID_SYS_NBUS_VOLT_FINAL             , // [ vid = 00105 ] ���������������ʵʱ��ĸ�ߵ�ѹ  [ 0.1V ]
    VID_SYS_BUS_VOLT1                   , // [ vid = 00106 ] �����ѹ1
    VID_SYS_SLW_BUS_VOLT                , // [ vid = 00107 ] �����ѹ  [ 0.1V ]
    VID_SYS_NBUS_VOLT1                  , // [ vid = 00108 ] ��ĸ�ߵ�ѹ1
    VID_SYS_FST_BUS_VOLT                , // [ vid = 00109 ] ����ѹ  [ 0.1V ]
    VID_GPRS_CONTROL                    , // [ vid = 00110 ] GPRS����
    VID_GPRS_RUN_STATUS                 , // [ vid = 00111 ] GPRS����״̬
    VID_GPRS_SIG_STRENGTH               , // [ vid = 00112 ] GPRS�ź�ǿ��
    VID_GPRS_CONNECT_STEP               , // [ vid = 00113 ] GPRS���Ӳ���
    VID_GPRS_ONLINE_TIME                , // [ vid = 00114 ] GPRS����ʱ��  [ Min ]
    VID_GPRS_SEND_NUM                   , // [ vid = 00115 ] GPRS�������ݰ���Ŀ
    VID_GPRS_RECV_OK_NUM                , // [ vid = 00116 ] GPRS���յ�OK����Ŀ
    VID_GPRS_FLOW_COUNT_HI              , // [ vid = 00117 ] GPRS�������ֽ�
    VID_GPRS_FLOW_COUNT_LO              , // [ vid = 00118 ] GPRS�������ֽ�
    VID_GPRS_IMEI1                      , // [ vid = 00119 ] GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI2                      , // [ vid = 00120 ] GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI3                      , // [ vid = 00121 ] GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI4                      , // [ vid = 00122 ] GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI5                      , // [ vid = 00123 ] GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI6                      , // [ vid = 00124 ] GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI7                      , // [ vid = 00125 ] GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI8                      , // [ vid = 00126 ] GPRSģ��IMEI�ַ���
    VID_GPRS_CCID1                      , // [ vid = 00127 ] SIM��CCID�ַ���
    VID_GPRS_CCID2                      , // [ vid = 00128 ] SIM��CCID�ַ���
    VID_GPRS_CCID3                      , // [ vid = 00129 ] SIM��CCID�ַ���
    VID_GPRS_CCID4                      , // [ vid = 00130 ] SIM��CCID�ַ���
    VID_GPRS_CCID5                      , // [ vid = 00131 ] SIM��CCID�ַ���
    VID_GPRS_CCID6                      , // [ vid = 00132 ] SIM��CCID�ַ���
    VID_GPRS_CCID7                      , // [ vid = 00133 ] SIM��CCID�ַ���
    VID_GPRS_CCID8                      , // [ vid = 00134 ] SIM��CCID�ַ���
    VID_GPRS_CCID9                      , // [ vid = 00135 ] SIM��CCID�ַ���
    VID_GPRS_CCID10                     , // [ vid = 00136 ] SIM��CCID�ַ���
    VID_GPRS_RESERVED1                  , // [ vid = 00137 ] ����1
    VID_GPRS_ENABLE                     , // [ vid = 00138 ] GPRS ʹ�ܿ���
    VID_GPRS_ERR_COUNT                  , // [ vid = 00139 ] GPRS �������
    VID_GPRS_RESERVED4                  , // [ vid = 00140 ] ����4
    VID_SYS_ALLOW_DSCH_CURR             , // [ vid = 00141 ] �������ŵ����  [ 0.1A ]
    VID_SYS_ALLOW_CHRG_CURR             , // [ vid = 00142 ] ������������  [ 0.1A ]
    VID_SYS_BAT_STATE                   , // [ vid = 00143 ] ϵͳ״̬  [ 4���ȼ� ]
    VID_SYS_BAT_FAULT1                  , // [ vid = 00144 ] ϵͳ���ϴ���1
    VID_SYS_BAT_FAULT2                  , // [ vid = 00145 ] ϵͳ���ϴ���2
    VID_SYS_BAT_FAULT3                  , // [ vid = 00146 ] ϵͳ���ϴ���3
    VID_SYS_BAT_FAULT4                  , // [ vid = 00147 ] ϵͳ���ϴ���4
    VID_SYS_FAULT                       , // [ vid = 00148 ] �Ӵ������ϴ���
    VID_SYS_HVREL_CMD                   , // [ vid = 00149 ] ��ѹ�̵�����������
    VID_SYS_USER_SET_SOC                , // [ vid = 00150 ] �û��ֶ�����SOC��ֵ
    VID_SYS_DEBUG_VAR1                  , // [ vid = 00151 ] ���Ա���1
    VID_SYS_DEBUG_VAR2                  , // [ vid = 00152 ] ���Ա���2
    VID_SYS_DEBUG_VAR3                  , // [ vid = 00153 ] ���Ա���3
    VID_SYS_DEBUG_VAR4                  , // [ vid = 00154 ] ���Ա���4
    VID_SYS_DEBUG_VAR5                  , // [ vid = 00155 ] ���Ա���5
    VID_SYS_DEBUG_VAR6                  , // [ vid = 00156 ] ���Ա���6
    VID_SYS_DEBUG_VAR7                  , // [ vid = 00157 ] ���Ա���7
    VID_SYS_DEBUG_VAR8                  , // [ vid = 00158 ] ���Ա���8
    VID_SYS_ALLOW_DSCH_POWER            , // [ vid = 00159 ] �������ŵ繦��  [ 0.1kW ]
    VID_SYS_ALLOW_CHRG_POWER            , // [ vid = 00160 ] ��������繦��  [ 0.1kW ]
    VID_SYS_CMD                         , // [ vid = 00161 ] ��������
    VID_SYS_SUPER_GPRS                  , // [ vid = 00162 ] GPRS��������
    VID_SYS_RELAY_PRE                   , // [ vid = 00163 ] Ԥ��̵�������  [ 0���� ��������Ӧ�̵����� ]
    VID_SYS_RELAY_MAIN                  , // [ vid = 00164 ] ���̵�������  [ 0���� ��������Ӧ�̵����� ]
    VID_SYS_RELAY_CHA                   , // [ vid = 00165 ] ���̵�������(����)  [ 0���� ��������Ӧ�̵����� ]
    VID_SYS_RELAY_NEGA                  , // [ vid = 00166 ] �ܸ��̵�������  [ 0���� ��������Ӧ�̵����� ]
    VID_SYS_RELAY_OUT                   , // [ vid = 00167 ] �ⲿ�̵�������  [ 0���� ��������Ӧ�̵����� ]
    VID_SYS_RELAY_HOT                   , // [ vid = 00168 ] BMU���ȼ̵�������  [ 0���� ��������Ӧ�̵����� ]
    VID_SYS_RELAY_BSU                   , // [ vid = 00169 ] BSU��Դ�̵�������  [ 0���� ��������Ӧ�̵����� ]
    VID_SYS_RELAY_BMU                   , // [ vid = 00170 ] BMU���߼̵�������  [ 0���� ��������Ӧ�̵����� ]
    VID_SYS_RELAY_AUX_FAIL              , // [ vid = 00171 ] �����������״̬  [ 0=������1=���� ]
    VID_SYS_MAX_TEMP_SHADOW             , // [ vid = 00172 ] ����¶�ֵ-Ӱ��  [ 0.1�� ]
    VID_SYS_MAXT_POSI_SHADOW            , // [ vid = 00173 ] ����¶�λ��-Ӱ��
    VID_SYS_MIN_TEMP_SHADOW             , // [ vid = 00174 ] ����¶�ֵ-Ӱ��  [ 0.1�� ]
    VID_SYS_MINT_POSI_SHADOW            , // [ vid = 00175 ] ����¶�λ��-Ӱ��
    VID_SYS_MAX_VOLT_SHADOW             , // [ vid = 00176 ] ��ߵ�ѹֵ-Ӱ��  [ mV ]
    VID_SYS_MAXV_POSI_SHADOW            , // [ vid = 00177 ] ��ߵ�ѹλ��-Ӱ��
    VID_SYS_MIN_VOLT_SHADOW             , // [ vid = 00178 ] ��͵�ѹֵ-Ӱ��  [ mV ]
    VID_SYS_MINV_POSI_SHADOW            , // [ vid = 00179 ] ��͵�ѹλ��-Ӱ��
    VID_SYS_RUN_PERIOD                  , // [ vid = 00180 ] ��Ȧ����  [ mS ]
    VID_SYS_CAN_SELF_TEST_RESULT        , // [ vid = 00181 ] CAN�Բ��Խ��  [ 0-δ��ʼ��1-������2+���� ]
    VID_SYS_USB_STATE                   , // [ vid = 00182 ] USB״̬  [ 0���� ]
    VID_SYS_OUT_TEMP2_CODE              , // [ vid = 00183 ] �ⲿ�¶�2��������ֵ
    VID_SYS_OUT_TEMP2_VOLT              , // [ vid = 00184 ] �ⲿ�¶�2�����ĵ�ѹ [ mV ]
    VID_SYS_OUT_TEMP2                   , // [ vid = 00185 ] �ⲿ�¶�2�������¶� [ 0.1�� ]
    VID_SYS_CP_AMPLITUDE                , // [ vid = 00186 ] CP�����ֵ [ 0.1V ]
    VID_SYS_CP_PWM_FREQ                 , // [ vid = 00187 ] CP����PWMƵ��  [ Hz ]
    VID_SYS_CP_PWM_DUTY_RATIO           , // [ vid = 00188 ] CP����PWMռ�ձ�  [ 0.1% ]
    VID_SYS_RELAY_FAN                   , // [ vid = 00189 ] BMU���Ʒ��ȼ̵�������  [ 0���� ��������Ӧ�̵����� ]
    VID_SYS_VCU_MAIN_RELAY_CMD          , // [ vid = 00190 ] VCU����BMS�������̵���������  [ 0���պ� 1���Ͽ� ]
    VID_SYS_BSU_RELAY_STATUS            , // [ vid = 00191 ] BSU��Դ�̵���״̬  [ 0���պ� 1���Ͽ� ]
    VID_SYS_LOW_VOLT_STATUS             , // [ vid = 00192 ] ������ѹ̫�� [ 0=����, 1=������ѹ̫�� ]
    VID_SYS_RESERVED26                  , // [ vid = 00193 ] Ԥ��26
    VID_SYS_VCU_COMM_FAIL               , // [ vid = 00194 ] VCUͨ�ų�ʱ
    VID_SYS_HVREL_FAIL                  , // [ vid = 00195 ] BMU��ѹ����
    VID_SYS_MAXV_NO                     , // [ vid = 00196 ] ��ߵ�ѹ�������
    VID_SYS_MINV_NO                     , // [ vid = 00197 ] ��͵�ѹ�������
    VID_SYS_MAXT_NO                     , // [ vid = 00198 ] ����¶ȵ������
    VID_SYS_MINT_NO                     , // [ vid = 00199 ] ����¶ȵ������
    VID_SYS_MINUS_CURR                  , // [ vid = 00200 ] �����������Ϊ�����ŵ�Ϊ����
    VID_SYS_AUX_FAIL_VID                , // [ vid = 00201 ] ����
    VID_SYS_MAIN_POS_OPEN               , // [ vid = 00202 ] �����̵�����·
    VID_SYS_MAIN_POS_SHORT              , // [ vid = 00203 ] �����̵���ճ��
    VID_SYS_MAIN_NEG_OPEN               , // [ vid = 00204 ] �ܸ��̵�����·
    VID_SYS_MAIN_NEG_SHORT              , // [ vid = 00205 ] �ܸ��̵���ճ��

    VID_SYS_DSW1_VOLT                   , // [ vid = 00206 ] DSW1��ѹ
    VID_SYS_DSW2_VOLT                   , // [ vid = 00207 ]
    VID_SYS_DSW3_VOLT                   , // [ vid = 00208 ]
    VID_SYS_DSW4_VOLT                   , // [ vid = 00209 ]

    VID_SYS_CC_VOLT                     , // [ vid = 00210 ] ���CC��ѹ
    VID_SYS_CC2_VOLT                    , // [ vid = 00211 ] ���CC2��ѹ
    VID_SYS_CP_VOLT                     , // [ vid = 00212 ] ���CP��ѹ
    VID_SYS_HALL_BREAK                  , // [ vid = 00213 ] ��������״̬

    VID_SYS_PWR_CODE                    , // [ vid = 00214 ]
    VID_SYS_CC_CODE                     , // [ vid = 00215 ]
    VID_SYS_CC2_CODE                    , // [ vid = 00216 ]
    VID_SYS_CP_CODE                     , // [ vid = 00217 ]
    VID_SYS_CC_RESISTANCE               , // [ vid = 00218 ] CC�ĵ��� [ �� ]
    VID_SYS_CC2_RESISTANCE              , // [ vid = 00219 ] CC2�ĵ��� [ �� ]
    VID_SYS_BAL_ACTIVE_MODE             , // [ vid = 00220 ] �������⹤��ģʽ ����ֹ���ŵ磬��磩
    VID_SYS_BAL_ACTIVE_DISH_NUM         , // [ vid = 00221 ] ��������ŵ�ģ����
    VID_SYS_BAL_ACTIVE_CHRG_NUM         , // [ vid = 00222 ] ����������ģ����
    VID_SYS_READY_TO_CUT                , // [ vid = 00223 ] ȡ��
    VID_SYS_PARA_FLAG                   , // [ vid = 00224 ] ������־ [ 1=FLASH, 2=EEPROM, 3=���ð汾��ƥ�䣬4=Ĭ�ϲ��������ã�5=EEPROM�� ]
    VID_SYS_ORIGINAL_CURR               , // [ vid = 00225 ] ԭʼ������δ����ĵ�����	[ 0.1A ]
    VID_SYS_FAST_CURR                   , // [ vid = 00226 ] ���ٵ��������˲��� [ 0.1A ]
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

    VID_SYS_GZ_TEST_1							,	// ��װ����ר��VID1
    VID_SYS_GZ_TEST_2							,	// ��װ����ר��VID2

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

    VID_SYS_MAX_NUM  =  0xFFF                     // [ vid = 00336 ] �����豸VID����  [ 256 + 80  ]

};

enum enParabmsVidBsu                            //BSU VID����     ��ʼ0x1000
{
    VID_BSU_ADDR                                 , // [ vid = 04096 ] ��BSU�ĵ�ַ
    VID_BSU_POSI                                 , // [ vid = 04097 ] BSUλ����Ϣ
    VID_BSU_SW_VER                               , // [ vid = 04098 ] BSU����汾��
    VID_BSU_RUN_STATUS                           , // [ vid = 04099 ] BSU����״̬
    VID_BSU_OFFLINE_STATUS                       , // [ vid = 04100 ] BSU����״̬  [ 0=���ߣ�1=���� ]
    VID_BSU_TOTAL_VOLT                           , // [ vid = 04101 ] ����CELL���ܵ�ѹ  [ 10mV ]
    VID_BSU_CURR                                 , // [ vid = 04102 ] BSU�ɼ�����  [ 0.1A ]
    VID_BSU_START_CELL_INDEX                     , // [ vid = 04103 ] ��һ�������ڵ�����е����
    VID_BSU_BAL_CMD                              , // [ vid = 04104 ] ��������������ر�
    VID_BSU_BAL_NO_SET                           , // [ vid = 04105 ] ���õľ������
    VID_BSU_BAL_CURR_SET                         , // [ vid = 04106 ] ���õľ������  [ 0.1A ]
    VID_BSU_CHN1_VOLT                            , // [ vid = 04107 ] ����ͨ��1�ĵ�ѹ  [ mV ]
    VID_BSU_CHN2_VOLT                            , // [ vid = 04108 ] ����ͨ��2�ĵ�ѹ  [ mV ]
    VID_BSU_BAL1_NO                              , // [ vid = 04109 ] ��1·ʵ�ʾ������
    VID_BSU_BAL1_CURR                            , // [ vid = 04110 ] ��1·ʵ�ʾ������  [ 0.1A ]
    VID_BSU_BAL2_NO                              , // [ vid = 04111 ] ��2·ʵ�ʾ������
    VID_BSU_BAL2_CURR                            , // [ vid = 04112 ] ��2·ʵ�ʾ������  [ 0.1A ]
    VID_BSU_FAN_CMD                              , // [ vid = 04113 ] ��������  [ 0=�رգ�1=���� ]
    VID_BSU_HOT_CMD                              , // [ vid = 04114 ] ��������  [ 0=�رգ�1=���� ]
    VID_BSU_FAN_STATUS                           , // [ vid = 04115 ] ����״̬  [ 0=�رգ�1=���� ]
    VID_BSU_HOT_STATUS                           , // [ vid = 04116 ] ����״̬  [ 0=�رգ�1=���� ]
    VID_BSU_BAL_FAIL                             , // [ vid = 04117 ] �������
    VID_BSU_DI1_STATUS                           , // [ vid = 04118 ] �ɽӵ�����1״̬
    VID_BSU_DI2_STATUS                           , // [ vid = 04119 ] �ɽӵ�����2״̬
    VID_BSU_BTS_DI1_STATUS                       , // [ vid = 04120 ] BTS��SW1״̬  [ 0=�������źţ�1=�������ź� ]
    VID_BSU_BTS_DI2_STATUS                       , // [ vid = 04121 ] BTS��SW2״̬  [ 0=�������źţ�1=�������ź� ]
    VID_BSU_HEAD_MAX_NUM                           // [ vid = 04122 ] �����豸VID����  [ 26 ]
};

enum enParabmsVidBsuCell                        //BSU ���VID����   ��ʼ0x1100
{
    VID_BSU_CELL_POSI                            , // [ vid = 04352 ] λ����Ϣ  [ �������ڵ�ء�BSU����Ϣ ]
    VID_BSU_CELL_UNIQUE_NO                       , // [ vid = 04353 ] ������������е����  [ ��1��ʼ ]
    VID_BSU_CELL_VOLT                            , // [ vid = 04354 ] �����ѹ  [ mV ]
    VID_BSU_CELL_TEMP                            , // [ vid = 04355 ] �����¶�  [ 0.1�� ]
    VID_BSU_CELL_BAL_CURR                        , // [ vid = 04356 ] �������  [ mA ]
    VID_BSU_CELL_BAL_CAPA                        , // [ vid = 04357 ] ��������  [ 0.1AH ]
    VID_BSU_CELL_CMD                             , // [ vid = 04358 ] �������
    VID_BSU_CELL_STATUS                          , // [ vid = 04359 ] ״̬(����)
    VID_BSU_CELL_BAR_R                           , // [ vid = 04360 ] ͭ�ŵ���  [ 10u�� ]
    VID_BSU_CELL_VOLT_ORG                        , // [ vid = 04361 ] �����ѹ(BSUԭʼֵ)  [ mV ]
    VID_BSU_CELL_TEMP_BSU                        , // [ vid = 04362 ] BSU�ϱ��¶�  [ 0.1�� ]
    VID_BSU_CELL_MAX_NUM                           // [ vid = 04363 ] �����豸VID����  [ 11 ]
};

enum enParabmsVidBat                            //��ذ�VID����  ��ʼ0xB000
{
    VID_BAT_TOTAL_VOLT                           , // [ vid = 45056 ] ����ܵ�ѹ  [ 0.1V ]
    VID_BAT_CURR                                 , // [ vid = 45057 ] ��ص���  [ 0.1A ]
    VID_BAT_SOC                                  , // [ vid = 45058 ] SOC  [ .001 ]
    VID_BAT_SOH                                  , // [ vid = 45059 ] SOH
    VID_BAT_CELL_NUM                             , // [ vid = 45060 ] ��Ч��ش���
    VID_BAT_AVG_VOLT                             , // [ vid = 45061 ] ƽ����ѹ  [ mV ]
    VID_BAT_TEMP_NUM                             , // [ vid = 45062 ] ��Ч�¶ȸ���
    VID_BAT_AVG_TEMP                             , // [ vid = 45063 ] ƽ���¶�  [ �� ]
    VID_BAT_TOTAL_CHRG_SOC                       , // [ vid = 45064 ] �ܳ������
    VID_BAT_TOTAL_DSCH_SOC                       , // [ vid = 45065 ] �ܷŵ�����
    VID_BAT_CYCLE_TIMES                          , // [ vid = 45066 ] ѭ������
    VID_BAT_SOC_RUNTIME                          , // [ vid = 45067 ] ���й�����δ����������SOC
    VID_BAT_SOC_BEFORE                           , // [ vid = 45068 ] ���س��ǰSOC
    VID_BAT_USER_SET_SOC                         , // [ vid = 45069 ] �û��ֶ�����SOC
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
    VID_BAT_PRE_STATE                            , // [ vid = 45194 ] Ԥ��״̬  [ 0����ʼ����1����ʼԤ�䣬2��Ԥ���У�3��������4��Ԥ����ɣ�5Ԥ��ʧ�� ]
    VID_BAT_PRE_COUNTER                          , // [ vid = 45195 ] Ԥ��ʱ��  [ ʵ��ʱ���� * 150ms ]
    VID_BAT_PRE_FILTER                           , // [ vid = 45196 ] Ԥ���˲�����
    VID_BAT_PRE_ENABLE                           , // [ vid = 45197 ] Ԥ��ʹ��  [ 0����ֹԤ�䣬1��Ԥ����Ч ]
    VID_BAT_RATED_VOLT                           , // [ vid = 45198 ] �������ѹ  [ 0.1V ]
    VID_BAT_RATED_POWER                          , // [ vid = 45199 ] ���������  [ 0.1kW ]
    VID_BAT_RESERVED7                            , // [ vid = 45200 ] Ԥ��
    VID_BAT_RESERVED8                            , // [ vid = 45201 ] Ԥ��
    VID_BAT_RESERVED9                            , // [ vid = 45202 ] Ԥ��
    VID_BAT_RESERVED10                           , // [ vid = 45203 ] Ԥ��
    VID_BAT_MAX_NUM                                // [ vid = 45204 ] �����豸VID����  [ 148 ]
};

enum enParabmsVidVcu                            //vcu VID����     ��ʼ0xD000
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
    VID_VCU_VIN1                                 , // [ vid = 53275 ] ����ʶ����
    VID_VCU_VIN2                                 , // [ vid = 53276 ]
    VID_VCU_VIN3                                 , // [ vid = 53277 ]
    VID_VCU_VIN4                                 , // [ vid = 53278 ]
    VID_VCU_VIN5                                 , // [ vid = 53279 ]
    VID_VCU_VIN6                                 , // [ vid = 53280 ]
    VID_VCU_VIN7                                 , // [ vid = 53281 ]
    VID_VCU_VIN8                                 , // [ vid = 53282 ]
    VID_VCU_VIN9                                 , // [ vid = 53283 ]
    VID_VCU_VIN10                                , // [ vid = 53284 ]
    VID_VCU_WZL_BMS_STATUS                       , // [ vid = 53285 ] BMS����״̬
    VID_VCU_WZL_HVRLY_STATUS                     , // [ vid = 53286 ] ��ѹ�̵�����©��״̬
    VID_VCU_WZL_ALLOW_MAX_TEMP                   , // [ vid = 53287 ] �������������¶�
    VID_VCU_WZL_ALLOW_MIN_TEMP                   , // [ vid = 53288 ] �������������¶�
    VID_VCU_WZL_ALLOW_MIN_SOC                    , // [ vid = 53289 ] ������������SOC
    VID_VCU_WZL_ALLOW_DSCH_CURR                  , // [ vid = 53290 ] �������ŵ����
    VID_VCU_WZL_ALLOW_CHRG_CURR                  , // [ vid = 53291 ] ������������
    VID_VCU_WZL_BMS_FAULT                        , // [ vid = 53292 ] �����ϵͳ������Ϣ
    VID_VCU_WZL_OUT_CHRG_TIME                    , // [ vid = 53293 ] ��ӳ����ʱ���ۼ�
    VID_VCU_WZL_CHRG_CTRL1                       , // [ vid = 53294 ] ����������(Ѳ��)
    VID_VCU_WZL_CHRG_CTRL2                       , // [ vid = 53295 ] ����������(ɲ��)
    VID_VCU_WZL_CHRG_CTRL3                       , // [ vid = 53296 ] ����������(�������)
    VID_VCU_WZL_DSCH_CMD                         , // [ vid = 53297 ] ���ٷŵ�����ָ��
    VID_VCU_WZL_LIFE                             , // [ vid = 53298 ] ����(����)�ź�
    VID_VCU_WZL_BMS_VER                          , // [ vid = 53299 ] �汾��
    VID_VCU_WZL_POSI1                            , // [ vid = 53300 ] �¶�/��������λ��
    VID_VCU_WZL_POSI2                            , // [ vid = 53301 ]
    VID_VCU_WZL_POSI3                            , // [ vid = 53302 ]
    VID_VCU_WZL_POSI4                            , // [ vid = 53303 ]
    VID_VCU_RELAY_REQ                            , // [ vid = 53304 ] VCU�������̵�������  [ 0��BMS���ƣ�1���Ͽ����̵��� ]
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
    VID_VCU_MAX_NUM = 256                          // [ vid = 53345 ] �����豸VID����  [ 97 ]
};

enum enParabmsVidChr                            //���VID����   ��ʼ0xD400
{
    VID_CHR_ONLINE                               , // [ vid = 54272 ] ��������״̬
    VID_CHR_STATE                                , // [ vid = 54273 ] ����״̬
    VID_CHR_CTRL                                 , // [ vid = 54274 ] ������������
    VID_CHR_STEP                                 , // [ vid = 54275 ] ���׶�
    VID_CHR_ALARM                                , // [ vid = 54276 ] �������ϴ���
    VID_CHR_VOLT_OUTPUT                          , // [ vid = 54277 ] ����ѹ - �������ֵ
    VID_CHR_CURR_OUTPUT                          , // [ vid = 54278 ] ������ - �������ֵ
    VID_CHR_VOLT_REQUEST                         , // [ vid = 54279 ] ����ѹ - ����ֵ
    VID_CHR_CURR_REQUEST                         , // [ vid = 54280 ] ������ - ����ֵ
    VID_CHR_CC                                   , // [ vid = 54281 ] ����CC  [ 0:δ���� 1������ ]
    VID_CHR_RELAY_STATE                          , // [ vid = 54282 ] ���̵���״̬  [ 0���Ͽ� 1���պ� ]
    VID_CHR_TYPE                                 , // [ vid = 54283 ] ��������
    VID_CHR_CHARGING                             , // [ vid = 54284 ]
    VID_CHR_RESERVED2                            , // [ vid = 54285 ]
    VID_CHR_RESERVED3                            , // [ vid = 54286 ]
    VID_CHR_RESERVED4                            , // [ vid = 54287 ]
    VID_CHR_RESERVED5                            , // [ vid = 54288 ]
    VID_CHR_RESERVED6                            , // [ vid = 54289 ]
    VID_CHR_RESERVED7                            , // [ vid = 54290 ]
    VID_CHR_RESERVED8                            , // [ vid = 54291 ]
    VID_CHR_RESERVED9                            , // [ vid = 54292 ]
    VID_CHR_CURR_REQUEST_TMP                     , // [ vid = 54293 ] ������ - ʵ������ֵ
    VID_CHR_CC2		                             , // [ vid = 54294 ] ����CC2  [ 0:δ���� 1������ ]
    VID_CHR_RESERVED12                           , // [ vid = 54295 ]
    VID_CHR_MAX_NUM                                // [ vid = 54296 ]�����豸VID����  [ 24 ]
};

enum enParabmsPidSys                                //ϵͳPID����   ��ʼ0xF000
{
    PID_START                                        , // [ vid = 0xF000 ] ( 0 )��ʼ  [ ���� ]
    PID_SYS_BAT_NUM                                  , // [ vid = 0xF001 ] ( 1 )�������
    PID_SYS_BSU_NUM                                  , // [ vid = 0xF002 ] ( 2 )ÿ���ص�BSU����
    PID_SYS_CFG_VER                                  , // [ vid = 0xF003 ] ( 3 )�����ļ��汾

    PID_SYS_LEM_HALL_TYPE                            , // [ vid = 0xF004 ] ( 4 )LEM��������  [ 18, 24, �� ]
    PID_SYS_BMU_ADDR                                 , // [ vid = 0xF005 ] ( 5 )��̨ͨ�ŵ�ַ
    PID_SYS_BMU_BAUD                                 , // [ vid = 0xF006 ] ( 6 )��̨ͨ�Ų�����  [ 0=9600,1=19200,2=... ]

    PID_SYS_HCU_TYPE                                 , // [ vid = 0xF007 ] ( 7 )��̨HCUЭ������
    PID_SYS_CHR_TYPE_ON_BOARD                        , // [ vid = 0xF008 ] ( 8 )���س�������

    PID_SYS_BMU_TYPE                                 , // [ vid = 0xF009 ] ( 9 )BMU����  [ 0=��������1=LCD��ʾ�� ]
    PID_SYS_BSU_TYPE                                 , // [ vid = 0xF00A ] ( 10 )BSU����  [ 0=12S��1=30S,  ]

    PID_SYS_RUN_HOUR                                 , // [ vid = 0xF00B ] ( 11 )�ۼ�����ʱ��  [ H ]
    PID_SYS_LAST_PWR_OFF_MD                          , // [ vid = 0xF00C ] ( 12 )�ϴιػ�ʱ������  [ ��¼�ϴιػ�����ʱ�� ]
    PID_SYS_LAST_PWR_OFF_HM                          , // [ vid = 0xF00D ] ( 13 )�ϴιػ�ʱ��ʱ��  [ ��¼�ϴιػ�����ʱ�� ]

    PID_SYS_ALARM_QUIET                              , // [ vid = 0xF00E ] ( 14 )�澯��������  [ 0=�澯����,1=������ ]
    PID_SYS_BMU_FAULT                                , // [ vid = 0xF00F ] ( 15 )BMU������ϴ���  [ ÿһλ����һ�ֹ��� ]

    PID_SYS_CURR_SENSOR_TYPE                         , // [ vid = 0xF010 ] ( 16 )��������������  [ 0=������1=������ ]
    PID_SYS_HALL_RATED_CURR                          , // [ vid = 0xF011 ] ( 17 )���������  [ A ]
    PID_SYS_HALL_RATED_VOLT                          , // [ vid = 0xF012 ] ( 18 )�������ѹ  [ mV ]
    PID_SYS_HALL_ZERO                                , // [ vid = 0xF013 ] ( 19 )������㼴ʵ�ʵ���Ϊ0ʱ������ʾֵ  [ 0.1A ]
    PID_SYS_HALL_POSI                                , // [ vid = 0xF014 ] ( 20 )����������λ��  [ 0=BMU,99=��Եģ�� ]
    PID_SYS_SHUNT_RATED_CURR                         , // [ vid = 0xF015 ] ( 21 )�����������  [ A ]
    PID_SYS_SHUNT_RATED_VOLT                         , // [ vid = 0xF016 ] ( 22 )���������ѹ  [ mV ]

    PID_SYS_RELAY1_CTRL_TYPE                         , // [ vid = 0xF017 ] ( 23 )�̵���1��������  [ 0=��澯�޹� ]
    PID_SYS_RELAY2_CTRL_TYPE                         , // [ vid = 0xF018 ] ( 24 )�̵���2��������  [ 1=�����и澯ʱ�Ͽ� ]
    PID_SYS_RELAY3_CTRL_TYPE                         , // [ vid = 0xF019 ] ( 25 )�̵���3��������  [ 2=�����޸澯ʱ�պ� ]
    PID_SYS_RELAY4_CTRL_TYPE                         , // [ vid = 0xF01A ] ( 26 )�̵���4��������  [ 3=��澯ǿ���� ]
    PID_SYS_RELAY5_CTRL_TYPE                         , // [ vid = 0xF01B ] ( 27 )�̵���5��������
    PID_SYS_RELAY6_CTRL_TYPE                         , // [ vid = 0xF01C ] ( 28 )�̵���6��������
    PID_SYS_RELAY7_CTRL_TYPE                         , // [ vid = 0xF01D ] ( 29 )�̵���7��������
    PID_SYS_RELAY8_CTRL_TYPE                         , // [ vid = 0xF01E ] ( 30 )�̵���8��������

    PID_SYS_FAN_START_TEMP                           , // [ vid = 0xF01F ] ( 31 )���������¶�  [ �� ]
    PID_SYS_FAN_STOP_TEMP                            , // [ vid = 0xF020 ] ( 32 )���ȹر��¶�  [ �� ]
    PID_SYS_FAN_START_DIFF                           , // [ vid = 0xF021 ] ( 33 )���������²�  [ �� ]
    PID_SYS_FAN_STOP_DIFF                            , // [ vid = 0xF022 ] ( 34 )���ȹر��²�  [ �� ]
    PID_SYS_HOT_START_TEMP                           , // [ vid = 0xF023 ] ( 35 )���������¶�  [ �� ]
    PID_SYS_HOT_STOP_TEMP                            , // [ vid = 0xF024 ] ( 36 )���ȹر��¶�  [ �� ]

    PID_SYS_OPEN_VOLT_SOC_ENABLE                     , // [ vid = 0xF025 ] ( 37 )��·��ѹ����SOC����  [ 0=�رգ�1=�� ]
    PID_SYS_OCV_TEMP_UP                              , // [ vid = 0xF026 ] ( 38 )��·��ѹ��Ч�¶�����  [ �� ]
    PID_SYS_OCV_TEMP_DOWN                            , // [ vid = 0xF027 ] ( 39 )��·��ѹ��Ч�¶�����  [ �� ]
    PID_SYS_00SOC_VOLT                               , // [ vid = 0xF028 ] ( 40 )SOC=0%ʱ�Ŀ�·��ѹ  [ mV ]
    PID_SYS_10SOC_VOLT                               , // [ vid = 0xF029 ] ( 41 )SOC=10%ʱ�Ŀ�·��ѹ  [ mV ]
    PID_SYS_20SOC_VOLT                               , // [ vid = 0xF02A ] ( 42 )SOC=20%ʱ�Ŀ�·��ѹ  [ mV ]
    PID_SYS_30SOC_VOLT                               , // [ vid = 0xF02B ] ( 43 )SOC=30%ʱ�Ŀ�·��ѹ  [ mV ]
    PID_SYS_40SOC_VOLT                               , // [ vid = 0xF02C ] ( 44 )SOC=40%ʱ�Ŀ�·��ѹ  [ mV ]
    PID_SYS_50SOC_VOLT                               , // [ vid = 0xF02D ] ( 45 )SOC=50%ʱ�Ŀ�·��ѹ  [ mV ]
    PID_SYS_60SOC_VOLT                               , // [ vid = 0xF02E ] ( 46 )SOC=60%ʱ�Ŀ�·��ѹ  [ mV ]
    PID_SYS_70SOC_VOLT                               , // [ vid = 0xF02F ] ( 47 )SOC=70%ʱ�Ŀ�·��ѹ  [ mV ]
    PID_SYS_80SOC_VOLT                               , // [ vid = 0xF030 ] ( 48 )SOC=80%ʱ�Ŀ�·��ѹ  [ mV ]
    PID_SYS_90SOC_VOLT                               , // [ vid = 0xF031 ] ( 49 )SOC=90%ʱ�Ŀ�·��ѹ  [ mV ]
    PID_SYS_100SOC_VOLT                              , // [ vid = 0xF032 ] ( 50 )SOC=100%ʱ�Ŀ�·��ѹ  [ mV ]

    PID_SYS_BAL_MODE                                 , // [ vid = 0xF033 ] ( 51 )����ģʽ  [ 0=�������⣬1=�������� ]
    PID_SYS_BAL_CURR                                 , // [ vid = 0xF034 ] ( 52 )��ؾ����������ֵ  [ mA ]
    PID_SYS_BAL_START_VOLT                           , // [ vid = 0xF035 ] ( 53 )��ؾ�������ѹ��  [ mV ]
    PID_SYS_BAL_START_CAPA                           , // [ vid = 0xF036 ] ( 54 )��ؾ�������������ֵ  [ 0.1AH ]
    PID_SYS_BAL_PROT_VOLT_UP                         , // [ vid = 0xF037 ] ( 55 )���Ᵽ����ѹ����  [ mV ]
    PID_SYS_BAL_PROT_VOLT_DN                         , // [ vid = 0xF038 ] ( 56 )���Ᵽ����ѹ����  [ mV ]
    PID_SYS_BAL_TIME_ACTIVE                          , // [ vid = 0xF039 ] ( 57 )��������ʱ��  [ S ]
    PID_SYS_BAL_TIME_PASSIVE                         , // [ vid = 0xF03A ] ( 58 )��������ʱ��  [ S ]
    PID_SYS_BAL_DURATION_PASSIVE                     , // [ vid = 0xF03B ] ( 59 )�����������ʱ��  [ ms ]
    PID_SYS_BAL_START_VOLT_PASSIVE                   , // [ vid = 0xF03C ] ( 60 )��������������ѹ  [ mv ]
    PID_SYS_BAL_START_VOLT_ACTIVE                    , // [ vid = 0xF03D ] ( 61 )������������ѹ��  [ mv ]
    PID_SYS_BAL_PHASE_ACTIVE                         , // [ vid = 0xF03E ] ( 62 )��������׶�  [ 0��ȫ�̿������� 1�����ʱ�������� ]
    PID_SYS_BAL_MODE_ACTIVE                          , // [ vid = 0xF03F ] ( 63 )��������ģʽ  [ 0������ģʽ 1������ģʽ(���ʱ��ֻ���ŵ���⣻�ŵ�ʱ��ֻ��������) ]
    PID_SYS_BAL_RESERVED3                            , // [ vid = 0xF040 ] ( 64 )
    PID_SYS_BAL_RESERVED4                            , // [ vid = 0xF041 ] ( 65 )

    PID_SYS_SOC_AUTOSET                              , // [ vid = 0xF042 ] ( 66 )�Զ�����SOC����  [ 0=�رգ�1=�� ]
    PID_SYS_SOC_SET_UP                               , // [ vid = 0xF043 ] ( 67 )���й�����SOC����ֵ����
    PID_SYS_SOC_UPSET_DELAY                          , // [ vid = 0xF044 ] ( 68 )����λSOC��ʱ
    PID_SYS_SOC_DNSET_DELAY                          , // [ vid = 0xF045 ] ( 69 )����λSOC��ʱ
    PID_SYS_0CURR_SET_TIME                           , // [ vid = 0xF046 ] ( 70 )0����������ʱ����SOC  [ H ]

    PID_GPRS_MODULE_TYPE                             , // [ vid = 0xF047 ] ( 71 )GPRSģ������  [ 0=WISOM228,1=M10 ]
    PID_GPRS_PROVIDER                                , // [ vid = 0xF048 ] ( 72 )GPRS��Ӧ��  [ 0=�ر�,1=�ƶ�,2=��ͨ,3=���� ]
    PID_GPRS_IP1                                     , // [ vid = 0xF049 ] ( 73 )GPRS IP��ַ1
    PID_GPRS_IP2                                     , // [ vid = 0xF04A ] ( 74 )GPRS IP��ַ2
    PID_GPRS_IP3                                     , // [ vid = 0xF04B ] ( 75 )GPRS IP��ַ3
    PID_GPRS_IP4                                     , // [ vid = 0xF04C ] ( 76 )GPRS IP��ַ4
    PID_GPRS_PORT                                    , // [ vid = 0xF04D ] ( 77 )GPRS�˿ں�
    PID_GPRS_CONN_TIMEOUT                            , // [ vid = 0xF04E ] ( 78 )GPRS���ӳ�ʱʱ��  [ S ]
    PID_GPRS_SEND_INTV                               , // [ vid = 0xF04F ] ( 79 )GPRS����ʱ����С���  [ S ]
    PID_GPRS_PACK2_TIME                              , // [ vid = 0xF050 ] ( 80 )GPRS��2�����ݷ��ͼ��  [ 0.1S ]
    PID_GPRS_PACK3_TIME                              , // [ vid = 0xF051 ] ( 81 )GPRS��3�����ݷ��ͼ��  [ 0.1S ]
    PID_GPRS_PACK4_TIME                              , // [ vid = 0xF052 ] ( 82 )GPRS��4�����ݷ��ͼ��  [ 0.1S ]
    PID_GPRS_PACK5_TIME                              , // [ vid = 0xF053 ] ( 83 )GPRS��5�����ݷ��ͼ��  [ 0.1S ]
    PID_GPRS_RECV_TIMEOUT                            , // [ vid = 0xF054 ] ( 84 )GPRS����OK��ʱʱ��  [ S ]
    PID_GPRS_SAVE_MODE                               , // [ vid = 0xF055 ] ( 85 )GPRS��ʡ����ģʽ  [ 0=��ֹ��1=ʹ�� ]
    PID_GPRS_ENABLE                              	 , // [ vid = 0xF056 ] ( 86 )GPRSʹ�ܿ��� [ 0=��ֹ��1=ʹ�� ]

    PID_SYS_BIU_POSI                                 , // [ vid = 0xF057 ] ( 87 )��Եģ��λ��  [ 0=BMU,99=��Եģ�� ]
    PID_SYS_JY_ENABLE                                , // [ vid = 0xF058 ] ( 88 )��Ե���ʹ��  [ 0=��ֹ��1=ʹ�� ]
    PID_SYS_JY_SPEED                                 , // [ vid = 0xF059 ] ( 89 )��Ե���������ٶ�  [ Ͷ�к�ȴ����� ]
    PID_SYS_JY_RESERVED                              , // [ vid = 0xF05A ] ( 90 )��Ե���ò���

    PID_BAT_TYPE                                     , // [ vid = 0xF05B ] ( 91 )�������
    PID_BAT_CHRG_COEF                                , // [ vid = 0xF05C ] ( 92 )���ϵ��  [ % ]
    PID_BAT_DSCH_COEF                                , // [ vid = 0xF05D ] ( 93 )�ŵ�ϵ��  [ % ]
    PID_BAT_RATED_CAPA                               , // [ vid = 0xF05E ] ( 94 )��ض����  [ AH ]
    PID_BAT_CELL_RATED_VOLT                          , // [ vid = 0xF05F ] ( 95 )������ѹ  [ mV ]

    PID_SYS_MAX_CHRG_VOLT                            , // [ vid = 0xF060 ] ( 96 )��������ѹ  [ V ]
    PID_SYS_MAX_FAST_CHRG_CURR                       , // [ vid = 0xF061 ] ( 97 )���������������(���) [ A ]
    PID_SYS_MAX_SLOW_CHRG_CURR                       , // [ vid = 0xF062 ] ( 98 )���������������(����) [ A ]
    PID_SYS_MAX_CELL_CHRG_VOLT                       , // [ vid = 0xF063 ] ( 99 )��������������ѹ  [1-4:�澯�㣬������ mV ]
    PID_SYS_CHRG_END_CURR                            , // [ vid = 0xF064 ] ( 100 )������С�������������ɵ�����  [ A ]
    PID_SYS_MIN_CELL_CHRG_VOLT                       , // [ vid = 0xF065 ] ( 101 )��������������ѹ  [1-4:�澯�㣬������ mV ]
    PID_SYS_CHRG_HEAT_CURR                           , // [ vid = 0xF066 ] ( 102 )������������� [ A ]
    PID_SYS_CHRG_HEAT_VOLT	                         , // [ vid = 0xF067 ] ( 103 )�����������ѹ [ V ] [ 0=��ص�ѹ������=���õ�ѹ ]

    PID_SYS_SOC                                      , // [ vid = 0xF068 ] ( 104 )ϵͳSOC
    PID_SYS_SOH                                      , // [ vid = 0xF069 ] ( 105 )ϵͳSOH
    PID_SYS_PERIOD_CHRG_TIME                         , // [ vid = 0xF06A ] ( 106 )��Ъʽ���ʱ��  [ S ]
    PID_SYS_DORMANT_TIME                             , // [ vid = 0xF06B ] ( 107 )����ʱ��  [ S ]
    PID_SYS_SELF_CONSUME                             , // [ vid = 0xF06C ] ( 108 )ϵͳ�Ժĵ�  [ 0.1A ]
    PID_SYS_SELF_CONSUME_SOC                         , // [ vid = 0xF06D ] ( 109 )ϵͳ�Ժĵ��Ƿ����SOC����  [ 0=�رգ�1=�� ]

    PID_SYS_ALARM_RUN_START                          , // [ vid = 0xF06E ] ( 110 )�澯ģ�鿪ʼ����ʱ��  [ S��ǰN�벻����澯 ]
    PID_SYS_HALL_DIRECTION                           , // [ vid = 0xF06F ] ( 111 )��������  [ 0�����ų�緽�򣨳��Ϊ�����ŵ�Ϊ������1�����ŷŵ緽�򣨷ŵ�Ϊ�������Ϊ���� ]

    PID_SYS_PRECHARGE_MODE                           , // [ vid = 0xF070 ] ( 112 )Ԥ��ʱ��  [ 0.1S��0=��Ԥ�䣬N=���Ԥ��ʱ�� ]
    PID_SYS_PRECHARGE_VOLT_RATE                      , // [ vid = 0xF071 ] ( 113 )Ԥ���ѹ�ٷֱ�  [ % ]
    PID_SYS_PRECHARGE_END_CURR                       , // [ vid = 0xF072 ] ( 114 )Ԥ���������  [ 0.1A ]
    PID_SYS_BATT_RATED_ENERGY                        , // [ vid = 0xF073 ] ( 115 )���ر��������  [ 0.1KWH ]
    PID_SYS_CELL_MAX_CHRG_VOLT                       , // [ vid = 0xF074 ] ( 116 )��������������ѹ  [ mV ]

    PID_SYS_FORCE_CHRG_INPUT                         , // [ vid = 0xF075 ] ( 117 )ǿ������ɽӵ�  [ 0=��ǿ�䣬1~3=����ɽӵ㣬11~13=���볣�� ]

    PID_SYS_RELAY_1                                  , // [ vid = 0xF076 ] ( 118 )K1�̵������ܶ��壨CPU���ϣ�  [ 1��Ԥ��̵��� ]
    PID_SYS_RELAY_2                                  , // [ vid = 0xF077 ] ( 119 )K2�̵������ܶ��壨CPU���ϣ�  [ 2�������������̵��� ]
    PID_SYS_RELAY_3                                  , // [ vid = 0xF078 ] ( 120 )K3�̵������ܶ��壨CPU���ϣ�  [ 3�����̵��� ]
    PID_SYS_RELAY_4                                  , // [ vid = 0xF079 ] ( 121 )K4�̵������ܶ��壨�Ͱ��ϣ�  [ 4���ⲿ�̵��� ]
    PID_SYS_RELAY_5                                  , // [ vid = 0xF07A ] ( 122 )K5�̵������ܶ��壨�Ͱ��ϣ�  [ 5�����ȼ̵��� ]
    PID_SYS_RELAY_6                                  , // [ vid = 0xF07B ] ( 123 )K6�̵������ܶ��壨�Ͱ��ϣ�  [ 6���ܸ��̵��� ]
    PID_SYS_RELAY_7                                  , // [ vid = 0xF07C ] ( 124 )K7�̵������ܶ��壨�Ͱ��ϣ�  [ 7�����ߣ�����BSU��Դ�� ]
    PID_SYS_RELAY_8                                  , // [ vid = 0xF07D ] ( 125 )K8�̵������ܶ��壨�Ͱ��ϣ�  [ 8: ��������Դ ]
    PID_SYS_RELAY_9                                  , // [ vid = 0xF07E ] ( 126 )K9�̵������ܶ��壨BSU�Ϸ��ȣ�  [ 9��BSUԤ��̵��� ]
    PID_SYS_RELAY_10                                 , // [ vid = 0xF07F ] ( 127 )K10�̵������ܶ��壨BSU�ϼ��ȣ�  [ 10��BSU���̵��� 11������������ ]

    PID_SYS_CHRG_INTERLOCK                           , // [ vid = 0xF080 ] ( 128 )��ŵ绥��  [ 0��������1�������������ʱ�Ͽ��ŵ��· ]
    PID_SYS_RELAY_RESET                              , // [ vid = 0xF081 ] ( 129 )�澯�ָ����Ƿ�ָ��̵���  [ 0�����ظ���1���ָ� ]

    PID_SYS_RUN_RANGE                                , // [ vid = 0xF082 ] ( 130 )������ʹ�õĻ��������ϣ����ܵļ̵������Ʒ�ʽ��ͬ��  [ 0�����綯 1����϶��� 2������ϵͳ ]
    PID_SYS_CHR_TYPE_OFF_BOARD                       , // [ vid = 0xF083 ] ( 131 )�ǳ��س���  [ 3=���ꣻ4=���� ]
    PID_SYS_BASE_BOARD_VER                           , // [ vid = 0xF084 ] ( 132 )ǿ�����õװ�汾  [ 0:������ ]

    PID_SYS_CHR_ON_TRICKLE_TIME                      , // [ vid = 0xF085 ] ( 133 )�������� Trickle���  [ 1S ]
    PID_SYS_CHR_ON_CURR_COE                          , // [ vid = 0xF086 ] ( 134 )�������� �����½���ϵ��  [ % ]
    PID_SYS_CHR_CC_POS                               , // [ vid = 0xF087 ] ( 135 )����CC2 ���ڵ�λ��  [ 0:��Դ���ӣ�1-3��D1-D3 9:BMU-J9����]

    PID_SYS_HOT_PHASE                                , // [ vid = 0xF088 ] ( 136 )���ȹ���  [ 0:ȫ�̼��� 1�����ʱ���� ]
    PID_SYS_AUX_POS                                  , // [ vid = 0xF089 ] ( 137 )���̵����������� ���ڵ�λ��  [ 0:�޸������㣬1-3��D1-D3 ]
    PID_SYS_POWER_OFF_INPUT                          , // [ vid = 0xF08A ] ( 138 )�ֶ��ػ�����ɽӵ�  [ 0=��ǿ�䣬1~3=����ɽӵ㣬11~13=���볣�� ]
    PID_SYS_ISO_MODE                                 , // [ vid = 0xF08B ] ( 139 )��Ե�������  [ 0��ȫ�̼�� 1�����ʱ����� ]
    PID_SYS_OUT_RELAY_TYPE                           , // [ vid = 0xF08C ] ( 140 )�ⲿ�̵��������߼�  [ 1=�´���2=�麣�ε� ]
    PID_SYS_PRE_MIN_TIME                             , // [ vid = 0xF08D ] ( 141 )Ԥ����Сʱ��  [ 0.01S ] δ��
    PID_SYS_SAMPLE_ACCURACY                          , // [ vid = 0xF08E ] ( 142 )BSU�����ѹ��������  [ 1mV ]
    PID_SYS_CELL_SEQUENCE                            , // [ vid = 0xF08F ] ( 143 )���������  [ 0�����ж��壨������Ŵ�������ʼ��1��������Ŵ��ܸ���ʼ ]
    PID_SYS_LOG_TIME                                 , // [ vid = 0xF090 ] ( 144 )�ڲ��洢���������ݼ��  [ 1S ]
    PID_SYS_LOG_ENABLE                               , // [ vid = 0xF091 ] ( 145 )�ڲ��洢ʹ��
    PID_SYS_FAN_PWM_FREQ                             , // [ vid = 0xF092 ] ( 146 )����PWMƵ��  [ Hz ]
    PID_SYS_RESERVED12                               , // [ vid = 0xF093 ] ( 147 )Ԥ��
    PID_SYS_CHR_MIN_CURR                             , // [ vid = 0xF094 ] ( 148 )������С�������������ɵ�����  [ A ]
    PID_SYS_CONSTANT_MODE                            , // [ vid = 0xF095 ] ( 149 )Ԥ��(��ͨ��ʾ��)
    PID_SYS_DSCH_POWER_LV1                           , // [ vid = 0xF096 ] ( 150 )1���ŵ繦��
    PID_SYS_DSCH_POWER_LV2                           , // [ vid = 0xF097 ] ( 151 )2���ŵ繦��
    PID_SYS_DSCH_POWER_LV3                           , // [ vid = 0xF098 ] ( 152 )3���ŵ繦��
    PID_SYS_DSCH_POWER_LV4                           , // [ vid = 0xF099 ] ( 153 )4���ŵ繦��
    PID_SYS_CHRG_POWER_LV1                           , // [ vid = 0xF09A ] ( 154 )1����繦��
    PID_SYS_CHRG_POWER_LV2                           , // [ vid = 0xF09B ] ( 155 )2����繦��
    PID_SYS_CHRG_POWER_LV3                           , // [ vid = 0xF09C ] ( 156 )3����繦��
    PID_SYS_CHRG_POWER_LV4                           , // [ vid = 0xF09D ] ( 157 )4����繦��
    PID_CHRG_CONSTANT_MODE                           , // [ vid = 0xF09E ] ( 158 )�ǳ��س���ѹ���Ʒ�ʽ(���ĺ���Ҫ������Ч)  [ 0:BMS����ѹ����������ƺ�ѹ 1��BMS���ƺ�ѹ ]
    PID_CHRG_ON_BOARD_CHANNEL                        , // [ vid = 0xF09F ] ( 159 )���س�������CAN��ͨ��  [ 0,1,2:��CAN2�� 3:��CAN3�� ]
    PID_SYS_RESERVED25                               , // [ vid = 0xF0A0 ] ( 160 )Ԥ��
    PID_SYS_RELAY_CURR                               , // [ vid = 0xF0A1 ] ( 161 )�̵��������Ƿ�͵����й���  [ 0:�̵����жϺ͵����й�ϵ 1:�͵����޹� ]
    PID_SYS_SLEEP_ENABLE                             , // [ vid = 0xF0A2 ] ( 162 )BMU���߹���ʹ�ܣ�BMU����BSU��Դ��  [ 0=��ֹ��1=ʹ�� ]
    PID_SYS_BTS_NUM                                  , // [ vid = 0xF0A3 ] ( 163 )�¶Ȳɼ�ģ�����
    PID_SYS_BACKLIGHT_TIME                           , // [ vid = 0xF0A4 ] ( 164 )LCD��ʾ���رձ���ʱ��  [ ��.0=���ر� ]
    PID_SYS_CHECK_HV_ENABLE                          , // [ vid = 0xF0A5 ] ( 165 )��ѹ�Լ�ʹ�ܿ���  [ 0=��ֹ��1=ʹ�� ]
    PID_SYS_POWER_CTRL_TYPE                          , // [ vid = 0xF0A6 ] ( 166 )���ʿ�������  [0=���ף�1=��ϸ]
    PID_SYS_MAIN_POS_DI                              , // [ vid = 0xF0A7 ] ( 167 )�����̵����ز�DI
    PID_SYS_MAIN_NEG_DI                              , // [ vid = 0xF0A8 ] ( 168 )�ܸ��̵����ز�DI
    PID_SYS_RESERVED34                               , // [ vid = 0xF0A9 ] ( 169 )Ԥ��
    PID_SYS_RESERVED35                               , // [ vid = 0xF0AA ] ( 170 )Ԥ��
    PID_SYS_RESERVED36                               , // [ vid = 0xF0AB ] ( 171 )Ԥ��
    PID_SYS_RESERVED37                               , // [ vid = 0xF0AC ] ( 172 )Ԥ��
    PID_SYS_RESERVED38                               , // [ vid = 0xF0AD ] ( 173 )Ԥ��
    PID_SYS_RESERVED39                               , // [ vid = 0xF0AE ] ( 174 )Ԥ��
    PID_SYS_RESERVED40                               , // [ vid = 0xF0AF ] ( 175 )Ԥ��
    PID_SYS_RESERVED41                               , // [ vid = 0xF0B0 ] ( 176 )Ԥ��
    PID_SYS_RESERVED42                               , // [ vid = 0xF0B1 ] ( 177 )Ԥ��
    PID_SYS_RESERVED43                               , // [ vid = 0xF0B2 ] ( 178 )Ԥ��
    PID_SYS_RESERVED44                               , // [ vid = 0xF0B3 ] ( 179 )Ԥ��
    PID_SYS_RESERVED45                               , // [ vid = 0xF0B4 ] ( 180 )Ԥ��
    PID_SYS_RESERVED46                               , // [ vid = 0xF0B5 ] ( 181 )Ԥ��
    PID_SYS_RESERVED47                               , // [ vid = 0xF0B6 ] ( 182 )Ԥ��
    PID_SYS_RESERVED48                               , // [ vid = 0xF0B7 ] ( 183 )Ԥ��
    PID_SYS_RESERVED49                               , // [ vid = 0xF0B8 ] ( 184 )Ԥ��
    PID_SYS_RESERVED50                               , // [ vid = 0xF0B9 ] ( 185 )Ԥ��
    PID_SYS_RESERVED51                               , // [ vid = 0xF0BA ] ( 186 )Ԥ��
    PID_SYS_RESERVED52                               , // [ vid = 0xF0BB ] ( 187 )Ԥ��
    PID_SYS_RESERVED53                               , // [ vid = 0xF0BC ] ( 188 )Ԥ��
    PID_SYS_RESERVED54                               , // [ vid = 0xF0BD ] ( 189 )Ԥ��
    PID_SYS_RESERVED55                               , // [ vid = 0xF0BE ] ( 190 )Ԥ��
    PID_SYS_RESERVED56                               , // [ vid = 0xF0BF ] ( 191 )Ԥ��
    PID_SYS_RESERVED57                               , // [ vid = 0xF0C0 ] ( 192 )Ԥ��
    PID_SYS_RESERVED58                               , // [ vid = 0xF0C1 ] ( 193 )Ԥ��
    PID_SYS_RESERVED59                               , // [ vid = 0xF0C2 ] ( 194 )Ԥ��
    PID_SYS_RESERVED60                               , // [ vid = 0xF0C3 ] ( 195 )Ԥ��
    PID_SYS_RESERVED61                               , // [ vid = 0xF0C4 ] ( 196 )Ԥ��
    PID_SYS_RESERVED62                               , // [ vid = 0xF0C5 ] ( 197 )Ԥ��
    PID_SYS_RESERVED63                               , // [ vid = 0xF0C6 ] ( 198 )Ԥ��
    PID_SYS_RESERVED64                               , // [ vid = 0xF0C7 ] ( 199 )Ԥ��
    PID_SYS_RESERVED65                               , // [ vid = 0xF0C8 ] ( 200 )Ԥ��
    PID_SYS_RESERVED66                               , // [ vid = 0xF0C9 ] ( 201 )Ԥ��
    PID_SYS_RESERVED67                               , // [ vid = 0xF0CA ] ( 202 )Ԥ��
    PID_SYS_RESERVED68                               , // [ vid = 0xF0CB ] ( 203 )Ԥ��
    PID_SYS_RESERVED69                               , // [ vid = 0xF0CC ] ( 204 )Ԥ��
    PID_SYS_RESERVED70                               , // [ vid = 0xF0CD ] ( 205 )Ԥ��
    PID_SYS_RESERVED71                               , // [ vid = 0xF0CE ] ( 206 )Ԥ��
    PID_SYS_RESERVED72                               , // [ vid = 0xF0CF ] ( 207 )Ԥ��
    PID_SYS_RESERVED73                               , // [ vid = 0xF0D0 ] ( 208 )Ԥ��
    PID_SYS_RESERVED74                               , // [ vid = 0xF0D1 ] ( 209 )Ԥ��
    PID_SYS_RESERVED75                               , // [ vid = 0xF0D2 ] ( 210 )Ԥ��
    PID_SYS_RESERVED76                               , // [ vid = 0xF0D3 ] ( 211 )Ԥ��
    PID_SYS_RESERVED77                               , // [ vid = 0xF0D4 ] ( 212 )Ԥ��
    PID_SYS_RESERVED78                               , // [ vid = 0xF0D5 ] ( 213 )Ԥ��
    PID_SYS_RESERVED79                               , // [ vid = 0xF0D6 ] ( 214 )Ԥ��
    PID_SYS_RESERVED80                               , // [ vid = 0xF0D7 ] ( 215 )Ԥ��
    PID_SYS_RESERVED81                               , // [ vid = 0xF0D8 ] ( 216 )Ԥ��
    PID_SYS_RESERVED82                               , // [ vid = 0xF0D9 ] ( 217 )Ԥ��
    PID_SYS_RESERVED83                               , // [ vid = 0xF0DA ] ( 218 )Ԥ��
    PID_SYS_RESERVED84                               , // [ vid = 0xF0DB ] ( 219 )Ԥ��
    PID_SYS_RESERVED85                               , // [ vid = 0xF0DC ] ( 220 )Ԥ��
    PID_SYS_RESERVED86                               , // [ vid = 0xF0DD ] ( 221 )Ԥ��
    PID_SYS_RESERVED87                               , // [ vid = 0xF0DE ] ( 222 )Ԥ��
    PID_SYS_RESERVED88                               , // [ vid = 0xF0DF ] ( 223 )Ԥ��
    PID_SYS_RESERVED89                               , // [ vid = 0xF0E0 ] ( 224 )Ԥ��
    PID_SYS_RESERVED90                               , // [ vid = 0xF0E1 ] ( 225 )Ԥ��
    PID_SYS_RESERVED91                               , // [ vid = 0xF0E2 ] ( 226 )Ԥ��
    PID_SYS_RESERVED92                               , // [ vid = 0xF0E3 ] ( 227 )Ԥ��
    PID_SYS_RESERVED93                               , // [ vid = 0xF0E4 ] ( 228 )Ԥ��
    PID_SYS_RESERVED94                               , // [ vid = 0xF0E5 ] ( 229 )Ԥ��
    PID_SYS_RESERVED95                               , // [ vid = 0xF0E6 ] ( 230 )Ԥ��
    PID_SYS_RESERVED96                               , // [ vid = 0xF0E7 ] ( 231 )Ԥ��
    PID_SYS_RESERVED97                               , // [ vid = 0xF0E8 ] ( 232 )Ԥ��
    PID_SYS_RESERVED98                               , // [ vid = 0xF0E9 ] ( 233 )Ԥ��
    PID_SYS_RESERVED99                               , // [ vid = 0xF0EA ] ( 234 )Ԥ��
    PID_SYS_RESERVED100                              , // [ vid = 0xF0EB ] ( 235 )Ԥ��
    PID_SYS_RESERVED101                              , // [ vid = 0xF0EC ] ( 236 )Ԥ��
    PID_SYS_RESERVED102                              , // [ vid = 0xF0ED ] ( 237 )Ԥ��
    PID_SYS_RESERVED103                              , // [ vid = 0xF0EE ] ( 238 )Ԥ��
    PID_SYS_TEMP1                                    , // [ vid = 0xF0EF ] ( 239 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP2                                    , // [ vid = 0xF0F0 ] ( 240 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP3                                    , // [ vid = 0xF0F1 ] ( 241 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP4                                    , // [ vid = 0xF0F2 ] ( 242 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP5                                    , // [ vid = 0xF0F3 ] ( 243 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP6                                    , // [ vid = 0xF0F4 ] ( 244 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP7                                    , // [ vid = 0xF0F5 ] ( 245 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP8                                    , // [ vid = 0xF0F6 ] ( 246 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP9                                    , // [ vid = 0xF0F7 ] ( 247 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP10                                   , // [ vid = 0xF0F8 ] ( 248 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP11                                   , // [ vid = 0xF0F9 ] ( 249 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP12                                   , // [ vid = 0xF0FA ] ( 250 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP13                                   , // [ vid = 0xF0FB ] ( 251 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP14                                   , // [ vid = 0xF0FC ] ( 252 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP15                                   , // [ vid = 0xF0FD ] ( 253 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP16                                   , // [ vid = 0xF0FE ] ( 254 )�����Ǳ�汾��ʱ���ȴ�ʩ��
    PID_SYS_TEMP255									 , // [ vid = 0xF0FF ] ( 255 )����

    PID_SYS_MAX_NUM                                    // [ vid = 0xF100 ]( 256 )ϵͳ�������PID  [ 256 ]
};

enum enBytePid                                      //�ֽ�PID
{
    PID_BYTE_RESERVED_00							, // [ vid = 0xFE00 ] ( 3584 )
    PID_BYTE_VIN_01									, // [ vid = 0xFE01 ] ( 3585 ) ����VIN
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

    PID_BYTE_BMU_NAME_01                            , // [ vid = 0xFE15 ] ( 3605 ) �豸����
    PID_BYTE_BMU_NAME_02                        	, // [ vid = 0xFE16 ] ( 3606 )
    PID_BYTE_BMU_NAME_03                    		, // [ vid = 0xFE17 ] ( 3607 )
    PID_BYTE_BMU_NAME_04                			, // [ vid = 0xFE18 ] ( 3608 )
    PID_BYTE_BMU_NAME_05            				, // [ vid = 0xFE19 ] ( 3609 )
    PID_BYTE_BMU_NAME_06        					, // [ vid = 0xFE1A ] ( 3610 )
    PID_BYTE_BMU_NAME_07    						, // [ vid = 0xFE1B ] ( 3611 )
    PID_BYTE_BMU_NAME_08							, // [ vid = 0xFE1C ] ( 3612 )
    PID_BYTE_BMU_NAME_09                            , // [ vid = 0xFE1D ] ( 3613 )
    PID_BYTE_BMU_NAME_10                        	, // [ vid = 0xFE1E ] ( 3614 )

    PID_BYTE_BMU_LABEL_01                   		, // [ vid = 0xFE1F ] ( 3615 ) �豸�����ǩ
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

    PID_BYTE_BMU_YEAR								, // [ vid = 0xFE33 ] ( 3635 ) �������, 15 = 2015��
    PID_BYTE_BMU_MONTH								, // [ vid = 0xFE34 ] ( 3636 ) �����·� [1~12]
    PID_BYTE_BMU_DAY								, // [ vid = 0xFE35 ] ( 3637 ) �������� [1~31]

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

    PID_BYTE_RESERVED_64							, // [ vid = 0xFE40 ] ( 3648 ) �ڶ�ҳ��ʼ
    PID_BYTE_RESERVED_65							, // [ vid = 0xFE41 ] ( 3649 )
    PID_BYTE_RESERVED_66							, // [ vid = 0xFE42 ] ( 3650 )
    PID_BYTE_RESERVED_67							, // [ vid = 0xFE43 ] ( 3651 )
    PID_BYTE_RESERVED_68							, // [ vid = 0xFE44 ] ( 3652 )

    PID_BYTE_MAX_NUM = 256					// �ֽ��Ͳ���������

};

enum enParabmsPidBsu    //BSU PID����
{
    PID_BSU_CELL_NUM        ,// ( 256 + BSU No. * 16 ) �ɼ��ĵ�ؽ���
    PID_BSU_TEMP_NUM        ,// ( 257 + BSU No. * 16 ) �ɼ����¶�·��
    PID_BSU_CHN_CFG1        ,// ( 258 + BSU No. * 16 ) �ɼ�ͨ������1
    PID_BSU_CHN_CFG2        ,// ( 259 + BSU No. * 16 ) �ɼ�ͨ������2
    PID_BSU_CHN_CFG3        ,// ( 260 + BSU No. * 16 ) �ɼ�ͨ������3
    PID_BSU_CHN_CFG4        ,// ( 261 + BSU No. * 16 ) �ɼ�ͨ������4
    //	PID_BSU_ADDRESS		,// ��ַ
    PID_BSU_BTS_TEMP_NUM	,// ( 262 + BSU No. * 16 ) �¶Ȳɼ�����ʹ�õ��¶�·��
    PID_BSU_PACK_NO         ,// ( 263 + BSU No. * 16 ) ����PACK���
    PID_BSU_DI_DO_CFG       ,// ( 264 + BSU No. * 16 ) �ɽӵ�����
    PID_BSU_TEMP_CFG1       ,// ( 265 + BSU No. * 16 ) �¶�����1	�����¶�
    PID_BSU_TEMP_CFG2       ,//	( 266 + BSU No. * 16 ) �¶�����2	�����¶�
    PID_BSU_BAR_CFG1        ,//	( 267 + BSU No. * 16 ) ͭ�ŵ�������1
    PID_BSU_BAR_CFG2        ,//	( 268 + BSU No. * 16 ) ����2
    PID_BSU_BAR_CFG3        ,//	( 269 + BSU No. * 16 ) ����3
    PID_BSU_BAR_CFG4        ,//	( 270 + BSU No. * 16 ) ����4
    PID_BSU_RESERVE5        ,//	( 271 + BSU No. * 16 ) ����5
    PID_BSU_MAX_NUM
};

enum enParabmsPidAlarm      //�澯PID����
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

enum enAlarmPara            //�澯����
{
	ALM_PARA_LEVEL1                                  , // һ���澯��  [ ������ ]
	ALM_PARA_LEVEL2                                  , // �����澯��
	ALM_PARA_LEVEL3                                  , // �����澯��
	ALM_PARA_LEVEL4                                  , // �ļ��澯��  [ ����΢ ]
	ALM_PARA_RELAY1                                  , // һ���澯�����̵���
	ALM_PARA_RELAY2                                  , // �����澯�����̵���
	ALM_PARA_DELAY                                   , // �̵���������ʱ  [ �����澯����ʱ�ж� ]
	ALM_PARA_FILTER_TIMES                            , // �澯�˲�����  [ �澯ȷ�ϴ��� ]
	ALM_PARA_SYS_LEVEL                               , // ϵͳ����
	ALM_PARA_DIS_LEVEL                               , // ��ʾ����
	ALM_PARA_MAX_NUM                                  // ���澯����  [ 10 ]
};

enum enAlarmId              //�澯ID
{
	ALM_CELL_OV                                      , // �����ѹ  [ OVER_VOLT ]
	ALM_CELL_UV                                      , // ����Ƿѹ  [ UNDER_VOLT ]
	ALM_CELL_OT                                      , // ��ظ���  [ OVER_TEMP ]
	ALM_CELL_UT                                      , // ��ص���  [ UNDER_TEMP ]
	ALM_CELL_LBK                                     , // �����ѹ����  [ LINE_BREAK ]
	ALM_CELL_TBK                                     , // �����¶ȶ���  [ TEMP_BREAK ]
	ALM_BATT_DV                                      , // ����ѹ�����  [ DIFF_VOLT ]
	ALM_BATT_DT                                      , // ����²����  [ DIFF_TEMP ]
	ALM_BATT_OV                                      , // �����ѹ  [ OVER_VOLT ]
	ALM_BATT_UV                                      , // ����Ƿѹ  [ UNDER_VOLT ]
	ALM_BATT_OC                                      , // �����SOC����  [ OVER_SOC ]
	ALM_BATT_UC                                      , // �����SOC����  [ UNDER_SOC ]
	ALM_CHRG_OCS                                     , // ��̬������  [ S=Steady state��̬ ]
	ALM_DSCH_OCS                                     , // ��̬�ŵ����
	ALM_CHRG_OCT                                     , // ˲̬������  [ T=transient˲̬ ]
	ALM_DSCH_OCT                                     , // ˲̬�ŵ����
	ALM_BSU_OFFLINE                                  , // BSU����
	ALM_BSU_FAULT                                    , // BSU����
	ALM_LEAK_OC                                      , // ©��������
	ALM_PRECHRG_FAIL                                 , // Ԥ��ʧ��
	ALM_AUX_FAIL                                     , // ���̵�����������ʧ��
	ALM_BMU_FAIL                                     , // BMU�ڲ�����
	ALM_VCU_OFFLINE                                  , // VCUͨ�Ŵ���
	ALM_HVREL_FAIL                                   , // ��ظ�ѹ�쳣
	ALM_HALL_BREAK                                   , // ��������
	ALM_RESERVED25                                   , // Ԥ���澯
	ALM_RESERVED26                                   , // Ԥ���澯
	ALM_RESERVED27                                   , // Ԥ���澯
	ALM_RESERVED28                                   , // Ԥ���澯
	ALM_RESERVED29                                   , // Ԥ���澯
	ALM_RESERVED30                                   , // Ԥ���澯
	ALM_RESERVED31                                   , // Ԥ���澯
	ALM_MAX_NUM                                       // ���澯����  [ 25 ]
};

enum enParabmsPidBat    //��ذ�PID����
{
    PID_BAT_SOC			,// ( 1280 + BAT No. * 16 ) ������SOC
    PID_BAT_SOH			,// ( 1281 + BAT No. * 16 ) ������SOH
    PID_BAT_CHRG_SOC	,//	( 1282 + BAT No. * 16 ) ������ۼƳ��SOC
    PID_BAT_DSCH_SOC	,//	( 1283 + BAT No. * 16 ) ������ۼƷŵ�SOC
    PID_BAT_CYCLE_TIMES	,//	( 1284 + BAT No. * 16 ) �����ѭ������
    PID_BAT_HALL_ZERO	,// ( 1285 + BAT No. * 16 ) ÿ������Ҫһ��������㣬��λ0.1A
    PID_BAT_RESERVE1	,//	( 1286 + BAT No. * 16 ) ����1
    PID_BAT_RESERVE2	,//	( 1287 + BAT No. * 16 ) ����2
    PID_BAT_RESERVE3	,//	( 1288 + BAT No. * 16 ) ����3
    PID_BAT_RESERVE4	,//	( 1289 + BAT No. * 16 ) ����4
    PID_BAT_RESERVE5	,//	( 1290 + BAT No. * 16 ) ����5
    PID_BAT_RESERVE6	,//	( 1291 + BAT No. * 16 ) ����6
    PID_BAT_RESERVE7	,//	( 1292 + BAT No. * 16 ) ����7
    PID_BAT_RESERVE8	,//	( 1293 + BAT No. * 16 ) ����8
    PID_BAT_RESERVE9	,//	( 1294 + BAT No. * 16 ) ����9
    PID_BAT_RESERVE10	,//	( 1295 + BAT No. * 16 ) ����10
    PID_BAT_MAX_NUM	//
};

enum enBSU02Bid
{
	BID_BSU02_VOLT1					, // �����ѹ1
	BID_BSU02_VOLT2					, // �����ѹ2
	BID_BSU02_VOLT3					, // �����ѹ3
	BID_BSU02_VOLT4					, // �����ѹ4
	BID_BSU02_VOLT5					, // �����ѹ5
	BID_BSU02_VOLT6					, // �����ѹ6
	BID_BSU02_VOLT7					, // �����ѹ7
	BID_BSU02_VOLT8					, // �����ѹ8
	BID_BSU02_VOLT9					, // �����ѹ9
	BID_BSU02_VOLT10				, // �����ѹ10
	BID_BSU02_VOLT11				, // �����ѹ11
	BID_BSU02_VOLT12				, // �����ѹ12
    BID_BSU02_VOLT13				, // �����ѹ1
    BID_BSU02_VOLT14				, // �����ѹ2
    BID_BSU02_VOLT15				, // �����ѹ3
    BID_BSU02_VOLT16				, // �����ѹ4
    BID_BSU02_VOLT17				, // �����ѹ5
    BID_BSU02_VOLT18				, // �����ѹ6
    BID_BSU02_VOLT19				, // �����ѹ7
    BID_BSU02_VOLT20				, // �����ѹ8
    BID_BSU02_VOLT21				, // �����ѹ9
	BID_BSU02_VOLT22				, // �����ѹ10
	BID_BSU02_VOLT23				, // �����ѹ11
	BID_BSU02_VOLT24				, // �����ѹ12
    BID_BSU02_VOLT25				, // �����ѹ1
    BID_BSU02_VOLT26				, // �����ѹ2
    BID_BSU02_VOLT27				, // �����ѹ3
    BID_BSU02_VOLT28				, // �����ѹ4
    BID_BSU02_VOLT29				, // �����ѹ5
    BID_BSU02_VOLT30				, // �����ѹ6

	BID_BSU02_VOLT31				, // �����ѹ11
	BID_BSU02_VOLT32				, // �����ѹ12
    BID_BSU02_VOLT33				, // �����ѹ1
    BID_BSU02_VOLT34				, // �����ѹ2
    BID_BSU02_VOLT35				, // �����ѹ3
    BID_BSU02_VOLT36				, // �����ѹ4
    BID_BSU02_VOLT37				, // �����ѹ5
    BID_BSU02_VOLT38				, // �����ѹ6
    BID_BSU02_VOLT39				, // �����ѹ7
    BID_BSU02_VOLT40				, // �����ѹ8
    BID_BSU02_VOLT41				, // �����ѹ9
	BID_BSU02_VOLT42				, // �����ѹ10
	BID_BSU02_VOLT43				, // �����ѹ11
	BID_BSU02_VOLT44				, // �����ѹ12
    BID_BSU02_VOLT45				, // �����ѹ1
    BID_BSU02_VOLT46				, // �����ѹ2
    BID_BSU02_VOLT47				, // �����ѹ3
    BID_BSU02_VOLT48				, // �����ѹ4
    BID_BSU02_VOLT49				, // �����ѹ4
	BID_BSU02_VOLT50				, // �����ѹ10
	BID_BSU02_VOLT51				, // �����ѹ11
	BID_BSU02_VOLT52				, // �����ѹ12
    BID_BSU02_VOLT53				, // �����ѹ1
    BID_BSU02_VOLT54				, // �����ѹ2
    BID_BSU02_VOLT55				, // �����ѹ3
    BID_BSU02_VOLT56				, // �����ѹ4
    BID_BSU02_VOLT57				, // �����ѹ5
    BID_BSU02_VOLT58				, // �����ѹ6
    BID_BSU02_VOLT59				, // �����ѹ7
    BID_BSU02_VOLT60				, // �����ѹ8
    BID_BSU02_VOLT61				, // �����ѹ9
	BID_BSU02_VOLT62				, // �����ѹ10
	BID_BSU02_VOLT63				, // �����ѹ11
	BID_BSU02_VOLT64				, // �����ѹ12

	BID_BSU02_LEAK_VOLT				, // ©������ѹֵ
	BID_BSU02_HALL_VOLT				, // ������ѹֵ
	BID_BSU02_BAL_NO				, // �����
	BID_BSU02_BAL_CURR				, // �������
	BID_BSU02_TEMP1					, // �����¶�1
	BID_BSU02_TEMP2					, // �����¶�2
	BID_BSU02_TEMP3					, // �����¶�3
	BID_BSU02_TEMP4					, // �����¶�1
	BID_BSU02_TEMP5					, // �����¶�2
	BID_BSU02_TEMP6					, // �����¶�2
	BID_BSU02_TEMP7					, // �����¶�3
	BID_BSU02_TEMP8					, // �����¶�1
	BID_BSU02_TEMP9					, // �����¶�2
    BID_BSU02_TEMP10				, // �����¶�3
    BID_BSU02_TEMP11				, // �����¶�1
    BID_BSU02_TEMP12				, // �����¶�2
    BID_BSU02_TEMP13				, // �����¶�3
    BID_BSU02_TEMP14				, // �����¶�1
    BID_BSU02_TEMP15				, // �����¶�2
    BID_BSU02_TEMP16				, // �����¶�1
    BID_BSU02_TEMP17				, // �����¶�2
    BID_BSU02_TEMP18				, // �����¶�3
    BID_BSU02_TEMP19				, // �����¶�1
    BID_BSU02_TEMP20				, // �����¶�2
	BID_BSU02_STATE					, // ״̬
	BID_BSU02_SWVER					, // ����汾��
	BID_BSU02_COUNT					, // ����汾��
	BID_BSU02_VOLT1_COE				, // У׼ϵ��1
	BID_BSU02_VOLT2_COE				, // У׼ϵ��2
	BID_BSU02_VOLT3_COE				, // У׼ϵ��3
	BID_BSU02_VOLT4_COE				, // У׼ϵ��4
	BID_BSU02_VOLT5_COE				, // У׼ϵ��5
	BID_BSU02_VOLT6_COE				, // У׼ϵ��6
	BID_BSU02_VOLT7_COE				, // У׼ϵ��7
	BID_BSU02_VOLT8_COE				, // У׼ϵ��8
	BID_BSU02_VOLT9_COE				, // У׼ϵ��9
	BID_BSU02_VOLT10_COE			, // У׼ϵ��10
	BID_BSU02_VOLT11_COE			, // У׼ϵ��11
	BID_BSU02_VOLT12_COE			, // У׼ϵ��12
	BID_BSU02_LEAK_ZERO				, // ©�������
	BID_BSU02_HALL_ZERO				, // �������
	BID_BSU02_SECOND				, // ��������
	BID_BSU02_AH1					, // ÿ�����
	BID_BSU02_AH2					, // ÿ�����
	BID_BSU02_MAX_NUM
};

enum enBTSBid
{
    BID_BTS_TEMP1               , // �¶�1
    BID_BTS_TEMP2               , // �¶�2
    BID_BTS_TEMP3               , // �¶�3
    BID_BTS_TEMP4               , // �¶�4
    BID_BTS_TEMP5               , // �¶�5
    BID_BTS_TEMP6               , // �¶�6
    BID_BTS_TEMP7               , // �¶�7
    BID_BTS_TEMP8               , // �¶�8
    BID_BTS_TEMP9               , // �¶�9
    BID_BTS_TEMP10				, // �¶�10
    BID_BTS_TEMP11				, // �¶�11
    BID_BTS_TEMP12				, // �¶�12
    BID_BTS_TEMP13				, // �¶�13
    BID_BTS_TEMP14				, // �¶�14
    BID_BTS_TEMP15				, // �¶�15
    BID_BTS_TEMP16				, // �¶�16
    BID_BTS_TEMP17				, // �¶�17
    BID_BTS_TEMP18				, // �¶�18
    BID_BTS_TEMP19				, // �¶�19
    BID_BTS_TEMP20				, // �¶�20
    BID_BTS_TEMP21				, // �¶�21
    BID_BTS_TEMP22				, // �¶�22
    BID_BTS_TEMP23				, // �¶�23
    BID_BTS_TEMP24				, // �¶�24
    BID_BTS_TEMP25				, // �¶�25
    BID_BTS_TEMP26				, // �¶�26
    BID_BTS_TEMP27				, // �¶�27
    BID_BTS_TEMP28				, // �¶�28
    BID_BTS_TEMP29				, // �¶�29
    BID_BTS_TEMP30				, // �¶�30
    BID_BTS_TEMP31				, // �¶�31
    BID_BTS_TEMP32				, // �¶�32
    BID_BTS_TEMP33				, // �¶�33
    BID_BTS_TEMP34				, // �¶�34
    BID_BTS_TEMP35				, // �¶�35
    BID_BTS_TEMP36				, // �¶�36
    BID_BTS_TEMP37				, // �¶�37
    BID_BTS_TEMP38				, // �¶�38
    BID_BTS_TEMP39				, // �¶�39
    BID_BTS_TEMP40				, // �¶�40

    BID_BTS_INSIDE_TEMP         , // �ڲ��¶�
    BID_BTS_BEAT                , // ����ֵ

    BID_BTS_DEV_TYPE            , // �豸����
    BID_BTS_SOFT_VER            , // ����汾
    BID_BTS_PRO_VER             , // Э��汾

    BID_BTS_MAX_NUM
};

#define BID_BSU_START		0
#define BID_BSU_SIZE		BID_BSU02_MAX_NUM
#define BID_MAKE_BSU_BID(nBsu, bid)	\
    (BID_BSU_START + BID_BSU02_MAX_NUM * (nBsu) + (bid))

enum enCurrentTree      //��ǰ��ͼѡ��
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

enum enCurrentPage      //��ǰҳ
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

////////////////////Operate///////������¼
enum enOperateLog
{
	OL_LOGIN,
	OL_CAN_OPEN,
	OL_CAN_RESERT,
	OL_CAN_CLOSE,
	OL_LOG_NUM
};

////////////////Alarm
// ���澯����
#define MAX_ALARM_LEVEL		4

// �澯������󳤶�
#define ALM_NAME_STR_LEN			12
#define ALM_FULL_NAME_STR_LEN		17

#define ALM_TIME_STRING_LEN			(sizeof("2012-01-23 12:34:56") - 1)

// ���ǰ�澯����
#define MAX_ACTV_ALM_NUM			50

// �����ʷ�澯����
#define MAX_HIST_ALM_NUM			60

// ��ʷ�澯������EEPROM��λ��
#define EEP_HIST_ALM_FLAG_POS		6
#define EEP_HIST_ALM_FLAG_VAL		0x55AA

// ����ֻ��Ҫһ���ֽ�
#define EEP_POS_HIST_ALM_NUM		8
#define EEP_POS_HIST_ALM_TAIL		9

#define EEP_POS_HIST_ALM_START		0x3000


// �澯����

/************************************************************************/
// �������£�
//		aaaaaaaa vvvv tttt pppppppp pppppppp
//	���У�
//		a	8λ����ʾ�澯���ͣ����ɱ�ʾ256�ֲ�ͬ�ĸ澯
//		v	4λ����ʾ�澯ֵ���澯����
//		t	4λ����ʾ�豸���ͣ�0-Sys, 1-Bat, 2-Cell, 3-BSU
//		p	16λ����ʾ�豸λ�ã��μ�ST_BSU_CELL_POSITION
//
//////////////////////////////////////////////////////////////////////////
//	ϵͳ��	aaaaaaaa vvvv 0000 0000 0000 00000000 
//	�����  aaaaaaaa vvvv 0001 batt bsubsu cccccc
//	������	aaaaaaaa vvvv 0010 batt bsubsu cccccc
//	BSU��	aaaaaaaa vvvv 0011 batt bsubsu cccccc
/************************************************************************/
typedef UINT32 ALARM_CODE;

enum enAlarmEquipType           //�澯��������
{
	AET_SYS,
	AET_BAT,
	AET_BSU,
	AET_CELL,
	AET_BREAK,
};

typedef struct stAlarmCode      //�澯����ṹ��
{
	// �ṹ�嶨���У�ǰ���ǵ�λ�������Ǹ�λ��С��ģʽ��
	UINT16 uiEquipPosi;
	UINT16 uiEquipType	: 4;
	UINT16 uiAlarmLevel	: 4;
	UINT16 uiAlarmId	: 8;
}ST_ALARM_CODE;

typedef union unAlarmCode       //�澯����������
{
	ST_ALARM_CODE stBit;
	UINT32 uiAll;
}UN_ALARM_CODE;

// �澯ʱ��

#define ALARM_TIME_YEAR_FROM	2000    //��ʼʱ��2000��

typedef struct stAlarmTime  //�澯ʱ��ṹ��
{
	UINT16 Year		: 6;	// ��2000�꿪ʼ�㣬�ɱ�ʾ2000~2064��
	UINT16 Month	: 4;	// 1-12��
	UINT16 Day		: 5;	// 1-31
	UINT16 Hour		: 5;	// 0-23
	UINT16 Min		: 6;	// 0-59
	UINT16 Sec		: 6;	// 0-59
}ST_ALARM_TIME;


// ��ǰ�澯
typedef struct stActiveAlarm_t
{
	ALARM_CODE	uiAlarmCode;
	ST_ALARM_TIME stStartTime;			/*�澯���ֵ�ʱ��*/
}ST_ACTV_ALARM;

// ��ʷ�澯
typedef struct stHistAlarm_t
{
	ALARM_CODE	uiAlarmCode;
	ST_ALARM_TIME stStartTime;			/*�澯���ֵ�ʱ��*/
	ST_ALARM_TIME stEndTime;			/*�澯������ʱ��*/
}ST_HIST_ALARM;


// ��ǰ�澯��¼
typedef struct stActvAlmRecord
{
	ST_ACTV_ALARM stAlm;
    UINT16 uiPrev;          //��һ��
    UINT16 uiNext;          //��һ��
}ST_ACTV_ALM_RECORD;

// ���е�ǰ�澯
typedef struct stAllActvAlm
{
	// ��0��Ԫ����������ͷ���
	ST_ACTV_ALM_RECORD astAlarms[MAX_ACTV_ALM_NUM + 1];

	UINT16 uiFree;
	UINT16 uiNum;
}ST_ALL_ACTV_ALM;

// ������ʷ�澯
typedef struct stAllHistAlm
{
	ST_HIST_ALARM astAlarms[MAX_HIST_ALM_NUM];
	UINT16 uiNum;		// �ܹ��ж�����
	UINT16 uiTail;		// ���һ����λ�ã������µ�һ��

}ST_ALL_HIST_ALM;


typedef struct stAlarmData
{
	UINT16 uiLevel		: 4;
	UINT16 uiTimes		: 8;
	UINT16 uiOldLevel	: 4;
}ST_ALARM_DATA;


// �澯����

typedef enum enAlarmMode
{
	OVER_TEST,
	UNDER_TEST,
	DIFF_TEST,
	BOOL_TEST

}EN_ALARM_MODE;

enum enParaType     //��������
{
    PARA_NORMAL,    //��ͨ����
    PARA_X10,       //10������
};

typedef struct stAlarmConfig    //�澯���ýṹ��
{
    UINT16 vid1;			//Ҫ�жϵ��ź�VID
    UINT16 vid2;            //�澯��׼VID

	UINT8 uiAlmId;			//�澯ID
	UINT8 uiAlmMode;		//�澯��ʽ

	UINT8 uiParaType;

}ST_ALARM_CONFIG;

#define	SYS_ALARM_NUM			8		/*ϵͳ��صĸ澯����*/
#define	BAT_ALARM_NUM			14		/*�������صĸ澯����*/
#define	CELL_ALARM_NUM			4		/*��������صĸ澯����*/
#define	BREAK_ALARM_NUM			2
#define	BSU_ALARM_NUM			2		/*�ɼ�ģ����صĸ澯����*/

// !!�澯�����ַ������Ϊ ALM_NAME_STR_LEN(12)!!

/////////////////Alarm

/*======================================================================*/
// �������Ͷ���
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
// CELLλ����Ϣ
//
/************************************************************************/

typedef struct stBsuCellPosition_t
{
	UINT16 uiCellNo		: 6;	// ������BSU�е���ţ�0~63
	UINT16 uiBsuNo		: 6;	// ����������ţ�0~BSU_MAX_NUM-1
	UINT16 uiBatNo		: 4;	// �������ڵ����ı��: 0~BAT_MAX_NUM-1
}ST_BSU_CELL_POSITION;

typedef union unBsuCellPosition_t
{
	ST_BSU_CELL_POSITION stBit;
	UINT16 uiAll;
}UN_BSU_CELL_POSITION;


/************************************************************************/
//
// CELL״̬��Ϣ
//
/************************************************************************/

typedef struct stBsuCellStatus_t
{
	UINT16 uiVbkCount		: 6;	// ��ѹ���߼���
	UINT16 uiVoltBreak		: 1;	// ��ѹ����
	UINT16 uiVbkChange		: 1;	// ��ѹ����״̬�仯

	UINT16 uiTbkCount		: 6;	// �¶ȶ��߼���
	UINT16 uiTempBreak		: 1;	// �¶ȶ���
	UINT16 uiTbkChange		: 1;	// �¶ȶ���״̬�仯
}ST_BSU_CELL_STATUS;

typedef union unBsuCellStatus_t
{
	ST_BSU_CELL_STATUS stBit;
	UINT16 uiAll;
}UN_BSU_CELL_STATUS;

//*****************BSU����****************
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
//*****************BSU����****************

//*****************BTS����****************
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
//*****************BTS����****************

typedef struct stCanJ1939Packet
{
	UINT32 uiFrameId;
	UINT32 auiVidCfg[8];
	BOOL bNetworkOrder;		// �����ֽ��򣬼����ģʽ���ȴ����ֽ�
	UINT16 uiSendPeriod;	// �������ڣ���λms
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

struct tagCanUnitRealData    //���ͻ��߽��ܵ���ϸ֡��Ϣ
{
	UINT32 m_uBMUId ;         //֡ID
	BYTE m_BData[8];     //8���ֽ�����
	int m_bSendOrRece;   //�Ƿ���֡���ǽ���֡  true�Ƿ���֡��false�ǽ���֡
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

	_US  m_usBmsVidSys[VID_SYS_MAX_NUM];                //ֵ
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

	_US  m_usBmsVidBsuCell[VID_BSU_CELL_MAX_NUM];                //ֵ
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

	_US  m_usBmsVidBsu[VID_BSU_HEAD_MAX_NUM];                //ֵ
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
	_US  m_usBmsVidBat[VID_BAT_MAX_NUM];                //ֵ
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
	_US  m_usBmsVidVcu[VID_VCU_MAX_NUM];                //ֵ
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
	_US  m_usBmsVidChr[VID_CHR_MAX_NUM];                //ֵ
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
	_US  m_usBmsPidSys[PID_SYS_MAX_NUM];                //ֵ
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
                    m_usBmsPidBsu[j][i] = 0xFFFF;//��ѹ���¶�����ͨ�����ʼ��Ϊ0xFFFF
                }
                else
                {
                    m_usBmsPidBsu[j][i] = 0;
                }
			}
		}
	}    
	_US  m_usBmsPidBsu[BMS_BSU_NUMBER][PID_BSU_MAX_NUM];                //ֵ
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
	_US  m_usBmsPidAlarm[ALM_MAX_NUM][ALM_PARA_MAX_NUM];                //ֵ
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
	_US  m_usBmsPidBat[BMS_BAT_NUMBER][PID_BAT_MAX_NUM];                //ֵ
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
    int m_iCommunite;               //��¼ͨѶ���������5�α�ʾͨѶ��
    bool m_bisBMUConnect;           //��¼ͨѶ����״̬
	tagCanBMSVid m_tagBmsVid;
	tagCanBMSPid m_tagBmsPid;
	UN_BSU02_DATA m_unBSU02Data;
    UN_BTS_DATA m_unBTSData;
	BYTE m_abyBytePara[PID_BYTE_MAX_NUM];

    //���ؼ��������͵�ѹ���¶�
    int m_nMaxCell, m_nMinCell, m_nMaxTemp, m_nMinTemp;
    int m_nCellDiff, m_nTempDiff;
    UN_BSU_CELL_POSITION m_unMaxVPosi;
    UN_BSU_CELL_POSITION m_unMinVPosi;
    UN_BSU_CELL_POSITION m_unMaxTPosi;
    UN_BSU_CELL_POSITION m_unMinTPosi;

    //VID
    _US get_usBmsVidSys(int vid_sys_para)//��ȡϵͳvid����
    {
        return m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[vid_sys_para];
    }

    void set_usBmsVidSys(_US BmsVidSys, int vid_sys_para)//����ϵͳvid����
    {
        m_tagBmsVid.m_tagBmsVidSys.m_usBmsVidSys[vid_sys_para] = BmsVidSys;
    }

    _US get_usBmsVidBsuHead(int vid_bsu_num, int vid_bsu_head_para)//��ȡ�ӿػ���vid����
    {
        return m_tagBmsVid.m_tagBmsVidBsu[vid_bsu_num].m_usBmsVidBsu[vid_bsu_head_para];
    }

    void set_usBmsVidBsuHead(_US BmsVidBsuHead, int vid_bsu_num, int vid_bsu_head_para)//���ôӿػ���vid����
    {
        m_tagBmsVid.m_tagBmsVidBsu[vid_bsu_num].m_usBmsVidBsu[vid_bsu_head_para] = BmsVidBsuHead;
    }

    _US get_usBmsVidBsuCell(int vid_bsu_num, int vid_bsu_cell_num, int vid_bsu_cell_para)//��ȡ�ӿص���vid����
    {
        return m_tagBmsVid.m_tagBmsVidBsu[vid_bsu_num].m_tagBmsVidBsuCell[vid_bsu_cell_num].m_usBmsVidBsuCell[vid_bsu_cell_para];
    }

    void set_usBmsVidBsuCell(_US BmsVidBsuCell, int vid_bsu_num, int vid_bsu_cell_num, int vid_bsu_cell_para)//���ôӿص���vid����
    {
        m_tagBmsVid.m_tagBmsVidBsu[vid_bsu_num].m_tagBmsVidBsuCell[vid_bsu_cell_num].m_usBmsVidBsuCell[vid_bsu_cell_para] = BmsVidBsuCell;
    }

    _US get_usBmsVidBat(int bat_num, int vid_bat_para)//��ȡ�����vid����
    {
        return m_tagBmsVid.m_tagBmsVidBat[bat_num].m_usBmsVidBat[vid_bat_para];
    }

    void set_usBmsVidBat(_US BmsVidBat, int bat_num, int vid_bat_para)//���õ����vid����
    {
        m_tagBmsVid.m_tagBmsVidBat[bat_num].m_usBmsVidBat[vid_bat_para] = BmsVidBat;
    }

    _US get_usBmsVidBatCell(int bat_num, int bat_cell_num)//��ȡ����鵥��
    {
        return m_tagBmsVid.m_tagBmsVidBat[bat_num].m_usBmsVidBatCell[bat_cell_num];
    }

    void set_usBmsVidBatCell(_US BmsVidBatCell, int bat_num, int bat_cell_num)//���õ���鵥��
    {
        m_tagBmsVid.m_tagBmsVidBat[bat_num].m_usBmsVidBatCell[bat_cell_num] = BmsVidBatCell;
    }

    _US get_usBmsVidVcu(int vid_vcu_para)//��ȡ����������vid����
    {
        return m_tagBmsVid.m_tagBmsVidVcu.m_usBmsVidVcu[vid_vcu_para];
    }

    void set_usBmsVidVcu(_US BmsVidVcu, int vid_vcu_para)//��������������vid����
    {
        m_tagBmsVid.m_tagBmsVidVcu.m_usBmsVidVcu[vid_vcu_para] = BmsVidVcu;
    }

    _US get_usBmsVidChr(int vid_chr_para)//��ȡ�ַ���vid����
    {
        return m_tagBmsVid.m_tagBmsVidChr.m_usBmsVidChr[vid_chr_para];
    }

    void set_usBmsVidChr(_US BmsVidChr, int vid_chr_para)//�����ַ���vid����
    {
        m_tagBmsVid.m_tagBmsVidChr.m_usBmsVidChr[vid_chr_para] = BmsVidChr;
    }

    //PID
    _US get_usBmsPidSys(int pid_sys_para)//��ȡϵͳpid����
    {
        return m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[pid_sys_para];
    }

    void set_usBmsPidSys(_US BmsPidSys, int pid_sys_para)//����ϵͳpid����
    {
        m_tagBmsPid.m_tagBmsPidSys.m_usBmsPidSys[pid_sys_para] = BmsPidSys;
    }

    _US get_usBmsPidBsu(int bsu_num, int pid_bsu_para)//��ȡ�ӿ�pid����
    {
        return m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[bsu_num][pid_bsu_para];
    }

    void set_usBmsPidBsu(_US BmsPidBsu, int bsu_num, int pid_bsu_para)//���ôӿ�pid����
    {
        m_tagBmsPid.m_tagBmsPidBsu.m_usBmsPidBsu[bsu_num][pid_bsu_para] = BmsPidBsu;
    }

    _US get_usBmsPidAlarm(int alm_num, int pid_alm_para)//��ȡ�澯pid����
    {
        return m_tagBmsPid.m_tagBmsPidAlarm.m_usBmsPidAlarm[alm_num][pid_alm_para];
    }

    void set_usBmsPidAlarm(_US BmsPidAlarm, int alm_num, int pid_alm_para)//���ø澯pid����
    {
        m_tagBmsPid.m_tagBmsPidAlarm.m_usBmsPidAlarm[alm_num][pid_alm_para] = BmsPidAlarm;
    }

    _US get_usBmsPidBat(int bat_num, int pid_bat_para)//��ȡ�����pid����
    {
        return m_tagBmsPid.m_tagBmsPidBat.m_usBmsPidBat[bat_num][pid_bat_para];
    }

    void set_usBmsPidBat(_US BmsPidBat, int bat_num, int pid_bat_para)//���õ����pid����
    {
        m_tagBmsPid.m_tagBmsPidBat.m_usBmsPidBat[bat_num][pid_bat_para] = BmsPidBat;
    }

    //BSU02
    DB_VALUE_T get_atArrayData(int bid)//��ȡbsu02���Բ�����������
    {
        return m_unBSU02Data.atArrayData[bid];
    }

    void set_atArrayData(DB_VALUE_T ArrayData, int bid)//����bsu02���Բ�����������
    {
        m_unBSU02Data.atArrayData[bid] = ArrayData;
    }

    DB_VALUE_T get_stBsu02Data(int bsu_num, int bid_bsu02_para)////��ȡbsu02��bid����
    {
        return m_unBSU02Data.stStructData.aatBsu02AllData[bsu_num].aatBsu02Data[bid_bsu02_para];
    }

    void set_stBsu02Data(DB_VALUE_T Bsu02Data, int bsu_num, int bid_bsu02_para)////��ȡbsu02��bid����
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
	int m_SendNum;                 //���ͼ��Σ�Ϊ-1��ʾѭ��һֱ��	
};



extern stControlStringEx g_stParabmsVidSys[VID_SYS_MAX_NUM];
extern QString GetLocalTime(tagSystemTime *st);
extern QString GetstrTime();
extern QString TakeOutReturn(QString str);
extern QString GetWorkPath(void);
extern QString GetFileName(QString strExp);
extern bool GetDataBit(_US usData, _US usPos);   //����usData�ĵ�usPosλ��0����1
extern float StrToF(QString str);
extern int HexStrToI(QString str);
extern QString FloatToStr(enParameterDisplayFormat disFormat, float fData, int iNumOfZero);
extern bool FindFile(QString path);
extern void AutoRemoveFaultFiles(void);
extern void AutoRemoveRunParaFiles(void);
#endif // PUBLIC_H
