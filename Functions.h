#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#ifdef _WIN32

typedef void(__thiscall *CConsole__AddStringVariable_t)(void *pConsole, char *szRule, int flags, char *szString, void *changefunc);
typedef void(__thiscall *CConsole__SetStringVariable_t)(void *pConsole, char *szRule, char *szString);
typedef void(__thiscall *CConsole__SetIntVariable_t)(void *pConsole, char *szRule, int value);
typedef void(__thiscall *CConsole__ModifyVariableFlags_t)(void *pConsole, char *szRule, int value);

typedef bool(__thiscall *CFilterscripts__LoadFilterscript_t)(void *pFilterscriptPool, char *szName);
typedef bool(__thiscall *CFilterscripts__UnLoadFilterscript_t)(void *pFilterscriptPool, char *szName);

typedef void(__thiscall *CPlayer__SpawnForWorld_t)(void *pPlayer);

typedef int (__thiscall *ProcessQueryPacket_t)(unsigned int binaryAddress, unsigned short port, char* data, int length, SOCKET s);
#else
typedef void(*CConsole__AddStringVariable_t)(void *pConsole, char *szRule, int flags, char *szString, void *changefunc);
typedef void(*CConsole__SetStringVariable_t)(void *pConsole, char *szRule, char *szString);
typedef void(*CConsole__SetIntVariable_t)(void *pConsole, char *szRule, int value);
typedef void(*CConsole__ModifyVariableFlags_t)(void *pConsole, char *szRule, int value);
             
typedef bool(*CFilterscripts__LoadFilterscript_t)(void *pFilterscriptPool, char *szName);
typedef bool(*CFilterscripts__UnLoadFilterscript_t)(void *pFilterscriptPool, char *szName);
             
typedef void(*CPlayer__SpawnForWorld_t)(void *pPlayer);

typedef int (*ProcessQueryPacket_t)(unsigned int binaryAddress, unsigned short port, char* data, int length, SOCKET s);
#endif

class CSAMPFunctions
{
public:
	static void		Initialize();
	
	static void		AddStringVariable(char *szRule, int flags, char *szString, void *changefunc);
	static void		SetStringVariable(char *szRule, char *szString);
	static void		SetIntVariable(char *szRule, int value);
	static void		ModifyVariableFlags(char *szRule, int value);
	
	static bool		LoadFilterscript(char *szName);
	static bool		UnLoadFilterscript(char *szName);
	
	static void		SpawnPlayer(int iPlayerId);
	static int		ProcessQueryPacket(unsigned int binaryAddress, unsigned short port, char* data, int length, SOCKET s);

	// Function
	// Rules
	static CConsole__AddStringVariable_t			pfn__CConsole__AddStringVariable;
	static CConsole__SetStringVariable_t			pfn__CConsole__SetStringVariable;
	static CConsole__SetIntVariable_t				pfn__CConsole__SetIntVariable;
	static CConsole__ModifyVariableFlags_t			pfn__CConsole__ModifyVariableFlags;
	// Filterscripts
	static CFilterscripts__LoadFilterscript_t		pfn__CFilterscripts__LoadFilterscript;
	static CFilterscripts__UnLoadFilterscript_t		pfn__CFilterscripts__UnLoadFilterscript;
	// Player
	static CPlayer__SpawnForWorld_t					pfn__CPlayer__SpawnForWorld;
	// Query
	static ProcessQueryPacket_t						pfn__ProcessQueryPacket;
};

#endif
