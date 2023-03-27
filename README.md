# AOS_project_sem_4
file editor program is command line base program , which provide following functionalities     	
1. Creating a file in any mode provided by the user (mode in octal number only)     
        <b>./fe -c filename mode(in octal no)

2. Reading from a file      		
    a. User can read whole file.     		
        <b>./fe -r filename
    b. User can read only some bytes of file.     		
        <b>./fe -r filename BytesToRead
    c. User can read only some bytes of file, from any offset of file.  
        <b>./fe -r filename BytesToRead OffSet
   	
3. Wrinting into a file     		
    a. User can write any number of bytes in a file     		
            <b>./fe -w filename
    b. User can write some number of bytes in a file     		
            <b>./fe -w filename BytesToWrite
    c. User can override the data of file (if user sends a positive number including 0 as offset )    
            <b>./fe -w filename BytesToWrite OffSet 		
    d. User can append into the file (if user sends any negative number as offset)     	
            <b>./fe -w filename BytesToWrite NegativeOffSet
                
4. Creating copy of a file , User needs to provide source and destination of file     
            <b>./fe -cp sourceFile DestinationFile

5. Stats of a file , User will get following information of the file     		
    a. Size of file     		
    b. Owner Id     		
    c. Group Id     		
    d. Inode No     		
    e. Permissions of file     		
    f. No of Disk Blocks Allocated   
            <b>./fe -stat filename  	
   
If user wants to know the format of commands he can just execute the object file without any arguments.
            <b>./fe
