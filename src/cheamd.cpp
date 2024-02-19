#include <cstdio>
#include <cstdint>
#include <cstring>
#include <stdlib.h>

static int8_t input_file_processing(char *filename, char *buffer, size_t *length) {
    //TEST(laura): Open file (filename) and read from it
    FILE *file_input = NULL;
    char temp_buffer[50];
    uint8_t line_len = 50;
    fopen_s(&file_input, filename,"r");
    if(!file_input) {
        return 1;
    }

    //Read each line and choose relevant information - store in buffer
    while(fgets(temp_buffer,line_len,file_input)) {
        //TODO(laura): Check if the line is an atom line, grab info from temp_buff and put into buffer
    }

    //Close and free pointers
    fclose(file_input);
    free(file_input);
    return 0;
}

//TODO(laura): I'm giving this chars for now, not gonna stay like this I want to store ints when necessary
struct process_args {
    char *time_of_process;
    char *gpu_cpu;
    char output_file[10];
};

int main (int argc, char *argv[]) {
    
    //TODO(laura): Here we can initialize to default args
    process_args main_args;

    //NOTE(laura): Don't know why argc == 1 does NOT work here
    if(!(argc >  1)) {
        printf("You can use -h as: cheamd -h to see help and available commands!\n");
        return 0;
    }

    //TODO(laura): provide help - commands and args: time of simulation, use GPU, output files. I'm just checking out how memcmp works
    if (!memcmp(argv[1],"-h",2)) {
        printf("Set first parameter as the file name, instead of -h. Such as:\ncheamd file.pdb\nThen choose options:\n-t <time of simulation> -p <GPU/CPU> -o <name of output file>\nexample: cheamd file.pdb -t 10ms -p GPU -o file_out (these are the defaults)\n");
        return 0;
    }
    
    //TODO(laura): Process the args to define app behaviour, set flags? Change some vars (for time it should change a value)
    for(int i = 2; i<argc;++i) {

        //FIXME(laura): There has to be a better way to do this, instead of a lot of ifs. Also check if argc >= works well
        //TEST: Check the first and last char sum (never start files with '-', only -t, -p etc.) so you always have dif depending on letter. Then use table
        if(!memcmp(argv[i], "-t", 2) && (argc >= i+1)) {
            main_args.time_of_process = argv[i+1];
        }

        if(!memcmp(argv[i], "-p", 2) && (argc >= i+1)) {
            main_args.gpu_cpu = argv[i+1];
        }
    }

    //TODO(laura): Input files processing - Storage of a buffer with atom information
    //TEST(laura): If it wasn't -h, and argc > 1, then the argv[1] IS the filename
    char *filename = argv[1];
    char *atoms_buffer = NULL;
    size_t length = 0;
    if(input_file_processing(filename, atoms_buffer, &length) != 0 || length == 0) {
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
