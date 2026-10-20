#include<stdio.h>
#include<stdlib.h>

int xstrlen(char *s);

void xstrcpy(char *d,char *s);

char* mstrcat(char str1[],char str2[]);

char* sstrcat(char str1[],char str2[]);

int xstrcmp(char *p1,char *p2);

static char strfinal[40];

int main()
{   
    char *ps, *pm;
    int c,c3,l,r;
    char str1[20],str2[20];

    printf("Press 1 for strlen, 2 for strcpy, 3 for strcat and 4 for strcmp\n");
    scanf("%d",&c);
    getchar();

    switch(c)
    {
        case 1:
            printf("Enter string\n");
            gets(str1);
            l=xstrlen(str1);
            printf("Length of the string is %d\n",l);
            break;
        
        case 2:
            printf("Enter source string\n");
            gets(str1);
            xstrcpy(str2,str1);
            printf("Destination string is %s",str2);
            break;

        case 3:
            printf("Enter string 1\n");
            gets(str1);
            printf("Enter string 2\n");
            gets(str2);

            printf("Enter 1 to use method 1 and 2 to use method 2\n");
            scanf("%d",&c3);

            switch(c3)
            {
                case 1:
                    ps=sstrcat(str1,str2);
                    puts(ps);
                    break;
                    
                case 2:
                    pm = mstrcat(str1, str2);
                    puts(pm);
                    break;
            }
            break;

        case 4:
            printf("Enter string 1\n");
            gets(str1);

            printf("Enter string 2\n");
            gets(str2);

            r=xstrcmp(str1,str2);
            printf("%d",r);
            break;
    }
}

// This is a user-defined function to find the length of a string
int xstrlen(char *s)
{
    int i=0;

    while(*s!='\0')
    {
        i++;
        s++;
    }
    return i;
}

// This is a user-defined string copy function
void xstrcpy(char *d,char *s)
{
    while(*s!=0)
    {
        *d=*s;
        s++;
        d++;
    }
    *d='\0';
}

// This is a user-defined string concatenation function which uses static memory allocation
char* sstrcat(char str1[],char str2[])
{   
    int i=0,j=0;
    
    
    while(str1[i]!='\0')
    {
        strfinal[i]=str1[i];
        i++;

    }
    while(str2[j]!='\0')
    {
        strfinal[i]=str2[j];
        j++;
        i++;
    }
    strfinal[i] = '\0';
    
    return strfinal;
    
}

// This is a user-defined string concatenation function which uses dynamic memory allocation
char* mstrcat(char str1[],char str2[])
{   
    int i=0,j=0;
    int len1 = 0, len2 = 0;
    int total_len;
    char *newstr, *retstr;

    len1 = xstrlen(str1);
    len2 = xstrlen(str2);

    total_len = len1+len2+1;
    newstr=malloc(total_len*sizeof(char));
    retstr = newstr;

    while(str1[i]!='\0')
    {
        *newstr=str1[i];
        i++;
        newstr++;

    }
    while(str2[j]!='\0')
    {
        *newstr=str2[j];
        j++;
        newstr++;
    }
    *newstr = '\0';

    return retstr;   
}

// This is a user-defined function which compares two strings and returns value 0 if both strings are equal else returns the numeric difference between the ascii values of the non-matching characters
int xstrcmp(char *p1,char *p2)
{
    int r=0;

    while(*p1==*p2 && *p1!='\0')
    {
        p1++;
        p2++;
    }
    r=*p1-*p2;
    
    return r;
}