from pathlib import Path

# YouTube video ID
video_id = "hI3DEimlvjg"

# Updated README content with YouTube thumbnail preview
readme_with_youtube = f"""

# TeslaAutopilot-Cpp

TeslaAutopilot-Cpp is a modular C++ controller for autonomous vehicle navigation in the Webots simulation environment. It emulates fundamental behaviors of a Tesla-style Autopilot system, including visual lane detection, obstacle avoidance, and real-time steering correction using a PID controller.

## Demo

[![Watch the demo](https://img.youtube.com/vi/{video_id}/0.jpg)](https://youtu.be/{video_id})

> Click the image above to watch a demo of the system in action.

## What This Controller Does

This project implements a custom autonomous driving stack from scratch using only Webots native APIs and a C++17 toolchain. The system is designed to operate on roads with painted yellow lanes and dynamic obstacles, making real-time control decisions to steer and drive the car safely through the environment.

### Core Functionalities

- **Lane Detection via Camera**: 
  Uses raw pixel analysis from Webots’ front camera to detect the average horizontal offset and approximate heading angle of yellow lane lines.

- **Steering Control via PID**:
  Computes a correction angle using a tuned PID controller based on combined lane offset and angle, adjusting both front steering actuators for smooth control.

- **Obstacle Detection via Lidar**:
  Monitors a forward-facing sector using lidar to determine obstacle presence, distance, and angle. When objects are detected, avoidance logic alters the steering trajectory accordingly.

- **Speed Management**:
  The controller drives at a base cruising speed and slows or halts the vehicle when imminent collisions are predicted based on lidar proximity.

- **Visual Dashboard**:
  Displays current speed and GPS information on the Webots vehicle dashboard using the in-simulation display API.




