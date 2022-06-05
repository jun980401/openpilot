# comma 시리얼

comma 시리얼을 사용하면 장치에 전원을 공급하기 위해 안정적인 12V를 제공하는 동안 comma three의 저수준 직렬 콘솔에 액세스할 수 있습니다.

시리얼은 [comma 상점](https://comma.ai/shop/products/comma-serial)에서 구매할 수 있습니다.

## 설정

* 세 개의 케이블을 모두 직렬로 연결
* USB A를 컴퓨터에 연결
* USB-C를 comma three의 OBD-C 포트에 연결

## 사용법

```
sudo screen /dev/ttyUSB0 115200
```
또는 `connect.sh`를 사용하여 루프에서 이전 명령을 실행합니다.


사용자 이름과 비밀번호는 모두 'comma'입니다.
