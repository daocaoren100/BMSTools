// This file is created by excel VBA
// Version : 1000
// Date    : 2014-2-14 上午 9:36:45
// Author  : FXS

#ifndef VID_MACRO_H
#define VID_MACRO_H



enum enSYSVid
{
    VID_SYS_NOT_USED                             , // 保留备用
    VID_SYS_HW_VER                               , // CPU板硬件版本
    VID_SYS_BASE_BOARD_VER                       , // ADUC软件版本
    VID_SYS_SW_VER                               , // 软件版本
    VID_SYS_LIB_VER                              , // 驱动库版本
    VID_SYS_DISP_VER                             , // 显示版本
    VID_SYS_SW_SUB_VER                           , // 其他版本(预留)
    VID_SYS_TM_YEAR                              , // 系统时间：年
    VID_SYS_TM_MONTH                             , // 月
    VID_SYS_TM_DAY                               , // 日
    VID_SYS_TM_HOUR                              , // 时
    VID_SYS_TM_MIN                               , // 分
    VID_SYS_TM_SEC                               , // 秒
    VID_SYS_XX                                   , // 
    VID_SYS_YY                                   , // 
    VID_SYS_MAIN_CYCLES_PER_SEC                  , // 每秒主循环次数
	VID_SYS_RUN_PERIOD                           , // 本圈周期  [ mS ]
    VID_SYS_MAX_PERIOD                           , // 主循环最长周期  [ mS ]
    VID_SYS_LAST_ERR_NO                          , // 最后错误码  [ BMU自身错误代码 ]
    VID_SYS_WORK_MODE                            , // 系统工作模式  [ 0=正常工作，1=工装模式 ]
    VID_SYS_ACC_STATUS                           , // ACC信号输入状态
    VID_SYS_TO_SUICIDE                           , // 系统准备自杀式断电
    VID_SYS_VOLT                                 , // 系统综合电压
    VID_SYS_CURR                                 , // 系统综合电流
    VID_SYS_TEMP                                 , // 系统综合温度
    VID_SYS_SOC                                  , // 系统综合SOC
    VID_SYS_BOOT_VER                             , // BOOT版本
    VID_SYS_LEFT_SW_VER                          , // 左CPU软件版本
    VID_SYS_RIGHT_SW_VER                         , // 右CPU软件版本
    VID_SYS_MOST_SEVERE_LEVEL                    , // 系统最严重告警级别
    VID_SYS_ACTV_ALM_NUM                         , // 活动告警总数
    VID_SYS_HIST_ALM_NUM                         , // 历史告警总数
    VID_SYS_ALM_L1_NUM                           , // 一级活动告警总数
    VID_SYS_ALM_L2_NUM                           , // 二级活动告警总数
    VID_SYS_ALM_L3_NUM                           , // 三级活动告警总数
    VID_SYS_ALM_L4_NUM                           , // 四级活动告警总数
    VID_SYS_RUN_STATUS                           , // 系统运行状态
    VID_SYS_DI1_STATUS                           , // DI输入状态  [ 0=断开，1=闭合 ]
    VID_SYS_DI2_STATUS                           , // 
    VID_SYS_DI3_STATUS                           , // 
    VID_SYS_DI4_STATUS                           , // 
    VID_SYS_DI5_STATUS                           , // 
    VID_SYS_DI6_STATUS                           , // 
    VID_SYS_DI7_STATUS                           , // 
    VID_SYS_DI8_STATUS                           , // 
    VID_SYS_RELAY1_STATUS                        , // 继电器输出状态  [ 0=断开，1=闭合 ]
    VID_SYS_RELAY2_STATUS                        , // 
    VID_SYS_RELAY3_STATUS                        , // 
    VID_SYS_RELAY4_STATUS                        , // 
    VID_SYS_RELAY5_STATUS                        , // 
    VID_SYS_RELAY6_STATUS                        , // 
    VID_SYS_RELAY7_STATUS                        , // 
    VID_SYS_RELAY8_STATUS                        , // BSU电源预充继电器状态
    VID_SYS_RELAY1_REASON                        , // 继电器断开原因  [ 0=闭合，1=告警关联，其他：原因 ]
    VID_SYS_RELAY2_REASON                        , // 
    VID_SYS_RELAY3_REASON                        , // 
    VID_SYS_RELAY4_REASON                        , // 
    VID_SYS_RELAY5_REASON                        , // 
    VID_SYS_RELAY6_REASON                        , // 
    VID_SYS_RELAY7_REASON                        , // 
    VID_SYS_RELAY8_REASON                        , // 
    VID_SYS_AD_GND_CODE							, // AD通道码值: 绝缘采集地
    VID_SYS_AD_PRE_VOLT_CODE						, // 预充电压
    VID_SYS_AD_BUS_VOLT_CODE					, // 电池母线总电压
    VID_SYS_AD_NBUS_VOLT_CODE					, // 负母线电压
    VID_SYS_AD_CODE5							, // 母线总电压2
    VID_SYS_AD_CODE6							, // 负母线电压2
    VID_SYS_AD_HALL_CODE						, // 霍尔电流
    VID_SYS_AD_SHUNT_CODE						, // 分流器电流
    VID_SYS_BUS_VOLT                             , // 电池母线总电压  [ 0.1V ]
    VID_SYS_PBUS_VOLT                            , // 正母线电压  [ 0.1V ]
    VID_SYS_NBUS_VOLT                            , // 负母线电压  [ 0.1V ]
    VID_SYS_PBUS_RES                             , // 正母线电阻  [ 0.1KΩ ]
    VID_SYS_NBUS_RES                             , // 负母线电阻  [ 0.1KΩ ]
    VID_SYS_LEAK_CURR                            , // 系统漏电流  [ 0.1mA ]
    VID_SYS_PRE_BUS_VOLT                         , // 预充电压  [ 0.1V ]
    VID_SYS_CURR1_VOLT                           , // 电流通道1的电压  [ mV ]
    VID_SYS_SHUNT_VOLT                           , // 电流通道2的电压  [ 0.01mV ]
    VID_SYS_CURR1                                , // 电流通道1的电流  [ 0.1A ]
    VID_SYS_CURR2                                , // 电流通道2的电流  [ 0.1A ]
    VID_SYS_POWER_VOLT                           , // 工作电源电压  [ 0.1V ]
    VID_SYS_BOARD_TEMP                           , // 板上温度传感器温度 [ 0.1℃ ]
    VID_SYS_OUT_TEMP							 , // 外部温度传感器温度 [ 0.1℃ ]
	VID_SYS_LEM_VOLT2                            , // LEM通道2电压
	VID_SYS_LEM_CURR                             , // LEM计算出的电流  [ 0.1A ]
    VID_SYS_LEM_CODE                             , // LEM通道码值
    VID_SYS_ONLINE_BSU_NUM                       , // 在线BSU个数
	VID_SYS_RATED_VOLT                           , // 电池额定电压  [ V ]
	VID_SYS_LIFE                                 , // 生命信息
	VID_SYS_GZ_FUNC_VER							, // 工装测试功能版本
    VID_SYS_PRECHARGE_FAIL                       , // 预充失败状态  [ 0=正常，1=失败 ]
    VID_SYS_MAX_VOLT                             , // 最高电压值  [ mV ]
    VID_SYS_MAXV_POSI                            , // 最高电压位置
    VID_SYS_MIN_VOLT                             , // 最低电压值  [ mV ]
    VID_SYS_MINV_POSI                            , // 最低电压位置
    VID_SYS_MAX_TEMP                             , // 最高温度值  [ 0.1℃ ]
    VID_SYS_MAXT_POSI                            , // 最高温度位置
    VID_SYS_MIN_TEMP                             , // 最低温度值  [ 0.1℃ ]
    VID_SYS_MINT_POSI                            , // 最低温度位置
    VID_JYM_STATUS                               , // 绝缘模块运行状态
    VID_JYM_OFFLINE                              , // 绝缘模块离线状态  [ 0=在线，1=离线 ]
    VID_JYM_OPEN_BAT_VOLT                        , // 电桥断开时电池总电压  [ 0.1V ]
    VID_JYM_OPEN_NBUS_VOLT                       , // 电桥断开时负母线电压  [ 0.1V ]
    VID_JYM_CLOSE_UP_NBUS_VOLT                   , // 上桥闭合时负母线电压  [ 0.1V ]
    VID_JYM_CLOSE_DN_NBUS_VOLT                   , // 下桥闭合时负母线电压  [ 0.1V ]
    VID_SYS_NBUS_VOLT_FINAL		                 , // 根据两档计算出的实时负母线电压  [ 0.1V ]
    VID_SYS_BUS_VOLT1							 , // 电池总压1
    VID_SYS_BUS_VOLT2		                     , // 电池总压2
    VID_SYS_NBUS_VOLT1                           , // 负母线电压1
    VID_SYS_NBUS_VOLT2                           , // 负母线电压2
    VID_GPRS_CONTROL                             , // GPRS控制
    VID_GPRS_RUN_STATUS                          , // GPRS运行状态
    VID_GPRS_SIG_STRENGTH                        , // GPRS信号强度
    VID_GPRS_CONNECT_STEP                        , // GPRS连接步骤
    VID_GPRS_ONLINE_TIME                         , // GPRS在线时间  [ Min ]
    VID_GPRS_SEND_NUM                            , // GPRS发送数据包数目
    VID_GPRS_RECV_OK_NUM                         , // GPRS接收到OK的数目
    VID_GPRS_FLOW_COUNT_HI                       , // GPRS流量高字节
    VID_GPRS_FLOW_COUNT_LO                       , // GPRS流量低字节
    VID_GPRS_IMEI1                               , // GPRS模块IMEI字符串
    VID_GPRS_IMEI2                               , // GPRS模块IMEI字符串
    VID_GPRS_IMEI3                               , // GPRS模块IMEI字符串
    VID_GPRS_IMEI4                               , // GPRS模块IMEI字符串
    VID_GPRS_IMEI5                               , // GPRS模块IMEI字符串
    VID_GPRS_IMEI6                               , // GPRS模块IMEI字符串
    VID_GPRS_IMEI7                               , // GPRS模块IMEI字符串
    VID_GPRS_IMEI8                               , // GPRS模块IMEI字符串
    VID_GPRS_CCID1                               , // SIM卡CCID字符串
    VID_GPRS_CCID2                               , // SIM卡CCID字符串
    VID_GPRS_CCID3                               , // SIM卡CCID字符串
    VID_GPRS_CCID4                               , // SIM卡CCID字符串
    VID_GPRS_CCID5                               , // SIM卡CCID字符串
    VID_GPRS_CCID6                               , // SIM卡CCID字符串
    VID_GPRS_CCID7                               , // SIM卡CCID字符串
    VID_GPRS_CCID8                               , // SIM卡CCID字符串
    VID_GPRS_CCID9                               , // SIM卡CCID字符串
    VID_GPRS_CCID10                              , // SIM卡CCID字符串
    VID_GPRS_RESERVED1                           , // 保留1
    VID_GPRS_ENABLE                          	 , // GPRS 使能开关
    VID_GPRS_ERR_COUNT                           , // GPRS 错误计数
    VID_GPRS_RESERVED4                           , // 保留4
    VID_SYS_ALLOW_DSCH_CURR                      , // 最大允许放电电流  [ 0.1A ]
    VID_SYS_ALLOW_CHRG_CURR                      , // 最大允许充电电流  [ 0.1A ]
    VID_SYS_BM_STATE                             , // 电池管理状态  [ 0=STOP, 1=INIT, 2=SELFTEST, 3=READY, 4=PRECHARGE, 5=RUN... ]
    VID_SYS_RESERVED_144                         , // 系统故障代码1
    VID_SYS_RESERVED_145                         , // 系统故障代码2
    VID_SYS_RESERVED_146                         , // 系统故障代码3
    VID_SYS_RESERVED_147                         , // 系统故障代码4
    VID_SYS_OCV_RESULT							 , // 开路电压置位SOC结果[ 负数=错误码，1-100=置位结果 ]
    VID_SYS_JY_BRIDGE_MANUAL_CTRL				 , // 绝缘电桥手动控制[ 0=自动投切，1=都断开，2=闭合上桥，3=闭合下桥，4=上下都闭合 ]
    VID_SYS_USER_SET_SOC                         , // 用户手动设置SOC的值
    VID_SYS_DEBUG_VAR1                           , // 调试变量1
    VID_SYS_DEBUG_VAR2                           , // 调试变量2
    VID_SYS_DEBUG_VAR3                           , // 调试变量3
    VID_SYS_DEBUG_VAR4                           , // 调试变量4
    VID_SYS_DEBUG_VAR5                           , // 调试变量5
    VID_SYS_DEBUG_VAR6                           , // 调试变量6
    VID_SYS_DEBUG_VAR7                           , // 调试变量7
    VID_SYS_DEBUG_VAR8                           , // 调试变量8
    VID_SYS_ALLOW_DSCH_POWER                     , // 最大允许放电功率  [ 0.1kW ]
    VID_SYS_ALLOW_CHRG_POWER                     , // 最大允许充电功率  [ 0.1kW ]

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

	VID_SYS_CAN_SELF_TEST_RESULT                 , // CAN自测试结果  [ 0-未开始；1-正常；2+故障 ]
    VID_SYS_USB_STATE                            , // USB状态  [ 0=无；1=可使用；<0=错误 ]
    VID_SYS_LOG_PAGE                             , // 内部存储写入的当前页
    VID_SYS_LOG_POS                              , // 内部存储写入的当前页的位置
	VID_SYS_OUT_TEMP2								, // (185) 外部温度2传感器温度 [ 0.1℃ ]
    VID_SYS_CP_AMPLITUDE                         , // CP输入幅值 [ 0.1V ]
    VID_SYS_CP_PWM_FREQ                          , // CP输入PWM频率  [ Hz ]
    VID_SYS_CP_PWM_DUTY_RATIO                    , // CP输入PWM占空比  [ 0.1% ]
    VID_SYS_RELAY_FAN                            , // BMU控制风扇继电器定义  [ 0：无 其他：对应继电器号 ]
    VID_SYS_VCU_MAIN_RELAY_CMD                   , // VCU发给BMS控制主继电器的命令  [ 0：闭合 1：断开 ]
    VID_SYS_BSU_RELAY_STATUS                     , // BSU电源继电器状态  [ 0：闭合 1：断开 ]
    VID_SYS_LOW_VOLT_STATUS						 , // 工作电压太低 [ 0=正常, 1=工作电压太低 ]
	VID_SYS_ADUC_COMM_BREAK						, // ADUC通信失败次数
    VID_SYS_VCU_COMM_FAIL						, // VCU通信超时
    VID_SYS_HIGH_VOLT_ABNORMAL					, // BMU高压异常
    VID_SYS_MAXV_NO                              , // 最高电压单体序号
    VID_SYS_MINV_NO                              , // 最低电压单体序号
    VID_SYS_MAXT_NO                              , // 最高温度单体序号
    VID_SYS_MINT_NO                              , // 最低温度单体序号
    VID_SYS_MINUS_CURR                           , // 负电流（充电为负，放电为正）
    VID_SYS_AUX_FAIL_STATUS                      , // 辅助触点故障检测结果 [ 0=正常, bit0,1=正极粘连,开路, bit2,3=负极, bit4,5=快充,bit6,7=慢充 ]

	VID_SYS_LEFT_CC_CODE                         , // 
    VID_SYS_LEFT_CC2_CODE                         , // 
    VID_SYS_LEFT_CP_CODE                         , // 
    VID_SYS_LEFT_ACC_CRG_CODE                         , // 
    VID_SYS_LEFT_RESERVED_206						 , // 备用
    VID_SYS_LEFT_RESERVED_207                         , // 
    VID_SYS_BOARD_TEMP_CODE						 , // 板上温度码值
    VID_SYS_CP_ORIGINAL_VOLT					, // 原始CP电压

    VID_SYS_CC_VOLT	                            , // 充电CC电压
    VID_SYS_CC2_VOLT                            , // 充电CC2电压
	VID_SYS_CP_VOLT								, // CP电压
	VID_SYS_HALL_BREAK							, // 霍尔断线状态

	VID_SYS_POWER_CODE,
	VID_SYS_CC_CODE,
	VID_SYS_CC2_CODE,
	VID_SYS_CP_CODE,
	VID_SYS_OUT_TEMP_CODE						,	// 外部温度测量的码值
	VID_SYS_OUT_TEMP_VOLT						,	// 外部温度测量的电压 [ mV ]
	VID_SYS_BAL_ACTIVE_MODE						,	// 主动均衡工作模式 （静止，放电，充电）
	VID_SYS_BAL_ACTIVE_DISH_NUM					,	//	主动均衡放电模块数
	VID_SYS_BAL_ACTIVE_CHRG_NUM					,	//	主动均衡充电模块数
	VID_SYS_BAL_ACTIVE_FAIL_NUM					,
	VID_SYS_PARA_FLAG							,	// 恢复默认参数成功
	VID_SYS_ORIGINAL_CURR						, // 原始电流（未清零的电流）	
	VID_SYS_FAST_CURR								, // (226) 快速电流（无滤波） [ 0.1A ]
	VID_SYS_CURR_RESERVED_227						, // (227) 
	VID_SYS_CURR_RESERVED_228						, // (228) 
	VID_SYS_CURR_RESERVED_229						, // (229) 
	VID_SYS_PROTECT_FAIL,
	VID_SYS_CELL_PROTECT_UP,
	VID_SYS_CELL_PROTECT_DOWN,
	VID_SYS_RESERVED_233,
	VID_SYS_RESERVED_234,
	//VID_SYS_RESERVED_235							, // (235) 
	VID_SYS_OUT_71A_TEMP1							, // (235) 用71A模块采集的温度1 (接HALL1)[ 0.1℃ ]
	VID_SYS_RESERVED_236,
	VID_SYS_RESERVED_237,
	//VID_SYS_RESERVED_238							, // (238) 
	VID_SYS_OUT_71A_TEMP2							, // (238) 用71A模块采集的温度2 (接HALL2)[ 0.1℃ ]
	VID_SYS_CELL_NUM_PER_BAT					, // 每组电池串联单体数
	VID_SYS_BSU_NUM_PER_BAT						, // 每组电池的BSU个数
	VID_SYS_DIFF_VOLT							, // 系统压差 [ mV ]
	VID_SYS_DIFF_TEMP							, // 系统温差 [ 0.1 ℃]
	VID_SYS_AVG_VOLT							, // 平均电压 [ mV ]
	VID_SYS_AVG_TEMP							, // 平均温度 [ 0.1 ℃]
	VID_SYS_BATT_AH								, // 电池容量（0.1AH）
	VID_SYS_CURR_INTEGRAL_COUNT						, // (246) 电流积分秒数 [ 每秒加一 ]
	VID_SYS_CURR_INTEGRAL_SUM						, // (247) 电流积分和 [ 0.1AS ]
	VID_SYS_RESERVED_ALARM28					, // 备用告警，用于库外控制
	VID_SYS_RESERVED_ALARM29					, // 备用告警，用于库外控制
	VID_SYS_RESERVED_250,							// DCDC电压

	VID_SYS_CMD_PARA1                            , // 控制命令参数1
	VID_SYS_CMD_PARA2                            , // 控制命令参数2
	VID_SYS_SELF_DEBUG_COMMAND                   , // 自调试超级控制命令

//	VID_SYS_RESERVED_254,
//	VID_SYS_RESERVED_255,
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

    VID_SYS_MAX_NUM                              , // 本类设备VID个数  [ 256 + 80 ]

};


enum enBSUVid
{
    VID_BSU_ADDR                                 , // 该BSU的地址
    VID_BSU_POSI                                 , // BSU位置信息
    VID_BSU_SW_VER                               , // BSU软件版本号
    VID_BSU_RUN_STATUS                           , // BSU运行状态
    VID_BSU_OFFLINE_STATUS                       , // BSU离线状态  [ 0=在线，1=离线 ]
    VID_BSU_TOTAL_VOLT                           , // 所有CELL的总电压  [ 10mV ]
    VID_BSU_CURR                                 , // BSU采集电流  [ 0.1A ]
    VID_BSU_START_CELL_INDEX                     , // 第一个单体在电池组中的序号 [ 从0开始 ]
    VID_BSU_BAL_CMD                              , // 均衡命令：开启、关闭
    VID_BSU_BAL_NO_SET                           , // 设置的均衡序号
    VID_BSU_BAL_CURR_SET                         , // 设置的均衡电流  [ 0.1A ]
    VID_BSU_CHN1_VOLT                            , // 电流通道1的电压  [ mV ]
    VID_BSU_CHN2_VOLT                            , // 电流通道2的电压  [ mV ]
    VID_BSU_BAL1_NO                              , // 第1路实际均衡序号
    VID_BSU_BAL1_CURR                            , // 第1路实际均衡电流  [ 0.1A ]
    VID_BSU_BAL2_NO                              , // 第2路实际均衡序号
    VID_BSU_BAL2_CURR                            , // 第2路实际均衡电流  [ 0.1A ]
    VID_BSU_FAN_CMD                              , // 风扇命令  [ 0=关闭，1=开启 ]
    VID_BSU_HOT_CMD                              , // 加热命令  [ 0=关闭，1=开启 ]
    VID_BSU_FAN_STATUS                           , // 风扇状态  [ 0=关闭，1=开启 ]
    VID_BSU_HOT_STATUS                           , // 加热状态  [ 0=关闭，1=开启 ]
    VID_BSU_BAL_FAIL                             , // 均衡故障
    VID_BSU_DI1_STATUS                           , // 干接点输入1状态
    VID_BSU_DI2_STATUS                           , // 干接点输入2状态
    VID_BSU_BTS_DI1_STATUS                       , // BTS的SW1状态  [ 0=无输入信号，1=有输入信号 ]
    VID_BSU_BTS_DI2_STATUS                       , // BTS的SW2状态  [ 0=无输入信号，1=有输入信号 ]

	VID_BSU_MAX_VOLT_01							, // BSU内部最高电压
	VID_BSU_MAX_VOLT_01_NO						, // BSU内部最高电压位置[0~N]
	VID_BSU_MAX_VOLT_02							, // BSU内部第二高电压
	VID_BSU_MAX_VOLT_02_NO						, // BSU内部第二高电压位置[0~N]

	VID_BSU_MIN_VOLT_01							, // BSU内部最低电压
	VID_BSU_MIN_VOLT_01_NO						, // BSU内部最低电压位置[0~N]
	VID_BSU_MIN_VOLT_02							, // BSU内部第二低电压
	VID_BSU_MIN_VOLT_02_NO						, // BSU内部第二低电压位置[0~N]

	VID_BSU_MAX_TEMP							, // BSU内部最高温度
	VID_BSU_MAX_TEMP_NO							, // BSU内部最高温度位置[0~N]
	VID_BSU_MIN_TEMP							, // BSU内部最低温度
	VID_BSU_MIN_TEMP_NO							, // BSU内部最低温度位置[0~N]

    VID_BSU_HEAD_MAX_NUM                         , // 本类设备VID个数  [ 38 ]

};


enum enBSU_CELLVid
{
    VID_BSU_CELL_POSI                            , // 位置信息  [ 包含所在电池、BSU等信息 ]
    VID_BSU_CELL_UNIQUE_NO                       , // 在整个电池组中的序号  [ 从1开始，跳线为0 ]
    VID_BSU_CELL_VOLT                            , // 单体电压  [ mV ]
    VID_BSU_CELL_TEMP                            , // 单体温度  [ 0.1℃ ]
    VID_BSU_CELL_BAL_CURR                        , // 均衡电流  [ mA ]
    VID_BSU_CELL_BAL_CAPA                        , // 均衡容量  [ 0.1AH ]
    VID_BSU_CELL_CMD                             , // 命令参数
    VID_BSU_CELL_STATUS                          , // 状态(复用)
    VID_BSU_CELL_BAR_R                           , // 铜排电阻  [ 10uΩ ]
    VID_BSU_CELL_VOLT_ORG                        , // 单体电压(BSU原始值)  [ mV ]
    VID_BSU_CELL_TEMP_BSU                        , // BSU上报温度  [ 0.1℃ ]
	VID_BSU_CELL_JUMPER_INFO					 , // 前面的跳线信息 [ 高字节为温度，低字节为电压； 0~N=跳线数据, 0xFF=本身就是跳线 ]

    VID_BSU_CELL_MAX_NUM                         , // 本类设备VID个数  [ 12 ]

};


enum enBATVid
{
    VID_BAT_TOTAL_VOLT                           , // 电池总电压  [ 0.1V ]
    VID_BAT_CURR                                 , // 电池电流  [ 0.1A ]
    VID_BAT_SOC                                  , // SOC  [ .001 ]
    VID_BAT_SOH                                  , // SOH
    VID_BAT_CELL_NUM                             , // 有效电池串数
    VID_BAT_AVG_VOLT                             , // 平均电压  [ mV ]
    VID_BAT_TEMP_NUM                             , // 有效温度个数
    VID_BAT_AVG_TEMP                             , // 平均温度  [ ℃ ]
    VID_BAT_TOTAL_CHRG_SOC                       , // 总充电容量
    VID_BAT_TOTAL_DSCH_SOC                       , // 总放电容量
    VID_BAT_CYCLE_TIMES                          , // 循环次数
    VID_BAT_SOC_RUNTIME                          , // 运行过程中未被修正过的SOC
    VID_BAT_SOC_BEFORE                           , // 蓄电池充电前SOC
    VID_BAT_USER_SET_SOC                         , // 用户手动设置SOC
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
    VID_BAT_PRE_STATE                            , // 预充状态  [ 0：初始化，1：开始预充，2：预充中，3：环流，4：预充完成，5预充失败 ]
    VID_BAT_PRE_COUNTER                          , // 预充时间  [ 实际时间是 * 150ms ]
    VID_BAT_PRE_FILTER                           , // 预充滤波次数
    VID_BAT_PRE_ENABLE                           , // 预充使能  [ 0：禁止预充，1：预充有效 ]
    VID_BAT_RATED_VOLT                           , // 电池组额定电压  [ 0.1V ]
    VID_BAT_RATED_POWER                          , // 电池组额定功率  [ 0.1kW ]
    VID_BAT_RESERVED7                            , // 预留
    VID_BAT_RESERVED8                            , // 预留
    VID_BAT_RESERVED9                            , // 预留
    VID_BAT_RESERVED10                           , // 预留
    VID_BAT_MAX_NUM                              , // 本类设备VID个数  [ 148 ]

};


enum enVCUVid
{
	VID_VCU_RECV_COUNTER						, // ( 53248 )接收整车通信数据帧计数器
    VID_VCU_TO_CTRL_RELAY						, // ( 53249 )VCU是否控制继电器 [ 0=否， 1=是 ]
    VID_VCU_CTRL_RELAY_REQ						, // ( 53250 )VCU控制继电器请求[ 0=未请求，1=断开，2=闭合 ]
    VID_VCU_LIFE								, // ( 53251 )VCU 生命计数器
	VID_VCU_SHUT_DOWN_REQ						, // ( 53252 )VCU请求BMS关机[ 0=未请求，1=请求 ]

    VID_VCU_CTRL_CMD							, // 接收到的VCU控制命令
    VID_VCU_RESERVED_06                          , // 
    VID_VCU_RESERVED_07                          , // 
    VID_VCU_RESERVED_08                          , // 
    VID_VCU_RESERVED_09                          , // 
    VID_VCU_RESERVED_10                          , // 
    VID_VCU_VIN1                                 , // 整车识别码
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

	VID_VCU_MAX_NUM                              , // 本类设备VID个数  [ 64 ]

};


enum enCHRVid
{
    VID_CHR_ONLINE                               , // 充电机在线状态 [ 0=OFFLINE, 1=ONLINE ]						[ vid = 54272 ]
    VID_CHR_STATE                                , // 充电机状态							[ vid = 54273 ]
    VID_CHR_CTRL                                 , // 充电机控制命令						[ vid = 54274 ]
    VID_CHR_STEP                                 , // 充电阶段								[ vid = 54275 ]
    VID_CHR_ALARM                                , // 充电机故障代码						[ vid = 54276 ]
    VID_CHR_VOLT_OUTPUT                          , // 充电电压 - 充电机输出值				[ vid = 54277 ]
    VID_CHR_CURR_OUTPUT                          , // 充电电流 - 充电机输出值				[ vid = 54278 ]
    VID_CHR_VOLT_REQUEST                         , // 充电电压 - 请求值	[0.1V]				[ vid = 54279 ]
    VID_CHR_CURR_REQUEST                         , // 充电电流 - 请求值	[0.1A]				[ vid = 54280 ]
    VID_CHR_CC_OR_CC2_CONNECTED                  , // 充电枪连接 [ 0:未连接 1：连接 ]		[ vid = 54281 ]
    VID_CHR_RELAY_STATE                          , // 充电继电器状态  [ 0：断开 1：闭合 ]	[ vid = 54282 ]
    VID_CHR_TYPE                                 , // 充电机类型 [ 0=未知，1=铁城，2=非标，3=国标，4=普天 ]							[ vid = 54283 ]
    VID_CHR_AC_CC_CONNECTED                      , // CC是否连接好  [ 0000=未连接，FFFF=连接好 ]	[ vid = 54284 ]
    VID_CHR_DC_CC2_CONNECTED                     , // CC2是否连接好 [ 0000=未连接，FFFF=连接好 ]	[ vid = 54285 ]
    VID_CHR_CONSTANT_MODE							, // 充电控制恒压恒流模式 [ 1= 恒压；2=恒流 ]		[ vid = 54286 ]
    VID_CHR_RESERVED4                            , // 										[ vid = 54287 ]
    VID_CHR_RESERVED5                            , // 										[ vid = 54288 ]
    VID_CHR_UV_FLAG                            , // 										[ vid = 54289 ]
    VID_CHR_RESERVED7                            , // 										[ vid = 54290 ]
    VID_CHR_RESERVED8                            , // 										[ vid = 54291 ]
    VID_CHR_REMAIN_TIME                          , // 预计充电完成时间 [ min ]				[ vid = 54292 ]
    VID_CHR_CURR_REQUEST_TMP                     , // 充电电流 - 实际请求值	 				[ vid = 54293 ]
    VID_CHR_ON_BOARD_CAN_CHN					, // 车载充电机CAN通道(自动模式下)			[ vid = 54294 ]
    VID_CHR_STOP_CHRG_REASON					, // 停止充电原因代码						[ vid = 54295 ]

	VID_CHR_AC_CC_STATUS						, // CC实时状态 [ 0=NC，1=220，2=680 ]
	VID_CHR_DC_CC2_STATUS						, // CC2实时状态 [ 0=NC，1=1K ]

	VID_CHR_CHARGE_STEP							, // 充电状态 [0=未开始，1=加热， 2=正在充电， 3=充电中止， 4=充电完成]
	VID_CHR_CURR_STEP							, // 充电电流阶段 [0=未开始，1=预充电， 2=恒流， 3=恒压， 4=绢充，5=完成]

	VID_CHR_TC_RECV_COUNTER						, // 接收铁城充电机通信计数器
	VID_CHR_GB_RECV_COUNTER						, // 接收国标充电机通信计数器

	VID_CHR_GB_COMM_STEP						, // 国标充电机通信阶段

	VID_CHR_GB_RECOGNITION						, // 充电机辨识结果[ 0x00=不能辨识，0xAA=能辨识 ]

	VID_CHR_GB_CHGR_MAX_VOLT						, // 充电机最高输出电压 [ 0.1V ]
	VID_CHR_GB_CHGR_MIN_VOLT						, // 充电机最低输出电压 [ 0.1V ]
	VID_CHR_GB_CHGR_MAX_CURR						, // 充电机最大输出电流 [ 0.1A ]
	VID_CHR_GB_CHGR_IS_READY						, // 充电机输出准备就绪 [ 0x00=未完成充电准备，0xAA=完成充电准备 ]
	VID_CHR_GB_BMS_IS_READY							, // BMS准备好充电

	VID_CHR_GB_ACCUMULATE_TIME						, // 充电机累计充电时间 [ min ]

	VID_CHR_GB_BMS_ABORT_REASON						, // BMS中止充电原因
	VID_CHR_GB_BMS_ABORT_FAULT						, // BMS中止充电故障原因
	VID_CHR_GB_BMS_ABORT_ERROR						, // BMS中止充电错误原因

	VID_CHR_GB_CHR_ABORT_REASON						, // 充电机中止充电原因
	VID_CHR_GB_CHR_ABORT_FAULT						, // 充电机中止充电故障原因
	VID_CHR_GB_CHR_ABORT_ERROR						, // 充电机中止充电错误原因

	VID_CHR_GB_OUTPUT_ENERGY					, // 充电机输出能量 [ 0.1KWH ]
	VID_CHR_GB_ERROR_MSG						, // 充电机错误报文
	VID_CHR_GB_BMS_ERROR_CODE					, // BMS错误报文代码

	VID_CHR_TC_ONLINE							, // 铁城充电机在线状态 [ 0=离线, 1=在线 ]
	VID_CHR_GB_ONLINE							, // 国标充电机在线状态 [ 0=离线, 1=在线 ]

	VID_CHR_HEAT_STEP							, // 充电加热步骤 [ 0=未开始，1=充电机准备，2=加热中，3=加热完成 ]

	//VID_CHR_RESERVED_50							, // 
	//VID_CHR_RESERVED_51							, // 
	VID_CHR_GB_PROTOCOL_VER						, // 国标充电机协议版本 [ 0=未通信, 100=2011版, 110=2015版 ]
	VID_CHR_GB_CHGR_MIN_CURR					, // 充电机最小输出电流 [ 0.1A ]
	VID_CHR_GB_CHRG_ENABLE						, // 充电机充电允许 [ 0=暂停, 1=允许 ]
	VID_CHR_RESERVED_53							, // 
	VID_CHR_RESERVED_54							, // 用于非标项目中
	VID_CHR_RESERVED_55							, // 用于非标项目中
	VID_CHR_RESERVED_56							, // 用于非标项目中
	VID_CHR_RESERVED_57							, // 用于非标项目中
	VID_CHR_RESERVED_58							, // 用于非标项目中
	VID_CHR_RESERVED_59							, // 用于非标项目中
	VID_CHR_RESERVED_60							, // 用于非标项目中

	VID_CHR_RESERVED_61							, // 用于非标项目中
	VID_CHR_RESERVED_62							, // 用于非标项目中
	VID_CHR_RESERVED_63							, // 用于非标项目中

	VID_CHR_MAX_NUM								, // 本类设备VID个数  [ 64 ]

};


#endif //VID_MACRO_H

