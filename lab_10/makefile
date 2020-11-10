CC = gcc
INCPATH := ../inc/
INC := -I $(INCPATH)
OUT = ./out/
SRC = ./src/
UNIT = ./unit_tests/
CFLAGS = -pedantic -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -std=gnu99


OBJS = $(OUT)list.o $(OUT)task_01.o $(OUT)task_02.o $(OUT)task_03.o $(OUT)my_check.o
#OBJS_UNIT = $(OUT)check_main.o $(OUT)check_f_count.o $(OUT)check_film_copy.o  \
$(OUT)check_film_found.o $(OUT)check_film_init.o $(OUT)check_film_read.o \
$(OUT)check_my_check_feild.o $(OUT)check_my_check_key.o

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

app.exe: $(OBJS) $(OUT)app.o
	$(CC) $^ -o $@
unit_tests.exe: $(OBJS) $(OBJS_UNIT)
	$(CC) $^ -o $@ -lcheck 

$(OUT)check_%.o : $(UNIT)check_%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<

$(OUT)%.o : $(SRC)%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<


run_unit_vg: unit_tests.exe
	valgrind --leak-check=full --leak-resolution=med --leak-check=full  ./unit_tests.exe

run_app_vg: app.exe
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe
	
run_func_vg: app.exe
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_01_in.txt out.txt p
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_02_in.txt out.txt p
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_03_in.txt out.txt s
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_04_in.txt out.txt s
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_05_in.txt out.txt r
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_06_in.txt out.txt r
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_07_in.txt out.txt i 3 4
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_08_in.txt out.txt i 2 1
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_09_in.txt out.txt i 2 45
	
