#ifndef CLA_H
#define CLA_H

/**Command line arguments Validate functions**/

bool validateOperation(char* argv);
bool validateFile(char* argv);
bool validateSignedInt(char* argv);
bool validateUnsignedInt(char* argv);

/**Get arguments from command line arguments functions**/

char* getOperation(char** argv, int argc);
char* getFile(char** argv, int argc);
char* getSource(char**argv, int argc);
char* getDestination(char** argv, int argc);
char* getMode(char** argv, int argc);
char* getBytes(char** argv, int argc);
char* getOffset(char** argv, int argc);

/**Function to check if the overwrite flag is there in the arguments entered by the user*/

bool isOverWrite(char** argv, int argc);

#endif