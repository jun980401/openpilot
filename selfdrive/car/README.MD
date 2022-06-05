## Port 구조
##### interface.py
CAN에서 메시지를 주고 받기 위한 일반 인터페이스(controlsd는 이를 사용하여 자동차와 통신함)
##### carcontroller.py
자동차로 보낼 CAN 메시지 빌드
##### carstate.py
자동차에서 CAN을 읽고 openpilot CarState 메시지를 빌드합니다.
##### values.py
지문 및 절대적 한계
##### radar_interface.py
레이더 인터페이스
