

#include "main.h"

//converting int size to char size
void int_to_normal(int value, unsigned char bytes[4]) {
    bytes[0] = (value >> 24) & 0xFF;
    bytes[1] = (value >> 16) & 0xFF;
    bytes[2] = (value >> 8) & 0xFF;
    bytes[3] = value & 0xFF;
}

void edit_details(char *argv[])
{


    //store frame_header --> 10 bytes
	//header have--> frame id --> TIT2, TPE1,TYER,TALB,TCOM.. ECT.(4 bytes)
	//and have size of the title name -> 4 bytes
	//2 bytes flag
 	char header[10];
	unsigned char size[4];
	char title[4];
	int t_size;
	char t_name[100] = {0};


    //here we need two files for copy data from one file to another file for update title names
	//open both srouce and destination file in read mode and write
	//after finding the which option user passed to update data, we just copy the remain data from sorce file to destination file
    FILE *src_fd = fopen(argv[4], "r+");
    FILE *des_fd = fopen("template.mp3", "r+");
    //calculating len of data that we need to update
    int len= strlen(argv[3]);
	//based on given data length creat another char array
    char n_data[len];
	//and copy that data from command line araument
    strcpy(n_data,argv[3]);
    len +=1;
    
	//convert int size into char size for update the size in file
    unsigned char normal_size[4];
    int_to_normal(len,normal_size);
    // to track the pointer postion
    long int p = 0;

    //check IDE from header 
    char ID[3];
	char ver[2];
    fread(header,1,10,src_fd);
    strncpy(ID,header,3);
    ID[3] = '\0';
    //if not match then don't process with reading
    if(strcmp(ID,"ID3") != 0)
    {
		printf("Please give IDE Version 2 MP3 file\n");
	    return;
    }

 
    
   printf("------------------------------------------SELECTED EDIT DETAILS-----------------------------------\n\n");

   while(1)
   {
	   //read 10 bytes and check which option passed by user via cmnd line
	   fread(header,1,10,src_fd);
	   //to track pointer position
	   p = ftell(src_fd);
	   //extract frame_header
	   strncpy(title,header,4);
	   title[4] = '\0';
	   //extract size and convert into integer
	   for(int i = 0; i < 4; i++)
		   size[i] = header[i+4];
	   t_size = normal_to_int(size);
	   //compare with user passed option
	   if(strcmp(title, argv[2]) == 0)
	   {
		   //move file pointer size number of bytes
		   fseek(src_fd,t_size, SEEK_CUR);
          //then copy remaining data from source file to destination file
           char buf[50];
           while(fread(buf,1,50,src_fd) >0)
		   {
			   fwrite(buf,1,50,des_fd);
		   }
            
		   //after copy the remaining data
		   //update the data from user selected option

		   //rewind the ptr to user selected option
		   fseek(src_fd,p,SEEK_SET);
		   //before update data, update old size with new data size
		   fseek(src_fd,-6,SEEK_CUR);
		   fwrite(normal_size,1,4,src_fd);
	       //after update the size move ptr to old data fisrt posirion
		   fseek(src_fd,3,SEEK_CUR);
           // then update the old data with new data
		   fwrite(n_data,1,len-1,src_fd);
           // then again copy all data from destination file to source file
		   fseek(des_fd,0,SEEK_SET);
		   while(fread(buf,1,50,des_fd) > 0)
		   {
			   fwrite(buf,1,50,src_fd);
		   }
           
		    // print the successfull message
            printf("---------------------  CHANGE THE ");
			find_header(title);
			printf("--------------------------\n\n");
			find_header(title);
			printf("           :    %s \n\n",  argv[3]);
			printf("---------------");
			find_header(title);
			printf("CHANGED SUCCESSFULLY---------------------\n\n");


		   break; 

	   }
	   fread(t_name,1,t_size,src_fd);
	   
   }


   fclose(src_fd);
   fclose(des_fd);


}

