CC = gcc
INCPATH := ../inc/
INC := -I $(INCPATH)
OUT = ./out/
SRC = ./src/
UNIT = ./unit_tests/
CFLAGS = -pedantic -Wall -Wextra -Wvla -Werror -Wfloat-equal -Wfloat-conversion -std=c99

OBJS = $(OUT)my_snprintf.o $(OUT)func.o
OBJS_UNIT = $(OUT)check_main.o $(OUT)check_my_snprintf.o $(OUT)check_my_strlen.o \
$(OUT)check_lennumber.o $(OUT)check_leninsystem.o $(OUT)check_inttostring.o \
$(OUT)check_toanysystem.o

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

#app.exe: $(OBJS) $(OUT)app.o
#	$(CC) $^ -o $@

unit_tests.exe: $(OBJS) $(OBJS_UNIT)
	$(CC) $^ -o $@ -lcheck #-lsubunit -lm -lpthread -lrt

$(OUT)check_%.o : $(UNIT)check_%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<

$(OUT)%.o : $(SRC)%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<

run_unit_vg: unit_tests.exe
	valgrind --leak-check=full --leak-resolution=med --leak-check=full ./unit_tests.exe

#run_app_vg: app.exe
#	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe

