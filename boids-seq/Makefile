CC=g++
SOURCE=main.cpp Flock.cpp Boid.cpp Structures.cpp
LIBS=/usr/include/boost/
SO=/usr/lib64/libboost_serialization.so.1.53.0

boids: $(SOURCE)
	$(CC) -I $(LIBS) $(SOURCE) $(SO) -o boids
