#include <ClosedForm.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::acos;
using std::sin;
using std::exp;
using std::ofstream;
using std::setprecision;
using arma::vec;
using arma::zeros;


void closedForm(vec x, vec t, int Nx, int Nt, int N) {
    ofstream closedFormFile;
    closedFormFile.open("closedForm_data.dat", std::ios::out);

    double pi = acos(-1.0);

    for (int k = 0; k < Nt; k++) {
        vec u = vec(Nx);
        for (int i = 0; i < Nx; i++) {
            u(i) = 0;
            for (int n = 1; n < N; n++) {
                double npi = n * pi;
                u(i) = u(i) + (2.0 / npi) * sin(npi*x(i)) * exp(-npi*npi*t(k));
            }
        }
        for (int i = 0; i < Nx; i++) {
            closedFormFile << setprecision(16) << u(i) << " ";
        }
        closedFormFile << "\n";

        // Print the progress to terminal.
        printf("Closed form progress: %10.2f %%\r", 100 * k / ((double) Nt));
    }
    closedFormFile.close();
}
