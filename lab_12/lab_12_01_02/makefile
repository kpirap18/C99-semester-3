CC = gcc
LIB = ./lib/
UNITINC = ./unit_tests/inc/
UNITSRC = ./unit_tests/src/
UNITOUT = ./unit_tests/out/
FLAGDLL = -D EXPORTS
CFLAGS = -pedantic -Wall -Werror -Wvla -Wfloat-equal -Wfloat-conversion -std=c99

OBJS = $(LIB)array.o

OBJS_UNIT = $(UNITOUT)check_is_square.o $(UNITOUT)check_shift_arr.o \
$(UNITOUT)check_square_arr.o $(UNITOUT)check_main.o 

lib : libarray.dll

unit_tests.exe: libarray.dll $(OBJS_UNIT) 
	$(CC) $^ -L. -larray -o $@ -lcheck #-lsubunit -lm -lpthread -lrt

%.dll : $(OBJS)
	$(CC) -shared $^ -Wl,--subsystem,windows -o $@
	
$(LIB)%.o : $(LIB)%.c
	cd lib && $(CC) $(CFLAGS) $(FLAGDLL) -I .$(LIB) -c ../$<
	
$(UNITOUT)check_%.o : $(UNITSRC)check_%.c
	cd $(UNITOUT) && $(CC) $(CFLAGS) -I ../.$(UNITINC) -I ../.$(LIB) -c ../../$<
	
.PHONY : clean
clean :
	$(RM) *.exe *.dll $(LIB)*.o $(UNITOUT)*.o
