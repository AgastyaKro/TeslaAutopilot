# TeslaAutopilot

A C++ autonomous vehicle controller built for the Webots simulator. Inspired by Tesla's Autopilot system, this project handles lane following, basic obstacle avoidance, and PID-based control logic for a simulated vehicle in an urban environment.

---

## Features

- Modular `Autopilot` controller architecture  
- Real-time camera frame processing via `CameraProcessor`  
- Lidar-based obstacle detection using `ObstacleAvoidance`  
- PID control for steering and velocity (`PID`)  
- Simulated city environment (`city.wbt`)  

---

## Directory Structure

```
TeslaAutopilot/
├── controllers/
│   └── autopilot/
│       ├── Autopilot.cpp
│       ├── Autopilot.hpp
│       ├── CameraProcessor.cpp
│       ├── CameraProcessor.hpp
│       ├── ObstacleAvoidance.cpp
│       ├── ObstacleAvoidance.hpp
│       ├── PID.cpp
│       ├── PID.hpp
│       ├── utils.hpp
│       ├── main.cpp
│       └── Makefile
├── worlds/
│   ├── city.wbt
│   └── .city.wbproj
```

---

## Build & Run

### 1. Clone the repository

```bash
git clone git@github.com:AgastyaKro/TeslaAutopilot.git
cd TeslaAutopilot
```

### 2. Build the controller

```bash
cd controllers/autopilot
make
```

### 3. Run the simulation

- Open Webots
- Load `worlds/city.wbt`
- Press the play button to begin the simulation

---

## Dependencies

- Webots (tested on R2023+)
- C++17 or newer
- GNU Make

---

## TODO

- [ ] Add lane detection logic to `CameraProcessor`
- [ ] Improve steering control using dynamic PID tuning
- [ ] Integrate velocity control based on Lidar feedback
- [ ] Add unit tests for all modules
- [ ] Add logging and visual debugging utilities

---

## License

This project is licensed under the MIT License.

---

## Author

**Agastya Krothapalli**  
GitHub: [@AgastyaKro](https://github.com/AgastyaKro)
