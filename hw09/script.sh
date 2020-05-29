#!/bin/bash

echo Running main.cpp

g++ main.cpp && ./a.out > datos.txt
python grafica.py

echo Done!