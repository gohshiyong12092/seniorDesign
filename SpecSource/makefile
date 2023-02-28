CC = gcc 
FFLAGS = -O3 -Wall
LFFLAG = 
OBJECTS = testVector.o 

.PHONY: clean help

main.exe: $(OBJECTS) 
	$(CC) $(LFFLAG) $(OBJECTS) -o main.exe

%.o:%.c
	$(CC) $(FFLAGS) -c $< 

clean:
	rm -f $(OBJECTS) main.exe