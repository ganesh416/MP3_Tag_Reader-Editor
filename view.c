

#include "main.h"



//for converting character size to int value
int normal_to_int(unsigned char bytes[4]) {
   return (bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | bytes[3];
}

void get_view_details(char file[])
{
	//store frame_header --> 10 bytes
	//header have--> frame id --> TIT2, TPE1,TYER,TALB,TCOM.. ECT.(4 bytes)
	//and have size of the title name -> 4 bytes
	//2 bytes flag
	char header[10];
	unsigned char size[4];
	char title[4];

	int t_size;

 

    //open file in read mode 
    FILE *ptr = fopen(file, "r");

    //check IDE from header 
    char ID[3];
	char ver[2];
    fread(header,1,10,ptr);
    strncpy(ID,header,3);
    ID[3] = '\0';
    //if not match then don't process with reading
   if(strcmp(ID,"ID3") != 0)
   {
	   return;
   }

   printf("-----------------------SELECED VIEW DETAILS-------------------\n\n");
   printf("--------------------------------------------------------------\n");
   printf("               MP3 TAG READER AND EDITOR FOR IDE3v2           \n");
   printf("--------------------------------------------------------------\n");


   while(1)
   {
	   //read frame header data
	   fread(header,1,10,ptr);
       //extract 4 byte frame id
	   strncpy(title,header,4);
	   title[4] = '\0'; 
	   //check respective  frame id 
	   //and print frame id using find_header
	   //it return if frame id match as per version2 else 0
      if(find_header(title) != 0)
	  {
		  //extract size from header data --> 4 bytes
		  for(int i = 0; i < 4; i++)
	      size[i] = header[i+4];
		  //size in char type convert into integer type call the function
		  //it return the size in int
	      t_size = normal_to_int(size);
          // print in table form
		  printf("        :         ");
		  //devclared one character array for storing title name
	      char t_name[100] = {0};
		  //read title name using size 
	      fread(t_name,1,t_size, ptr);
		  //using while loop printi title
	      int i = 1;
          while(t_name[i] != '\0')
		  {
			  printf("%c",t_name[i]);
			  i++;
		  }
		  printf("\n");
	      
	  }
	  else
	  {
		  break;
	  }
   }
   printf("--------------------------------------------------------------\n\n");
   printf("----------------DEATAILS DISPLAYED SUCCESSFULLY----------------\n");


}
