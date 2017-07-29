BINCHECK = if [ ! -d bin ]; then mkdir bin; fi;
TEST_BINCHECK = if [ ! -d bin/test ]; then mkdir -p bin/test; fi;
BIN = 'bin/include-file'
COMPILER = 'clang'
FLAGS = '-Weverything'

CHARCOUNT_TESTER = 'bin/test/get-char-count'

# main binary
$(BIN): src/* 
	$(BINCHECK) $(COMPILER) $(FLAGS) src/main.c -o $(BIN);

check:
	$(BIN) test/several_directives/main.txt

#============
# build tests
#============

$(CHARCOUNT_TESTER): src/file-attributes.h src/get-char-count.h src/test/get-char-count.c
	$(TEST_BINCHECK) $(COMPILER) $(FLAGS) src/test/get-char-count.c -o $(CHARCOUNT_TESTER)

tests: $(CHARCOUNT_TESTER)

#==========
# run tests
#==========

check-get-char-count:
	$(CHARCOUNT_TESTER) test/lorem-ipsum.txt

check-tests: check-get-char-count

#===================
# project-wide tasks
#===================

all: $(BIN) tests

clean:
	rm -rf bin; 
