// Attributes of file being scanned
typedef struct {
    FILE *input;
    int char_count;
    char input_char;
	char copy[];
}file_attr;

file_attr file;
