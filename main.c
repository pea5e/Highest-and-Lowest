#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void high_and_low (const char *strnum, char *result)
{
  
  int max=-1,min=-1,maxl,minl,i,x=1;
  while(x<strlen(strnum))
  {
    i=1;
    while( x+i<strlen(strnum) && strnum[strlen(strnum)-(x+i+1)]!=' ' ){ i++; }
    
    //printf("%c %c",strnum[max],strnum[min]);

    x += i;
    if( max==-1 || maxl-(2*((int)strnum[max]=='-'))<i-(2*((int)strnum[strlen(strnum)-x]=='-')) || maxl==i && strnum[strlen(strnum)-x]>strnum[max] )
    {
        max = strlen(strnum)-x;
        maxl = i;
    }   
    if( min==-1 || minl-(2*((int)strnum[min]=='-'))>i-(2*((int)strnum[strlen(strnum)-x]=='-')) )
    {
        min = strlen(strnum)-x;
        minl = i;
    }
    else if( min!=-1 && minl==i && strnum[strlen(strnum)-x]<strnum[min] )
    {
        
    }
 
  }
    // printf("%c %c",strnum[max],strnum[min]);
    // printf("%d %d",max,min);
    i=0;
    while(strnum[max+i]!=' ')
     {
        result[i] = strnum[max+i] ;
        i++;
     }
     result[i] = strnum[max+i];
     x = i+1;
     i=0;
    while(strnum[min+i]!=' ')
     {
        result[i+x] = strnum[min+i] ;
        i++;
     }
  
}

int main() {
    char result[256];
    high_and_low ("9 -4 7 3 4 -3 6",result);
    printf("%s",result);
    return 1;
}
