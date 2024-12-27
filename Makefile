CC:=clang
CFLAGS:= -std=c17 -g
INCLUDES:=-I./include
SRC_DIR:=src
TEST_DIR:=test

TEST_SRC:=$(wildcard $(TEST_DIR)/*.c)
SRC:=$(wildcard $(SRC_DIR)/*.m)

# run test files
test: 
	NSDebugEnabled=NO $(CC) $(CFLAGS) $(INCLUDES) $(SRC) test/main.c -o test
	./test

clean:
	rm -f test