# AvionicsGen2 _ Arduino
## GIT 사용법
### 0) 알면 도움되는 명령어

```bash
"로컬 저장소": 내 컴퓨터 파일

"원격 저장소": 깃허브에 만든 원격 저장소
pwd // 내가 현재 위치하고있는 폴더의 주소
ls // 현재 폴더에 존재하는 것들을 보여줌

cd foldername //foldername의 폴더로 이동
cd .. // "..": "상위 폴더" 로 이동
code . // "." : "현재 위치"에서 vscode 실행
```

### 1) 시작해볼까?

```bash
 git init // 이건 로컬 파일을 원격 저장소로 올리고 싶을 때 
```

```bash
git clone [url] // 이건 깃허브에 있는 원격 저장소 파일을 로컬 저장소에서 작업할 때
```

### 2) Code 수정 및 추가

### 3) Staging 영역에 추가

```bash
git add . //모든 업데이트된 파일
```

```bash
git add -A
```

```bash
git status // add내역 확인
```

```bash
git restore . (stage 된 파일 모두 unstage)
```

### 4) repository에 commit

```bash
git commit -m "blabla" //커밋이다.
```

### 5) 원격 저장소 push

```bash
git remote add origin URL //origin은 그냥 remote 이름
```

```bash
git branch -m main //main브랜치로 옮김.
```

```bash
git push origin main //orgin이라는 remote에 main 브랜치로 push
```

---

### 기타) branch 생성 및 변경

```bash
git branch newbranchName // 기존 branch의 새로운 branch 생성
git checkout mybranch // 기존 브랜치에서 새로운 브랜치로 전환

git merge mybranch // 현재 branch에서 mybranch로 merge(병합) 함

git branch -m 기존branch이름 바꿀branch이름
```
