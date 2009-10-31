#ifndef __AKELEDIT_H__
#define __AKELEDIT_H__


//// Includes

#include <richedit.h>
#include <shellapi.h>


//// Defines

#define AES_AKELEDITCLASSA       "AkelEditA"
#define AES_AKELEDITCLASSW      L"AkelEditW"
#define AES_RICHEDITCLASSA       "RichEdit20A"
#define AES_RICHEDITCLASSW      L"RichEdit20W"

//AEM_CONTROLCLASS
#define AECLASS_AKELEDIT        1
#define AECLASS_RICHEDIT        2

//Window styles
#ifndef ES_NOHIDESEL
  #define ES_NOHIDESEL        0x00000100  //See AECO_NOHIDESEL.
#endif
#ifndef ES_READONLY
  #define ES_READONLY         0x00000800  //See AECO_READONLY.
#endif
#ifndef ES_WANTRETURN
  #define ES_WANTRETURN       0x00001000  //See AECO_WANTRETURN.
#endif
#ifndef ES_DISABLENOSCROLL
  #define ES_DISABLENOSCROLL  0x00002000  //See AECO_DISABLENOSCROLL.
#endif
#define ES_HEAP_SERIALIZE     0x00008000  //Mutual exclusion will be used when the heap functions allocate and free memory from window heap. Serialization of heap access allows two or more threads to simultaneously allocate and free memory from the same heap.
                                          //Compatibility: define same as ES_SAVESEL.

//Strings
#define AES_WORDDELIMITERSW     L" \t\n'`\"\\|[](){}<>,.;:+-=~!@#$%^&*/?"
#define AES_WRAPDELIMITERSW     L" \t"
#define AES_URLLEFTDELIMITERSW  L" \t\n'`\"(<{[="
#define AES_URLRIGHTDELIMITERSW L" \t\n'`\")>}]"
#define AES_URLPREFIXESW        L"http:\0https:\0www.\0ftp:\0file:\0mailto:\0\0"

//AEM_SETEVENTMASK flags
#define AENM_SELCHANGE          0x00000001  //Sends AEN_SELCHANGING and AEN_SELCHANGED notifications.
#define AENM_TEXTCHANGE         0x00000002  //Sends AEN_TEXTCHANGING and AEN_TEXTCHANGED notifications.
#define AENM_MODIFY             0x00000004  //Sends AEN_MODIFY notifications.
#define AENM_SCROLL             0x00000008  //Sends AEN_HSCROLL and AEN_VSCROLL notifications.
#define AENM_DROPFILES          0x00000010  //Sends AEN_DROPFILES notifications.
#define AENM_DRAGDROP           0x00000020  //Sends AEN_DROPSOURCE and AEN_DROPTARGET notifications.
#define AENM_LINK               0x00000040  //Sends AEN_LINK notifications.
#define AENM_PROGRESS           0x00000080  //Sends AEN_PROGRESS notifications.

//AEN_TEXTCHANGING and AEN_TEXTCHANGED flags
#define AETCT_REPLACESEL        0x00000001  //Replace selection.
#define AETCT_APPENDTEXT        0x00000002  //Append text.
#define AETCT_SETTEXT           0x00000004  //Set text.
#define AETCT_STREAMIN          0x00000008  //Stream in.
#define AETCT_WRAP              0x00000010  //Send AEM_SETWORDWRAP.
#define AETCT_UNDO              0x00000020  //Undo.
#define AETCT_REDO              0x00000040  //Redo.
#define AETCT_CUT               0x00000080  //Cut.
#define AETCT_CHAR              0x00000100  //Insert char.
#define AETCT_KEYRETURN         0x00000200  //Pressed VK_RETURN.
#define AETCT_KEYBACKSPACE      0x00000400  //Pressed VK_BACK.
#define AETCT_KEYDELETE         0x00000800  //Pressed VK_DELETE.
#define AETCT_DRAGDELETE        0x00001000  //Dragging text delete.
#define AETCT_DROPINSERT        0x00002000  //Dropping text insert.

//AEN_TEXTCHANGED flags
#define AETCT_NONE              0x00100000  //No text is changed.
#define AETCT_DELETEALL         0x00200000  //Indicate that due to AETCT_* action all text has been modified.

//AEN_DROPTARGET actions
#define AEDT_TARGETENTER        1  //Enter into the target window.
#define AEDT_TARGETOVER         2  //Moving over the target window.
#define AEDT_TARGETLEAVE        3  //Leaving the target window.
#define AEDT_TARGETDROP         4  //Drops the data into the target window.

//AEN_DROPSOURCE actions
#define AEDS_SOURCEBEGIN        1  //Begin selection dragging.
#define AEDS_SOURCEEND          2  //End selection dragging.

//AEN_PROGRESS type
#define AEPGS_SETTEXT           0x00000001  //Setting text.
#define AEPGS_WRAPTEXT          0x00000002  //Wrapping text.
#define AEPGS_STREAMIN          0x00000004  //Receiving stream text.

//AEM_SETOPTIONS flags
#define AECO_READONLY           0x00000001  //Set read-only mode. You can use ES_READONLY window style.
#define AECO_DISABLENOSCROLL    0x00000002  //Disables scroll bars instead of hiding them when they are not needed. You can use ES_DISABLENOSCROLL window style.
#define AECO_NOHIDESEL          0x00000004  //If you do not specify this style, then hides the selection when the control loses the input focus and inverts the selection when the control receives the input focus. You can use ES_NOHIDESEL window style.
#define AECO_WANTRETURN         0x00000008  //If you do not specify this style, pressing the ENTER key has the same effect as pressing the dialog box's default push button. You can use ES_WANTRETURN window style.
#define AECO_DETAILEDUNDO       0x00000010  //The control stores any typing action, into a new action in the undo queue.
#define AECO_DISABLEBEEP        0x00000020  //Disables sound beep, when unallowable action occur.
#define AECO_PASTESELECTCOLUMN  0x00000040  //Selects pasted text in column mode.
#define AECO_DISABLEDRAG        0x00000080  //Disables OLE text dragging.
#define AECO_DISABLEDROP        0x00000100  //Disables OLE text dropping.
#define AECO_CARETOUTEDGE       0x00000200  //Allow caret moving out of the line edge.
#define AECO_ACTIVECOLUMN       0x00000400  //Draw caret vertical line.
#define AECO_PAINTGROUP         0x00000800  //Paint text by group of characters (default is character by character). With this style combined unicode symbols can be drawn correctly but editing of whose characters isn't comfortable.
#define AECO_ALTDECINPUT        0x00001000  //Do Alt+NumPad decimal input with NumLock on (default is decimal input after two "Num 0").

#define AECOOP_SET              1  //Sets the options to those specified by lParam.
#define AECOOP_OR               2  //Combines the specified options with the current options.
#define AECOOP_AND              3  //Retains only those current options that are also specified by lParam.
#define AECOOP_XOR              4  //Logically exclusive OR the current options with those specified by lParam.

//Modifier flags
#define AEMOD_ALT               0x01  //ALT key
#define AEMOD_SHIFT             0x02  //SHIFT key
#define AEMOD_CONTROL           0x04  //CTRL key

//AEM_GETLINENUMBER flags
#define AEGL_LINECOUNT              0  //Total number of text lines. If the control has no text, the return value is 1.
#define AEGL_FIRSTSELLINE           1  //First line of the selection.
#define AEGL_LASTSELLINE            2  //Last line of the selection.
#define AEGL_CARETLINE              3  //Caret line.
#define AEGL_FIRSTVISIBLELINE       4  //First visible line.
#define AEGL_LASTVISIBLELINE        5  //Last visible line.
#define AEGL_FIRSTFULLVISIBLELINE   6  //First fully visible line.
#define AEGL_LASTFULLVISIBLELINE    7  //Last fully visible line.

//AEM_GETINDEX flags
#define AEGI_FIRSTCHAR              1  //First character.
#define AEGI_LASTCHAR               2  //Last character.
#define AEGI_FIRSTSELCHAR           3  //First character of the selection.
#define AEGI_LASTSELCHAR            4  //Last character of the selection.
#define AEGI_CARETCHAR              5  //Caret character.
#define AEGI_FIRSTVISIBLELINE       6  //First character of the first visible line.
#define AEGI_LASTVISIBLELINE        7  //Last character of the last visible line.
#define AEGI_NEXTLINE               8  //First character of the next line. lParam must point to an input index.
#define AEGI_PREVLINE               9  //First character of the previous line. lParam must point to an input index.
#define AEGI_NEXTCHAR              10  //Next wide character. lParam must point to an input index.
#define AEGI_PREVCHAR              11  //Previous wide character. lParam must point to an input index.
#define AEGI_WRAPLINEBEGIN         18  //First character of the unwrapped line. lParam must point to an input index. Returns number of characters as AEM_GETINDEX result.
#define AEGI_WRAPLINEEND           19  //Last character of the unwrapped line. lParam must point to an input index. Returns number of characters as AEM_GETINDEX result.
#define AEGI_NEXTCHARINLINE        20  //Next character in line. lParam must point to an input index.
#define AEGI_PREVCHARINLINE        21  //Previous character in line. lParam must point to an input index.
#define AEGI_FIRSTFULLVISIBLELINE  22  //First character of the first fully visible line.
#define AEGI_LASTFULLVISIBLELINE   23  //Last character of the last fully visible line.
#define AEGI_INCREMENT             24  //lParam must point to an input index.
#define AEGI_DECREMENT             25  //lParam must point to an input index.

//AEM_ISDELIMITER parameter
#define AEDLM_PREVCHAR  0x00000001  //Check previous char.
#define AEDLM_WORD      0x00000010  //Word delimiter.
#define AEDLM_WRAP      0x00000020  //Wrap delimiter.
#define AEDLM_URLLEFT   0x00000040  //URL left delimiter.
#define AEDLM_URLRIGHT  0x00000080  //URL right delimiter.

//AEM_SETSEL and AEM_UPDATESEL flags
#define AESELT_COLUMNON            0x00000001  //Make column selection ON.
#define AESELT_COLUMNASIS          0x00000002  //Leave column selection as is.
#define AESELT_LOCKNOTIFY          0x00000004  //Disable AEN_SELCHANGING and AEN_SELCHANGED notifications.
#define AESELT_LOCKSCROLL          0x00000008  //Lock edit window scroll.
#define AESELT_LOCKUPDATE          0x00000010  //Lock edit window update.
#define AESELT_LOCKCARET           0x00000020  //Lock caret reposition.
#define AESELT_LOCKUNDOGROUPING    0x00000040  //Don't use it. For internal code only.
#define AESELT_NOCARETHORZINDENT   0x00000080  //Caret horizontal indent isn't changed.
#define AESELT_NOVERTSCROLLCORRECT 0x00000100  //On some conditions scroll can be increased to a height of one line.
#define AESELT_MOUSE               0x00000200  //Don't use it. For internal code only.
#define AESELT_RESETSELECTION      0x00000400  //Don't use it. For internal code only.

//AEM_ADDPOINT flags
#define AEPT_GLOBALMODIFY          0x00000001  //If set, AEPOINT.ciPoint index has been modified.
#define AEPT_LOCALMODIFY           0x00000002  //Don't use it. For internal code only.

//AEM_CHARFROMPOS return value
#define AEPC_ERROR    0  //Error.
#define AEPC_EQUAL    1  //Char exactly in specified position.
#define AEPC_BEFORE   2  //Char before the specified position.
#define AEPC_AFTER    3  //Char after the specified position.

//New line value
#define AELB_ASIS     1  //Use new line of the source.
#define AELB_ASINPUT  2  //Use input new line, see AEM_SETNEWLINE with AENL_INPUT.
#define AELB_ASOUTPUT 3  //Use output new line, see AEM_SETNEWLINE with AENL_OUTPUT.
#define AELB_EOF      4  //End-of-file, last line in document.
#define AELB_R        5  //"\r" new line.
#define AELB_N        6  //"\n" new line.
#define AELB_RN       7  //"\r\n" new line.
#define AELB_RRN      8  //"\r\r\n" new line.
#define AELB_WRAP     9  //No new line, this line is wrapped.

//AEM_SETNEWLINE flags
#define AENL_INPUT           0x00000001  //Sets default new line for the input operations, for example AEM_PASTE.
#define AENL_OUTPUT          0x00000002  //Sets default new line for the output operations, for example AEM_COPY.

//AEM_SETCOLORS flags
#define AECLR_DEFAULT        0x00000001  //Use default system colors for the specified flags, all members of the AECOLORS structure are ignored.
#define AECLR_CARET          0x00000002  //Sets caret color. crCaret member is valid.
#define AECLR_BASICTEXT      0x00000004  //Sets basic text color. crBasicText member is valid.
#define AECLR_BASICBK        0x00000008  //Sets basic background color. crBasicBk member is valid.
#define AECLR_SELTEXT        0x00000010  //Sets text in selection color. crSelText member is valid.
#define AECLR_SELBK          0x00000020  //Sets background in selection color. crSelBk member is valid.
#define AECLR_ACTIVELINETEXT 0x00000040  //Sets active line text color. crActiveLineText member is valid.
#define AECLR_ACTIVELINEBK   0x00000080  //Sets active line background color. crActiveLineBk member is valid.
#define AECLR_URLTEXT        0x00000100  //Sets hiperlink text color. crUrlText member is valid.
#define AECLR_ACTIVECOLUMN   0x00000200  //Sets active column color. crActiveColumn member is valid.
#define AECLR_COLUMNMARKER   0x00000400  //Sets column marker color. crColumnMarker member is valid.

#define AECLR_ALL            (AECLR_CARET         |\
                              AECLR_BASICTEXT     |\
                              AECLR_BASICBK       |\
                              AECLR_SELTEXT       |\
                              AECLR_SELBK         |\
                              AECLR_ACTIVELINETEXT|\
                              AECLR_ACTIVELINEBK  |\
                              AECLR_URLTEXT       |\
                              AECLR_ACTIVECOLUMN  |\
                              AECLR_COLUMNMARKER)

//Print
#define AEPRN_TEST                      0x01  //Calculate data without painting.
#define AEPRN_INHUNDREDTHSOFMILLIMETERS 0x02  //Indicates that hundredths of millimeters are the unit of measurement for margins.
#define AEPRN_INTHOUSANDTHSOFINCHES     0x04  //Indicates that thousandths of inches are the unit of measurement for margins.
#define AEPRN_WRAPNONE                  0x08  //Print without wrapping.
#define AEPRN_WRAPWORD                  0x10  //Print with word wrapping (default).
#define AEPRN_WRAPSYMBOL                0x20  //Print with symbols wrapping.
#define AEPRN_IGNOREFORMFEED            0x40  //Ignore form-feed character '\f'.
#define AEPRN_ANSI                      0x80  //Ansi text output. Can solve draw problems on Win95/98/Me.

//Highlight flags
#define AEHLF_MATCHCASE              0x0001  //If set, the highlight operation is case-sensitive. If not set, the highlight operation is case-insensitive.
#define AEHLF_WORDCOMPOSITION        0x0002  //Word is a composition of characters. For example, AEWORDITEM.pWord equal to "1234567890" with this flag, means highlight words that contain only digits.
#define AEHLF_QUOTEEND_REQUIRED      0x0004  //If quote end isn't found, text after quote start will not be highlighted.
#define AEHLF_QUOTESTART_ISDELIMITER 0x0008  //Last meet delimiter used as quote start (AEQUOTEITEM.pQuoteStart member is ignored).
#define AEHLF_QUOTEEND_ISDELIMITER   0x0010  //First meet delimiter used as quote end (AEQUOTEITEM.pQuoteEnd member is ignored).
#define AEHLF_QUOTESTART_NOHIGHLIGHT 0x0020  //Don't highlight quote start string.
#define AEHLF_QUOTEEND_NOHIGHLIGHT   0x0040  //Don't highlight quote end string.
#define AEHLF_QUOTESTART_NOMATCH     0x0080  //Don't match and don't highlight quote start string.
#define AEHLF_QUOTEEND_NOMATCH       0x0100  //Don't match and don't highlight quote end string.
#define AEHLF_QUOTESTART_ATLINESTART 0x0200  //Quote start located at line start.
#define AEHLF_QUOTEEND_ATLINEEND     0x0400  //Quote end located at line end.
#define AEHLF_QUOTESTART_ISWORD      0x0800  //Quote start is surrounded with delimiters.
#define AEHLF_QUOTEEND_ISWORD        0x1000  //Quote end is surrounded with delimiters.
#define AEHLF_QUOTEWITHOUTDELIMITERS 0x2000  //Quote doesn't contain delimiters.
#define AEHLF_QUOTEINCLUDE           0x4000  //Quote include string is valid.
#define AEHLF_QUOTEEXCLUDE           0x8000  //Quote exclude string is valid.

//Highlight font style
#define AEHLS_NONE                  0  //Current style.
#define AEHLS_FONTNORMAL            1  //Normal style.
#define AEHLS_FONTBOLD              2  //Bold style.
#define AEHLS_FONTITALIC            3  //Italic style.
#define AEHLS_FONTBOLDITALIC        4  //Bold italic style.

//AEM_SCROLL, AEM_LINESCROLL flags
#define AESB_HORZ            0x00000001  //Horizontal scroll. Cannot be used with AESB_VERT.
#define AESB_VERT            0x00000002  //Vertical scroll. Cannot be used with AESB_HORZ.
#define AESB_RETURNUNITS     0x00000004  //If AESB_HORZ specified, number of characters scrolled returns. If AESB_VERT specified, number of lines scrolled returns.
#define AESB_ALIGNLEFT       0x00000008  //Align first visible char.
#define AESB_ALIGNRIGHT      0x00000010  //Align last visible char.
#define AESB_ALIGNTOP        0x00000020  //Align first visible line.
#define AESB_ALIGNBOTTOM     0x00000040  //Align last visible line.

//AEM_SCROLLCARET, AEM_SCROLLCARETTEST flags
#define AESC_UNITPIXELX      0x00000001  //Low word of the lParam specifies pixels number.
#define AESC_UNITPIXELY      0x00000002  //High word of the lParam specifies pixels number.
#define AESC_UNITCHARX       0x00000004  //Low word of the lParam specifies characters number.
#define AESC_UNITCHARY       0x00000008  //High word of the lParam specifies characters number.
#define AESC_UNITRECTDIVX    0x00000010  //Low word of the lParam specifies divisor of the edit rectangle width.
#define AESC_UNITRECTDIVY    0x00000020  //High word of the lParam specifies divisor of the edit rectangle width.
#define AESC_FORCELEFT       0x00000040  //Scrolls to the left even if caret visible.
#define AESC_FORCETOP        0x00000080  //Scrolls to the top even if caret visible.
#define AESC_FORCERIGHT      0x00000100  //Scrolls to the right even if caret visible.
#define AESC_FORCEBOTTOM     0x00000200  //Scrolls to the bottom even if caret visible.

//AEM_SCROLLCARET, AEM_SCROLLCARETTEST return flags
#define AECSE_SCROLLEDX      0x00000001  //Edit control was horizontally scrolled.
#define AECSE_SCROLLEDY      0x00000002  //Edit control was vertically scrolled.
#define AECSE_SCROLLEDLEFT   0x00000004  //Edit control was scrolled left horizontally.
#define AECSE_SCROLLEDRIGHT  0x00000008  //Edit control was scrolled right horizontally.
#define AECSE_SCROLLEDUP     0x00000010  //Edit control was scrolled up vertically.
#define AECSE_SCROLLEDDOWN   0x00000020  //Edit control was scrolled down vertically.

//AEM_GETCHARSIZE flags
#define AECS_HEIGHT          0  //Current font character height.
#define AECS_AVEWIDTH        1  //Current font character average width.

//AEM_CONVERTPOINT flags
#define AECPT_GLOBALTOCLIENT 0  //Convert position in the virtual text space of the document, to client area coordinates.
#define AECPT_CLIENTTOGLOBAL 1  //Convert position in the client area coordinates, to virtual text space of the document.

//AEM_FINDTEXTA, AEM_FINDTEXTW flags
#define AEFR_DOWN            0x00000001  //If set, the search is from the beginning to the end of the search range. If not set, the search is from the end to the beginning of the search range.
#define AEFR_WHOLEWORD       0x00000002  //If set, the operation searches only for whole words that match the search string. If not set, the operation also searches for word fragments that match the search string.
#define AEFR_MATCHCASE       0x00000004  //If set, the search operation is case-sensitive. If not set, the search operation is case-insensitive.

//AEM_DRAGDROP flags
#define AEDD_GETDRAGWINDOW   1  //Return dragging window handle.
#define AEDD_STOPDRAG        2  //Set stop dragging operation flag.

//AEM_SETWORDWRAP flags
#define AEWW_WORD            0x00000001  //Wrap by words.
#define AEWW_SYMBOL          0x00000002  //Wrap by symbols.
#define AEWW_LIMITPIXEL      0x00000100  //Limit in pixels (default).
#define AEWW_LIMITSYMBOL     0x00000200  //Limit in symbols.

//AEM_SETMARKER types
#define AEMT_PIXEL           0  //Pixel integer.
#define AEMT_SYMBOL          1  //Column number.

//AEM_SETWORDBREAK flags
#define AEWB_LEFTWORDSTART   0x00000001  //Left movement is stopped, when word start is found.
#define AEWB_LEFTWORDEND     0x00000002  //Left movement is stopped, when word end is found.
#define AEWB_RIGHTWORDSTART  0x00000004  //Right movement is stopped, when word start is found.
#define AEWB_RIGHTWORDEND    0x00000008  //Right movement is stopped, when word end is found.
#define AEWB_STOPSPACESTART  0x00000010  //Movement is stopped, when spacing start is found. Cannot be combined with AEWB_SKIPSPACESTART.
#define AEWB_STOPSPACEEND    0x00000020  //Movement is stopped, when spacing end is found. Cannot be combined with AEWB_SKIPSPACEEND.
#define AEWB_SKIPSPACESTART  0x00000040  //Movement is continued, when spacing start is found. Cannot be combined with AEWB_STOPSPACESTART.
#define AEWB_SKIPSPACEEND    0x00000080  //Movement is continued, when spacing end is found. Cannot be combined with AEWB_STOPSPACEEND.
#define AEWB_STOPNEWLINE     0x00000100  //Movement is stopped, when new line is found.

//AEM_STREAMIN, AEM_STREAMOUT flags
#define AESF_SELECTION       0x00000001  //Stream-in (read) or stream-out (write) the current selection. If not specified, stream-in (read) or stream-out (write) the entire contents of the control.
#define AESF_FILLSPACES      0x00000002  //Stream-out (write) the current column selection with the filling empty spaces. Valid if bColumnSel member of a AESTREAMOUT structure is TRUE.

#ifndef FR_DOWN
  #define FR_DOWN 0x00000001
#endif
#ifndef FR_WHOLEWORD
  #define FR_WHOLEWORD 0x00000002
#endif
#ifndef FR_MATCHCASE
  #define FR_MATCHCASE 0x00000004
#endif
#ifndef EC_LEFTMARGIN
  #define EC_LEFTMARGIN 0x0001
#endif
#ifndef EC_RIGHTMARGIN
  #define EC_RIGHTMARGIN 0x0002
#endif
#ifndef GT_SELECTION
  #define GT_SELECTION 0x0002
#endif
#ifndef SPI_GETWHEELSCROLLLINES
  #define SPI_GETWHEELSCROLLLINES 0x0068
#endif
#ifndef WC_NO_BEST_FIT_CHARS
  #define WC_NO_BEST_FIT_CHARS 0x00000400
#endif
#ifndef WM_MOUSEWHEEL
  #define WM_MOUSEWHEEL 0x020A
#endif
#ifndef EN_DRAGDROPDONE
  #define EN_DRAGDROPDONE 0x070c
#endif
#ifndef EM_SHOWSCROLLBAR
  #define EM_SHOWSCROLLBAR (WM_USER + 96)
#endif
#ifndef EM_SETTEXTEX
  #define EM_SETTEXTEX (WM_USER + 97)

  #define ST_DEFAULT    0x0000
  #define ST_KEEPUNDO   0x0001
  #define ST_SELECTION  0x0002
  #define ST_NEWCHARS   0x0004

  typedef struct {
    DWORD flags;
    UINT codepage;
  } SETTEXTEX;
#endif
#ifndef EM_GETSCROLLPOS
  #define EM_GETSCROLLPOS (WM_USER + 221)
#endif
#ifndef EM_SETSCROLLPOS
  #define EM_SETSCROLLPOS (WM_USER + 222)
#endif
#ifndef MAKE_IDENTIFIER
  #define MAKE_IDENTIFIER(a, b, c, d)  ((DWORD)MAKELONG(MAKEWORD(a, b), MAKEWORD(c, d)))
#endif
#ifndef mod
  #define mod(a)  ((((int)(a)) < 0) ? (0 - ((int)(a))) : (a))
#endif

typedef DWORD (CALLBACK *AEStreamCallback)(DWORD dwCookie, wchar_t *wszBuf, DWORD dwBufLen, DWORD *dwBufDone);
//dwCookie    Value of the dwCookie member of the AESTREAMIN or AESTREAMOUT structure. The application specifies this value when it sends the AEM_STREAMIN or AEM_STREAMOUT message.
//wszBuf      Pointer to a buffer to read from or write to. For a stream-in (read) operation, the callback function fills this buffer with data to transfer into the edit control. For a stream-out (write) operation, the buffer contains data from the control that the callback function writes to some storage.
//dwBufLen    Number of bytes to read or write.
//dwBufDone   Pointer to a variable that the callback function sets to the number of bytes actually read or written.
//
//Return Value
// The callback function returns zero to indicate success.
//
//Remarks
// The control continues to call the callback function until one of the following conditions occurs:
// * The callback function returns a nonzero value.
// * The callback function returns zero in the *dwBufDone parameter.


//// Structures

#ifndef _HSTACK_STRUCT_
#define _HSTACK_STRUCT_
typedef struct {
  int first;
  int last;
} HSTACK;
#endif

#ifndef _STACK_STRUCT_
#define _STACK_STRUCT_
typedef struct _stack {
  struct _stack *next;
  struct _stack *prev;
} stack;
#endif

typedef struct _AELINEDATA {
  struct _AELINEDATA *next;   //Pointer to the next AELINEDATA structure.
  struct _AELINEDATA *prev;   //Pointer to the previous AELINEDATA structure.
  wchar_t *wpLine;            //Text of the line, terminated with NULL character.
  int nLineLen;               //Length of the wpLine, not including the terminating NULL character.
  int nLineBreak;             //New line: AELB_EOF, AELB_R, AELB_N, AELB_RN, AELB_RRN or AELB_WRAP. HIWORD is free and can be used.
  int nLineWidth;             //Width of the line in pixels.
  int nSelStart;              //Selection start character position in line.
  int nSelEnd;                //Selection end character position in line.
} AELINEDATA;

typedef struct _AELINEINDEX {
  int nLine;                  //Zero based line number in document.
  AELINEDATA *lpLine;         //Pointer to the AELINEDATA structure.
} AELINEINDEX;

typedef struct _AECHARINDEX {
  int nLine;                  //Zero based line number in document.
  AELINEDATA *lpLine;         //Pointer to the AELINEDATA structure.
  int nCharInLine;            //Character position in line.
} AECHARINDEX;

typedef struct {
  AECHARINDEX ciMin;  //First character index in range.
  AECHARINDEX ciMax;  //Last character index in range.
} AECHARRANGE;

typedef struct {
  AECHARRANGE crSel;  //Characters range.
  DWORD dwFlags;      //See AESELT_* defines.
} AESELECTION;

typedef struct _AEPOINT {
  struct _AEPOINT *next;   //Pointer to the next AEPOINT structure.
  struct _AEPOINT *prev;   //Pointer to the previous AEPOINT structure.
  AECHARINDEX ciPoint;     //Character index.
  DWORD dwFlags;           //See AEPT_* defines.
  DWORD dwUserData;        //User data.
} AEPOINT;

typedef struct {
  char *pText;        //[in] Text to append.
  DWORD dwTextLen;    //[in] Text length. If this value is �1, the string is assumed to be null-terminated and the length is calculated automatically.
  BOOL bColumnSel;    //[in] Column selection. If this value is �1, use current selection type.
} AEAPPENDTEXTA;

typedef struct {
  wchar_t *pText;     //[in] Text to append.
  DWORD dwTextLen;    //[in] Text length. If this value is �1, the string is assumed to be null-terminated and the length is calculated automatically.
  BOOL bColumnSel;    //[in] Column selection. If this value is �1, use current selection type.
} AEAPPENDTEXTW;

typedef struct {
  char *pText;                 //[in]  Text to replace with.
  DWORD dwTextLen;             //[in]  Text length. If this value is �1, the string is assumed to be null-terminated and the length is calculated automatically.
  BOOL bColumnSel;             //[in]  Column selection. If this value is �1, use current selection type.
  AECHARINDEX *ciInsertStart;  //[out] Insert "from" character index after replacement.
  AECHARINDEX *ciInsertEnd;    //[out] Insert "to" character index after replacement.
} AEREPLACESELA;

typedef struct {
  wchar_t *pText;              //[in]  Text to replace with.
  DWORD dwTextLen;             //[in]  Text length. If this value is �1, the string is assumed to be null-terminated and the length is calculated automatically.
  BOOL bColumnSel;             //[in]  Column selection. If this value is �1, use current selection type.
  AECHARINDEX *ciInsertStart;  //[out] Insert "from" character index after replacement.
  AECHARINDEX *ciInsertEnd;    //[out] Insert "to" character index after replacement.
} AEREPLACESELW;

typedef struct {
  AECHARRANGE cr;      //[in]  Characters range to retrieve.
  BOOL bColumnSel;     //[in]  Column selection. If this value is �1, use current selection type.
  char *pBuffer;       //[out] Pointer to buffer that receives the text. If this value is NULL, the function returns the required buffer size in characters.
  DWORD dwBufferMax;   //[in]  Specifies the maximum number of characters to copy to the buffer, including the NULL character.
  int nNewLine;        //[in]  See AELB_* defines.
  int nCodePage;       //[in]  Code page identifier (any available in the system). You can also specify one of the following values: CP_ACP - ANSI code page, CP_OEMCP - OEM code page, CP_UTF8 - UTF-8 code page.
  char *lpDefaultChar; //[in]  Points to the character used if a wide character cannot be represented in the specified code page. If this member is NULL, a system default value is used.
  BOOL *lpUsedDefChar; //[in]  Points to a flag that indicates whether a default character was used. The flag is set to TRUE if one or more wide characters in the source string cannot be represented in the specified code page. Otherwise, the flag is set to FALSE. This member may be NULL.
  BOOL bFillSpaces;    //[in]  If bColumnSel is TRUE, fill empties with spaces.
} AETEXTRANGEA;

typedef struct {
  AECHARRANGE cr;      //[in]  Characters range to retrieve.
  BOOL bColumnSel;     //[in]  Column selection. If this value is �1, use current selection type.
  wchar_t *pBuffer;    //[out] Pointer to buffer that receives the text. If this value is NULL, the function returns the required buffer size in characters.
  DWORD dwBufferMax;   //[in]  Specifies the maximum number of characters to copy to the buffer, including the NULL character.
  int nNewLine;        //[in]  See AELB_* defines.
  int nCodePage;       //[in]  Ignored. Code page is always 1200 (UTF-16 LE).
  char *lpDefaultChar; //[in]  Ignored.
  BOOL *lpUsedDefChar; //[in]  Ignored.
  BOOL bFillSpaces;    //[in]  If bColumnSel is TRUE, fill empties with spaces.
} AETEXTRANGEW;

typedef struct {
  DWORD dwCookie;               //[in]  Specifies an application-defined value that the edit control passes to the AEStreamCallback function specified by the lpCallback member.
  DWORD dwError;                //[out] Indicates the results of the stream-in (read) operation.
  AEStreamCallback lpCallback;  //[in]  Pointer to an AEStreamCallback function, which is an application-defined function that the control calls to transfer data. The control calls the callback function repeatedly, transferring a portion of the data with each call.
  int nNewLine;                 //[in]  See AELB_* defines.
  DWORD dwTextLen;              //[in]  Text length. Need if using AEN_PROGRESS notification.
  int nFirstNewLine;            //[out] Indicates first new line. See AELB_* defines.
} AESTREAMIN;

typedef struct {
  DWORD dwCookie;               //[in]  Specifies an application-defined value that the edit control passes to the AEStreamCallback function specified by the lpCallback member.
  DWORD dwError;                //[out] Indicates the results of the stream-out (write) operation.
  AEStreamCallback lpCallback;  //[in]  Pointer to an AEStreamCallback function, which is an application-defined function that the control calls to transfer data. The control calls the callback function repeatedly, transferring a portion of the data with each call.
  int nNewLine;                 //[in]  See AELB_* defines.
  BOOL bColumnSel;              //[in]  Column selection. If this value is �1, use current selection type.
} AESTREAMOUT;

typedef struct {
  DWORD dwFlags;           //[in]  See AEFR_* defines.
  char *pText;             //[in]  Text to find.
  DWORD dwTextLen;         //[in]  Text length. If this value is �1, the string is assumed to be null-terminated and the length is calculated automatically.
  int nNewLine;            //[in]  See AELB_* defines.
  AECHARRANGE crSearch;    //[in]  Range of characters to search.
  AECHARRANGE crFound;     //[out] Range of characters in which text is found.
} AEFINDTEXTA;

typedef struct {
  DWORD dwFlags;           //[in]  See AEFR_* defines.
  wchar_t *pText;          //[in]  Text to find.
  DWORD dwTextLen;         //[in]  Text length. If this value is �1, the string is assumed to be null-terminated and the length is calculated automatically.
  int nNewLine;            //[in]  See AELB_* defines.
  AECHARRANGE crSearch;    //[in]  Range of characters to search.
  AECHARRANGE crFound;     //[out] Range of characters in which text is found.
} AEFINDTEXTW;

typedef struct {
  DWORD dwFlags;             //[in] See AECLR_* defines.
  COLORREF crCaret;          //[in] Caret color.
  COLORREF crBasicText;      //[in] Basic text color.
  COLORREF crBasicBk;        //[in] Basic background color.
  COLORREF crSelText;        //[in] Text color in selection.
  COLORREF crSelBk;          //[in] Background color in selection.
  COLORREF crActiveLineText; //[in] Text color in active line.
  COLORREF crActiveLineBk;   //[in] Background color in active line.
  COLORREF crUrlText;        //[in] Hiperlink text color.
  COLORREF crActiveColumn;   //[in] Active column color.
  COLORREF crColumnMarker;   //[in] Column marker color.
} AECOLORS;

typedef struct {
  AECHARINDEX *ciCharIn;   //[in]  Input character index.
  AECHARINDEX *ciCharOut;  //[out] Output character index (result).
  int nOffset;             //[in]  Offset can be positive or negative. For example, +1 will return next character, -1 will return previous character.
  int nNewLine;            //[in]  See AELB_* defines.
} AEINDEXOFFSET;

typedef struct {
  AECHARINDEX *ciChar1;   //[in] First character index.
  AECHARINDEX *ciChar2;   //[in] Second character index.
  BOOL bColumnSel;        //[in] Column selection. If this value is �1, use current selection type.
  int nNewLine;           //[in] See AELB_* defines.
} AEINDEXSUBTRACT;

typedef struct {
  DWORD dwFlags;          //[in]     See AEPRN_* defines.
  HDC hPrinterDC;         //[in]     Printer device context.
  HFONT hEditFont;        //[in]     Edit font.
  HFONT hPrintFont;       //[out]    Print font (mapped edit font).
  int nCharHeight;        //[out]    Print character height.
  int nAveCharWidth;      //[out]    Print character average width.
  int nSpaceCharWidth;    //[out]    Print space width.
  int nTabWidth;          //[out]    Print tabulation width.
  RECT rcMargins;         //[in]     Specifies the widths of the left, top, right, and bottom margins. The AEPRN_INHUNDREDTHSOFMILLIMETERS or AEPRN_INTHOUSANDTHSOFINCHES flag indicates the units of measurement.
  RECT rcPageFull;        //[out]    Complete page rectangle. Filled by AEM_STARTPRINTDOC message.
  RECT rcPageIn;          //[in,out] Available page rectangle (minus margins). Filled by AEM_STARTPRINTDOC message and can be modified by user before AEM_PRINTPAGE call.
  RECT rcPageOut;         //[out]    Filled page rectangle. Filled by AEM_PRINTPAGE message.
  AECHARRANGE crText;     //[in,out] Text range to print. Filled by user and changed after AEM_PRINTPAGE message.
} AEPRINT;

typedef struct _AEDELIMITEMA {
  struct _AEDELIMITEMA *next;
  struct _AEDELIMITEMA *prev;
  char *pDelimiter;          //Delimiter string.
  int nDelimiterLen;         //Delimiter string length.
  DWORD dwFlags;             //See AEHLF_* defines.
  COLORREF crText;           //Delimiter text color. If -1, then don't set.
  COLORREF crBk;             //Delimiter background color. If -1, then don't set.
  DWORD dwFontStyle;         //See AEHLS_* defines.
} AEDELIMITEMA;

typedef struct _AEDELIMITEMW {
  struct _AEDELIMITEMW *next;
  struct _AEDELIMITEMW *prev;
  wchar_t *pDelimiter;       //Delimiter string.
  int nDelimiterLen;         //Delimiter string length.
  DWORD dwFlags;             //See AEHLF_* defines.
  COLORREF crText;           //Delimiter text color. If -1, then don't set.
  COLORREF crBk;             //Delimiter background color. If -1, then don't set.
  DWORD dwFontStyle;         //See AEHLS_* defines.
} AEDELIMITEMW;

typedef struct _AEWORDITEMA {
  struct _AEWORDITEMA *next;
  struct _AEWORDITEMA *prev;
  char *pWord;               //Word string.
  int nWordLen;              //Word string length.
  DWORD dwFlags;             //See AEHLF_* defines.
  COLORREF crText;           //Word text color. If -1, then don't set.
  COLORREF crBk;             //Word background color. If -1, then don't set.
  DWORD dwFontStyle;         //See AEHLS_* defines.
} AEWORDITEMA;

typedef struct _AEWORDITEMW {
  struct _AEWORDITEMW *next;
  struct _AEWORDITEMW *prev;
  wchar_t *pWord;            //Word string.
  int nWordLen;              //Word string length.
  DWORD dwFlags;             //See AEHLF_* defines.
  COLORREF crText;           //Word text color. If -1, then don't set.
  COLORREF crBk;             //Word background color. If -1, then don't set.
  DWORD dwFontStyle;         //See AEHLS_* defines.
} AEWORDITEMW;

typedef struct _AEQUOTEITEMA {
  struct _AEQUOTEITEMA *next;
  struct _AEQUOTEITEMA *prev;
  char *pQuoteStart;         //Quote start string.
  int nQuoteStartLen;        //Quote start string length.
  char *pQuoteEnd;           //Quote end string. If NULL, line end used as quote end.
  int nQuoteEndLen;          //Quote end string length.
  char chEscape;             //Escape character. If it precedes quote string then quote ignored.
  char *pQuoteInclude;       //Quote include string.
  int nQuoteIncludeLen;      //Quote include string length.
  char *pQuoteExclude;       //Quote exclude string.
  int nQuoteExcludeLen;      //Quote exclude string length.
  DWORD dwFlags;             //See AEHLF_* defines.
  COLORREF crText;           //Quote text color. If -1, then don't set.
  COLORREF crBk;             //Quote background color. If -1, then don't set.
  DWORD dwFontStyle;         //See AEHLS_* defines.
} AEQUOTEITEMA;

typedef struct _AEQUOTEITEMW {
  struct _AEQUOTEITEMW *next;
  struct _AEQUOTEITEMW *prev;
  wchar_t *pQuoteStart;      //Quote start string.
  int nQuoteStartLen;        //Quote start string length.
  wchar_t *pQuoteEnd;        //Quote end string. If NULL, line end used as quote end.
  int nQuoteEndLen;          //Quote end string length.
  wchar_t wchEscape;         //Escape character. If it precedes quote string then quote ignored.
  wchar_t *pQuoteInclude;    //Quote include string.
  int nQuoteIncludeLen;      //Quote include string length.
  wchar_t *pQuoteExclude;    //Quote exclude string.
  int nQuoteExcludeLen;      //Quote exclude string length.
  DWORD dwFlags;             //See AEHLF_* defines.
  COLORREF crText;           //Quote text color. If -1, then don't set.
  COLORREF crBk;             //Quote background color. If -1, then don't set.
  DWORD dwFontStyle;         //See AEHLS_* defines.
} AEQUOTEITEMW;

typedef struct _AEMARKTEXTITEMA {
  struct _AEMARKTEXTITEMA *next;
  struct _AEMARKTEXTITEMA *prev;
  char *pMarkText;           //Mark text.
  int nMarkTextLen;          //Mark text length.
  DWORD dwFlags;             //See AEHLF_* defines.
  COLORREF crText;           //Mark text color. If -1, then don't set.
  COLORREF crBk;             //Mark background color. If -1, then don't set.
  DWORD dwFontStyle;         //See AEHLS_* defines.
} AEMARKTEXTITEMA;

typedef struct _AEMARKTEXTITEMW {
  struct _AEMARKTEXTITEMW *next;
  struct _AEMARKTEXTITEMW *prev;
  wchar_t *pMarkText;        //Mark text.
  int nMarkTextLen;          //Mark text length.
  DWORD dwFlags;             //See AEHLF_* defines.
  COLORREF crText;           //Mark text color. If -1, then don't set.
  COLORREF crBk;             //Mark background color. If -1, then don't set.
  DWORD dwFontStyle;         //See AEHLS_* defines.
} AEMARKTEXTITEMW;

typedef struct _AEMARKRANGEITEM {
  struct _AEMARKRANGEITEM *next;
  struct _AEMARKRANGEITEM *prev;
  CHARRANGE crMarkRange;     //cpMin member is the first character in the range (RichEdit offset), cpMax member is the last character in the range (RichEdit offset).
  DWORD dwFlags;             //Reserved.
  COLORREF crText;           //Mark text color. If -1, then don't set.
  COLORREF crBk;             //Mark background color. If -1, then don't set.
  DWORD dwFontStyle;         //See AEHLS_* defines.
} AEMARKRANGEITEM;

typedef struct {
  NMHDR hdr;
  DWORD dwBytes;        //Number of bytes that cannot be allocated.
} AENERRSPACE;

typedef struct {
  NMHDR hdr;
  AESELECTION aes;      //Current selection.
  AECHARINDEX ciCaret;  //Caret character index position.
} AENSELCHANGE;

typedef struct {
  NMHDR hdr;
  AESELECTION aes;      //Current selection.
  AECHARINDEX ciCaret;  //Caret character index position.
  DWORD dwType;         //See AETCT_* defines.
} AENTEXTCHANGE;

typedef struct {
  NMHDR hdr;
  BOOL bModified;      //TRUE document state is set to modified, FALSE document state is set to unmodified.
} AENMODIFY;

typedef struct {
  NMHDR hdr;
  int nPosNew;         //Current scroll position.
  int nPosOld;         //Previous scroll position.
  int nPosMax;         //Maximum scroll position.
} AENSCROLL;

typedef struct {
  NMHDR hdr;
  HDROP hDrop;         //Handle to the dropped files list (same as with WM_DROPFILES).
  AECHARINDEX ciChar;  //Character index at which the dropped files would be inserted.
} AENDROPFILES;

typedef struct {
  NMHDR hdr;
  int nAction;         //See AEDS_* defines.
  DWORD dwEffect;      //Cursor effect: DROPEFFECT_COPY, DROPEFFECT_MOVE or DROPEFFECT_NONE.
  DWORD dwDropResult;  //Drop result, valid if nAction equal to AEDS_SOURCEEND.
} AENDROPSOURCE;

typedef struct {
  NMHDR hdr;
  int nAction;         //See AEDT_* defines.
  POINT pt;            //Cursor position.
  DWORD dwEffect;      //Cursor effect: DROPEFFECT_COPY, DROPEFFECT_MOVE or DROPEFFECT_NONE.
} AENDROPTARGET;

typedef struct {
  NMHDR hdr;
  UINT uMsg;           //Mouse message: WM_LBUTTONDBLCLK, WM_LBUTTONDOWN, WM_LBUTTONUP, WM_MOUSEMOVE, WM_RBUTTONDBLCLK, WM_RBUTTONDOWN, WM_RBUTTONUP, WM_SETCURSOR.
  WPARAM wParam;       //First parameter of a message.
  LPARAM lParam;       //Second parameter of a message.
  AECHARRANGE crLink;  //Range of characters which contain URL text.
} AENLINK;

typedef struct {
  NMHDR hdr;
  DWORD dwType;        //See AEPGS_* defines.
  DWORD dwTimeElapsed; //Elapsed time since action was start.
  int nCurrent;        //Characters processed. Equal to zero, if first message.
  int nMaximum;        //Total number of characters. Equal to nCurrent member, if last message.
} AENPROGRESS;


//// AkelEdit functions

#ifdef AEC_INDEXCOMPARE
#define AEC_INDEXCOMPARE_INCLUDED
  int AEC_IndexCompare(const AECHARINDEX *ciChar1, const AECHARINDEX *ciChar2)
  {
    if (ciChar1->nLine == ciChar2->nLine &&
        ciChar1->nCharInLine == ciChar2->nCharInLine)
    {
      return 0;
    }
    if ((ciChar1->nLine < ciChar2->nLine) ||
        (ciChar1->nLine == ciChar2->nLine &&
         ciChar1->nCharInLine < ciChar2->nCharInLine))
    {
      return -1;
    }
    return 1;
  }
#else
  int AEC_IndexCompare(const AECHARINDEX *ciChar1, const AECHARINDEX *ciChar2);
#endif


//// AkelEdit messages

//Notifications
#define AEN_ERRSPACE              (WM_USER + 1001)  //0x7E9
#define AEN_SETFOCUS              (WM_USER + 1002)  //0x7EA
#define AEN_KILLFOCUS             (WM_USER + 1003)  //0x7EB
#define AEN_SELCHANGING           (WM_USER + 1004)  //0x7EC
#define AEN_SELCHANGED            (WM_USER + 1005)  //0x7ED
#define AEN_TEXTCHANGING          (WM_USER + 1006)  //0x7EE
#define AEN_TEXTCHANGED           (WM_USER + 1007)  //0x7EF
#define AEN_MODIFY                (WM_USER + 1008)  //0x7F0
#define AEN_HSCROLL               (WM_USER + 1009)  //0x7F1
#define AEN_VSCROLL               (WM_USER + 1010)  //0x7F2
#define AEN_DROPFILES             (WM_USER + 1011)  //0x7F3
#define AEN_DROPSOURCE            (WM_USER + 1012)  //0x7F4
#define AEN_DROPTARGET            (WM_USER + 1013)  //0x7F5
#define AEN_LINK                  (WM_USER + 1014)  //0x7F6
#define AEN_PROGRESS              (WM_USER + 1015)  //0x7F7

//Text retrieval and modification
#define AEM_SETTEXTA              (WM_USER + 2001)
#define AEM_SETTEXTW              (WM_USER + 2002)
#define AEM_APPENDTEXTA           (WM_USER + 2003)
#define AEM_APPENDTEXTW           (WM_USER + 2004)
#define AEM_REPLACESELA           (WM_USER + 2005)
#define AEM_REPLACESELW           (WM_USER + 2006)
#define AEM_GETTEXTRANGEA         (WM_USER + 2007)
#define AEM_GETTEXTRANGEW         (WM_USER + 2008)
#define AEM_STREAMIN              (WM_USER + 2009)
#define AEM_STREAMOUT             (WM_USER + 2010)
#define AEM_CANPASTE              (WM_USER + 2011)
#define AEM_PASTE                 (WM_USER + 2012)
#define AEM_CUT                   (WM_USER + 2013)
#define AEM_COPY                  (WM_USER + 2014)
#define AEM_CHECKCODEPAGE         (WM_USER + 2015)
#define AEM_FINDTEXTA             (WM_USER + 2016)
#define AEM_FINDTEXTW             (WM_USER + 2017)
#define AEM_ISMATCHA              (WM_USER + 2018)
#define AEM_ISMATCHW              (WM_USER + 2019)
#define AEM_KEYDOWN               (WM_USER + 2020)
#define AEM_DRAGDROP              (WM_USER + 2021)

//Undo and Redo
#define AEM_CANUNDO               (WM_USER + 2051)
#define AEM_CANREDO               (WM_USER + 2052)
#define AEM_UNDO                  (WM_USER + 2053)
#define AEM_REDO                  (WM_USER + 2054)
#define AEM_EMPTYUNDOBUFFER       (WM_USER + 2055)
#define AEM_STOPGROUPTYPING       (WM_USER + 2056)
#define AEM_BEGINUNDOACTION       (WM_USER + 2057)
#define AEM_ENDUNDOACTION         (WM_USER + 2058)
#define AEM_LOCKCOLLECTUNDO       (WM_USER + 2059)
#define AEM_GETUNDOLIMIT          (WM_USER + 2060)
#define AEM_SETUNDOLIMIT          (WM_USER + 2061)
#define AEM_GETMODIFY             (WM_USER + 2062)
#define AEM_SETMODIFY             (WM_USER + 2063)
#define AEM_UNDOBUFFERSIZE        (WM_USER + 2064)

//Text coordinates
#define AEM_EXGETSEL              (WM_USER + 2099)
#define AEM_EXSETSEL              (WM_USER + 2100)
#define AEM_GETSEL                (WM_USER + 2101)
#define AEM_SETSEL                (WM_USER + 2102)
#define AEM_GETCOLUMNSEL          (WM_USER + 2103)
#define AEM_UPDATESEL             (WM_USER + 2104)
#define AEM_GETLINENUMBER         (WM_USER + 2105)
#define AEM_GETINDEX              (WM_USER + 2106)
#define AEM_GETLINEINDEX          (WM_USER + 2107)
#define AEM_INDEXUPDATE           (WM_USER + 2108)
#define AEM_INDEXCOMPARE          (WM_USER + 2109)
#define AEM_INDEXSUBTRACT         (WM_USER + 2110)
#define AEM_INDEXOFFSET           (WM_USER + 2111)
#define AEM_INDEXTORICHOFFSET     (WM_USER + 2112)
#define AEM_RICHOFFSETTOINDEX     (WM_USER + 2113)
#define AEM_ADDPOINT              (WM_USER + 2114)
#define AEM_DELPOINT              (WM_USER + 2115)
#define AEM_GETINDEXCOLUMN        (WM_USER + 2116)
#define AEM_GETWRAPLINE           (WM_USER + 2117)
#define AEM_GETUNWRAPLINE         (WM_USER + 2118)
#define AEM_GETNEXTBREAK          (WM_USER + 2119)
#define AEM_GETPREVBREAK          (WM_USER + 2120)
#define AEM_ISDELIMITER           (WM_USER + 2121)

//Screen coordinates
#define AEM_CHARFROMPOS           (WM_USER + 2151)
#define AEM_POSFROMCHAR           (WM_USER + 2152)
#define AEM_GETRECT               (WM_USER + 2153)
#define AEM_SETRECT               (WM_USER + 2154)
#define AEM_GETSCROLLPOS          (WM_USER + 2155)
#define AEM_SETSCROLLPOS          (WM_USER + 2156)
#define AEM_SCROLL                (WM_USER + 2157)
#define AEM_LINESCROLL            (WM_USER + 2158)
#define AEM_SCROLLCARET           (WM_USER + 2159)
#define AEM_SCROLLCARETTEST       (WM_USER + 2160)
#define AEM_LOCKSCROLL            (WM_USER + 2161)
#define AEM_GETERASERECT          (WM_USER + 2162)
#define AEM_SETERASERECT          (WM_USER + 2163)
#define AEM_GETCHARSIZE           (WM_USER + 2164)
#define AEM_GETSTRWIDTH           (WM_USER + 2165)
#define AEM_GETCARETPOS           (WM_USER + 2166)
#define AEM_GETCARETHORZINDENT    (WM_USER + 2167)
#define AEM_SETCARETHORZINDENT    (WM_USER + 2168)
#define AEM_CONVERTPOINT          (WM_USER + 2169)

//Options
#define AEM_CONTROLCLASS          (WM_USER + 2199)
#define AEM_CONTROLVERSION        (WM_USER + 2200)
#define AEM_GETEVENTMASK          (WM_USER + 2201)
#define AEM_SETEVENTMASK          (WM_USER + 2202)
#define AEM_GETOPTIONS            (WM_USER + 2203)
#define AEM_SETOPTIONS            (WM_USER + 2204)
#define AEM_GETNEWLINE            (WM_USER + 2205)
#define AEM_SETNEWLINE            (WM_USER + 2206)
#define AEM_GETCOLORS             (WM_USER + 2207)
#define AEM_SETCOLORS             (WM_USER + 2208)
#define AEM_GETDETECTURL          (WM_USER + 2209)
#define AEM_SETDETECTURL          (WM_USER + 2210)
#define AEM_GETOVERTYPE           (WM_USER + 2211)
#define AEM_SETOVERTYPE           (WM_USER + 2212)
#define AEM_GETCARETWIDTH         (WM_USER + 2213)
#define AEM_SETCARETWIDTH         (WM_USER + 2214)
#define AEM_GETTABSTOP            (WM_USER + 2215)
#define AEM_SETTABSTOP            (WM_USER + 2216)
#define AEM_GETWORDWRAP           (WM_USER + 2217)
#define AEM_SETWORDWRAP           (WM_USER + 2218)
#define AEM_GETWORDDELIMITERS     (WM_USER + 2219)
#define AEM_SETWORDDELIMITERS     (WM_USER + 2220)
#define AEM_GETWRAPDELIMITERS     (WM_USER + 2221)
#define AEM_SETWRAPDELIMITERS     (WM_USER + 2222)
#define AEM_GETURLLEFTDELIMITERS  (WM_USER + 2223)
#define AEM_SETURLLEFTDELIMITERS  (WM_USER + 2224)
#define AEM_GETURLRIGHTDELIMITERS (WM_USER + 2225)
#define AEM_SETURLRIGHTDELIMITERS (WM_USER + 2226)
#define AEM_GETURLPREFIXES        (WM_USER + 2227)
#define AEM_SETURLPREFIXES        (WM_USER + 2228)
#define AEM_GETURLMAXLENGTH       (WM_USER + 2229)
#define AEM_SETURLMAXLENGTH       (WM_USER + 2230)
#define AEM_GETWORDBREAK          (WM_USER + 2231)
#define AEM_SETWORDBREAK          (WM_USER + 2232)
#define AEM_GETMARKER             (WM_USER + 2233)
#define AEM_SETMARKER             (WM_USER + 2234)
#define AEM_GETLINEGAP            (WM_USER + 2235)
#define AEM_SETLINEGAP            (WM_USER + 2236)

//Draw
#define AEM_SHOWSCROLLBAR         (WM_USER + 2351)
#define AEM_UPDATESCROLLBAR       (WM_USER + 2352)
#define AEM_UPDATECARET           (WM_USER + 2353)
#define AEM_HIDESELECTION         (WM_USER + 2354)

//Window data
#define AEM_GETWINDOWDATA         (WM_USER + 2401)
#define AEM_SETWINDOWDATA         (WM_USER + 2402)
#define AEM_CREATEWINDOWDATA      (WM_USER + 2403)
#define AEM_DELETEWINDOWDATA      (WM_USER + 2404)

//Clone
#define AEM_ADDCLONE              (WM_USER + 2421)
#define AEM_DELCLONE              (WM_USER + 2422)
#define AEM_GETMASTER             (WM_USER + 2423)
#define AEM_GETCLONE              (WM_USER + 2424)

//Print
#define AEM_STARTPRINTDOC         (WM_USER + 2451)
#define AEM_PRINTPAGE             (WM_USER + 2452)
#define AEM_ENDPRINTDOC           (WM_USER + 2453)

//Highlight
#define AEM_HLCREATETHEMEA        (WM_USER + 2501)
#define AEM_HLCREATETHEMEW        (WM_USER + 2502)
#define AEM_HLGETTHEMEA           (WM_USER + 2503)
#define AEM_HLGETTHEMEW           (WM_USER + 2504)
#define AEM_HLGETTHEMENAMEA       (WM_USER + 2505)
#define AEM_HLGETTHEMENAMEW       (WM_USER + 2506)
#define AEM_HLTHEMEEXISTS         (WM_USER + 2507)
#define AEM_HLSETTHEME            (WM_USER + 2508)
#define AEM_HLDELETETHEME         (WM_USER + 2509)
#define AEM_HLADDDELIMITERA       (WM_USER + 2521)
#define AEM_HLADDDELIMITERW       (WM_USER + 2522)
#define AEM_HLDELETEDELIMITER     (WM_USER + 2523)
#define AEM_HLADDWORDA            (WM_USER + 2531)
#define AEM_HLADDWORDW            (WM_USER + 2532)
#define AEM_HLDELETEWORD          (WM_USER + 2533)
#define AEM_HLADDQUOTEA           (WM_USER + 2541)
#define AEM_HLADDQUOTEW           (WM_USER + 2542)
#define AEM_HLDELETEQUOTE         (WM_USER + 2543)
#define AEM_HLADDMARKTEXTA        (WM_USER + 2551)
#define AEM_HLADDMARKTEXTW        (WM_USER + 2552)
#define AEM_HLDELETEMARKTEXT      (WM_USER + 2553)
#define AEM_HLADDMARKRANGE        (WM_USER + 2561)
#define AEM_HLDELETEMARKRANGE     (WM_USER + 2562)


//// RichEdit messages

/*
AkelEdit can emulate RichEdit 3.0 and support the following messages:

EN_CHANGE
EN_DRAGDROPDONE
EN_DROPFILES
EN_ERRSPACE
EN_HSCROLL
EN_KILLFOCUS
EN_LINK
EN_MSGFILTER
EN_SELCHANGE
EN_SETFOCUS
EN_VSCROLL

EM_AUTOURLDETECT
EM_CANPASTE
EM_CANREDO
EM_CANUNDO
EM_CHARFROMPOS
EM_EMPTYUNDOBUFFER
EM_EXGETSEL
EM_EXLINEFROMCHAR
EM_EXSETSEL
EM_FINDTEXT
EM_FINDTEXTEX
EM_FINDTEXTEXW
EM_FINDTEXTW
EM_FINDWORDBREAK
EM_GETAUTOURLDETECT
EM_GETEVENTMASK
EM_GETFIRSTVISIBLELINE
EM_GETLINE
EM_GETLINECOUNT
EM_GETMARGINS
EM_GETMODIFY
EM_GETOPTIONS
EM_GETRECT
EM_GETSCROLLPOS
EM_GETSEL
EM_GETSELTEXT
EM_GETTEXTEX
EM_GETTEXTLENGTHEX
EM_GETTEXTRANGE
EM_GETTHUMB
EM_HIDESELECTION
EM_LINEFROMCHAR
EM_LINEINDEX
EM_LINELENGTH
EM_LINESCROLL
EM_POSFROMCHAR
EM_REDO
EM_REPLACESEL
EM_SCROLL
EM_SCROLLCARET
EM_SETBKGNDCOLOR
EM_SETEVENTMASK
EM_SETMARGINS
EM_SETMODIFY
EM_SETOPTIONS
EM_SETREADONLY
EM_SETRECT
EM_SETRECTNP
EM_SETSCROLLPOS
EM_SETSEL
EM_SETTEXTEX
EM_SETUNDOLIMIT
EM_SHOWSCROLLBAR
EM_STOPGROUPTYPING
EM_STREAMIN
EM_STREAMOUT
EM_UNDO
*/


//// AkelEdit messages description

/*
AEN_ERRSPACE
____________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure when an edit control cannot allocate enough memory.

(int)wParam           == specifies the control identifier.
(AENERRSPACE *)lParam == pointer to a AENERRSPACE structure.

Return Value
 zero


AEN_SETFOCUS
____________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure when an edit control receives the keyboard focus.

(int)wParam     == specifies the control identifier.
(NMHDR *)lParam == pointer to a NMHDR structure.

Return Value
 zero


AEN_KILLFOCUS
_____________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure when an edit control loses the keyboard focus.

(int)wParam     == specifies the control identifier.
(NMHDR *)lParam == pointer to a NMHDR structure.

Return Value
 zero


AEN_SELCHANGING
_______________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure before the current selection has changed.

(int)wParam            == specifies the control identifier.
(AENSELCHANGE *)lParam == pointer to a AENSELCHANGE structure.

Return Value
 zero

Remarks
 To receive AEN_SELCHANGING notifications, specify AENM_SELCHANGE in the mask sent with the AEM_SETEVENTMASK message.


AEN_SELCHANGED
______________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure after the current selection has changed.

(int)wParam            == specifies the control identifier.
(AENSELCHANGE *)lParam == pointer to a AENSELCHANGE structure.

Return Value
 zero

Remarks
 To receive AEN_SELCHANGED notifications, specify AENM_SELCHANGE in the mask sent with the AEM_SETEVENTMASK message.


AEN_TEXTCHANGING
________________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure before the document text has changed.

(int)wParam             == specifies the control identifier.
(AENTEXTCHANGE *)lParam == pointer to a AENTEXTCHANGE structure.

Return Value
 zero

Remarks
 To receive AEN_TEXTCHANGING notifications, specify AENM_TEXTCHANGE in the mask sent with the AEM_SETEVENTMASK message.


AEN_TEXTCHANGED
_______________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure after the document text has changed.

(int)wParam             == specifies the control identifier.
(AENTEXTCHANGE *)lParam == pointer to a AENTEXTCHANGE structure.

Return Value
 zero

Remarks
 To receive AEN_TEXTCHANGED notifications, specify AENM_TEXTCHANGE in the mask sent with the AEM_SETEVENTMASK message.


AEN_MODIFY
__________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure after the document modify state has changed.

(int)wParam         == specifies the control identifier.
(AENMODIFY *)lParam == pointer to a AENMODIFY structure.

Return Value
 zero

Remarks
 To receive AEN_MODIFY notifications, specify AENM_MODIFY in the mask sent with the AEM_SETEVENTMASK message.


AEN_HSCROLL
___________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure before an edit control window scrolled horizontally.

(int)wParam         == specifies the control identifier.
(AENSCROLL *)lParam == pointer to a AENSCROLL structure.

Return Value
 If zero, the control allows scroll operation.
 If a nonzero value, the control suppress scroll operation.

Remarks
 To receive AEN_HSCROLL notifications, specify AENM_SCROLL in the mask sent with the AEM_SETEVENTMASK message.


AEN_VSCROLL
___________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure before an edit control window scrolled horizontally.

(int)wParam         == specifies the control identifier.
(AENSCROLL *)lParam == pointer to a AENSCROLL structure.

Return Value
 If zero, the control allows scroll operation.
 If a nonzero value, the control suppress scroll operation.

Remarks
 To receive AEN_VSCROLL notifications, specify AENM_SCROLL in the mask sent with the AEM_SETEVENTMASK message.


AEN_DROPFILES
_____________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure when the user is attempting to drop files into the control (when it receives the WM_DROPFILES message).

(int)wParam            == specifies the control identifier.
(AENDROPFILES *)lParam == pointer to a AENDROPFILES structure.

Return Value
 If zero, the control ignores the drop operation.
 If a nonzero value, the control allows the drop operation.

Remarks
 To receive AEN_DROPFILES notifications, specify AENM_DROPFILES in the mask sent with the AEM_SETEVENTMASK message.
 To receive WM_DROPFILES messages, the parent window must register the control as a drop target by using the DragAcceptFiles function. The control does not register itself.


AEN_DROPSOURCE
______________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure when the user is dragging the selection.

(int)wParam             == specifies the control identifier.
(AENDROPSOURCE *)lParam == pointer to a AENDROPSOURCE structure.

Return Value
 If zero, the control ignores the drop operation.
 If a nonzero value, the control allows the drop operation.

Remarks
 To receive AEN_DROPSOURCE notifications, specify AEN_DRAGDROP in the mask sent with the AEM_SETEVENTMASK message.


AEN_DROPTARGET
______________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure when the user is attempting to drop data into the control.

(int)wParam             == specifies the control identifier.
(AENDROPTARGET *)lParam == pointer to a AENDROPTARGET structure.

Return Value
 If zero, the control ignores the drop operation.
 If a nonzero value, the control allows the drop operation.

Remarks
 To receive AEN_DROPTARGET notifications, specify AEN_DRAGDROP in the mask sent with the AEM_SETEVENTMASK message.


AEN_LINK
________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure when edit control receives mouse messages while the mouse pointer is over URL.

(int)wParam       == specifies the control identifier.
(AENLINK *)lParam == pointer to a AENLINK structure.

Return Value
 If zero, the control proceeds with its normal handling of the mouse message.
 If a nonzero value, the control does not handle the mouse message.

Remarks
 To receive AEN_LINK notifications, specify AENM_LINK in the mask sent with the AEM_SETEVENTMASK message and turn on URL detection with the AEM_SETDETECTURL message.


AEN_PROGRESS
____________

Notification message sends in the form of a WM_NOTIFY message.
Sends to the parent window procedure when required number of lines was proceed.

(int)wParam           == specifies the control identifier.
(AENPROGRESS *)lParam == pointer to a AENPROGRESS structure.

Return Value
 If zero, the control continues operation.
 If a nonzero value, the control stops operation.

Remarks
 To receive AEN_PROGRESS notifications, specify AENM_PROGRESS in the mask sent with the AEM_SETEVENTMASK message.


AEM_SETTEXTA
____________

Set ansi text of the edit control.

(DWORD)wParam  == text length. If this value is �1, the string is assumed to be null-terminated and the length is calculated automatically.
(char *)lParam == text pointer.

Return Value
 Text length.

Example:
 SendMessage(hWndEdit, AEM_SETTEXTA, (WPARAM)-1, (LPARAM)"SomeText");


AEM_SETTEXTW
____________

Set unicode text of the edit control.

(DWORD)wParam     == text length. If this value is �1, the string is assumed to be null-terminated and the length is calculated automatically.
(wchar_t *)lParam == text pointer.

Return Value
 Text length.

Example:
 SendMessage(hWndEdit, AEM_SETTEXTW, (WPARAM)-1, (LPARAM)L"SomeText");


AEM_APPENDTEXTA
_______________

Append ansi text to the end of the edit control.

wParam                  == not used.
(AEAPPENDTEXTA *)lParam == pointer to a AEAPPENDTEXTA structure.

Return Value
 zero

Example:
 AEAPPENDTEXTA at;

 at.pText="SomeText";
 at.dwTextLen=(DWORD)-1;
 at.bColumnSel=FALSE;
 SendMessage(hWndEdit, AEM_APPENDTEXTA, 0, (LPARAM)&at);


AEM_APPENDTEXTW
_______________

Append unicode text to the end of the edit control.

wParam                  == not used.
(AEAPPENDTEXTW *)lParam == pointer to a AEAPPENDTEXTW structure.

Return Value
 zero

Example:
 AEAPPENDTEXTW at;

 at.pText=L"SomeText";
 at.dwTextLen=(DWORD)-1;
 at.bColumnSel=FALSE;
 SendMessage(hWndEdit, AEM_APPENDTEXTW, 0, (LPARAM)&at);


AEM_REPLACESELA
_______________

Replace selection with the ansi text.

wParam                  == not used.
(AEREPLACESELA *)lParam == pointer to a AEREPLACESELA structure.

Return Value
 zero

Example:
 AEREPLACESELA rs;

 rs.pText="SomeText";
 rs.dwTextLen=(DWORD)-1;
 rs.bColumnSel=SendMessage(hWndEdit, AEM_GETCOLUMNSEL, 0, 0);
 rs.ciInsertStart=NULL;
 rs.ciInsertEnd=NULL;
 SendMessage(hWndEdit, AEM_REPLACESELA, 0, (LPARAM)&rs);


AEM_REPLACESELW
_______________

Replace selection with the unicode text.

wParam                  == not used.
(AEREPLACESELW *)lParam == pointer to a AEREPLACESELW structure.

Return Value
 zero

Example:
 AEREPLACESELW rs;

 rs.pText=L"SomeText";
 rs.dwTextLen=(DWORD)-1;
 rs.bColumnSel=SendMessage(hWndEdit, AEM_GETCOLUMNSEL, 0, 0);
 rs.ciInsertStart=NULL;
 rs.ciInsertEnd=NULL;
 SendMessage(hWndEdit, AEM_REPLACESELW, 0, (LPARAM)&rs);


AEM_GETTEXTRANGEA
_________________

Retrieve a specified range of ansi characters from an edit control.

wParam                 == not used.
(AETEXTRANGEA *)lParam == pointer to a AETEXTRANGEA structure.

Return Value
 Number of characters copied, not including the terminating NULL character.

Example:
 AETEXTRANGEA tr;
 int nLen;

 SendMessage(hWndEdit, AEM_GETSEL, (WPARAM)NULL, (LPARAM)&tr);
 tr.pText=NULL;
 tr.nNewLine=AELB_ASOUTPUT;
 tr.nCodePage=CP_ACP;
 tr.lpDefaultChar=NULL;
 tr.lpUsedDefChar=NULL;
 tr.bFillSpaces=FALSE;

 if (nLen=SendMessage(hWndEdit, AEM_GETTEXTRANGEA, 0, (LPARAM)&tr))
 {
   if (tr.pText=(char *)GlobalAlloc(GPTR, nLen + 1))
   {
     SendMessage(hWndEdit, AEM_GETTEXTRANGEA, 0, (LPARAM)&tr);
     MessageBoxA(NULL, tr.pText, NULL, 0);

     GlobalFree((HGLOBAL)tr.pText);
   }
 }


AEM_GETTEXTRANGEW
_________________

Retrieve a specified range of unicode characters from an edit control.

wParam                 == not used.
(AETEXTRANGEW *)lParam == pointer to a AETEXTRANGEW structure.

Return Value
 Number of characters copied, not including the terminating NULL character.

Example:
 AETEXTRANGEW tr;
 int nLen;

 SendMessage(hWndEdit, AEM_GETSEL, (WPARAM)NULL, (LPARAM)&tr);
 tr.pText=NULL;
 tr.nNewLine=AELB_ASOUTPUT;
 tr.bFillSpaces=FALSE;

 if (nLen=SendMessage(hWndEdit, AEM_GETTEXTRANGEW, 0, (LPARAM)&tr))
 {
   if (tr.pText=(wchar_t *)GlobalAlloc(GPTR, nLen * sizeof(wchar_t) + 2))
   {
     SendMessage(hWndEdit, AEM_GETTEXTRANGEW, 0, (LPARAM)&tr);
     MessageBoxW(NULL, tr.pText, NULL, 0);

     GlobalFree((HGLOBAL)tr.pText);
   }
 }


AEM_STREAMIN
____________

Replace the contents of an edit control with a stream of data provided by an application defined callback function.

(DWORD)wParam        == see AESF_* defines.
(AESTREAMIN *)lParam == pointer to a AESTREAMIN structure.

Return Value
 Number of characters read.

Example:
 typedef struct {
   wchar_t *wpData;
   int nDataLen;
   int nCount;
 } STREAMINDATA;

 AESTREAMIN aesi;
 STREAMINDATA sid;

 sid.wpData=L"SomeText";
 sid.nDataLen=lstrlenW(sid.wpData);
 sid.nCount=0;

 aesi.dwCookie=(DWORD)&sid;
 aesi.lpCallback=InputStreamCallback;
 aesi.nNewLine=AELB_ASINPUT;
 aesi.dwTextLen=sid.nDataLen;
 SendMessage(hWndEdit, AEM_STREAMIN, AESF_SELECTION, (LPARAM)&aesi);

 DWORD CALLBACK InputStreamCallback(DWORD dwCookie, wchar_t *wszBuf, DWORD dwBufLen, DWORD *dwBufDone)
 {
   STREAMINDATA *lpData=(STREAMINDATA *)dwCookie;
   wchar_t *wpSrc=lpData->wpData;
   wchar_t *wpDest=wszBuf;
   DWORD dwDestLen=dwBufLen / sizeof(wchar_t);
   DWORD i;

   for (i=0; i < dwDestLen; ++i)
   {
     if (lpData->nCount >= lpData->nDataLen)
       break;
     wpDest[i]=wpSrc[lpData->nCount++];
   }
   *dwBufDone=i * sizeof(wchar_t);

   return 0;
 }


AEM_STREAMOUT
_____________

Cause an edit control to pass its contents to an application defined callback function.
The callback function can then write the stream of data to a file or any other location that it chooses.

(DWORD)wParam         == see AESF_* defines.
(AESTREAMOUT *)lParam == pointer to a AESTREAMOUT structure.

Return Value
 Number of characters written to the data stream.

Example:
 typedef struct {
   HANDLE hFile;
 } STREAMOUTDATA;

 AESTREAMOUT aeso;
 STREAMOUTDATA sod;

 sod.hFile=CreateFileA("C:\\Test.tmp", GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_WRITE, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);

 if (sod.hFile != INVALID_HANDLE_VALUE)
 {
   aeso.dwCookie=(DWORD)&sod;
   aeso.lpCallback=OutputStreamCallback;
   aeso.nNewLine=AELB_ASOUTPUT;
   aeso.bColumnSel=FALSE;
   SendMessage(hWndEdit, AEM_STREAMOUT, 0, (LPARAM)&aeso);

   CloseHandle(sod.hFile);
 }

 DWORD CALLBACK OutputStreamCallback(DWORD dwCookie, wchar_t *wszBuf, DWORD dwBufLen, DWORD *dwBufDone)
 {
   STREAMOUTDATA *lpData=(STREAMOUTDATA *)dwCookie;
   unsigned char *pDataToWrite=(unsigned char *)wszBuf;
   DWORD dwBytesToWrite=dwBufLen;

   return !WriteFile(lpData->hFile, pDataToWrite, dwBytesToWrite, dwBufDone, NULL);
 }


AEM_CANPASTE
____________

Determine whether an edit control can paste a text from clipboard.

wParam == not used.
lParam == not used.

Return Value
 TRUE   success.
 FALSE  failed.

Example:
 SendMessage(hWndEdit, AEM_CANPASTE, 0, 0);


AEM_PASTE
_________

Paste text from clipboard.

wParam       == not used.
(BOOL)lParam == TRUE   paste as ANSI text.
                FALSE  paste as Unicode text, if no Unicode text available ANSI text will be used (default).

Return Value
 TRUE   success.
 FALSE  failed.

Example:
 SendMessage(hWndEdit, AEM_PASTE, 0, FALSE);


AEM_CUT
_______

Delete the current selection, if any, and copy the deleted text to the clipboard.

wParam == not used.
lParam == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_CUT, 0, 0);


AEM_COPY
________

Copy the current selection to the clipboard.

wParam == not used.
lParam == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_COPY, 0, 0);


AEM_CHECKCODEPAGE
_________________

Check that the contents of an edit control can be converted to the specified code page.

(int)wParam == code page to check.
lParam      == not used.

Return Value
 Zero if successful, otherwise returns first met line number containing nonconverted character.

Remarks
 Windows 95 isn't supported.

Example:
 SendMessage(hWndEdit, AEM_CHECKCODEPAGE, 1251, 0);


AEM_FINDTEXTA
_____________

Find ansi text within an edit control.

wParam                == not used.
(AEFINDTEXTA *)lParam == pointer to a AEFINDTEXTA structure.

Return Value
 TRUE   founded.
 FALSE  not found.

Example:
 AEFINDTEXTA ft;
 AESELECTION aes;

 ft.dwFlags=AEFR_DOWN;
 ft.pText="SomeText";
 ft.dwTextLen=(DWORD)-1;
 ft.nNewLine=AELB_ASIS;
 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTCHAR, (LPARAM)&ft.crSearch.ciMin);
 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_LASTCHAR, (LPARAM)&ft.crSearch.ciMax);

 if (SendMessage(hWndEdit, AEM_FINDTEXTA, 0, (LPARAM)&ft))
 {
   aes.crSel=ft.crFound;
   aes.dwFlags=0;
   SendMessage(hWndEdit, AEM_SETSEL, (WPARAM)NULL, (LPARAM)&aes);
 }


AEM_FINDTEXTW
_____________

Find unicode text within an edit control.

wParam                == not used.
(AEFINDTEXTW *)lParam == pointer to a AEFINDTEXTW structure.

Return Value
 TRUE   founded.
 FALSE  not found.

Example:
 AEFINDTEXTW ft;
 AESELECTION aes;

 ft.dwFlags=AEFR_DOWN;
 ft.pText=L"SomeText";
 ft.dwTextLen=(DWORD)-1;
 ft.nNewLine=AELB_ASIS;
 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTCHAR, (LPARAM)&ft.crSearch.ciMin);
 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_LASTCHAR, (LPARAM)&ft.crSearch.ciMax);

 if (SendMessage(hWndEdit, AEM_FINDTEXTW, 0, (LPARAM)&ft))
 {
   aes.crSel=ft.crFound;
   aes.dwFlags=0;
   SendMessage(hWndEdit, AEM_SETSEL, (WPARAM)NULL, (LPARAM)&aes);
 }


AEM_ISMATCHA
____________

Is ansi text matched with text at specified position.

(AECHARINDEX *)wParam == position to check from.
(AEFINDTEXTA *)lParam == pointer to a AEFINDTEXTA structure.

Return Value
 Length of the matched text or zero if not found.

Example:
 AEFINDTEXTA ft;
 AECHARINDEX ciChar;
 AESELECTION aes;

 ft.dwFlags=AEFR_MATCHCASE;
 ft.pText="SomeText";
 ft.dwTextLen=(DWORD)-1;
 ft.nNewLine=AELB_ASIS;
 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTSELCHAR, (LPARAM)&ciChar);

 if (SendMessage(hWndEdit, AEM_ISMATCHA, (WPARAM)&ciChar, (LPARAM)&ft))
 {
   aes.crSel=ft.crFound;
   aes.dwFlags=0;
   SendMessage(hWndEdit, AEM_SETSEL, (WPARAM)NULL, (LPARAM)&aes);
 }


AEM_ISMATCHW
____________

Is unicode text matched with text at specified position.

(AECHARINDEX *)wParam == position to check from.
(AEFINDTEXTW *)lParam == pointer to a AEFINDTEXTW structure.

Return Value
 Length of the matched text or zero if not found.

Example:
 AEFINDTEXTW ft;
 AECHARINDEX ciChar;
 AESELECTION aes;

 ft.dwFlags=AEFR_MATCHCASE;
 ft.pText=L"SomeText";
 ft.dwTextLen=(DWORD)-1;
 ft.nNewLine=AELB_ASIS;
 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTSELCHAR, (LPARAM)&ciChar);

 if (SendMessage(hWndEdit, AEM_ISMATCHW, (WPARAM)&ciChar, (LPARAM)&ft))
 {
   aes.crSel=ft.crFound;
   aes.dwFlags=0;
   SendMessage(hWndEdit, AEM_SETSEL, (WPARAM)NULL, (LPARAM)&aes);
 }


AEM_KEYDOWN
___________

Emulate key down pressing.

(int)wParam   == virtual-key code.
(DWORD)lParam == see AEMOD_* defines.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_KEYDOWN, VK_RIGHT, AEMOD_SHIFT|AEMOD_CONTROL);


AEM_DRAGDROP
____________

Operations with current drag'n'drop.

(DWORD)wParam == see AEDD_* defines.
lParam        == not used.

Return Value
 Value depended on the AEDD_* define.

Example:
 HWND hWndDragSource;

 hWndDragSource=(HWND)SendMessage(hWndEdit, AEM_DRAGDROP, AEDD_GETDRAGWINDOW, 0);


AEM_CANUNDO
___________

Determine whether there are any actions in an edit control's undo queue.

wParam == not used.
lParam == not used.

Return Value
 TRUE   success.
 FALSE  failed.

Example:
 SendMessage(hWndEdit, AEM_CANUNDO, 0, 0);


AEM_CANREDO
___________

Determine whether there are any actions in an edit control's redo queue.

wParam == not used.
lParam == not used.

Return Value
 TRUE   success.
 FALSE  failed.

Example:
 SendMessage(hWndEdit, AEM_CANREDO, 0, 0);


AEM_UNDO
________

Undo the last edit control operation in the control's undo queue.

wParam == not used.
lParam == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_UNDO, 0, 0);


AEM_REDO
________

Redo the next edit control operation in the control's redo queue.

wParam == not used.
lParam == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_REDO, 0, 0);


AEM_EMPTYUNDOBUFFER
___________________

Erase undo and redo history.

wParam == not used.
lParam == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_EMPTYUNDOBUFFER, 0, 0);


AEM_STOPGROUPTYPING
___________________

Stops the control from collecting additional typing actions into the current undo action.
The control stores the next typing action, if any, into a new action in the undo queue.

wParam == not used.
lParam == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_STOPGROUPTYPING, 0, 0);


AEM_BEGINUNDOACTION
___________________

Beginning of a set of operations that will be undone all as one operation.

wParam == not used.
lParam == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_STOPGROUPTYPING, 0, 0);
 SendMessage(hWndEdit, AEM_BEGINUNDOACTION, 0, 0);
 SendMessage(hWndEdit, EM_REPLACESEL, TRUE, (LPARAM)"123");
 SendMessage(hWndEdit, EM_REPLACESEL, TRUE, (LPARAM)"456");
 SendMessage(hWndEdit, AEM_ENDUNDOACTION, 0, 0);
 SendMessage(hWndEdit, AEM_STOPGROUPTYPING, 0, 0);


AEM_ENDUNDOACTION
_________________

End of a set of operations that will be undone all as one operation.

wParam == not used.
lParam == not used.

Return Value
 zero

Example:
 See AEM_BEGINUNDOACTION example.


AEM_LOCKCOLLECTUNDO
___________________

Stop collect undo/redo history.

(BOOL)wParam == TRUE   stop collect
                FALSE  start collect
lParam       == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_EMPTYUNDOBUFFER, 0, 0);
 SendMessage(hWndEdit, AEM_LOCKCOLLECTUNDO, TRUE, 0);
 SendMessage(hWndEdit, EM_REPLACESEL, TRUE, (LPARAM)"123");
 SendMessage(hWndEdit, EM_REPLACESEL, TRUE, (LPARAM)"456");
 SendMessage(hWndEdit, AEM_LOCKCOLLECTUNDO, FALSE, 0);


AEM_GETUNDOLIMIT
________________

Get the maximum number of actions that can stored in the undo queue.

wParam == not used.
lParam == not used.

Return Value
 Maximum number of actions that can be stored in the undo queue.

Example:
 SendMessage(hWndEdit, AEM_GETUNDOLIMIT, 0, 0);


AEM_SETUNDOLIMIT
________________

Set the maximum number of actions that can stored in the undo queue.

(DWORD)wParam == maximum number of actions that can be stored in the undo queue. By default, the maximum number of actions in the undo queue is unlimited.
lParam        == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_SETUNDOLIMIT, 100, 0);


AEM_GETMODIFY
_____________

Retrieve the state of an edit control's modification flag.

wParam == not used.
lParam == not used.

Return Value
 TRUE   text has been modified.
 FALSE  text has not been modified.

Example:
 SendMessage(hWndEdit, AEM_GETMODIFY, 0, 0);


AEM_SETMODIFY
_____________

Set the state of an edit control's modification flag.

(BOOL)wParam == TRUE   text has been modified.
                FALSE  text has not been modified.
lParam       == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_SETMODIFY, FALSE, 0);


AEM_UNDOBUFFERSIZE
__________________

Get the number of bytes stored in the undo queue.

wParam == not used.
lParam == not used.

Return Value
 Number of bytes.

Example:
 SendMessage(hWndEdit, AEM_UNDOBUFFERSIZE, 0, 0);


AEM_EXGETSEL
____________

Retrieve the current selection information of an edit control. Simple form of AEM_GETSEL.

(AECHARINDEX *)wParam == selection start index. Can be NULL.
(AECHARINDEX *)lParam == selection end index. Can be NULL.

Return Value
 TRUE   selection is not empty.
 FALSE  selection is empty.

Example:
 AECHARRANGE aecr;

 SendMessage(hWndEdit, AEM_EXGETSEL, (WPARAM)&aecr.ciMin, (LPARAM)&aecr.ciMax);


AEM_EXSETSEL
____________

Set the current selection of an edit control. Simple form of AEM_SETSEL.

(AECHARINDEX *)wParam == selection start index.
(AECHARINDEX *)lParam == selection end index.

Return Value
 zero

Example:
 AECHARRANGE aecr;
 BOOL bCaretAtEnd=TRUE;

 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTCHAR, (LPARAM)&aecr.ciMin);
 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_LASTCHAR, (LPARAM)&aecr.ciMax);

 if (bCaretAtEnd)
   SendMessage(hWndEdit, AEM_EXSETSEL, (WPARAM)&aecr.ciMin, (LPARAM)&aecr.ciMax);
 else
   SendMessage(hWndEdit, AEM_EXSETSEL, (WPARAM)&aecr.ciMax, (LPARAM)&aecr.ciMin);


AEM_GETSEL
__________

Retrieve the current selection information of an edit control.

(AECHARINDEX *)wParam == caret index, NULL if not needed.
(AESELECTION *)lParam == pointer to a AESELECTION structure, NULL if not needed.

Return Value
 TRUE   selection is not empty.
 FALSE  selection is empty.

Example:
 AESELECTION aes;
 AECHARINDEX ciCaret;

 SendMessage(hWndEdit, AEM_GETSEL, (WPARAM)&ciCaret, (LPARAM)&aes);


AEM_SETSEL
__________

Set the current selection of an edit control.

(AECHARINDEX *)wParam == caret index, can be NULL.
(AESELECTION *)lParam == pointer to a AESELECTION structure.

Return Value
 zero

Example:
 AESELECTION aes;

 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTCHAR, (LPARAM)&aes.crSel.ciMin);
 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_LASTCHAR, (LPARAM)&aes.crSel.ciMax);
 aes.dwFlags=0;
 SendMessage(hWndEdit, AEM_SETSEL, (WPARAM)&aes.crSel.ciMax, (LPARAM)&aes);


AEM_GETCOLUMNSEL
________________

Retrieve the column mode of the current selection.

wParam == not used.
lParam == not used.

Return Value
 TRUE   selection is in column mode.
 FALSE  selection is in non-column mode.

Example:
 SendMessage(hWndEdit, AEM_GETCOLUMNSEL, 0, 0);


AEM_UPDATESEL
_____________

Update current selection.

(DWORD)wParam == see AESELT_* defines.
lParam        == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_UPDATESEL, AESELT_LOCKSCROLL, 0);


AEM_GETLINENUMBER
_________________

Retrieve the specified line number.

(int)wParam == see AEGL_* defines.
lParam      == not used.

Return Value
 Zero based line number.

Example:
 SendMessage(hWndEdit, AEM_GETLINENUMBER, AEGL_LINECOUNT, 0);


AEM_GETINDEX
____________

Retrieve the specified character index.

(int)wParam           == see AEGI_* defines.
(AECHARINDEX *)lParam == character index.

Return Value
 Zero if failed, non-zero if success.

Example:
 AECHARINDEX ciChar;

 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTCHAR, (LPARAM)&ciChar);


AEM_GETLINEINDEX
________________

Retrieve the first character index in the specified line.

(int)wParam           == zero based line number.
(AECHARINDEX *)lParam == character index.

Return Value
 TRUE   success.
 FALSE  failed.

Example:
 AECHARINDEX ciChar;

 SendMessage(hWndEdit, AEM_GETLINEINDEX, 10, (LPARAM)&ciChar);


AEM_INDEXUPDATE
_______________

Update lpLine member of the AECHARINDEX structure, to avoid dangling of a pointer after text change.

wParam                == not used.
(AECHARINDEX *)lParam == character index.

Return Value
 TRUE   success.
 FALSE  failed.

Example:
 AESELECTION aes;

 SendMessage(hWndEdit, AEM_GETSEL, (WPARAM)NULL, (LPARAM)&aes);
 SendMessage(hWndEdit, EM_REPLACESEL, TRUE, (LPARAM)"123");
 SendMessage(hWndEdit, AEM_INDEXUPDATE, 0, (LPARAM)&aes.crSel.ciMin);
 SendMessage(hWndEdit, AEM_INDEXUPDATE, 0, (LPARAM)&aes.crSel.ciMax);


AEM_INDEXCOMPARE
________________

Compare two character indexes.

(AECHARINDEX *)wParam == first character index.
(AECHARINDEX *)lParam == second character index.

Return Value
 -1  first index is less than second index
  0  first index is equal to second index
  1  first index is greater than second index

Example:
 AESELECTION aes;

 SendMessage(hWndEdit, AEM_GETSEL, (WPARAM)NULL, (LPARAM)&aes);
 SendMessage(hWndEdit, AEM_INDEXCOMPARE, (WPARAM)&aes.crSel.ciMin, (LPARAM)&aes.crSel.ciMax);

For better performance instead of AEM_INDEXCOMPARE message add:
 #define AEC_INDEXCOMPARE
 #include "AkelEdit.h"
And use AEC_IndexCompare call:
 AEC_IndexCompare(&aes.crSel.ciMin, &aes.crSel.ciMax);


AEM_INDEXSUBTRACT
_________________

Retrieve how many characters between two character indexes.

wParam                    == not used.
(AEINDEXSUBTRACT *)lParam == pointer to a AEINDEXSUBTRACT structure.

Return Value
 Number of characters. Negative if AEINDEXSUBTRACT.ciChar1 < AEINDEXSUBTRACT.ciChar2.

Example:
 AEINDEXSUBTRACT is;

 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTCHAR, (LPARAM)&is.ciChar1);
 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_LASTCHAR, (LPARAM)&is.ciChar2);
 is.bColumnSel=FALSE;
 is.nNewLine=AELB_ASIS;
 SendMessage(hWnd, AEM_INDEXSUBTRACT, 0, (LPARAM)&is);


AEM_INDEXOFFSET
_______________

Retrieve the target character index at the specified offset from source character index.

wParam                  == not used.
(AEINDEXOFFSET *)lParam == pointer to a AEINDEXOFFSET structure.

Return Value
 Processed number of characters.

Example:
 AEINDEXOFFSET io;
 AECHARINDEX ciCharIn;
 AECHARINDEX ciCharOut;

 //Get 10 character index of the edit control
 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTCHAR, (LPARAM)&ciCharIn);
 io.ciCharIn=&ciCharIn;
 io.ciCharOut=&ciCharOut;
 io.nOffset=10;
 io.nNewLine=AELB_R;
 SendMessage(hWnd, AEM_INDEXOFFSET, 0, (LPARAM)&io);


AEM_INDEXTORICHOFFSET
_____________________

Convert AkelEdit character index to RichEdit offset.

wParam                == not used.
(AECHARINDEX *)lParam == AkelEdit character index.

Return Value
 RichEdit offset.

Example:
 AECHARRANGE aecr;
 CHARRANGE recr;

 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTVISIBLELINE, (LPARAM)&aecr.ciMin);
 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_LASTVISIBLELINE, (LPARAM)&aecr.ciMax);
 recr.cpMin=SendMessage(hWndEdit, AEM_INDEXTORICHOFFSET, 0, (LPARAM)&aecr.ciMin);
 recr.cpMax=SendMessage(hWndEdit, AEM_INDEXTORICHOFFSET, 0, (LPARAM)&aecr.ciMax);
 SendMessage(hWndEdit, EM_EXSETSEL, 0, (LPARAM)&recr);


AEM_RICHOFFSETTOINDEX
_____________________

Convert RichEdit offset to AkelEdit character index.

(DWORD)wParam         == RichEdit offset.
(AECHARINDEX *)lParam == AkelEdit character index.

Return Value
 zero

Example:
 AECHARRANGE aecr;
 CHARRANGE recr;

 SendMessage(hWndEdit, EM_EXGETSEL, 0, (LPARAM)&recr);
 SendMessage(hWndEdit, AEM_RICHOFFSETTOINDEX, (WPARAM)recr.cpMin, (LPARAM)&aecr.ciMin);
 SendMessage(hWndEdit, AEM_RICHOFFSETTOINDEX, (WPARAM)recr.cpMax, (LPARAM)&aecr.ciMax);


AEM_ADDPOINT
____________

Add character index to a points stack. Character index will be updated after every text change.

wParam                == not used.
(AECHARINDEX *)lParam == AkelEdit character index.

Return Value
 Pointer to a AEPOINT structure.

Example:
 AEPOINT *lpPoint;
 AECHARINDEX ciChar;

 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTSELCHAR, (LPARAM)&ciChar);
 lpPoint=(AEPOINT *)SendMessage(hWndEdit, AEM_ADDPOINT, 0, (LPARAM)&ciChar);
 SendMessage(hWndEdit, EM_REPLACESEL, TRUE, (LPARAM)"123");
 ciChar=lpPoint->ciPoint;  //Read new position
 SendMessage(hWndEdit, AEM_DELPOINT, (WPARAM)lpPoint, 0);


AEM_DELPOINT
____________

Delete character index from points stack.

(AEPOINT *)wParam == pointer to a AEPOINT structure, returned by AEM_ADDPOINT.
lParam            == not used.

Return Value
 zero

Example:
 See AEM_ADDPOINT example.


AEM_GETINDEXCOLUMN
__________________

Retrieve the character index column taking into account tab stop size.

(DWORD)wParam         == low-order word:
                          tab stop size in characters.
                         high-order word:
                          TRUE   scan all wrapped lines.
                          FALSE  scan to first char in line.
(AECHARINDEX *)lParam == AkelEdit character index.

Return Value
 Character index column.

Example:
 AECHARINDEX ciCaret;
 int nTabStop;

 nTabStop=SendMessage(hWndEdit, AEM_GETTABSTOP, 0, 0);
 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_CARETCHAR, (LPARAM)&ciCaret);
 SendMessage(hWndEdit, AEM_GETINDEXCOLUMN, MAKELONG(nTabStop, TRUE), (LPARAM)&ciCaret);


AEM_GETWRAPLINE
_______________

Convert unwrapped line number to wrapped line number.

(int)wParam           == zero based unwrapped line.
(AECHARINDEX *)lParam == returned first character in wrapped line. Can be NULL.

Return Value
 Wrapped line.

Example:
 AECHARINDEX ciChar;

 SendMessage(hWndEdit, AEM_GETWRAPLINE, (WPARAM)10, (LPARAM)&ciChar);


AEM_GETUNWRAPLINE
_________________

Convert wrapped line number to unwrapped line number.

(int)wParam == zero based wrapped line.
lParam      == not used.

Return Value
 Unwrapped line.

Example:
 AECHARINDEX ciCaret;
 int nUnwrappedLine;

 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_CARETCHAR, (LPARAM)&ciCaret);

 if (SendMessage(hWndEdit, AEM_GETWORDWRAP, 0, (LPARAM)NULL))
   nUnwrappedLine=SendMessage(hWndEdit, AEM_GETUNWRAPLINE, (WPARAM)ciCaret.nLine, 0);
 else
   nUnwrappedLine=ciCaret.nLine;


AEM_GETNEXTBREAK
________________

Retrieve next word break index.

(DWORD)wParam         == see AEWB_* defines. If zero, use current word break settings, see AEM_SETWORDBREAK message.
(AECHARINDEX *)lParam == character index (input/output).

Return Value
 Number of characters to break.

Example:
 AECHARINDEX ciCaret;

 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_CARETCHAR, (LPARAM)&ciCaret);
 SendMessage(hWndEdit, AEM_GETNEXTBREAK, AEWB_RIGHTWORDSTART|AEWB_RIGHTWORDEND, (LPARAM)&ciCaret);


AEM_GETPREVBREAK
________________

Retrieve previous word break index.

(DWORD)wParam         == see AEWB_* defines. If zero, use current word break settings, see AEM_SETWORDBREAK message.
(AECHARINDEX *)lParam == character index (input/output).

Return Value
 Number of characters to break.

Example:
 AECHARINDEX ciCaret;

 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_CARETCHAR, (LPARAM)&ciCaret);
 SendMessage(hWndEdit, AEM_GETPREVBREAK, AEWB_LEFTWORDSTART|AEWB_LEFTWORDEND, (LPARAM)&ciCaret);


AEM_ISDELIMITER
_______________

Retrieve character index delimiter or not.

(DWORD)wParam         == see AEDLM_* defines.
(AECHARINDEX *)lParam == character index.

Return Value
 TRUE   character index is a delimiter.
 FALSE  character index isn't a delimiter.

Example:
 AECHARINDEX ciChar;

 SendMessage(hWndEdit, AEM_ISDELIMITER, AEDLM_WORD, (LPARAM)&ciChar);


AEM_CHARFROMPOS
_______________

Retrieve the closest wide character to a specified point in the client area of an edit control.

(POINT *)wParam       == coordinates of a point in the control's client area.
(AECHARINDEX *)lParam == character index.

Return Value
 See AEPC_* defines.

Example:
 RECT rc;
 AECHARINDEX ciFirstVisible;

 SendMessage(hWndEdit, AEM_GETRECT, 0, (LPARAM)&rc);
 SendMessage(hWndEdit, AEM_CHARFROMPOS, (WPARAM)&rc.left, (LPARAM)&ciFirstVisible);


AEM_POSFROMCHAR
_______________

Retrieve the client area coordinates of a specified character in an edit control.

(POINT *)wParam       == coordinates of a point in the control's client area.
(AECHARINDEX *)lParam == character index.

Return Value
 See AEPC_* defines.

Example:
 POINT pt;
 AECHARINDEX ciChar;

 SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTVISIBLELINE, (LPARAM)&ciChar);
 SendMessage(hWndEdit, AEM_POSFROMCHAR, (WPARAM)&pt, (LPARAM)&ciChar);


AEM_GETRECT
___________

Retrieve the formatting rectangle of an edit control. The formatting rectangle is the limiting rectangle into which the control draws the text.

wParam         == not used.
(RECT *)lParam == pointer to a RECT structure that receives the formatting rectangle.

Return Value
 zero

Example:
 RECT rc;

 SendMessage(hWndEdit, AEM_GETRECT, 0, (LPARAM)&rc);


AEM_SETRECT
___________

Set the formatting rectangle of an edit control. The formatting rectangle is the limiting rectangle into which the control draws the text.

(BOOL)wParam   == TRUE   redraw edit window.
                  FALSE  don't redraw edit window.
(RECT *)lParam == pointer to a RECT structure that specifies the new dimensions of the rectangle. If this parameter is NULL, the formatting rectangle is set to its default values.

Return Value
 zero

Example:
 RECT rc;

 rc.left=10;
 rc.top=10;
 rc.right=200;
 rc.bottom=200;
 SendMessage(hWndEdit, AEM_SETRECT, TRUE, (LPARAM)&rc);


AEM_GETSCROLLPOS
________________

Obtain the current and/or maximum scroll position of the edit control.

(POINT *)wParam == pointer to a POINT structure that receives the maximum scroll position in the virtual text space of the document, expressed in pixels. Can be NULL.
(POINT *)lParam == pointer to a POINT structure that receives the upper-left corner position in the virtual text space of the document, expressed in pixels. Can be NULL.

Return Value
 zero

Example:
 POINT ptMax;
 POINT ptPos;

 SendMessage(hWndEdit, AEM_GETSCROLLPOS, (WPARAM)&ptMax, (LPARAM)&ptPos);


AEM_SETSCROLLPOS
________________

Scroll an edit control to a particular point.

wParam          == not used.
(POINT *)lParam == pointer to a POINT structure which specifies a point in the virtual text space of the document, expressed in pixels.

Return Value
 zero

Example:
 POINT pt;

 pt.x=20;
 pt.y=10;
 SendMessage(hWndEdit, AEM_SETSCROLLPOS, 0, (LPARAM)&pt);


AEM_SCROLL
__________

Scroll the text horizontally or vertically in an edit control. This message is equivalent of WM_HSCROLL and WM_VSCROLL.

(DWORD)wParam == see AESB_* defines.
(int)lParam   == action that can be specified with AESB_HORZ:
                  SB_LINELEFT  scrolls left by one character.
                  SB_LINERIGHT scrolls right by one character.
                  SB_PAGELEFT  scrolls left by the width of the window.
                  SB_PAGERIGHT scrolls right by the width of the window.
                  SB_LEFT      scrolls to the most left.
                  SB_RIGHT     scrolls to the most right.
                 action that can be specified with AESB_VERT:
                  SB_LINEUP    scrolls one line up.
                  SB_LINEDOWN  scrolls one line down.
                  SB_PAGEUP    scrolls one page up.
                  SB_PAGEDOWN  scrolls one page down.
                  SB_TOP       scrolls to the most up.
                  SB_BOTTOM    scrolls to the most down.

Return Value
 Pixels scrolled.

Example:
 SendMessage(hWndEdit, AEM_SCROLL, AESB_VERT, SB_LINEDOWN);


AEM_LINESCROLL
______________

Scroll the text horizontally or vertically on the specified number of characters or lines.

(DWORD)wParam == see AESB_* defines.
(int)lParam   == If AESB_HORZ specified, the number of characters to scroll horizontally.
                 If AESB_VERT specified, the number of lines to scroll vertically.

Return Value
 Pixels scrolled.

Example:
 SendMessage(hWndEdit, AEM_LINESCROLL, AESB_VERT, -10);


AEM_SCROLLCARET
_______________

Scroll the caret into view in an edit control.

(DWORD)wParam == see AESC_* defines.
(DWORD)lParam == the low-order word contains the horizontal scroll unit,
                 the high-order word contains the vertical scroll unit.

Return Value
 See AECSE_* defines.

Example:
 SendMessage(hWndEdit, AEM_SCROLLCARET, AESC_UNITCHARX|AESC_UNITCHARY, MAKELONG(1, 1));


AEM_SCROLLCARETTEST
___________________

Same as AEM_SCROLLCARET, but only test for scroll.

(DWORD)wParam == see AESC_* defines.
(DWORD)lParam == the low-order word contains the horizontal scroll unit,
                 the high-order word contains the vertical scroll unit.

Return Value
 See AECSE_* defines.

Example:
 SendMessage(hWndEdit, AEM_SCROLLCARETTEST, AESC_UNITCHARX|AESC_UNITCHARY, MAKELONG(1, 1));


AEM_LOCKSCROLL
______________

Lock scrolling of an edit control.

(int)wParam  == SB_BOTH  lock horizontal and vertical scroll.
                SB_HORZ  lock horizontal scroll.
                SB_VERT  lock vertical scroll.
(BOOL)lParam == TRUE   lock scroll.
                FALSE  unlock scroll.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_LOCKSCROLL, SB_BOTH, TRUE);
 SendMessage(hWndEdit, EM_SETSEL, (WPARAM)-1, (LPARAM)-1);
 SendMessage(hWndEdit, AEM_LOCKSCROLL, SB_BOTH, FALSE);


AEM_GETERASERECT
________________

Retrieve the erasing rectangle of an edit control. Make sense in WM_ERASEBKGND respond.

wParam         == not used.
(RECT *)lParam == pointer to a RECT structure that receives the erasing rectangle.

Return Value
 zero

Example:
 if (uMsg == WM_ERASEBKGND)
 {
   RECT rcErase;

   SendMessage(hWndEdit, AEM_GETERASERECT, 0, (LPARAM)&rcErase);
   if (rcErase.left < 10)
   {
     //Don't erase left 10 pixels, to avoid flashing.
     rcErase.left=10;
     SendMessage(hWndEdit, AEM_SETERASERECT, 0, (LPARAM)&rcErase);
   }
 }

AEM_SETERASERECT
________________

Set the erasing rectangle of an edit control. Make sense in WM_ERASEBKGND respond.

wParam         == not used.
(RECT *)lParam == pointer to a RECT structure that specifies the new dimensions of the rectangle.

Return Value
 zero

Example:
 See AEM_GETERASERECT example.


AEM_GETCHARSIZE
_______________

Retrieve current font character height and average width.

(DWORD)wParam == see AECS_* defines.
lParam        == not used.

Return Value
 Integer that depend on AECS_* value.

Example:
 SendMessage(hWndEdit, AEM_GETCHARSIZE, AECS_HEIGHT, 0);


AEM_GETSTRWIDTH
_______________

Retrieve string width. Uses the currently selected font.

(wchar_t *)wParam == unicode string.
(int)lParam       == string length.

Return Value
 String width.

Example:
 SendMessage(hWndEdit, AEM_GETSTRWIDTH, (WPARAM)L"ABC", 3);


AEM_GETCARETPOS
_______________

Obtain the current caret position.

(POINT *)wParam == pointer to a POINT structure that receives the caret position in the client area coordinates, expressed in pixels. Can be NULL.
(POINT *)lParam == pointer to a POINT structure that receives the caret position in the virtual text space of the document, expressed in pixels. Can be NULL.

Return Value
 TRUE   caret is visible.
 FALSE  caret isn't visible.

Example:
 POINT ptClient;
 POINT ptGlobal;

 SendMessage(hWndEdit, AEM_GETCARETPOS, (LPARAM)&ptClient, (WPARAM)&ptGlobal);


AEM_GETCARETHORZINDENT
______________________

Retrieve caret horizontal indent. It's unchanged after VK_UP, VK_DOWN, VK_PRIOR, VK_NEXT key pressed.

wParam == not used.
lParam == not used.

Return Value
 Caret horizontal indent in the virtual text space of the document.

Example:
 SendMessage(hWndEdit, AEM_GETCARETHORZINDENT, 0, 0);


AEM_SETCARETHORZINDENT
______________________

Set caret horizontal indent. It's unchanged after VK_UP, VK_DOWN, VK_PRIOR, VK_NEXT key pressed.

(DWORD)wParam == caret horizontal indent in the virtual text space of the document.
lParam        == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_SETCARETHORZINDENT, 10, 0);


AEM_CONVERTPOINT
________________

Convert position coordinates.

(DWORD)wParam   == see AECPT_* defines.
(POINT *)lParam == pointer to a POINT structure.

Return Value
 zero

Example:
 POINT pt;

 pt.x=SendMessage(hWndEdit, AEM_GETCARETHORZINDENT, 0, 0);
 pt.y=0;
 SendMessage(hWndEdit, AEM_CONVERTPOINT, AECPT_GLOBALTOCLIENT, (LPARAM)&pt);


AEM_CONTROLCLASS
________________

Retrieve control class AkelEdit or RichEdit.

wParam == not used.
lParam == not used.

Return Value
 See AECLASS_* defines.

Example:
 SendMessage(hWndEdit, AEM_CONTROLCLASS, 0, 0);


AEM_CONTROLVERSION
__________________

Retrieve control version.

wParam == not used.
lParam == not used.

Return Value
 Version number. Created as: MAKE_IDENTIFIER(dwMajor, dwMinor, dwRelease, dwBuild).

Example:
 DWORD dwVersion;
 DWORD dwMajor;
 DWORD dwMinor;
 DWORD dwRelease;
 DWORD dwBuild;

 dwVersion=SendMessage(hWndEdit, AEM_CONTROLVERSION, 0, 0);
 dwMajor=LOBYTE(LOWORD(dwVersion));
 dwMinor=HIBYTE(LOWORD(dwVersion));
 dwRelease=LOBYTE(HIWORD(dwVersion));
 dwBuild=HIBYTE(HIWORD(dwVersion));


AEM_GETEVENTMASK
________________

Retrieve the event mask for an edit control. The event mask specifies which notification messages the control sends to its parent window.

wParam == not used.
lParam == not used.

Return Value
 See AENM_* defines.

Example:
 SendMessage(hWndEdit, AEM_GETEVENTMASK, 0, 0);


AEM_SETEVENTMASK
________________

Set the event mask for an edit control. The event mask specifies which notification messages the control sends to its parent window.

wParam        == not used.
(DWORD)lParam == see AENM_* defines.

Return Value
 Previous event mask.

Example:
 SendMessage(hWndEdit, AEM_SETEVENTMASK, 0, AENM_SELCHANGE|AENM_TEXTCHANGE|AENM_MODIFY);


AEM_GETOPTIONS
______________

Retrieve edit control options.

wParam == not used.
lParam == not used.

Return Value
 Combination of the current option flag values. See AECO_* defines.

Example:
 SendMessage(hWndEdit, AEM_GETOPTIONS, 0, 0);


AEM_SETOPTIONS
______________

Set the options for an edit control.

(DWORD)wParam == see AECOOP_* defines.
(DWORD)lParam == see AECO_* defines.

Return Value
 Current option of edit control.

Example 1:
 SendMessage(hWndEdit, AEM_SETOPTIONS, AECOOP_OR, AECO_DISABLEDRAG|AECO_DISABLEDROP);

Example 2:
 if (bDisableNoScroll)
 {
   SendMessage(hWndEdit, AEM_SETOPTIONS, AECOOP_OR, AECO_DISABLENOSCROLL);
   ShowScrollBar(hWndEdit, SB_BOTH, TRUE);
   SetScrollRange(hWndEdit, SB_HORZ, 0, 100, TRUE);
   SetScrollRange(hWndEdit, SB_VERT, 0, 100, TRUE);
   SendMessage(hWndEdit, AEM_UPDATESCROLLBAR, SB_BOTH, 0);
 }
 else
 {
   SendMessage(hWndEdit, AEM_SETOPTIONS, AECOOP_XOR, AECO_DISABLENOSCROLL);
   ShowScrollBar(hWndEdit, SB_BOTH, TRUE);
   SendMessage(hWndEdit, AEM_UPDATESCROLLBAR, SB_BOTH, 0);
 }


AEM_GETNEWLINE
______________

Retrieve the default new line options for an edit control.

wParam == not used.
lParam == not used.

Return Value
 The low-order word contains the default input new line.
 The high-order word contains the default output new line.

Remarks
 Possible new lines: AELB_ASIS, AELB_R, AELB_N, AELB_RN, AELB_RRN.

Example:
 SendMessage(hWndEdit, AEM_GETNEWLINE, 0, 0);


AEM_SETNEWLINE
______________

Set the default new line options for an edit control.

(DWORD)wParam == see AENL_* defines.
(DWORD)lParam == the low-order word contains the default input new line. Valid if AENL_INPUT is specified.
                 the high-order word contains the default output new line. Valid if AENL_OUTPUT is specified.

Return Value
 zero

Remarks
 Possible new lines: AELB_ASIS, AELB_R, AELB_N, AELB_RN, AELB_RRN.

Example:
 SendMessage(hWndEdit, AEM_SETNEWLINE, AENL_INPUT|AENL_OUTPUT, MAKELONG(AELB_R, AELB_RN));


AEM_GETCOLORS
_____________

Retrieve colors of the edit control.

wParam             == not used.
(AECOLORS *)lParam == pointer to a AECOLORS structure.

Return Value
 zero

Example:
 AECOLORS aec;

 aec.dwFlags=AECLR_ALL;
 SendMessage(hWndEdit, AEM_GETCOLORS, 0, (LPARAM)&aec);


AEM_SETCOLORS
_____________

Set colors of the edit control.

wParam             == not used.
(AECOLORS *)lParam == pointer to a AECOLORS structure.

Return Value
 zero

Example:
 AECOLORS aec;

 aec.dwFlags=AECLR_BASICTEXT|AECLR_BASICBK;
 aec.crBasicText=GetSysColor(COLOR_WINDOWTEXT);
 aec.crBasicBk=GetSysColor(COLOR_WINDOW);
 SendMessage(hWndEdit, AEM_SETCOLORS, 0, (LPARAM)&aec);


AEM_GETDETECTURL
________________

Retrieve whether the URL detection is turned on.

wParam == not used.
lParam == not used.

Return Value
 TRUE   URL detection is on.
 FALSE  URL detection is off.

Example:
 SendMessage(hWndEdit, AEM_GETDETECTURL, 0, 0);


AEM_SETDETECTURL
________________

Enables or disables detection and highligthing of URLs by an edit control.

(BOOL)wParam == TRUE   enable URL detection.
                FALSE  disable URL detection.
lParam       == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_SETDETECTURL, TRUE, 0);


AEM_GETOVERTYPE
_______________

Retrieve type mode.

wParam == not used.
lParam == not used.

Return Value
 TRUE   control is in overtype mode.
 FALSE  control is in insert mode.

Example:
 SendMessage(hWndEdit, AEM_GETOVERTYPE, 0, 0);


AEM_SETOVERTYPE
_______________

Set type mode.

(BOOL)wParam == TRUE   sets overtype mode.
                FALSE  sets insert mode.
lParam       == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_SETOVERTYPE, TRUE, 0);


AEM_GETCARETWIDTH
_________________

Retrieve caret width.

wParam          == not used.
(POINT *)lParam == pointer to a POINT structure that receives the insert mode caret width in x member and overtype mode caret height in y member.

Return Value
 zero

Example:
 POINT pt;

 SendMessage(hWndEdit, AEM_GETCARETWIDTH, 0, (LPARAM)&pt);


AEM_SETCARETWIDTH
_________________

Set caret width.

wParam          == not used.
(POINT *)lParam == pointer to a POINT structure which specifies the insert mode caret width in x member and overtype mode caret height in y member.

Return Value
 zero

Example:
 POINT pt;

 pt.x=2;
 pt.y=3;
 SendMessage(hWndEdit, AEM_SETCARETWIDTH, 0, (LPARAM)&pt);


AEM_GETTABSTOP
______________

Retrieve tab stop size.

wParam == not used.
lParam == not used.

Return Value
 Tab stop size in characters.

Example:
 SendMessage(hWndEdit, AEM_GETTABSTOP, 0, 0);


AEM_SETTABSTOP
______________

Set tab stop size.

(int)wParam == new tab stop size in characters.
lParam      == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_SETTABSTOP, 4, 0);


AEM_GETWORDWRAP
_______________

Retrieve word wrap mode.

wParam          == not used.
(DWORD *)lParam == pointer to a variable that receives wrap limit number. Can be NULL.

Return Value
 See AEWW_* defines.

Example:
 DWORD dwWrapLimit;

 SendMessage(hWndEdit, AEM_GETWORDWRAP, 0, (LPARAM)&dwWrapLimit);


AEM_SETWORDWRAP
_______________

Set word wrap mode.

(DWORD)wParam == see AEWW_* defines.
(int)lParam   == wrap limit, if zero window right edge is used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_SETWORDWRAP, AEWW_WORD, 0);


AEM_GETWORDDELIMITERS
_____________________

Retrieve word break delimiters.

(int)wParam       == size of the buffer in TCHARs.
(wchar_t *)lParam == pointer to a buffer that receives delimiter characters.

Return Value
 zero

Example:
 wchar_t wszDelimiters[128];

 SendMessage(hWndEdit, AEM_GETWORDDELIMITERS, 128, (LPARAM)wszDelimiters);


AEM_SETWORDDELIMITERS
_____________________

Set word break delimiters.

wParam            == not used.
(wchar_t *)lParam == string that specifies delimiter characters. If NULL, then default delimiters will be used.

Return Value
 zero

Example:
 wchar_t wszDelimiters[128]=L" \t\n[](){}<>";

 SendMessage(hWndEdit, AEM_SETWORDDELIMITERS, 0, (LPARAM)wszDelimiters);


AEM_GETWRAPDELIMITERS
_____________________

Retrieve word wrapping delimiters.

(int)wParam       == size of the buffer in TCHARs.
(wchar_t *)lParam == pointer to a buffer that receives delimiter characters.

Return Value
 zero

Example:
 wchar_t wszDelimiters[128];

 SendMessage(hWndEdit, AEM_GETWRAPDELIMITERS, 128, (LPARAM)wszDelimiters);


AEM_SETWRAPDELIMITERS
_____________________

Set delimiters for word wrapping.

wParam            == not used.
(wchar_t *)lParam == string that specifies delimiter characters. If NULL, then default delimiters will be used.

Return Value
 zero

Example:
 wchar_t wszDelimiters[128]=L" \t\n[](){}<>";

 SendMessage(hWndEdit, AEM_SETWRAPDELIMITERS, 0, (LPARAM)wszDelimiters);


AEM_GETURLLEFTDELIMITERS
________________________

Retrieve URL left delimiters.

(int)wParam       == size of the buffer in TCHARs.
(wchar_t *)lParam == pointer to a buffer that receives delimiter characters.

Return Value
 zero

Example:
 wchar_t wszDelimiters[128];

 SendMessage(hWndEdit, AEM_GETURLLEFTDELIMITERS, 128, (LPARAM)wszDelimiters);


AEM_SETURLLEFTDELIMITERS
________________________

Set left delimiters for URL detection.

wParam            == not used.
(wchar_t *)lParam == string that specifies delimiter characters. If NULL, then default delimiters will be used.

Return Value
 zero

Example:
 wchar_t wszDelimiters[128]=L" \t\n'`\"(<{[=";

 SendMessage(hWndEdit, AEM_SETURLLEFTDELIMITERS, 0, (LPARAM)wszDelimiters);


AEM_GETURLRIGHTDELIMITERS
________________________

Retrieve URL right delimiters.

(int)wParam       == size of the buffer in TCHARs.
(wchar_t *)lParam == pointer to a buffer that receives delimiter characters.

Return Value
 zero

Example:
 wchar_t wszDelimiters[128];

 SendMessage(hWndEdit, AEM_GETURLRIGHTDELIMITERS, 128, (LPARAM)wszDelimiters);


AEM_SETURLRIGHTDELIMITERS
________________________

Set right delimiters for URL detection.

wParam            == not used.
(wchar_t *)lParam == string that specifies delimiter characters. If NULL, then default delimiters will be used.

Return Value
 zero

Example:
 wchar_t wszDelimiters[128]=L" \t\n'`\")>}]";

 SendMessage(hWndEdit, AEM_SETURLRIGHTDELIMITERS, 0, (LPARAM)wszDelimiters);


AEM_GETURLPREFIXES
__________________

Retrieve URL prefixes.

(int)wParam       == size of the buffer in TCHARs.
(wchar_t *)lParam == pointer to a buffer that receives pairs of null-terminated prefixes strings. The last string terminated by two NULL characters.

Return Value
 zero

Example:
 wchar_t wszPrefixes[128];

 SendMessage(hWndEdit, AEM_GETURLPREFIXES, 128, (LPARAM)wszPrefixes);


AEM_SETURLPREFIXES
__________________

Set prefixes for URL detection.

wParam            == not used.
(wchar_t *)lParam == buffer containing pairs of null-terminated prefixes strings. The last string in the buffer must be terminated by two NULL characters. If NULL, then default prefixes will be used.

Return Value
 Number of prefixes strings.

Example:
 wchar_t wszPrefixes[128]=L"http:\0https:\0www.\0ftp:\0file:\0mailto:\0\0"

 SendMessage(hWndEdit, AEM_SETURLPREFIXES, 0, (LPARAM)wszPrefixes);


AEM_GETURLMAXLENGTH
___________________

Retrieve URL maximum length.

wParam == not used.
lParam == not used.

Return Value
 URL maximum length.

Example:
 SendMessage(hWndEdit, AEM_GETURLMAXLENGTH, 0, 0);


AEM_SETURLMAXLENGTH
___________________

Set URL maximum length.

(DWORD)wParam == URL maximum length (default is 512).
lParam        == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_SETURLMAXLENGTH, 1024, 0);


AEM_GETWORDBREAK
________________

Retrieve word break movement.

wParam == not used.
lParam == not used.

Return Value
 See AEWB_* defines.

Example:
 SendMessage(hWndEdit, AEM_GETWORDBREAK, 0, 0);


AEM_SETWORDBREAK
________________

Set word break movement.

(DWORD)wParam == see AEWB_* defines.
lParam        == not used.

Return Value
 Previous word break movement. See AEWB_* defines.

Example:
 SendMessage(hWndEdit, AEM_SETWORDBREAK, AEWB_LEFTWORDSTART|AEWB_RIGHTWORDSTART, 0);


AEM_GETMARKER
_____________

Retrieve marker column.

(int *)wParam == pointer to a variable that receives marker type, see AEMT_* defines. Can be NULL.
lParam        == not used.

Return Value
 Column number, zero if no marker set.

Example:
 SendMessage(hWndEdit, AEM_GETMARKER, (WPARAM)NULL, 0);


AEM_SETMARKER
_____________

Set marker at specified position.

(int)wParam == see AEMT_* defines.
(int)lParam == integer, zero to clear marker.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_SETMARKER, AEMT_SYMBOL, 80);


AEM_GETLINEGAP
______________

Retrieve character external leading.

wParam == not used.
lParam == not used.

Return Value
 Line gap (external leading).

Example:
 SendMessage(hWndEdit, AEM_GETLINEGAP, 0, 0);


AEM_SETLINEGAP
______________

Set character external leading.

(int)wParam == line gap (external leading), default is zero.
lParam      == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_SETLINEGAP, 3, 0);


AEM_SHOWSCROLLBAR
_________________

Show or hide scroll bars in the edit control.

(int)wParam  == SB_BOTH  horizontal and vertical scroll bars.
                SB_HORZ  horizontal scroll bar.
                SB_VERT  vertical scroll bar.
(BOOL)lParam == TRUE   show.
                FALSE  hide.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_SHOWSCROLLBAR, SB_BOTH, FALSE);


AEM_UPDATESCROLLBAR
___________________

Update scroll bars in the edit control.

(int)wParam  == SB_BOTH  horizontal and vertical scroll bars.
                SB_HORZ  horizontal scroll bar.
                SB_VERT  vertical scroll bar.
lParam       == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_UPDATESCROLLBAR, SB_BOTH, 0);


AEM_UPDATECARET
_______________

Update caret in the edit control.

wParam == not used.
lParam == not used.

Return Value
 TRUE   window has focus.
 FALSE  window hasn't focus.

Example:
 SendMessage(hWndEdit, AEM_UPDATECARET, 0, 0);


AEM_HIDESELECTION
_________________

Hides or shows the selection in an edit control.

(BOOL)wParam == TRUE   hide selection.
                FALSE  show selection.
lParam       == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_HIDESELECTION, TRUE, 0);


AEM_GETWINDOWDATA
_________________

Retrieve window data handle.

wParam == not used.
lParam == not used.

Return Value
 Window data handle.

Example:
 HANDLE hHandle=(HANDLE)SendMessage(hWndEdit, AEM_GETWINDOWDATA, 0, 0);


AEM_SETWINDOWDATA
_________________

Associate new window data handle.

(HANDLE)wParam == window data handle.
lParam         == not used.

Return Value
 Old window data handle.

Example:
 See AEM_CREATEWINDOWDATA example.


AEM_CREATEWINDOWDATA
____________________

Create new window data handle.

wParam                 == not used.
(CREATESTRUCT *)lParam == pointer to a CREATESTRUCT structure.

Return Value
 Created window data handle.

Example:
 CREATESTRUCTA cs;
 HANDLE hHandleNew;
 HANDLE hHandleOld;

 cs.lpCreateParams=NULL;
 cs.hInstance=GetModuleHandle(NULL);
 cs.hMenu=(HMENU)100;
 cs.hwndParent=GetParent(hWndEdit);
 cs.cy=CW_USEDEFAULT;
 cs.cx=CW_USEDEFAULT;
 cs.y=CW_USEDEFAULT;
 cs.x=CW_USEDEFAULT;
 cs.style=WS_CHILD|WS_VISIBLE|WS_HSCROLL|WS_VSCROLL|ES_DISABLENOSCROLL;
 cs.lpszName=NULL;
 cs.lpszClass=AES_AKELEDITCLASSA;
 cs.dwExStyle=WS_EX_CLIENTEDGE;

 hHandleNew=(HANDLE)SendMessage(hWndEdit, AEM_CREATEWINDOWDATA, 0, (LPARAM)&cs);
 hHandleOld=(HANDLE)SendMessage(hWndEdit, AEM_SETWINDOWDATA, (WPARAM)hHandleNew, 0);
 SendMessage(hWndEdit, AEM_UPDATESCROLLBAR, SB_BOTH, 0);
 SendMessage(hWndEdit, AEM_UPDATECARET, 0, 0);
 InvalidateRect(hWndEdit, NULL, TRUE);


AEM_DELETEWINDOWDATA
____________________

Destroys window data handle.

(HANDLE)wParam == window data handle.
lParam         == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_DELETEWINDOWDATA, (WPARAM)hHandle, 0);


AEM_ADDCLONE
____________

Adds clone to the master window. Message sended to a master window which will be cloned.

(HWND)wParam == edit control handle which become a clone. Text of the master and clone windows will be the same.
lParam       == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_ADDCLONE, (HWND)hWndEdit2, 0);


AEM_DELCLONE
____________

Removes clone from the master window. Message sended to a master window.

(HWND)wParam == edit control handle that will lose clone status. Text of the clone window will be restored.
lParam       == not used.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_DELCLONE, (HWND)hWndEdit2, 0);


AEM_GETMASTER
_____________

Retrieve master window handle. Message sended to a master or slave window.

wParam == not used.
lParam == not used.

Return Value
 Master window handle.

Example:
 HWND hWndMaster;

 if (hWndMaster=(HWND)SendMessage(hWndEdit, AEM_GETMASTER, 0, 0))
 {
   if (hWndMaster == hWndEdit)
     MessageBox(NULL, "hWndEdit is master", NULL, 0);
   else
     MessageBox(NULL, "hWndEdit is slave", NULL, 0);
 }
 else MessageBox(NULL, "hWndEdit nor master, nor slave", NULL, 0);


AEM_GETCLONE
____________

Retrieve clone window handle. Message sended to a master window.

(DWORD)wParam == zero based clone index.
lParam        == not used.

Return Value
 Clone window handle.

Example:
 SendMessage(hWndEdit, AEM_GETCLONE, 2, 0);


AEM_STARTPRINTDOC
_________________

Prepare document printing.

wParam            == not used.
(AEPRINT *)lParam == pointer to a AEPRINT structure.

Return Value
 Document handle.

Example:
 PRINTDLGA pdlg={0};
 DOCINFOA di={0};
 AEPRINT prn;
 HANDLE hPrintDoc;
 BOOL bPrintStop=FALSE;

 //Choose printer
 pdlg.lStructSize=sizeof(PRINTDLGA);
 pdlg.hwndOwner=hWndEdit;
 pdlg.Flags=PD_ALLPAGES|PD_NOPAGENUMS|PD_RETURNDC|PD_USEDEVMODECOPIESANDCOLLATE;
 pdlg.nCopies=1;
 if (!PrintDlgA(&pdlg)) return;

 //Set print settings
 prn.dwFlags=AEPRN_INHUNDREDTHSOFMILLIMETERS|AEPRN_WRAPWORD;
 prn.hPrinterDC=pdlg.hDC;
 prn.hEditFont=(HFONT)SendMessage(hWndEdit, WM_GETFONT, 0, 0);
 prn.rcMargins.left=1000;
 prn.rcMargins.top=1000;
 prn.rcMargins.right=1000;
 prn.rcMargins.bottom=1000;
 if (pdlg.Flags & PD_SELECTION)
 {
   SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTSELCHAR, (LPARAM)&prn.crText.ciMin);
   SendMessage(hWndEdit, AEM_GETINDEX, AEGI_LASTSELCHAR, (LPARAM)&prn.crText.ciMax);
 }
 else
 {
   SendMessage(hWndEdit, AEM_GETINDEX, AEGI_FIRSTCHAR, (LPARAM)&prn.crText.ciMin);
   SendMessage(hWndEdit, AEM_GETINDEX, AEGI_LASTCHAR, (LPARAM)&prn.crText.ciMax);
 }

 //Document properties
 di.cbSize=sizeof(DOCINFOA);
 di.lpszDocName="AkelEdit document";
 if (pdlg.Flags & PD_PRINTTOFILE)
   di.lpszOutput="FILE:";

 //Start document
 if (StartDocA(pdlg.hDC, &di) > 0)
 {
   if (hPrintDoc=(HANDLE)SendMessage(hWndEdit, AEM_STARTPRINTDOC, 0, (LPARAM)&prn))
   {
     while (!bPrintStop)
     {
       if (StartPage(prn.hPrinterDC) > 0)
       {
         //Print page
         if (!SendMessage(hWndEdit, AEM_PRINTPAGE, (WPARAM)hPrintDoc, (LPARAM)&prn))
           bPrintStop=TRUE;

         if (EndPage(prn.hPrinterDC) <= 0)
           bPrintStop=TRUE;
       }
       else bPrintStop=TRUE;
     }
     SendMessage(hWndEdit, AEM_ENDPRINTDOC, (WPARAM)hPrintDoc, (LPARAM)&prn);
   }
   EndDoc(pdlg.hDC);
 }
 DeleteDC(pdlg.hDC);
 pdlg.hDC=NULL;


AEM_PRINTPAGE
_____________

Print page.

(HANDLE)wParam    == document handle returned by AEM_STARTPRINTDOC.
(AEPRINT *)lParam == pointer to a AEPRINT structure.

Return Value
 TRUE   page is printed and there is more text for printing.
 FALSE  page is printed and there is no more text for printing.

Example:
 See AEM_STARTPRINTDOC example.


AEM_ENDPRINTDOC
_______________

Close print document handle.

(HANDLE)wParam    == document handle returned by AEM_STARTPRINTDOC.
(AEPRINT *)lParam == pointer to a AEPRINT structure.

Return Value
 zero

Example:
 See AEM_STARTPRINTDOC example.


AEM_HLCREATETHEMEA
__________________

Create empty highlight theme.

wParam         == not used.
(char *)lParam == ansi theme name.

Return Value
 Theme handle.

Example:
 HANDLE hTheme;
 AEDELIMITEMA di;
 AEWORDITEMA wi;
 AEQUOTEITEMA qi;
 AEMARKRANGEITEM mri;
 AEMARKTEXTITEMA mti;

 if (hTheme=(HANDLE)SendMessage(hWndEdit, AEM_HLCREATETHEMEA, 0, (LPARAM)"MyTheme"))
 {
   di.pDelimiter=" ";
   di.nDelimiterLen=lstrlenA(di.pDelimiter);
   di.dwFlags=AEHLF_MATCHCASE;
   di.crText=(DWORD)-1;
   di.crBk=(DWORD)-1;
   SendMessage(hWndEdit, AEM_HLADDDELIMITERA, (WPARAM)hTheme, (LPARAM)&di);

   wi.pWord="for";
   wi.nWordLen=lstrlenA(wi.pWord);
   wi.dwFlags=AEHLF_MATCHCASE;
   wi.crText=RGB(0x00, 0xFF, 0x00);
   wi.crBk=(DWORD)-1;
   SendMessage(hWndEdit, AEM_HLADDWORDA, (WPARAM)hTheme, (LPARAM)&wi);

   qi.pQuoteStart="\"";
   qi.nQuoteStartLen=lstrlenA(qi.pQuoteStart);
   qi.pQuoteEnd="\"";
   qi.nQuoteEndLen=lstrlenA(qi.pQuoteEnd);
   qi.chEscape='\\';
   qi.dwFlags=AEHLF_MATCHCASE;
   qi.crText=RGB(0x00, 0x00, 0xFF);
   qi.crBk=(DWORD)-1;
   SendMessage(hWndEdit, AEM_HLADDQUOTEA, (WPARAM)hTheme, (LPARAM)&qi);

   mri.crMarkRange.cpMin=10;
   mri.crMarkRange.cpMax=20;
   mri.dwFlags=0;
   mri.crText=RGB(0xFF, 0x00, 0x00);
   mri.crBk=(DWORD)-1;
   SendMessage(hWndEdit, AEM_HLADDMARKRANGE, (WPARAM)hTheme, (LPARAM)&mri);

   mti.pMarkText="or";
   mti.nMarkTextLen=lstrlenA(mti.pMarkText);
   mti.dwFlags=AEHLF_MATCHCASE;
   mti.crText=(DWORD)-1;
   mti.crBk=RGB(0xFF, 0x00, 0x00);
   SendMessage(hWndEdit, AEM_HLADDMARKTEXTA, (WPARAM)hTheme, (LPARAM)&mti);

   SendMessage(hWndEdit, AEM_HLSETTHEME, (WPARAM)hTheme, TRUE);
 }


AEM_HLCREATETHEMEW
__________________

Create empty highlight theme.

wParam            == not used.
(wchar_t *)lParam == unicode theme name.

Return Value
 Theme handle.

Example:
 HANDLE hTheme;
 AEDELIMITEMW di;
 AEWORDITEMW wi;
 AEQUOTEITEMW qi;
 AEMARKRANGEITEM mri;
 AEMARKTEXTITEMW mti;

 if (hTheme=(HANDLE)SendMessage(hWndEdit, AEM_HLCREATETHEMEW, 0, (LPARAM)L"MyTheme"))
 {
   di.pDelimiter=L" ";
   di.nDelimiterLen=lstrlenW(di.pDelimiter);
   di.dwFlags=AEHLF_MATCHCASE;
   di.crText=(DWORD)-1;
   di.crBk=(DWORD)-1;
   SendMessage(hWndEdit, AEM_HLADDDELIMITERW, (WPARAM)hTheme, (LPARAM)&di);

   wi.pWord=L"for";
   wi.nWordLen=lstrlenW(wi.pWord);
   wi.dwFlags=AEHLF_MATCHCASE;
   wi.crText=RGB(0x00, 0xFF, 0x00);
   wi.crBk=(DWORD)-1;
   SendMessage(hWndEdit, AEM_HLADDWORDW, (WPARAM)hTheme, (LPARAM)&wi);

   qi.pQuoteStart=L"\"";
   qi.nQuoteStartLen=lstrlenW(qi.pQuoteStart);
   qi.pQuoteEnd=L"\"";
   qi.nQuoteEndLen=lstrlenW(qi.pQuoteEnd);
   qi.wchEscape=L'\\';
   qi.dwFlags=AEHLF_MATCHCASE;
   qi.crText=RGB(0x00, 0x00, 0xFF);
   qi.crBk=(DWORD)-1;
   SendMessage(hWndEdit, AEM_HLADDQUOTEW, (WPARAM)hTheme, (LPARAM)&qi);

   mri.crMarkRange.cpMin=10;
   mri.crMarkRange.cpMax=20;
   mri.dwFlags=0;
   mri.crText=RGB(0xFF, 0x00, 0x00);
   mri.crBk=(DWORD)-1;
   SendMessage(hWndEdit, AEM_HLADDMARKRANGE, (WPARAM)hTheme, (LPARAM)&mri);

   mti.pMarkText=L"or";
   mti.nMarkTextLen=lstrlenW(mti.pMarkText);
   mti.dwFlags=AEHLF_MATCHCASE;
   mti.crText=(DWORD)-1;
   mti.crBk=RGB(0xFF, 0x00, 0x00);
   SendMessage(hWndEdit, AEM_HLADDMARKTEXTW, (WPARAM)hTheme, (LPARAM)&mti);

   SendMessage(hWndEdit, AEM_HLSETTHEME, (WPARAM)hTheme, TRUE);
 }


AEM_HLGETTHEMEA
_______________

Retrieve highlight theme handle.

wParam         == not used.
(char *)lParam == ansi theme name to retrieve. If NULL, active theme handle will be returned.

Return Value
 Theme handle.

Example:
 HANDLE hTheme=(HANDLE)SendMessage(hWndEdit, AEM_HLGETTHEMEA, 0, (LPARAM)"MyTheme");


AEM_HLGETTHEMEW
_______________

Retrieve highlight theme handle.

wParam            == not used.
(wchar_t *)lParam == unicode theme name to retrieve. If NULL, active theme handle will be returned.

Return Value
 Theme handle.

Example:
 HANDLE hTheme=(HANDLE)SendMessage(hWndEdit, AEM_HLGETTHEMEW, 0, (LPARAM)L"MyTheme");


AEM_HLGETTHEMENAMEA
___________________

Retrieve ansi highlight theme name.

(HANDLE)wParam == theme handle.
(char *)lParam == pointer to a buffer that receives ansi highlight theme name. If NULL, return value is the required buffer size.

Return Value
 Length of the string copied to the buffer, in TCHARs, not including the terminating null character.

Example:
 char szThemeName[MAX_PATH];

 SendMessage(hWndEdit, AEM_HLGETTHEMENAMEA, (WPARAM)hTheme, (LPARAM)szThemeName);


AEM_HLGETTHEMENAMEW
___________________

Retrieve unicode highlight theme name.

(HANDLE)wParam    == theme handle.
(wchar_t *)lParam == pointer to a buffer that receives unicode highlight theme name. If NULL, return value is the required buffer size.

Return Value
 Length of the string copied to the buffer, in TCHARs, not including the terminating null character.

Example:
 wchar_t wszThemeName[MAX_PATH];

 SendMessage(hWndEdit, AEM_HLGETTHEMENAMEW, (WPARAM)hTheme, (LPARAM)wszThemeName);


AEM_HLTHEMEEXISTS
_________________

Retrieve highlight theme existence.

(HANDLE)wParam == theme handle.
lParam         == not used.

Return Value
 TRUE   theme exists.
 FALSE  theme doesn't exist.

Example:
 SendMessage(hWndEdit, AEM_HLTHEMEEXISTS, (WPARAM)hTheme, 0);


AEM_HLSETTHEME
______________

Activate highlight theme.

(HANDLE)wParam == theme handle. If NULL, active theme will be deactivated.
(BOOL)lParam   == TRUE   redraw the edit window.
                  FALSE  don't redraw the edit window.

Return Value
 zero

Example:
 See AEM_HLCREATETHEMEA or AEM_HLCREATETHEMEW example.


AEM_HLDELETETHEME
_________________

Delete highlight theme.

(HANDLE)wParam == theme handle. If NULL, delete all themes.
lParam         == not used.

Return Value
 zero

Example:
 HANDLE hTheme;

 hTheme=(HANDLE)SendMessage(hWndEdit, AEM_HLCREATETHEMEW, 0, (LPARAM)L"MyTheme");
 SendMessage(hWndEdit, AEM_HLDELETETHEME, (WPARAM)hTheme, 0);


AEM_HLADDDELIMITERA
___________________

Add ansi delimiter to highlight theme.

(HANDLE)wParam         == theme handle.
(AEDELIMITEMA *)lParam == pointer to a AEDELIMITEMA structure.

Return Value
 Delimiter handle.

Example:
 See AEM_HLCREATETHEMEA example.


AEM_HLADDDELIMITERW
___________________

Add unicode delimiter to highlight theme.

(HANDLE)wParam         == theme handle.
(AEDELIMITEMW *)lParam == pointer to a AEDELIMITEMW structure.

Return Value
 Delimiter handle.

Example:
 See AEM_HLCREATETHEMEW example.


AEM_HLDELETEDELIMITER
_____________________

Delete delimiter from highlight theme.

(HANDLE)wParam == theme handle.
(HANDLE)lParam == delimiter handle. If NULL, delete all delimiters.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_HLDELETEDELIMITER, (WPARAM)hTheme, (LPARAM)hDelimiter);


AEM_HLADDWORDA
______________

Add ansi word to highlight theme.

(HANDLE)wParam        == theme handle.
(AEWORDITEMA *)lParam == pointer to a AEWORDITEMA structure.

Return Value
 Word handle.

Example:
 See AEM_HLCREATETHEMEA example.


AEM_HLADDWORDW
______________

Add unicode word to highlight theme.

(HANDLE)wParam        == theme handle.
(AEWORDITEMW *)lParam == pointer to a AEWORDITEMW structure.

Return Value
 Word handle.

Example:
 See AEM_HLCREATETHEMEW example.


AEM_HLDELETEWORD
________________

Delete word from highlight theme.

(HANDLE)wParam == theme handle.
(HANDLE)lParam == word handle. If NULL, delete all words.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_HLDELETEWORD, (WPARAM)hTheme, (LPARAM)hWord);


AEM_HLADDQUOTEA
_______________

Add ansi quote to highlight theme.

(HANDLE)wParam         == theme handle.
(AEQUOTEITEMA *)lParam == pointer to a AEQUOTEITEMA structure.

Return Value
 Quote handle.

Example:
 See AEM_HLCREATETHEMEA example.


AEM_HLADDQUOTEW
_______________

Add unicode quote to highlight theme.

(HANDLE)wParam         == theme handle.
(AEQUOTEITEMW *)lParam == pointer to a AEQUOTEITEMW structure.

Return Value
 Quote handle.

Example:
 See AEM_HLCREATETHEMEW example.


AEM_HLDELETEQUOTE
_________________

Delete quote from highlight theme.

(HANDLE)wParam == theme handle.
(HANDLE)lParam == quote handle. If NULL, delete all quotes.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_HLDELETEQUOTE, (WPARAM)hTheme, (LPARAM)hQuote);


AEM_HLADDMARKTEXTA
__________________

Add ansi text mark to highlight theme.

(HANDLE)wParam            == theme handle.
(AEMARKTEXTITEMA *)lParam == pointer to a AEMARKTEXTITEMA structure.

Return Value
 Text mark handle.

Example:
 See AEM_HLCREATETHEMEA example.


AEM_HLADDMARKTEXTW
__________________

Add unicode text mark to highlight theme.

(HANDLE)wParam            == theme handle.
(AEMARKTEXTITEMW *)lParam == pointer to a AEMARKTEXTITEMW structure.

Return Value
 Text mark handle.

Example:
 See AEM_HLCREATETHEMEW example.


AEM_HLDELETEMARKTEXT
____________________

Delete text mark from highlight theme.

(HANDLE)wParam == theme handle.
(HANDLE)lParam == text mark handle. If NULL, delete all marks.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_HLDELETEMARKTEXT, (WPARAM)hTheme, (LPARAM)hMark);


AEM_HLADDMARKRANGE
__________________

Add unicode range mark to highlight theme.

(HANDLE)wParam            == theme handle.
(AEMARKRANGEITEM *)lParam == pointer to a AEMARKRANGEITEM structure.

Return Value
 Range mark handle.

Example:
 See AEM_HLCREATETHEMEW example.


AEM_HLDELETEMARKRANGE
_____________________

Delete range mark from highlight theme.

(HANDLE)wParam == theme handle.
(HANDLE)lParam == range mark handle. If NULL, delete all marks.

Return Value
 zero

Example:
 SendMessage(hWndEdit, AEM_HLDELETEMARKRANGE, (WPARAM)hTheme, (LPARAM)hMark);

*/


//// UNICODE define

#ifndef UNICODE
  #define AES_AKELEDITCLASS AES_AKELEDITCLASSA
  #define AES_RICHEDITCLASS AES_RICHEDITCLASSA

  #define AEAPPENDTEXT AEAPPENDTEXTA
  #define AEREPLACESEL AEREPLACESELA
  #define AETEXTRANGE AETEXTRANGEA
  #define AEFINDTEXT AEFINDTEXTA
  #define AEDELIMITEM AEDELIMITEMA
  #define AEWORDITEM AEWORDITEMA
  #define AEQUOTEITEM AEQUOTEITEMA
  #define AEMARKTEXTITEM AEMARKTEXTITEMA

  #define AEM_SETTEXT AEM_SETTEXTA
  #define AEM_APPENDTEXT AEM_APPENDTEXTA
  #define AEM_REPLACESEL AEM_REPLACESELA
  #define AEM_GETTEXTRANGE AEM_GETTEXTRANGEA
  #define AEM_FINDTEXT AEM_FINDTEXTA
  #define AEM_ISMATCH AEM_ISMATCHA
  #define AEM_HLCREATETHEME AEM_HLCREATETHEMEA
  #define AEM_HLGETTHEME AEM_HLGETTHEMEA
  #define AEM_HLGETTHEMENAME AEM_HLGETTHEMENAMEA
  #define AEM_HLADDDELIMITER AEM_HLADDDELIMITERA
  #define AEM_HLADDWORD AEM_HLADDWORDA
  #define AEM_HLADDQUOTE AEM_HLADDQUOTEA
  #define AEM_HLADDMARKTEXT AEM_HLADDMARKTEXTA
#else
  #define AES_AKELEDITCLASS AES_AKELEDITCLASSW
  #define AES_RICHEDITCLASS AES_RICHEDITCLASSW

  #define AEAPPENDTEXT AEAPPENDTEXTW
  #define AEREPLACESEL AEREPLACESELW
  #define AETEXTRANGE AETEXTRANGEW
  #define AEFINDTEXT AEFINDTEXTW
  #define AEDELIMITEM AEDELIMITEMW
  #define AEWORDITEM AEWORDITEMW
  #define AEQUOTEITEM AEQUOTEITEMW
  #define AEMARKTEXTITEM AEMARKTEXTITEMW

  #define AEM_SETTEXT AEM_SETTEXTW
  #define AEM_APPENDTEXT AEM_APPENDTEXTW
  #define AEM_REPLACESEL AEM_REPLACESELW
  #define AEM_GETTEXTRANGE AEM_GETTEXTRANGEW
  #define AEM_FINDTEXT AEM_FINDTEXTW
  #define AEM_ISMATCH AEM_ISMATCHW
  #define AEM_HLCREATETHEME AEM_HLCREATETHEMEW
  #define AEM_HLGETTHEME AEM_HLGETTHEMEW
  #define AEM_HLGETTHEMENAME AEM_HLGETTHEMENAMEW
  #define AEM_HLADDDELIMITER AEM_HLADDDELIMITERW
  #define AEM_HLADDWORD AEM_HLADDWORDW
  #define AEM_HLADDQUOTE AEM_HLADDQUOTEW
  #define AEM_HLADDMARKTEXT AEM_HLADDMARKTEXTW
#endif

#endif
