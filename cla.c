#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "cla.h"

/**Command line arguments Validate functions**/

bool validateOperation(char* argv){
    if(!strcmp(argv,"--help") || !strcmp(argv,"--c") || !strcmp(argv,"--r") || !strcmp(argv,"--w") || !strcmp(argv,"--cp") ||!strcmp(argv,"--stat")){
        return true;
    }
    return false;
}

bool validateFile(char* argv){
    int i=0;
    //check if it is not a flag
    char ch = argv[0];
    if(ch=='-'){
        return false;
    }
    // Check for invalid characters
    while (argv[i] != '\0') {
        char ch = argv[i];
        if (ch == '\\' || ch == '?' || ch=='~' || ch == '*' || ch == ':' || ch == '"' || ch == '<' || ch == '>' || ch == '|') {
            return false;
        }
        i++;
    }
    // Check if the file name ends with a period
    int len = i;
    if (len > 0 && argv[len - 1] == '.') {
        return false;
    }
    return true;
}

bool validateSignedInt(char* argv){
    int i=0;
    if(argv[0]=='-'){
        i = 1;
    }
    while(argv[i]!='\0'){
        char ch = argv[i];
        if(ch <'0' || ch >'9'){
            return false;
        }
        i++;
    }
    return true;
}

bool validateUnsignedInt(char* argv){
    int i=0;
    while(argv[i]!='\0'){
        char ch = argv[i];
        if(ch <'0' || ch >'9'){
            return false;
        }
        i++;
    }
    return true;
}

/**Get arguments from command line arguments functions**/

char* getOperation(char** argv, int argc){
    for(int i=0; i<argc && i+1<<argc; i++){
        if((!strcmp(argv[i],"-op") || !strcmp(argv[i],"-oP") || !strcmp(argv[i],"-Op") || !strcmp(argv[i],"-OP"))&&(i+1<argc))
        {
            if(validateOperation(argv[i+1])==true) 
                return argv[i+1];
        }
    }
    return "NULL";
}

char* getFile(char** argv, int argc){
    for(int i=0; i<argc && i+1<<argc; i++){
        if((!strcmp(argv[i],"-f") || !strcmp(argv[i],"-F"))&&(i+1<argc))
        {
            if(validateFile(argv[i+1])==true) 
                return argv[i+1];
        }
    }
    return "NULL";
}

char* getSource(char**argv, int argc){
    for(int i=0; i<argc && i+1<<argc; i++){
        if((!strcmp(argv[i],"-S") || !strcmp(argv[i],"-s"))&&(i+1<argc))
        {
            if(validateFile(argv[i+1])==true) 
                return argv[i+1];
        }
    }
    return "NULL";
}

char* getDestination(char** argv, int argc){
    for(int i=0; i<argc && i+1<<argc; i++){
        if((!strcmp(argv[i],"-D") || !strcmp(argv[i],"-d"))&&(i+1<argc))
        {
            if(validateFile(argv[i+1])==true) 
                return argv[i+1];
        }
    }
    return "NULL";
}

char* getMode(char** argv, int argc){
    for(int i=0; i<argc && i+1<<argc; i++){
        if((!strcmp(argv[i],"-m") || !strcmp(argv[i],"-M"))&&(i+1<argc))
        {
            if(validateUnsignedInt(argv[i+1])==true) 
                return argv[i+1];
        }
    }
    return "NULL";
}

char* getBytes(char** argv, int argc){
    int flag = 0;
    for(int i=0; i<argc && i+1<<argc; i++){
        if((!strcmp(argv[i],"-b") || !strcmp(argv[i],"-B"))&&(i+1<argc))
        {
            flag = 1;
            if(validateUnsignedInt(argv[i+1])==true) 
                return argv[i+1];
        }
    }
    if(flag==0)
        return "NULL";
    else 
        return "INVALID";
}

char* getOffset(char** argv, int argc){
    int flag = 0;
    for(int i=0; i<argc && i+1<<argc; i++){
        if((!strcmp(argv[i],"-O") || !strcmp(argv[i],"-o"))&&(i+1<argc))
        {
            flag = 1;
            if(validateSignedInt(argv[i+1])==true) 
                return argv[i+1];
        }
    }
    if(flag==1){
        return "INVALID";
    }
    return "NULL";
}

bool isOverWrite(char** argv, int argc){
    for(int i=0; i<argc; i++){
        if(!strcmp(argv[i],"---ow")||!strcmp(argv[i],"---oW")||!strcmp(argv[i],"---Ow")||!strcmp(argv[i],"---OW")){
            return true;
        }
    }
    return false;
}