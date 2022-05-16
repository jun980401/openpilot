# 스톡 기능과의 통합

지원되는 모든 차량에서:
* LKA(스톡 차선 유지 보조) 및 스톡 ALC는 사용자가 openpilot을 사용할 때만 작동하는 openpilot ALC로 대체됩니다.
* 스톡 LDW는 openpilot LDW로 대체됩니다.

또한 특정 지원 차량의 경우 ([지원 차량](CARS.md)의 ACC 열을 참조하십시오.):
* 스톡 ACC는 openpilot ACC로 대체됩니다.
* openpilot FCW는 스톡 FCW에 추가로 작동합니다.

openpilot은 FCW, 자동 비상 제동(AEB), 자동 상향등, 사각 지대 경고 및 측면 충돌 경고를 포함하되 이에 국한되지 않는 다른 모든 차량의 기본 기능을 보존해야 합니다.
