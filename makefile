build:
	clear
	g++ -std=c++11 main.cpp String.cpp Date.cpp Car.cpp CarPtr.cpp CarFile.cpp CarCache.cpp Inventory.cpp -o vcs

run:
	clear
	./vcs