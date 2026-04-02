# digital-alarm-clock
# [엠하이브 디지털 알람 시계](https://www.youtube.com/playlist?list=PLUaCOzp6U-Rp6p3XVk9BFsjWsa7bZQDUH)




## [1-1. 버튼 입력으로 LED 토글 1](https://www.youtube.com/watch?v=kQcF4ELYz64)
<img width="661" height="464" alt="image" src="https://github.com/user-attachments/assets/0a22fd6d-9fbe-4dc2-ae51-f179d2e2d6d9" />
<img width="1326" height="747" alt="image" src="https://github.com/user-attachments/assets/d785d6ad-68a8-475d-ad45-052858cd9685" />


```mermaid
classDiagram
direction LR

class Input {
}

class Output {
}

class DigitalAlarmClock {
}

DigitalAlarmClock *-- "3" Input
DigitalAlarmClock *-- "6" Output
```

## [1-2. 버튼 입력 및 UART 입력으로 LED 토글](https://youtu.be/Bg9hrV3UmNI?si=QyxuOjNht088D7Jv)

<img width="1329" height="747" alt="image" src="https://github.com/user-attachments/assets/b25ca1fc-1603-4f76-9de9-f911c2bc408d" />

```mermaid
classDiagram
direction LR

class Input {
}

class Output {
}

class DigitalAlarmClock {
}

DigitalAlarmClock *-- "3" Input
DigitalAlarmClock *-- "6" Output
DigitalAlarmClock o-- "3" Output
```

## [1-3. 버튼 누른 시간 카운트](https://youtu.be/ARtBX-rpjCA?si=GdJaIIyo2OaC4g94)

```mermaid
classDiagram
direction LR

class Input {
}

class Output {
}

class Segment {
}

class Data {
}

class DigitalAlarmClock {
}

DigitalAlarmClock *-- Input
DigitalAlarmClock *-- "2" Output
DigitalAlarmClock o-- Segment
DigitalAlarmClock o-- Data
Segment o-- Data



```

```mermaid
classDiagram
    direction BT

    class DigitalAlarmClock {
        +DigitalAlarmClock_init()
        +DigitalAlarmClock_operate()
    }

    class Input {
        -port: GPIO_TypeDef*
        -pin: uint16_t
        -type: InputType
        -lastState: bool
        -state: bool
        +Input_isOn() bool
        +Input_isRising() bool
        +Input_isFalling() bool
        +Input_update()
    }

    class Output {
        -port: GPIO_TypeDef*
        -pin: uint16_t
        -type: OutputType
        +Output_turnOn()
        +Output_turnOff()
        +Output_toggle()
    }

    %% 합성 관계 및 역할명(Role Name) 표기
    DigitalAlarmClock "1" *-- "1" Input : button1
    DigitalAlarmClock "1" *-- "1" Input : button2
    DigitalAlarmClock "1" *-- "1" Input : button3

    DigitalAlarmClock "1" *-- "1" Output : leftRed
    DigitalAlarmClock "1" *-- "1" Output : leftGreen
    DigitalAlarmClock "1" *-- "1" Output : leftBlue

    DigitalAlarmClock "1" *-- "1" Output : rightRed
    DigitalAlarmClock "1" *-- "1" Output : rightGreen
    DigitalAlarmClock "1" *-- "1" Output : rightBlue
```
