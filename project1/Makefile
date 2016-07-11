EXENAME = code
OBJS = main.o course.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp course.h
	$(CXX) $(CXXFLAGS) main.cpp

course.o : course.cpp course.h
	$(CXX) $(CXXFLAGS) course.cpp

clean :
	-rm -f *.o $(EXENAME)
