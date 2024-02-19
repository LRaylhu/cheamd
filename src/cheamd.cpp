#include <cstdio>
#include <cstdint>
#include <cstring>
#include <stdlib.h>

static int8_t input_file_processing(char *filename, char *buffer, size_t *length)
{
    //TEST(laura): Open file (filename) and read from it
    FILE *file_input = NULL;
    char temp_buffer[50];
    uint8_t line_len = 50;
    fopen_s(&file_input, filename,"r");
    if(!file_input)
    {
        return 1;
    }

    //Read each line and choose relevant information - store in buffer
    while(fgets(temp_buffer,line_len,file_input))
    {
        //TODO(laura): Check if the line is an atom line, grab info from temp_buff and put into buffer
    }

    //Close and free pointers
    fclose(file_input);
    free(file_input);
    return 0;
}

int main (int argc, char *argv[])
{
    
    //TEST(laura): Check if memcmp works here
    if (memcmp(argv[1],"-h",2))
    {
        //TODO(laura): provide help - commands and args: time of simulation, use GPU, output files 
        printf("Set first parameter as the file name, instead of -h. Such as:\ncheamd file.pdb\nThen choose options:\n-t <time of simulation> -p <GPU/CPU> -o <name of output file>\nexample: cheamd file.pdb -t 10ms -p GPU -o file_out (these are the defaults)\n");
        return 0;
    }

    //TODO(laura): Handle when no args; argc = 1? Then you say you can use -h for help.
    if(argc == 1)
    {
        printf("You can use -h as: cheamd -h to see help and available commands!\n");
        return 0;
    }
    
    //TODO(laura): Process the args to define app behaviour, set flags? Change some vars (for time it should change a value)
    //TODO(laura): Input files processing - Storage of a buffer with atom information
    //TEST(laura): If it wasn't -h then the argv[1] IS the filename
    char *filename = argv[1];
    char *atoms_buffer;
    size_t length = 0;
    if(input_file_processing(filename, atoms_buffer, &length) != 0 || length == 0)
    {
        printf("Could not open file: %s\n", filename);
        return 1;
    }
    //TODO(laura): Grid generation
    //TODO(laura): Storage of atoms in the grid structure
    //TODO(laura): Table with interaction data depending on type
    //TODO(laura): Pick initial atom - atom sampling - store new positions... next atom - sampling ...
    //TODO(laura): Apply transforms and correct poses - invalid positions

    return 0;
}
