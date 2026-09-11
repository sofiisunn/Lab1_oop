#include "resource.h"
#include "module2.h"

static int* value = nullptr;
static int pos = 50; 

static INT_PTR CALLBACK DlgProc2(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam)
{

    HWND hWndScroll = GetDlgItem(hDlg, 1002);

    switch (iMessage)
    {
    case WM_INITDIALOG:

        SetScrollRange(hWndScroll, SB_CTL, 1, 100, TRUE);
        SetScrollPos(hWndScroll, SB_CTL, pos, TRUE);
        SetDlgItemInt(hDlg, IDC_STATIC, pos, TRUE);
        return (INT_PTR)TRUE;

    case WM_HSCROLL: 
        pos = GetScrollPos(GetDlgItem(hDlg, 1002), SB_CTL);
        switch (LOWORD(wParam))
        {
        case SB_LINELEFT:  pos--; break; 
        case SB_LINERIGHT: pos++; break; 
        case SB_THUMBPOSITION:
        case SB_THUMBTRACK:
            pos = HIWORD(wParam); 
            break;
        default: break;
        }

        SetScrollPos(hWndScroll, SB_CTL, pos, TRUE);
        SetDlgItemInt(hDlg, IDC_STATIC, pos, TRUE);
        break;

    case WM_COMMAND:
        if (LOWORD(wParam) == 1 || LOWORD(wParam) == IDOK) 
        {
            if (value) {
                *value = pos; 
            }
            EndDialog(hDlg, 1);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == 2 || LOWORD(wParam) == IDCANCEL) 
        {
            EndDialog(hDlg, 0);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

int Func_MOD2(HWND hWnd, int* valueAddress)
{
    value = valueAddress;
    return DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(130), hWnd, DlgProc2);
}