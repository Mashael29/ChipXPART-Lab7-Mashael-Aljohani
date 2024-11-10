#include <stdio.h>

int main() {
    //open the input file (bitsream.bit) for reading 
    //and the output file (bitsream.hex) for creating and wrting 
    FILE *inputFile = fopen("bitstream.bit", "r");
    FILE *outputFile = fopen("bitstream.hex", "w");

    //check if the files opened 
    if (!inputFile || !outputFile) {
        printf("Error: Could not open input or output file.\n");
        return 1;
    }

    int bit; //to store each bit (0 or 1) that read from the file
    int byte = 0; //to gather the 8 bits into a single byte
    int count = 0; //to count how many bits i have gather so far

    // Read each bit from the input file
    while ((bit = fgetc(inputFile)) != EOF) {
        if (bit == '0' || bit == '1') {
            // Shift bits into place in little-endian order
            byte |= (bit - '0') << count;
            count++;

            // If we have 8 bits, write the hexadecimal value to output
            if (count == 8) {
                fprintf(outputFile, "%02X\n", byte);
                count = 0; //reset the counter for the next byte
                byte = 0; 
            }
        }
    }

    // If there are remaining bits, pad with zeros and write them as well
    if (count > 0) {
        fprintf(outputFile, "%02X\n", byte);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Conversion complete! Check bitstream.hex for output.\n");
    return 0;
}
