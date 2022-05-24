# 기여 방법

당사 소프트웨어는 오픈 소스이므로 다른 사람의 도움 없이 여러분이 문제를 해결할 수 있습니다. 그리고 문제를 해결한 후 본인이 원한다면 그것을 공개하여 전 세계가 사용할 수 있도록 할 수 있습니다. [외부화에 대한 게시물](https://blog.comma.ai/a-2020-theme-externalization/)을 확인하세요.

대부분의 오픈 소스 개발 활동은 [GitHub 토론](https://github.com/commaai/openpilot/discussions) 및 [Discord](https://discord.comma.ai)를 통해 조정됩니다. https://docs.comma.ai 및 [블로그](https://blog.comma.ai/)에 있는 많은 문서를 사용하실 수 있습니다.

### 시작하기

 * [개발 환경](../tools/) 설정
 * [디스코드](https://discord.comma.ai) 참여
 * [GitHub 계정](https://github.com/signup/free) 생성
 * GitHub에서 [리포지토리](https://github.com/commaai) 포크

### 첫 번째 기여
아래의 pull requests 아이디어를 시도해보고 코드베이스에 대해 알아보세요.

* [mypy](http://mypy-lang.org/) 적용 범위 확대
* 문서 작성
* 미해결 [good first issue](https://github.com/commaai/openpilot/issues?q=is%3Aissue+is%3Aopen+label%3A%22good+first+issue%22) 해결

## 풀 리퀘스트

풀 리퀘스트는 마스터 브랜치에 대한 것이어야 합니다. 버그 리포트, 자동차 포트 및 [미해결 문제](https://github.com/commaai/openpilot/issues)에 대한 기여는 언제나 환영합니다. 기여에 대해 확신이 서지 않으면 자유롭게 토론, 이슈를 열거나 PR 초안을 작성하여 해결하려는 문제에 대해 논의하십시오.

좋은 풀 리퀘스트에는 아래 요소가 모두 포함됩니다.
* 분명한 목적
* 직접 변경된 모든 라인은 명시된 목적에 기여합니다.
* 검증, 즉 PR을 어떻게 테스트했습니까?
* 정당화
   * 최적화한 것이 있다면 벤치마크를 게시하여 더 낫다는 것을 증명하세요.
   * 자동차 튜닝을 개선했다면 플롯 전후를 게시하십시오.
* CI 테스트 통과

### 자동차 포트

Toyota/Lexus 모델로의 이식을 위한 [모델 포트 가이드](https://blog.comma.ai/openpilot-port-guide-for-toyota-models/)를 출시했습니다.

openpilot을 새로운 자동차 브랜드로 이식할 경우, 보다 일반적인 [브랜드 포트 가이드](https://blog.comma.ai/how-to-write-a-car-port-for-openpilot/)를 참조하세요.

## 테스트

### 자동화 테스트

모든 PR 및 커밋은 GitHub Actions에서 자동으로 확인됩니다. GitHub Actions가 실행하는 내용은 `.github/workflows/`를 확인하세요. 모든 새 테스트는 GitHub 작업에 추가되어야 합니다.

### 코드 스타일 및 라이닝

코드는 자동화된 테스트의 일부로 GitHub Actions에 의해 스타일이 자동으로 확인됩니다. `pre-commit run --all`을 실행하여 이러한 테스트를 직접 실행할 수도 있습니다.
