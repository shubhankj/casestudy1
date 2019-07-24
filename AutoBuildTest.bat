@echo off
C:\Windows\Microsoft.NET\Framework\v4.0.30319\MSBuild.exe ConsoleApplication1\ConsoleApplication1.csproj
rem ConsoleApplication1\bin\Debug\ConsoleApplication1.exe
cd spotbugs-3.1.12\bin
START "spotbugs" spotbugs.bat -textui -maxHeap 1500 -nested:false -output ..\..\ReportFile.emacs -effort:max -low -sortByClass -emacs sourcepath ..\..\HelloWorld
cd ..\..\pmd-bin-6.16.0\bin
START .\pmd.bat -d ..\..\HelloWorld\src\HelloWorld.java -f text -R rulesets/java/quickstart.xml -r ..\..\output.txt

echo Error code is %errorlevel%

rem dont display this
pause