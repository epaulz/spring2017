SRC = driver.cpp image.cpp header.cpp color.cpp pixel.cpp point.cpp shape.cpp triangle.cpp quadrilateral.cpp circle.cpp
OBJ = driver.o image.o header.o color.o pixel.o point.o shape.o triangle.o quadrilateral.o circle.o
PROG = driver

$(PROG) : $(OBJ)
	g++ $(OBJ) -o $(PROG) -Wall -lm -g

$(OBJ) : $(SRC)

run:
	./driver input.txt output.ppm

clean:
	rm *.o driver
