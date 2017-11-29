# Wonkwang-UNIV.-Visual-C
---
![원광대](https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&cad=rja&uact=8&ved=0ahUKEwi4kY_eruPXAhUFl5QKHQfiBO0QjRwIBw&url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3DotOqGFPLg7M&psig=AOvVaw1WkGAtQr6bU5I3p1kaBqyx&ust=1512029179196654)

Wonkwang Univ.Visual C Programming Source Code

Wonkwang University : <http://www.wku.ac.kr>

Wonkwang University Dept. of Computer Engineering : <http://computer.wku.ac.kr>

---
##C언어의 역사 및 구조
>
* 이기종 컴퓨터간의 호환성을 가질수 있을정도로 **<span style="color : red">고급언어**이면서, 기능면에서 어셈블리언어처럼 컴퓨터의 **<span style="color : red">하드웨어 기능까지 제어**할수 있는 새로운 프로그래밍언어가 필요.</br>
->1972년 벨(Bell)연구소의 **_Dennis Ritch_** 에 의해 개발.</br>
->**UNIX**운영체제의 구현을 위해 사용.<br></br>
* **고급언어이자 저급언어로 시스템프로그래밍도 가능**=>**<span style="color : red">중급언어**
 * 저급언어 : 컴퓨터가 실행하는 실제의 명령(기호형태)을 다룸
 * 고급언어 : 여러가지 제어구조와 I/O명령문 등을 제공(프로그래밍이 쉽고 빠르다)
 * **<span style="color : red">함수(function)**의 집합으로 구성되어 **<span style="color : red">구조적 프로그램**에 적합
 * 다양한 **<span style="color : red">자료구조의 표현에 적합**
 * 다른시스템의 **<span style="color : red">이식성**이 좋다.
 * 입출력 문장이 따로 존재하지않음(**<span style="color : red">library함수 이용**)

![구조적프로그래밍](https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&cad=rja&uact=8&ved=0ahUKEwiMnObrr-PXAhUFFZQKHT-wAY8QjRwIBw&url=http%3A%2F%2Fblog.daum.net%2F_blog%2FBlogTypeView.do%3Fblogid%3D0ToMF%26articleno%3D668%26_bloghome_menu%3Drecenttext&psig=AOvVaw3jqW-RVM9P-3tS7ZJY8NRn&ust=1512030804174320)
<br>[출처:[Daum](http://blog.daum.net/_blog/BlogTypeView.do?blogid=0ToMF&articleno=668&_bloghome_menu=recenttext)]</br>

##구조적 프로그래밍
>
* 큰 규묘의 프로그램은 **일관성**을 갖는 기능에 따라 여러개의 **작은 단위 프로그램**으로 나누어 작성하는 것이 프로그램에 개발과 관리, 그리고 프로그램에 대한 이해를 쉽게 해준다.
* 프로그램의 처리는 하나의 주(**main**)프로그램이 필요한 시점에서 **기능별(Functional)단위 프로그램들을 호출하여 원하는 처리**를 하는 방법으로 진행.
* **<span style="color : red">구조적 프로그래밍(Structured programming)**은 이와같은 방법으로 **<span style="color : red">순서구조, 조건구조 및 반복구조**만으로 프로그램을 작성
<br></br>

##객체지향 프로그래밍	
>
*  하드웨어의 부품처럼 **재사용**이 가능하고 **유지보수**가 편리
*  프로그램 기술방식이 인가의 사고 체계를 그대로 묘사할 수 있도록 변화
*  프로그래머는 이미 만들어져 있는 **객체(Object)의 내부는 알지 못하고** 그 객체가 수항할 수 있는 **기능만을 인지**한 상태에서 문제 해결에 필요한 메세지를 해당 객체에 전달
*  해당 객체는 자신의 기능만으로 해결하지 못하는 부분에 대해서는 **메세지 전달**을 통해 다른 객체에 의해서 해결될 수 있도록 함<br>
<p>
## C 프로그램의 구조

 ![C언어](https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&cad=rja&uact=8&ved=0ahUKEwjgpdy_sOPXAhUQOrwKHdJrBn0QjRwIBw&url=http%3A%2F%2Fic.bu.ac.kr%2Fmediawiki%2Findex.php%2FC%25EC%2596%25B8%25EC%2596%25B4%25EC%259D%2598_%25EA%25B5%25AC%25EC%2584%25B1&psig=AOvVaw3qU6G6Z0imO1DZCmRmy815&ust=1512030980650639)

[출처:[ic.bu.ac.kr](http://ic.bu.ac.kr/mediawiki/index.php/C%EC%96%B8%EC%96%B4%EC%9D%98_%EA%B5%AC%EC%84%B1)]
<p>

##실행파일
	* *컴파일, 랭킹 과정을 통해 생성
	* 운영체제의 로더(loader)가 메모리에 적재
	* 하나의 프로세스 주소공간을 갖음
	* 하나의 프로세스 주소공간을 갖음
		* 스택(Stack)세그먼트
		* 힙(Heap)
		* 데이터 세그먼트
		* 텍스트
	* CPU가 해당 메모리 주소공간을 읽고 수행함 

* 코드 에디터
	* 프로그램을 작성하는 과정에서 사용하는 편집기
	* 단축키, 실행취소/재실행, 매크로, 맞춤법 검사 외에 각 에디터마다 특징이 있음
	* Emacs,Ultra Editor, Eclipse, Crimson Editor Etc.
* 통합개발환경**<span style="color : green">(Integrated Development Environment : IDLE )** 
	* 컴퓨터를 이용해	Application을 개발하는 과정에서 **<span style="color : red">에디터,<span style="color : green"> 컴파일러, <span style="color : yellow">어셈블리어,<span style ="color : orange"> 링크,<span style ="color : blue"> 디버그**등의 각각의 단계가 모두 하나의 프로그램 안에 통합 되어있는 것

이곳에서 **Visual Studio 2017 Community**를 받을수 있다.<br></br>
[![visualStudoi2017](https://www.google.com/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&cad=rja&uact=8&ved=0ahUKEwjk8cKLtePXAhWBoZQKHdGbAoAQjRwIBw&url=https%3A%2F%2Fwww.iconfinder.com%2Ficons%2F98775%2F2012_studio_visual_icon&psig=AOvVaw14nRSBOS0uEQrXx38PYaBi&ust=1512032205011584)](https://www.visualstudio.com/ko/downloads/)<br>

