
#include "main.h"


// this function print the frame title by using user given options
int find_header(char title[])
{
     if(strcmp(title, "TIT2") == 0)
	 {
        printf("TITLE  ");
		return 1;
	 }
	 else if(strcmp(title, "TPE1") == 0)
	 {
          
		 printf("ARTIST ");
		 return 2;
	 }
	 else if(strcmp(title, "TALB") == 0)
	 {
		 printf("ALBUM  ");
		 return 3;
	 }
	 else if(strcmp(title,"TYER") == 0) 
	 {
		 printf("YEAR   ");
		 return 4;
	 }
	 else if(strcmp(title, "TCON") == 0)
	 {
		 printf("MUSIC  ");
		 return 5;
	 }
	 else if(strcmp(title,"TCOM") == 0)
	 {
		 printf("COMMENT");
		 return 6;
	 }
	 else
		 return 0;

}
