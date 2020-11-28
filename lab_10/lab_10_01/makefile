CC = gcc
INCPATH := ../inc/
INC := -I $(INCPATH)
OUT = ./out/
SRC = ./src/
UNIT = ./unit_tests/
CFLAGS = -pedantic -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -std=gnu99


OBJS = $(OUT)list.o $(OUT)task_01.o $(OUT)task_02.o $(OUT)task_03.o $(OUT)list_arr.o 
OBJS_UNIT = $(OUT)check_main.o  $(OUT)check_pop.o $(OUT)check_comparator.o \
$(OUT)check_task_02.o $(OUT)check_task_03.o \
$(OUT)check_find.o $(OUT)check_insert.o \
$(OUT)check_listcreatenode.o $(OUT)check_listread.o $(OUT)check_listaddbegin.o \
$(OUT)check_front_back_split.o $(OUT)check_remove_dup.o \
$(OUT)check_copy.o

debug : CFLAGS += -g3
debug : app.exe

release : CFLAGS += -DNDEBUG -g0
release : app.exe

app.exe: $(OBJS) $(OUT)app.o
	$(CC) $^ -o $@
unit_tests.exe: $(OBJS) $(OBJS_UNIT)
	$(CC) $^ -o $@ -lcheck  -lsubunit -lm -lpthread -lrt

$(OUT)check_%.o : $(UNIT)check_%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<

$(OUT)%.o : $(SRC)%.c
	cd out && $(CC) $(CFLAGS) $(INC) -c ../$<

func: 
	touch out.txt
	bash ./run_pos.sh
	bash ./run_neg.sh
	rm out.txt

run_unit_vg: unit_tests.exe
	valgrind --leak-check=full --leak-resolution=med --leak-check=full  ./unit_tests.exe

run_app_vg: app.exe
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe
	
run_func_vg: app.exe
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_in_01.txt out.txt p
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_in_02.txt out.txt p
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_in_03.txt out.txt s
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_in_04.txt out.txt s
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_in_05.txt out.txt r
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_in_06.txt out.txt r
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_in_07.txt out.txt i WWW QQQ "I’m Bored" "Michael Ian Black"
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_in_08.txt out.txt i WWW QQQ "I’m Bored" "Michael Ian Black"
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_in_09.txt out.txt i WWW QQQ qq ww
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_in_10.txt out.txt i WWW QQQ "The Million Pound Bank" "Mark Twain"
	
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_in_01.txt out.txt p; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_in_02.txt out.txt s; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_in_03.txt out.txt r; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_in_04.txt out.txt p; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_in_05.txt out.txt p; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_in_06.txt out.txt s; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_in_07.txt out.txt r; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_in_08.txt out.txt ; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_in_09.txt out.txt j k j k; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_in_10.txt out.txt i 8; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_in_11.txt out.txt i 6 g; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_in_12.txt out.txt i j 9; true
	