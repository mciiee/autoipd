CC=clang
ifneq ($(ASAN),)
ASAN_FLAGS=-g -fsanitize=address
else
ASAN_FLAGS=
endif
CFLAGS=-std=c23 -Wall -Werror -Wpedantic $(ASAN_FLAGS)
LIBS=curl
LIBS_FLAGS=$(foreach LIB,$(LIBS),-l$(LIB))

SRC_DIR=src
BUILD_DIR=build
LIB_DIR=lib
DB_DIR=db

EXEC_FILE=autoipd
OUTFILE=$(BUILD_DIR)/$(EXEC_FILE)

.PHONY: clean

$(OUTFILE): $(BUILD_DIR)/main.o $(BUILD_DIR)/ip.o
	$(CC) $(CFLAGS) $(LIBS_FLAGS) $^ -o $@ 

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(BUILD_DIR)/ip.o: $(SRC_DIR)/ip.c $(SRC_DIR)/ip.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm $(BUILD_DIR)/*

