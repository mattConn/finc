int directive_detection_i = 0;
bool directive_detection(char s)
{
    bool status=false;
    if(s == directive[directive_detection_i])
        directive_detection_i++;

    if(directive_detection_i == 2)
    {
        directive_detection_i = 0;
        status = true;
    }
    return status;
}

