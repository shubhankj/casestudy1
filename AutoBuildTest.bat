rem @echo off

cd pmd-bin-6.16.0\bin
call pmd.bat -d ..\..\HelloWorld\src\HelloWorld.java -f text -R rulesets\java\quickstart.xml -r ..\..\output.txt

cd ..\..\spotbugs-3.1.12\bin
call spotbugs.bat -textui -maxHeap 1500 -nested:false -output ..\..\ReportFile.emacs -effort:max -low -sortByClass -emacs sourcepath ..\..\HelloWorld

cd ..\..\StaticCodeAnalyzer
g++ StaticCodeAnalyzer.cpp -o StaticCodeAnalyzer.exe
StaticCodeAnalyzer.exe

echo Error code is %errorlevel%


rem dont display this
pause
