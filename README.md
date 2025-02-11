TGF-Propagation-Geant4-MT
=====
Geant4 model for Terrestrial Gamma-ray Flashes (TGF) propagation in Earth's atmosphere.
=====

* contact : <david (dot) sarria (at) uib (dot) no>

* Same as TGF-TEB-Propagation-Geant4, but optimized for TGF only : the electrons and positrons are not recorded and the magnetic field is disactivated

* Output file is different and described in `build/README_output.txt`

Compilation Instructions
-----
### Prerequisites
* A properly installed Geant4 environment is required. You can install it using the easy install scripts available at: https://github.com/davsar89/GEANT4-easy-install-scripts-Linux-Mac

### Compiling on Ubuntu (or WSL with Ubuntu)
1. Open a terminal in the build directory:
```bash
cd build
```

2. Generate build files with CMake and compile:
```bash
cmake ..
make
```

Running the Application
-----
After successful compilation, run the executable from the build directory:
```bash
./TGF_Propa
```

The executable will run with the default parameters as specified in `src/src/Settings.cc`. Check this file to view or modify the simulation parameters.
