CC = gcc
LIB = ../lib/
FLAGDLL = -D EXPORTS
CFLAGS = -pedantic -Wall -Werror -Wvla -Wfloat-equal -Wfloat-conversion -std=c99

OBJS = $(LIB)array.o

lib : libarray.dll

app : libarray.dll
	gcc -std=c99 -Wall -I C:/Users/Ira/AppData/Local/Programs/Python/Python38/include  -c wrap.c
	gcc -shared -o libarray_dll.pyd wrap.o libarray.dll -L C:/Users/Ira/AppData/Local/Programs/Python/Python38/libs -lpython3 -lpython38
	rm *.o

unit_tests.exe: libarray.dll $(OBJS_UNIT) 
	$(CC) $^ -L. -lapp -o $@ -lcheck #-lsubunit -lm -lpthread -lrt

%.dll : $(OBJS)
	$(CC) -shared $^ -Wl,--subsystem,windows -o $@
	
$(LIB)%.o : $(LIB)%.c
	cd ../lib && $(CC) $(CFLAGS) $(FLAGDLL) -I $(LIB) -c $<
	
.PHONY : clean
clean :
	$(RM) *.exe *.dll *.pyd $(LIB)*.o
