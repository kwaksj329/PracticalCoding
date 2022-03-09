## Practical Coding Report

### `sshid` : pcc001
### `name` : 곽수정 ✨
### `id` : 201921085

***

## Contents  

1. [ Lecture 1 ](#lecture-1)
2. [ Lecture 2 ](#lecture-2)
3. [ Lecture 3 ](#lecture-3)
4. [ Lecture 4 ](#lecture-4)
5. [ Lecture 5 ](#lecture-5)
6. [ Lecture 6 ](#lecture-6)
7. [ Lecture 7 ](#lecture-7)
8. [ Lecture 8 ](#lecture-8)
9. [ Lecture 9 ](#lecture-9)
10. [ Lecture 10 ](#lecture-10)
11. [ Lecture 11 ](#lecture-11)
12. [ Lecture 12 ](#lecture-12)
13. [ Lecture 13 ](#lecture-13)
14. [ Lecture 14 ](#lecture-14)

***

## Lecture 1  

##### - 2022. 01. 04   

* git을 사용하기 위한 프로그램 설치

* Basic Linux Command

### `ls`

현재 디렉토리에 어떤 파일이 있는지 list를 보여주는 명령어  

```bash
$ ls -l                   # 파일의 상세 정보 표시
$ ls -a                   # 숨어있는 파일들도 표시
$ ls -al pcc001           # pcc001 디렉토리의 모든 파일 표시
```

### `pwd`  

print working directory : 현재 디렉토리 보여줌  

### `hostname`  
내가 지금 어떤 컴퓨터를 쓰는지 알고싶다면 사용  

```bash
$ hostname  
Kwakui-MacBookPro.local
```

### `who`  
컴퓨터에 누가 들어왔는지 보고싶을 때 사용  
호스트에 로그인한 사용자의 정보를 출력

### `wc`  
word count  
주어지는 파일 또는 표준 입력의 바이트, 문자, 단어 그리고 줄(라인) 수를 출력해주는 명령어

### `who | wc`  
who의 output이 다음 명령 wc에 들어감 : 현재 접속자 수 보여줌  

### `who | sort`  
who의 output 정렬해서 보여줌

### `mkdir`  
디렉토리 생성하는 명령어  

```bash
$ mkdir pcc         # pcc 디렉토리 생성, 이미 디렉토리가 존재한다면 에러 발생
```  

### `cd`  
change directory  
디렉토리를 이동하는 명령어

```bash
$ cd                # cd 뒤에 디렉토리 입력 안하면 home directory로 이동
$ cd ~              # home directory로 이동, 위 명령어와 동일
$ cd ..             # 윗 디렉토리로 이동
$ cd lec01          # lec01 디렉토리로 이동
```

### `vi hello.c`  
vi 에디터로 파일 생성 후 편집  

 * 3가지 mode: normal, insert, command mode  

    * normal 모드에서 i 를 눌러 insert mode로 전환 후 타이핑  

        * 한 글자 지우기: delete 키 / x 키, undo: u 키, 커서 뒤에 append: a 키  

    * insert mode에서 esc 눌러 빠져나오면 normal mode로 전환됨  

    * normal mode에서 command mode로 들어가려면 : 누름  

        * ex) **:wq** = write & quit  



### `cc hello.c`  
hello.c 파일 컴파일 -> 기본적으로 a.out 실행파일 생성됨  

### `mv`  
파일을 이동시키는 명령어  

```bash
$ mv a.out hello.c pcc            # a.out와 hello.c 파일을 pcc 디렉토리로 이동시킴  
$ mv hello.c hola.c               # hello.c 파일의 이름을 hola.c 로 변경 가능
```

_cp는 원본 파일이 남아있지만 mv는 원본 파일이 남아있지 않아 파일 이름 변경시에도 사용 가능하다._  

### `passwd`  
비밀번호 변경 가능, 현재 비밀번호 입력한 뒤 새로운 비밀번호로 변경  

### `chmod`  
파일의 모드를 변경하는 명령어
  
| 파일 소유자 | 그룹 | 그 외 사용자 |
|:--------:|:----:|:--------:|
|read, write, execute| read, write, execute | read, write, execute|
|4 2 1| 4 2 1 | 4 2 1 |

|  변경 전  |  명령어  |  변경 후  |
|:-------:|:-------:|:-------:|
|drwxrwxrwx| chmod 700 pcc001 | drwx------|
| drwx------| chmod 777 forAll | drwxrwxrwx|  

* 예시) `drwxrw----- pcc039 pcc forAll`  
    * forAll이라는 디렉토리의 소유자는 pcc039이며 그룹은 pcc 이다.
    * 디렉토리의 소유자인 pcc039는 read, write, execute 권한을 가진다.
    * 그룹 pcc에 속한 사용자는 read와 write 권한을 갖는다.
    * 그 외 사용자는 아무 권한도 갖지 않는다.
    * _super user는 항상 모든 권한을 갖고 있다._

* 예시) `d---rwx--- pcc039 pcc forAll`
    * 디렉토리의 소유자인 pcc039는 아무 권한도 갖지 않는다.
    * 따라서 소유자 pcc039는 forAll 디렉토리에 들어가지 못한다!
    * **디렉토리에 들어가려면 실행 권한(x = execute)이 필요하다.**
    * 디렉토리 소유자와 others는 아무 권한이 없고, pcc group에 속한 사용하즌 read, write, execute 권한을 갖는다.

* 예시) `d---rwxrwx pcc039 pcc forAll`
    * forAll 디렉토리에 들어갈 수 있는 사람은 소유자 pcc039 빼고 모두이다.  
    즉, group에 속한 사용자, 그 외 사용자, 그리고 super user이다.
    * super user = root = 이 기계를 관리하는 사람

### `groups`  
내가 속한 그룹 보여줌

### `whoami`  
현재 로그인한 사용자의 id 출력

```bash
$ whoami
pcc001
```

### `cat`  
어떤 파일의 내용을 보는 명령어

```c
$ cat hello.c
#include <stdio.h>

int main()
{
	printf("Hello World \n"); //Comment
}
```

### `whoami >> output`  
whoami의 결과인 pcc001이 output 파일에 추가됨

### `history`  
내가 입력한 명령어 이력들 보기  

***

## Lecture 2
  
##### - 2022. 01. 05 
  

### `Computer Hardware System`  

<div style="text-align : center;">
    <img src=./img/hardware_sys.png width="70%"/>  
</div>

_lec01 실습: output device에 Hello World를 출력하도록 명령함  
실행 파일명: a.out_  

* CPU: central processing unit  
* Memory: RAM, ROM  
* Input Devices: 키보드, 마우스, 마이크  
* Output Devices: 모니터, 프린터, 스피커  
* Storage Devices: hhd, ssd, 파일이 들어있는 곳

**Q**) Storage에 들어있는 a.out 파일을 CPU가 바로 실행할 수 있다? [ **X** ]
> CPU는 storage device에 들어있는 파일을 직접 실행할 수 있는 경우가 없다!

**Q**) CPU는 output device에 데이터를 내보낼 수 있다? [ **X** ]
> 직접 output device에 데이터를 내보낼 수 없다! 따라서 메모리에 두어야함.  

* Storage에 저장되어 있는 a.out 프로그램을 실행하려면 메모리에 두어야하고, 그럼 CPU가 메모리에서 하나씩 가져다가 실행함  

* 메모리 중에서 초록색으로 표시된 부분은? **buffer**
> input device가 쓰는 버퍼: input buffer  
> output device가 쓰는 버퍼: output buffer  

### `Computer system 구성요소`  
 
<div style="text-align : center;">
    <img src=./img/computer_sys.png width="70%"/>  
</div>

* User, data, hardware, software 로 구성되어 있다.

### `Software`  
* Application software  
* System software: os, compiler, device driver  
    * system software, os: 사용자가 하드웨어를 쓰기 쉽게 해주는 기능 제공
    * os ( 운영체제 ): 하드웨어 바로 위에 존재  

<div style="text-align : center;">
    <img src=./img/software.png width="70%"/>  
</div>

* bash: git-scm 설치 후 프롬프트 나오고 대화형으로 이 유틸리티를 사용할 수 있도록 만들어주는 것

* HW에 Hello world! 가 출력 되려면?  
    * hello.c를 컴파일해서 a.out 이라는 app 을 만든다. -> bash에서 a.out을 실행시킨다.  
    * HW에 출력하기 위해 shell에서 실행되어 system call 중 printf를 사용하여 커널에게 요청하고, 커널이 hw에게 출력하기를 요청하여 모니터에 Hello World! 가 출력된다.  

### `Linux kernel`

<div style="text-align : center;">
    <img src=./img/linux_kernel.png width="75%"/>  
</div>

* Linux Kernel에서도 위 **Computer hardware system** 그림에서 볼 수 있는 5가지 구성 요소를 모두 가지고 있다.  
즉 OS는 Input & Output device, Memory, CPU, Storage devices와 같은 hw를 사용자가 사용하기 쉽게 만들어준다.

* Linux kernel & Computer hardware system
    * I/O subsystem - _Input & Output device_
    * Memory management subsystem - _Memory_
    * Process management subsystem - _CPU_
    * File systems - _Storage devices_  

* 위로 갈 수록 sw, 아래로 갈 수록 hw와 가깝다. 예를 들어 Network 장치를 이용한 통신을 위한 sw는 socket이다.  

* Processor != Process != Thread  

<div style="text-align : center;">
    <img src=./img/terminal.png />  
</div>

* Terminal을 이해하기 위해서는 옛날 컴퓨터 사용방법 생각해보기  
    * 하나의 컴퓨터에 통신선을 통해 터미널과 연결하여 사용했었음  
    * 옛날에 사용하던 터미널에도 CPU, memory, I/O device 등 존재했지만 실제로 계산하는 중심적인 서비스를 제공하는 것은 async mainframe host였기 때문에 상대적으로 터미널(단말)이라고 불렀다.  

* 사용자가 hw를 사용하기 편리하도록 기본적으로 설치되는 시스템 소프트웨어: 운영체제  

* 터미널 앞에는 컴퓨터의 4대 구성요소 중 하나인 user가 있고, HW 관점으로 봤을 때 사용자와 직접적으로 맞닥뜨리는 종점( 단말 )이 **Terminal**이다.  

* Terminal = character device = Input 장치이면서 output 장치이다.  

### `Lec02 실습`

* 리눅스에서는 모든 컴퓨터 자원, resource를 파일로 관리한다.  

* git bash를 여는 순간 터미널이 열린다. 터미널의 타입을 xterm-256color로 설정하면 색이 설정되어 나온다.

* $ = prompt = 예전에는 컴퓨터 사용하는 시간만큼 돈을 냈었다.  

* 명령어를 기다리고 있다가 명령어를 수행하는 프로그램 이름은? **shell**

### `ssh`  
리눅스 서버에 원격 접속할 때 사용하는 명령어

```bash
$ ssh pcc001@git.ajou.ac.kr
```

### `ps`  
내가 실행하는 process 보고 싶을 때 사용하는 명령어  

```bash
$ ps
    PID    TTY      TIME        CMD
    5655   pts/8    00:00:00    bash
    9159   pts/8    00:00:00    ps
```
_bash를 실행하는 중 & ps 명령어도 실행되고 있었으므로 표시됨_  
* `PID` = process id = 리눅스 내부에서는 process들이 번호로 관리됨  
* `TTY` = terminal  

### `tty`  
리눅스 device 중 콘솔/터미널을 의미함  

```bash
$ tty
/dev/pts/8
```  

* 리눅스 운영체제는 컴퓨터의 모든 자원을 파일로 관리하며, 그 파일은 disk이다.  
Disk는 디렉토리를 찾아서 갈 수 있다.  

### `cd /dev`  

/dev = device 파일을 위한 디렉토리이다.  
장치 드라이버, 터미널, 프린터 등 주변 장치들을 나타내는 파일들이 존재한다.  

* d - directory
* c - character device
* b - block device
* l - simbolic link  

_permission 앞에 붙은 문자는 파일의 종류를 나타낸다._

### `cd /dev/pts`  

내 device pts가 존재하는 디렉토리  

```bash
crw--w----  1  hwan  tty  136,  8  1월  5  14:19  8
```  

**Q**) 위 /dev/pts에 존재하는 8번 파일에 대해 설명하세요.  
> 8이라고 하는 파일은 character device 입니다.  
8 device를 소유한 hwan은 read, write 할 수 있습니다.  
8 파일을 소유한 tty 그룹은 write 할 수 있는 권한이 있으며 이 외의 사용자는 아무 권한도 없습니다.  

* 위 8번 device에 대해 권한 변경 가능 -> ex) chmod 777 8
> echo pcc001 > 8 으로 입력 가능  

### `wall`  
write all = 모두에게 메세지 보낼 수 있음, ctrl + d 로 메세지 입력 종료  

### `write pcc001`  
wall과 같이 메세지를 보낼 수 있는 명령어, write pcc001은 pcc001에게 메세지를 보내게 된다.  

### `mesg n`  
message no = write permission turned off  

### `biff`  
이메일이 오면 벨을 울리게 하는 명령어, 개발한 사람의 옆집 개 이름  

> 리눅스 명령어에서 어떤 규칙을 찾는 것은 불가능하다.  
명령어의 word 선택은 규칙이 없다.

### `man`  
각종 명령어와 프로그램 사용법, 메뉴얼을 보여준다.

```bash
$ man cat       # cat 명령어의 메뉴얼을 보여준다.
```  

```bash
$ man cp        # cp 명령어의 메뉴얼을 보여준다.
```  

<div style="text-align : center;">
    <img src=./img/man_cp.png width="75%"/>  
</div>  

* `cp [OPTION]` -> [OPTION]은 생략할 수 있다.  
* `cp [OPTION] ...` -> ...은 여러 옵션이 붙을 수 있음을 의미한다.  
* `cp [OPTION] ... SOURCE ... DIRECTORY` -> SOURCE ...은 SOURCE가 여러개 붙을 수 있다는 뜻이다.  

**tab을 습관적으로 사용하기! -> 파일명 입력할 때 실수를 줄여주는 방법**  

### `반드시 알아야 할 단축키`  
* ctrl + d: exit, EOF (End Of File)  
* ctrl + c: kill signal  
* ctrl + z: suspend signal  

**Q**) ssh로 팔달관에 있는 git.ajou.ac.kr 컴퓨터로 들어갈 수 있다. git.ajou.ac.kr이 우리에게 device를 하나씩 줬는데 무슨 device일까?  
> Terminal  

**Q**) 나에게 준 터미널이 무엇인지 물어보고 싶다면?  
> tty 명령어 입력 -> /dev/pts/11  
/dev/pts/11 터미널을 주고 passward를 물어봐서 일치하면 첫번째로 실행되는 process는 bash임을 알 수 있다.  
(ps 명령어로 실행중인 process 알 수 있다.)  

### `ls -l 과 ps -l`  
* ls -l: 파일이 자세히 보임
* ps -l: process가 상세히 보임
* 명령어 자체에는 규칙성이 없지만 명령어의 옵션이나 syntex의 규칙은 서로 매우 비슷하다!  

```bash
$ ps -l
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  4001 18126 18125  2  80   0 -  6054 wait   pts/2    00:00:00 bash
0 R  4001 18143 18126  0  80   0 -  7551 -      pts/2    00:00:00 ps
```  

* UID: user id  
* PID: process id  
* PPID: parent process id
* ps process의 부모가 bash임을 알 수 있다.  
    * ps의 PPID: 18126 == bash의 PID: 18126  

**ls -al 명령어가 hidden 파일 보여주는 것처럼 ps -al 명령어도 hidden process 보여준다.**  

<div style="text-align : center;">
    <img src=./img/hello_world.png width="75%"/>  
</div>  

**Q**) a.out를 실행하면 왜 모니터에 Hello World! 가 출력될까?  
> 지금 내가 사용하고 있는 shell 입장에서 shell의 가장 기본이 되는 input 장치와 output 장치 = **표준입출력장치**  
stdio.h 를 include 했기 때문에 표준입출력장치에 Hello World! 가 출력된다.  

### `stdio.h`  

**Q**) stdio.h 파일은 어디에 있을까?  
> /usr/bin/include 에 stdio.h가 존재한다!  
```c
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
```

* **리눅스는 모든 device가 파일이다!**  

* I/O stream은 buffer로 이해하면 좋다.  

* vi editor 명령:  
    * if에 해당하는 endif 찾고 싶다면 **%** 누르기  
    * 괄호의 짝을 찾을 때도 **%** 누르기
    * line number 보고 싶다면 **:set number**
    * 검색하고 싶을 때는 **/검색어** 로 찾기

* /vmlinuz: 커널 파일, boot/vmlinuz-4.15.0-163-generic에 링크되어있다.  

* /var: variable length, log 파일 등 가변 데이터 파일들이 저장된다.  

### `lec02의 hello.c`  

```c
#include <stdio.h>

int main()
{
    FILE *fout;
    fout = fopen("output.txt", "w");
    fprintf(fout, "Hello World\n");
}
```

**Q**) 위 코드를 통해 Hello World가 output.txt 파일에 써질까? [ **X** ]  
> buffer를 닫지 않았기 때문에 output.txt에 써지지 않는다.  

### `hello.c 수정한 버전`  

```c
#include <stdio.h>

int main()
{
    FILE *fout;
    fout = fopen("output.txt", "w");
    fprintf(fout, "Hello World\n");
    fclose(fout);
}
```

_이제 Hello World가 output.txt에 저장된다!_  

* CPU가 Hello World라고 쓰면 storage device에 써지지 않음! buffer에 쓰여진다.  

* buffer에 있는 것이 storage device에 저장되는 때는..? 3가지 mode 존재
    1. memory 크기는 유한대이므로 buffer가 꽉 차면 그 때 storage device에 저장한다.
    2. 한글자 buffer에 올때마다 storage device에 저장한다. (buffer size: 1byte)
        * 대신 성능이 나쁘다. -> 일반적으로 memory보다 storage가 속도가 느리기 때문에
    3. buffer control하는 명령이 왔을 때 storage device에 저장한다.  

### `sleep`  
뒤 입력 초만큼 sleep 하는 명령어, kill하고 싶다면 **ctrl + c** 누르기  

```bash
$ sleep 600             # 600초, 10분 동안 sleep
```  

### `cat`  
파일(들)을 순서대로 읽고 그 내용을 읽은 순서대로 표준 출력에 쓰는 명령  

```bash
$ cat  
aaa                     # 입력
aaa                     # 출력
bbb                     # 입력
bbb                     # 출력
```
작업 끝내고 싶다면 **ctrl + d** 누르기  

### `vi 에디터로 편집 중에 ctrl + z 누른 경우`  
process를 잠시 suspend 시킴 (보류)  

```bash
$ vi hello.c            # 편집 중에 ctrl + z 누른 뒤...
[1]+    Stopped         vi hello.c  

$ps
  PID  TTY          TIME CMD
20145  pts/11    0:00:00 bash
23919  pts/11    0:00:00 vi
27662  pts/11    0:00:00 ps

$ jobs
[1]+    Stopped         vi hello.c 
```  

### `Stopped 시킨 job으로 돌아가기`  
**fg** = background 작업을 foreground로 옮기기
```bash
$ fg %1             # 1번 작업인 vi 에디터로 다시 돌아감  
```

### `(sleep 1000 ; echo "pcc001 - 1000sec") &`  
* 프로그램 실행 시에 끝에 &를 붙여 백그라운드로 실행시킬 수 있다.  
* jobs 명령을 통해 현재 백그라운드에서 동작하고 있는 프로그램의 확인이 가능하다.  
* 백그라운드 프로그램을 죽이고 싶다면 **kill -9 %번호**

```bash
$ sleep 1000 ; echo "pcc001 - 1000sec" &            # 앞 작업이 끝나야 뒤 작업 실행되므로 제대로 작동하지 않음
$ (sleep 1000 ; echo "pcc001 - 1000sec") &          # 묶어주면 background 작업으로 작동함
```

### `cat a.out`  
* a.out는 우리가 읽을 수  있는 텍스트 파일이 아니고 binary 파일이다.  
따라서 cat a.out 실행시 읽을 수 없는 내용이 보여진다.  
* hello.c는 C source, ASCII text 파일이므로 cat hello.c 명령어 실행시 파일 내용을 보여준다.  

### `cat`  
* concatenate files and print on the standard output  
* 파일을 합쳐서 statndard output으로 보여주는 명령어  
* ctrl + d 누르면 cat 프로그램 종료, (EOF)

```bash
$ cat
aaa                 # 파일이 없다면 statndard input을 입력으로 받아서
aaa                 # standard output에 출력한다.  
```
* 터미널 사용할 때 기본 입력장치: 키보드, 기본 출력장치: 모니터  
* 버퍼 종류 중에 대표적인 것: 한줄씩 보내줌.
    * stdin으로 aaa 엔터 입력 -> CPU가 처리 -> stdout으로 한줄 내보냄.

### `redirection`  
* `< file` : stdin 대신에 이 파일을 쓰세요
* `0< file` : < file 과 동일
* `> file` : stdout 디바이스(/dev/pts/8)로 나갈 것을 file에 써주세요.  
* `1> file`: > file과 동일  
* `2> file`: stderr를 이 file로 내보내주세요.  

### `date`  
현재의 시간과 날짜를 stdout에 출력해주는 명령어  

```bash
$ date > date.txt           # stdout이 date.txt 파일로 리디렉션됨.  
$ cat date.txt
2022. 01. 05 (수) 16:02:23 KST  

$ cat date.txt hello.c output.txt > total.txt            
# 파일 3개가 total.txt로 concatenate됨.
$ cat hello.c hello.c hello.c > hello3                   
# hello.c 3개가 hello3에 합쳐짐  

$ cat < hello3                                             
# input으로 hello.c를 받아서 stdout에 출력함.
$ cat hello3                                               
# cat < hello3와 동일  

$ cat < hello3 > hello4
$ diff hello3 hello4        # 두 파일은 동일한 파일이다.  

$ cat hello.c hello.cpp 1>out.txt 2>err.txt 
# hello.c 내용을 받아 stdout이 out.txt에 저장됨. hello.cpp 파일이 없어 발생한 에러 메세지는 err.txt에 저장된다.  
```  

### `stdin, stdout, stderr redirection`  
in.txt 파일에는 학번(201921085)이 저장되어있고 아래 코드는 hello.c 파일이다.

```c
#include <stdio.h>

int main()
{
    int in_a;
    fscanf(stdin, "%d", &in_a);
    fprintf(stdout, "Hello stdout %d\n", in_a);
    fprintf(stderr, "Hello stderr %d\n", in_a);
}
```

```bash
./a.out < in.txt > out.txt 2>err.txt
```

위 명령어 실행시 out.txt에는 Hello stdout 201921085가, err.txt에는 Hello stderr 201921085가 저장된다.  
`>>` 는 계속 내용이 누적되도록 할 수 있다.  

***

## Lecture 3  

##### - 2022. 01. 06  

### `linux command`

교수님의 코드를 카피하였더니 프롬프트가 초록색으로 변경되었다. (색 지정 O)  

```bash
cp ~hwan/.profile  ~hwan/.bashrc  ~hwan/.bash_logout ~
source .profile
```  

### `which`  
* 특정 명령어의 위치를 찾아주는 명령어  
* which 명령어를 사용하면 현재 사용하고 있는 명령어 실행파일의 위치를 알 수 있다.

### `grep`  
텍스트 파일에서 원하는 문자열이 들어간 행을 찾아 출력하는 명령어  

### `ls`  
ls 명령어가 처음에 위치해 있는 곳은?? **storage**, storage에 들어있는 것은 파일이다.  

```bash
$ which ls
/bin/ls
```  

### `PATH`  

```bash
$ vi ls             # ls에는 ls -lida 저장함
$ chmod +x ls
$ ./ls              # 직접 작성한 ./ls 실행됨
$ ls                # /bin/ls의 ls가 실행됨
```  

* 시스템 안에 존재하는 ls 중 무엇을 실행시킬지 순서를 정해야함: 환경변수 **PATH**  

```bash
$ echo $PATH
/home/course/pcc039/bin:/home/course/pcc039/.local/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:.
```  

* source .profile을 통해 마지막줄 PATH="$HOME/bin:$HOME/.local/bin:$PATH:."이 실행되어 path가 추가되었다.

* 따라서 lec02에 있는 a.out를 ./a.out으로 실행했어야 했는데 path를 추가한 뒤에는 a.out으로 실행시킬 수 있다.  

```bash
$ which a.out
./a.out                         # 현재 디렉토리 밑에 있는 a.out이 실행된다.
```  

_그래도 .을 빼는 것이 보안상 안전하다..!_  

### `Markdown`  

* `#`: 제목
* `##`: 부제목
* `###`: 부부부제목  
* 문단을 나누고 싶을 때는 빈 줄을 한줄 더 만들기  
* `*` 또는 `1. `: 목록 또는 숫자 붙은 목록이 만들어진다.
    * 계속 1. 로 적어도 자동으로 1, 2, 3 순서대로 숫자 붙여준다.

* git.ajou.ac.kr 에서 마크다운 language를 사용하여 README.md 수정한 뒤 commit message를 쓰고 commit 하였다.  

> 마크다운 공부하려면 Markdown 클릭! [Markdown](https://www.youtube.com/playlist?list=PLKseYrrlvWNpYJxtfoUj5FLuMHv7Wrmid)  

### `주의할 점`  

* 코드로 쓰는 쌍 따옴표, 단 따옴표와 MS word가 바꾸는 코드는 다르다..!
* MS word에서는 ASCII 코드가 아니라 유니코드임  

<div style="text-align : center;">
    <img src=./img/echo.png width="50%" >  
</div>  

### `gitignore`  

* git.ajou.ac.kr에서 내 폴더로 들어간 뒤 new file을 추가함  
* template type을 .gitignore로 선택한 뒤, binary 파일을 git 서버에 백업하지 않도록 아래와 같이 작성하고 commit 하였다.

```bash
*.out
```  

### `clone`  
* clone with https를 눌러 링크를 복사한 뒤 ssh 서버의 pcc 디렉토리에 git clone https://git.ajou.ac.kr/kwaksj329/pcc001.git 으로 clone 하였다.  

* pcc001 디렉토리 안에는 .git과 .gitignore 와 같은 hidden file과 README.md가 있다.  

* . 으로 시작하는 파일은 hidden 파일이다.  

```bash
$ file * .*             # 모든 파일과 hidden 파일
README.md:  UTF-8 Unicode text  
.:          directory
..:         directory
.git        directory
.gitignore:  ASCII text
```

.gitignore는 한글이 하나도 포함되어 있지 않기 때문에 ASCII text이다.  

### `clear`  
터미널 내용을 지우고 싶을 때 사용하는 명령어  

### `unicode`  
unicode는 1바이트, 2바이트, 4바이트, 8바이트로 이루어져 있다.  
한글을 쓰려면 unicode, UTF-8 을 써야한다.  

### `git 프로젝트를 전체 프로젝트로 만들기`  

1. lec01 & lec02 를 pcc001로 옮기기  
2. pcc001에 있는 모든 파일을 pcc 디렉토리 밑으로 옮기기  
    * 아래 코드는 2번 방법에 해당함

```bash
$ mv pcc001/* .                 # pcc 디렉토리에 hidden 파일은 안옮
$ mv .git .gitignore ..         # pcc 디렉토리로 옮김
```  

### `ssh & https`  

* git-scm 설치
* git-bash 실행시 가상의 터미널이 열림 -> 터미널이 열리자마자 bash가 실행됨
* ssh 프로그램 실행시켜 git.ajou.ac.kr 접속함 => 터미널로 들어온 것은 `ssh` 서비스라고 함  
* 웹브라우저로 git.ajou.ac.kr로 접속함 => `https` 서비스로 접속함

### `pipe`  
어떤 출력을 다음에 오는 명령어의 입력으로 넣는 명령어  

```bash
$ ps -ael | grep ssh            # ps -ael의 출력 중 ssh를 찾는 명령어
$ who | wc                      # who 결과의 라인수, 단어수, 글자수 세어줌

$ wc
aaa bbbb cccc
1   3   15                      # 1글자, 3단어, 15글자 (글자 + 줄바꿈까지)

$ grep aaa                      # 파일 없이 standard input을 받아 해당 string이 나타나면 표시해줌  
$ grep printf hello.c | wc      # hello.c 파일의 printf 찾아 라인수, 단어수, 글자수 세어줌
```  

**Q**) 파이프는 어디에 있을까?  
> buffer, output buffer를 input buffer에 symbolic link 시켜둠  
파이프는 메모리에 버퍼 형태로 존재하며 파이프도 디바이스기 때문에 /dev/에 디파이스 파일로 만들 수 있다.  

* 파이프를 자료구조로 생각하면 queue이다. (FIFO)
* 따라서 파이프 만드는 명령어 `mkfifo mypipe`  
* 파이프는 파일의 속성이 **p**이다!  

```bash
$ mkfifo mypipe
```

### `tee`  
stdin을 받아서 stdout과 하나 이상의 파일에 그 입력을 출력하는 명령어

<div style="text-align : center;">
    <img src=./img/tee.png width="70%" >  
</div>  

```bash
$ echo testing | tee test.txt
test
$ cat test.txt
test

$ ls -l | tee aaa           # ls -l의 결과가 stdout에도 출력되고 aaa에도 저장된다. 
```  

### `git 서버에 올리는 방법`  

```bash
$ git pull                  # 혹시 서버에서 update 한게 있다면 가져와 merge 함
$ git add *
$ git commit -m "Added something"
$ git push
```  

* git commit만 치면 nano editor가 실행된다.  
* vi ~/.gitconfig 파일에 아래 코드를 추가하면 nano 에디터가 아닌 vi 에디터가 실행된다.  
    * git commit 실행 후 파일에 commit message 적어서 저장해주면 commit message가 설정된다.  

```bash
[editor]
    editor = vi
[color]
    ui = auto
```

* 내 PC 에서 git bash 실행하여 Desktop/new_folder로 이동한 다음 git clone 해옴  
* 내 PC 에서도 파일을 수정하고 git add, git commit, git push 가능!  

***

## Lecture 4  

##### - 2022. 01. 10  

### `pipe`  

* standard I/O는 기본적으로 메모리에 들어있다.  
* 그 메모리에 구성되어있는 디바이스는 /dev/stdin, /dev/stderr, /dev/stdout, /dev/fd 에 있다.  
* 추가로 사용자가 3, 4, 5 ... 도 만들어서 stdin이나 stdout으로 내보낼 수 있다.  

<div style="text-align : center;">
    <img src=./img/stdio.png width="70%" >  
</div>  

### `redirection`  

* `<` == `0<`  : 파일로부터 표준 입력을 받도록 redirection
* `>` == `1>`  : stdout의 출력을 파일의 출력으로 redirection
* `>>` == `1>>`  :stdout의 출력을 파일에 내용 추가 (append)
* `2>`  : stderr의 출력을 파일의 출력으로 redirection
* `2>>`  : stderr의 출력을 파일에 내용 추가 (append)  

```bash
$ echo hello > /tmp/out
$ > /tmp/out echo hello             
$ echo > /tmp/out hello                 # 순서 바꿔도 상관 없음
$ echo hello >&2
$ echo >&2 hello                        # stdout을 stderr로 내보냄
$ read -r line < file            
$ < file read -r line
```  

```bash
$ mycomm > outfile 2>&1 을 줄여서 mycomm &> outfile
$ mycomm >> outfile 2>&1 을 줄여서 mycomm &>> outfile
$ mycomm1 2>&1 | mycomm2 을 줄여서 mycomm1 |& mycomm2
```  

```bash
$ a.out <<< 300 &> out.txt
$ more out.txt
Hello stderr 300
Hello stdout 300
```

**Q**) 코드는 stdout -> stderr 순서로 작성했는데 왜 out.txt에는 반대 순서로 저장되어 있을까?  
> stdout에서 stdout device로, 그리고 stderr에서 stderr device로 나가는 순서는 누가 먼저 나갈지 아무도 모름!  
만약 stdout 먼저 나가게 하고 싶다면 stdout buffer에 쓰고 flush 명령으로 버퍼 비우게 해야함. 그 다음에 stderr buffer에 쓰고 stderr device에 내보내야 순서대로 저장된다.  

* 리디렉션 공부시 참고! [Redirection](https://mug896.github.io/bash-shell/redirections.html)  

### `here document, here string`  

* `here document`
* `<<` == `0<<`  : 임시 파일을 만들어 stdin으로 연결  

```bash
$ cat <<EOF         # EOF 라고 타이핑하기 전까지는 계속 입력을 받으세요.
"200"
EOF                 # 입력 끝냄
"200"
```  

```bash
$ cat <<QQQ
> 200
> Hi
> Print
> QQQ               # 입력 끝냄
200
Hi
Print
```

* `here string`
* `<<<`  : string을 stdin 입력으로 연결 (bash only)

```bash
$ cat <<< $( echo -e "hello\nhere        string" )          
# $ == 명령어 실행한 결과
hello
here        string

$ cat <<< *               # globbing 이 발생하지 않는다.
*
```

```c
//hello.c 파일
#include <stdio.h>  

int main()
{
    int in_a;
    fscanf(stdin, "%d", &in_a);
    fprintf(stdout, "Hello stdout %d\n", in_a);
    fprintf(stderr, "Hello stderr %d\n", in_a);
}

```

```bash
$ cc hello.c            # hello.c 컴파일하여 a.out 실행파일 생성됨.
$ a.out <<< 99          # here string, bash에서만 가능!
Hello stdout 99
Hello stderr 99
```

### `pipe order of execution`  

`$ cmd1 | cmd2`  
* cmd1 과 cmd2 는 동시에 병렬로 실행된다.  

* cmd1 이 cmd2 보다 빠르면 파이프에 write 은 블록되고 더이상 진행되지 않는다.  

* cmd2 가 cmd1 보다 빠르면 파이프 로부터의 read 는 블록된다.  

* cmd1 이 먼저 종료하면 파이프는 close 되고 cmd2 는 End-Of-File 로 인식해 종료한다.  

* cmd2 가 먼저 종료하면 파이프는 close 되고 cmd1 은 다음번 write 에 SIGPIPE 신호를 받게되고 종료된다. (파이프가 깨졌다는 신호)  

**Q**) cmd1 이 cmd2 보다 빠르면 파이프에 write 은 블록되고 더이상 진행되지 않는 이유?  
> stdin buffer와 stdout buffer 둘다 1024 바이트일 때, stdin이 stdout 보다 느린 경우 stdout을 안가져가면 버퍼가 꽉차서 stdout에 더 이상 내보내면 안된다.  
버퍼가 꽉 차있는데 내보내면 버퍼 플로우가 일어나서 데이터를 잃게 된다.  

**Q**) cmd2가 cmd1보다 빠른 반대의 경우에는?
> cmd2 이 cmd1 보다 빠르면 파이프에 read 은 블록되고 더이상 진행되지 않는다.  

### `named pipe`  

* Pipe는 자동으로 생성 / 소멸
* Named Pipe
    * mkfifo 명령으로 생성 – 파일처럼 생성됨 
    * redirection으로 sending
* 읽는 상대편이 없으면 Block 된다
* Buffer Control 이 필요

### `globbing, wild card`  

* glob 문자에 의해 매칭된 파일들로 치환되는 것: globbing
* \* = 없는 것을 포함하여, 어떠한 수의 문자라도 일치
* ? = 어떤 한 문자를 일치
* [abc] = 대괄호 안의 하나의 문자를 일치
* [a-c] =  대괄호 안의 범위에 속하는 하나의 문자를 일치  

```bash
$ echo h*           # h로 시작하는 파일 보여줌
hello.c
$ echo *.c
hello.c
$ echo ?????        # 5글자 파일 보여줌
a.out
$ echo ?????*       # 5글자 넘는 파일 보여줌
$ echo [abc]*       # a/b/c로 시작하는 파일 보여줌
$ echo [a-q]*       # a~q로 시작하는 파일 보여줌
```  

### `b.out | a.out`  

```c
//hello.c               # a.out 실행파일
#include <stdio.h>

int main()
{
    int in_a;
    fscanf(stdin, "%d", &in_a);
    fprintf(stdout, "Hello stdout %d\n", in_a);
    fprintf(stderr, "Hello stderr %d\n", in_a);
}
```

```bash
$ vi hello2.c               # input을 받아 stdout으로 숫자 내보내는 코드 작성
$ cc -o b.out hello2.c
$ b.out | a.out             # b.out의 출력이 a.out의 입력으로 들어가 실행됨
999
Hello stdout 999
Hello stderr 999
```

### `named pipe`  

```bash
# 첫번째 터미널에서..
$ mkfifo pipe
$ b.out > pipe
99

# 동시에 두번째 터미널에서..
$ ./a.out < pipe        # pipe에 담긴 99 읽어와서 실행 + 출력
Hello stdout 99
Hello stderr 99
```  

_pipe: a.out라는 프로그램과 b.out라는 프로그램, 두 프로그램 사이에서 통신하는데 사용 가능_   

**대표적으로 두개의 process 간의 통신하는 방식: pipe**  

### `vi pipe`

```bash
$ vi pipe           # vi 에디터로 pipe 열어서 12345 저장함
$ cat < pipe        # pipe에 저장한 것 보여준다
12345
```

### `basic data type`  

```c
int ifuncAdd(int a, int b)
{
    return a+b;
}
```

**Q**) 여기서 a, b는 정수이다 -> [ X ]
> 정수는 -무한대 ~ 무한대이기 때문에 a, b는 정수형이다. (정수 타입)  

**Q**) int가 4바이트라고 표준화 기구가 정했다 -> [ X ]  
> 기계에 따라 다르다. 어떤 기계에서는 4바이트, 8바이트, 2바이트로 달라진다.  

**위 코드는 이 컴퓨터와 컴파일러에서 정희한 정수형 데이터타입이 허용하는 범위 내의 a, b를 합하여 니온 결과가 다시 한번 허용하는 정수 범위 내에 있어야한다.**

* int: 4바이트, 2바이트, 8바이트, 1바이트
* char, unsigned char: 1바이트, 2바이트

* Standard signed integer type
    * signed char, short int, int, long int, long long int
* Unsigned
    * unsigned ...
* floating type
    * flout, double, (long double) 
* Definition in standard
    * char - large enough to store any execution character set
    * floating - The set of values of the type float is a subset of the set of values of the type double; the set of values of the type double is a subset of the set of values of the type long double.
    * Complex
    * Bool - 0,1을 저장하면 된다. (따라서 일반적으로 int형 사용)  
    * void - char의 포인터라고 생각하면 쉽다.  

* c언어에서 half float (2byte), float (4byte) double (8byte) long double(16byte)로 몇 바이트인지 정의하고 있지 않다. 

* 대신 half float ⊆ float ⊆ double ⊆ long double처럼 부분집합 (subset)으로 정의하고 있다.

### `Negative integer`  

`음수 표현 방법 3가지`  

* signed bit + value  
* two's complement: -를 곱하고 +1
* one's complement: not (bitwise)  

* C 언어에서는..? 음수를 표현하기 위해 위 3가지 경우 중 하나 사용하면 된다.  

### `signed & unsigend`

* signed & unsigend: noun-adjective format  
* 그래서 int나 char같은 타입 앞에 signed / unsigend를 쓴다.

### `(터미널에서) python 사용`  

```bash
$ python
$ bin(-4)
'-0b100'
$ bin(-7)
'-0b111'
```

* python의 integer
    * 2 ** 32, 2 ** 64, 2 ** 1024... 표현 가능
    * 따라서 python의 integer는 크기의 제한이 없다.

* python에서는 음수 표현할 때 대부분 two's complement를 사용한다.

### `limits.h`

* /usr/include/limits.h에 타입과 그 크기가 정의되어 있다.
* Maximum length of any multibyte character in any locale.
    * define MB_LEN_MAX     16 
    * = 이 컴퓨터에서는 multibyte character 16 바이트보다는 크지 않아야한다.

**limits.h는 기계마다, 컴파일러마다 다르다!**

### `10진수를 2진수로 출력해주는 코드`

```c
//binary.c
# include <stdio.h>

int main()
{
    int i;
    int in_a;
    fscanf(stdin, "%d", &in_a);
    for (i = 31 ; i >= 0 ; i--){
        
        fprintf(stdout, "%d", ((in_a>>i) & 1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");
}
```
```bash
$ cc -o bin binary.c
$ bin <<< 3
0000 0000 0000 0000 0000 0000 0000 0011
```

* int 형 변수 in_a 를 입력받아 shitf 연산을 한 후에 1과 &(and) 연산을 하여 2진수로 변환하여 출력하는 코드이다.
* `>>` 는 right shift이고 나누기 2와 같다.
* `<<` 는 left shift이고 곱하기 2와 같다.

### `음의 10진수 <-> 2진수 변환 방법`  

* 음의 10진수 정수를 2진수로 바꾸고 싶을 때
    1. 해당 정수를 양수로 바꾸어 2진수로 표현한 후, 
    2. 구한 2진수에서 1은 0으로, 0은 1로 바꾼 다음,
    3. 1을 더한다.

* 2진수를 음의 10진수 정수로 바꾸고 싶을 때
    1. 2진수에서 1은 0으로, 0은 1로 바꾼 다음,
    2. 바꾼 2진수에서 1을 더하고
    3. 더한 2진수를 10진수로 변환하여, 음을 붙인다.

<div style="text-align : center;">
    <img src=./img/twos.png width="65%" >  
</div>  

* 사진에서 위의 식은 2진수를 양의 10진수로, 아래 식은 음의 10진수로 변환하는 식이다.

* 00000000 = 0 (10진수)
* 00000001 = 1 (10진수)
* 00000010 = 2 (10진수)
* 10000000 = -128 (10진수)
* 10000001 = -127 (10진수)
* 11111111 = -1 (10진수)
* 11111110 = -2 (10진수)

### `python과 bin에서의 정수형`

* python에서는..

```bash
$ bin(3)
'0b11'
$ bin(-3)
'-0b11'
```

* 우리가 위에서 짠 bin 프로그램에서는..

```bash
$ bin <<< 3
0000 0000 0000 0000 0000 0000 0000 0011

$ bin <<< -3
1111 1111 1111 1111 1111 1111 1111 1101
```

* 우리가 짠 bin 프로그램을 바탕으로 3과 -3을 & operation하면 0000 0000 0000 0000 0000 0000 0000 0001이 나온다.

* 파이썬에서도 bin(3&-3)을 하면 '0b1'이 나온다.

* 파이썬에는 정수형 데이터의 길이가 정해져있지 않다.

* 파이썬에서는 모든 음수를 two's complement로 표현한다.
    * 내부적으로는 bin(-3)이 '-0b11' 이렇게 bit가 표현되어 있지 않다는 뜻이다.

* 파이썬에서 3은 0000000....0000011 로 앞에 0이 무한대로 있다.

* 파이썬에서 -3은 11111111......1101로 앞에 1이 무한대로 있다.

### `2진수의 & operation 코드`  

* 앞 코드에서 in_c = in_a & in_b 추가함

```c
// binary.c
# include <stdio.h>

int main()
{
    int i;
    int in_a, in_b, in_c;
    fscanf(stdin, "%d %d", &in_a, &in_b);
    in_c = in_a & in_b;
    for (i = 31 ; i >= 0 ; i--){
        
        fprintf(stdout, "%d", ((in_a>>i) & 1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");

    for (i = 31 ; i >= 0 ; i--){
        
        fprintf(stdout, "%d", ((in_b>>i) & 1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");

    for (i = 31 ; i >= 0 ; i--){
        
        fprintf(stdout, "%d", ((in_c>>i) & 1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");
    
}
```

```bash
$ cc -o bin binary.c
$ bin
100 -100                # 100과 -100의 & operation
0000 0000 0000 0000 0000 0000 0110 0100
1111 1111 1111 1111 1111 1111 1001 1100
0000 0000 0000 0000 0000 0000 0000 0100
```

### `in_c = in_a >> 2 수정 (오른쪽으로 shift)`  

* 위 코드에서 in_c = in_a & in_b를 in_c = in_a >> 2로 수정해보았다.

```bash
$ bin
-456 456
1111 1111 1111 1111 1111 1110 0011 1000
0000 0000 0000 0000 0000 0001 1100 1000
1111 1111 1111 1111 1111 1111 1000 1110
```

* 그리고 a, b, c를 unsigned int로 바꿔서 실행해본 결과이다.

```bash
$ bin
-456 456
1111 1111 1111 1111 1111 1110 0011 1000
0000 0000 0000 0000 0000 0001 1100 1000
0011 1111 1111 1111 1111 1111 1000 1110
```

* 위 두가지 case로 알 수 있는 점)

* int 형(signed int)일 때 오른쪽으로 shift하는 경우에는 가장 왼쪽에 1이 들어간다.

* 반면 unsigned int 형일 때는 오른쪽으로 shift하면 가장 왼쪽에 0이 들어간다.

* 오른쪽으로 1 shift는 나누기 2와 같다. 아래 예시는 signed int 형일 때 0이 아닌 1이 가장 왼쪽에 들어가는 모습을 보여준다.
    * 1000 0000 = -128 (10진수)
    * 1100 0000 = -64 (10진수)
    * 1110 0000 = -32 (10진수)
    * 1111 0000 = -16 (10진수)

* 주의해서 봐야할 점)

|signed int|unsigned int|
|:---------:|:---------:|
|-456 = 1111 1111 1111 1111 1111 1110 0011 1000|-456 = 1111 1111 1111 1111 1111 1110 0011 1000|
|-456을 오른쪽으로 2번 shift한 결과 1111 1111 1111 1111 1111 1111 1000 1110|-456을 오른쪽으로 2번 shift한 결과 0011 1111 1111 1111 1111 1111 1000 1110|

* -456 2번 shift한 결과를 보면 signed int는 맨 앞에 11이 들어갔는데 unsigned int는 맨 앞에 00이 들어가게 되었다.

**signed int일 때, 즉 맨 앞이 1이어서 음수일 때는 오른쪽으로 shift 연산이 일어나면 1이 들어간다.**  

**unsigned int일 때, 즉 맨 앞이 1이지만 양수일 때는 오른쪽으로 shift 연산이 일어나면 0이 들어가게 된다.**  

***

## Lecture 5
##### - 2022. 01. 11   

* more: cat 과 비슷한데 다음 페이지 보고싶으면 space 키 누름

* man cc -> gcc가 나옴

* which cc -> /usr/bin/cc
    * cc -> /etc/alternatives/cc
    * /etc/alternatives/cc -> /usr/bin/gcc
    * gcc -> gcc-7
    * gcc-7 -> x86_64-linux-gnu-gcc-7
    * x86_64-linux-gnu-gcc-7 : 이게 진짜 실행파일  

* x86_64-linux-gnu-gcc-7  
    * x86: cpu가 intel cpu 용이며, 
    * _64: intel cpu를 위한 64bit, 
    * linux: 운영체제는 리눅스를 위한,
    * gnu gcc compiler이다.  

* cpp = C preprocessor

* 우리가 cc 하면 제일 먼저 cpp가 돌고, gcc compiler가 돌고, loader가 돌아서 a.out가 만들어진다.  

### `unsigned int`  

* binary.c 파일 아래와 같이 수정함

```c
//binary.c
# include <stdio.h>

int main()
{
    int i;
    unsigned int in_a;
    fscanf(stdin, "%u", &in_a);
    fprintf(stdout, "%u \t : ", in_a);
    for (i = 31 ; i >= 0 ; i--){
        
        fprintf(stdout, "%d", ((in_a>>i) & 1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    fprintf(stdout, "\n");
}
```

* unsigned int 범위를 넘어가는 입력이나 음수를 입력받으면 입력한 수와 다른 수로 출력된다.
    * -1 입력하면 4294967295가 출력됨. (unsigned int로)

### `signed & unsigned int`

* hello.c 아래와 같이 수정함 (실행파일 : a.out)

```c
//hello.c
#include <stdio.h>

int main()
{
    signed int siA;
    unsigned int unA;

    fscanf(stdin, "%d", &siA);
    fprintf(stdout, "signed integer : %d\n", siA);
    unA = siA;
    fprintf(stdout, "unsigned integer : %u\n", unA);
    fprintf(stdout, "unsigned integer percent d : %d\n", unA);
    fprintf(stdout, "signed integer percent u : %u\n", siA);

    fscanf(stdin, "%u", &unA);
    fprintf(stdout, "unsigned integer : %u\n", unA);
    siA = unA;
    fprintf(stdout, "signed integer : %d\n", siA);
}
```

```bash
$ a.out
-1
signed integer : -1
unsigned integer : 4294967295
unsigned integer percent d : -1
signed integer percent u : 4294967295
4294967295
unsigned integer : 4294967295
signed integer : -1
```

* -1이 signed integer로 저장되면 메모리 상에 1111 1111 1111 1111 1111 1111 1111 1111로 저장된다.

* 따라서 저장된 데이터 1111 1111 1111 1111을 unsigned integer로 읽으면 2진수 그대로 읽어서 4294967295로 출력하게 되는 것이다.

* signed int로 받은 입력 -1을 signed int 변수와 unsigned int에 저장해서 출력해보기  

|signed integer|unsigned integer|
|:-------------:|:-------------:|
|%d로 출력하기: -1|%d로 출력하기: -1|
|%u로 출력하기: 4294967295|%u로 출력하기: 4294967295|

* 이를 통해서 signed integer 변수에 저장하거나 unsigned integer 변수에 같은 값을 저장해도 %d, %u에 따라 출력된다는 것을 알 수 있다.

**unsigned 와 signed 는 bitwise 똑같은 데이터이고, bit 상태가 구분되지 않는 똑같은 데이터임을 알 수 있다.**

**다만 print할 때 %d로 print하면 signed int로, %u로 print하면 unsiged int로 출력된다.**

**Q**) 어떤 숫자에 unsigned integer 값을 더하면 그 값은 절대로 증가한다? [ X ]
> 오버플로우가 일어난다면 증가하지 않는다!  

### `vi editor`  

* yy + p : 복사 & 붙여넣기

* 6yy + p : 6줄 복사 후 붙여넣기

* dd : 한줄 삭제

* dd + p : 삭제 한 줄 붙여넣기

### `signed / unsigned & int / short`  

```c
// hello.c
// siA와 sumS는 signed int 형
// unA와 sumU는 unsigned int 형으로 선언함
// shortS는 signed short, ushortS는 unsigned short로 선언
// 이전코드에서 siA를 입력받아 unA에 넣어준 상황

sumS = siA + (signed int) unA;
sumU = (unsigned int) siA + unA;
fprintf(stdout, "sumS %%d %d\n", sumS);
fprintf(stdout, "sumS %%u %u\n", sumS);
fprintf(stdout, "sumU %%d %d\n", sumU);
fprintf(stdout, "sumU %%u %u\n", sumU);

shortS = siA + unA;
ushortS = siA + unA;
fprintf(stdout, "sumS %%d %d\n", shortS);
fprintf(stdout, "sumS %%u %u\n", shortS);
fprintf(stdout, "sumU %%d %d\n", ushortS);
fprintf(stdout, "sumU %%u %u\n", ushortS);
```

```bash
$ cc hello.c
$ ./a.out
-1
sumS %d -2
sumS %u 4294967294
sumU %d -2
sumU %u 4294967294
sumS %d -2
sumS %u 4294967294
sumU %d 65534
sumU %u 65534
```

**Q**) 왜 실행한 결과의 마지막 2줄은 다르게 나왔을까?
> signed int와 unsigned int를 더하여 unsigned short 형 변수에 저장하였으므로 자동으로 type casting이 일어났기 때문이다.

**C언어에서는 연산시에 자동으로 type casting이 일어난다.**  

```c
shortS = siA + unA;
ushortS = siA + unA;
fprintf(stdout, "sumS %%d %d\n", shortS);
fprintf(stdout, "sumS %%u %u\n", shortS);
fprintf(stdout, "sumU %%d %d\n", ushortS);
fprintf(stdout, "sumU %%u %u\n", ushortS);

shortS = (short)siA + (short)unA;
ushortS = (unsigned short)siA + (unsigned short)unA;
fprintf(stdout, "sumS %%d %d\n", shortS);
fprintf(stdout, "sumS %%u %u\n", shortS);
fprintf(stdout, "sumU %%d %d\n", ushortS);
fprintf(stdout, "sumU %%u %u\n", ushortS);
```

**따라서 위 코드에서 type casting이 자동으로 일어나 같은 결과가 출력된다.**

`cc -W hello.c`  
컴파일 시 모든 것에 대해 warning을 출력하고 싶을 때 사용한다.

### `count1.c - 32bit integer에서 1의 개수 세는 프로그램`  

```c
//count1.c
#include <stdio.h>
#define VALUE_ONE 1

//count number of 1 (binary)
int count_one(unsigned int a){

    int count = 0;

    while(a != 0){
        count += a & VALUE_ONE;
        a >>= VALUE_ONE;
    }

    return count;
}

int main()
{
    int i;
    int in_a;
    fscanf(stdin, "%u", &in_a);
    fprintf(stdout, "%u \t : ", in_a);
    for(i = 31 ; i >= 0 ; i--){

        fprintf(stdout, "%d", ((in_a >>i ) &1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    fprintf(stdout, ": %d \n", count_one(in_a));

}
```

* 위의 코드 설명 - 어떻게 1의 개수를 count할까?  

a가 10진수로 6이라면 2진수로 0000 0000 0000 0000 0000 0000 0000 0110이다.

|  shift 횟수  |   a   |
|:------:|:------:|
|0번째|0000 0000 0000 0000 0000 0000 0000 0110|
|1번째|0000 0000 0000 0000 0000 0000 0000 0011|
|2번째|0000 0000 0000 0000 0000 0000 0000 0001|
|3번째|0000 0000 0000 0000 0000 0000 0000 0000|

따라서 1 (VALUE_ONE)과 a의 맨 마지막 bit 가 & 연산을 하여 1의 개수를 계산하기 때문에,  

1번째 shift 결과와 2번째 shift 결과에서 & 연산을 통해 count에 1이 더해지게 된다.  

따라서 6의 1의 개수는 2개임을 구할 수 있다.  


### `if문의 성능`  

```c
// sol1
if((in_a >> i) & 1)
    count++;

// sol2
count += in_a >> i & 1; 
```

* C operator precedence에 따라 shift를 먼저 하고 & operation을 하기 때문에 위 & 아래 코드의 연산은 같다.  

* 대신 우선순위가 헷갈리기 때문에 괄호를 사용하는 것을 추천한다.

* sol1과 sol2의 실행결과는 같은데 실행속도는 sol2가 빠르다.  
    * if문은 굉장히 느리다. if문은 굉장히 비싼 operation이다.  

```c
c = a >> 1 + b;          //case 1
c = (a >> 1) + b;        //case 2
c = a >> (1 + b);        //case 3
```

* shift 연산이 곱하기 / 나누기와 우선순위가 같다고 오해할 수 있다. 하지만 shift 연산은 더하기와 빼기보다 우선순위가 낮다.

* case 1의 결과는 case 2가 아닌 case 3과 같다!

* 따라서 case case 1처럼 코드를 작성하고 a의 shift가 먼저 일어날 것이라고 오해할 수 있으므로, 헷갈리지 않도록 괄호를 사용하는 것을 권장한다.

### `Three basic memory model in C`  

* signed / unsigned 는 int와 같은 자료형의 앞에 붙는다.  

* 나머지 수식은 자료형의 뒤에 붙는다. (ex - const, auto, static)  
    * ex- int const

* `Automatic` : automatic 변수는 현재 블록이 끝나면 자동으로 사라지는 변수이다.  
    * int 이렇게 선언하면 automatic이다.  
    * 처음 사용할 때 변수를 선언한다.
    * 범위를 벗어날 때 제거된다.  

* `Static` : static 변수는 선언된 함수 내에서만 사용이 가능하며, 단 한번만 초기화를 하고 프로그램이 종료될 때까지 메모리 공간에 존재하는 변수이다.  
    * 프로그램이 실행되는 동안 같은 공간에 존재한다.  
    * Array sizes는 고정되지만 values는 변경 가능하다.  
    * main 시작전에 데이터가 초기화된다. 따라서 계산을 필요로 하지 않는 상수를 사용하여 초기화해야 한다.  
    * static 키워드로 함수 밖에서 선언된 variables (in file scope)와 함수 안에서 선언된 variables는 static이다.  
    * static variable을 초기화 하지 않으면, zeros (or NULL)로 초기화된다.  

* `Manual`  
    * manual type에는 malloc과 free가 포함된다.  
    * manual type만 array의 크기가 선언 이후에도 조정할 수 있다.  

### `Noun-Adjective Form`  

* `int const A` constant integer  
    * const가 뒤에서 앞으로 int를 수식함

* `int const * A ` (variable) pointer to a constant integer 
    * const가 int를 수삭한다. A는 const int를 가리키는 포인터이다.

* `int * const A` constant pointer to a (variable) integer 
    * int를 가리키고 있는 포인터인데 그 포인터가 const이다.

* `int * const * A` pointer to a constant pointer to an integer  
    * int를 가리키는 const 포인터를 가리키는 포인터, 이 포인터 값은 변할 수 있다.

* `int const * * A` pointer to a pointer to a constant integer  
    * const int를 가리키는 포인터의 포인터, 두 포인터 다 변경될 수 있다.

* `int const * const * A` pointer to a constant pointer to a constant integer 
    * const int를 가리키는 const 포인터의 포인터

**Q**) `double (*f[10])(int const *a, double (*g[10])(double h));`의 의미는?  

* 함수 이름이 f인 함수를 선언하였으며 이 함수는 double을 리턴한다.  

* 함수 f는 크기가 10인 포인터의 array이며 첫번째 parameter는 int const 형태의 포인터 a이다.  

* 두번째 parameter는 함수 이름이 g이고 크기가 10인 포인터의 array이다.

* g 함수는 double을 리턴하며, double을 리턴하는 상수 h를 parameter로 가진다.  

### `static 변수 예시`  

```c
//count1.c
#include <stdio.h>
#define VALUE_ONE 1

//count number of 1 (binary)
int count_one(unsigned int a){

    int static numCalls = 0;
    int count = 0;

    while(a != 0){
        count += a & VALUE_ONE;
        a >>= VALUE_ONE;
    }

    fprintf(stderr, "Call : %d\n", numCalls);
    numCalls++;

    return count;
}

int main()
{
    int i;
    int in_a;
    fscanf(stdin, "%u", &in_a);
    fprintf(stdout, "%u \t : ", in_a);
    for(i = 31 ; i >= 0 ; i--){

        fprintf(stdout, "%d", ((in_a >>i ) &1));
        if (i % 4 == 0)
            fprintf(stdout, " ");
    }
    count_one(in_a);
    count_one(in_a);
    count_one(in_a);
    count_one(in_a);
    fprintf(stdout, ": %d \n", count_one(in_a));

}
```  

* count_one 함수의 parameter로 signed int를 받게 되면 무한루프에 빠질 수 있다.  
    * a가 signed int형 변수이고, 음수 데이터가 저장되어 있을 때, 오른쪽으로 shift를 계속해도 0이 되지 않고 계속 1이 채워지기 때문에 while문에서 무한루프에 빠지게 된다.  
    * a가 unsigned int 형이면 오른쪽으로 shift할 때 맨 왼쪽에 0이 채워지게 되고, 그럼 while문 안에서 shift가 반복해서 일어나면 언젠가 a가 꼭 0이 된다.
    * 따라서 입력이 음수일 때 무한루프에 빠지지 않기 위해서 count_one 함수의 parameter를 unsigned int a라고 선언해야한다.

* count_one을 4번 호출한 결과로 아래와 같이 출력된다.  

```
Call: 0
Call: 1
Call: 2
Call: 3
Call: 4
```

* numCalls 변수가 int 형 변수라면 모두 0이 나왔겠지만, int static 변수이기 때문에 0, 1, 2, 3, 4가 출력되었다.  

* numCalls 변수가 static 변수이기 때문에 한번만 초기화하고, 프로그램이 종료될 때까지 메모리 공간에 계속 존재하기 때문에 0으로 초기화되지 않고 값을 누적해서 출력한 것을 볼 수 있다.

* static 변수는 초기화하지 않으면 자동으로 0 (또는 NULL)으로 초기화 되지만 automatic 변수는 초기화하지 않고 값을 출력해보면 랜덤한 값이 출력된다.  

### `define`  

* preprocessor는 반복되는 값이나 작업을 미리 정의할 때 사용하며, preprocessor에서 #define으로 매크로를 정의할 수 있다.  

* #define 매크로이름 값 : 이렇게 매크로를 정의할 수 있다.  

* 이러한 매크로를 사용하면 preprocessor를 거쳐 내부적으로 소스 코드가 일괄 변환되게 된다.

### `const`  

* const 변수는 값을 변경할 수 없다. 변수가 상수임을 선언하는 예약어이다.

* 상수는 반드시 선언과 동시에 값을 할당하여 초기화해주어야 하며 초기화를 하지 않으면 컴파일 에러가 발생한다.

```c
int const con = 100;
con++;
```

* const 변수로 선언된 값은 변경이 불가능하므로 컴파일 time에 에러가 난다! ( increment of read-only variable 'con' )

***

## Lecture 6
##### - 2022. 01. 12   

### `.bash_logout`  

```bash
if [ "$SHLVL" = 1 ]; then
    [ -x /usr/bin/clear_console ] && /usr/bin/clear_console -q
fi
clear
clear
echo HAVE a NICE DAY - I am Sujong Kwak
```  

logout 시에 clear 명령으로 터미널 명령을 지우고, echo로 원하는 문장을 출력하도록 하였다.  

### `alias`  

alias = bash에 들어있는 built in 명령이다.  

```bash
$ alias -p
alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'
alias cc='cc -Wall'
alias egrep='egrep --color=auto'
alias fgrep='fgrep --color=auto'
alias grep='grep --color=auto'
alias h='history'
alias l='ls -CF'
alias la='ls -A'
alias ll='ls -alF'
alias ls='ls --color=auto'
```

* alias cc='cc -Wall' 을 통해 cc 명령어 실행시 자동으로 cc -Wall 명령으로 바뀌도록 할 수 있다.  

* alias를 풀고 싶다면 unalias cc 사용  

* 만약 alias를 사용하고 싶지 않다면 back slash('\')를 사용한다.  

```bash
$ ls            # alias 사용
$ \ls           # alias 사용 X
```

* 로그아웃하면 없어지기 때문에 ~/.bashrc 에 alias 를 추가해야한다.  

* source ~/.bashrc 로 실행하면 적용된다.

### `오늘의 목표 - Pointer 이해하기`  

* pointer basic
    * &val - Address of val
    * *ptr - Value in address val

* increment
    * int *a;       //a++ increment by 4
        * a = integer를 가리키는 주소
    * long long *b; //b++ increment by 8
        * b = long long을 가리키는 주소
    * void *c;      //c++ increment by 1

### `&& 와 ;`

```bash
$ cc hello.c && a.out       #1
$ cc hello.c ; a.out        #2
```

첫번째 명령은 hello.c가 에러가 나지 않을 때만 a.out가 실행되는 반면에,  
두번째 명령은 hello.c가 에러나도 a.out가 항상 실행된다.  

* 앞이 오류나지 않았을 때만 뒤 명령어 실행하고 싶다면 -> 명령어1 && 명령어2  

* 앞이 오류났을 때 뒤 명령어를 실행하고 싶다면 -> 명령어1 || 명령어2  

### `hello.c - a와 b의 주소`  

```c
#include <stdio.h>

int main()
{
    int a = 100;
    int b = 200;
    fprintf(stdout, "%d : %d\n", a, &a);    // 100 : 1893560592
    fprintf(stdout, "%d : %d\n", b, &b);    // 200 : 1893560596
}
```

* a의 주소에서 int형 변수의 크기인 4바이트 떨어진 곳에 b가 위치한 것을 알 수 있다.  

* int * -> long long -> lld로 출력하기! 16진수로 보고싶다면 llx로 출력한다.  

* a와 *&a는 같다. *&a에 값을 넣을수도 있다. ( *&a = 500; )

**Q**) 어떤 사람은 주소 결과가 음수로 나왔는데 왜일까?
> 메모리 주소 길이가 오버플로우 났기 때문이다.  
우리가 쓰고 있는 컴퓨터에서 int * 은 long long과 크기가 같다.

**Q**) 8bit / 16bit / 32bit / 64bit 컴퓨터의 의미??
> 한번에 처리 가능한 데이터의 크기, address line의 크기  
한번의 hardware operation으로 처리할 수 있는 데이터의 길이  
(대부분) 64bit 컴퓨터라면 데이터의 주소도 64bit length이다.  

```c
#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int main()
{
    int a = 100;
    int b = 200;
    int c;
    // int * = long long 

    fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
    fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
    c = add(a, b);
    fprintf(stdout, "%d : %lld %llx\n", c, &c, &c);
}
```

* 실행결과로 a, b, c의 주소가 4바이트씩 차이 나는 것을 볼 수 있다.  

### `call by reference`  

```c
#include <stdio.h>

int add(int *a, int *b)
{
    return *a + *b;
}

int main()
{
    int a = 100;
    int b = 200;
    int c;
    // int * = long long 

    fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
    fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
    c = add(&a, &b);
    fprintf(stdout, "%d : %lld %llx\n", c, &c, &c);
}
```

* call by reference도 실행결과 동일하게 잘 실행된다!  

```c
//a, b, c는 주소가 4바이트씩 차이난다.  
int a = 100;
int b = 200;
int c = 999;
```

**Q**) 이때 `*(a + 4)`는 값이 b의 값인 200일까? [ **X** ]  

**Q**) 이때 `*(a + 8)`는 값이 c의 값인 999일까? [ **X** ]  

**Q**) 이때 `*(a + 1)`는 값이 b의 값인 200일까? [ **O** ]  

**Q**) 이때 `*(a + 2)`는 값이 c의 값인 999일까? [ **O** ]  

* a가 int 형이기 때문에 +1을 하게 되면 4바이트가 더해진다.  
따라서 +1을 하면 4바이트 더해진 주소에 위치한 b값에 접근한다.  
그리고 +2를 하면 8바이트 더해진 주소에 위치한 c값에 접근하게 된다.  

```c
#include <stdio.h>

void add(int *a, int *b, int *c)
{
    *c = *a + *b;
}

int main()
{
    const int a = 100;
    int b = 200;
    const int c = 999;
    // int * = long long 

    fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
    fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
    add(&a, &b, &c);
    fprintf(stdout, "%d : %lld %llx\n", c, &c, &c);
}
```  

* c가 const int 형임에도 불구하고 값에 바뀔 수 있다.  
    * c의 포인터를 통해 값을 변경할 수 있다.  

```c
#include <stdio.h>

void add(int *a, int *b, int *c)
{
    *c = *a + *b;
}

int main()
{
    const int a = 100;
    int b = 200;
    long long c = 999;
    // int * = long long 

    fprintf(stdout, "%d : %lld %llx\n", a, &a, &a);
    fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
    add(&a, &b, &c);
    fprintf(stdout, "%d : %lld %llx\n", c, &c, &c);
    fprintf(stdout, "%d : %lld %llx\n", c, (&c)+1, &c+1);
    //fprintf(stdout, "%d : %lld %llx\n", c, ((void *)(&c))+1, &c+1);
    //원래는 long long 포인터인데 void 포인터로 바껴서 1씩 증가됨 (char 포인터도 1씩 증가)
    fprintf(stdout, "%d : %lld %llx\n", c, (&c)+2, &c+2);
}
```

* 어떤 주소에 1을 더하는 것은 그 데이터 타입의 값(크기)를 더한다!  

* (&c) + 1 이나 (&c) + 2 의 경우에도 주소가 어떤 데이터의 주소인지 물어보게 된다.  
따라서 주소에 + 1 이나 주소에 + 2 되지 않는다.  
c가 long long 형이므로 주소에 + 8바이트, 주소에 + 16바이트가 더해진 결과를 얻을 수 있다.  

* 정말로 주소에 딱 1만 더하고 싶다면 ((void *)(&c))+1 를 사용해야 한다.  
    * 그럼 c가 long long의 포인터였다가 void 포인터로 바뀌게 되어 1씩 증가된다.  
    * void와 char 포인터는 1씩 증가하기 때문이다.  

* const는 automatic과 비슷하지만 다른 점은 이 값을 change하려 하면 컴파일러가 에러를 발생시킨다.  

<div style="text-align : center;">
    <img src=./img/three_model.png width="45%" >  
</div>  

### `int an_array[] vs int *a_pointer`  

* int an_array[32];
    * Program will do;
    * set aside a space on the stack big enough for 32 integers, 
    * declare that an_array is a pointer, and  
    * bind that pointer to point to the newly allocated space  
    * an_array라고 하는 포인터를 만든다!
    * an_array는 배열의 시작 부분을 가리키고 있다.
    * an_array 값이 저장되는 공간은 8바이트이다. 포인터이기 때문에.

* int *a_pointer;
    * Just pointer
    * a_pointer = malloc(32*4);
    * 포인터에게 어떤 값을 주기 전까지는 제대로 된 값을 갖고있는지 아닌지 알 수 없다.  

### `array & pointer`  

```c
//sumarr.c
#include <stdio.h>

int sumArray3(int *a, int sum)
{   
    sum = *a;
    a++;
    sum += *a;
    a++;
    sum += *a;
    fprintf(stdout, "%d : %lld %llx\n", sum, &sum, &sum);
    return a[3];
}
int main()
{
    int a = 100;
    int b = 200;
    int c = 999;
    const int arr[4] = {100, 200, 300, 400};
    int *parr;
    parr = arr;
    parr++;
    fprintf(stdout, "%d : %lld %lld\n", *parr, parr, arr);
    c = sumArray3(arr, b);
    fprintf(stdout, "%d : %lld %llx\n", b, &b, &b);
    fprintf(stdout, "%d : %lld %llx\n", arr, arr, arr);
    fprintf(stdout, "%d : %lld %llx\n", *arr, *arr, *arr);
    fprintf(stdout, "%d : %lld %llx\n", &arr, &arr, &arr);
    fprintf(stdout, "%d : %lld %llx\n", arr[2], &arr[2], &arr[2]);
    fprintf(stdout, "%d : %lld %llx\n", arr[3], &arr[3], &arr[3]);
}
```

* arr = integer가 아닌 long long이다.  

* *arr = a[0]이다.  

* arr = &arr = 배열의 시작 부분 주소이다.

* arr[0], arr[1], arr[2], arr[3]은 4바이트씩 떨어져있다.

* arr를 4개짜리로 선언했지만 arr[4]를 print해보면 arr[3]에서 4바이트 떨어진 주소가 출력된다.
    * arr 길이가 4인데 5번째를 access 할 수 있다는 것이 이상하다.
    * 에러가 나는 것이 정상인데 나지 않는다.

* call by reference - 주소에 대한 데이터 변경하면 주소에 있는 값 변경된다.

* call by value - value 값이 함수에서 아무리 바꾸려해도 바뀌지 않는다.  

* Segmentation fault ( core dumped ) - memory protection
    * a.out 를 실행할 때 주어진 공간을 벗어나서 접근했 때 발생한다.  
    * segmentation violation
    * core dumped - core라고 하는 파일에 프로그램의 snapshot이 만들어짐

```c
sum = a[0];         // a[0] = sum = 100
sum += *(a+1);      // *(a+1) = a[1] = 200
sum += *(a+2);      // *(a+2) = a[3] = 300

sum = *a;           // *a = sum = 100
a++;                // a++ = a는 a[1]의 주소가 됨
sum += *a;          // *a = sum = 200
a++;                // a++ = a는 a[2]의 주소가 됨
sum += *a;          // *a = sum = 300
```

* *a + 1; 이나 *a + 2는 *a인 100에 1과 2를 더한 것이므로 101과 102이다.  
    * value operater는 더하기보다 우선순위가 더 낮다.

* 반면 *(a+1)는 a가 int형 포인터이므로 +1이 4바이트로 더해져 a[1]의 값인 200이 된다.  

* 그리고 *(a+2)도 a가 int형 포인터이므로 +2이 8바이트로 더해져 a[2]의 값인 300이 된다.  

* a 변수를 increment / decrement 할 수 있으므로 a의 저장공간이 있다는 것을 알 수 있다.

```c
int *parr;
parr = arr;
parr++;
```

* *parr = 200이 출력됨!

* parr에 int 형 배열의 주소를 담고 있는 arr이 저장되었기 때문에 parr++ 하면 arr[1]의 위치를 가리키게 된다. 따라서 *parr은 200이다.

***

## Lecture 7
##### - 2022. 01. 13  

### `Noun-Adgective Form - 중요한 차이점!`  

* `int const * A` : int가 상수 정수이며 이를 가리키는 포인터
    * int 상수값은 변경될 수 없다. 대신 이를 가리키는 포인터는 변경될 수 있다.

* `int * const A` : 이 포인터는 상수 포인터인데 변수는 int를 가리키고 있다.
    * int 값은 변경될 수 있다! 주소는 변경 불가능

### `함수의 포인터 연습`  

```c
void mul(int *a, int *b, int *c)
{ *c = *a + *b;}

int main()
{
    int const a = 100;
    int b = 200;
    int c = 9999;
    int *p = &a;
    fprintf(stdout, "a, b, c: %d %d %d\n", a, b, c);
    *p = 200;
    fprintf(stdout, "a, b, c: %d %d %d\n", a, b, c);
```

* 만약 a에 다른 값을 그대로 넣으면 에러가 발생한다.
    * assignment of read-only variable 'a'

* 그런데 위 코드처럼 a의 주소를 p에 넣고, p가 가리키는 a의 주소에 들어있는 값을 변경하면 a의 값이 변하게 된다.  

* const로 선언한 것이 주소를 통해서 값이 바뀐다면 어떤 의미가 있을까?
    * error / warning이 나오게 하려는 의미가 있다! (위 코드에서 warning 발생 O)

```c
int * const p = &a;         // case 1
p = &b;

int const * p = &a;         // case 2
p = &b;
```

1. 포인터가 const인데 b의 주소로 바뀌었으니 에러가 발생한다!  

2. int 상수 값은 변하면 안되지만 이를 가리키는 포인터는 변해도 된다.
    * 따라서 2번째 경우에는 에러가 발생하지 않는다!

```c
void *fp();         // 함수의 포인터
fp = mul;           // 에러 발생
fp(a, b, c)

void (*fp)();
fp = mul
fp(&a, &b, &c);
```

* fp가 가리키는 함수 mul은 parameter 3가지 모두 포인터로 받고 있기 때문에 fp를 호출할 때에도 a, b, c의 주소값을 넘겨줘야한다.  

* mul 과 mul()의 차이점
    * 선언문에 mul()은 함수를 선언한 것이다.  
    * 실행문에 mul()은 함수를 실행하라는 것이다.  
    * 따라서 실행문에는 mul을 사용해야한다.  

### `void (*fp[4])(int *, int *, int *) = {add, sub, mul, div};`  

* 포인터가 4개인 array이며, parameter는 int *, int *, int * 형을 받는다.

* 그리고 그 포인터 4개는 add, sub, mul, div 함수를 각각 가리킨다.  

```c
//fnpointer.c
#include <stdio.h>

void add(int *a, int *b, int *c)
{ *c = *a + *b;}

void sub(int *a, int *b, int *c)
{ *c = *a - *b;}

void div(int *a, int *b, int *c)
{ *c = (*a) / (*b);}

void mul(int *a, int *b, int *c)
{ *c = (*a) * (*b);}


int main()
{
    int a = 100;
    int b = 200;
    int c = 0;
    char ch;
    int op = 0;
    scanf("%d %c %d", &a, &ch, &b);

    void (*fp[4])(int *, int *, int *) = {add, sub, mul, div};

    switch(ch){
        case '+':
            op = 0;
            break;
        case '-':
            op = 1;
            break;
        case '*':
            op = 2;
            break;
        case '/':
            op = 3;
            break;
    }

    fprintf(stdout, "a, b, c: %d %d %d\n", a, b, c);
    fp[op](&a, &b, &c);
    fprintf(stdout, "a, b, c: %d %d %d\n", a, b, c);
    fprintf(stdout, "fp %lld %lld %lld %lld\n", add, sub, mul, div);
}
```

* 입력받은 숫자를 사칙연산하는 프로그램 (함수의 포인터 배열 이용)  

* lld로 add, sub, mul, div를 출력하면?
    * 함수의 주소가 출력된다.

### `od`
a.out 코드 어떻게 생겼는지 보고싶다면 od 명령어를 사용한다.

```bash
$ od a.out
$ od -x a.out       # 16진수로 보여줌
```

### `오늘의 목표`  

* C compile process  
* CPP - C Preprocessor
* Compile options

<div style="text-align : center;">
    <img src=./img/compile.png width="60%" >  
</div> 

1. compile - compile 명령 넣음  
preprocessor directive - C언어에서 #

2. compile user source code - # 되어있던 것 모두 바뀜  
Assembly 를 생성함

3. Link Assembler - printf, scanf와 같은 함수들과 연결시켜줌 & 실행파일 만들어줌  
    1. static link - printf, scanf와 같은 것을 그냥 실행파일에 붙여줌
        * 실행파일 사이즈 커짐, 대신 항상 어떤 기계에서든 실행됨
    2. dynamic link - dynamic library에 있는 함수를 쓰게함
        * 보안상의 이유 등으로 사용, 성능상으로 약간의 문제 있을 수 있다

4. loader, loads the executable code into memory
    * 주소는 실행될 때 결정된다. (실행될 때 메모리에 a.out가 load 된다)

* Natural language
* program language
    1. 한줄 바꿔서 실행하기 반복 = interpreter
        * ex - python
    2. 프로그램 전체 번역해서 한번에 실행코드 생성 = compiler
        * ex - C
* Machine language

### `gcc compile options`  

gcc [-c|-S|-E] [-std=standard]
 [-g] [-pg] [-Olevel]
 [-Wwarn...] [-Wpedantic]
 [-Idir...] [-Ldir...]
 [-Dmacro[=defn]...] [-Umacro]
 [-foption...] [-mmachine-option...]
 [-o outfile] [@file] infile...

* -c : generate .o file
    * preprocessing & compile 까지만 실행
* -g : for debug
* -O : Optimization  
    * 최적화, 의미가 없는 코드는 아예 지워버린다. (빨라짐!)
* -E : generate preprocessing
    * preprocessing만 실행 -> .c 파일 만들어짐
* -pg : for profile
* -m32 -m64
    * 32bit / 64bit 컴파일
    * 64bit는 32bit에서 실행 불가
    * 32bit는 64bit에서 실행 가능

### `gcc option : preprocessor`  

 -Aquestion=answer -A-question[=answer] -C -CC -Dmacro[=defn] -dD -dI
 -dM -dN -dU -fdebug-cpp -fdirectives-only -fdollars-in-identifiers
 -fexec-charset=charset -fextended-identifiers -finput-charset=charset
 -fmacro-prefix-map=old=new -fno-canonical-system-headers -fpch-deps
 -fpch-preprocess -fpreprocessed -ftabstop=width -ftrack-macro-expansion
 -fwide-exec-charset=charset -fworking-directory -H -imacros file
 -include file -M -MD -MF -MG -MM -MMD -MP -MQ -MT
 -no-integrated-cpp -P -pthread -remap -traditional -traditional-cpp
 -trigraphs -Umacro -undef -Wp,option -Xpreprocessor option

> 잘 정리된 문서로 옵션 정리 해보기..!  

### `gcc compile - for multiple file`

```c
//func.h
#define DF(a) ((a) * (a))
extern int func1(int x);

//func.c
#include "func.h"
int func1(int a)
{
    return (a * 10);
}
int func2(int a)
{
    return (a * 2);
}

//main.c
#include <stdio.h>
#include "func.h"

int main()
{
    fprintf(stdout, "func %d %d\n", func1(100), DF(10));
    //func 110 100
}
```  

`gcc main.c func.c`  

1. main.c 컴파일 -> stdio.h preprocessing -> func.h preprocessing  

2. func.h의 DF(a) 대입해주고, func1에 대해 extern임을 마킹해둠  

3. main.o 파일 생성  

4. func.c 컴파일 -> func.h 파일 가져옴, object file 만듦  

5. 링킹 - printf & func1 에 대해 링크를 걸어둠.  

    * printf - dynamic link  

    * func1 - static link  

**main.c에서 func2를 사용하고 싶다면 func.h에 반드시 extern 선언을 해주어야한다.**  

* extern int func2(int x);

`cc -c main.c` : main.c -> main.o 생성해줌 (컴파일 : source code -> object code)
`cc -c func.c` : func.c -> func.o 생성해줌 (컴파일 : source code -> object code)
`cc main.o func.o` : a.out 실행파일 만들어줌  

이 상태에서 main.c를 수정했다면 `cc main.c func.o` 로 실행한다.  

func.c를 수정했다면 `cc func.c main.o` 로 실행한다.  

**Q**) 왜 이렇게 실행할까?
> 만약 func.c를 컴파일 할 때 많은 시간이 걸리고, func.c를 수정하지 않았다면 object code인 func.o를 그대로 사용한다.  
main.c를 수정했다면 main.c와 이전에 생성한 func.o를 컴파일해주면 된다.  

### `C preprocessor (CPP)`  

1. include head files  
2. define macro  
3. conditional compilation  
4. line control  

### `CPP - include file`

* #include file as text  
    * #include <stdio.h> or "file.h"  

* gcc Option - I
    * Include location - ./usr/include/
    * default include location

* prevent multiple include
    * #pragma once
    * #ifndef \_MATH_
    * #include <math.h>
    * #endif

### `CPP - conditional compilation`  

* #if
* #ifdef
* #ifndef
* #elif
* #else
* #endif

```c
#ifdef _VERSION_
#if _VERSION_ >= 3
    printf("Version is greater or equal than 3\n");
#elif _VERSION_ == 2
#error VERSION 2 IS NOT SUPPORTED
#endif
#endif  //ifdef _VERSION_
```

* 버전이 3보다 크면 print문을 출력한다.

* 버전이 2와 같다면 에러가 발생한다.

* ifdef의 짝은 마지막 endif로, \_VERSION_ 이 정의되어있다면 조건을 만족하게 하고, 아니라면 점프한다.  

### `Macro Definition`  

* #define <identifier> <replcement tokenlist>
    * object
* #define <identifier> (<parameter list>) <replacement token list>
    * function-like macro, note parameters

* ex - #define f(a) ((a) * (a)) : 의도는 제곱!

**위 예시에서 주의할 점! 무조건 parameter에 괄호치기**

[ **good ex** ] #define f(a) ((a) * (a))
> f(20+13)으로 사용하면 ((20+13) * (20+13))이 되어 의도대로 작동한다. 

[ **bad ex** ] #define f(a) a*a
> f(20+13)으로 사용하고자 했다면 20 + 13 * 20 + 13이 되어 의도대로 작동하지 않는다.

<div style="text-align : center;">
    <img src=./img/func.png width="30%" >  
</div>  

* cc -E func.c를 통해 func.h에 있던 extern 코드가 func.c로 온 것을 볼 수 있다.
    * -E : preprocessing option

* func.h에서 define한 DF(a)를 func.c에서 사용하면 DF(a) 대신에 ((a)*(a))가 들어가게 된다.

* func.h의 메크로를 수정했다고 해보자.
    * 수정한 이후에 기존에 생성한 object code를 cc main.o func.c 로 컴파일 했다면
    * 수정한 내용이 반영되어 작동하지 않는다!

**func.h처럼 수정된 메크로를 사용하는 모든 소스코드는 반드시 다시 컴파일해야한다.**

따라서 모두 다시 컴파일해야하기 때문에 메크로를 자주 수정하는 것은 좋지 않다.  

```c
#define DF(a) ((-a) * (a))      //의도한대로 잘 동작하지 않는다.
DF(a+1) == ((-a+1) * (a+1))     //이렇게 작동한다.

#define DF(a) (-(a) * (a))
DF(a+1) == (-(a+1) * (a+1)) 
```

* 첫번째처럼 작성하면 10을 대입했을 때 -11 * 11이 나오지 않는다.
    * 대신 -9 * 11이 계산된다.

* 두번째처럼 작성하면 -11 * 11로, 의도대로 잘 작동한다.
    * 따라서 괄호 적절하게 무조건 사용하기!

**ex**) main.c와 func.h 두 파일에서 #include <stdio.h> 를 사용했다면?  

* main.c에서 두번 include 된다. 그럼 오류가 날 가능성이 있다.

* 따라서 func.h에 #pragma once 를 사용한다. 그럼 이 파일은 한번만 include 된다.

```c
#ifdef __FUNC_
#define __FUNC_ 0
//codes....
#endif
```

* 또는 위 코드와 같이 func.h에서 __FUNC_가 정의되어 있다면 ifdef 아래 코드를 실행하고, 아니면 점프를 하게 할 수 있다.
    * 그러면 `__FUNC_` 가 정의되지 않았을 때 한번만 실행하게 되고, 두번째 로딩할 때는 ifdef의 아래 코드가 실행되지 않는다.

```c
#ifndef __FUNC_

#define __FUNC_ 0

#if FUNCTION_NEGATIVE == 1
#define DF(a) (-(a)*(a))
#else
#define DF(a) ((a) * (a))
#endif

extern int func1(int x);
extern int func2(int x);

#endif
```

1. __FUNC_가 정의되어있지 않다면 그 아래 코드 실행, 정의되어 있다면 점프한다.  

2. FUNCTION_NEGATIVE가 1이라면 #define DF(a) (-(a)*(a)) 로 작동한다.  

3. FUNCTION_NEGATIVE가 1이 아니라면 #define DF(a) ((a) * (a)) 로 작동한다.

* #if 0 ~~~ #endif = 이 코드를 사용하지 않겠다! (command 처리하기 복잡할 때 사용하면 좋다.)

***

## Lecture 8
##### - 2022. 01. 17  

### `Macro 순서 예시`  

```c
// macrotest.c
#define HE HI
#define LLO _THERE
#define HELLO "HI THERE"
#define CAT(a, b) a##b
#define XCAT(a, b) CAT(a, b)
#define CALL(fn) fn(HE, LLO)
CAT(HE, LLO)    // "HI THERE", because concatenation occurs before normal expansion
XCAT(HE, LLO),  // HI_THERE, because the tokens originating from parameters ("HE" and "LLO") are expanded first
CALL(CAT)       // "HI THERE", because parameters are expanded first
```

위 코드를 cc -E macrotest.c 로 preprocessing을 하면  

* CAT(HE, LLO) -> "HI THERE"  

    * CAT(a, b)는 a##b이므로 concat 매크로를 통해 HELLO가 된다.  

    * 그럼 HELLO가 매크로를 통해 "HI THERE"가 된다.  

* XCAT(HE, LLO) -> HI_THERE  
    
    * XCAT(HE, LLO)는 CAT(HE, LLO)이며 파라미터가 각각 먼저 expanded 되었기 때문에 CAT(HI, _THERE)가 된다. 따라서 concat 매크로를 통해 HI_THERE가 된다.

* CALL(CAT) -> "HI THERE" 의 결과를 얻게 된다.
    
    * CALL(CAT)은 CALL(HE, LLO)가 되고 concat 매크로를 통해 HELLO가 된다.  


_되도록이면 이런식으로 macro 사용하지 않기..! 간단한 단어들을 매크로 사용하면 오히려 이해하기 어렵다._

* 간단한 단어들을 #define의 identifier로 사용하지 않기.

### `Special Macro and Directives`  

```c
__FILE__
__LINE__
```  

* __FILE__에는 파일 이름이 프린팅 된다.
    
    * 여러 파일 컴파일 할 때 어떤 파일에서 오류가 났는지 모를 때 사용한다.  

* __FILE__은 string, __LINE__은 integer이다.

* #error 는 에러를 발생시키게 할 수 있다.

### `Token stringification`  

* string 토큰으로 바꿔준다.

```c
#define str(s)  #s
str(p = "foo\n";)       //outputs "p = \"foo\\n";"
str(\n)                 //outputs "\n"
```

* #s로 매크로를 정의하면 문자열로 만들어준다.

* print 매크로를 만들고 싶은데 어떤때에는 %d, %c, %s로 프린트 하고 싶을 때 token stringification을 사용하면 유용하다.  

### `Token Concatenation`  

* 두개를 붙여주는 매크로이다.

```c
#define DECLARE_STRUCT_TYPE(name) typedef struct name##_s name##_t
DECLARE_STRUCT_TYPE(g_object);
//outputs: typedef struct g_object_s g_object_t
```

g_object가 매크로의 name이 위치한 곳에 들어가 붙여져서 결과가 typedef struct g_object_s g_object_t 가 된다.  

* 왜 #define sq(a) a*a를 사용할 때 concatenation 해야하는가?  

```c
#define sq(a) a*a
sq(B)
#define sq(a) aaa
sq(C)
#define sq(a) a##a##a
sq(D)
```

* sq(B)는 B*B가 되는 것은 맞다.  

* sq(C)가 출력할 때는 CCC가 나오는 것이 아니라 그냥 aaa의 결과를 얻게 된다.  

* 따라서 붙여쓰고 싶다면 마지막처럼 a##a##a로 concatenation을 정의해야 DDD 라는 결과를 얻을 수 있다.

### `GCC Optimization`  

* 최적화에 대한 table 존재  

|Option|Meaning|
|:--------:|:--------:|
|-O0(기본값)|최적화를 수행하지 않는다.|
|-O / -O1|코드 크기와 실행 시간을 줄이는 것을 제외한 최적화는 실행하지 않는다. |
|-O2|메모리 공간과 속도를 희생하지 않는 범위내의 모든 최적화를 수행한다. loop unrolling과 function inlining에 대한 최적화를 수행하지 않는다.|
|-O3 / -O2|최적화에 인라인 함수와 레지스터에 대한 최적화를 추가로 수행한다.|
|-Os / -O2|최적화 기능을 사용하지만, 코드 크기를 증가시키는 최적화는 생략한다.|

* optimization을 하다보면 코드 크기가 커진다.  

### `함수의 메모리 공간`  

```c
int fun(int a){
    
    int b;
    return a * a;
}

int main(){
    int a = 100;
    fun(a);
}
```

* 실행하기 전에 필요한 데이터 넣어둔다.  
    * main의 메모리 공간에 a의 4바이트 등

* 함수가 호출되면 호출될 때 메모리 stack 만든다.  
    * parameter a를 받기 위한 메모리
    * int b를 위한 메모리
    * return 값 저장하기 위한 메모리  

* main에 있는 a와 함수에 있는 a는 다르다! 다른 위치의 메모리에 위치한다.  

* optimize하면 사용하지 않는 변수인 int b를 사용하지 않는다. (사라진다.)  

* *fn에서 `return a * a`하는 것과, main에서 `b = a *a` 하는 것의 차이는?

**Q**) 함수를 만드는 것이 좋을까? 만들지 않는 것이 좋을까?  
1. 성능은 어느쪽이 빠를까 (main 코드 vs 함수)  
2. 코드 길이는 어떻게 구현하는 것이 짧을까

**Q**) 함수는 stack 만드는 비용이 들어서 main 코드가 성능이 빠를 것 같은데 왜 함수를 사용하는가?
> main함수나 다른 함수들에서 그 함수가 1000번 소스코드에 appear 된다고 가정하면, 코드의 길이 입장에서는 main에  당연히 함수로 만드는 것이 좋다.  

* **#define으로 함수 정의하는 것은 잘 사용하기만 한다면 성능면에서와 코드 길이면에서 좋다!**

* #define으로 함수 정의하면 함수의 내용이 그대로 들어가게 된다.  

* c++에서는 inline으로 코드 끼워넣을 수 있다. (함수의 코드 자체가 그대로 들어간다.)

### `C Compile and Execution`  

* [ C Compile and Execution ](#오늘의-목표)
    * compile 과정 복습

### `gcc -options`  

* 옵션이 매우 많은데 중요한 것만 뽑은 내용이다.

* -std=<standard> Assume that the input sources are for <standard>.
* -E Preprocess only; do not compile, assemble or link.
    * CPP, c preprocessor만 실행함
* -S Compile only; do not assemble or link.
    * compile만 함
* -c Compile and assemble, but do not link.
    * .o 파일을 만든다.
* -o <file> Place the output into <file>.

### `gcc machine option (x86 & x86 win)`  

* 컴파일된 실행파일 a.out가 다른 기계에서도 실행되면 좋을 것 같을 때 machine option을 사용한다.  

* arm에서 사용하도록 하고 싶다면 arm용 컴파일러를 설치하여야 한다.  

* -m32 -m64 -mx32 -m16 
    * 각각 32bit, 64bit

### `gcc option: preprocessor`  

* -Aquestion=answer
 * preprocessor가 질문하는 경우가 있다. answer에 yes라 해두면 계속 yes로 대답함

* -dI: include 파일은 이 디렉토리에서 가져오도록 설정

### `Must Know..`  

* 여기에 있는 내용은 꼭 알고 있기

gcc [-c|-S|-E] [-std=standard]
 [-g] [-pg] [-Olevel]
 [-Wwarn...] [-Wpedantic]
 [-Idir...] [-Ldir...]
 [-Dmacro[=defn]...] [-Umacro]
 [-foption...] [-mmachine-option...]
 [-o outfile] [@file] infile...

* -c : generate .o file
    * preprocessing & compile 까지만 실행
* -g : for debug
* -O : Optimization  
    * 최적화, 의미가 없는 코드는 아예 지워버린다. (빨라짐)
* -E : generate preprocessing
    * preprocessing만 실행 -> .c 파일 만들어짐
* -pg : for profile
* -m32 -m64
    * 32bit / 64bit 컴파일
    * 64bit는 32bit에서 실행 불가
    * 32bit는 64bit에서 실행 가능

### `compile 순서와 옵션`  

1. cc -E hello.c > hellocpp.c = c preprocessing, cpp 코드 만들어줌
2. cc -S hellocpp.c = hellocpp.s 만들어짐, compile해서 assembly로 고쳐짐
3. cc -c hellocpp.s = hellocpp.o 만들어짐, object 코드 만들어짐
4. cc -o hellocpp hellocpp.o = 실행파일 hellocpp.out가 만들어진다!  

### `CPP processing`  

* Character set
    * utf-8 = 유니코드

* Initial processing
    1. LF, CR LF and CR processing
        * 줄바꿈 코드를 모드 CR로 바꾼다.  

    2. if –trigraphs

    3. long line with “\” -> merge
        * 긴줄, 여러줄 줄 바꿔서 쓰고 싶을 때 사용한다.
        * \을 사용하면 대신 c preprocessing 이 한줄로 다시 붙인다.

    4. All comments -> “ ”
        * 모든 comment는 " "로 지운다.

* Tokenization with space
    * #define foo() bar
    * foo()bar -> bar bar    not    barbar    // use ## for concat
    * foo()bar를 했을 때는 barbar가 아닌 bar bar의 결과를 얻을 수 있다.
    * barbar처럼 붙어있는 결과를 얻고 싶다면 ## concatenation을 사용한다.

* Preprocessing language
    * inclusion of header / Macro Expansion / Conditional Compile / Line Control Diagnostics (에러 발생)

* od -x -c hello.c

<div style="text-align : center;">
    <img src=./img/od.png width="70%"/>  
</div>

* 여기서 \n이 들어가있고 \n이 0a = 10임을 알 수 있다.  

* pc에서는 \n과 \r이 들어가있는데 유닉스에서는 \n만 들어있다.  

    * 줄바꿈을 표현하는 방법은 시스템과 운영 체제에 따라 여러 가지가 있다. 
    * 윈도우는 ASCII의 CR+LF로 새줄을 나타내고 유닉스는 LF로 새줄을 나타낸다. 
    * 맥 OS은 새줄 문자로 버전 9까지 CR을 썼지만 버전 10부터 LF를 쓰고 있다.
    
* 위에서 언급한 CR processing이 일어나면 \n으로 다 바뀐다.

* MS word 왼쪽, 오른쪽 구분되는 따옴표는 유니코드이다. -> C 언어에서 사용 불가!
    * printf(“Hello World\n”");  

### `Macro Definition (1)`  

* #define PI 3.14159 = 텍스를 대치줌

* 괄호로 묶어주는 것이 안전하다.

### `Macro Definition (2)`  

* Multiple lines
```c
#define NUMBERS 1, \
                2, \
                3  

int x[] = { NUMBERS };  //int x[] = { 1, 2, 3 };  
//define 활용한 예시
```

여러줄로 define 하고 싶을 때 위에서 나온 back slash (\)을 사용한다.  

* Define Where?

```c
    foo = X; 
    #define X 4 
    bar = X;    // foo = X and bar = 4
```

define은 어디에서나 할 수 있는데, 자신 직전에 했던 define이 작동한다.

```c
#define TABLESIZE BUFSIZE
#define BUFSIZE 1024 // TABLESIZE -> BUFSIZE  -> 1024 [X]
```

TABLESIZE 가 BUFSIZE임을 정의하기 전에 BUFSIZE가 1024로 정의되어 있지 않아서 TABLESIZE가 1024로 작동하지 않는다.  

```c
#define BUFSIZE 1020
#define TABLESIZE BUFSIZE
#undef BUFSIZE
#define BUFSIZE 37   // TABLESIZE = 37
```

이 경우에서는 BUFSIZE를 정의하고 그 다음에 TABLESIZE를 정의하였기 때문에 잘 작동한다.  

### `Macro Definition (3) - Function like Macro`  

* C언어에서 if 조건문은 성능을 떨어뜨리는데 C 언어에서 사용하는 ? 조건문은 생각보다 성능이 좋다.  

```c
#define min(X, Y) ((X) < (Y) ? (X) : (Y))
```

조건이 true이면 X이고, false이면 Y가 된다.  

* omit parameter  

```c
min(, b) -> (()<(b) ? ( ) : (b))
```

빈 parameter에 무엇이 들어가든 모든 빈 공간에 paramter가 들어간다.  

따라서 빈 paramter에 값이 들어가면 조건에 따라 새로 들어간 parameter 혹은 b 를 얻게 된다.  

**대신 paramter 개수는 맞춰서 넣어줘야 한다.**
> 위 경우에는 paramter 2개 필요! parameter 개수 맞지 않으면 에러 발생  

### `Macro Definition (4) - Stringization and concat`  

* Stringization
    * Parameter leading with #
    * 위에서 본 예시 참고 -> paramter 안의 모든 것 string으로 바꿔줌

* Concatenation
    * ##을 사용하면 paramter로 들어온 것을 공백없이 합쳐주거나 공백없이 그 자리에 넣어준다.

### `Macro Definition (5) - Variadic`  

```c
eprintf ("%s:%d: ", input_file, lineno) 
fprintf (stderr, "%s:%d: ", input_file, lineno)  

#define eprintf(format, ...) fprintf (stderr, format __VA_OPT__(,) __VA_ARGS__)
```

* 뒤에 parameter들이 개수에 따라 여러개의 parameter 개수가 될 수 있는 함수 만들 수 있다.

### `Macro 예시`  

* Misnesting  

```c
#define twice(x) (2*(x))  
#define call_with_1(x) x(1)  
call_with_1 (twice)  // -> twice(1)  -> (2*(1))  

#define strange(file) fprintf (file, "%s %d", strange(stderr) p, 35); // -> fprintf (stderr, "%s %d", p, 35);  
```

* 위 예시처럼 코드 짜지 않기..  실행이 되긴 되긴 하지만 이해하기 어렵다.

* Operator precedence  

* Newline

### `Predefined Macros`  

* All Standards

```c
__FILE__    // Filename with full path string
__LINE__    // Decimal number of current line
```

* __LINE__으로 line number를 바꿀 수 있다.

```c
//hello.c
#include <stdio.h>

void add(int *a, int *b, int *c)
{
        *c = *a + *b;
}

int main()
{
        int a = 100;
        int b = 200;
        int c = 999;
        // int * = long long

        fprintf(stdout, "%d : %lld %llx\n", a, (long long )&a, (long long)&a);
        fprintf(stdout, "%d : %lld %llx\n", b, (long long)&b, (long long)&b);
        add(&a, &b, &c);
        fprintf(stdout, "%s %d : %d \n", __FILE__, __LINE__, c);
}
```

```bash
$ a.out
100 : 140734210326444 7fff3c9d3fac
200 : 140734210326448 7fff3c9d3fb0
hello.c 18 : 300
```

* 위 hello.c 코드에서 사용한 __FILE__과 __LINE_으로 파일 이름 hello.c와 line number 18이 출력된 것을 볼 수 있다.

* 만약 print문 직전에 `#define __LINE__ 1000` 매크로를 사용했다면 print문의 line number가 1000으로 출력된다.

* `#error 1024`를 사용하면 컴파일 시도할 때 바로 에러가 발생한다.

```c
#define ERR_DATA 1000
#if ERR_DATA > 1000
#error 1024
#else
#warning ERR_DATA
#endif
        fprintf(stdout, "%s %d : %d \n", __FILE__, __LINE__, c);
```

* 위 코드는 ERR_DATA가 1000이므로 에러가 나지 않고 warning과 함께 아래의 print문이 출력된다.

* line number를 define하면 line number가 증가하지 않는다. -> 되도록이면 line number 지정하지 않기.

### `Project`  

* 아주대학교의 임베디드 시스템을 위한 고정소수점 수학 라이브러리 개발  

* 고정소수점 <-> 부동소수점 (뜰 부, floating point)

* 10010101 = 정수로 149 (10진수)

* 2진수 1101.11 = 9.75
    * 소수점 뒤 부분은 1/2, 1/4가 된다.  

* 부동소수점  

<div style="text-align : center;">
    <img src=./img/floating_point.png width="70%"/>  
</div>

* 위 사진에서 1 / 10000101 / 11011010100000000000000 를 10진수로 바꾸고 싶다면
    * 순서대로 각각 s, e, m
    * 1.m * (2 ^ (e-127)) 이다.
    * 부호는 (-2S + 1) 로 이를 곱해줘야한다.

* 만약 32bit signed 정수를 2의 보수로 표현한다면
    * s / 15bit / 16bit
    * signed int a 의 실제 값은 a * 2 ^ (-16) 이다.

### `입력받은 수를 fixed point로 출력하는 프로그램`  

```c
//pcc001_final / test.c
#include <stdio.h>

// #### #### #### #### .  #### #### #### ####
// S 15 . 16

#define FX_Q_NUM 16
#define FX_2_MINUS_16 1.52587890625e-05
#define FX_2_PLUS_16 65536

int main()
{
    int ia;
    float fa;
    fscanf(stdin, "%d", &ia);
    fprintf(stdout, "%d : %d %d\n", 2, 16, 2^16 );
    fprintf(stdout, "%d : %f %f\n", ia, (float)ia, (float)ia *  FX_2_MINUS_16);
    //ia를 fixed point로 출력하고 싶다면 float형으로 바꾸고 2의 -16승을 곱해준다.
    fscanf(stdin, "%f", &fa);
    fprintf(stdout, "%f : %d %d\n", fa, (int)fa, (int) (fa * FX_2_PLUS_16));
    //floating point에 2의 16승을 곱하고 int형으로 바꿔 fixed point로 출력한다.
}
```

* fixed point로 바꾸기
    * int형 데이터 -> float 형으로 바꾸고 2의 -16승을 곱해준다.
    * float형 데이터 -> 2의 16승을 곱하고 int형으로 바꿔준다.

***

## Lecture 9
##### - 2022. 01. 18  

### `project`  

* 아주대학교의 임베디드 시스템을 위한 고정소수점 수학 라이브러리 개발  

* CPU가 하는 중요한 작업 두가지
    * ALU - arithmetic logic unit
    * CU - control unit

* +, -, *, /, &, |, ^, ~, >>, << : 보통 단위 사이클에 끝남
    * 곱셈, 나눗셈 : 어떤 컴퓨터에서는 한 사이클에 끝나지만 어떤 컴퓨터에서는 아닐 수도 있다.

* ex) Processor : Intel(R) Core(TM) i7-8700K CPU 3.70GHz
    * 기본 한 사이클 : 1 / clock speed = 1 / 3.7GHz = 0.27 nano second

* fixed point를 사용하는 이유?
    * floating point 연산은 integer 연산에 비해 매우 비싼 연산이다.
    * 내가 표현하고 싶은 수가 정수가 아니라 유효숫자가 있는 수를 표현하고 싶다면 int로 표현하되 소숫점을 고정해서 표현한다.

* #define FX_S32_31은 signed 32bit + 31bit이니까 64bit long long을 사용해야한다.

* #define FX_S47_16 -> signed long long

* #define FX_S16_15 & #define FX_S23_08 -> signed integer

* #define FX_S8_7 -> signed short

* #define FX_S4_3 -> signed char

### `S 15 . 16`  

```c
#include <stdio.h>

// #### #### #### #### .  #### #### #### ####
// S 15 . 16

#define FX_Q_NUM 16
#define FX_2_MINUS_16 1.52587890625e-05F
#define FX_2_PLUS_16 65536
#define FX_S_15_16 11516
#define FX_SYSTEM FX_S_15_16

typedef int fixed32;

fixed32 fromFloat(float fa)
{
    return (fixed32) (fa * FX_2_PLUS_16);

}

float toFloat(fixed32 xa)
{
    return ((float)(xa)) * FX_2_MINUS_16;

}

fixed32 fxAdd(fixed32 a, fixed32 b)
{
    return fromFloat((toFloat(a) + toFloat(b)));
}

fixed32 fxAdd2(fixed32 a, fixed32 b)
{
    return a + b;
}

int main()
{
    long long i=0;
    int ia, ib, ic, ic2;
    float fa;
    //fscanf(stdin, "%d %d", &ia, &ib);
    for(i = 0; i < (long long )256 * 256 * 256 * 256 ; i += (256 * 256))
    {
        ic = fxAdd(i, i);
        ic2 = fxAdd2(i, i);
        fprintf(stdout, "%f + %f : %f, %f diff = %d\n", toFloat(i), toFloat(i), toFloat(ic), toFloat(ic2),ic-ic2 );
    }
    //fprintf(stdout, "%d + %d : %d\n", ia, ib, ic);
    //fprintf(stdout, "%f + %f : %f\n", toFloat(ia), toFloat(ib), toFloat(ic));
}
```

* #define FX_2_PLUS_16의 65536을 (1<<16)으로 사용해도 성능상에서는 차이 없다.

* fromFloat 함수 : fixed point로 변환해서 return

* toFloat 함수 : floating point로 변환해서 return

* fxAdd : fixed point를 floating point로 변환 후에 더하고 다시 fixed point로 변환해서 return 해줌

* fxAdd2 : 그냥 a와 b를 더해서 return  

**Q**) fxAdd와 fxAdd2의 결과는 같을까?
> ic에는 fxAdd의 결과를, ic2에는 fxAdd2의 결과를 저장하였다.  
실행결과는 result.out에 저장함.  

`project - 보고서에 써야할 점`  

* i가 0에서부터 500만까지 i++ 해서 들어갈 때, 결과를 출력해보면 0.000000 + 0.000000....이고 그 다음이 0.000015 였다.  

* 이 숫자가 표현할 수 있는 가장 작은 숫자의 차이가 0.000015라는 뜻이다.

> 이 시스템은 정수파트가 15비트, 소수점 이하 부분이 16비트인 시스템인데 이 시스템에서 표현할 수 있는 가장 작은 차이의 수는 0.000015 입니다.  
정확한 값인지 아닌지는 나중에 계산해봐야함 -> 0.000015가 맞았다면 그 다음이 0.000030이어야 하는데 0.000031이니까 계산해봐야함  

* i = long long, for (i = 0 ; (long long) 256 * 256 * 256 * 256; i += (256 * 256) ) 실행 했을 때 결과 중 오버플로우 발생
    * 이때 16385.000000 + 16385.000000 = -32768.000000 으로 오버플로우 발생

### `debugging`  

* gcc compile options 중에 -g 가 for debug

* pcc001_final/test.c를 수정해서 일부러 &ib를 ib로 scanf 하여 에러가 발생하도록 하였다.

```bash
$ cc -g test.c
test.c: In function ‘main’:
test.c:41:21: warning: format ‘%d’ expects argument of type ‘int *’, but argument 4 has type ‘int’ [-Wformat=]
  fscanf(stdin, "%d %d", &ia, ib);

$ ./a.out
200 200         # 200 200 입력함
Segmentation fault (core dumped)

$ file a.out
a.out: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/ld-linux-x86-64.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=a4867b47f1cd5e4faf38b42c8bde146a4cfc100d, with debug_info, not stripped

# a.out 파일에 디버깅 내용 들어가서 크기가 확 커짐

$ gdb a.out
```

* gdb 사용하는 방법 = gdb 실행파일 = gdb a.out

### `gdb - GNU debugger`  

* gcc -g 옵션으로 컴파일하고 gdb를 통해 디버깅

```bash
(gdb) run           # 실행
Starting program: /home/course/pcc001/pcc/lec09/a.out
500 500             # scanf로 입력받을 값 넣어줌

Program received signal SIGSEGV, Segmentation fault.
0x00007ffff7a53932 in _IO_vfscanf_internal (s=s@entry=0x7ffff7dcfa00 <_IO_2_1_stdin_>, format=<optimized out>,
    argptr=argptr@entry=0x7fffffffe0f0, errp=errp@entry=0x0) at vfscanf.c:1898
1898	vfscanf.c: No such file or directory.
# 에러가 scanf에서 발생했음을 알 수 있다.

(gdb) where         # 에러가 발생한 현재 위치가 어디인지 알려줌
#0  0x00007ffff7a53932 in _IO_vfscanf_internal (s=s@entry=0x7ffff7dcfa00 <_IO_2_1_stdin_>, format=<optimized out>,
    argptr=argptr@entry=0x7fffffffe0f0, errp=errp@entry=0x0) at vfscanf.c:1898
#1  0x00007ffff7a60356 in __isoc99_fscanf (stream=0x7ffff7dcfa00 <_IO_2_1_stdin_>, format=<optimized out>)
    at isoc99_fscanf.c:34
#2  0x000055555555485d in main () at test.c:41

(gdb) pwd
Working directory /home/course/pcc001/pcc/lec09.

(gdb) list
1893    in vfscanf.c

(gdb) list main
32  {
33      return a + b;
34  }
35
36  int main()
37  {
38      long long i=0;
39      int ia, ib, ic, ic2;
40      float fa;
41      fscanf(stdin, "%d %d", &ia, ib);
```  

* gdb 명령어  
    * run : 실행
    * where : 에러가 발생한 현재 위치가 어디인지 알려줌
    * pwd : 현재 작업 디렉토리
    * list : 현재 vfscanf.c를 보고있다.
    * list function_name : 함수의 소스코드를 보여준다.

* where를 통해 알게 된 점  
test.c의 41번째 라인에서 에러가 발생했다.  
test.c의 main() 함수에서 __isoc99_fscanf를 호출하였고, 이 함수는 _IO_vfscanf_internal 함수를 호출하였다.  
== `call stack`  

```bash
(gdb) list
29      return a + b;
30  }
31
32  int main()
33  {
34      long long i=0;
35      int ia, ib, ic, ic2;
36      float fa;
37      fscanf(stdin, "%d %d", &ia, ib);

(gdb) break 34
Breakpoint 1 at 0x833: file test.c, line 34

(gdb) run
Starting program: /home/course/pcc001/lec09/a.out

Breakpoint 1, main() at test.c:34
34              int i=0;

(gdb) print i
$i =0

(gdb) step
37              fscanf(stdin, "%d %d", &ia, ib);
# 왜 다음 줄인 35번이 아니라 37번을 실행한 것일까?
# 실행문이 아니라 선언문이므로 다음 실행문이 37번 라인을 실행함

(gdb) print ia
$2 = 32767
(gdb) print ic
$3 = 0
(gdb) print ic2
$4 = 21845              # 변수에 garbage 들어가있는 모습

(gdb) watch ic
Hardware watchpoint 2: ic

(gdb) continue
Continuing.
0.000000 + 0.000000 : 0.000000 , 0.000000 diff = 0

Hardware watchpoint 2:ic

Old value = 0
New value = 131072
main () at test.c:41
41                      ic2 = fxAdd2(i, i);
# ic 값이 40 라인에서 바뀌어서 바로 그 다음줄 41번 라인에서 stop한다.
```

* gdb 명령어
    * break line_number : line number로 breakpoint 지정해줌
        * break 함수명도 가능
    * run : breakpoint 지정했다면 실행 후 그 라인에서 멈춤
    * print 변수 : 현재 변수에 저장된 값 볼 수 있음
    * step : 그 다음 줄 실행 (실행문) - 호출된 함수의 소스코드로 들어갈 수 O
    * next == ni : 현재 소스코드의 다음 줄 실행
    * continue : 계속 실행하고 싶을 때
    * quit : 실행 process 종료
    * clear breakpoints line_number : line number로 지정된 breakpoint 삭제
    * bt :  충돌이 일어난 시점에서 프로그램의 현재 호출 스택 보여줌 (call stack)
        * ex) fromFloat를 fxAdd가 호출하였고, fxAdd를 main이 호출하였음을 알 수 있다.  
    * watch 변수명 : 어떤 변수의 값이 변했을 때 stop 시키고 싶다면 사용

**next vs step**  
next : 현재 소스코드의 다음 줄 실행  
step : 다음 줄 실행하긴 하는데 호출된 함수의 소스코드로 들어가고 싶을 때 사용  

***

## Lecture 10
##### - 2022. 01. 19  

### `(1) coredump 시키는 방법 & gdb`  

* ulimit -a 했을 때  core file size가 unlimited 가 아니라면 ulimit -c unlimited

```bash
$ sudo service apport stop
$ ulimit -a
core file size          (blocks, -c) 0
data seg size           (kbytes, -d) unlimited
scheduling priority             (-e) 0
file size               (blocks, -f) unlimited
pending signals                 (-i) 256271
max locked memory       (kbytes, -l) 65536
max memory size         (kbytes, -m) unlimited
open files                      (-n) 1024
pipe size            (512 bytes, -p) 8
POSIX message queues     (bytes, -q) 819200
real-time priority              (-r) 0
stack size              (kbytes, -s) 8192
cpu time               (seconds, -t) unlimited
max user processes              (-u) 256271
virtual memory          (kbytes, -v) unlimited
file locks                      (-x) unlimited

$ ulimit -c unlimited
$ ulimit -a
core file size          (blocks, -c) unlimited
data seg size           (kbytes, -d) unlimited
scheduling priority             (-e) 0
file size               (blocks, -f) unlimited
pending signals                 (-i) 256271
max locked memory       (kbytes, -l) 65536
max memory size         (kbytes, -m) unlimited
open files                      (-n) 1024
pipe size            (512 bytes, -p) 8
POSIX message queues     (bytes, -q) 819200
real-time priority              (-r) 0
stack size              (kbytes, -s) 8192
cpu time               (seconds, -t) unlimited
max user processes              (-u) 256271
virtual memory          (kbytes, -v) unlimited
file locks                      (-x) unlimited
```

```bash
$ vi coredump.c
$ cc -g coredump.c
coredump.c: In function ‘main’:
coredump.c:3:12: warning: division by zero [-Wdiv-by-zero]
  int a = 10/0;
            ^
$ ./a.out
Floating point exception (core dumped)
-rw-------  1 pcc001 pcc 245760  1월 19 13:40 core      # core 생성됨
$ gdb a.out core      # gdb 실행
$ rm core             # 메모리를 낭비하기 때문에 디버깅이 끝나고 core 삭제하기

```

### `core생성 안될 때`  

* (관리자가 sudo 안했을 때)

```bash
$ cd /var/lib/apport/coredump/ 에 core가 위치함
$ cd ~/pcc/lec10
$ gdb a.out /var/lib/apport/coredump/core._home_course_pcc001_pcc_lec10_a_out.4001.34e8117c-1278-4ea4-a8b5-e6131460d25d.22969.84048070

(gdb) where         # error / warning 난 위치 보여줌
#0  0x00005621a9052609 in main () at coredump.c:3
```

* coredump = a.out를 실행하며 생긴 메모리를 통째로 dump한 것
    * 따라서 에러가 난 현재 메모리 상태를 볼 수 있다.

### `(2) visual studio 2022에서 debug`  

* new project -> empty project 생성 -> source files -> add -> new item -> c++ File(cpp)에서 hello.c로 생성 -> c 코드 작성  

```c
#include <stdio.h>

int main(){
    int a = 100;
    printf("Hello World\n");
    a = a / 0;
}
```

* f5누르면 컴파일  

* release mode : cc로 컴파일
    * cd /c/Users/hwany/source/repos/Project2/x64/Debug/Project2.exe -> exe 실행파일이 여기에 위치해있다! (소스코드 있는 디렉토리에 위치 X)

```bash
$ file Project2.exe
Project2.exe: PE32+ executable (console) x86-64, for MS Windows
# visual studio로 컴파일하여 만들어진 exe 실행파일의 정보도 볼 수 있다.
```

* debug : cc -g와 동일

* n번 라인에서 break하기: debug 모드에서 line 수 옆의 dot 누르기 (누르면 빨간색 점이 됨)  -> break point 생성됨, 계속하고 싶다면 continue 누르기

* step into, next : 한줄씩 실행 (gdb와 동일하다)
    * step into : print문을 실행했다면 print의 소스코드로 들어갈 수 있다.

* autos에 a 값 보여줌 == gdb에서의 print a 기능과 같다.  

### `Optimization`  

* Golden Rule
    * speed - CPU > Memory > Storage > IO > Human
    * Register > Cache (1st, 2nd) > Memory > ...
        * 성능을 높이려면 hardware 최대한 덜 사용해야함 (ex - printf= I/O 자제)
    * Locality
        * 사용하는 데이터 주변의 데이터를 같이 load 해오는 locality의 특성을 이용하면 메모리를 덜 사용하여 성능이 좋아질 수 있다.
    * Pipeline
    * Error  
        * 에러 처리시에도 많은 비용 사용됨

### `Pipeline`  

* CPU에서의 instruction 처리 단계
    1. Fetch: 실행할 명령을 메모리에서 읽어온다.
    2. Decode: 명령어의 해석 단계이며 명령어의 종류와 타겟 등을 판단한다.
    3. Execute: 해석된 명령어에 따라 데이터에 대한 연산을 수행한다.
    4. Memory: 메모리에 접근한다.
    5. Write: 수행한 명령의 결과를 메모리에 저장한다.  

<div style="text-align : center;">
    <img src=./img/pipeline.png width="65%"/>  
</div>

* pipeline은 한 instruction의 모든 과정이 끝나기 전에, 즉 한번에 하나의 명령어만 실행하는 것이 아니라 하나의 명령어가 실행되는 도중에 다른 명령어 실행을 시작하는 식으로 동시의 여러 개의 명령어를 실행하는 기법이다.  

* if문에 의해 branch가 발생하게 되면 어느 instruction이 그 다음에 실행해야 할 instruction인지 알 수 없게 된다. 따라서 pipeline이 깨져 성능이 떨어진다.

* 함수호출은 되도록이면 안하는 것이 좋다.
    * -> 대신 #define macro 를 사용하여 단순화 시키는 것이 좋다.
* if 조건문은 비싸지만 ? 조건문은 성능이 좋다.
* optimization을 하면 기존의 코드에서 달라지는 부분이 생기기 때문에 디버깅이 불가능하다.

### `gprof - GNU Profiling`  

* 성능을 측정하기 위해서 사용

* -gp option을 사용하여 컴파일 한다.
    * cc -gp -Wall test.c test

* 프로그램을 실행하고 gmon.out 파일을 생성한다.
    * $ ./test

* gprof를 실행한다.
    * $ gprof test gmon.out

```bash
$ cc -pg test.c         #profiling 하려면 -pg 옵션 넣어야함
$ a.out
$ ls -al
-rw-r--r--  1 pcc001 pcc  714  1월 19 15:45 gmon.out
$ gprof a.out gmon.out
# call graph 볼 수 있다.

# i += 25로 바꿔서 10배 더 느리게 실행된 결과

Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ns/call  ns/call  name
 25.80      0.67     0.67 343597384     1.96     1.96  toFloat
 21.95      1.25     0.57                             main
 19.25      1.75     0.50 171798692     2.93     2.93  fromFloat
 18.48      2.23     0.48 171798692     2.81     9.65  fxAdd
 11.94      2.54     0.31 171798692     1.81     1.81  fxAdd2
  3.08      2.62     0.08                             frame_dummy

# self: 이 함수 안에서 발생했던 time 

granularity: each sample hit covers 2 byte(s) for 0.38% of 2.62 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     96.9    0.57    1.97                 main [1]
                0.48    1.18 171798692/171798692     fxAdd [2]
                0.31    0.00 171798692/171798692     fxAdd2 [5]
-----------------------------------------------
                0.48    1.18 171798692/171798692     main [1]
[2]     63.2    0.48    1.18 171798692         fxAdd [2]
                0.67    0.00 343597384/343597384     toFloat [3]
                0.50    0.00 171798692/171798692     fromFloat [4]
-----------------------------------------------
                0.67    0.00 343597384/343597384     fxAdd [2]
[3]     25.7    0.67    0.00 343597384         toFloat [3]
-----------------------------------------------
                0.50    0.00 171798692/171798692     fxAdd [2]
[4]     19.2    0.50    0.00 171798692         fromFloat [4]
-----------------------------------------------
                0.31    0.00 171798692/171798692     main [1]
[5]     11.9    0.31    0.00 171798692         fxAdd2 [5]
-----------------------------------------------
                                                 <spontaneous>
[6]      3.1    0.08    0.00                 frame_dummy [6]
-----------------------------------------------
```

* 주의할 점: 충분히 많이 call 해야 정확한 측정이 가능하다.

* 함수의 호출은 매우 비싸다!

* 함수의 호출이 비싸기 때문에 아래처럼 바꿔서 수정해봄

```c
fixed32 fxAdd(fixed32 a, fixed32 b)
{
        //return fromFloat((toFloat(a) + toFloat(b)));
        return (fixed32)((((float)(a)) * FX_2_MINUS_16 + ((float)(b)) * FX_2_MINUS_16) * FX_2_PLUS_16);

}
```

```bash
Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ns/call  ns/call  name
 54.23      0.68     0.68 171798692     3.98     3.98  fxAdd
 27.91      1.04     0.35 171798692     2.05     2.05  fxAdd2
 13.56      1.21     0.17                             main
  4.79      1.27     0.06                             toFloat

  granularity: each sample hit covers 2 byte(s) for 0.79% of 1.27 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     95.2    0.17    1.04                 main [1]
                0.68    0.00 171798692/171798692     fxAdd [2]
                0.35    0.00 171798692/171798692     fxAdd2 [3]
-----------------------------------------------
                0.68    0.00 171798692/171798692     main [1]
[2]     54.0    0.68    0.00 171798692         fxAdd [2]
-----------------------------------------------
                0.35    0.00 171798692/171798692     main [1]
[3]     27.8    0.35    0.00 171798692         fxAdd2 [3]
-----------------------------------------------
                                                 <spontaneous>
[4]      4.8    0.06    0.00                 toFloat [4]
-----------------------------------------------
```

* function call을 하지 않았더니 거의 2배 더 빨라진 결과를 얻을 수 있었다.

```c
//macro를 call 하도록 함
#define fromFloat(fa) ((fixed32)( (fa) * FX_2_PLUS_16))
#define toFloat(xa) (((float)(xa)) * FX_2_MINUS_16)
```

* macro 를 사용한 결과 : function call 사용하지 않은 경우와 비슷하였다.

* 주의할 점: 10~20% 오차 발생할 수 있다는 점 기억해두기  

`long long & 64bit`  

* long long 자료형을 사용하도록 코드를 수정한 결과

```c
//test2.c
#include <stdio.h>

int fxMul1(int a, int b)
{
    return a * b;
}

int fxMul2(int a, int b)
{
    return (int)((long long) a * (long long) b);
}

int main()
{
    long long i=0;
    int ia, ib, ic, ic2;
    float fa;
    //fscanf(stdin, "%d %d", &ia, &ib);
    for(i = 0; i < (long long )256 * 256 * 256 * 256 ; i += 25)
    {
        ic = fxMul1(i, i);
    }
    for(i = 0; i < (long long )256 * 256 * 256 * 256 ; i += 25)
    {
        ic = fxMul2(i, i);
    }
}
```

`long long & 32bit`  

* cc -pg -m32 test2.c       //32bit 컴퓨터용으로 컴파일 함
* a.out

```bash
$ file a.out
a.out: ELF 32-bit LSB shared object, Intel 80386, version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux.so.2, for GNU/Linux 3.2.0, BuildID[sha1]=e6b9b35bc23da8fcf7462c1df17b7a2c6063cb88, not stripped
```

* 64bit로 컴파일 했을 때보다 32bit에서 mul1은 엄청 느려졌고, mul2는 조금 느려졌다.  
    * 32bit, 64bit 컴파일 시에도 gprof로 성능 비교 가능 (대신 오차 주의하기)

* 굉장히 오차가 많이 때문에 통계적인 기법을 사용해서 테스팅해보는 것을 권장한다.
    * ex - outlier 빼고 통계 내보기

### `project`  

* 기본 자료형 c  
    * [unsigned , signed]  X  [long long, int (long), short, char]
    * float, double, (half, quad)

* IEEE754

* IEEE802 - LAN 표준
    * IEEE802.11 - 와이파이 표준

* ex - unsigned char
    * val =  b7 * 27 + b6 * 26 + b5 * 25 + …… + b1 * 21 + b0 * 20
    * 가장 작은 수 : 0 ~ 가장 큰 수 : 255, 데이터의 해상도: 256 

* ex - signed char
    * sign bit가 1이면 : –(~b6 * 26 + ~b5 * 25 + …… + ~b1 * 21 + ~b0 * 20 + 1) 
    * sign bit가 0이면 : b6 * 26 + b5 * 25 + …… + b1 * 21 + b0 * 20  

* c언어의 float는 실수를 표현할 수 없다.
    * 실수를 표현하기 위해서는 무한히 큰 메모리가 필요하다.
    * 따라서 어느정도에서 근사치를 컴퓨터에 저장한다. (approximation)  

* float
    * (sign * -2 + 1) * (1.0 + fraction * 2-23 ) * 2 ^ (exp – 127) 
    * 실수를 approximation한 데이터 타입이다.  

* others
    * half – sign 1, exp 5, fraction 11
    * double – sign 1, exp 11, fraction 53
    * quadruple – sign 1, exp 15, fraction 113  

* int, char, short : fixed point number 이다.  

* fixed point number
    *  fixed point는 실수를 표현할 때 정밀도가 떨어진다.  

* FX_S03_04로 표현할 수 있는 가장 큰 수와 작은 수
    * **내 시스템에서 표현할 수 있는 가장 큰 수와 가장 작은 수 보고서에 적기**  
    * signed 8bit : -128 ~ 127 표현 가능
    * FX_S03_04의 val은 정수로 표현된 값 / 16이다.
    * 따라서 -128/16 ~ 127/16 = -8 ~ 7.9375이다.

* val = 정수로 표현된 값 (ival) * (2 ^ (-q))
    * (2 ^ (-q)) = 제일 작은 해상도, 서로 구분할 수 있는 숫자의 차이

* 사칙연산
    * v_a (fixed point) -> iv_a (정수로 표현한 값)
    * v_b (fixed point) -> iv_b (정수로 표현한 값)
    * 덧셈 / 뺄셈: v = v_a + v_b = iv_a * (2^-q)  + iv_b * (2^-q)   = (iv_a + iv_b) * (2^-q) 
        * iv = iv_a + iv_b  

    * 곱셈: v = v_a * v_b = iv_a * (2^-q)  * iv_b * (2^-q)   = (iv_a * iv_b) * (2^-2q) 
        * iv = iv_a * iv_b * (2^-q)
        * 위 식의 2^-q에 2^q 를 곱해주면 2^-q로 만들 수 있다.

    * 나눗셈: v = v_a / v_b = iv_a * (2^-q)  / iv_b * (2^-q)   = (iv_a / iv_b)  
        * iv = iv_a / iv_b * (2^q)
        * iv = iv_a * (2^q) / iv_b 

* #define FX_S32_31 ((1<<16) | (32<<8) | (31))
    * 1에 256*256 곱하기 + 32에 256 곱하기 + 31

* 조건부 compile
    * #define FX_SYSTEM_INTEGER 32 & 64
        * 이거에 따라서 자기의 코드 다르게 컴파일 되어야함 (두세트 짜야함)
    * #define FX_POINT = #define FX_S32_31
    * #define FX_OP_PREFERRENCE
        * FX_OP_FLOAT - float 로 전부 바꿔서 연산
        * FX_OP_PRECISION - 정밀도가 높은 연산 
        * FX_OP_FAIR - 꽤 괜찮은 연산
        * FX_OP_PERFORMANCE - 성능 높은 연산

* Fixed point arithmetic
    * 연산 – 덧셈/뺄셈/곱셈/나눗셈 (복수의 장단점이 있는 함수)
    * 함수 – Sine, Cosine, Tan, Sqrt (가능하면)
        * 전부 table로 만들 수 있다 (메모리에 만들어두기)
            * ex - 0도에서 90도까지 array table 만들고 만약 30.5도면 30도와 31도를 선형으로 interpolation 해도 됨 (선형 보간법)
    * 변환 – from/to double, float, int, short, longlong
    * 상수 – PI, 1/PI, e, log 10, log 2, 자주 쓰이는 수
        * #define으로 정의함

`보고서 - project 분석 - 성능과 정밀도`  

* 특히 곱셈 / 나눗셈에 대해
    * 성능 (천만번 - 몇초) / 정밀도 분석
    * 성능 분석 전: function으로 만들었더니 이러이러한 결과가 나왔다.
    * 성능 분석 후: MACRO로 개발
    * 오류처리에 대한 처리
        * 오버플로우가 발생했을 때 어떻게 해야한다.

***

## Lecture 11
##### - 2022. 01. 20  

* addValue - call by value : 함수 호출시 값을 보내주는 방법 
* addPointer - call by address : 함수 호출시 주소를 보내주는 방법
    * call by address는 call by reference의 한 종류임

### `how to use gprof`  

* gprof options
    * -b // -brief -q -p : call graph or runtime
    * -z // add unused functions
        * 사용하지 않은 함수도 나타내준다.
        * 함수 포인터로 호출된 함수도 counting이 증가한다. (ex - fn = mul;)
    * -A // Annotation on source, must be compiled with -pg -g
        * 소스코드에 주석을 달아줌, 제일 많이 실행된 라인, 실행 요약 보여줌
    * --graph

### `What makes different performance`  

* System을 느리게 하는 것들!

* golden rule
    * speed - CPU > Memory > Storage > IO > Human
        * print 문 - IO
        * file open - storage
    * Register > Cache (1st, 2nd) > Memory > ...
    * Locality
    * Pipeline
        * 조건문
    * Error

* function call 도 매우 느리다.

* Depend on HW
    * One cycle execution - +, -, >>, <<, > ?

**Q**) 왜 덧셈이 곱하기보다 느릴까?
> 덧셈 오버플로우가 발생했기 때문이다. (Error)  
(long long) 256 * 256 * 256 * 256 이렇게 큰 수를 더할 때 오버플로우가 발생  
따라서 64 * 256 * 256 * 256으로 성능 테스트 해보기

```c
#include <stdio.h>

int fxMul1(int a, int b)
{
        return a * b;
}

int fxMul2(int a, int b)
{
        return (int)((long long) a * (long long) b);
}

int main()
{
        int i=0;
        int ia, ib, ic, ic2;
        float fa;
        //fscanf(stdin, "%d %d", &ia, &ib);
        for(i = 0; i < 64 * 256 * 256 * 256 ; i += 5)
        {
                ic = fxMul1(i, i);
        }
        for(i = 0; i < 64 * 256 * 256 * 256 ; i += 5)
        {
                ic = fxMul2(i, i);
        }
}
```

```bash
$ cc -pg -g test3.c
$ a.out
$ gprof -b
Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ns/call  ns/call  name
 43.11      0.12     0.12                             main
 34.13      0.22     0.10 42949673     2.23     2.23  fxMul2
 23.35      0.28     0.07 42949673     1.52     1.52  fxMul1


			Call graph


granularity: each sample hit covers 2 byte(s) for 3.55% of 0.28 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]    100.0    0.12    0.16                 main [1]
                0.10    0.00 42949673/42949673     fxMul2 [2]
                0.07    0.00 42949673/42949673     fxMul1 [3]
-----------------------------------------------
                0.10    0.00 42949673/42949673     main [1]
[2]     33.9    0.10    0.00 42949673         fxMul2 [2]
-----------------------------------------------
                0.07    0.00 42949673/42949673     main [1]
[3]     23.2    0.07    0.00 42949673         fxMul1 [3]
-----------------------------------------------


Index by function name

   [3] fxMul1                  [2] fxMul2                  [1] main
pcc001@git:~/pcc/lec10$
```

* 왜 mul1이 mul2보다 느릴까?
    * mul1에서는 오버플로우가 발생했지만 mul2에서는 long long으로 바꿨기 때문에 오버플로우가 발생하지 않는다.  

* 32bit 용으로 컴파일하면 더 빨라짐
    * 32bit integer 연산이 많다면 더 빨라진다.
    * 그리고 대부분 32bit integer 연산이다.

```bash
gprof -b
Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ns/call  ns/call  name
 25.75      0.11     0.11 42949673     2.46     2.46  fxMul1
 25.75      0.21     0.11 42949673     2.46     2.46  fxMul2
 22.07      0.30     0.09                             __x86.get_pc_thunk.bx
 17.16      0.37     0.07                             main
  9.81      0.41     0.04                             __x86.get_pc_thunk.dx


			Call graph


granularity: each sample hit covers 2 byte(s) for 2.43% of 0.41 seconds

index % time    self  children    called     name
                                                 <spontaneous>
[1]     68.3    0.07    0.21                 main [1]
                0.11    0.00 42949673/42949673     fxMul1 [2]
                0.11    0.00 42949673/42949673     fxMul2 [3]
-----------------------------------------------
                0.11    0.00 42949673/42949673     main [1]
[2]     25.6    0.11    0.00 42949673         fxMul1 [2]
-----------------------------------------------
                0.11    0.00 42949673/42949673     main [1]
[3]     25.6    0.11    0.00 42949673         fxMul2 [3]
-----------------------------------------------
                                                 <spontaneous>
[4]     22.0    0.09    0.00                 __x86.get_pc_thunk.bx [4]
-----------------------------------------------
                                                 <spontaneous>
[5]      9.8    0.04    0.00                 __x86.get_pc_thunk.dx [5]
-----------------------------------------------


Index by function name

   [4] __x86.get_pc_thunk.bx   [2] fxMul1                  [1] main
   [5] __x86.get_pc_thunk.dx   [3] fxMul2
```

* 위 결과로 같은 코드인데 32bit 컴파일하고 실행했더니 이 경우가 더 빨라진 것을 볼 수 있다.  

### `project - ARM Instruction set format`  

### `rgba.c`  

* 4byte - unsigned int로 선언 (uint32)
    * HSB - 8bit(r) 8bit(g) 8bit(b) 8bit(a) - LSB
    * 2의 24승 색 표현할 수 있다.

* 표현할 수 있는 가장 어두운 red & 밝은 red는 몇단계로 변할 수 있을까?
    * 0 ~ 255 : 256단계

* fixed point : 0은 0.0으로, 255는 1.0으로 표현하고 싶다.

`shift 로 계산`  

```c
#include <stdio.h>

typedef unsigned int t_rgba;

unsigned int fromRGBA(int r, int g, int b, int a)
{
        return (r<<24|g<<16|b<<8|a);
}

int main(){

        int red, green, blue, alpha;
        t_rgba rgba_1;
        // input value must be in 0~255
        // rgba_1 [rrrrrrrr][gggggggg][bbbbbbbb][aaaaaaaa]
        printf("Input 4 values with 0~255 ");
        scanf("%d %d %d %d", &red, &green, &blue, &alpha);
        rgba_1 = fromRGBA(red, green, blue, alpha);
        printf("%d %d %d %d : %d 0x08%x\n", red, green, blue, alpha, rgba_1, rgba_1);
}
```

`곱하기로 계산`  

```c
#include <stdio.h>

typedef unsigned int t_rgba;

unsigned int fromRGBA(int r, int g, int b, int a)
{
        return r*256*256*256 + g*256*256 + b*256 + a*1;
}

int main(){

        int red, green, blue, alpha;
        t_rgba rgba_1;
        // input value must be in 0~255
        // rgba_1 [rrrrrrrr][gggggggg][bbbbbbbb][aaaaaaaa]
        printf("Input 4 values with 0~255 ");
        scanf("%d %d %d %d", &red, &green, &blue, &alpha);
        rgba_1 = fromRGBA(red, green, blue, alpha);
        printf("%d %d %d %d : %u 0x08%x\n", red, green, blue, alpha, rgba_1, rgba_1);
}
```

```bash
$ a.out
Input 4 values with 0~255 255 255 255 255
255 255 255 255 : 4294967295 0xffffffff
```

* 두 소스코드 모두 같은 결과를 갖는다.

* `(r<<24|g<<16|b<<8|a);` 와 `r*256*256*256 + g*256*256 + b*256 + a*1;`는
    * r, g, b, a가 0에서 255임을 만족한다면 연산은 완전히 같다.

* 컴퓨터는 2진수 체계

* chmod ### 은 8진수 체계 , 사용할 수 있는 수가 0~7이다.

```c
return (r<<24|g<<16|b<<8|a)                 //case 0
return (r<<24 + g<<16 + b<<8 + a);          //case 1
return (r<<24) + (g<<16) + (b<<8) + (a);    //case 2
```

**Q**) |를 +로 바꿔도 잘 계산될까?
> +가 <<<보다 우선순위가 높기 때문에 우선순위 때문에 의도한대로 출력되지 않는다.  
r<<< (24 + g) <<< (16 + b) <<< (8+a);로 계산된다.  
따라서 두번째 case 처럼 **괄호**를 사용해야한다.  

```c
return ((r&0xff)<<24)|((g&0xff)<<16)|((b&0xff)<<8)|(a&0xff)    
```

* 예를 들어 green에 이상한 숫자 들어가면 다른 자리 말고 green 만 영향을 받게 하고 싶다면 위 코드를 사용한다.

* LSB, 가장 낮은 자리수에 있는 8bit만 남기고 나머지에 0을 쓰는 코드이다.

```c
#define fromRGBA(r, g, b, a) ((r&0xff)<<24)|((g&0xff)<<16)|((b&0xff)<<8)|(a&0xff)
#define fromRGBA(r, g, b, a) (((r)&0xff)<<24)|(((g)&0xff)<<16)|(((b)&0xff)<<8)|((a)&0xff)
```

* 첫번째 경우에서 꼭 변수에 독립적으로 괄호를 사용해야한다!

* r+3을 첫번째에 넣었다면 (r + 3 & 0xff )<<24 로 계산되었을 것이다.

* 따라서 두번째처럼 메크로 정의하면 의도대로 사용이 가능하다.

### `mul vs div`  

```c
#define FNUM_1_255      (1.0f/255.0f)

t_rgba mul_float(t_rgba c1, trgba c2){

        float r1, g1, b1, a1;
        float r2, g2, b2, a2;
        r1 = (float) ((c1 >> 24)       ) * FNUM_1_255;
	    g1 = (float) ((c1 >> 16) & 0xff) * FNUM_1_255;
	    b1 = (float) ((c1 >>  8) & 0xff) * FNUM_1_255;
	    a1 = (float) ((c1      ) & 0xff) * FNUM_1_255;
}
```

* 곱셈이 나눗셈보다 4배정도 빠르다.  

* 따라서 위 코드에서 나눗셈 대신에 역수 메크로를 정의해서 곱해주는 것이 더 빠르다.

    * F_NUM_1_255는 #define F_NUM_1_255 (1.0f/255.0f) 로 정의되었다.

### `t_rgba float / int 곱하기 함수`    

```c
#define FNUM_1_255	(1.0f/255.0f)

t_rgba mul_float(t_rgba c1, t_rgba c2){		
	
	float 	r1, g1, b1, a1;
	float 	r2, g2, b2, a2;
	int	ir, ig, ib, ia;

	r1 = (float) ((c1 >> 24)       ) * FNUM_1_255;
	g1 = (float) ((c1 >> 16) & 0xff) * FNUM_1_255;
	b1 = (float) ((c1 >>  8) & 0xff) * FNUM_1_255;
	a1 = (float) ((c1      ) & 0xff) * FNUM_1_255;

	r2 = (float) ((c1 >> 24)       ) * FNUM_1_255;
	g2 = (float) ((c1 >> 16) & 0xff) * FNUM_1_255;
	b2 = (float) ((c1 >>  8) & 0xff) * FNUM_1_255;
	a2 = (float) ((c1      ) & 0xff) * FNUM_1_255;
	
	ir = (int)((r1 * r2) * 255.0f);
	ig = (int)((g1 * g2) * 255.0f);
	ib = (int)((b1 * b2) * 255.0f);
	ia = (int)((a1 * a2) * 255.0f);

	return fromRGBA(ir, ig, ib, ia);
}

t_rgba mul_int(t_rgba c1, t_rgba c2)
{
	unsigned int r1, g1, b1, a1;
	unsigned int r2, g2, b2, a2;
	unsigned int r, g, b, a;
	
	r1 = c1 >> 24;		 r2 = c2 >> 24;
	g1 = (c1 >> 16) & 0xff;  g2 = (c2 >> 16) & 0xff;
	b1 = (c1 >> 8) & 0xff;   b2 = (c2 >> 8) & 0xff;
	a1 = c1 & 0xff; 	 a2 = c2 & 0xff;

	r = (r1 * r2)>>8;
	g = (g1 * g2)>>8;
	b = (b1 * b2)>>8;
	a = (a1 * a2)>>8;

	return fromRGBA(r, g, b, a);
}
```

* 위 코드는 t_rgba 형 데이터 두 개를 입력받아 float 또는 int로 변환하여 각각의 컬러끼리 곱한 결과를 t_rgba로 return하는 함수이다.

***

## Lecture 12  

##### - 2022. 01. 24   

### `project`  

> lec12에 /tmp/lec12/* 을 모두 copy 해옴 (템플릿 코드)

* fx_head.h 그냥 include 해서 사용하기

* Operation preference
    * FX_OP_FLOAT : 연산 floating으로 할 때
    * FX_OP_PRECISION : 정밀한 계산
    * FX_OP_FAIR : 꽤 정밀한 계산
    * FX_OP_PERFORMANCE : 성능 좋은 계산

* fx_s32_31.c fx_s32_31.h 를 작성하고 테스트하는 코드 필요

```c
#define FX_SYSTEM_INTEGER       32                              // or 64 32
#define FX_SYSTEM_FLOAT         32                              // or 32 64
```

* FX_SYSTEM_INTEGER & FLOAT = 자기가 정해야함

* 우리 ssh 서버 : 64bit integer가 32bit integer보다 계산이 더 빠르다.

* FX_SYSTEM_INTEGER로 32를 선언하면, 조건부 컴파일에서 32bit 컴파일에 맞춰서 컴파일 되도록 해야함 (우리가 짜야함 - 선택적 컴파일)

```c
#if FX_SYSTEM_FLOAT==64
#define  fromFloat(d)           ((fixed)((d)*DOUBLE_Q_VALUE))
#define  toFloat(d)             ((double)(d)*DOUBLE_1_Q_VALUE)
#else // == 32
#define  fromFloat(d)           ((fixed)((d)*FLOAT_Q_VALUE))
#define  toFloat(d)             ((float)(d)*FLOAT_1_Q_VALUE)
#endif
```

* FX_SYSTEM_FLOAT==64 이면 이 기계는 64bit floating 연산이나 32bit floating 연산이나 성능이 똑같기 때문에 if 문으로 double 을 사용하는 fromFloat / to Float 를 사용하도록 한다.

* else는 32bit floating 을 사용하고 싶을 때 가능하도록 남겨둔다.

* fx_s15_16.h에 있는 나머지 constant는 그대로 사용가능

* 일반 규칙
    * func.c 의 f1(), f2()
    * func.h 의 #define F1_f.., extern f1(), f2()
    * test.c는 함수를 쓰기 위해 반드시 #include "func.h"  
    * func.c를 include 하지 않는 이유 - func.c가 10만줄이라면 매번 include 해서 컴파일을 해야하기 때문  

### `dependency (전제조건)`    

```bash
$ cc -c main.c fx_s15_16.c      // main.o fx_s15_16.o 파일 만들어짐
//이후에 fx_s15_16.h 파일 수정함
$ cc main.o fx_s15_16.o         //파일 수정하였기 때문에 dependency 가 있어 object 파일로 컴파일 불가
```

따라서 이런 불편함을 해결하기 위해 make 를 사용한다.  

### `make (GNU make)`  

* Lots of source files: foo1.h, foo2.h, foobar1.cpp….
* How to manage them all - 모두 쉽게 관리하는 방법 없을까?
* Compiling is not easy
    * different target system
    * different purpose of compiling – debug, release, preprocessor… - 목적에 따른 컴파일링
    * compile what we need to 
    * dependency

* Solution is 
    * make

* `Makefile` 이라는 파일을 만들면 make를 사용하도록 작성할 수 있다.
    * given targets (usually file to be created)
        * 타겟 = 생성되는 파일 (ex - a.out:)
    * Specify dependencies for each target
        * a.out를 만들기 위해 필요한 파일들
    * Give command to create target from dependencies
        * ex - ccs
    * `make` recursively build targets from dependencies
        * dependency를 따라가며 필요한 것들 만든다.
        * make 라는 명령어 사용, make 뒤에 파일명 사용하지 않으면 현재 디렉토리에 있는 Makefile 기본으로 사용한다.
    * recompilation – time-stamp of modification 
        * ls -al 했을 때 나오는 정보 : time-stamp

### `Makefile 만드는 방법`  

taget (`$@`) dependency files (`$< $^ $?`)  
`main.o: main.c main.h`
`	cc –c main.c –o main.o`
tab	   Execute if dependency changes

* main.o를 만들기 위해 필요한 파일은 main.c, main.h 이다.  

* Macro  

```bash
OBJS = main.o data.o
$(OBJS)
```

* #default shell is /bin/sh  
    * make를 실행하면 새로운 오리지널 sh 쉘이 실행된다.
* #if you want change SHELL:=/bin/bash b: SHELL:=/bin/bash
    * shell이 아니라 bash를 사용할 수 있다.

### `Makefile (1)`  

```bash
main: main.c fx_s15_16.c fx_head.h fx_s15_16.h
        cc main.c fx_s15_16.c -o main
```

* main.c fx_s15_16.c fx_head.h fx_s15_16.h : make 타겟 파일이 만들어지기 위한 dependency가 있는 파일들

* 실행파일로 a.out가 아닌 main이 만들어진다.

```bash
$ make
cc main.c fx_s15_16.c -o main
$ make
make: 'main' is up to date.         # 수정된 파일이 없으므로 main 파일을 다시 만들 필요가 없어서 make 하지 않는다.
# main.c 를 수정함
$ make
cc main.c fx_s15_16.c -o main       # compile 다시한다.

# 또는 touch main.c
$ touch main.c                      # touch로 main.c의 timestamps가 바뀌었다.
$ make                              # 따라서 make 가 실행된다.
cc main.c fx_s15_16.c -o main

$ touch *.h                         # 헤더파일을 touch해도 가능
$ make                              # 따라서 make 가 실행된다.
cc main.c fx_s15_16.c -o main

$ vi Makefile                       # makefile에 -g 옵션 넣어서 수정함
$ make                              # make 불가
make: 'main' is up to date.
```

* 이 파일이 가장 최근에 modify 된게 언제인지 : timestamps

* main.c fx_s15_16.c fx_s15_16.h : dependency 가진다.  

* 근데 main이 최신 파일이니까 컴파일 할 필요가 없어서 또 make 하면 make: 'main' is up to date. 라고 뜬다.

* touch: change file timestamps - c파일이나 h파일 등을 수정했을 때는 make가 되지만, Makefile을 수정해도 다시 make, 컴파일하지 않는다.

```bash
main: main.c fx_s15_16.c fx_head.h fx_s15_16.h
        cc -g main.c fx_s15_16.c -o main
clean:
        rm main *.o *.out
```

* make clean 실행시 main과 object 파일, out 파일이 삭제된다.  

* 따라서 make clean 후 make 하면 항상 새로 컴파일된다.

* touch로 수정한 시간을 원하는 시간으로 설정할 수 있기 때문에 file의 modification time은 보안상의 의미가 없다.

### `Makefile (2)`  

```bash
main: main.o fx_s15_16.o
	cc main.o fx_s15_16.o -o main
main.o: main.c fx_head.h fx_s15_16.h
	cc -c main.c
fx_s15_16.o: fx_head.h fx_s15_16.c
	cc -c fx_s15_16.c
clean:
	rm main *.o *.out
```

* cc -c 로 object 파일을 만들고, 이를 사용해서 컴파일 하고 싶다면 위 Makefile 사용
    * main.c fx_head.h fx_s15_16.h 를 사용하여 main.o 생성
    * fx_head.h fx_s15_16.c 를 사용하여 fx_s15_16.o 생성
    * 만들어진 main.o fx_s15_16.o 를 사용하여 컴파일 후 main 실행파일이 생성된다.

```bash
$ make
cc -c main.c
cc -c fx_s15_16.c
cc main.o fx_s15_16.o -o main

$ touch main.c
$ make
cc -c main.c
cc main.o fx_s15_16.o -o main
```

* make 실행시 순서대로 main.o, fx_s15_16.o 를 생성하여 main 실행파일을 만든다.

* 만약 main.c 파일만 수정되었다면 fx_s15_16.o를 다시 만들 필요가 없기 때문에 main.o 파일만 생성하여 컴파일한다.

* 내가 원하는 파일만 touch 해서 그 파일만 컴파일 가능하다.

### `Makefile (3)`  

```bash
OBJS = main.o fx_s15_16.o
main: $(OBJS)
        cc $(OBJS) -o $@
main.o: main.c fx_head.h fx_s15_16.h
        cc -c $<
fx_s15_16.o: fx_s15_16.c fx_s15_16.h
        cc -c $<
clean:
        rm main $(OBJS)
```

* object 파일을 OBJS 라고 선언하면 $(OBJS) 에 대신 들어간다.

* `$@` : 타겟 파일 이름이 들어간다.
* `$<` : 첫번째 prerequisite, dependency 에 있는 이름이 들어간다.

* Automatic Variables - Basic

|Automatic Variable|Content|
|:-----------------:|:----:|
|`$@`|The file name of the target of the rule.|
|`$%`|The target member name, when the target is an archive member.|
|`$<`|The name of the first prerequisite.|
|`$*`|The stem with which an implicit rule matches|
|`$?`|The names of all the prerequisites that are newer than the target, with spaces between them.|
|`$^`|The names of all the prerequisites, with spaces between them.|
|`$+`|This is like '$^', but prerequisites listed more than once are duplicated in the order they were listed in the makefile.|
|`'$(@D)'`|The directory part of the file name of the target, with the trailing slash removed.|
|`'$(@F)'`|The file-within-directory part of the file name of the target.|
|`'$(*D)''$(*F)'`|The directory part and the file-within-directory part of the stem; dir and foo in this example.|

* 이러한 automatic variable 을 사용하여 더 간단하고 짧은 Makefile을 만들 수 있다.
    * 더 많은 변수는 피피티 참고


* CCFLAGS 를 사용한 Makefile  

```bash
OBJS = main.o fx_s15_16.o
CCFLAGS = -Wall -g -pg
main: $(OBJS)
        cc $(OBJS) $(CCFLAGS) -o $@
main.o: main.c fx_head.h fx_s15_16.h
        cc -c $(CCFLAGS) $<
fx_s15_16.o: fx_s15_16.c fx_s15_16.h
        cc -c $(CCFLAGS) $<
clean:
        rm main $(OBJS)
```

* Pre-defined MACRO  

|MACRO|Description|
|:-----------------:|:----:|
|AR|Archive-maintain program; default ‘ar’|
|ARGLAGS|Options of AR command|
|AS|Assembler. Default is ‘as’|
|ASFLAGS|Options of AS command|
|CC|C Complier. Default is ‘cc’|
|CCFLAGS|Options of C Compiler|
|CXX|C++ Compiler: Default is ‘g++’|
|CXXFLAGS|Options of C++ Compiler|
|LDFLAGS|Options of ‘ld’ command|

```bash
$ make
cc main.o fx_s15_16.o -Wall -g -pg -o main
```

* CCFLAGS에 넣은 c 컴파일러 옵션들이 적용되어 컴파일 된 것을 볼 수 있다.

### `Makefile (4)`  

```bash
OBJS = main.o fx_s15_16.o
CCFLAGS = -Wall -g -pg
main: $(OBJS)
        cc $(OBJS) $(CCFLAGS) -o $@
.c.o:
        cc -c $(CCFLAGS) $<
clean:
        rm main $(OBJS)
```

```bash
$ make
cc -c -Wall -g -pg main.c
cc -c -Wall -g -pg fx_s15_16.c
cc main.o fx_s15_16.o -Wall -g -pg -o main

$ touch *.h
$ make
make: 'main' is up to date.         # 파일을 수정해도 make를 새로하지 않는다.
```

* 위 Makefile은 실행이 잘 되긴 하지만 dependency 제대로 작동하지 않는다.

* 따라서 `$ gccmakedep main.c fx_s15_16.c` 실행 : gcc make dependency

```bash
OBJS = main.o fx_s15_16.o
CCFLAGS = -Wall -g -pg
main: $(OBJS)
        cc $(OBJS) $(CCFLAGS) -o $@
.c.o:
        cc -c $(CCFLAGS) $<
clean:
        rm main $(OBJS)
# DO NOT DELETE
main.o: main.c /usr/include/stdc-predef.h fx_s15_16.h fx_head.h \
 /usr/include/math.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 # 생략...
fx_s15_16.o: fx_s15_16.c /usr/include/stdc-predef.h fx_head.h fx_s15_16.h \
 /usr/include/math.h \
 /usr/include/x86_64-linux-gnu/bits/libc-header-start.h \
 /usr/include/features.h /usr/include/x86_64-linux-gnu/sys/cdefs.h \
 # 생략...
 /usr/include/x86_64-linux-gnu/bits/mathcalls-helper-functions.h \
 /usr/include/x86_64-linux-gnu/bits/mathcalls.h
```

* `gccmakedep main.c fx_s15_16.c` 실행시 dependency 파일 자동으로 만들어짐

```bash
$ touch *.h
$ make
cc -c -Wall -g -pg main.c
cc -c -Wall -g -pg fx_s15_16.c
cc main.o fx_s15_16.o -Wall -g -pg -o main
```

* gccmakedep main.c fx_s15_16.c 실행 후에는 실행 전과는 다르게 dependency가 있는 파일을 수정하면 새로 컴파일하는 모습을 볼 수 있다.

```bash
OBJS = main.o fx_s15_16.o
CCFLAGS = -Wall -g -pg
#CCFLAGS = -Wall -O3
main: $(OBJS)
        cc $(OBJS) $(CCFLAGS) -o $@
.c.o:
        cc -c $(CCFLAGS) $<
debug: main.c fx_s15_16.c fx_s15_16.h fx_head.h
        cc -o main_for_debug -pg -g main.c fx_s15_16.c
clean:
        rm main $(OBJS)
# DO NOT DELETE - gccmakedep main.c fx_s15_16.c
```

```bash
$ make debug
cc -o main_for_debug -pg -g main.c fx_s15_16.c
```

* make debug 실행시 디버깅을 위한 컴파일 옵션이 적용되어 컴파일 되고, main_for_debug 라는 실행파일이 생성되도록 할 수 있다. 

### `CMake`  

```cmake
# CMakeLists.txt
project(main)
ADD_EXECUTABLE(main main.c fx_s15_16.c)
```

* main 을 만들기 위해 main.c, fx_s15_16.c 두 파일이 필요하다.

* cmake 파일을 만들기 위해 CMakeLists.txt 파일에 위와 같이 작성하였다.

```bash
$ cmake .
$ make          # main 생성됨
Scanning dependencies of target main
[ 33%] Building C object CMakeFiles/main.dir/main.c.o
[ 66%] Building C object CMakeFiles/main.dir/fx_s15_16.c.o
[100%] Linking C executable main
[100%] Built target main
```

* CMakeFiles, cmake_install.cmake, CMakeLists.txt, makefile도 생성됨
    * main 실행파일 생성되어 실행 가능하다.

```cmake
# 요구 CMake 최소 버전, 2.8 이하에서는 만들지 않는다.
CMAKE_MINIMUM_REQUIRED ( VERSION 2.8 )
 
# 프로젝트 이름 및 버전, 실행파일 안에 버전 정보가 들어간다.
PROJECT ( "andromeda" )
SET ( PROJECT_VERSION_MAJOR 0 )
SET ( PROJECT_VERSION_MINOR 1 )
 
# 빌드 형상(Configuration) 및 Makefile 생성 여부, debug, release
SET ( CMAKE_BUILD_TYPE Debug )
SET ( CMAKE_VERBOSE_MAKEFILE true )         # verbose (주저리주저리)

# 빌드 대상 바이너리 파일명 및 소스 파일 목록
SET ( OUTPUT_ELF
        "${CMAKE_PROJECT_NAME}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.out"
        )
SET ( SRC_FILES
        bar.c
        foo.c
        main.c
        )
 
# 공통 컴파일러, cc, gcc 설정 가능
SET ( CMAKE_C_COMPILER "gcc" )
```

### `project`  

* 정밀도가 높은 integer 곱셈은 어떻게 만들까? (s15.16 기준)

1. 오버플로우가 발생하지 않는 방법

* 32bit를 64bit로 늘려 계산하여 오버플로우가 발생하지 않도록함

```c
fixed fxMul_precision(fixed a, fixed b) 
{
	long long la = a, lb = b, lc;
	lc = la * lb;		// 장점: 오버플로우가 발생하지 않는다.
    lc >>= FX_Q_NUM;    // 2의 -FX_Q_NUM승을 곱한 것과 같다.
	return (fixed) lc;
}
```

* fixed point 뒤에 있는 bit 수 = FX_Q_NUM

초록색 고정 점이 없는 전체 숫자 i 는 integer 값으로 어떻게 계산할까? (크기: 8bit)  

i(a) = (2^7) * (2^bit 값) + ... (2^0) * (2^bit 값)  

R(a) = (2^3) * (2^bit 값) + ... (2^0) * (2^bit 값) 점(.) (2^-1) * (2^bit 값) ... (2^-4) * (2^bit 값)  

-4 => FX_Q_NUM이 4이다.  

Real 값 : **R(a) = ia * (2 ^ -FX_Q_NUM)**  

R(a) = R(b) = ia * (2 ^ -4)라고 가정하고 R(a) * R(b) = R(c) 연산 시에 R(c)는 ia * ib * (2 ^ -8)로 표현되면 안된다.  

R(c) = (ia * ib * (2 ^ -4)) * (2 ^ -4) = R(c)는 ia, ib를 그대로 integer처럼 곱하고 2의 -4승을 곱하면 R(c)를 계산할 수 있다.  

```c
#define FX_Q_NUM_A (FX_Q_NUM - (FX_Q_NUM/2))
#define FX_Q_NUM_B (FX_Q_NUM/2)

fixed fxMul_fair(fixed a, fixed b)
{
	return (a>>FX_Q_NUM) * (b>>FX_Q_NUM_B);
}
```

1. ia * ib * (2의 -8승)  
2. (ia * ib * (2의 -4승)) * (2의 -4승)  
    * 오버플로우 발생 가능성 O
3. (ia * (2의 -2승)) * (ib * (2의 -2승)) * (2의 -4승)
    * 수학적으로는 1, 2, 3 모두 같은 식이지만 3번 연산은 계산 전에 값을 깎아버리는 문제가 발생한다.   
    * 위 코드가 3번 방식과 유사한 방법으로 연산한다.

* 계산 방법의 장단점, 계산 가능한 범위 -> 리포트에 기록하기

```c
//FX_Q_NUM이 8일 때
fixed fxMul_fair(fixed a, fixed b)
{
	return ((a>>4) * (b>>4)) >> 8;
}

fixed fxMul_performance(fixed a, fixed b)
{
	return (a>>8) * (b>>8);
}
```

* 두 함수를 비교했을 때 퍼포먼스 함수가 shift 두번에 곱셈 한번이기 때문에 속도는 퍼포먼스가 더 빠르다.

* 대신 퍼포먼스 합수로 10000 * 0.0001 계산하면 1이 나와야하는데 0이 나온다.

* 어디서부터 언더/오버플로우가 발생하는지, 이 시스템에서 표현할 수 있는 가장 작은, 큰 수가 무엇인지, 가장 작은 차는 무엇인지, 함수를 사용하면 연산이 어떻게 되고 함수마다 어떤 장단점을 보이는지 비교 정리하여 보고서에 기록하기

***


## Lecture 13  

##### - 2022. 01. 25  

### `project`  

* long long 으로 만드는 사람은 특별하게 32bit computing을 고려하지 않아도 된다.
    * 그래도 32bit computer에서 돌아갈 수 있도록 해야함

* 성능 - 곱셈, 나눗셈에서 측정, 정밀도 - overflow (grpof)
    * 그냥, 64bit, 32bit 조건부 컴파일 시 성능 비교
    * 덧셈, 뺄셈, 곱셈, 나눗셈 - 4개씩 존재
    * -max ~ +max = 보고서에 넣어야함
    * (1) (-max * -max ) ~ (+max * +max)
    * (2) (0에서 감소하면서 * -max ) ~ (-max에서 0까지 증가하면서 * -max) 

* (a * b) >> 16 = 오버플로우 발생  

* (a >> 8) * (b >> 8) = 오버플로우는 덜 생기지만 a, b가 작은 숫자일 때 뒤 숫자들이 잘려서 0이 되어버림

* 나의 max 값 : (2 ^ 63 -1)/ (2 ^ 31)

* 나의 min 값 : (2 ^ 63)/ (2 ^ 31)

* resolution 값도 적어야함

* fx_head.h 고칠 경우에는 코멘트 남기기

* 정밀도 성능 분석 시 실험 환경 기록해야함 - CPU 정보, 환경(리눅스 20.04)

* 실행파일, .o 파일은 깃에 올리지 않기

### `System call & Thread`  

* CPU code  
    * ex) Intel i7-980x  
    * cache = CPU 부속 메모리, 상당히 빠른 메모리이다.  
    * core 6개 = CPU가 6개 있는 것과 마찬가지이다.  
        * 3 core씩 같은 shared cache 사용
    * 하나의 job은 하나의 core에서만 실행된다.  
    * processor는 core와 같다.  
    * job이 메모리로 올라가면서 process로 만들어진다. (process = 작업 단위)  

* OS가 실행됨 -> OS의 process들이 실행됨 -> 사람들이 기계에 로그인을 하면 디바이스를 제어하는 tty (terminal) 프로세스 실행되고 -> 로그인에 성공하면 명령어를 실행할 수 있는 shell 이 실행된다.  

* User process 실행 과정
    * a.out는 실행 이전에 파일 형태로 storage에 저장되어 있다. -> 실행시 a.out를 메모리로 가져온다. ->  메모리에 가져온 작업을 process라고 한다.  

* System process
    * OS가 만든 process들은 system process라고 한다.

**Q**) 6 core를 가진 컴퓨터에서 process 2000~3000를 처리하는 방법은?  
> CPU scheduling - 여러 프로세스들을 끊임없이 작업 중일 수 있도록 프로세스의 배분 및 교환을 해주어 처리한다. 

**Q**) Core가 6개면 어떤 프로그램 하나를 6개의 core에서 나누어서 실행할 수 있을까?
> job 하나는 하나의 코어에서 실행되기 때문에 가능하지 않다.

* Context Switching
    * 하나의 프로세스가 CPU를 사용 중인 상태에서 다른 프로세스가 CPU를 사용하도록 하기 위해, 이전의 프로세스의 상태(문맥)를 보관하고 새로운 프로세스의 상태를 올린다.

### `ps`  

* 내가 실행하고 있는 process 를 보는 명령어

```bash
$ ps
  PID TTY          TIME CMD
 5656 pts/12   00:00:00 ps
28047 pts/12   00:00:00 bash
```

### `process의 3가지 상태`  

* run = fg(foreground), bg(background)
* stop(메모리에 올라가있긴 한데 실행 중은 아님)
* kill/idle

* vi 에디터 열면 - vi process 실행 중 `run` -> vi process 를 stop 상태로 바꾸려면 ctrl + z `stop`  

```bash
$ vi test.c         # vi 에디터 실행 중 stop 시킴

[1]+ Stopped            vi test.c
$ ps                
  PID TTY          TIME CMD
 6219 pts/12   00:00:00 vi
 5656 pts/12   00:00:00 ps
28047 pts/12   00:00:00 bash
```

* PPID = parent process  

* ps -al : 모든 process 정보 보여줌

* fg : stopped 된 process 가 다시 running 상태로 돌아간다.

* sleep : 입력한 초만큼 sleep 한다.  

### `어떤 작업을 background로 실행시키는 방법`  

```bash
$ sleep 3 ; echo "wake up 3sec"
# 3초 후에 wake up 3sec 출력 실행
$ (sleep 3 ; echo "wake up 3sec") &
# 3초 후에 wake up 3sec 출력 실행 명령이 background로 실행된다.

$ sleep 100 &
$ sleep 50 &
$ ps -l                 # background로 실행중인 sleep process도 보여준다.
F S   UID   PID  PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  4039  7935 22016  0  80   0 -  2190 hrtime pts/0    00:00:00 sleep
0 S  4039  7964 22016  0  80   0 -  2190 httime pts/0    00:00:00 sleep
0 R  4039  8023 22016  0  80   0 -  7551 -      pts/0    00:00:00 ps
4 S  4039 22016 22015  0  80   0 -  7058 wait   pts/0    00:00:00 bash
$ jobs                  # job id 볼 수 있는 명령어
[1]  Running             sleep 100 &
[2]- Done                sleep 50
[3]+ Running             sleep 3600 &
$ fg %3                 # 3번 job인 sleep 3600 & job을 foreground에서 실행시킨다.
# foreground로 실행중인 작업을 stop 시키고 싶다면 -> 컨트롤 z
$ bg                    # 가장 최근에 관련된 작업을 background에서 실행시킨다.
$ kill %3               # 실행중인 작업을 kill 시킨다. (terminated)
```

**Q**) vi 에디터는 왜 background로 돌지 못할까?  
* 터미널의 기본 입력장치 : stdin, 출력장치 : stdout, stderr  
* background 작업으로 stdout에 이것저것 내보내는 것은 혼잡스럽긴 하지만 작동한다.   
* 반면 vi 에디터는 stdin으로 입력을 받는데, vi 에디터를 background로 실행시키고 bash 작업시 bash도 stdin으로 입력을 받기 때문에 입력이 vi 에디터로 들어가는지, bash로 들어가는지 모르고 알 수 없다.  
* 따라서 stdin 을 받는 작업은 background로 돌 수 없다.  
* stdin은 무조건 foreground 작업으로만 실행시킬 수 있다.  
* background 작업에서 stdin을 받고자 한다면 stdin을 만나는 곳에서 stop된다.  
* scanf를 background에서 작업하고 싶다면 stdin으로 받지 않고, redirection으로 입력 받으면 가능하다.

```bash
$ ./bin             # scanf를 사용하는 프로그램
$ ./bin &
# scanf를 사용하는 프로그램이기 때문에 background로 실행시 바로 stop 된다.
$ ./bin <<< 9988 &
# redirection으로 입력을 받게 하면 background에서 프로그램이 실행될 수 있다.
```

* foreground 작업 죽이는 방법 = ctrl + c

* 0번 process = kernel

### `CPU 개수 및 정보 보는 방법`  

* $ cat /proc/cpuinfo

* webmin에서 CPU 정보, processor 정보 등을 볼 수 있다.

### `Context Switching`  

* 메모리에 여러 작업이 올라와 있고 이를 context switching 하며 실행 중인 상황

* 경우에 따라 메모리가 부족하면 작업을 잠시 disk에 저장했다가 다시 메모리로 가져옴 = swapping
    * disk의 한쪽 영역을 virtual memory로 만든다.

* context switching 시 job을 context switching 중 시간이 많이 걸리면 CPU가 그 동안 다른 작업을 처리해 job의 starvation이 때문에 오버헤드가 발생한다.   
    * 따라서 thread가 등장하게 됨

### `Thread`  

* context switching 을 빠르게 수행하도록 core를 논리적으로 나눈 것 = Thread  

* OS 입장에서 실제로 core가 4개 밖에 없지만 thread로 인해 processor가 8개 존재한다고 생각하고 작업을 수행할 수 있다. 

* vi 에디터를 실행중 다른 명령어를 수행하고 싶을 때 사용하는 방법 두 가지  
    1. vi 에디터를 stopped 시키고 (ctrl + z) 명령어 수행 후 foreground 로 실행 (fg)
    2. vi 에디터 화면에서 `:! 명령어` 실행

* :!ls = vi 에디터에서 잠시 ls 명령어 사용하고 싶을 때

* :r output.txt = vi 에디터에서 파일을 읽고 싶을 때

* :r!ls = ls 명령의 결과를 읽어옴

* :w -> :!cc test.c -> :!./a.out = 파일 저장 -> 컴파일 > 실행 수행

* :w -> :!cc test.c ; ./a.out = 파일 저장 -> 컴파일과 실행까지 수행

### `system - system call`  

```c
#include <stdlib.h>
int system(const char *command);
// 실행 결과 int로 저장되어 볼 수 있다. ($?)       
execl("/bin/sh", "sh", "-c", command, (char *) 0);
//두 함수 모두 system call 실행하는 기능이다.

//test 예시
#include <stdio.h>
#include <stdlib.h>

int main()
{
        printf("System Call: %d\n", system("ls -li"));
}
//실행 시 ls -li 명령어가 실행된다.
//return 값을 출력해보면 0으로 출력됨
```

```bash
$ ./a.out
total 20
31327658 -rwxr-xr-x 1 pcc001 pcc 8344  1월 25 15:19 a.out
31327640 -rw-r--r-- 1 pcc001 pcc    6  1월 25 15:10 output.txt
31327679 -rw-r--r-- 1 pcc001 pcc  103  1월 25 15:19 test.c
System Call: 0
```

* ls -li 명령어가 정상적으로 실행되었기 때문에 return 값이 0이다.

```bash
$ ./a.out          # system("ls -li zzz") + main에 return 100 추가
ls: cannot access 'zzz': No such file or directory
System Call: 512

$ echo $?
100
```

* system("ls -li zzz") 실행 시 오류가 나기 때문에 return 되는 int 값이 512이다.  

* main 함수 안에 return 100을 했기 때문에 $? 를 출력하면 100이 나온다.

```bash
$ ls -l zzz test.c                                 # 1
ls: cannot access 'zzz': No such file or directory
-rw-r--r-- 1 pcc001 pcc 120  1월 25 15:20 test.c

$ ls -l zzz test.c > lsout.txt                      # 2
ls: cannot access 'zzz': No such file or directory
$ cat lsout.txt
-rw-r--r-- 1 pcc001 pcc 120  1월 25 15:20 test.c

$ ls -l zzz test.c 2> lserr.txt                     # 3
-rw-r--r-- 1 pcc001 pcc 120  1월 25 15:20 test.c
$ cat lserr.txt
ls: cannot access 'zzz': No such file or directory

$ ls -l zzz test.c 1> lsout.txt 2> lserr.txt         #4

$ ls -l zzz test.c &> lsoutierr.txt                  # 5
$ cat lsoutierr.txt
ls: cannot access 'zzz': No such file or directory
-rw-r--r-- 1 pcc001 pcc 120  1월 25 15:20 test.c
```

1. ls -l 실행 시 에러와 정상적으로 실행된 내용을 둘 다 보여준다.  

2. stdout은 txt 파일에 저장되고 stderr 은 터미널에 출력된다.

3. stdout은 터미널에 출력되고 stderr 은 txt 파일에 저장된다.

4. stdout은 lsout.txt 파일에, stderr은 lserr.txt 파일에 저장된다.

5. stdout과 stderr이 함께 lsoutierr.txt 파일에 저장된다.

### `popen`  

* pipe open 함수 - 실행시킨 명령어의 표준입력 / 표준출력을 주고 받기 위한 용도로 사용한다.
    * input / output pipe 를 open 하기 위한 용도로 사용한다.

* parameter
    * command : 실행할 명령어
    * type
        * "r" : 명령어를 실행하면 명령어가 표준 출력으로 출력한 문자열을 읽기 위한 용도로 파이프를 오픈한다.
        * "w" : 명령어를 실행 후 사용자가 키보드로 데이터를 입력해야 하는 명령에 사용한다. 즉 command의 표준입력으로 데이터를 전송하기 위한 파이프를 오픈한다.

```c
#include <stdio.h>

FILE *popen(const char *command, const char *type);
```

```bash
$ sh -c "ls -li"        # 1
$ ls -li                # 2
```

1. shell을 실행한 뒤 ls -li 실행 후 빠져나옴  
    * sh -> ls -li -> exit

2. 그냥 바로 ls -li 실행

### `fork`  

* fork는 실행 중인 프로세스의 복사본 프로세스를 생성하는 함수이다.

```c
//fork를 사용하기 위한 헤더파일과 fork 함수
#include <sys/types.h>
#include <unistd.h>
pid_t fork(void);

#define _GNU_SOURCE
#include <sched.h>
long clone(unsigned long flags, void *child_stack, int *ptid, int *ctid, unsigned long newtls);
```

* a.out 실행하다가 fork를 만나면 다른 메모리에 a.out가 똑같이 복사가 되어 실행된다.  

* fork 시 pid type (process id)가 다르게 생성된다.
    * 이를 통해 process id 에 따라 다른 일을 수행하도록 할 수 있다.

```c
//forktest.c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
        int a = 0;
        pid_t pid;
        pid = fork();
        for (int i = 0; i < 100; i++)
        {
                sleep(1) ;
                printf("PID %d A=%d i=%d : \n", pid, a++, i);
        }
}
```

* sleep 명령어도 있지만,sleep 이라고 하는 system call (library)도 있다.
    * :!man printf = user command
    * :!man 3 printf = system 함수 (linux programmer's manual)
    * :!man sleep = user command (명령어)
    * :!man 3 sleep = system 함수
        * #include <unistd.h>
        * unsigned int sleep(unsigned int seconds);
        * 입력한 초만큼 sleep 하는 함수

```bash
# forktest.c 실행 결과
PID 24515 : A=0 : i=0 :
PID 0 : A=0 : i=0 :
PID 24515 : A=1 : i=1 :
PID 0 : A=1 : i=1 :
PID 24515 : A=2 : i=2 :
PID 0 : A=2 : i=2 :
PID 24515 : A=3 : i=3 :
PID 0 : A=3 : i=3 :
PID 24515 : A=4 : i=4 :
PID 0 : A=4 : i=4 :
PID 24515 : A=5 : i=5 :
PID 0 : A=5 : i=5 :
# 생략...

$ a.out &
$ ps
  PID TTY          TIME CMD
24514 pts/12   00:00:00 a.out
24515 pts/12   00:00:00 a.out
24562 pts/12   00:00:00 ps
28047 pts/12   00:00:00 bash
```

* 실행 시 fork 되어 서로 다른 PID를 가진 프로세스가 실행되는 모습을 볼 수 있다.

* fork는 context 전체가 메모리에 복제된다. 따라서 다른 프로세스(PID 24515)에서 A 값을 수정해도 이 프로세스(PID 0)에는 영향을 주지 않는다.

* 실행 중 ps 명령어로 프로세스를 살펴보면 a.out가 두 개 실행된다.

* 프로그램 실행 중 `kill -9 PID` 명령어 실행하면 프로세스 하나가 죽는다.

### `PID에 따라 다른 작업 수행하도록 하기`  

```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
        int a = 0;
        pid_t pid ,pid2;
        pid = fork();
        for (int i = 0; i < 100; i++)
        {
                sleep(1);
                if (pid == 0)
                        printf("PID %d : A=%d : i=%d : \n", pid, a++, i);
                else
                        printf("PID %d : A=%d : i=%d : \n", pid, a--, i);
        }
}
```

* pid가 0인 프로세스는 a 값을 증가시킨다.  

* pid가 0이 아닌 프로세스는 a 값을 감소시킨다.

```bash
# 실행 결과
PID 25453 : A=0 : i=0 :
PID 0 : A=0 : i=0 :
PID 25453 : A=-1 : i=1 :
PID 0 : A=1 : i=1 :
PID 25453 : A=-2 : i=2 :
PID 0 : A=2 : i=2 :
PID 25453 : A=-3 : i=3 :
PID 0 : A=3 : i=3 :
PID 25453 : A=-4 : i=4 :
PID 0 : A=4 : i=4 :
PID 25453 : A=-5 : i=5 :
PID 0 : A=5 : i=5 :
```

### `두 번 fork 하기`  

```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int a = 0;
	pid_t pid ,pid2;
    pid = fork();
	pid2 = fork();
	for (int i = 0; i < 100; i++)
	{
		sleep(1);
		printf("PID %d : PID2 %d : A=%d : i=%d : \n", pid, pid2, a++, i);
	}
}
```

**Q**) a.out & 실행 시 프로세스가 총 몇 개 생길까요?
> 아래 실행 결과 참고

```bash
# 실행 결과
  PID TTY          TIME CMD
24668 pts/4    00:00:00 bash
26223 pts/4    00:00:00 a.out
26224 pts/4    00:00:00 a.out
26225 pts/4    00:00:00 a.out
26226 pts/4    00:00:00 a.out
26243 pts/4    00:00:00 ps
```

* 프로세스가 총 4개 생성된다. main을 실행하던 중 첫번째 fork를 만나 프로세스가 두 개가 된다. -> 두 프로세스가 진행 중 두번째 fork 를 만나 각각 fork 되어 총 4개의 프로세스가 생성되는 것이다.

### `Thread`  

* core vs Thread
    * core는 실제 하드웨어적으로 존재하지만, thread는 가상의 logical한 실행 흐름 단위이다.
    * thread는 여러 CPU에서 실행될 수 있다.

<div style="text-align : center;">
    <img src=./img/corethread.png width="70%"/>  
</div>

* 위 그림처럼 하나의 process에 속하는 하나의 thread가 하나의 core에서 실행된다.  

* 또는 하나의 process에 속하는 여러 threads가 여러 core에서, 여러 processor에서 실행될 수 있다. (운영체제가 작업을 assign 한다.)

### `thread vs pthread`  

* thread.h (C11 - 2011년 버전)  
    * windows

```c
#include <threads.h>
#include <stdio.h>

int run(void *arg)
{
    printf("Hello world of C11 threads.");
    return 0;
}

int main(int argc, const char *argv[])
{
    thrd_t thread;
    int result;
    thrd_create(&thread, run, NULL);
    thrd_join(&thread, &result);
    printf("Thread return %d at the end\n", result);
}
```

* pthread.h (POSIX)  

```c
#include <pthread.h>
#include <stdio.h>

void *run (void *arg)       //void * = 함수의 포인터
{
    printf("Hello world of POSXI threads.");
    return 0;

}

int main()
{
	pthread_t thread;
	int result; 
	pthread_create(&thread, NULL, run, NULL );
	pthread_join(thread, &result);          //thread 끝날 때까지 기다림
	printf("Thread return %d at the end\n", result);
}
```

* thread와 pthread에서 thread type, thread_create() 함수의 parameter 등 조금씩 다른 점이 있다.

### `pthread.h API`  

```c
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);
//생성 함수 start_routine을 실행

void pthread_exit(void *retval);
//호출하는 스레드를 종료한다.

int pthread_join(pthread_t thread, void **retval);
//Synchronization을 구현하고 싶다면 호출
//pthread_join은 스레드를 생성했던 thread를 끝날때까지 기다려준다. 
//만약 thread가 이미 종료되었다면 즉시 리턴한다.

void pthread_cancel(pthread_t thread);
//스레드에게 취소 요청을 보낸다.

pthread_t pthread_self(void);
//현재 스레드의 id를 출력한다.

int pthread_equal(pthread_t t1, pthread_t t2);
//두 스레드가 같은 스레드인지 id를 비교한다.
```

### `pthread 사용 프로그램`  

```c
//threadtest.c - pthread 사용
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int bbb = 0; 

void fn_s()
{
    static int a = 0; 
    printf("== %d %d ==",a++, bbb++);
}


void *run (void *arg)
{
    printf("Hello world of POSIX threads.%d\n", (int)(0) );
    for (int i = 0; i < 10; i++)
	{
		sleep(1); 
		fn_s(); 
	}
    return 0;

}

int main()
{
	char bufff[10];
    	setvbuf(stdout, bufff,  _IOFBF,  10);
	//pthread_t thread1;
	int result1;
	//pthread_create(&thread1, NULL, run, NULL );
	run((void *) 0); 
	//pthread_join(thread1, (void **) &result1);
	printf("Thread return %d at the end\n", result1);
}
```

* cc threadtest.c -lpthread : pthread 라이브러리를 포함해서 컴파일

**Q**) 왜 a.out가 작동하지 않는 것일까?
> Hint: 버퍼 (혼자 추측해보기.. 다음 시간에 설명)  

***

## Lecture 14  

##### - 2022. 01. 26   

### `Unix, linux 역사`  

* digital -> pdp 11 -> c언어 등장

* 이 당시 사용하던 OS : VMS, unix

* Unix = AT&T 가 개발 (Bell lab)

* Unix 이후 개발된 OS, unix 계열 OS
    * bsd -> ios 
    * XINU
    * GNU (GNU is Not Unix)
    * linux (리누스 토발즈가 개발)

* 이러한 여러 unix 계열 OS가 각각 다르게 개발됨 -> 표준화를 위해 POSIX 등장
    * IEEE -> POSIX로 표준화 함

### `sleep 사용 프로그램`  

```c
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int bbb = 0;

void fn_s()
{
    static int a = 0;
    printf("== %d %d ==",a++, bbb++);
}


void *run (void *arg)
{
    printf("Hello world of POSIX threads.%d\n", (int)(0) );
    for (int i = 0; i < 100; i++)
        {
                sleep(1);
                fn_s();
        }
    return 0;

}

int main()
{
    int result1;
    run((void *) 0);
    printf("Thread return %d at the end\n", result1);
}
```

* 실행 시 Hello world of POSIX threads.0 만 출력되고 실행이 안되는 문제 발생

**이는 실행이 안되는 것이 아니라, 터미널에 출력되지 않을 뿐 100초 뒤에 아래와 같은 출력 결과를 얻을 수 있었다.**

```bash
$ a.out
Hello world of POSIX threads.0
== 0 0 ==== 1 1 ==== 2 2 ==== 3 3 ==== 4 4 ==== 5 5 ==== 6 6 ==== 7 7 ==== 8 8 ==== 9 9 ==== 10 10 ==== 11 11 ==== 12 12 ==== 13 13 ==== 14 14 ==== 15 15 ==== 16 16 ==== 17 17 ==== 18 18 ==== 19 19 ==== 20 20 ==== 21 21 ==== 22 22 ==== 23 23 ==== 24 24 ==== 25 25 ==== 26 26 ==== 27 27 ==== 28 28 ==== 29 29 ==== 30 30 ==== 31 31 ==== 32 32 ==== 33 33 ==== 34 34 ==== 35 35 ==== 36 36 ==== 37 37 ==== 38 38 ==== 39 39 ==== 40 40 ==== 41 41 ==== 42 42 ==== 43 43 ==== 44 44 ==== 45 45 ==== 46 46 ==== 47 47 ==== 48 48 ==== 49 49 ==== 50 50 ==== 51 51 ==== 52 52 ==== 53 53 ==== 54 54 ==== 55 55 ==== 56 56 ==== 57 57 ==== 58 58 ==== 59 59 ==== 60 60 ==== 61 61 ==== 62 62 ==== 63 63 ==== 64 64 ==== 65 65 ==== 66 66 ==== 67 67 ==== 68 68 ==== 69 69 ==== 70 70 ==== 71 71 ==== 72 72 ==== 73 73 ==== 74 74 ==== 75 75 ==== 76 76 ==== 77 77 ==== 78 78 ==== 79 79 ==== 80 80 ==== 81 81 ==== 82 82 ==== 83 83 ==== 84 84 ==== 85 85 ==== 86 86 ==== 87 87 ==== 88 88 ==== 89 89 ==== 90 90 ==== 91 91 ==== 92 92 ==== 93 93 ==== 94 94 ==== 95 95 ==== 96 96 ==== 97 97 ==== 98 98 ==== 99 99 ==Thread return 0 at the end
```

* 이를 해결하는 방법으로 아래 printf 코드와 같이 출력문 뒤에 \n을 추가하는 것이 있었다.

```c
printf("== %d %d ==",a++, bbb++);
printf("== %d %d ==\n",a++, bbb++);        // \n 추가 후
```

* \n 이 있으면 1초마다 출력되며, 한줄씩 줄 바꿈이 일어났다.
* \n이 없으면 100초 후 한꺼번에 출력되며, 줄바꿈이 일어나지 않았다.

### `buffer`  

1. CPU가 메모리에 있는 프로그램 실행해서 출력 장치인 terminal hello world를 출력하도록 하였다. (terminal은 character device이다.)

2. 그런데 terminal에 character 글자 하나씩 출력하게 하면 CPU가 비효율적으로 사용된다.  

3. CPU > Memory > Storage > I/O 순서대로 속도가 느려졌기 때문에 terminal이 한글자씩 출력하면 CPU는 그 동안 일을 하지 않고 놀게 되며 이 때문에 비효율적이다.  

4. 따라서 CPU를 효율적으로 사용하기 위해 CPU보다는 느리지만 출력 장치보다는 빠른 메모리의 버퍼에 저장해둔다. (input buffer, output buffer, stdin, stdout, stderr)

5. 버퍼가 작동하는 원리에 3가지 모드가 있다. 
    1. buffer full mode = 버퍼가 꽉 차면 buffer full signal을 보내고, 이때 버퍼 안의 내용을 가져간다.
    2. line by line mode = \n을 만나면 한 줄이 들어갔다고 인식하고 한 줄씩 내보낸다.
    3. character by character mode = 한 글자씩 가져간다. (buffer size 0/1, zero 버퍼와 같다.)

**우리 시스템의 default mode는 line by line mode이다.**  

따라서 lec14의 맨 위 코드를 실행했을 때 바로 출력되지 않았지만 \n을 추가한 코드는 1초마다 바로 출력되었던 이유도 이 시스템이 기본으로 line by line mode를 따르기 때문에 \n을 만났을 때 터미널에 출력하였다.  

### `첫 번째 방법 - 명령어 stdbuf`

```bash
$ man stdbuf                    # 표준 버퍼
$ stdbuf --out=0 a.out          #no buffer - 1초마다 나옴
```

* buffer size를 0으로 만들어 no buffer 상태에서 a.out를 실행한다.  

* CPU 성능은 비효율적이지만 결과가 바로 출력된다.

### `두 번째 - program 내에서 buffer control`

```c
void fn_s()
{
    char bufff[10];
    static int a = 0;
    setvbuf(stdout, bufff,  _IOFBF,  10);
    //출력 버퍼의 크기를 10으로 설정s
    printf("== %d %d ==",a++, bbb++);
}
```

* _IONBF : no buffered
* _IOLBF : line buffered
* _IOFBF : fully buffered

* setvbuf 함수를 통해 출력 버퍼를 fully buffered, 크기를 10바이트로 설정하였다.

```bash
$ a.out
Hello world of POSIX threads.0
== <�0 ==== <�1 ==== <�2 ==== <�3 ==== <�4 ==== <�5 ==== <�6 ==== <�7 ==== <�8 ==== 9 9 ==Thread return 0 at the end
```

* 글자가 깨지긴 하지만 출력이 바로바로 나온다.  

* _IONBF로 no buffer를 사용하면 출력이 바로바로 나온다.

```c
//main에 추가
int main()
{
        char bufff[10];
        setvbuf(stdout, bufff,  _IOFBF,  10);
```

* 위 코드에서 for 루프에서 fn_s() 함수가 호출될 때마다 setvbuf 하지말고 main에서 한번만 버퍼를 컨트롤 하도록 수정하였다.

```bash
$ a.out
Hello world of POSIX threads.0
== 0 0 ==== 1 1 ==== 2 2 ==== 3 3 ==== 4 4 ==== 5 5 ==== 6 6 ==== 7 7 ==== 8 8 ==== 9 9 ==Thread return 750253696 at the end
```

* setvbuf를 통해 바로바로 출력되도록 버퍼 컨트롤 할 수 있다!

### `line by line`  

```bash
$ stdbuf --output=L a.out
```

* L 옵션으로 line by line mode로 변경하여 a.out를 실행하였다.

* 현재 a.out에는 setvbuf가 있지만 명령어로 실행할 때에는 line by line mode로 설정한 상황

**실행 결과로 line by line mode가 적용되지 않고 a.out 프로그램 내의 setvbuf로 인해 1초마다 출력되었다.**

### `fflush`  

* fflush 함수 = flush a stream

```c
void fn_s()
{
    static int a = 0;
    printf("== %d %d ==",a++, bbb++);
    fflush();
}
```

* fflush 함수를 사용해서 a.out 실행 시 출력이 1초마다 나오는 것을 볼 수 있다. (강제로 flush)

### `scanf & printf warning`  

```c
//prtest.c
#include <stdio.h>

int main()
{
	char a;
	short b;
	int c;
	long long d;

	scanf("%d %d %d %d", &a, &b, &c, &d);
	printf("%d %d %d %d\n", a, b, c, d);
}
```

* 4개의 변수 모두 자료형이 다르지만 scanf 와 printf 함수에서 %d로 입력받고 출력하였다.

* 컴파일 시 warning 발생

```bash
# 위 코드를 컴파일 하고 a.out 실행
$ a.out
255 2000 4000 5000
-1 2000 4000 5000

$ a.out
8000 8000 8000 8000
64 8000 8000 8000
```

* 예상과는 다르게 8000이 -가 아니라 64 값으로 이상한 값이 나왔다.

* 경우에 따라서는 어떤 시스템에서 계속 문제를 일으키게 된다.  

* warning을 살펴보면 char * 타입을 위해 %d 대신 %hhd를 사용하도록, short int * 타입을 위해 %d 대신 %hd를 사용하도록 등 맞지 않는 부분을 수정하도록 알려주고 있다.
    * 아래 코드는 warning에 따라 수정한 코드이다.

```c
#include <stdio.h>

int main()
{
        char a;
        short b;
        int c;
        long long d;

        scanf("%hhd %hd %d %lld", &a, &b, &c, &d);
        printf("%hhd %hd %d %lld\n", a, b, c, d);
}
```

* a.out 실행 시 자료형에 맞춰 masking 후 정상적으로 출력된 결과를 볼 수 있었다.

### `pthread 테스트 코드`  

```c
//threadtest.c
#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int bbb = 0;

void fn_s()
{
    static int a = 0;
    printf("<== %d %d ==>",a++, bbb++);
    fflush(stdout);
}


void *run (void *arg)
{
    printf("Hello world of POSIX threads.%d\n", (int) pthread_self() );
    for (int i = 0; i < 100; i++)
        {
                usleep(10000);
                fn_s();
        }
    return 0;

}

int main()
{
        pthread_t thread1;
        int result1;

        pthread_create(&thread1, NULL, run, NULL );
        printf("JUST AFTER THR Create\n");
        run((void *) 0);
        pthread_join(thread1, (void **) &result1);
        printf("\nThread return %d at the end\n", result1);
}
```

* cc threadtest.c -lpthread (라이브러리 붙여 컴파일 해야함)

**Q**) JUST AFTER THR Create 출력은 aaa bbb 100개 출력 뒤에 나올까 아니면 바로 출력이 나올까?  
> JUST AFTER THR Create이 바로 출력된다.  
그리고 0부터 199까지 aaa와 bbb가 증가하여 출력되었다. -> Asynchronous execution  

* fork 와 다른 점으로 global variable이나 static variable을 두 thread가 공유하고 있기 때문에 같이 증가시켜서 99까지 출력되는 것이 아니라 199까지 출력되는 결과를 얻을 수 있었다.

### `Asynchronous execution`  

* Asynchronous execution = 비동기적 실행

* 동기적 실행은 하나가 끝나면 그 다음 것을 순차적으로 실행하는 것이다.

* pthread_create가 아닌 상태에서 실행 시에는 run 함수가 끝날 때까지 기다리고 그 다음 것을 실행하였다. (동기적 실행)  

* 하지만 비동기식 실행에서는 pthread_create에서 생성된 thread, 즉 새로운 process가 run을 실행하고 원래 실행 중이던 thread가 run이 끝날 때까지 기다리지 않고, 바로 JUST AFTER THR Create 를 출력하였다.  

### `동기화 문제 발생 프로그램`  

```c
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

int bbb = 0; 

void fn_s()
{
    static int a = 0;
    printf("<== %d %d ==>",a++, bbb++);
    fflush(stdout);
}


void *run (void *arg)
{
    printf("Hello world of POSXI threads.%d\n", (int) pthread_self() );
    for (int i = 0; i < 1000; i++)
	{
		//usleep(10000); 
		fn_s(); 
	}
    return 0;

}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;
	int result1, result2, result3;

	pthread_create(&thread1, NULL, run, NULL );
	pthread_create(&thread2, NULL, run, NULL );
	pthread_create(&thread3, NULL, run, NULL );
	run((void *) 0); 
	pthread_join(thread1, (void **) &result1);
	pthread_join(thread2, (void **) &result2);
	pthread_join(thread3, (void **) &result3);
	printf("\nThread return %d at the end\n", result1);
}
```

* usleep 사용 유무에 따른 차이점
    * usleep 사용 X = 출력 마지막 aaa, bbb 값이 3976, 3977
    * uslepp 사용 O = 출력 마지막 aaa, bbb 값이 3995, 3995

* a++ 명령은 메모리의 a주소에서 a 값을 레지스터에 load 해오고 레지스터에 1을 더하고 a의 메모리 주소에 그 값을 저장한다.

* thread를 여러개 create 했기 때문에 어떤 thread에서는 300 값을 읽고 1 더하는 중인데 301을 store 하기 전 다른 thread 도 같은 값을 읽고 1을 더해서 301을 store하고, 이후에 먼저 읽었던 thread에서도 301을 저장하는 경우가 발행한다. 그럼 302가 되어야하는데 301이 저장되는 `동기화` 문제가 발생한다.  
    * 따라서 위 출력도 aaa와 bbb 값이 서로 다르거나 3999가 아닌 이유도 동기화 문제가 발생했기 때문이다.

* 동기화 문제 해결 방법 : 내가 쓰는 자원을 다른 thread가 건들이지 않는 mutual exclusion을 사용한다.
    * mutual exclusion == mutex

### `Mutex`  

* mutex는 하나의 thread가 자원을 사용하는 동안 다른 thread가 자원에 접근하거나 사용하지 못하도록 하는 방법이다.

```c
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

//example
pthread_mutex_lock(&mutex);
count++;
pthread_mutex_unlock(&mutex);
```

* mutex를 사용하여 위 threadtest.c 코드를 수정하였다.

```c
void fn_s()
{
	static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    static int a = 0; 
    printf("<= %d %d =>",a, bbb);
    pthread_mutex_lock(&mutex);
	a++; bbb++;
    pthread_mutex_unlock(&mutex);
}
```

* aaa와 bbb의 값을 변경시키는 함수인 fn_s() 함수에서 mutex를 선언하였다.  

* aaa와 bbb의 값을 변경시킬 때 다른 thread 가 이 자원을 동시에 건들이지 않도록 lock을 잡고 aaa와 bbb를 수정한 뒤 저장한 이후에 lock 을 해제해도록 하였다.

**실행 결과 하나의 thread만 aaa와 bbb 자원의 lock을 잡고 수정하였기 때문에 마지막 출력 결과가 3999임을 확인할 수 있었다.**

* (project) I/O 디바이스를 사용하는 것은 좋은 profiling이 아니다.
    * 퍼포먼스를 정확하게 측정하기 위해 `a.out > /dev/null` 로 I/O를 날려서 실행하기

***
