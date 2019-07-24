@echo off

cd spotbugs-3.1.12\bin
spotbugs.bat -textui -maxHeap 1500 -nested:false -output ..\..\ReportFile.emacs -effort:max -low -sortByClass -emacs sourcepath ..\..\HelloWorld

cd ..\..\pmd-bin-6.16.0\bin
 .\pmd.bat -d ..\..\HelloWorld\src\HelloWorld.java -f text -R rulesets/java/quickstart.xml -r ..\..\output.txt

cd ..\..\StaticCodeAnalyzer
g++ StaticCodeAnalyzer.cpp -o StaticCodeAnalyzer.exe
StaticCodeAnalyzer.exe

echo Error code is %errorlevel%

rem dont display this
pause