
C_SOURCES = $(filter-out src/main.c, $(wildcard src/*.c))
OBJ_FILES = $(patsubst src/%,obj/%,$(patsubst %.c,%.o,${C_SOURCES}))


.PHONY: all
all: bin/main


bin/main: src/main.c ${OBJ_FILES} | bin
	$(CC) ${CFLAGS} -Iinclude $^ -lm -o $@

obj/%.o: src/%.c | obj
	$(CC) ${CFLAGS} -Iinclude $< -c -o $@


bin:
	mkdir -p bin

obj:
	mkdir -p obj



.PHONY: clean
clean:
	$(RM) -r bin
	$(RM) -r obj
