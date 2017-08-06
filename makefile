BINCHECK = if [ ! -d bin ]; then mkdir bin; fi;
TEST_BINCHECK = if [ ! -d bin/test ]; then mkdir -p bin/test; fi;
BIN = 'bin/finc'
COMPILER = 'clang'
FLAGS = '-w'

TEST_TARGET = 'test/several_directives/main.txt'
CHARCOUNT_TESTER = 'bin/test/get_char_count'
COPYFILE_TESTER = 'bin/test/copy_file'
DLOCATE_TESTER = 'bin/test/directive_locate'
DARRSIZE_TESTER = 'bin/test/directive_arr_size'
DCHECK_TESTER = 'bin/test/directive_check'
DTRIM_TESTER = 'bin/test/directive_trim'
LONGESTLINE_TESTER = 'bin/test/get_longest_line_length'
LINECOUNT_TESTER = 'bin/test/get_line_count'

# main binary
$(BIN): src/* src/util/*
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

$(DTRIM_TESTER): src/util/directive_trim.h src/test/directive_trim.c
	$(TEST_BINCHECK) $(COMPILER) $(FLAGS) src/test/directive_trim.c -o $(DTRIM_TESTER)

$(DLOCATE_TESTER): src/test/directive_locate.c src/directive_locate.h src/util/*
	$(TEST_BINCHECK) $(COMPILER) $(FLAGS) src/test/directive_locate.c -o $(DLOCATE_TESTER)

$(DARRSIZE_TESTER): src/test/directive_arr_size.c src/util/directive_arr_size.h
	$(TEST_BINCHECK) $(COMPILER) $(FLAGS) src/test/directive_arr_size.c -o $(DARRSIZE_TESTER)

$(LONGESTLINE_TESTER): src/file_attributes.h src/util/get_longest_line_length.h src/test/get_longest_line_length.c
	$(TEST_BINCHECK) $(COMPILER) $(FLAGS) src/test/get_longest_line_length.c -o $(LONGESTLINE_TESTER)

$(LINECOUNT_TESTER): src/file_attributes.h src/util/get_line_count.h src/test/get_line_count.c
	$(TEST_BINCHECK) $(COMPILER) $(FLAGS) src/test/get_line_count.c -o $(LINECOUNT_TESTER)

tests: $(CHARCOUNT_TESTER) $(COPYFILE_TESTER) $(DLOCATE_TESTER) $(DCHECK_TESTER) $(DARRSIZE_TESTER) $(LONGESTLINE_TESTER) $(LINECOUNT_TESTER) \
 $(DTRIM_TESTER)

#==========
# run tests
#==========

checkgetchar_count:
	$(CHARCOUNT_TESTER) $(TEST_TARGET)

checkcopy_file:
	$(COPYFILE_TESTER) $(TEST_TARGET)

checkdirective_check:
	$(DCHECK_TESTER) $(TEST_TARGET)

checkdirective_arr_size:
	$(DARRSIZE_TESTER) $(TEST_TARGET)

checkdirective_trim:
	$(DTRIM_TESTER) $(TEST_TARGET)

checklongest_line:
	$(LONGESTLINE_TESTER) $(TEST_TARGET)

checkline_count:
	$(LINECOUNT_TESTER) $(TEST_TARGET)

checkdirective_locate:
	$(DLOCATE_TESTER) $(TEST_TARGET)

checktests: checkget_char_count checkcopy_file checkdirective_check checkdirective_arr_size checkdirective_locate checklongest_line checkline_count \ checkdirective_trim

#===================
# project-wide tasks
#===================

all: $(BIN) tests

clean:
	rm -rf bin; 
