CC=/usr/local/gcc-modules/bin/g++-modules
AR=/usr/local/gcc-modules/bin/gcc-ar-modules
CFLAGS= -fmodules-ts -std=c++2a
MKDIR_P = @mkdir -p


.PHONY: all rem clean tests
all: tests

DIRS = lib bin obj obj/rem obj/rem/vec obj/rem/internal
$(DIRS):
	$(MKDIR_P) $@
	


SRCS = ../src/internal/common.ixx ../src/internal/util.ixx ../src/vec/vec.ixx ../src/vec/comparisonoperators.ixx ../src/vec/bitwiseoperators.ixx ../src/vec/arithmeticoperators.ixx ../src/mat/mat.ixx ../src/mat/arithmeticoperators.ixx ../src/mat/bitwiseoperators.ixx ../src/mat/comparisonoperators.ixx ../src/mat/inverse.ixx ../src/mat/transpose.ixx ../src/rem.ixx



PROGS = $(patsubst ../src/%.ixx,obj/rem/%.o,$(SRCS))

obj/rem/%.o: ../src/%.ixx | $(DIRS)
	@echo Compiling $<
	$(CC) $(CFLAGS) -x c++ -c $< -o $@
	

lib/librem.a: $(PROGS)
	@echo Creating static library
	$(AR) rcs lib/librem.a $(PROGS)


bin/%: lib/librem.a ../tests/%.cpp
	@echo Creating exe $@ 
	$(CC) $(CFLAGS) -o $@ $^

tests: bin/constructors

clean:
	rm -f lib/*
	rm -fr obj/*
	rm -f bin/*
	rm -f gcm.cache/*