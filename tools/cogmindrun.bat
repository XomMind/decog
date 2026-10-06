@echo off
set VSDIR=%COGMIND_MSVC%\vc\Program Files\Microsoft Visual Studio 10.0
set SDKDIR=%COGMIND_MSVC%\sdk\Program Files\Microsoft SDKs\Windows\v7.1
set PATH=%VSDIR%\VC\bin;%VSDIR%\Common7\IDE;%COGMIND_MSVC%\vc\Win\System;%PATH%
set INCLUDE=%VSDIR%\VC\include;%SDKDIR%\Include;C:\_\_RL\COGMIND\_cogmind\include\compat
set LIB=%VSDIR%\VC\lib;%SDKDIR%\Lib
set TMP=Z:\tmp
set TEMP=Z:\tmp
cd /d %COGMIND_CWD%
%*
if %errorlevel% neq 0 exit /b %errorlevel%
