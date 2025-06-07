```markdown

## 🔐 File-EncryptDecrypt - Linux-based File Encryption & Decryption in C++

## 📌 Overview

**File-EncryptDecrypt** is a modular C++ project for secure file encryption and decryption, built to run on Linux systems. It leverages core **Operating System concepts** and is developed using **Windows Subsystem for Linux (WSL)** for portability on Windows.

The project is designed with clean separation of concerns across file handling, process management, and encryption logic.

---

## 🧠 Core Operating System Concepts Used

### 🧅 Process Management
- Execution and management of encryption/decryption flows through modular processes.
- Simulated task distribution logic in `ProcessManagement.cpp`.

### 🧵 Multiprocessing & Multithreading
- The program is capable of encrypting and decrypting **multiple files concurrently**.
- This parallelism is implemented using **multiple processes** and can be extended to support **multithreading** for performance scaling.
- Ensures efficient CPU utilization and concurrent file handling.

### 📂 File System Interface
- Reading and writing files securely via system calls in `IO.cpp`, including recursive environment-based path reads (`ReadEnv.cpp`).
- Usage of environment variables (`.env` file) for file path configuration.

### 🧠 Memory Management
- Efficient buffer management for file content encryption/decryption.

### 🚱 Access Control & Security
- File operations respect Linux file permissions.
- `.env` configuration ensures secure and portable path management.

### 🗞 System Calls
- Direct use of low-level Linux syscalls for file and process operations.

---

## 🗂 Project Structure

```

.
├── .vscode/                     # VSCode settings
├── src/
│   └── app/
│       ├── encryptDecrypt/      # Encryption and Decryption logic
│       │   ├── Cryption.cpp
│       │   ├── Cryption.hpp
│       │   └── CryptionMain.cpp
│       ├── fileHandling/        # File I/O and environment
│       │   ├── IO.cpp / IO.hpp
│       │   ├── ReadEnv.cpp / .o
│       └── processes/           # Process management abstraction
│           ├── ProcessManagement.cpp / .o
│           └── Task.hpp
├── test/                        # Sample test files
│   ├── test1.txt
│   ├── test2.txt
│   └── test3.txt
├── .env                         # Environment variable config
├── .gitignore                   # Git ignore config
├── main.cpp                     # Project entry point
├── Makefile                     # Compilation instructions
├── File-EncryptDecrypt (binary) # Output binary
└── README.md                    # Project documentation

````

---

## 🧪 Usage

### ✅ Build the project

```bash
make
````

This uses the `Makefile` to compile all `.cpp` files into an executable named `File-EncryptDecrypt`.

### ▶️ Run the program

```bash
./File-EncryptDecrypt
```

The program will execute according to the logic defined in `main.cpp` and call appropriate modules for file reading and encryption/decryption.

---

## ⚙ Configuration

The `.env` file defines key variables used for locating files or controlling behavior. Example:

```env
INPUT_PATH=./test/test1.txt
OUTPUT_PATH=./test/encrypted.txt
```

Use `ReadEnv.cpp` to safely load and use these environment variables.

---

## 🧼 Clean Build Files

```bash
make clean
```
Removes all `.o` object files and the binary.

---

## 🧠 How to Extend

* Add new encryption schemes inside `encryptDecrypt/Cryption.cpp`.
* Implement compression modules using similar process-based design inside `processes/`.
* Enhance parallelism with multithreading using `<thread>` or OpenMP.

```
## Source
@Lovepreet Singh

