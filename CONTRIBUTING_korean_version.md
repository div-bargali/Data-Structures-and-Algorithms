# 기여

해당 프로젝트에 기여하기 위해선, 다음과 같습니다.

- 버그를 보고하기
- 코드의 현재 상태에 대해서 논의하기
- 수정 사항 제출하기
- 새로운 기능들 제안하기
- 관리자 되기


## 기여를 위한 과정

* 당신이 작업하려는 이슈에 대해 언급합니다. 다른 사람들에게 작업하려는 이슈가 할당되지 않았는지 확인하도록 합니다.

* 만약 알고리즘이 부족하다고 생각되면, 이슈를 만드십시오.

### Pull Request 만들기

> - PR을 만들고자 하는 이슈에 대해 할당되었는지 확인하십시오.
> - 만약 할당되기 전에 PR을 만들경우, `invalid(유효하지 않음)`으로 표시되며 병합되지 않고 닫힙니다.

* 저장소를 포크하고 당신의 컴퓨터에 복사하십시오.
* 복사된 저장소의 메인 branch에 upstream link를 더하십시오.
    ```
    git remote add upstream https://github.com/div-bargali/Data-Structures-and-Algorithms.git 
    ```
* Upstream에서 가져와 Clone 저장소를 최신 상태로 유지합니다. (해당 작업은 새로운 변경 사항을 커밋하는 동안 병합 충돌을 방지할 수도 있습니다).
    ```
    git pull upstream main https://github.com/div-bargali/Data-Structures-and-Algorithms.git 
    ```
* 당신의 feature branch를 만드십시오.
    ```
    git checkout -b <feature-name>
    ```
* 모든 변경 사항에 대해 커밋하십시오.
    ```
    git commit -m "Meaningful commit message"
    ```
* 검토를 위해 변경사항을 push하십시오.
    ```
    git push origin <branch-name>
    ```

* GitHub의 해당 프로젝트의 저장소에 PR을 만드십시오.

### 추가 참고 사항

* 코드는 가독성을 위해 올바르게 작성되어야 합니다.
* 만약 테스트 해야 하는 코드를 추가할 경우 주석으로 tests를 추가해줍니다.
* Python의 경우, 테스트를 제공하기 위해 docstrings을 사용합니다.
* 당신의 코드가 올바르게 형식화되어 있는지 확인하십시오.
* 올바른 디렉터리 구조를 유지하고 있는지 확인하십시오:
    ```
    <Language>/<Algorithms>/<Algorithm Paradigm>/<. . .>
    ```
    ```
    <Language>/<Data Structures>/<Data Structure name>/<. . .>
    ```
* 해당 Pull request를 이슈화하십시오!

## 문제 제기/버그 신고하기

이슈를 만들때, 이미 제시된 것이 아님을 확인하십시오. 더 나아가 변경사항에 대해 올바른 설명을 제공하십시오.
만약 어떤 코드의 개선 사항에 대해서 제시하는 경우, 해당 개선 사항에 대한 세부 정보를 제시(제공)하십시오.

**중대한 이슈 제의**는 아래 사항을 가지고 있어야 합니다:

- 변경 사항에 대한 빠른 요약
- 재처리의 과정에서 생길수도 있는 버그에 대해서
    - 구체적이게!
    - 가능하면 샘플 코드 제공하기.
    - 예상했던 일 (문제점)
    - 실제로 발생한 일 (문제점)
    - 메모 (아마 당신이 이것이 일어날 것이라고 생각한 것을 포함하거나, 시도했으나 작동하지 않는 것)

## 참고

해당 문서는 [페이스북의 Draft(초안)](https://github.com/facebook/draft-js/blob/a9316a723f9e918afde44dea68b5f9f39b7d9b00/CONTRIBUTING.md) 의 오픈 소스 기여 가이드라인에서부터 적용되었습니다.