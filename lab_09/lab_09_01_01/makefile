CC = gcc
INCPATH := ../inc/
INC := -I $(INCPATH)
OUT = ./out/
SRC = ./src/
UNIT = ./unit_tests/
CFLAGS = -pedantic -Wall -Werror -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -std=gnu99


OBJS = $(OUT)film.o $(OUT)film_arr.o $(OUT)my_check.o
OBJS_UNIT = $(OUT)check_main.o $(OUT)check_f_count.o $(OUT)check_film_copy.o  \
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
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_01_in.txt year > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_02_in.txt title > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_03_in.txt name > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_04_in.txt year > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_05_in.txt year 2017> out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_06_in.txt title Avatar > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_07_in.txt name "James Cameron" > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_08_in.txt year 1984 > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_09_in.txt title "The Terminal" > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_10_in.txt name "Olivier Nakache" > out.txt;
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_11_in.txt year 2020 > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_12_in.txt title AdM > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_13_in.txt name Fedor > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_14_in.txt year > out.txt
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/pos_15_in.txt year > out.txt
	
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_01_in.txt year > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_02_in.txt year > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_03_in.txt year > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_04_in.txt year > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_05_in.txt year > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_06_in.txt year > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_07_in.txt year > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_08_in.txt year > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_09_in.txt year 0 > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_10_in.txt year ee > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_11_in.txt year -4 > out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_12_in.txt year asd ASD qww> out.txt; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe ; true
	valgrind --leak-check=full --leak-resolution=med --track-origins=yes -s --show-reachable=yes --tool=memcheck ./app.exe func_tests/neg_14_in.txt years > out.txt; true
.PHONY : clean debug release
clean :
	$(RM) $(OUT)*.o *.exe
