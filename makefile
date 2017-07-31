BINCHECK = if [ ! -d bin ]; then mkdir bin; fi;
TEST_BINCHECK = if [ ! -d bin/test ]; then mkdir -p bin/test; fi;
BIN = 'bin/finc'
COMPILER = 'clang'
FLAGS = '-Weverything'

TEST_TARGET = 'test/several_directives/main.txt'
CHARCOUNT_TESTER = 'bin/test/get_char_count'
COPYFILE_TESTER = 'bin/test/copy_file'
DCHECK_TESTER = 'bin/test/directive_check'

# main binary
$(BIN): src/* 
	$(BINCHECK) $(COMPILER) $(FLAGS) src/main.c -o $(BIN);

check:
	$(BIN) test/several_directives/main.txt

#============
# build tests
#============

$(CHARCOUNT_TESTER): src/file_attributes.h src/get_char_count.h src/test/get_char_count.c
	$(TEST_BINCHECK) $(COMPILER) $(FLAGS) src/test/get_char_count.c -o $(CHARCOUNT_TESTER)

$(COPYFILE_TESTER): src/file_attributes.h src/copy_file.h src/test/copy_file.c
	$(TEST_BINCHECK) $(COMPILER) $(FLAGS) src/test/copy_file.c -o $(COPYFILE_TESTER)

$(DCHECK_TESTER): src/file_attributes.h src/test/directive_check.c
	$(TEST_BINCHECK) $(COMPILER) $(FLAGS) src/test/directive_check.c -o $(DCHECK_TESTER)

tests: $(CHARCOUNT_TESTER) $(COPYFILE_TESTER) $(DCHECK_TESTER)

#==========
# run tests
#==========

checkgetchar_count:
	$(CHARCOUNT_TESTER) $(TEST_TARGET)

checkcopy_file:
	$(COPYFILE_TESTER) $(TEST_TARGET)

checkdirective_check:
	$(DCHECK_TESTER) $(TEST_TARGET)

checktests: checkget_char_count checkcopy_file checkdirective_check

#===================
# project-wide tasks
#===================

all: $(BIN) tests

clean:
	rm -rf bin; 
