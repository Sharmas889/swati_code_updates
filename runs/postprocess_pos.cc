#include "common/physics.hh"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace Spectrum;

int main(int argc, char** argv)
{
  std::string infilename1 = "results/14oct/distro_xsh_fix_pos_500k_dt_1k.dat";
  std::string outfilename = "results/14oct/modulated_distro_xsh_fix_pos_500k_dt_1k.dat";

   std::string line;
   int i, N = 500;
   int sum_c1[N];
   double position1[N], distro1[N], sum_w1[N];
   double v, p2, dp, t_sim, energy0 = SPC_CONST_CGSM_MEGA_ELECTRON_VOLT;
  
// Open input distro file
   std::ifstream input_spectrum_file1(infilename1);

// Read first two lines of distro file
   std::getline(input_spectrum_file1, line);
   std::getline(input_spectrum_file1, line);

// Read data
   for(i = 0; i < N; i++) {
      input_spectrum_file1 >> position1[i];
      input_spectrum_file1 >> distro1[i];
      input_spectrum_file1 >> sum_w1[i];
      input_spectrum_file1 >> sum_c1[i];
   };

// Close input cartesian distro file
   input_spectrum_file1.close();

// Open output distro file
   std::ofstream output_spectrum_file(outfilename);

// Output data
   output_spectrum_file << std::setprecision(8);

   for (i = 0; i < N; i++) {
     t_sim = 723.0;
     output_spectrum_file << std::setw(20) << position1[i];
     output_spectrum_file << std::setw(20) <<  distro1[i];
     output_spectrum_file << std::setw(20) <<  distro1[i] * sum_c1[i];
     output_spectrum_file << std::setw(20) <<  sum_c1[i];
     output_spectrum_file << std::setw(20) <<  sum_c1[i] * t_sim;      
     output_spectrum_file << std::endl;
    };

   output_spectrum_file.close();

   return 0;
};
