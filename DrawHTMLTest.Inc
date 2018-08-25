include windows.inc
include user32.inc
include kernel32.inc
include gdi32.inc
include shell32.inc
include comctl32.inc
include comdlg32.inc
include masm32.inc

includelib user32.lib
includelib kernel32.lib
includelib gdi32.lib
includelib shell32.lib
includelib comctl32.lib
includelib comdlg32.lib
includelib masm32.lib


;-----------------------------------------------------------------------------------------
; DrawHTMLTest Prototypes
;-----------------------------------------------------------------------------------------
WinMain					PROTO :DWORD,:DWORD,:DWORD,:DWORD
WndProc					PROTO :DWORD,:DWORD,:DWORD,:DWORD
DoPaint                 PROTO :DWORD


.CONST
;-----------------------------------------------------------------------------------------
; DrawHTMLTest Constants
;-----------------------------------------------------------------------------------------

ICO_MAIN                EQU 100

; Main Dialog
IDD_DIALOG				EQU 1000

; Main Menu 
IDM_MENU				EQU 10000
IDM_FILE_EXIT			EQU 10001
IDM_HELP_ABOUT			EQU 10101



.DATA
;-----------------------------------------------------------------------------------------
; DrawHTMLTest Initialized Data
;-----------------------------------------------------------------------------------------
ClassName				DB 'DLGCLASS',0
AppName					DB 'DrawHTMLCODE Test',0
AboutMsg				DB 'www.LetTheLight.in',13,10,'Copyright © fearless 2018',0

szFontSegioUI           DB "Segio UI",0


;szText                  DB "<pre></font> and </b></b></pre>"
;                        DB 0,0,0,0

szText                  DB "<p>Beauty, success, truth ..."
                        DB "<br><em>He is blessed who has two.</em>"
                        DB "<br><color='#C00000'><b>Your  program has  none.</b></color>"
                        DB "<p><em>Ken Carpenter</em>"
                        DB "<br><a href='www.google.com'>Google</a> test"
                        DB "<pre>This example",9," used the",9,"following tags: <p>,  <br>,   <em>,   <color='#C00000'> and <b></pre>"
                        DB "<pre>And the following end tags: </p>,  </br>,   </em>,   </font> and </b></pre>"
                        DB "<br>test"
                        DB "<code><pre>test</pre></code>"
                        DB "<code>test</code>"
                        DB "<quote>Man is still the most extraordinary computer of all.</quote>"
                        DB "<br> - John F. Kennedy"
                        DB "<hr>"
                        DB "<ul>"
                        DB "<li><b>List 1 - First Item</b> - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.</li>"
                        DB "<li><em>List 1 - Second Item</em></li>"
                        DB "</ul>"
                        DB "<ol>"
                        DB "<li><b>List 2 - First Item</b> - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.</li>"
                        DB "<li><em>List 2 - Second Item</em></li>"
                        DB "</ol>"
                        DB "<ul>"
                        DB "<li><b>List 3 - First Item</b> - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.</li>"
                        DB "<li><em>List 3 - Second Item</em></li>"
                        DB "<ul>"
                        DB "<li><b>List 3 - Lvl 2 - First Item</b> - which is a test to see if the text in this item will properly wrap around in the next line to indent after the bullet symbol and match the indent of the first letter of the first line.</li>"
                        DB "<li><em>List 3 - Lvl 2 - Second Item</em></li>"
                        DB "</ul>"
                        DB "<li><u>List 3 - Third Item</u></li>"
                        DB "</ul>"                        
                        DB 0,0,0,0


szBBCodeText            DB "Beauty, success, truth ...",13,10
                        DB "[i]He is blessed who has two.[/i]",13,10
                        DB "[color='#C00000'][b]Your  program has  none.[/b][/color]",13,10
                        DB "[i]Ken Carpenter[/i]",13,10
                        DB "[code]This example  used the",9,"following tags: [i], [color='#C00000'] and [b][/code]",13,10
                        DB "[code]And the following end tags: [/i],   and [/b][/code]",13,10
                        DB 13,10
                        DB "[code]test[/code]",13,10
                        DB "[code]test[/code]",13,10
                        DB 13,10,13,10
                        DB "[q]Man is still the most extraordinary computer of all.[/q]",13,10
                        DB " - John F. Kennedy",13,10
                        DB 0,0,0,0


dwRGBCodeTextColor      DD 0h
dwRGBCodeBackColor      DD 0E5DBCEh

dwRGBQuoteTextColor     DD 05C5C5Ch
dwRGBQuoteBackColor     DD 0D1D1D1h

dwRGBHorzRuleColor      DD 0C8C8C8h

.DATA?
;-----------------------------------------------------------------------------------------
; DrawHTMLTest Uninitialized Data
;-----------------------------------------------------------------------------------------
icc 					INITCOMMONCONTROLSEX <>
hInstance				DD ?
CommandLine				DD ?
hWnd					DD ?
hFontSegioUI            DD ?
CodeBackBrush           DD ?
QuoteBackBrush          DD ?


