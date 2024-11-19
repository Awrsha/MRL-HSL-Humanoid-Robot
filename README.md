<div align="center">
  
  # MRL-HSL Humanoid Soccer Robot Projects
  
  [![Project Status: Active](https://img.shields.io/badge/Project%20Status-Active-green.svg)](https://github.com/mrl-hsl)
  [![License](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
  [![Python](https://img.shields.io/badge/Python-3.7%2B-blue)](https://www.python.org/)
  [![OpenCV](https://img.shields.io/badge/OpenCV-4.5%2B-red)](https://opencv.org/)
  
  <a href="https://github.com/mrl-hsl">
    <img src="https://github.com/Awrsha/MRL-HSL-Humanoid-Robot-Projects/assets/89135083/0dc6d650-0b2e-461c-a312-bb9a237e4378" alt="HSL" width="400">
  </a>

  ### 🤖 Humanoid Soccer Robot | Karen 🤖
</div>

---

## 🛠️ Technologies & Tools

<div align="center">

[![Python](https://img.shields.io/badge/Python-FFD43B?style=for-the-badge&logo=python&logoColor=blue)](https://www.python.org/)
[![OpenCV](https://img.shields.io/badge/OpenCV-27338e?style=for-the-badge&logo=OpenCV&logoColor=white)](https://opencv.org/)
[![PyTorch](https://img.shields.io/badge/PyTorch-EE4C2C?style=for-the-badge&logo=pytorch&logoColor=white)](https://pytorch.org/)
[![NumPy](https://img.shields.io/badge/Numpy-777BB4?style=for-the-badge&logo=numpy&logoColor=white)](https://numpy.org/)
[![Pandas](https://img.shields.io/badge/Pandas-2C2D72?style=for-the-badge&logo=pandas&logoColor=white)](https://pandas.pydata.org/)
[![Qt](https://img.shields.io/badge/Qt-41CD52?style=for-the-badge&logo=qt&logoColor=white)](https://www.qt.io/)
[![Jupyter](https://img.shields.io/badge/Jupyter-F37626.svg?&style=for-the-badge&logo=Jupyter&logoColor=white)](https://jupyter.org/)
[![VSCode](https://img.shields.io/badge/VSCode-0078D4?style=for-the-badge&logo=visual%20studio%20code&logoColor=white)](https://code.visualstudio.com/)
[![Anaconda](https://img.shields.io/badge/Anaconda-44A833?style=for-the-badge&logo=anaconda&logoColor=white)](https://www.anaconda.com/)

</div>

---

## 📖 Description

<div align="justify">

The MRL project, initiated in 2003 at the Mechatronics Research Laboratory (Islamic Azad University, Qazvin branch), stands at the forefront of robotics research and education. With a distinguished history in RoboCup competitions, our team has consistently pushed the boundaries of humanoid robotics.

### 🤖 About the Humanoid League

> Experience the pinnacle of robotics where autonomous humanoid robots compete in soccer matches using human-like perception and movement. Our robots navigate complex challenges including dynamic walking, running, ball manipulation, visual perception, self-localization, and team coordination - all without simplified sensor systems.

### 🏛️ About Mechatronic Research Laboratory (MRL)

> Since 2003, MRL has evolved from a single laboratory to a comprehensive research center comprising 11 specialized labs. Our facility stands as a national scientific research pole, distinguished by its cutting-edge equipment, expert researchers, and numerous international accolades.

</div>

---

## 📊 Project Architecture & Workflows

### State Machine Workflow
```mermaid
stateDiagram-v2
    [*] --> Initialize
    Initialize --> Ready
    Ready --> SearchBall
    SearchBall --> ApproachBall
    ApproachBall --> AlignToBall
    AlignToBall --> Kick
    Kick --> SearchBall
    
    SearchBall --> Ready: Ball Lost
    ApproachBall --> SearchBall: Ball Lost
    AlignToBall --> SearchBall: Ball Lost
    
    Ready --> [*]: Shutdown
```

### Data Flow
```mermaid
flowchart LR
    A[Camera Input] --> B[Image Processing]
    B --> C{Object Detection}
    C -->|Ball| D[Ball Tracking]
    C -->|Field| E[Localization]
    C -->|Players| F[Player Tracking]
    
    D --> G[World Model]
    E --> G
    F --> G
    
    G --> H[Decision Making]
    H --> I[Motion Planning]
    I --> J[Motor Control]
    J --> K[Robot Actions]
```

### Component Hierarchy
```mermaid
classDiagram
    class Robot {
        +VisionSystem vision
        +MotionSystem motion
        +DecisionMaking brain
        +initialize()
        +run()
    }
    
    class VisionSystem {
        +Camera camera
        +ImageProcessor processor
        +ObjectDetector detector
        +processFrame()
    }
    
    class MotionSystem {
        +WalkingEngine walker
        +KickEngine kicker
        +BalanceController balance
        +executeMotion()
    }
    
    class DecisionMaking {
        +WorldModel world
        +StrategyPlanner strategy
        +BehaviorTree behavior
        +makeDecision()
    }
    
    Robot *-- VisionSystem
    Robot *-- MotionSystem
    Robot *-- DecisionMaking
```

## 🌟 Key Features

- 🤖 Advanced Humanoid Robot Control
- 🧠 Deep Learning Integration
- 👀 Computer Vision Systems
- 🎮 Real-time Control Systems
- 🌐 Simulation Environments
- 📊 Data Analysis Tools

---

## 💻 Development Team

<div align="center">

| <img src="https://avatars.githubusercontent.com/u/20186211?v=4" width="80" alt="Saeid"/> | <img src="https://avatars.githubusercontent.com/u/46896724?v=4" width="80" alt="Arash"/> | <img src="https://avatars.githubusercontent.com/u/48767380?v=4" width="80" alt="Amir"/> |
|:---:|:---:|:---:|
| [Saeid Tafazzol](https://github.com/saeidtafazzol) | [Arash Rahmani](https://github.com/arashrahmani) | [Amir Gholami](https://github.com/AmiirGholamii) |

| <img src="https://avatars.githubusercontent.com/u/89135083?v=4" width="80" alt="Amir"/> | <img src="https://avatars.githubusercontent.com/u/104717705?v=4" width="80" alt="Mahdi"/> | <img src="https://avatars.githubusercontent.com/u/73719921?v=4" width="80" alt="Hamta"/> |
|:---:|:---:|:---:|
| [Amir M. Parvizi](https://github.com/Awrsha) | [Mahdi Zynali](https://github.com/mahdizynali) | [Hamta Niknazar](https://github.com/hamta-niknazar) |

[View all contributors →](./CONTRIBUTORS.md)

</div>

---

## 📫 Contact & Support

<div align="center">

[![Website](https://img.shields.io/badge/Website-Visit%20Us-blue?style=for-the-badge)](https://sites.google.com/view/mrl-hsl)
[![Email](https://img.shields.io/badge/Email-Contact%20Us-red?style=for-the-badge)](mailto:contact@mrl-hsl.com)
[![Star](https://img.shields.io/github/stars/mrl-hsl/karen?style=for-the-badge)](https://github.com/Awrsha/MRL-HSL-Humanoid-Robot)

</div>

---

<div align="center">
  
### 💙 Support the Project
If you find this project useful, please consider giving it a ⭐️

<img src="https://raw.githubusercontent.com/mayhemantt/mayhemantt/Update/svg/Bottom.svg" alt="Github Stats" />

</div>
