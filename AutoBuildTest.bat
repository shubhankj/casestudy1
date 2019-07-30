rem @echo off


cd StaticCodeAnalyser\StaticCodeAnalyser
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\MSBuild\15.0\Bin\msbuild.exe" StaticCodeAnalyser.vcxproj /p:configuration=debug	rem jugaad
Debug\StaticCodeAnalyser.exe

cd ..\StaticCodeAnalyserTest
"C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\MSBuild\15.0\Bin\msbuild.exe" StaticCodeAnalyserTest.vcxproj /p:configuration=debug	rem jugaad
Debug\StaticCodeAnalyserTest.exe

echo Error code is %errorlevel%

rem linking test project to main project jugaad
pause