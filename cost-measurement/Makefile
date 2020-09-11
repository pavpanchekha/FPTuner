CC=gcc
CFLAGS=-Wall -Wextra -Wconversion -O3 -march=native -mtune=native -DNDEBUG

ALL_SOURCES = $(wildcard src/*.c)

TIME_SOURCES = $(filter src/%time.c, ${ALL_SOURCES})
TIME_FILES = $(patsubst src/%.c,bin/%,${TIME_SOURCES})
TIME_LOGFILES = $(patsubst src/%.c,log/%_log.txt,${TIME_SOURCES})

TEST_SOURCES = $(filter src/%test.c, ${ALL_SOURCES})
TEST_FILES = $(patsubst src/%.c,bin/%,${TEST_SOURCES})
TEST_LOGFILES = $(patsubst src/%.c,log/%_log.txt,${TEST_SOURCES})

OBJ_SOURCES = $(filter-out src/%time.c, $(filter-out src/%test.c, ${ALL_SOURCES}))
OBJ_FILES = $(patsubst src/%,obj/%,$(patsubst %.c,%.o,${OBJ_SOURCES}))

KERNS_SOURCES = $(wildcard kerns/*.c)

TIME_KERNS_SOURCES = $(filter kerns/%time.c, ${KERNS_SOURCES})
TIME_KERNS_FILES = $(patsubst kerns/%.c,bin/%,${TIME_KERNS_SOURCES})
TIME_KERNS_LOGFILES = $(patsubst kerns/%.c,log/%_log.txt,${TIME_KERNS_SOURCES})

OBJ_KERNS_SOURCES = $(filter-out kerns/%time.c, $(filter-out kerns/%test.c, ${KERNS_SOURCES}))
OBJ_KERNS_FILES = $(patsubst kerns/%,obj/%,$(patsubst %.c,%.o,${OBJ_KERNS_SOURCES}))


.PHONY: all
all: ${TIME_FILES} ${TEST_FILES} ${TIME_KERNS_FILES}


.PHONY: run
run: run_test run_time

.PHONY: run_test
run_test:${TEST_LOGFILES}

.PHONY: run_time
run_time:${TIME_LOGFILES}

log/%test_log.txt: bin/%test | log
	$^ > $@

log/%time_log.txt: bin/%time | log
	$^ > $@

bin/%time: src/%time.c ${OBJ_FILES} | bin
	$(CC) ${CFLAGS} -Iinclude $^ -lm -lrt -o $@

bin/%test: src/%test.c ${OBJ_FILES} | bin
	$(CC) ${CFLAGS} -Iinclude $^ -lm -lrt -lmpfr -o $@

obj/%.o: src/%.c | obj
	$(CC) ${CFLAGS} -Iinclude $< -c -o $@


bin/%time: kerns/%time.c ${OBJ_FILES} ${OBJ_KERNS_FILES} | bin
	$(CC) ${CFLAGS} -Iinclude $^ -lm -lrt -o $@

obj/%.o: kerns/%.c | obj
	$(CC) ${CFLAGS} -Iinclude $< -c -o $@


bin:
	mkdir -p bin

obj:
	mkdir -p obj

log:
	mkdir -p log


.PHONY: clean
clean:
	$(RM) -r bin
	$(RM) -r obj