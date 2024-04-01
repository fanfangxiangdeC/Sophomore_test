#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("git add ./");
    system("git commit -m\"code commit\"");
    system("git push");
    return 0;
}