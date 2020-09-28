CC = gcc
INC = ./inc/
OUT = ./out/
SRC = ./src/
UNIT = ./unit_tests/
CFLAGS = -pedantic -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -std=c99

OBJS = $(OUT)mysort.o $(OUT)key.o $(OUT)parsing.o
OBJS_UNIT = $(OUT)check_avarage.o $(OUT)check_compare.o $(OUT)check_file_size.o \
$(OUT)check_key.o $(OUT)check_key_count.o $(OUT)check_mysort.o $(OUT)check_parsing_array.o \
$(OUT)check_parsing_key_array.o

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

app.exe: $(OUT)app.o $(OBJS)
	$(CC) $^ -o $@
unit_tests.exe: $(OUT)check_main.o $(OBJS) $(OBJS_UNIT) 
	$(CC) $^ -o $@ -lcheck
	
analis.exe: analis.o 
	$(CC) $^ -o $@
	
	
$(OUT)app.o: $(SRC)app.c $(INC)my_main.h $(INC)mysort.h $(INC)key.h $(INC)parsing.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)mysort.o: $(SRC)mysort.c $(INC)my_main.h $(INC)mysort.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)key.o: $(SRC)key.c $(INC)my_main.h $(INC)parsing.h $(INC)key.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)parsing.o: $(SRC)parsing.c $(INC)my_main.h $(INC)parsing.h
	cd out && $(CC) $(CFLAGS) -c ../$<

$(OUT)check_main.o: $(UNIT)check_main.c $(INC)mysort.h $(INC)key.h $(INC)parsing.h $(INC)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_avarage.o: $(UNIT)check_avarage.c $(INC)mysort.h $(INC)key.h $(INC)parsing.h $(INC)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_compare.o: $(UNIT)check_compare.c $(INC)mysort.h $(INC)key.h $(INC)parsing.h $(INC)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_file_size.o: $(UNIT)check_file_size.c $(INC)mysort.h $(INC)key.h $(INC)parsing.h $(INC)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_key.o: $(UNIT)check_key.c $(INC)mysort.h $(INC)key.h $(INC)parsing.h $(INC)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_key_count.o: $(UNIT)check_key_count.c $(INC)mysort.h $(INC)key.h $(INC)parsing.h $(INC)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_mysort.o: $(UNIT)check_mysort.c $(INC)mysort.h $(INC)key.h $(INC)parsing.h $(INC)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_parsing_array.o: $(UNIT)check_parsing_array.c $(INC)mysort.h $(INC)key.h $(INC)parsing.h $(INC)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
$(OUT)check_parsing_key_array.o: $(UNIT)check_parsing_key_array.c $(INC)mysort.h $(INC)key.h $(INC)parsing.h $(INC)check_main.h
	cd out && $(CC) $(CFLAGS) -c ../$<
	
analis.o: analis.c
	$(CC) $(CFLAGS) -c $<

%.d : %.c
	$(CC) -M $< > $@
	
SRGC := $(wildcard *.c)

include $(SRGC:.c=.d)

.PHONY : clean debug release
clean :
	$(RM) $(OUT)*.o *.exe