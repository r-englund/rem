CC=/usr/local/gcc-modules/bin/g++-modules
AR=/usr/local/gcc-modules/bin/gcc-ar-modules
CFLAGS= -fmodules-ts -std=c++2a
MKDIR_P = @mkdir -p


.PHONY: all rem clean
all: bin/simple1

DIRS = lib bin obj obj/rem
$(DIRS):
	$(MKDIR_P) $@
	
#obj/rem/mat.o: ../src/mat.cpp
#	$(CC) $(CFLAGS) -c ../src/mat.cpp -o obj/rem/mat.o

#SRCS = $(wildcard ../src/*.cpp)
SRCS = ../src/vec/vec.ixx ../src/vec/comparisonoperators.ixx ../src/vec/bitwiseoperators.ixx ../src/vec/arithmeticoperators.ixx ../src/mat.ixx ../src/rem.ixx
PROGS = $(patsubst ../src/%.cpp,obj/rem/%.o,$(SRCS))


obj/rem/%.o: ../src/%.ixx | $(DIRS)
	@echo Compiling $<
	$(CC) $(CFLAGS) -x c++ -c $< -o $@

lib/librem.a: $(PROGS)
	@echo Creating static library
	$(AR) rcs lib/librem.a $(PROGS)

obj/simple1.o: ../examples/simple1.cpp
	@echo Compiling $<
	$(CC) $(CFLAGS) -c ../examples/simple1.cpp -o obj/simple1.o

bin/simple1: lib/librem.a obj/simple1.o 
	@echo Creating exe $@
	$(CC) $(CFLAGS) lib/librem.a -o bin/simple1 obj/simple1.o


clean:
	rm -f lib/*
	rm -fr obj/*
	rm -f bin/*
	rm -f gcm.cache/*