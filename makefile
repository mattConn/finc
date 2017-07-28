BINCHECK = if [ ! -d bin ]; then mkdir bin; fi; 
BIN = 'bin/include-file'
COMPILER = 'clang'
FLAGS = '-Weverything'

$(BIN): src/main.c src/directive_matching.h src/scanner.h
	$(BINCHECK) $(COMPILER) $(FLAGS) src/main.c -o $(BIN);

check:
	$(BIN) test/several_directives/main.txt

check-no-directives:
	$(BIN) test/no_directives.txt

check-mangled-directives:
	$(BIN) test/mangled_directives.txt

all: $(BIN) check check-no-directives check-mangled-directives

clean:
	rm $(BIN); rm -r bin; 
