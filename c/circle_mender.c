void circle_mender(char *content)
{
    int inside = 0; // flag to see if we are inside the circle
    for (char *c = content; *c != 0; c += 41) // iterate line by line in outer loop
    {
        for (char *s = c + 40; s != c; s--) // find the last # character
        {
            if (*s == '#')
            {
                for (char *a = c; a != s; a++) // iteratre through the line until the last # character
                {
                    if (*a == '#') inside = 1; // when we reach the first #, we are inside
                    if (inside)
                    {
                        if (*a == ' ') *a = '#';
                    }
                }
                inside = 0; // set inside flag back to 0 for next line
                break;
            }
        }
    }
}
