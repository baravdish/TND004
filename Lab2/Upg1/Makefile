# Select compiler.
CXX = g++
 
# Set flags
CXXFLAGS := -std=c++11 -std=gnu++11
 
# Set output name.
BINNAME = main.exe
 
# Specify files to compile.
SRCDIR = $(wildcard *.cpp)
 
compile: $(SRCDIR)
	$(CXX) $(CXXFLAGS) $(SRCDIR) -o $(BINNAME)