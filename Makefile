CC = gcc
CFLAGS = -Wall -Wextra -pedantic -ggdb -fsanitize=address

project_6: Console_IO_Utility.c File_Input_Utility.c File_Output_Utility.c Arizona_Tax_Utility.c project_6_.c
	$(CC) $(CFLAGS) Console_IO_Utility.c File_Input_Utility.c File_Output_Utility.c Arizona_Tax_Utility.c project_6_.c -o project_6 

clean:
	/bin/rm -f project_6