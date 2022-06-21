// SplitFiles.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


#include <stdio.h>
#include <string>

FILE* stream, * stream2;

#define FILENAME1 "ddat"

int main(void)
{
    FILE* streamA;
    FILE* streamB;
    char list[500];
    int  count=0, numread, numwritten;

    std::string fnA= FILENAME1;

    fnA += ".txt";

 

    if (fopen_s(&streamA, fnA.c_str(), "r") == 0)
    {
        // Attempt to read in 25 characters
        numread = fread(list, sizeof(char), 200, streamA);

        while (numread) {
            printf("Number of items read = %d\n", numread);
            printf("Contents of buffer = %.125s\n", list);


            std::string fnB= FILENAME1;
            fnB += std::to_string(count);
            fnB += ".txt";
            if (fopen_s(&streamB, fnB.c_str(), "w") == 0)
            {
                while (fnB.size() < 20)fnB += " ";
                numwritten = fwrite(fnB.c_str(), sizeof(char), fnB.size(), streamB);
                printf("Wrote %d items\n", numwritten);
                numwritten = fwrite(list, sizeof(char), numread, streamB);
                printf("Wrote %d items\n", numwritten);
                fclose(streamB);

            }
            else
                printf("Problem opening the file\n");


            if (numread < 200)
                break;
            
            numread = fread(list, sizeof(char), 200, streamA);
            count++;
        }
        fclose(streamA);
    }


    else
        printf("File could not be opened\n");
}