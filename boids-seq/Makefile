CC=g++
SOURCE=main.cpp Flock.cpp Boid.cpp Structures.cpp
LIBS=/usr/include/boost/
SO=/usr/lib/libboost_serialization.so.1.46.1

boids: $(SOURCE)
	$(CC) -I $(LIBS) $(SOURCE) $(SO) -o boids
