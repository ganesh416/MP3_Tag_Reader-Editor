**MP3 Tag Reader and Editor**

**Introduction**
MP3 tag reader is a software which will read and display MP3 (ID3) tag information from MP3 files. The software will be desktop based and not web based.
This documents is the System Requirements Specification (SRS) for MP3 tag reader.  The product will be useful to individuals who wish to view and collect 
mp3 tag data. This project can be extended to implement a tag editor, where in users can modify mp3 tag information.

**Scope**
The purpose of this SRS is to completely capture all the requirements pertaining to mp3 tag reader. It will be used for determining the architecture, and preparing design document.

** Development Environment**
We will be using C programming language and command line interface tool to manupulate metadata of mp3 file.

** The Main Ueser interface has following components:**
 1. A help menu
    
     This must display a help window showing all options
    ![image](https://github.com/user-attachments/assets/40389f68-0876-4bbd-8939-1471745d05b5)

3. All information must display all metadata related to mp3 file
   
   ![image](https://github.com/user-attachments/assets/e04a8079-e810-4f82-8cc3-3a932c6f0417)

**Functional Requirements**

 This section list the functional requirements for the application.
 
 **Mandatory features:**
 
 1. This application, should able to  handle all ID3 versions (Exept v2.4) 
tags.

 2. Display which version of ID3 tag is used.
    
 3. Display all the metadata information from ID3 tag.
    
 4. User should able to change tags according to options given (Refer: 
illustration 1).

 5. Should display a help screen on request (--help option).
  
 6. If any image embedded in file, display details about image (Type, path 
and size).

 7. If ID3 tag not found display proper error messages


**Additional features:  **

** Implement tag editor**

1. Add an option to extract the album art (image) from file .
   
2. Add an option to delete all tag datas from the file.
 
3. In corporate ID3v2.4 version .
  
4. It should be possible to delete a selected tag by options

**About (mp3) ID3 tag**
ID3 is a metadata container most often used in conjunction with the MP3 audio file format. It allows information such as the title, artist, album, track number, 
and other information about the file to be stored in the file itself. There are two unrelated versions of ID3: ID3v1 and ID3v2. You will have to first detect the ID3 version before getting the tag details.

** ID3v1 & ID3v1.1**
Total 128 bytes used for storing these metadata. If you one sum the the size of all these fields we see that 30+30+30+4+30+1 equals 125 bytes and not 128 bytes. The missing three bytes can be found at the 
very end of the tag, before the song title. These three bytes are always "TAG" and is the identification that this is indeed a ID3 tag. As all artists doesn't have a 30 character name it is said that if there is some bytes left after the information is entered in the 
field, those bytes should be fille with the binary value 0.


** ID3v2 , ID3v2.3 & ID3v2.4**

An ID3v2 tag starts with a tag header followed by one or more frames. Each frame in turn consists of a header and (usually) some kind of content.The ID3v2 tag is more flexible and hence more 
difficult to work with. An ID3v2 tag has a signature code of "ID3x" where x is the sub-version number of the tag. Typically ID3v2 tags are found at the beginning of an MP3 file but this is 
not an absolute restriction. What happens next depends on the subversion of the ID3v2 tag. As far as we can tell, there have been three versions so far: 2,3 and 4.


** ID3v2 header**
 ID3v2/file identifier   "ID3"
 ID3v2 version     $03 00 (2, 3 or 4)
 ID3v2 flags       %abc00000          
ID3v2 size       4 * %0xxxxxxx (Total size of ID3 tag)

**ID3v2.2 Frame header**

 Frame ID    $xx xx xx(Three characters)
 
 eg:TAL  Album/Movie/Show title
 
    TOA   Original artist(s)/performer(s)
    
Size        $xx xx xx(Three characters)

**ID3v2.3 or ID3v2.4 Frame header**

 Frame ID   $xx xx xx xx (Four characters)

     eg: TALB    Album/Movie/Show title

     TIT2    Title/songname/content description


Size     $xx xx xx xx (Four characters)
Flags       $xx xx


**Used C concepts are **
C concepts : File operator, functions, pointers and command line arguments

In this assignment i used two MP3 files like source file(music.mp3) and destination file (template.mp3), when user want to view MP3 tag reader, open source file in read mode and print details,
when user want to edit soming in the tag details, user open both source and destination files in read and write mode ("r+"), the destination file used to copy remaining data from source file after finding the option
that user passed via command line arguments, then after update old data with new data again copy remaing  data from destination file to source file.

 
 
   
