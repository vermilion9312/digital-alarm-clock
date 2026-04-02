# digital-alarm-clock
# [엠하이브 디지털 알람 시계](https://www.youtube.com/playlist?list=PLUaCOzp6U-Rp6p3XVk9BFsjWsa7bZQDUH)




## [1-1. 버튼 입력으로 LED 토글 1](https://www.youtube.com/watch?v=kQcF4ELYz64)
<img width="661" height="464" alt="image" src="https://github.com/user-attachments/assets/0a22fd6d-9fbe-4dc2-ae51-f179d2e2d6d9" />

```mermaid
classDiagram
direction LR

class Input {
}

class Output {
}

class DigitalAlarmClock {
    - Input button1
    - Input button2
    - Input button3

    - Output leftRed
    - Output leftGreen
    - Output leftBlue

    - Output rightRed
    - Output rightGreen
    - Output rightBlue
}

DigitalAlarmClock *--> "3" Input
DigitalAlarmClock *--> "6" Output
```

## [1-2. 버튼 입력 및 UART 입력으로 LED 토글]([https://www.youtube.com/watch?v=kQcF4ELYz64](https://youtu.be/Bg9hrV3UmNI?si=QyxuOjNht088D7Jv))

```mermaid
classDiagram
direction LR

class Input {
}

class Output {
}

class DigitalAlarmClock {
    - Input button1
    - Input button2
    - Input button3

    - Output leftRed
    - Output leftGreen
    - Output leftBlue

    - Output rightRed
    - Output rightGreen
    - Output rightBlue

    - Output* red
    - Output* green
    - Output* blue
}

DigitalAlarmClock *--> "3" Input
DigitalAlarmClock *--> "6" Output
DigitalAlarmClock o--> "3" Output
```
