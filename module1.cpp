#include "module1.h"

static wchar_t* text = nullptr;
static int maxLetters_local = 0;

static INT_PTR CALLBACK DlgProc1(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
    switch (iMessage)
    {
    case WM_COMMAND:
        if (LOWORD(wParam) == 1 || LOWORD(wParam) == IDOK)
        {
            GetDlgItemText(hDlg, ID_MODULE1, text, maxLetters_local);

            EndDialog(hDlg, 1);
            break;
        } 

        if (LOWORD(wParam) == 2 || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, 0); 
            break;
        }
        break;
    default: break;
    }
    return FALSE;
}

int Func_MOD1(HWND hWnd, wchar_t* textAddress, int maxLetters)
{
    text = textAddress;
    maxLetters_local = maxLetters;
    return DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(129), hWnd, DlgProc1);
}