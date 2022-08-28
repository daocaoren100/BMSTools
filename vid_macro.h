// This file is created by excel VBA
// Version : 1000
// Date    : 2014-2-14 ���� 9:36:45
// Author  : FXS

#ifndef VID_MACRO_H
#define VID_MACRO_H



enum enSYSVid
{
    VID_SYS_NOT_USED                             , // ��������
    VID_SYS_HW_VER                               , // CPU��Ӳ���汾
    VID_SYS_BASE_BOARD_VER                       , // ADUC����汾
    VID_SYS_SW_VER                               , // ����汾
    VID_SYS_LIB_VER                              , // ������汾
    VID_SYS_DISP_VER                             , // ��ʾ�汾
    VID_SYS_SW_SUB_VER                           , // �����汾(Ԥ��)
    VID_SYS_TM_YEAR                              , // ϵͳʱ�䣺��
    VID_SYS_TM_MONTH                             , // ��
    VID_SYS_TM_DAY                               , // ��
    VID_SYS_TM_HOUR                              , // ʱ
    VID_SYS_TM_MIN                               , // ��
    VID_SYS_TM_SEC                               , // ��
    VID_SYS_XX                                   , // 
    VID_SYS_YY                                   , // 
    VID_SYS_MAIN_CYCLES_PER_SEC                  , // ÿ����ѭ������
	VID_SYS_RUN_PERIOD                           , // ��Ȧ����  [ mS ]
    VID_SYS_MAX_PERIOD                           , // ��ѭ�������  [ mS ]
    VID_SYS_LAST_ERR_NO                          , // ��������  [ BMU���������� ]
    VID_SYS_WORK_MODE                            , // ϵͳ����ģʽ  [ 0=����������1=��װģʽ ]
    VID_SYS_ACC_STATUS                           , // ACC�ź�����״̬
    VID_SYS_TO_SUICIDE                           , // ϵͳ׼����ɱʽ�ϵ�
    VID_SYS_VOLT                                 , // ϵͳ�ۺϵ�ѹ
    VID_SYS_CURR                                 , // ϵͳ�ۺϵ���
    VID_SYS_TEMP                                 , // ϵͳ�ۺ��¶�
    VID_SYS_SOC                                  , // ϵͳ�ۺ�SOC
    VID_SYS_BOOT_VER                             , // BOOT�汾
    VID_SYS_LEFT_SW_VER                          , // ��CPU����汾
    VID_SYS_RIGHT_SW_VER                         , // ��CPU����汾
    VID_SYS_MOST_SEVERE_LEVEL                    , // ϵͳ�����ظ澯����
    VID_SYS_ACTV_ALM_NUM                         , // ��澯����
    VID_SYS_HIST_ALM_NUM                         , // ��ʷ�澯����
    VID_SYS_ALM_L1_NUM                           , // һ����澯����
    VID_SYS_ALM_L2_NUM                           , // ������澯����
    VID_SYS_ALM_L3_NUM                           , // ������澯����
    VID_SYS_ALM_L4_NUM                           , // �ļ���澯����
    VID_SYS_RUN_STATUS                           , // ϵͳ����״̬
    VID_SYS_DI1_STATUS                           , // DI����״̬  [ 0=�Ͽ���1=�պ� ]
    VID_SYS_DI2_STATUS                           , // 
    VID_SYS_DI3_STATUS                           , // 
    VID_SYS_DI4_STATUS                           , // 
    VID_SYS_DI5_STATUS                           , // 
    VID_SYS_DI6_STATUS                           , // 
    VID_SYS_DI7_STATUS                           , // 
    VID_SYS_DI8_STATUS                           , // 
    VID_SYS_RELAY1_STATUS                        , // �̵������״̬  [ 0=�Ͽ���1=�պ� ]
    VID_SYS_RELAY2_STATUS                        , // 
    VID_SYS_RELAY3_STATUS                        , // 
    VID_SYS_RELAY4_STATUS                        , // 
    VID_SYS_RELAY5_STATUS                        , // 
    VID_SYS_RELAY6_STATUS                        , // 
    VID_SYS_RELAY7_STATUS                        , // 
    VID_SYS_RELAY8_STATUS                        , // BSU��ԴԤ��̵���״̬
    VID_SYS_RELAY1_REASON                        , // �̵����Ͽ�ԭ��  [ 0=�պϣ�1=�澯������������ԭ�� ]
    VID_SYS_RELAY2_REASON                        , // 
    VID_SYS_RELAY3_REASON                        , // 
    VID_SYS_RELAY4_REASON                        , // 
    VID_SYS_RELAY5_REASON                        , // 
    VID_SYS_RELAY6_REASON                        , // 
    VID_SYS_RELAY7_REASON                        , // 
    VID_SYS_RELAY8_REASON                        , // 
    VID_SYS_AD_GND_CODE							, // ADͨ����ֵ: ��Ե�ɼ���
    VID_SYS_AD_PRE_VOLT_CODE						, // Ԥ���ѹ
    VID_SYS_AD_BUS_VOLT_CODE					, // ���ĸ���ܵ�ѹ
    VID_SYS_AD_NBUS_VOLT_CODE					, // ��ĸ�ߵ�ѹ
    VID_SYS_AD_CODE5							, // ĸ���ܵ�ѹ2
    VID_SYS_AD_CODE6							, // ��ĸ�ߵ�ѹ2
    VID_SYS_AD_HALL_CODE						, // ��������
    VID_SYS_AD_SHUNT_CODE						, // ����������
    VID_SYS_BUS_VOLT                             , // ���ĸ���ܵ�ѹ  [ 0.1V ]
    VID_SYS_PBUS_VOLT                            , // ��ĸ�ߵ�ѹ  [ 0.1V ]
    VID_SYS_NBUS_VOLT                            , // ��ĸ�ߵ�ѹ  [ 0.1V ]
    VID_SYS_PBUS_RES                             , // ��ĸ�ߵ���  [ 0.1K�� ]
    VID_SYS_NBUS_RES                             , // ��ĸ�ߵ���  [ 0.1K�� ]
    VID_SYS_LEAK_CURR                            , // ϵͳ©����  [ 0.1mA ]
    VID_SYS_PRE_BUS_VOLT                         , // Ԥ���ѹ  [ 0.1V ]
    VID_SYS_CURR1_VOLT                           , // ����ͨ��1�ĵ�ѹ  [ mV ]
    VID_SYS_SHUNT_VOLT                           , // ����ͨ��2�ĵ�ѹ  [ 0.01mV ]
    VID_SYS_CURR1                                , // ����ͨ��1�ĵ���  [ 0.1A ]
    VID_SYS_CURR2                                , // ����ͨ��2�ĵ���  [ 0.1A ]
    VID_SYS_POWER_VOLT                           , // ������Դ��ѹ  [ 0.1V ]
    VID_SYS_BOARD_TEMP                           , // �����¶ȴ������¶� [ 0.1�� ]
    VID_SYS_OUT_TEMP							 , // �ⲿ�¶ȴ������¶� [ 0.1�� ]
	VID_SYS_LEM_VOLT2                            , // LEMͨ��2��ѹ
	VID_SYS_LEM_CURR                             , // LEM������ĵ���  [ 0.1A ]
    VID_SYS_LEM_CODE                             , // LEMͨ����ֵ
    VID_SYS_ONLINE_BSU_NUM                       , // ����BSU����
	VID_SYS_RATED_VOLT                           , // ��ض��ѹ  [ V ]
	VID_SYS_LIFE                                 , // ������Ϣ
	VID_SYS_GZ_FUNC_VER							, // ��װ���Թ��ܰ汾
    VID_SYS_PRECHARGE_FAIL                       , // Ԥ��ʧ��״̬  [ 0=������1=ʧ�� ]
    VID_SYS_MAX_VOLT                             , // ��ߵ�ѹֵ  [ mV ]
    VID_SYS_MAXV_POSI                            , // ��ߵ�ѹλ��
    VID_SYS_MIN_VOLT                             , // ��͵�ѹֵ  [ mV ]
    VID_SYS_MINV_POSI                            , // ��͵�ѹλ��
    VID_SYS_MAX_TEMP                             , // ����¶�ֵ  [ 0.1�� ]
    VID_SYS_MAXT_POSI                            , // ����¶�λ��
    VID_SYS_MIN_TEMP                             , // ����¶�ֵ  [ 0.1�� ]
    VID_SYS_MINT_POSI                            , // ����¶�λ��
    VID_JYM_STATUS                               , // ��Եģ������״̬
    VID_JYM_OFFLINE                              , // ��Եģ������״̬  [ 0=���ߣ�1=���� ]
    VID_JYM_OPEN_BAT_VOLT                        , // ���ŶϿ�ʱ����ܵ�ѹ  [ 0.1V ]
    VID_JYM_OPEN_NBUS_VOLT                       , // ���ŶϿ�ʱ��ĸ�ߵ�ѹ  [ 0.1V ]
    VID_JYM_CLOSE_UP_NBUS_VOLT                   , // ���űպ�ʱ��ĸ�ߵ�ѹ  [ 0.1V ]
    VID_JYM_CLOSE_DN_NBUS_VOLT                   , // ���űպ�ʱ��ĸ�ߵ�ѹ  [ 0.1V ]
    VID_SYS_NBUS_VOLT_FINAL		                 , // ���������������ʵʱ��ĸ�ߵ�ѹ  [ 0.1V ]
    VID_SYS_BUS_VOLT1							 , // �����ѹ1
    VID_SYS_BUS_VOLT2		                     , // �����ѹ2
    VID_SYS_NBUS_VOLT1                           , // ��ĸ�ߵ�ѹ1
    VID_SYS_NBUS_VOLT2                           , // ��ĸ�ߵ�ѹ2
    VID_GPRS_CONTROL                             , // GPRS����
    VID_GPRS_RUN_STATUS                          , // GPRS����״̬
    VID_GPRS_SIG_STRENGTH                        , // GPRS�ź�ǿ��
    VID_GPRS_CONNECT_STEP                        , // GPRS���Ӳ���
    VID_GPRS_ONLINE_TIME                         , // GPRS����ʱ��  [ Min ]
    VID_GPRS_SEND_NUM                            , // GPRS�������ݰ���Ŀ
    VID_GPRS_RECV_OK_NUM                         , // GPRS���յ�OK����Ŀ
    VID_GPRS_FLOW_COUNT_HI                       , // GPRS�������ֽ�
    VID_GPRS_FLOW_COUNT_LO                       , // GPRS�������ֽ�
    VID_GPRS_IMEI1                               , // GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI2                               , // GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI3                               , // GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI4                               , // GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI5                               , // GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI6                               , // GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI7                               , // GPRSģ��IMEI�ַ���
    VID_GPRS_IMEI8                               , // GPRSģ��IMEI�ַ���
    VID_GPRS_CCID1                               , // SIM��CCID�ַ���
    VID_GPRS_CCID2                               , // SIM��CCID�ַ���
    VID_GPRS_CCID3                               , // SIM��CCID�ַ���
    VID_GPRS_CCID4                               , // SIM��CCID�ַ���
    VID_GPRS_CCID5                               , // SIM��CCID�ַ���
    VID_GPRS_CCID6                               , // SIM��CCID�ַ���
    VID_GPRS_CCID7                               , // SIM��CCID�ַ���
    VID_GPRS_CCID8                               , // SIM��CCID�ַ���
    VID_GPRS_CCID9                               , // SIM��CCID�ַ���
    VID_GPRS_CCID10                              , // SIM��CCID�ַ���
    VID_GPRS_RESERVED1                           , // ����1
    VID_GPRS_ENABLE                          	 , // GPRS ʹ�ܿ���
    VID_GPRS_ERR_COUNT                           , // GPRS �������
    VID_GPRS_RESERVED4                           , // ����4
    VID_SYS_ALLOW_DSCH_CURR                      , // �������ŵ����  [ 0.1A ]
    VID_SYS_ALLOW_CHRG_CURR                      , // ������������  [ 0.1A ]
    VID_SYS_BM_STATE                             , // ��ع���״̬  [ 0=STOP, 1=INIT, 2=SELFTEST, 3=READY, 4=PRECHARGE, 5=RUN... ]
    VID_SYS_RESERVED_144                         , // ϵͳ���ϴ���1
    VID_SYS_RESERVED_145                         , // ϵͳ���ϴ���2
    VID_SYS_RESERVED_146                         , // ϵͳ���ϴ���3
    VID_SYS_RESERVED_147                         , // ϵͳ���ϴ���4
    VID_SYS_OCV_RESULT							 , // ��·��ѹ��λSOC���[ ����=�����룬1-100=��λ��� ]
    VID_SYS_JY_BRIDGE_MANUAL_CTRL				 , // ��Ե�����ֶ�����[ 0=�Զ�Ͷ�У�1=���Ͽ���2=�պ����ţ�3=�պ����ţ�4=���¶��պ� ]
    VID_SYS_USER_SET_SOC                         , // �û��ֶ�����SOC��ֵ
    VID_SYS_DEBUG_VAR1                           , // ���Ա���1
    VID_SYS_DEBUG_VAR2                           , // ���Ա���2
    VID_SYS_DEBUG_VAR3                           , // ���Ա���3
    VID_SYS_DEBUG_VAR4                           , // ���Ա���4
    VID_SYS_DEBUG_VAR5                           , // ���Ա���5
    VID_SYS_DEBUG_VAR6                           , // ���Ա���6
    VID_SYS_DEBUG_VAR7                           , // ���Ա���7
    VID_SYS_DEBUG_VAR8                           , // ���Ա���8
    VID_SYS_ALLOW_DSCH_POWER                     , // �������ŵ繦��  [ 0.1kW ]
    VID_SYS_ALLOW_CHRG_POWER                     , // ��������繦��  [ 0.1kW ]

    VID_SYS_RESERVED_161						, // DSCH CURR
    VID_SYS_RESERVED_162						, // CHRG CURR
	VID_SYS_RESERVED_163						, // DSCH POWER
    VID_SYS_RESERVED_164						, // CHRG POWER
    VID_SYS_RESERVED_165						, // 
    VID_SYS_RESERVED_166						, // 
    VID_SYS_RESERVED_167						, // 
    VID_SYS_RESERVED_168						, // 
    VID_SYS_RESERVED_169						, // 
    VID_SYS_RESERVED_170						, // 
    VID_SYS_RESERVED_171						, // 

	VID_SYS_RESERVED_172						, // 
    VID_SYS_RESERVED_173						, // 
    VID_SYS_RESERVED_174						, // 
    VID_SYS_RESERVED_175						, // 
    VID_SYS_RESERVED_176						, // 
    VID_SYS_RESERVED_177						, // 
    VID_SYS_RESERVED_178						, // 
    VID_SYS_RESERVED_179						, // 
    VID_SYS_RESERVED_180						, // 

	VID_SYS_CAN_SELF_TEST_RESULT                 , // CAN�Բ��Խ��  [ 0-δ��ʼ��1-������2+���� ]
    VID_SYS_USB_STATE                            , // USB״̬  [ 0=�ޣ�1=��ʹ�ã�<0=���� ]
    VID_SYS_LOG_PAGE                             , // �ڲ��洢д��ĵ�ǰҳ
    VID_SYS_LOG_POS                              , // �ڲ��洢д��ĵ�ǰҳ��λ��
	VID_SYS_OUT_TEMP2								, // (185) �ⲿ�¶�2�������¶� [ 0.1�� ]
    VID_SYS_CP_AMPLITUDE                         , // CP�����ֵ [ 0.1V ]
    VID_SYS_CP_PWM_FREQ                          , // CP����PWMƵ��  [ Hz ]
    VID_SYS_CP_PWM_DUTY_RATIO                    , // CP����PWMռ�ձ�  [ 0.1% ]
    VID_SYS_RELAY_FAN                            , // BMU���Ʒ��ȼ̵�������  [ 0���� ��������Ӧ�̵����� ]
    VID_SYS_VCU_MAIN_RELAY_CMD                   , // VCU����BMS�������̵���������  [ 0���պ� 1���Ͽ� ]
    VID_SYS_BSU_RELAY_STATUS                     , // BSU��Դ�̵���״̬  [ 0���պ� 1���Ͽ� ]
    VID_SYS_LOW_VOLT_STATUS						 , // ������ѹ̫�� [ 0=����, 1=������ѹ̫�� ]
	VID_SYS_ADUC_COMM_BREAK						, // ADUCͨ��ʧ�ܴ���
    VID_SYS_VCU_COMM_FAIL						, // VCUͨ�ų�ʱ
    VID_SYS_HIGH_VOLT_ABNORMAL					, // BMU��ѹ�쳣
    VID_SYS_MAXV_NO                              , // ��ߵ�ѹ�������
    VID_SYS_MINV_NO                              , // ��͵�ѹ�������
    VID_SYS_MAXT_NO                              , // ����¶ȵ������
    VID_SYS_MINT_NO                              , // ����¶ȵ������
    VID_SYS_MINUS_CURR                           , // �����������Ϊ�����ŵ�Ϊ����
    VID_SYS_AUX_FAIL_STATUS                      , // ����������ϼ���� [ 0=����, bit0,1=����ճ��,��·, bit2,3=����, bit4,5=���,bit6,7=���� ]

	VID_SYS_LEFT_CC_CODE                         , // 
    VID_SYS_LEFT_CC2_CODE                         , // 
    VID_SYS_LEFT_CP_CODE                         , // 
    VID_SYS_LEFT_ACC_CRG_CODE                         , // 
    VID_SYS_LEFT_RESERVED_206						 , // ����
    VID_SYS_LEFT_RESERVED_207                         , // 
    VID_SYS_BOARD_TEMP_CODE						 , // �����¶���ֵ
    VID_SYS_CP_ORIGINAL_VOLT					, // ԭʼCP��ѹ

    VID_SYS_CC_VOLT	                            , // ���CC��ѹ
    VID_SYS_CC2_VOLT                            , // ���CC2��ѹ
	VID_SYS_CP_VOLT								, // CP��ѹ
	VID_SYS_HALL_BREAK							, // ��������״̬

	VID_SYS_POWER_CODE,
	VID_SYS_CC_CODE,
	VID_SYS_CC2_CODE,
	VID_SYS_CP_CODE,
	VID_SYS_OUT_TEMP_CODE						,	// �ⲿ�¶Ȳ�������ֵ
	VID_SYS_OUT_TEMP_VOLT						,	// �ⲿ�¶Ȳ����ĵ�ѹ [ mV ]
	VID_SYS_BAL_ACTIVE_MODE						,	// �������⹤��ģʽ ����ֹ���ŵ磬��磩
	VID_SYS_BAL_ACTIVE_DISH_NUM					,	//	��������ŵ�ģ����
	VID_SYS_BAL_ACTIVE_CHRG_NUM					,	//	����������ģ����
	VID_SYS_BAL_ACTIVE_FAIL_NUM					,
	VID_SYS_PARA_FLAG							,	// �ָ�Ĭ�ϲ����ɹ�
	VID_SYS_ORIGINAL_CURR						, // ԭʼ������δ����ĵ�����	
	VID_SYS_FAST_CURR								, // (226) ���ٵ��������˲��� [ 0.1A ]
	VID_SYS_CURR_RESERVED_227						, // (227) 
	VID_SYS_CURR_RESERVED_228						, // (228) 
	VID_SYS_CURR_RESERVED_229						, // (229) 
	VID_SYS_PROTECT_FAIL,
	VID_SYS_CELL_PROTECT_UP,
	VID_SYS_CELL_PROTECT_DOWN,
	VID_SYS_RESERVED_233,
	VID_SYS_RESERVED_234,
	//VID_SYS_RESERVED_235							, // (235) 
	VID_SYS_OUT_71A_TEMP1							, // (235) ��71Aģ��ɼ����¶�1 (��HALL1)[ 0.1�� ]
	VID_SYS_RESERVED_236,
	VID_SYS_RESERVED_237,
	//VID_SYS_RESERVED_238							, // (238) 
	VID_SYS_OUT_71A_TEMP2							, // (238) ��71Aģ��ɼ����¶�2 (��HALL2)[ 0.1�� ]
	VID_SYS_CELL_NUM_PER_BAT					, // ÿ���ش���������
	VID_SYS_BSU_NUM_PER_BAT						, // ÿ���ص�BSU����
	VID_SYS_DIFF_VOLT							, // ϵͳѹ�� [ mV ]
	VID_SYS_DIFF_TEMP							, // ϵͳ�²� [ 0.1 ��]
	VID_SYS_AVG_VOLT							, // ƽ����ѹ [ mV ]
	VID_SYS_AVG_TEMP							, // ƽ���¶� [ 0.1 ��]
	VID_SYS_BATT_AH								, // ���������0.1AH��
	VID_SYS_CURR_INTEGRAL_COUNT						, // (246) ������������ [ ÿ���һ ]
	VID_SYS_CURR_INTEGRAL_SUM						, // (247) �������ֺ� [ 0.1AS ]
	VID_SYS_RESERVED_ALARM28					, // ���ø澯�����ڿ������
	VID_SYS_RESERVED_ALARM29					, // ���ø澯�����ڿ������
	VID_SYS_RESERVED_250,							// DCDC��ѹ

	VID_SYS_CMD_PARA1                            , // �����������1
	VID_SYS_CMD_PARA2                            , // �����������2
	VID_SYS_SELF_DEBUG_COMMAND                   , // �Ե��Գ�����������

//	VID_SYS_RESERVED_254,
//	VID_SYS_RESERVED_255,
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

    VID_SYS_MAX_NUM                              , // �����豸VID����  [ 256 + 80 ]

};


enum enBSUVid
{
    VID_BSU_ADDR                                 , // ��BSU�ĵ�ַ
    VID_BSU_POSI                                 , // BSUλ����Ϣ
    VID_BSU_SW_VER                               , // BSU����汾��
    VID_BSU_RUN_STATUS                           , // BSU����״̬
    VID_BSU_OFFLINE_STATUS                       , // BSU����״̬  [ 0=���ߣ�1=���� ]
    VID_BSU_TOTAL_VOLT                           , // ����CELL���ܵ�ѹ  [ 10mV ]
    VID_BSU_CURR                                 , // BSU�ɼ�����  [ 0.1A ]
    VID_BSU_START_CELL_INDEX                     , // ��һ�������ڵ�����е���� [ ��0��ʼ ]
    VID_BSU_BAL_CMD                              , // ��������������ر�
    VID_BSU_BAL_NO_SET                           , // ���õľ������
    VID_BSU_BAL_CURR_SET                         , // ���õľ������  [ 0.1A ]
    VID_BSU_CHN1_VOLT                            , // ����ͨ��1�ĵ�ѹ  [ mV ]
    VID_BSU_CHN2_VOLT                            , // ����ͨ��2�ĵ�ѹ  [ mV ]
    VID_BSU_BAL1_NO                              , // ��1·ʵ�ʾ������
    VID_BSU_BAL1_CURR                            , // ��1·ʵ�ʾ������  [ 0.1A ]
    VID_BSU_BAL2_NO                              , // ��2·ʵ�ʾ������
    VID_BSU_BAL2_CURR                            , // ��2·ʵ�ʾ������  [ 0.1A ]
    VID_BSU_FAN_CMD                              , // ��������  [ 0=�رգ�1=���� ]
    VID_BSU_HOT_CMD                              , // ��������  [ 0=�رգ�1=���� ]
    VID_BSU_FAN_STATUS                           , // ����״̬  [ 0=�رգ�1=���� ]
    VID_BSU_HOT_STATUS                           , // ����״̬  [ 0=�رգ�1=���� ]
    VID_BSU_BAL_FAIL                             , // �������
    VID_BSU_DI1_STATUS                           , // �ɽӵ�����1״̬
    VID_BSU_DI2_STATUS                           , // �ɽӵ�����2״̬
    VID_BSU_BTS_DI1_STATUS                       , // BTS��SW1״̬  [ 0=�������źţ�1=�������ź� ]
    VID_BSU_BTS_DI2_STATUS                       , // BTS��SW2״̬  [ 0=�������źţ�1=�������ź� ]

	VID_BSU_MAX_VOLT_01							, // BSU�ڲ���ߵ�ѹ
	VID_BSU_MAX_VOLT_01_NO						, // BSU�ڲ���ߵ�ѹλ��[0~N]
	VID_BSU_MAX_VOLT_02							, // BSU�ڲ��ڶ��ߵ�ѹ
	VID_BSU_MAX_VOLT_02_NO						, // BSU�ڲ��ڶ��ߵ�ѹλ��[0~N]

	VID_BSU_MIN_VOLT_01							, // BSU�ڲ���͵�ѹ
	VID_BSU_MIN_VOLT_01_NO						, // BSU�ڲ���͵�ѹλ��[0~N]
	VID_BSU_MIN_VOLT_02							, // BSU�ڲ��ڶ��͵�ѹ
	VID_BSU_MIN_VOLT_02_NO						, // BSU�ڲ��ڶ��͵�ѹλ��[0~N]

	VID_BSU_MAX_TEMP							, // BSU�ڲ�����¶�
	VID_BSU_MAX_TEMP_NO							, // BSU�ڲ�����¶�λ��[0~N]
	VID_BSU_MIN_TEMP							, // BSU�ڲ�����¶�
	VID_BSU_MIN_TEMP_NO							, // BSU�ڲ�����¶�λ��[0~N]

    VID_BSU_HEAD_MAX_NUM                         , // �����豸VID����  [ 38 ]

};


enum enBSU_CELLVid
{
    VID_BSU_CELL_POSI                            , // λ����Ϣ  [ �������ڵ�ء�BSU����Ϣ ]
    VID_BSU_CELL_UNIQUE_NO                       , // ������������е����  [ ��1��ʼ������Ϊ0 ]
    VID_BSU_CELL_VOLT                            , // �����ѹ  [ mV ]
    VID_BSU_CELL_TEMP                            , // �����¶�  [ 0.1�� ]
    VID_BSU_CELL_BAL_CURR                        , // �������  [ mA ]
    VID_BSU_CELL_BAL_CAPA                        , // ��������  [ 0.1AH ]
    VID_BSU_CELL_CMD                             , // �������
    VID_BSU_CELL_STATUS                          , // ״̬(����)
    VID_BSU_CELL_BAR_R                           , // ͭ�ŵ���  [ 10u�� ]
    VID_BSU_CELL_VOLT_ORG                        , // �����ѹ(BSUԭʼֵ)  [ mV ]
    VID_BSU_CELL_TEMP_BSU                        , // BSU�ϱ��¶�  [ 0.1�� ]
	VID_BSU_CELL_JUMPER_INFO					 , // ǰ���������Ϣ [ ���ֽ�Ϊ�¶ȣ����ֽ�Ϊ��ѹ�� 0~N=��������, 0xFF=����������� ]

    VID_BSU_CELL_MAX_NUM                         , // �����豸VID����  [ 12 ]

};


enum enBATVid
{
    VID_BAT_TOTAL_VOLT                           , // ����ܵ�ѹ  [ 0.1V ]
    VID_BAT_CURR                                 , // ��ص���  [ 0.1A ]
    VID_BAT_SOC                                  , // SOC  [ .001 ]
    VID_BAT_SOH                                  , // SOH
    VID_BAT_CELL_NUM                             , // ��Ч��ش���
    VID_BAT_AVG_VOLT                             , // ƽ����ѹ  [ mV ]
    VID_BAT_TEMP_NUM                             , // ��Ч�¶ȸ���
    VID_BAT_AVG_TEMP                             , // ƽ���¶�  [ �� ]
    VID_BAT_TOTAL_CHRG_SOC                       , // �ܳ������
    VID_BAT_TOTAL_DSCH_SOC                       , // �ܷŵ�����
    VID_BAT_CYCLE_TIMES                          , // ѭ������
    VID_BAT_SOC_RUNTIME                          , // ���й�����δ����������SOC
    VID_BAT_SOC_BEFORE                           , // ���س��ǰSOC
    VID_BAT_USER_SET_SOC                         , // �û��ֶ�����SOC
    VID_BAT_XXXX                                 , // 
    VID_BAT_YYYY                                 , // 
    VID_BAT_ZZZZ                                 , // 
    VID_BAT_XYZ                                  , // 
    VID_BAT_VMAX01_VOLT                          , // 
    VID_BAT_VMAX01_POSI                          , // 
    VID_BAT_VMAX01_NO                            , // 
    VID_BAT_VMAX02_VOLT                          , // 
    VID_BAT_VMAX02_POSI                          , // 
    VID_BAT_VMAX02_NO                            , // 
    VID_BAT_VMAX03_VOLT                          , // 
    VID_BAT_VMAX03_POSI                          , // 
    VID_BAT_VMAX03_NO                            , // 
    VID_BAT_VMAX04_VOLT                          , // 
    VID_BAT_VMAX04_POSI                          , // 
    VID_BAT_VMAX04_NO                            , // 
    VID_BAT_VMAX05_VOLT                          , // 
    VID_BAT_VMAX05_POSI                          , // 
    VID_BAT_VMAX05_NO                            , // 
    VID_BAT_VMAX06_VOLT                          , // 
    VID_BAT_VMAX06_POSI                          , // 
    VID_BAT_VMAX06_NO                            , // 
    VID_BAT_VMAX07_VOLT                          , // 
    VID_BAT_VMAX07_POSI                          , // 
    VID_BAT_VMAX07_NO                            , // 
    VID_BAT_VMAX08_VOLT                          , // 
    VID_BAT_VMAX08_POSI                          , // 
    VID_BAT_VMAX08_NO                            , // 
    VID_BAT_VMAX09_VOLT                          , // 
    VID_BAT_VMAX09_POSI                          , // 
    VID_BAT_VMAX09_NO                            , // 
    VID_BAT_VMAX10_VOLT                          , // 
    VID_BAT_VMAX10_POSI                          , // 
    VID_BAT_VMAX10_NO                            , // 
    VID_BAT_VMIN01_VOLT                          , // 
    VID_BAT_VMIN01_POSI                          , // 
    VID_BAT_VMIN01_NO                            , // 
    VID_BAT_VMIN02_VOLT                          , // 
    VID_BAT_VMIN02_POSI                          , // 
    VID_BAT_VMIN02_NO                            , // 
    VID_BAT_VMIN03_VOLT                          , // 
    VID_BAT_VMIN03_POSI                          , // 
    VID_BAT_VMIN03_NO                            , // 
    VID_BAT_VMIN04_VOLT                          , // 
    VID_BAT_VMIN04_POSI                          , // 
    VID_BAT_VMIN04_NO                            , // 
    VID_BAT_VMIN05_VOLT                          , // 
    VID_BAT_VMIN05_POSI                          , // 
    VID_BAT_VMIN05_NO                            , // 
    VID_BAT_VMIN06_VOLT                          , // 
    VID_BAT_VMIN06_POSI                          , // 
    VID_BAT_VMIN06_NO                            , // 
    VID_BAT_VMIN07_VOLT                          , // 
    VID_BAT_VMIN07_POSI                          , // 
    VID_BAT_VMIN07_NO                            , // 
    VID_BAT_VMIN08_VOLT                          , // 
    VID_BAT_VMIN08_POSI                          , // 
    VID_BAT_VMIN08_NO                            , // 
    VID_BAT_VMIN09_VOLT                          , // 
    VID_BAT_VMIN09_POSI                          , // 
    VID_BAT_VMIN09_NO                            , // 
    VID_BAT_VMIN10_VOLT                          , // 
    VID_BAT_VMIN10_POSI                          , // 
    VID_BAT_VMIN10_NO                            , // 
    VID_BAT_TMAX01_TEMP                          , // 
    VID_BAT_TMAX01_POSI                          , // 
    VID_BAT_TMAX01_NO                            , // 
    VID_BAT_TMAX02_TEMP                          , // 
    VID_BAT_TMAX02_POSI                          , // 
    VID_BAT_TMAX02_NO                            , // 
    VID_BAT_TMAX03_TEMP                          , // 
    VID_BAT_TMAX03_POSI                          , // 
    VID_BAT_TMAX03_NO                            , // 
    VID_BAT_TMAX04_TEMP                          , // 
    VID_BAT_TMAX04_POSI                          , // 
    VID_BAT_TMAX04_NO                            , // 
    VID_BAT_TMAX05_TEMP                          , // 
    VID_BAT_TMAX05_POSI                          , // 
    VID_BAT_TMAX05_NO                            , // 
    VID_BAT_TMAX06_TEMP                          , // 
    VID_BAT_TMAX06_POSI                          , // 
    VID_BAT_TMAX06_NO                            , // 
    VID_BAT_TMAX07_TEMP                          , // 
    VID_BAT_TMAX07_POSI                          , // 
    VID_BAT_TMAX07_NO                            , // 
    VID_BAT_TMAX08_TEMP                          , // 
    VID_BAT_TMAX08_POSI                          , // 
    VID_BAT_TMAX08_NO                            , // 
    VID_BAT_TMAX09_TEMP                          , // 
    VID_BAT_TMAX09_POSI                          , // 
    VID_BAT_TMAX09_NO                            , // 
    VID_BAT_TMAX10_TEMP                          , // 
    VID_BAT_TMAX10_POSI                          , // 
    VID_BAT_TMAX10_NO                            , // 
    VID_BAT_TMIN01_TEMP                          , // 
    VID_BAT_TMIN01_POSI                          , // 
    VID_BAT_TMIN01_NO                            , // 
    VID_BAT_TMIN02_TEMP                          , // 
    VID_BAT_TMIN02_POSI                          , // 
    VID_BAT_TMIN02_NO                            , // 
    VID_BAT_TMIN03_TEMP                          , // 
    VID_BAT_TMIN03_POSI                          , // 
    VID_BAT_TMIN03_NO                            , // 
    VID_BAT_TMIN04_TEMP                          , // 
    VID_BAT_TMIN04_POSI                          , // 
    VID_BAT_TMIN04_NO                            , // 
    VID_BAT_TMIN05_TEMP                          , // 
    VID_BAT_TMIN05_POSI                          , // 
    VID_BAT_TMIN05_NO                            , // 
    VID_BAT_TMIN06_TEMP                          , // 
    VID_BAT_TMIN06_POSI                          , // 
    VID_BAT_TMIN06_NO                            , // 
    VID_BAT_TMIN07_TEMP                          , // 
    VID_BAT_TMIN07_POSI                          , // 
    VID_BAT_TMIN07_NO                            , // 
    VID_BAT_TMIN08_TEMP                          , // 
    VID_BAT_TMIN08_POSI                          , // 
    VID_BAT_TMIN08_NO                            , // 
    VID_BAT_TMIN09_TEMP                          , // 
    VID_BAT_TMIN09_POSI                          , // 
    VID_BAT_TMIN09_NO                            , // 
    VID_BAT_TMIN10_TEMP                          , // 
    VID_BAT_TMIN10_POSI                          , // 
    VID_BAT_TMIN10_NO                            , // 
    VID_BAT_PRE_STATE                            , // Ԥ��״̬  [ 0����ʼ����1����ʼԤ�䣬2��Ԥ���У�3��������4��Ԥ����ɣ�5Ԥ��ʧ�� ]
    VID_BAT_PRE_COUNTER                          , // Ԥ��ʱ��  [ ʵ��ʱ���� * 150ms ]
    VID_BAT_PRE_FILTER                           , // Ԥ���˲�����
    VID_BAT_PRE_ENABLE                           , // Ԥ��ʹ��  [ 0����ֹԤ�䣬1��Ԥ����Ч ]
    VID_BAT_RATED_VOLT                           , // �������ѹ  [ 0.1V ]
    VID_BAT_RATED_POWER                          , // ���������  [ 0.1kW ]
    VID_BAT_RESERVED7                            , // Ԥ��
    VID_BAT_RESERVED8                            , // Ԥ��
    VID_BAT_RESERVED9                            , // Ԥ��
    VID_BAT_RESERVED10                           , // Ԥ��
    VID_BAT_MAX_NUM                              , // �����豸VID����  [ 148 ]

};


enum enVCUVid
{
	VID_VCU_RECV_COUNTER						, // ( 53248 )��������ͨ������֡������
    VID_VCU_TO_CTRL_RELAY						, // ( 53249 )VCU�Ƿ���Ƽ̵��� [ 0=�� 1=�� ]
    VID_VCU_CTRL_RELAY_REQ						, // ( 53250 )VCU���Ƽ̵�������[ 0=δ����1=�Ͽ���2=�պ� ]
    VID_VCU_LIFE								, // ( 53251 )VCU ����������
	VID_VCU_SHUT_DOWN_REQ						, // ( 53252 )VCU����BMS�ػ�[ 0=δ����1=���� ]

    VID_VCU_CTRL_CMD							, // ���յ���VCU��������
    VID_VCU_RESERVED_06                          , // 
    VID_VCU_RESERVED_07                          , // 
    VID_VCU_RESERVED_08                          , // 
    VID_VCU_RESERVED_09                          , // 
    VID_VCU_RESERVED_10                          , // 
    VID_VCU_VIN1                                 , // ����ʶ����
    VID_VCU_VIN2                                 , // 
    VID_VCU_VIN3                                 , // 
    VID_VCU_VIN4                                 , // 
    VID_VCU_VIN5                                 , // 
    VID_VCU_VIN6                                 , // 
    VID_VCU_VIN7                                 , // 
    VID_VCU_VIN8                                 , // 
    VID_VCU_VIN9                                 , // 
    VID_VCU_VIN10                                , // 

	VID_VCU_RESERVED1                            , // 
    VID_VCU_RESERVED2                            , // 
    VID_VCU_RESERVED3                            , // 
    VID_VCU_RESERVED4                            , // 
    VID_VCU_RESERVED5                            , // 
    VID_VCU_RESERVED6                            , // 
    VID_VCU_RESERVED7                            , // 
    VID_VCU_RESERVED8                            , // 
    VID_VCU_RESERVED9                            , // 
    VID_VCU_RESERVED10                           , // 
    VID_VCU_RESERVED11                           , // 
    VID_VCU_RESERVED12                           , // 
    VID_VCU_RESERVED13                           , // 
    VID_VCU_RESERVED14                           , // 
    VID_VCU_RESERVED15                           , // 
    VID_VCU_RESERVED16                           , // 
    VID_VCU_RESERVED17                           , // 
    VID_VCU_RESERVED18                           , // 
    VID_VCU_RESERVED19                           , // 
    VID_VCU_RESERVED20                           , // 
    VID_VCU_RESERVED21                           , // 
    VID_VCU_RESERVED22                           , // 
    VID_VCU_RESERVED23                           , // 
    VID_VCU_RESERVED24                           , // 
    VID_VCU_RESERVED25                           , // 
    VID_VCU_RESERVED26                           , // 
    VID_VCU_RESERVED27                           , // 
    VID_VCU_RESERVED28                           , // 
    VID_VCU_RESERVED29                           , // 
    VID_VCU_RESERVED30                           , // 
    VID_VCU_RESERVED31                           , // 
    VID_VCU_RESERVED32                           , // 
    VID_VCU_RESERVED33                           , // 
    VID_VCU_RESERVED34                           , // 
    VID_VCU_RESERVED35                           , // 
    VID_VCU_RESERVED36                           , // 
    VID_VCU_RESERVED37                           , // 
    VID_VCU_RESERVED38                           , // 
    VID_VCU_RESERVED39                           , // 
    VID_VCU_RESERVED40                           , // 
	VID_VCU_RESERVED41                           , // 
	VID_VCU_RESERVED42                           , // 
	VID_VCU_RESERVED43                           , // 

	VID_VCU_MAX_NUM                              , // �����豸VID����  [ 64 ]

};


enum enCHRVid
{
    VID_CHR_ONLINE                               , // ��������״̬ [ 0=OFFLINE, 1=ONLINE ]						[ vid = 54272 ]
    VID_CHR_STATE                                , // ����״̬							[ vid = 54273 ]
    VID_CHR_CTRL                                 , // ������������						[ vid = 54274 ]
    VID_CHR_STEP                                 , // ���׶�								[ vid = 54275 ]
    VID_CHR_ALARM                                , // �������ϴ���						[ vid = 54276 ]
    VID_CHR_VOLT_OUTPUT                          , // ����ѹ - �������ֵ				[ vid = 54277 ]
    VID_CHR_CURR_OUTPUT                          , // ������ - �������ֵ				[ vid = 54278 ]
    VID_CHR_VOLT_REQUEST                         , // ����ѹ - ����ֵ	[0.1V]				[ vid = 54279 ]
    VID_CHR_CURR_REQUEST                         , // ������ - ����ֵ	[0.1A]				[ vid = 54280 ]
    VID_CHR_CC_OR_CC2_CONNECTED                  , // ���ǹ���� [ 0:δ���� 1������ ]		[ vid = 54281 ]
    VID_CHR_RELAY_STATE                          , // ���̵���״̬  [ 0���Ͽ� 1���պ� ]	[ vid = 54282 ]
    VID_CHR_TYPE                                 , // �������� [ 0=δ֪��1=���ǣ�2=�Ǳ꣬3=���꣬4=���� ]							[ vid = 54283 ]
    VID_CHR_AC_CC_CONNECTED                      , // CC�Ƿ����Ӻ�  [ 0000=δ���ӣ�FFFF=���Ӻ� ]	[ vid = 54284 ]
    VID_CHR_DC_CC2_CONNECTED                     , // CC2�Ƿ����Ӻ� [ 0000=δ���ӣ�FFFF=���Ӻ� ]	[ vid = 54285 ]
    VID_CHR_CONSTANT_MODE							, // �����ƺ�ѹ����ģʽ [ 1= ��ѹ��2=���� ]		[ vid = 54286 ]
    VID_CHR_RESERVED4                            , // 										[ vid = 54287 ]
    VID_CHR_RESERVED5                            , // 										[ vid = 54288 ]
    VID_CHR_UV_FLAG                            , // 										[ vid = 54289 ]
    VID_CHR_RESERVED7                            , // 										[ vid = 54290 ]
    VID_CHR_RESERVED8                            , // 										[ vid = 54291 ]
    VID_CHR_REMAIN_TIME                          , // Ԥ�Ƴ�����ʱ�� [ min ]				[ vid = 54292 ]
    VID_CHR_CURR_REQUEST_TMP                     , // ������ - ʵ������ֵ	 				[ vid = 54293 ]
    VID_CHR_ON_BOARD_CAN_CHN					, // ���س���CANͨ��(�Զ�ģʽ��)			[ vid = 54294 ]
    VID_CHR_STOP_CHRG_REASON					, // ֹͣ���ԭ�����						[ vid = 54295 ]

	VID_CHR_AC_CC_STATUS						, // CCʵʱ״̬ [ 0=NC��1=220��2=680 ]
	VID_CHR_DC_CC2_STATUS						, // CC2ʵʱ״̬ [ 0=NC��1=1K ]

	VID_CHR_CHARGE_STEP							, // ���״̬ [0=δ��ʼ��1=���ȣ� 2=���ڳ�磬 3=�����ֹ�� 4=������]
	VID_CHR_CURR_STEP							, // �������׶� [0=δ��ʼ��1=Ԥ��磬 2=������ 3=��ѹ�� 4=��䣬5=���]

	VID_CHR_TC_RECV_COUNTER						, // �������ǳ���ͨ�ż�����
	VID_CHR_GB_RECV_COUNTER						, // ���չ������ͨ�ż�����

	VID_CHR_GB_COMM_STEP						, // �������ͨ�Ž׶�

	VID_CHR_GB_RECOGNITION						, // ������ʶ���[ 0x00=���ܱ�ʶ��0xAA=�ܱ�ʶ ]

	VID_CHR_GB_CHGR_MAX_VOLT						, // ������������ѹ [ 0.1V ]
	VID_CHR_GB_CHGR_MIN_VOLT						, // ������������ѹ [ 0.1V ]
	VID_CHR_GB_CHGR_MAX_CURR						, // �������������� [ 0.1A ]
	VID_CHR_GB_CHGR_IS_READY						, // �������׼������ [ 0x00=δ��ɳ��׼����0xAA=��ɳ��׼�� ]
	VID_CHR_GB_BMS_IS_READY							, // BMS׼���ó��

	VID_CHR_GB_ACCUMULATE_TIME						, // �����ۼƳ��ʱ�� [ min ]

	VID_CHR_GB_BMS_ABORT_REASON						, // BMS��ֹ���ԭ��
	VID_CHR_GB_BMS_ABORT_FAULT						, // BMS��ֹ������ԭ��
	VID_CHR_GB_BMS_ABORT_ERROR						, // BMS��ֹ������ԭ��

	VID_CHR_GB_CHR_ABORT_REASON						, // ������ֹ���ԭ��
	VID_CHR_GB_CHR_ABORT_FAULT						, // ������ֹ������ԭ��
	VID_CHR_GB_CHR_ABORT_ERROR						, // ������ֹ������ԭ��

	VID_CHR_GB_OUTPUT_ENERGY					, // ����������� [ 0.1KWH ]
	VID_CHR_GB_ERROR_MSG						, // ����������
	VID_CHR_GB_BMS_ERROR_CODE					, // BMS�����Ĵ���

	VID_CHR_TC_ONLINE							, // ���ǳ�������״̬ [ 0=����, 1=���� ]
	VID_CHR_GB_ONLINE							, // �����������״̬ [ 0=����, 1=���� ]

	VID_CHR_HEAT_STEP							, // �����Ȳ��� [ 0=δ��ʼ��1=����׼����2=�����У�3=������� ]

	//VID_CHR_RESERVED_50							, // 
	//VID_CHR_RESERVED_51							, // 
	VID_CHR_GB_PROTOCOL_VER						, // �������Э��汾 [ 0=δͨ��, 100=2011��, 110=2015�� ]
	VID_CHR_GB_CHGR_MIN_CURR					, // ������С������� [ 0.1A ]
	VID_CHR_GB_CHRG_ENABLE						, // ����������� [ 0=��ͣ, 1=���� ]
	VID_CHR_RESERVED_53							, // 
	VID_CHR_RESERVED_54							, // ���ڷǱ���Ŀ��
	VID_CHR_RESERVED_55							, // ���ڷǱ���Ŀ��
	VID_CHR_RESERVED_56							, // ���ڷǱ���Ŀ��
	VID_CHR_RESERVED_57							, // ���ڷǱ���Ŀ��
	VID_CHR_RESERVED_58							, // ���ڷǱ���Ŀ��
	VID_CHR_RESERVED_59							, // ���ڷǱ���Ŀ��
	VID_CHR_RESERVED_60							, // ���ڷǱ���Ŀ��

	VID_CHR_RESERVED_61							, // ���ڷǱ���Ŀ��
	VID_CHR_RESERVED_62							, // ���ڷǱ���Ŀ��
	VID_CHR_RESERVED_63							, // ���ڷǱ���Ŀ��

	VID_CHR_MAX_NUM								, // �����豸VID����  [ 64 ]

};


#endif //VID_MACRO_H

