#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Advection Equation
// du/dt + c du/dx = 0
//

#define NX 100 // Number of grid elements
#define L 1.0  // Domain Length
#define C 1.0  // Advection Velocity
double u[NX];  // Array of interest

#define integration 3 // Integration Time

void initialize() {
  for (int i = 0; i < NX; ++i) {
    double x = (double)i / (NX - 1) * L; // get position
    if (x >= 0.3 && x <= 0.6) {
      u[i] = 1.0;
    } else {
      u[i] = 0.0;
    }
  }
}

void integrateEuler(double dt) {
  for (int i = 1; i < NX - 1; ++i) {
    double du_dx = (u[i] - u[i - 1]) / (L / (NX - 1));
    u[i] = u[i] - dt * C * du_dx;
  }
}

int main() {
  double dx = L / (NX - 1);
  double dt = 1;
  double t = 0.0;

  initialize();

  while (t < integration) {
    integrateEuler(dt);   
    t += dt;
  }
}

