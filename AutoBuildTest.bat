@echo off
C:\Windows\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe ConsoleApplication1\ConsoleApplication1.csproj
ConsoleApplication1\bin\Debug\ConsoleApplication1.exe
C:\Windows\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe UnitTestProject1\UnitTestProject1.csproj
UnitTestProject1\bin\Debug\UnitTestProject1.exe
"C:\Program Files (x86)\Microsoft Visual Studio 14.0\Common7\IDE\mstest" /testcontainer:UnitTestProject1\bin\debug\UnitTestProject1.dll /resultsfile:UnitTestProject1\results.trx

echo Error code is %errorlevel%
rem dont display this
pause