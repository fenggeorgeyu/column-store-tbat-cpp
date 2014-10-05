CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =	

LIBS =

TARGET =	

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

test_hello: test1/test_hello.cpp
	$(CXX) -o test1/test_hello test1/test_hello.cpp

clean:
	rm -f $(OBJS) $(TARGET)
