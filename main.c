/*
Name: Ganesh pyndla
Date: 27-07-2024
Description: MP3 tag Reader and Editor
*/

#include "main.h"

//read command line arguments
int main(int argc, char *argv[])
{
	//check command arguments passed or not
	if(argc > 1)
	{
       //in this is project we have to do MP3 reader and edito
	   //-v ---> MP3 reader
		//-e --> MP3 editor
       if(strcmp(argv[1],"-v") == 0)
	   {
		   //check extenstion of the file
		   if(strstr(argv[2],".mp3") != NULL)
		   {
			   //call the function to view the details
			   get_view_details(argv[2]);
		   }
		   else
		   {
			     //if user give insufficent arguments then show eerors
		         printf("ERROR: ./a.out : INVALID ARGUMENTS\nUSAGE : \n");
	 	         printf("To view please pass Like:  ./a.out -v mp3filename\n");
			   
		   }
	   }
	   //MP3 Editor
	   else if(strcmp(argv[1],"-e") ==0)
	   {
         
		    //check mp3 file passed or not  
		   if(strstr(argv[4],".mp3") != NULL)
		   {
			  //while editing we have different options
			  //update option with corresponding frame_header name 
              if(strcmp(argv[2], "-t") == 0)
			  {
				  argv[2] = "TIT2";
			  }
			  else if(strcmp(argv[2], "-a") == 0)
			  {
				  argv[2] = "TPE1";
			  }
			  else if(strcmp(argv[2], "-A") == 0)
			  {
				  argv[2] = "TALB";
			  }
			  else if(strcmp(argv[2], "-y") == 0)
			  {
				  argv[2] = "TYER";
			  }
			  else if(strcmp(argv[2], "-m") == 0)
			  {
				  argv[2] = "TCON";
			  
			  }
			  else if(strcmp(argv[2], "-c") == 0)
			  {
				  argv[2] = "TCOM";
			  }
			   
			  //call the function for edit give frame 
			  edit_details(argv);
		
		   }
		   else
		   {
			     //if user entered invalid arguments
		         printf("ERROR: ./a.out : INVALID ARGUMENTS\nUSAGE : \n");
		         printf("To edit please pass like : ./a.out -e -t/-a/-A/-m/-y/-c changing_text Mp3filename\n");
		   }
	   }
	   //if user want help which option they want pass --help to command line
		else if(strcmp(argv[1],"--help") == 0)
		{
			printf("\n\n-----------------------------HELP MENU----------------------------------------\n\n");
			printf("1. -v -> to view mp3 file contents\n");
			printf("2. -v -> to view mp3 file contents\n");
			printf("         2.1. -t -> to edit song title\n");
			printf("         2.2. -a -> to edit artist name\n");
			printf("         2.3. -A -> to edit album name\n");
			printf("         2.4. -y -> to edit year\n");
			printf("         2.5. -m -> to edit content\n");
			printf("         2.6. -c -> to edit comment\n");
			printf("\n--------------------------------------------------------------------------------\n\n");

		}

	}
	//error message and usage
	else
	{
		printf("---------------------------------------------------------------------------------\n\n");
		printf("ERROR: ./a.out : INVALID ARGUMENTS\nUSAGE : \n");
		printf("To view please pass Like:  ./a.out -v mp3filename\n");
		printf("To edit please pass like : ./a.out -e -t/-a/-A/-m/-y/-c changing_text Mp3filename\n");
		printf("To get help pass like : ./a.out --help\n\n");
		printf("---------------------------------------------------------------------------------\n\n");

	}

}
