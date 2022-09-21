/*
MADE BY RASBI A.K.A 그날본 카드의 이름
EASY APP DISABLE TOOL = EASY ADT
VER 0.1 release
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	 
	// 메뉴 번호 저장용 변수
	int MenuNum = 0;

	// 패키지명 저장용 변수
	char AppName[100] = {97, };

	//명령어 조합용 변수
	char cmd[100] = { 97, };

	//비활성화 y/n 변수
	char Ok = 'a';

	//삭제한 앱 확인용 변수
	char Sucess[100] = {97, };

	//삭제 로그 txt 파일 기록용 포인터 
	FILE *file = nullptr;

	//삭제 로그 기록용 변수
	char save[100] = { 97, };

	//삭제 로그 불러오기용 변수
	char DeleteLogOpen[CHAR_MAX] = { 97, };


MainMenu: //goto 문
	system("cls");
	printf("///EASY App Disable TOOL = EASY ADT VER 0.1 release///\n");
	printf("------------------------------------------------------\n");
	printf("원하시는 메뉴를 선택해주세요.\n");
	printf("------------------------------------------------------\n");
	printf("1. 앱 비활성화하기 \n2. 삭제한 앱 확인 \n3. 도움말 \n4. 종료\n");
	printf("------------------------------------------------------\n");
	printf("번호 입력:");
	
	//scanf_s로 메뉴 번호 입력 받아 MenuNum에 저장
	scanf_s("%d", &MenuNum); //scanf_s 함수는 %s 와 같은 문자열 파라미터에만 버퍼 사이즈를 넘기게 되어있다. 뒤에 sizeof 안써도 됨


	//앱 비활성화의 경우
Menu1: //goto 문 

	if (MenuNum == 1) 
	{
		printf("------------------------------------------------------\n");
		system("adb devices"); // adb 서버 시작
		system("cls"); // 콘솔 화면 초기화
		printf("------------------------------------------------------\n");
		system("adb shell pm list packages"); //앱 리스트 불러오기
		printf("------------------------------------------------------\n");
		printf("1. 앱 리스트 불러오기 완료. 삭제하고 싶은 앱을 확인해주세요.\n");
		printf("2. 누락된 패키지가 있다면 별도의 패키지 명을 확인할 수 있는 앱을 통해서 확인해야됩니다.\n");
		printf("------------------------------------------------------\n");
		printf("패키지 이름을 복사 / 우클릭으로 붙여넣기 후 엔터(com. 으로 시작):");
		scanf_s("%s", AppName, (int)sizeof(AppName)); //패키지명 저장, 64비트는 이상하게 에러가 나서 int형으로 32비트로 지정

		printf("------------------------------------------------------\n");
		printf("선택한 패키지 :%s\n", AppName);
		printf("비활성화를 계속하려면 y 입력 후 엔터(y/n):");
		scanf_s(" %c", &Ok, 1); //입력 버퍼 문제로 %c 앞에 한칸 띄어 놓음

		if (Ok == 'n') //사용자가 취소 시
		{

			system("cls");
			goto Menu1;
		}

		system("cls");
		sprintf_s(cmd, "adb shell pm uninstall -k --user 0 %s", AppName); //sprintf 함수로 명령어 조합후 system으로 넘겨준다.
		system(cmd); //선택한 앱 비활성화

		//앱 삭제 리스트 저장용 코드

		sprintf_s(save, "%s\n", AppName); //sprintf 함수로 이름 끝에 엔터 넣은후 fputs으로 넘겨준다.

		system("cls");
		fopen_s(&file, "DeleteLog.txt", "a+"); //DeleteLog 파일이 없다면 만들고, 있다면 불러오기
		fputs(save, file); //AppName을 file포인터가 가르키고 있는 곳 = DeleteLog.txt에 넣는다.

		fclose(file); //파일 포인터 닫기
		printf("------------------------------------------------------\n");
		printf("비활성화 기록 저장 완료\n");

		printf("------------------------------------------------------\n");
		printf("작업 완료... 권한 에러시 스마트폰 재부팅 후 다시 시도해 주세요\n");
		printf("------------------------------------------------------\n");
		system("pause");

		goto MainMenu; //작업 완료후 메인 메뉴로 복귀

	}
	
	//삭제한 앱 확인의 경우
	if (MenuNum == 2)
	{
		system("cls");
		printf("------------------------------------------------------\n");

		fopen_s(&file,"DeleteLog.txt", "r"); //로그 파일 불러오기
		fread_s(DeleteLogOpen,sizeof(DeleteLogOpen),sizeof(DeleteLogOpen),1,file); //포인터에 로그 저장
		printf("%s", DeleteLogOpen);
		fclose(file); //파일 포인터 닫기

		printf("\n------------------------------------------------------\n");
		printf("DeleteLog.txt불러오기 완료.\n");
		printf("------------------------------------------------------\n");
		system("pause");
		goto MainMenu; // 작업 완료후 메인 메뉴로 복귀
	}



	//도움말의 경우
	if (MenuNum == 3)
	{
		system("cls");
		printf("------------------------------------------------------\n");
		printf("made by rasbi a.k.a 그날본 카드의 이름 VER 0.1 release\n");
		printf("------------------------------------------------------\n");
		printf("0.프로그램을 사용하며 발생하는 문제는 모두 사용자에게 책임이 있습니다.\n");
		printf("\n");
		printf("1.이 프로그램은 adb로 앱을 비활성화하는 프로그램입니다.\n");
		printf("\n");
		printf("2.앱 복구 기능을 넣지 않은 이유는 기기 별로 복구 명령어가 다르기 때문입니다. \n   (어떤 명령어는 되고 안되고 이런 게 너무 많았습니다.)\n");
		printf("\n");
		printf("3.앱 복구는 기기 펌웨어를 다시 설치하거나, 공장초기화하는 경우 복구가 가능합니다.\n");
		printf("\n");
		printf("4.이 프로그램은 오픈소스 프로그램이며, 자유롭게 변형 및 배포가 가능합니다.\n");
		printf("\n");
		printf("5.adb 명령어 참조 사이트: https://develoid.github.io/android/android-adb-app-disable.html\n");
		printf("\n");
		printf("------------------------------------------------------\n");
		system("pause");

	}


	//프로그램 종료의 경우
	if (MenuNum == 4)
	{
		system("cls");
		printf("프로그램을 종료합니다...\n");
		printf("------------------------------------------------------\n");
		system("pause");//계속하려면 아무키나 눌러주십시오...
		system("adb kill-server"); //adb 먼저 종료
		exit(0);//c언어에서 프로그램 종료하는 함수
	}

	else
	{
		goto MainMenu; //잘못된 값 입력시 메인 메뉴로 복귀
	}

	return 0; //정상 종료했다고 알림
}