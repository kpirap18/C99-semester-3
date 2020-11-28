CC := gcc
CFILE := $(wildcard *.c)
OBJ := $(CFILE:%.c=%.o)
FLAGS := -Wall -Werror -pedantic -Wextra -Wvla -Wfloat-equal -Wfloat-conversion -std=c99

app.exe: $(OBJ) *.h
	$(CC) $(FLAGS) $(OBJ) -o app.exe

%.o: %.c *.h
	$(CC) $(FLAGS) -c $<

.PHONY: clean
clean:
	$(RM) *.o *.exe