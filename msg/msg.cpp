#include <Windows.h>
#include <shellapi.h>
#include <tchar.h>

int main()
{
	TCHAR **argv;
	int argc;
	argv = (TCHAR**)CommandLineToArgvW(GetCommandLine(), &argc);

	TCHAR* msg;
	TCHAR* cap;

	if (argc >= 3)
	{
		msg = argv[argc-2];
		cap = argv[argc-1];
	}
	else if (argc == 2)
	{
		msg = argv[1];
		cap = _T("Message");
	}
	else
	{
		msg = _T("msg.exe \"Message\" \"Title\"");
		cap = _T("Help");
	}

	MessageBox(NULL, msg, cap, 0);

	ExitProcess(0);
}
