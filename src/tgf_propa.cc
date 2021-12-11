////////////////////////////////////////////////////////////////////////////////

// /* GEANT4 code for propagation of x/gamma-rays in
// Earth's atmosphere */
//
// //
// // ********************************************************************
// // * License and Disclaimer                                           *
// // *                                                                  *
// // * The  Geant4 software  is  copyright of the Copyright Holders  of *
// // * the Geant4 Collaboration.  It is provided  under  the terms  and *
// // * conditions of the Geant4 Software License,  included in the file *
// // * LICENSE and available at  http://cern.ch/geant4/license .  These *
// // * include a list of copyright holders.                             *
// // *                                                                  *
// // * Neither the authors of this software system, nor their employing *
// // * institutes,nor the agencies providing financial support for this *
// // * work  make  any representation or  warranty, express or implied, *
// // * regarding  this  software system or assume any liability for its *
// // * use.  Please see the license in the file  LICENSE  and URL above *
// // * for the full disclaimer and the limitation of liability.         *
// // *                                                                  *
// // * This  code  implementation is the result of  the  scientific and *
// // * technical work of the GEANT4 collaboration.                      *
// // * By using,  copying,  modifying or  distributing the software (or *
// // * any work based  on the software)  you  agree  to acknowledge its *
// // * use  in  resulting  scientific  publications,  and indicate your *
// // * acceptance of all terms of the Geant4 Software license.          *
// // ********************************************************************
////////////////////////////////////////////////////////////////////////////////

#include "G4UImanager.hh"
#include <DetectorConstruction.hh>
#include <PhysicsList.hh>

#define G4VIS_USE 1
#define G4UI_USE 1

#ifdef G4VIS_USE

#include "G4VisExecutive.hh"

#endif // ifdef G4VIS_USE

#ifdef G4UI_USE

#include "G4UIExecutive.hh"

#endif // ifdef G4UI_USE

#include <RunAction.hh>

#include <EventAction.hh>
#include <SteppingAction.hh>

#include <chrono>

#include <G4Threading.hh>

#ifdef G4MULTITHREADED

#include <thread>
#include "G4MTRunManager.hh"

#else
#include "G4RunManager.hh"
#endif

#include "ActionInitialization.hh"

#include <CoordTopocentric.h>
#include <CoordGeodetic.h>
#include <Observer.h>
#include <SGP4.h>
#include "Settings.hh"
#include <string>
#include "myUtils.hh"

using namespace std;

/////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
    double wall0 = myUtils::get_wall_time();

    G4String number_st;
    G4String Mode = "run";

    if (argc > 3)
    {
        number_st = argv[1];
        Settings::SOURCE_ALT = std::stod(argv[2]);
        Settings::SOURCE_LAT = std::stod(argv[3]);
        Settings::SOURCE_LONG = std::stod(argv[4]);
        Settings::SOURCE_SIGMA_TIME = std::stod(argv[5]);
        Settings::SOURCE_OPENING_ANGLE = std::stod(argv[6]);
        Settings::TILT_ANGLE = std::stod(argv[7]);
        Settings::BEAMING_TYPE = argv[8];
        Settings::record_altitude = std::stod(argv[9]); // can remove this as it is defined later
    }
    else
    {
        // default values can be seen/changed in src/include/Settings.cc
        Mode = "run";
        number_st = "10000000";
    }

    //// choose the Random engine and give seed
    G4Random::setTheEngine(new CLHEP::MixMaxRng);

    // random seeds, different each time code is run
    long start = myUtils::generate_a_unique_ID();
    long seeds[2];
    seeds[0] = start;
    seeds[1] = myUtils::generate_a_unique_ID();

    G4cout << "seed set to: " << start << " ns" << G4endl;

    G4Random::setTheSeeds(seeds,2);

    auto *runManager = new G4RunManager;

    runManager->SetUserInitialization(new TGFDetectorConstruction());

    TGF_PhysicsList *physicsList = new TGF_PhysicsList();
    runManager->SetUserInitialization(physicsList);

    runManager->SetUserInitialization(new ActionInitialization());

    // Initialize G4 kernel
    runManager->Initialize();
    G4cout << G4endl << "Initialization OK" << G4endl;

    // get the pointer to the User Interface manager
    G4UImanager *UImanager = G4UImanager::GetUIpointer();

    if (Mode == "visu")
    {
#ifdef G4VIS_USE
        G4VisManager *visManager = new G4VisExecutive;
        visManager->Initialize();
#endif // ifdef G4VIS_USE
#ifdef G4UI_USE
        G4UIExecutive *ui = new G4UIExecutive(argc, argv);
#ifdef G4VIS_USE
        UImanager->ApplyCommand("/control/execute vis.mac");
#endif // ifdef G4VIS_USE
        ui->SessionStart();
        delete ui;
#endif // ifdef G4UI_USE
#ifdef G4VIS_USE
        delete visManager;
#endif // ifdef G4VIS_USE
    }
    else if (Mode == "run")
    {
        UImanager->ApplyCommand("/run/beamOn " + number_st);
    }

    //
    delete runManager;
    //
    double wall1 = myUtils::get_wall_time();
    G4cout << G4endl << "WALL TIME TAKEN : " << wall1 - wall0 << " seconds "
           << G4endl;
    //
    return 0;
} // main
