# 실전코딩 2 실습 리포트

### `sshid` : pcc001
### `name` : 곽수정 ✨
### `id` : 201921085

***

## Lecture 1  

##### - 2022. 01. 04   [ C Development Platform ]  

* git을 사용하기 위한 프로그램 설치

* basic linux command

`ls`

> 현재 디렉토리에 어떤 파일이 있는지 list를 보여주는 명령어  

```
$ ls -l                   ; 파일의 상세 정보 표시
$ ls -a                   ; 숨어있는 파일들도 표시
$ ls -al pcc001           ; pcc001 디렉토리의 모든 파일 표시
```

`pwd`

> print working directory : 현재 디렉토리 보여줌  

`hostname`
> 내가 지금 어떤 컴퓨터를 쓰는지 알고싶다면 사용  

```
$ hostname  
Kwakui-MacBookPro.local
```

`who`
> 컴퓨터에 누가 들어왔는지 보고싶을 때 사용  
호스트에 로그인한 사용자의 정보를 출력

`wc`
> word count  
주어지는 파일 또는 표준 입력의 바이트, 문자, 단어 그리고 줄(라인) 수를 출력해주는 명령어

`who | wc`
> who의 output이 다음 명령 wc에 들어감 : 현재 접속자 수 보여줌  

`who | sort`
> who의 output 정렬해서 보여줌

`mkdir`
> 디렉토리 생성하는 명령어  

```
$ mkdir pcc         ; pcc 디렉토리 생성, 이미 디렉토리가 존재한다면 에러 발생
```  

`cd`
> change directory  
디렉토리를 이동하는 명령어

```
$ cd                ; cd 뒤에 디렉토리 입력 안하면 home directory로 이동
$ cd ~              ; home directory로 이동, 위 명령어와 동일
$ cd ..             ; 윗 디렉토리로 이동
$ cd lec01          ; lec01 디렉토리로 이동
```

`vi hello.c`
> vi 에디터로 파일 생성 후 편집  

* 3가지 mode: normal, insert, command mode  

    * normal 모드에서 i 를 눌러 insert mode로 전환 후 타이핑  

        * 한 글자 지우기: delete 키 / x 키, undo: u 키, 커서 뒤에 append: a 키  

    * insert mode에서 esc 눌러 빠져나오면 normal mode로 전환됨  

    * normal mode에서 command mode로 들어가려면 : 누름  

        * ex) **:wq** = wirte & quit  


`cc hello.c`
> hello.c 파일 컴파일 -> 기본적으로 a.out 실행파일 생성됨  

`mv`
> 파일을 이동시키는 명령어  

```
$ mv a.out hello.c pcc            ; a.out와 hello.c 파일을 pcc 디렉토리로 이동시킴  
$ mv hello.c hola.c               ; hello.c 파일의 이름을 hola.c 로 변경 가능
```

_cp는 원본 파일이 남아있지만 mv는 원본 파일이 남아있지 않아 파일 이름 변경시에도 사용 가능하다._  

`passwd`
> 비밀번호 변경 가능, 현재 비밀번호 입력한 뒤 새로운 비밀번호로 변경  

`chmod`
> 파일의 모드를 변경하는 명령어
  
| 파일 소유자 | 그룹 | 그 외 사용자 |
|:--------:|:----:|:--------:|
|read, write, execute| read, write, execute | read, write, execute|
|4 2 1| 4 2 1 | 4 2 1 |

|  변경 전  |  명령어  |  변경 후  |
|:-------:|:-------:|:-------:|
|drwxrwxrwx| chmod 700 pcc001 | drwx------|
| drwx------| chmod 777 forAll | drwxrwxrwx|  

* 예시) drwxrw----- pcc039 pcc forAll  
    * forAll이라는 디렉토리의 소유자는 pcc039이며 그룹은 pcc 이다.
    * 디렉토리의 소유자인 pcc039는 read, write, execute 권한을 가진다.
    * 그룹 pcc에 속한 사용자는 read와 write 권한을 갖는다.
    * 그 외 사용자는 아무 권한도 갖지 않는다.
    * _super user는 항상 모든 권한을 갖고 있다._

* 예시) d---rwx--- pcc039 pcc forAll
    * 디렉토리의 소유자인 pcc039는 아무 권한도 갖지 않는다.
    * 따라서 소유자 pcc039는 forAll 디렉토리에 들어가지 못한다!
    * **디렉토리에 들어가려면 실행 권한(x = execute)이 필요하다.**
    * 디렉토리 소유자와 others는 아무 권한이 없고, pcc group에 속한 사용하즌 read, write, execute 권한을 갖는다.

* 예시) d---rwxrwx pcc039 pcc forAll
    * forAll 디렉토리에 들어갈 수 있는 사람은 소유자 pcc039 빼고 모두이다.  
    즉, group에 속한 사용자, 그 외 사용자, 그리고 super user이다.
    * super user = root = 이 기계를 관리하는 사람

`groups`
> 내가 속한 그룹 보여줌

`whoami`
> 현재 로그인한 사용자의 id 출력
```
$ whoami
pcc001
```

`cat`
> 어떤 파일의 내용을 보는 명령어
```
$ cat hello.c
#include <stdio.h>

int main()
{
	printf("Hello World \n"); //Comment
}
```

`whoami >> output`
> whoami의 결과인 pcc001이 output 파일에 추가됨

`history`
> 내가 입력한 명령어 이력들 보기  

***

## Lecture 2
  
##### - 2022. 01. 05 [ Advanced C 언어 (1) 및 편집 도구 ]
  
***

## Lecture 3  

##### - 2022. 01. 06 [ Advanced C 언어 (2) 및 편집 도구 ]

### linux command

교수님의 코드를 카피함

```
cp ~hwan/.profile  ~hwan/.bashrc  ~hwan/.bash_logout ~
source .profile
```

이렇게 하니까 프롬프트가 초록색이 됨

***

## Lecture 4  

##### - 2022. 01. 10