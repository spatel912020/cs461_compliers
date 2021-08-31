CXX=		g++
CXXFLAGS=	-g -std=gnu++11
LDFLAGS=	
SHELL=		bash
PROGRAMS=	pa1
SOURCES=	pa1.cpp
OBJECTS=	$(SOURCES:.cpp=.o)

all:		$(PROGRAMS)

%.o:		%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^

pa1:	$(OBJECTS) 
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

clean:
	rm -f $(PROGRAMS) $(OBJECTS)

