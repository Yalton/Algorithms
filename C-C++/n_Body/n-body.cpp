#include <iostream>
#include <math.h>

using namespace std;

const double G = 6.674e-11; // gravitational constant

// Struct to represent a body in the system
struct Body
{
    double mass;
    double x, y, z;    // position
    double vx, vy, vz; // velocity
};

// Function to calculate the force between two bodies
double force(Body b1, Body b2)
{
    double dx = b1.x - b2.x;
    double dy = b1.y - b2.y;
    double dz = b1.z - b2.z;
    double r2 = dx * dx + dy * dy + dz * dz;
    double f = G * b1.mass * b2.mass / r2;
    return f;
}

// Function to update the position and velocity of a body
// based on the forces acting on it
void update(Body &b, double dt)
{
    // Update position
    b.x += b.vx * dt;
    b.y += b.vy * dt;
    b.z += b.vz * dt;

    // Update velocity
    b.vx += dt * force(b, b) / b.mass;
    b.vy += dt * force(b, b) / b.mass;
    b.vz += dt * force(b, b) / b.mass;
}

int main()
{
    // Set up the initial conditions of the system
    Body b1, b2; // two bodies
    b1.mass = 1.0;
    b2.mass = 2.0;
    b1.x = 0.0;
    b1.y = 0.0;
    b1.z = 0.0;
    b1.vx = 0.0;
    b1.vy = 0.0;
    b1.vz = 0.0;
    b2.x = 1.0;
    b2.y = 0.0;
    b2.z = 0.0;
    b2.vx = 0.0;
    b2.vy = 0.0;
    b2.vz = 0.0;

    // Simulation parameters
    double dt = 1.0;     // timestep
    double tmax = 100.0; // maximum time

    // Run the simulation
    for (double t = 0; t < tmax; t += dt)
    {
        update(b1, dt);
        update(b2, dt);
        cout << "t = " << t << "  b1 = " << b1.x << "  b2 = " << b2.x << endl;
    }
}