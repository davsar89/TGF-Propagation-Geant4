Outputs are written in the folder ./output_ascii/

Each output file contains a list of recorded particles with the following columns :	

    * settings->RANDOM_SEED : the random number seed
	* settings->SOURCE_ALT : altitude of record (km)
	* settings->SOURCE_OPENING_ANGLE (deg, half cone for uniform beaming or sigma for Gaussian beaming)
	* settings->NB_EVENT : number of TGF photons sampled when this record is made, only a small fraction of them leads to a detection
	* time of record (us), with respect to TGF photon sampling time
	* energy of record (keV)
	* latitude of record (deg)
	* longitude of record (deg)
	* altitude of record (km), should always be equal to the same value (e.g. 400)
	* mometum direction on the X direction (ECEF coordinates)
	* mometum direction on the Y direction (ECEF coordinates)
	* mometum direction on the Z direction (ECEF coordinates)
