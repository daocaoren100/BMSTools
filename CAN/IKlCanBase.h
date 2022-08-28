
#pragma once

#include "IKlCanServe.h"
#include <Windows.h>

enum enIKCState
{
	IKC_STATE_OK = 0,
	IKC_STATE_ERROR,
};

enum enIKCCode
{
	IKC_ERROR_OK = 0,
	IKC_ERROR_INIT,
	IKC_ERROR_UNINIT,
	IKC_ERROR_OPEN,
	IKC_ERROR_PARAM,
	IKC_ERROR_WRITE,
	IKC_ERROR_READ,
	IKC_ERROR_CLOSE,
	IKC_ERROR_RESET,
	IKC_ERROR_STATE,
};

class IKlCanBase
{
public:

	virtual enIKCCode IKC_Init() = 0;			//��ʼ���ӿ�
	virtual enIKCCode IKC_Uninit() = 0;			//	ж�ؽӿ�

	virtual enIKCCode IKC_Reset() = 0;			//	ж�ؽӿ�

	virtual DWORD IKC_GetState(enIKCChannel eCan) = 0;
	virtual enIKCCode IKC_GetZLGState(enIKCChannel eCan, ZLG_CAN_STATUS *vStatus) = 0;
	virtual enIKCCode IKC_Open(enIKCChannel eCan, enIKCBtr eBtr) = 0;			//	��CAN
	virtual enIKCCode IKC_Close(enIKCChannel eCan) = 0;			//	�ر�CAN
	virtual bool IKC_IsOpened(enIKCChannel eCan) = 0;

	virtual enIKCCode IKC_Read(enIKCChannel eCan, stCanFrame *pCanFrame, int nLen, int *pLen) = 0;			//	����CAN��Ϣ
	virtual enIKCCode IKC_Write(enIKCChannel eCan, stCanFrame *pCanFrame) = 0;			//	����CAN��Ϣ

	//virtual enIKCCode IKC_GetStatus() = 0;		//	���״̬
	//virtual enIKCCode IKC_GetErrCode() = 0;		//	��ô�����

	//virtual enIKCCode IKC_GetVersion() = 0;		//	��ð汾��

protected:
private:
};