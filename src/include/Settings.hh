//////////////////////////////////////////////////////////////////////////////////

//// /* GEANT4 code for propagation of gamma-rays, electron and positrons in
/// Earth's atmosphere */
////
//// //
//// // ********************************************************************
//// // * License and Disclaimer                                           *
//// // *                                                                  *
//// // * The  Geant4 software  is  copyright of the Copyright Holders  of *
//// // * the Geant4 Collaboration.  It is provided  under  the terms  and *
//// // * conditions of the Geant4 Software License,  included in the file *
//// // * LICENSE and available at  http://cern.ch/geant4/license .  These *
//// // * include a list of copyright holders.                             *
//// // *                                                                  *
//// // * Neither the authors of this software system, nor their employing *
//// // * institutes,nor the agencies providing financial support for this *
//// // * work  make  any representation or  warranty, express or implied, *
//// // * regarding  this  software system or assume any liability for its *
//// // * use.  Please see the license in the file  LICENSE  and URL above *
//// // * for the full disclaimer and the limitation of liability.         *
//// // *                                                                  *
//// // * This  code  implementation is the result of  the  scientific and *
//// // * technical work of the GEANT4 collaboration.                      *
//// // * By using,  copying,  modifying or  distributing the software (or *
//// // * any work based  on the software)  you  agree  to acknowledge its *
//// // * use  in  resulting  scientific  publications,  and indicate your *
//// // * acceptance of all terms of the Geant4 Software license.          *
//// // ********************************************************************
//////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "G4SystemOfUnits.hh"
#include "G4UnitsTable.hh"
#include <vector>

// there is a a copy of it on class that need it
// should not be used to share values around

// ....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
namespace Settings {

    extern double SOURCE_LAT;
    extern double SOURCE_LONG;
    extern double SOURCE_ALT;
    extern double record_altitude;

    extern double SOURCE_OPENING_ANGLE;
    extern G4String BEAMING_TYPE;

    extern double TILT_ANGLE;

    extern double SOURCE_SIGMA_TIME; // microsecond

    // force max step only for layers where particles are recorded
    extern G4bool USE_STEP_MAX_for_record;
    extern double STEP_MAX_RECORD_AREA;

    extern G4bool OUTPUT_TO_ASCII_FILE;

    extern double dr_over_R; // stepping parameter for ionization, default is 0.2, that may be too high
    extern double MIN_ENERGY_OUTPUT;

    // date
    extern int dt_year;
    extern double dt_month;
    extern double dt_day;
    extern double dt_hour;
    extern double dt_minute;
    extern double dt_second;
    extern double dt_microsecond;

    // Earth radius
    extern double earthRadius;
}
