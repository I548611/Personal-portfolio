CXX = g++
CXXFLAGS = -Wall -std=c++17

main: drone.cpp mockController.cpp Gps.cpp Receiver.cpp DroneControllerProxy.cpp Motor.cpp
	$(CXX) $(CXXFLAGS) -o main drone.cpp mockController.cpp Gps.cpp Receiver.cpp DroneControllerProxy.cpp Motor.cpp

run: main
	./main

clean:
	rm -f main
