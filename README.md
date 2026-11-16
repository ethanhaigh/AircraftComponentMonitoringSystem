# Aircraft Component Monitoring System

## Overview

A C++ command-line application for managing and monitoring aircraft components. Users can add, remove, update and view components, as well as check their condition.

The system supports three component types:
- Engine
- Landing Gear
- Wing

## Features

- Add and delete components.
- Update component information and status.
- Monitor component measurements and generate warnings.
- Validate user input and prevent duplicate IDs.
- Save and load component data using a CSV file.
- Display maintenance and safety alerts.

## Design

The project uses object-oriented programming, including inheritance, encapsulation, abstraction and polymorphism.

It also uses the Factory pattern to create components and the Observer pattern to handle alerts and maintenance notifications.

## Running the Application

Compile and run the C++ project using a compatible C++ compiler. The application will display a command-line menu with instructions for each available option.

Component data is stored in `src/main/resources/components.csv`.
