#include "common/physics.hh"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace Spectrum;


int main(int argc, char** argv)
{

   std::string infilename1 = "distro_xsh_fix_mom_500k_dt_1k.dat";
   std::string outfilename = "modulated_distro_xsh_fix_mom_500k_dt_1k.dat";
   
   std::string line;
   int i, N = 50;
   int sum_c1[N];
   double momentum1[N], distro1[N], sum_w1[N];
   double  v, p2, dp, t_sim, energy0 = SPC_CONST_CGSM_MEGA_ELECTRON_VOLT;

// Open input distro file
   std::ifstream input_spectrum_file1(infilename1);

// Read first two lines of distro file
   std::getline(input_spectrum_file1, line);
   std::getline(input_spectrum_file1, line);

// Read data
   for(i = 0; i < N; i++) {
      input_spectrum_file1 >> momentum1[i];
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

   for(i = 0; i < N; i++) {
         t_sim = 723.0; 
         p2 = Sqr(momentum1[i]/ 10.0 / momentum1[0]);
         dp = momentum1[i + 1] - momentum1 [i];
         v = Vel(momentum1[i]/ 10.0 / momentum1[0], Specie::proton); //////* unit_velocity_fluid;             
       
        output_spectrum_file << std::setw(20) << momentum1[i] / 10.0 / momentum1[0];
        output_spectrum_file << std::setw(20) <<   distro1[i] * sum_c1[i];
        output_spectrum_file << std::setw(20) <<   distro1[i] * sum_c1[i] * t_sim;
        output_spectrum_file << std::setw(20) <<   distro1[i] * sum_c1[i] / dp;
        output_spectrum_file << std::setw(20) <<   distro1[i] * sum_c1[i] * t_sim / dp;
        output_spectrum_file << std::endl;
 };

// Close output distro file
   output_spectrum_file.close();

   return 0;
};
