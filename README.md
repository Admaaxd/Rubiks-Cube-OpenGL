# Rubik's Cube OpenGL🟥

![RubiksCube](https://github.com/user-attachments/assets/798a9e0b-f2d9-45ff-ad03-19e3db5ef2db)

## ✅ Features

- [ ] **Cube Manipulation**

- [ ] **Custom Background**  

- [x] **Additional Cube Variants**   
  - [x] 2x2 Rubik's Cube.
  - [x] 3x3 Rubik's Cube. 
  - [x] 4x4 Rubik's Cube.  
  - [x] 5x5 Rubik's Cube.  

- [x] **Graphical User Interface (GUI)**    
  - [ ] Cube size selection.
  - [x] Cube variant selection.
  - [ ] Background customization.  
  - [ ] Adjustable light intensity.
  - [ ] Customizable light colors. 

- [ ] **Custom Lighting**    
  - [ ] Dynamic shadows.
     

## How to build it using CMake

1. **Clone the repository**:
   ```bash
   git clone https://github.com/Admaaxd/Rubiks-Cube-OpenGL.git
   cd Rubiks-Cube-OpenGL

2. **Build the project**
   ```bash
   mkdir build
   cd build
   cmake -DCMAKE_BUILD_TYPE=Debug ..
   cmake --build .
   
3. **Run the program**
   ```bash
   cd Debug
   Rubiks_Cube.exe
