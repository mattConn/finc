// Attributes of file being scanned
typedef struct {
    FILE *input;
    int char_count;
    char input_char;
}file_attr;

file_attr file;

void reset_file_attr()
{
    //reset input file attributes 
    rewind(file.input);
    fclose(file.input);
    file.input_char = '\0';
    file.char_count = 0;
}
