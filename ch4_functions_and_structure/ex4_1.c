/* Right-most substring */
#include <stdio.h>

int strrindex(char corpus[], char target[]);
int issubstr(char corpus[], char target[], int startloc);
void teststrrindex(char corpus[], char target[], int expectedresult);

int main() {

    teststrrindex("hahaha", "your face", -1);
    teststrrindex("hahaha", "ha", 4);
    teststrrindex("seasons greetings", "greet", 8);
    teststrrindex("the bear", "bears", -1);
    teststrrindex("seaseasons greetings", "season", 3);
    teststrrindex("", "hi", -1);
    teststrrindex("hi", "", -1);
    teststrrindex("", "", -1);

    return 0;
}


int strrindex(char corpus[], char target[]) {
    int substrindex, i;
    char startchar;

    startchar = target[0];
    substrindex = -1;

    for (i = 0; corpus[i] != '\0'; i++) {
        if (corpus[i] == startchar && issubstr(corpus, target, i))
            substrindex = i;
    }

    return substrindex;
}


int issubstr(char corpus[], char target[], int startloc) {
    int i;

    for (i = 0; target[i] != '\0'; i++) {
        if (target[i] != corpus[startloc + i] || corpus[startloc + i] == '\0')
            return 0; /* not the same */
    }

    return 1; /* made it through loop, so target is a substring 
                 of corpus starting at startloc */
}


void teststrrindex(char corpus[], char target[], int expectedresult) {
    int res = strrindex(corpus, target);

    if (res == expectedresult)
        printf("ok\n");
    else {
        printf("\nFAIL, expected %d got %d\nfor %s in %s\n\n", 
               expectedresult, res, target, corpus);
    }
}
