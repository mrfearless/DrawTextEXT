;==============================================================================
;
; DrawTextEXT v1.0.0.0
;
; by mrfearless - www.github.com/mrfearless - http://www.LetTheLight.in
;
; Adapted from DrawHTML code posted by Ukkie9 
;
; https://www.codeproject.com/Articles/7936/DrawHTML
;
;==============================================================================


DrawHTMLCODE PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; hdc, lpString, nCount, lpRect, uFormat, lpLink

;==============================================================================
; DrawHTMLCODE supports the following html tags, enclosed in angle brackets 
; '<>' for starting tags and '</>' for ending tags:
;
; - <b> </b>, <strong> </strong> for bolding text 
; - <t> </t>, <em> </em> for italic text
; - <u> </u> for underlined text
; - <sub> </sub> for subscript
; - <sup> </sup> for superscript
; - <pre> </pre>, <code> </code> for preformatted text
; - <br> for line breaks
; - <p> for paragraph breaks
; - <font color='#RRGGBB'> </font> for color of text using a hex string
; - <color='#RRGGBB'> </color> for color of text using a hex string
; - <q> </q>, <quote> </quote>, <blockq> </blockq> for block quotes
; - <ul> </ul> for unordered lists with bullets
; - <ol> </ol> for ordered lists with numbers
; - <li> </li> for list items within a list
; - <hr> </hr> for horizontal rule
; - <a href='url'>title</a> for hyperlinks having a url and title *
;
; * Experimental/Not Complete
;
; Note: Strings that include byte sequences of 13,10 (0D,0Ah) known as CRLF 
; or 10 (0Ah) known as LF, ARE IGNORED. Use the <br> or <p> if you wish to break
; to a new line.
;
;------------------------------------------------------------------------------


DrawBBCODE   PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD ; hdc, lpString, nCount, lpRect, uFormat

;==============================================================================
; DrawBBCODE supports the following bbcode tags, enclosed in aquare brackets 
; '[]' for starting tags and '[/]' for ending tags:
;
; - [b] [/b], <strong> </strong> for bolding text 
; - [i] [/i] for italic text
; - [u] [/u] for underlined text
; - [code> [/code] for preformatted text
; - [color='#RRGGBB'] [/color] for color of text using a hex string
; - [q] [/q], [quote] [/quote] for block quotes
; - [ul] [/ul] for unordered lists with bullets
; - [ol] [/ol] for ordered lists with numbers
; - [li] [/li] for list items within a list
;
; * Experimental/Not Complete
;
; Note: There is no bbcode for line breaks or paragraph. Strings that include 
; byte sequences of 13,10 (0D,0Ah) known as CRLF or 10 (0Ah) known as LF, are
; automatically processed to break to a new line.
; 
;------------------------------------------------------------------------------



