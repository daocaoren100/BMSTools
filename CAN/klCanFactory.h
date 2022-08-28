
#pragma once

#include "IKlCanServe.h"

class CKlCanServe;

#ifdef CAN_INTERFACE_EXPORTS
class __declspec(dllexport) CKlCanFactory
#else
class __declspec(dllimport) CKlCanFactory
#endif
{
public:
	static IKlCanServe *GetInterface();
	static void Destroy();
private:
	static CKlCanServe *m_pKlCan;
};
