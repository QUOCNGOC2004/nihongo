# 日本語学習アプリ (Nihongo Learning App)

A sample C++ project demonstrating multi-file structure with CMake build system.

## 📁 Project Structure

```
nihongo/
├── CMakeLists.txt          # CMake configuration
├── build.bat               # Build & Run script (like Code::Blocks)
├── include/                # Header files
│   ├── student.hpp         # Student class declaration
│   └── utils.h             # Utility functions declaration
├── src/                    # Source files
│   ├── main.cpp            # Main application
│   ├── student.cpp         # Student class implementation
│   └── utils.cpp           # Utility functions implementation
└── build/                  # Build output (generated)
```

## 🚀 How to Build & Run

### Method 1: Using build.bat (Full Build - First Time or New Files)
**When to use:**
- First time building
- After adding/removing .cpp or .hpp files
- After modifying CMakeLists.txt

Just double-click `build.bat` or run:
```cmd
build.bat
```

### Method 2: Using rebuild.bat (Quick Rebuild - Code Changes Only) ⚡
**When to use:**
- Only modified existing .cpp or .hpp files
- No new files added
- Faster than build.bat!

Just double-click `rebuild.bat` or run:
```cmd
rebuild.bat
```

### Method 3: Using Antigravity workflow
```cmd
/build-run
```

### Method 4: Manual CMake commands
```cmd
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
cmake --build .
nihongo_app.exe
```

> 💡 **Tip**: Use `rebuild.bat` for daily coding - it's 2-3x faster!

## 🛠️ Requirements

- **CMake** 3.10 or higher ✓
- **G++** (MinGW/MSYS2) ✓
- **Windows** with UTF-8 support

## 📚 What This Project Demonstrates

- ✅ Multiple source files (.cpp)
- ✅ Header files (.hpp and .h)
- ✅ Class-based OOP design
- ✅ Namespace usage
- ✅ CMake build system
- ✅ **Automatic file detection** (no need to edit CMakeLists.txt when adding files!)
- ✅ One-click build & run (like Code::Blocks)
- ✅ Fast rebuild for code changes

## 🎯 Features

- Student management system
- Japanese language learning theme
- Time-based greetings
- UTF-8 Japanese character support
- Clean separation of interface and implementation

## ➕ Adding New Files

**Good news!** You don't need to manually edit `CMakeLists.txt` anymore!

### To add a new class:
1. Create `include/yourclass.hpp`
2. Create `src/yourclass.cpp`
3. Run `build.bat` (first time)
4. Edit code and use `rebuild.bat` (subsequent times)

**That's it!** CMake automatically finds all `.cpp` files in `src/` directory.

### Rules:
- All `.cpp` files must be in `src/` folder
- All `.hpp/.h` files must be in `include/` folder

---

**Enjoy learning C++ and 日本語! 頑張って！(Ganbatte!)**
