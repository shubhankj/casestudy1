rem @echo off

g++ StaticCodeAnalyzer\StaticCodeAnalyzer.cpp -o StaticCodeAnalyzer\StaticCodeAnalyzer.exe
StaticCodeAnalyzer\StaticCodeAnalyzer.exe

echo Error code is %errorlevel%

rem dont display this
pause

rem pmd-bin-6.16.0\bin\pmd.bat -d HelloWorld -f text -R pmd-bin-6.16.0\bin\rulesets\java\quickstart.xml -r output.txt
rem spotbugs-3.1.12\bin\spotbugs.bat -textui -maxHeap 1500 -nested:false -output ReportFile.emacs -effort:max -low -sortByClass -emacs sourcepath HelloWorld