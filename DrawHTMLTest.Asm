.686
.MMX
.XMM
.model flat,stdcall
option casemap:none
include \masm32\macros\macros.asm

;DEBUG32 EQU 1

IFDEF DEBUG32
    PRESERVEXMMREGS equ 1
    includelib M:\Masm32\lib\Debug32.lib
    DBG32LIB equ 1
    DEBUGEXE textequ <'M:\Masm32\DbgWin.exe'>
    include M:\Masm32\include\debug32.inc
ENDIF

include DrawHTMLTest.inc

include DrawTextEXT.asm

.code

start:

    Invoke GetModuleHandle,NULL
    mov hInstance, eax
    Invoke GetCommandLine
    mov CommandLine, eax
    Invoke InitCommonControls
    mov icc.dwSize, sizeof INITCOMMONCONTROLSEX
    mov icc.dwICC, ICC_COOL_CLASSES or ICC_STANDARD_CLASSES or ICC_WIN95_CLASSES
    Invoke InitCommonControlsEx, offset icc
    
    Invoke WinMain, hInstance, NULL, CommandLine, SW_SHOWDEFAULT
    Invoke ExitProcess, eax

;-------------------------------------------------------------------------------------
; WinMain
;-------------------------------------------------------------------------------------
WinMain proc hInst:HINSTANCE,hPrevInst:HINSTANCE,CmdLine:LPSTR,CmdShow:DWORD
    LOCAL   wc:WNDCLASSEX
    LOCAL   msg:MSG

    mov     wc.cbSize, sizeof WNDCLASSEX
    mov     wc.style, 0;CS_HREDRAW or CS_VREDRAW
    mov     wc.lpfnWndProc, offset WndProc
    mov     wc.cbClsExtra, NULL
    mov     wc.cbWndExtra, DLGWINDOWEXTRA
    push    hInst
    pop     wc.hInstance
    mov     wc.hbrBackground, COLOR_WINDOW+1
    mov     wc.lpszMenuName, IDM_MENU
    mov     wc.lpszClassName, offset ClassName
    Invoke LoadIcon, hInstance, ICO_MAIN ; resource icon for main application icon
    mov     wc.hIcon, eax
    mov     wc.hIconSm, eax
    Invoke LoadCursor, NULL, IDC_ARROW
    mov     wc.hCursor,eax
    Invoke RegisterClassEx, addr wc
    Invoke CreateDialogParam, hInstance, IDD_DIALOG, NULL, addr WndProc, NULL
    mov hWnd, eax
    Invoke ShowWindow, hWnd, SW_SHOWNORMAL
    Invoke UpdateWindow, hWnd
    .WHILE TRUE
        invoke GetMessage, addr msg, NULL, 0, 0
      .BREAK .if !eax
        Invoke TranslateMessage, addr msg
        Invoke DispatchMessage, addr msg
    .ENDW
    mov eax, msg.wParam
    ret
WinMain endp


;-------------------------------------------------------------------------------------
; WndProc - Main Window Message Loop
;-------------------------------------------------------------------------------------
WndProc proc hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
    
    mov eax, uMsg
    .IF eax == WM_INITDIALOG
        push hWin
        pop hWnd

        Invoke CreateFont, -16, 0,0,0,FW_NORMAL, FALSE, FALSE, FALSE, 0,0,0,0,0, Addr szFontSegioUI
        mov hFontSegioUI, eax
        Invoke CreateSolidBrush, dwRGBCodeBackColor
        mov CodeBackBrush, eax
        Invoke CreateSolidBrush, dwRGBQuoteBackColor
        mov QuoteBackBrush, eax     

    .ELSEIF eax == WM_COMMAND
        mov eax, wParam
        and eax, 0FFFFh
        .IF eax == IDM_FILE_EXIT
            Invoke SendMessage,hWin,WM_CLOSE,0,0
            
        .ELSEIF eax == IDM_HELP_ABOUT
            Invoke ShellAbout,hWin,addr AppName,addr AboutMsg,NULL
        
        .ELSEIF eax == IDC_LINK_MSGBOX
            Invoke MessageBox, hWin, Addr szLinkMsgBoxMsg, Addr AppName, MB_OK
        
        .ELSE
            mov eax, lParam
            .IF eax == hHyperlink
                mov eax, wParam
                shr eax, 16d
                ; we have resource id
                IFDEF DEBUG32
                    PrintText 'Hyperlink clicked with res id'
                    PrintDec eax
                ENDIF
            .ENDIF
        .ENDIF

    .ELSEIF eax == WM_SIZE
        Invoke InvalidateRect, hWin, NULL, TRUE
    
    .ELSEIF eax == WM_CLOSE
        Invoke DestroyWindow,hWin

    .ELSEIF eax == WM_PAINT
        Invoke DoPaint, hWin

    .ELSEIF eax == WM_DESTROY
        Invoke PostQuitMessage,NULL
        
    .ELSE
        Invoke DefWindowProc,hWin,uMsg,wParam,lParam
        ret
    .ENDIF
    xor    eax,eax
    ret
WndProc endp


;-------------------------------------------------------------------------------------
; DoPaint
;-------------------------------------------------------------------------------------
DoPaint PROC hWin:DWORD
    LOCAL ps:PAINTSTRUCT
    LOCAL hdc:DWORD
    LOCAL rect:RECT
    LOCAL hFontOld:DWORD

    Invoke BeginPaint, hWin, Addr ps
    mov hdc, eax

    Invoke GetClientRect, hWin, Addr rect
    add rect.left, 10
    add rect.top, 10
    sub rect.right, 10
    sub rect.bottom, 10 
    
    Invoke SelectObject, hdc, hFontSegioUI
    mov hFontOld, eax
    Invoke DrawHTMLCODE, hdc, Addr szText, -1, Addr rect, DT_WORDBREAK, Addr hHyperlink
    ;Invoke DrawBBCODE, hdc, Addr szBBCodeText, -1, Addr rect, DT_WORDBREAK
    Invoke SelectObject, hdc, hFontOld

    Invoke EndPaint, hWin, Addr ps
    ret
DoPaint ENDP




end start
