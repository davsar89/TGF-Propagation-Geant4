TGF-Propagation-Geant4-MT
=====
Geant4 model for Terrestrial Gamma-ray Flashes (TGF) propagation in Earth's atmosphere.
=====

* contact : <david (dot) sarria (at) uib (dot) no>

* Same as TGF-TEB-Propagation-Geant4, but optimized for TGF only : the electrons and positrons are not recorded and the magnetic field is disactivated

* Output files are located in the folder `build/output_ascii`. The folder should be created automatically when `./TGF_Propa` is executed (if it is not the case somehow, create it manually). The output files are different from the TGF-TEB version and are described in `build/README_output.txt`

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

The executable can be run in two ways:

1. Without arguments: Uses default parameters from `src/src/Settings.cc`:
```bash
./TGF_Propa
```
Default values:
- SOURCE_ALT = 15.0 km
- SOURCE_LAT = 0.0°
- SOURCE_LONG = 0.0°
- SOURCE_SIGMA_TIME = 0.0 μs
- SOURCE_OPENING_ANGLE = 40.0°
- TILT_ANGLE = 0.0°
- BEAMING_TYPE = "Gaussian"
- record_altitude = 400.0 km

2. With command-line arguments:
```bash
./TGF_Propa number_events source_alt source_lat source_long source_sigma_time opening_angle tilt_angle beaming_type record_alt
```

Example:
```bash
./TGF_Propa 10000000 12.0 5.0 -60.0 0.0 35.0 0.0 Gaussian 500.0
```
This runs the simulation with:
- 10 million events
- Source altitude: 12.0 km
- Source latitude: 5.0°
- Source longitude: -60.0°
- Time spread (σ): 0.0 μs
- Opening angle: 35.0°
- Tilt angle: 0.0°
- Beaming type: Gaussian
- Recording altitude: 500.0 km
