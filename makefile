BINCHECK = if [ ! -d bin ]; then mkdir bin; fi;
TEST_BINCHECK = if [ ! -d bin/test ]; then mkdir -p bin/test; fi;
BIN = 'bin/include-file'
COMPILER = 'clang'
FLAGS = '-Weverything'

TEST_TARGET = 'test/lorem-ipsum.txt'
CHARCOUNT_TESTER = 'bin/test/get-char-count'
COPYFILE_TESTER = 'bin/test/copy-file'

# main binary
$(BIN): src/* 
	$(BINCHECK) $(COMPILER) $(FLAGS) src/main.c -o $(BIN);

check:
	$(BIN) test/several_directives/main.txt

#============
# build tests
#============

$(CHARCOUNT_TESTER): src/file-attributes.h src/util/* src/get-char-count.h src/test/get-char-count.c
	$(TEST_BINCHECK) $(COMPILER) $(FLAGS) src/test/get-char-count.c -o $(CHARCOUNT_TESTER)

$(COPYFILE_TESTER): src/file-attributes.h src/util/* src/copy-file.h src/test/copy-file.c
	$(TEST_BINCHECK) $(COMPILER) $(FLAGS) src/test/copy-file.c -o $(COPYFILE_TESTER)

tests: $(CHARCOUNT_TESTER) $(COPYFILE_TESTER)

#==========
# run tests
#==========

check-get-char-count:
	$(CHARCOUNT_TESTER) $(TEST_TARGET)

check-copy-file:
	$(COPYFILE_TESTER) $(TEST_TARGET)

check-tests: check-get-char-count check-copy-file

#===================
# project-wide tasks
#===================

all: $(BIN) tests

clean:
	rm -rf bin; 
