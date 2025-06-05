
# Car Autopilot C++ Controller

This project implements a Tesla-style autonomous driving system in C++ using the Webots robotics simulator. It is a from-scratch, low-level controller that leverages real-time camera and lidar input to follow lane markings, avoid obstacles, and control a virtual vehicle's steering and throttle.

## Demo

[![Watch the demo](https://i.imgur.com/muqQhuK.jpeg)](https://youtu.be/hI3DEimlvjg)

The vehicle is able to:

* Follow lane markings using onboard camera input
* Steer proportionally based on curvature and alignment of detected lanes
* Move forward with basic speed control
* Avoid static obstacles using lidar input (optional feature toggle)

## Overview

The goal of this project is to simulate an end-to-end self-driving vehicle system using modern C++ and robotics APIs. It emphasizes clarity and control at the system level without relying on high-level frameworks. The codebase interfaces directly with the Webots simulation environment through its C++ API to access sensor data and actuate the vehicle.

The project is modularly structured to reflect a simplified version of an actual vehicle stack, including camera processing, control logic, and motion execution.


## Implementation

### Language & Platform

* **C++23**
* **Webots Simulator** (macOS-compatible, no external dependencies)
* **Modular architecture** designed for real-time robotics control

### Core Components

* **CameraProcessor**

  * Extracts grayscale image from onboard camera
  * Applies basic thresholding and filtering to detect yellow lane lines
  * Estimates lane center offset for steering decisions

* **AutopilotController**

  * Reads sensor input (camera, optionally lidar)
  * Calls PID steering and velocity controllers
  * Sends target speed and steering angle to the motors

* **Motor & Steering Interface**

  * Uses `webots::Motor` API to drive wheels and steer
  * Parameters such as max speed, turn ratio, and update timestep are tunable

* **Main Simulation Loop**

  * Synchronously steps the Webots simulation
  * Updates control loop based on camera frames every timestep
  * Modular for extension with more sensors (e.g., radar, GPS)


