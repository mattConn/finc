BINCHECK = if [ ! -d bin ]; then mkdir bin; fi; 
BIN = 'test/several_directives/include-file'

$(BIN): src/main.c src/directive_matching.h src/scanner.h
	$(BINCHECK) gcc -Wall src/main.c -o $(BIN);

check:
	$(BIN) test/several_directives/main.txt

check-no-directives:
	$(BIN) test/no_directives.txt

check-mangled-directives:
	$(BIN) test/mangled_directives.txt

all: $(BIN) check check-no-directives check-mangled-directives

clean:
	rm $(BIN); rm -r bin; 
