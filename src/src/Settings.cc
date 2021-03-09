#include "Settings.hh"

namespace Settings {

    double SOURCE_LAT = 0.0;
    double SOURCE_LONG = 0.0;
    double SOURCE_ALT = 15.0;
    double record_altitude = 400.0;

    double SOURCE_OPENING_ANGLE = 40.0;
    G4String BEAMING_TYPE = "Gaussian";

    double TILT_ANGLE = 0.0;

    double SOURCE_SIGMA_TIME = 0.; // microsecond

    // force max step only for layers where particles are recorded
    G4bool USE_STEP_MAX_for_record = true;
    double STEP_MAX_RECORD_AREA = 100.0 * meter;

    G4bool OUTPUT_TO_ASCII_FILE = true;

    double dr_over_R = 0.4; // stepping parameter for ionization, default is 0.2, that may be too high
    double MIN_ENERGY_OUTPUT = 20.0 * keV;

    // date
    int dt_year = 2019;
    double dt_month = 3;
    double dt_day = 24;
    double dt_hour = 0;
    double dt_minute = 31;
    double dt_second = 53;
    double dt_microsecond = 135444;

    // Earth radius
    double earthRadius = 6378.137 * km;
}