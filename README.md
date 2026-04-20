# Memory Manager

A simple C program for managing data in memory at the byte level with persistence capabilities. 
- Project for **educational purpose**.

## Description

This program allows users to read and write different data types (integers and characters) to memory, with the data being persisted to a binary file. The memory structure consists of two main sections:

- Integer array (64 bytes - 16 integers)
- Character array (16 bytes - 16 characters)

## Features

- Read/Write operations for integers and characters
- Persistent storage using binary files
- Memory initialization on first run
- User-friendly interface for operations
- Byte-level memory management

## Project Structure

```
memory_gestor/
├── data_manipulation/
│   ├── data_access.c     # Data reading/writing operations
│   └── data_access.h     
├── runtime_memory/
│   ├── manage_runtime_memory.c    # Memory management functions
│   └── manage_runtime_memory.h
├── user_interaction/
│   ├── user_interaction.c    # User interface functions
│   └── user_interaction.h
└── main.c    # Program entry point
```

## Usage

1. Run the program
2. Choose operation type:
   - `r`: Read data
   - `w`: Write data
3. Select data type:
   - `i`: Integer
   - `c`: Character
4. Follow the prompts to read or modify data at specific indices

## Technical Details

**Memory Layout:**

- First 64 bytes: Integer array (16 integers × 4 bytes)
- Last 16 bytes: Character array

**Data is persisted in** `memory.bin`

**Initial values:**

- Integers: Initialized to `0`
- Characters: Initialized to `'A'`

## Functions

### Main Operations

- `startup_memory()`: Initializes the binary file with default values
- `read_binary()`: Debug function to display binary file contents
- `load_into_memory()`: Loads binary file into runtime memory

### User Interface

- `define_task()`: Gets user operation choice
- `define_datatype()`: Gets user data type choice

### Memory Management

- `divide_int_memory()`: Extracts integer array from memory
- `divide_char_memory()`: Extracts character array from memory
- `update_memory()`: Persists changes back to binary file

## Building

Compile using a C compiler:

```bash
gcc main.c data_manipulation/data_access.c runtime_memory/manage_runtime_memory.c user_interaction/user_interaction.c -o memory_manager
```
