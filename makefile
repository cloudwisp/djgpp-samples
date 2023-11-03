all:
	mkdir -p bin/Release
	g++ -w hello.cpp -o bin/Release/hello.exe
	g++ -w echo.cpp -o bin/Release/ech.exe
	g++ -w keytest.cpp -o bin/Release/keytest.exe
	g++ -w keytest2.cpp -o bin/Release/keytest2.exe
	