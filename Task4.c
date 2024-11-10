#include <stdio.h>
#include <string.h>

void encrypt(char *input, char *output) {
    int i = 0;
    while (input[i] != '\0') { //loop through each character of the string
        if (input[i] >= 'A' && input[i] <= 'Z') { //check if character is uppercase
            output[i] = (input[i] - 'A' - 3 + 26) % 26 + 'A'; // shift the letter by 3 positions
        } else if (input[i] >= 'a' && input[i] <= 'z') { // check if character is lowercase
            output[i] = (input[i] - 'a' - 3 + 26) % 26 + 'a'; // shift lowercase letter by 3 positions
        } else {
            output[i] = input[i]; // if it's not a letter, keep it unchanged
        }
        i++;
    }
    output[i] = '\0'; // End the string with a null 
}

void decrypt(char *input, char *output) {
    int i = 0;
    while (input[i] != '\0') { //loop through each character of the string
        if (input[i] >= 'A' && input[i] <= 'Z') { //check if character is uppercase
            output[i] = (input[i] - 'A' + 3) % 26 + 'A'; //shift letter by 3 positions back
        } else if (input[i] >= 'a' && input[i] <= 'z') { //check if character is lowercase
            output[i] = (input[i] - 'a' + 3) % 26 + 'a'; //shift lowercase letter by 3 positions back
        } else {
            output[i] = input[i]; //if it's not a letter, keep it unchanged
        }
        i++;
    }
    output[i] = '\0'; //end the string with a null character
}

void encrypt_from_file(const char *input_filename, const char *output_filename) {
    FILE *infile = fopen(input_filename, "r");
    if (infile == NULL) {
        printf("Error: Could not open input file.\n");
        return;
    }

    FILE *outfile = fopen(output_filename, "w");
    if (outfile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(infile);
        return;
    }

    char ch;
    while ((ch = fgetc(infile)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            fputc((ch - 'A' - 3 + 26) % 26 + 'A', outfile); // encrypt uppercase
        } else if (ch >= 'a' && ch <= 'z') {
            fputc((ch - 'a' - 3 + 26) % 26 + 'a', outfile); //encrypt lowercase
        } else {
            fputc(ch, outfile); // copy other characters unchanged
        }
    }

    fclose(infile);
    fclose(outfile);
    printf("File encrypted successfully.\n");
}

void decrypt_from_file(const char *input_filename, const char *output_filename) {
    FILE *infile = fopen(input_filename, "r");
    if (infile == NULL) {
        printf("Error: Could not open input file.\n");
        return;
    }

    FILE *outfile = fopen(output_filename, "w");
    if (outfile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(infile);
        return;
    }

    char ch;
    while ((ch = fgetc(infile)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            fputc((ch - 'A' + 3) % 26 + 'A', outfile);   //decrypt uppercase
        } else if (ch >= 'a' && ch <= 'z') {
            fputc((ch - 'a' + 3) % 26 + 'a', outfile);  // decrypt lowercase
        } else {
            fputc(ch, outfile); //copy other characters unchanged
        }
    }

    fclose(infile);
    fclose(outfile);
    printf("File decrypted successfully.\n");
}

int main() {
    char choice;
    char data_choice;
    char input[1024], output[1024];
    char input_filename[100], output_filename[100];

    printf("Welcome to the Caesar Cipher Program!\n");

    //ask the user if they want to Encrypt or Decrypt
    printf("Do you want to perform (E)ncryption or (D)ecryption? ");
    scanf(" %c", &choice);

    // if encryption is selected
    if (choice == 'E' || choice == 'e') {
        printf("Do you want to encrypt data from a (F)ile or enter a (S)tring? ");
        scanf(" %c", &data_choice);

        if (data_choice == 'S' || data_choice == 's') {
            //encrypt a string entered by the user
            printf("Please enter the string to encrypt: ");
            getchar();  //to consume newline character
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0; //Remove newline from input string
            encrypt(input, output);
            printf("Encrypted string: %s\n", output);
        } else if (data_choice == 'F' || data_choice == 'f') {
            //encrypt a file
            printf("Please enter the filename to encrypt: ");
            scanf("%s", input_filename);
            printf("Please enter the output filename: ");
            scanf("%s", output_filename);
            encrypt_from_file(input_filename, output_filename);
        } else {
            printf("Invalid option! Please choose F or S.\n");
        }
    }
    // if decryption is selected
    else if (choice == 'D' || choice == 'd') {
        printf("Do you want to decrypt data from a (F)ile or enter a (S)tring? ");
        scanf(" %c", &data_choice);

        if (data_choice == 'S' || data_choice == 's') {
            //decrypt a string entered by the user
            printf("Please enter the string to decrypt: ");
            getchar();  //to consume newline character left by previous scanf
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = 0; // remove newline from input string
            decrypt(input, output);
            printf("Decrypted string: %s\n", output);
        } else if (data_choice == 'F' || data_choice == 'f') {
            // decrypt a file
            printf("Please enter the filename to decrypt: ");
            scanf("%s", input_filename);
            printf("Please enter the output filename: ");
            scanf("%s", output_filename);
            decrypt_from_file(input_filename, output_filename);
        } else {
            printf("Invalid option! Please choose F or S.\n");
        }
    }
    else {
        printf("Invalid choice! Please choose E or D.\n");
    }

    return 0;
}
