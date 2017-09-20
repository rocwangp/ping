CC := g++

DEBUG := 
CXXFLAGS := -g -Wall -D_REENTRANT $(DEBUG)

LIBS := -lpthread 

INCLUDE := -I./

TARGET := ping

OBJECTS := ping.o test.o
	
.cpp.o:
	$(CC) $(CXXFLAGS) $(INCLUDE) -c $<

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(LIBS)


.PHONY : clean

clean:
	-rm -f $(TARGET) $(OBJECTS)


