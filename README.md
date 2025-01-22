# Address Book Management System

A command-line contact management system with CRUD operations and persistent storage.

## Features

- Contact management (create, read, update, delete)
- Search by name, phone, or email
- Multiple sorting options
- Data validation
- File persistence
- 100 contact capacity

## Project Structure

### Available Files
- `main.c` - Entry point and menu interface
- `contact.h` - Core data structures and function declarations
- `functions.h` - Utility function declarations
- `file.h` - File I/O function declarations

### Required Implementation Files (Not Included)
- `contact.c` - Implementation of core contact operations
- `functions.c` - Implementation of utility functions
- `file.c` - Implementation of file I/O operations

## Build Requirements

- C compiler (GCC recommended)
- Implementation files for: `contact.c`, `functions.c`, `file.c`

## Build Instructions

Once implementation files are created:

```bash
gcc main.c contact.c functions.c file.c -o address_book
```

## Function Modules

### Core (contact.h)
- Contact creation
- Search functionality
- Edit operations
- Delete operations
- List/display functions
- Address book initialization

### Utilities (functions.h)
- Data validation (name, phone, email)
- Search operations
- Sorting functions
- Duplicate checking

### File Operations (file.h)
- Save contacts
- Load contacts

## License

[Add your chosen license here]
