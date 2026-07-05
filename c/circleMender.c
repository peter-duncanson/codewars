void circle_mender(char *content)
{
    int lineNum = 0;
    char currentChar;
    char newline = 0x0A;
    char space = 0x20;
    char pound = 0x23;
    char newlineFlag = 0;
    char spaceFlag = 0;
    char poundFlag = 0;
    for (int i = 0; i <= 40; i ++) {
        currentChar = content[(lineNum * 40) + i];
        if (currentChar == space && !poundFlag && !spaceFlag) {
            spaceFlag = 1;
        }
        if (currentChar == pound) {
            
        }
    }
}
