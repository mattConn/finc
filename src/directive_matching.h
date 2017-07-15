// Match single characters from some stream against single characters in directive char array

int directive_detection_i = 0;
char directive[] = {"##INCLUDE "};
int directive_count = 0;

bool directive_detection(char s)
{
    bool status=false;
    if(s == directive[directive_detection_i])
        directive_detection_i++;
	else
        directive_detection_i=0;

    if(directive_detection_i == sizeof(directive)/sizeof(directive[0])-1)
    {
        directive_detection_i = 0;
        status = true;
    }
    return status;
}

