@ECHO OFF
Set MSSDK=D:\Program Files\Microsoft Platform SDK
Set VCDIR=D:\Program Files\Microsoft Visual C++ Toolkit 2003
Set LANGNAME=English
Set LANGID=0x409

::###################################::
Set PATH=%VCDIR%\bin;%MSSDK%\bin;%PATH%
Set INCLUDE=%VCDIR%\include;%MSSDK%\include;%INCLUDE%
Set LIB=%VCDIR%\lib;%MSSDK%\lib;%LIB%

rc /R /DEXE_VERSION /DRC_VERSIONLANGID=%LANGID% /Fo"AkelPad.res" "AkelFiles\Langs\Resources\%LANGNAME%.rc"
cl /O1 /DRC_VERSIONLANGID=%LANGID% AkelPad.c Edit.c AkelPad.res /link kernel32.lib user32.lib gdi32.lib advapi32.lib shell32.lib comctl32.lib comdlg32.lib version.lib /SUBSYSTEM:WINDOWS /OPT:NOWIN98 /MACHINE:I386 /NODEFAULTLIB /ENTRY:_WinMain /OUT:AkelPad.exe

if exist AkelPad.obj del AkelPad.obj
if exist Edit.obj del Edit.obj
if exist AkelEdit.obj del AkelEdit.obj
if exist AkelPad.res del AkelPad.res
@PAUSE
