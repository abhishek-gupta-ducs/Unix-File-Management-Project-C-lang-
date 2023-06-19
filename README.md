# Unix File Management Project (C lang)

  

This is a command-line based project that provides the following functionalities:

  

## 1. Creating a file in any mode provided by the user (mode in octal number only)

  

```./fe -op --c -f filename -m mode(in octal no)```

  

## 2. Reading from a file

  

### a. User can read the whole file.

  

```./fe -op --r -f filename```

  

### b. User can read only some bytes of the file.

  

```./fe -op --r -f filename -b BytesToRead```

  

### c. User can read only some bytes of the file from any offset of the file.

  

```./fe -op --r -f filename -b BytesToRead -o Offset```

  
  

## 3. Writing into a file

  

### a. User can write any number of bytes into a file.

  

`./fe -op --w -f filename`

  
  

### b. User can write some number of bytes into a file.

  

`./fe -op --w -f filename -b BytesToWrite`

  
  

### c. User can overwrite the data of the file at any offset of the file by including the `--ow` flag.

  

`./fe -op --w -f filename -b BytesToWrite -o Offset --ow`

  

**Note:** If the user does not include the `--ow` (overwrite) flag, the entered data will be inserted at the offset in the file.

  

### d. User can append to the file by default or if any negative number is sent as the offset.

  

`./fe -op --w -f filename -b BytesToWrite -o NegativeOffset`

  
  

## 4. Creating a copy of a file

  

User needs to provide the source and destination of the file.

  

```./fe -op --cp -s sourceFile -d DestinationFile```

  
  

## 5. File stats

  

User will get the following information about the file:

  

a. Size of the file

b. Owner Id

c. Group Id

d. Inode No

e. Permissions of the file

f. Number of Disk Blocks Allocated

  

```./fe -op --stat -f filename```

  
  

## Getting command format documentation

  

If the user wants to know the format of the commands, they can use the following command:

  

```./fe -op --help```

  
  

## Flags and their corresponding operations

  

(Each flag is case-insensitive)

  

- `--help`: To get the documentation of the program

- `-op`: To denote the operation the user wants to perform on the file

- `--c`: To create a file

- `-f`: To enter the file name

- `-m`: To enter the file mode (in Octal)

- `--r`: To read from a file

- `-b`: Number of Bytes to Read

- `-o`: Offset of the file

- `--w`: To write into a file

- `--ow`: To overwrite into a file

- `--cp`: To copy a file

- `-s`: Source file or path

- `-d`: Destination file or path

- `--stat`: To get the stats of a file

## Results (Screenshots)
![1.png](/Results/1.png)
![2.png](/Results/2.png)
![3.png](/Results/3.png)
![4.png](/Results/4.png)
![5.png](/Results/5.png)
![6.png](/Results/6.png)
![7.png](/Results/7.png)
![8.png](/Results/8.png)
![9.png](/Results/9.png)