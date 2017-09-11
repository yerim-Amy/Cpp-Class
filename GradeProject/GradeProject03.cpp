#include<iostream>

using namespace std;

int main(){

	int st_cnt;
	cout << "몇명을 입력하시겠습니까?";
	cin >> st_cnt;//에러. 상수.

	int **score = new int*[st_cnt];
	for (int i = 0; i < st_cnt; i++)
	{
		score[i] = new int[10];
	}
	double* avg = new double[st_cnt];
	char* major = new char[st_cnt];

	char **st_number = new char*[st_cnt];
	for (int i = 0; i < st_cnt; i++)
	{
		st_number[i] = new char[5];
	}

	char** st_name = new char*[st_cnt];
	for (int i = 0; i < st_cnt; i++)
	{
		st_name[i] = new char[10];
	}

	int* grade = new int[st_cnt];

	char sub[9][6] = { "국어", "영어", "수학", "C++", "JAVA", "과학", "OS ", "SB ", "DS " };

	int subject;//과목수
	cout << "몇 과목을 입력하시겠습니까?";
	cin >> subject;

	for (int i = 0; i < st_cnt; i++){

		cout << "학생 학번을 입력해주세요 : ";
		cin >> st_number[i];

		cout << "학생 이름을 입력해주세요 : ";
		cin >> st_name[i];

		score[i][subject] = 0;//초기화

		for (int j = 0; j < subject; j++)
		{
			do{
				cout << "학생 " << i + 1 << "의 " << sub[j] << "점수를 입력해주세요 : ";
				cin >> score[i][j];

				if (score[i][j]<0 || score[i][j]>100)
					cout << "잘못 입력하셨습니다" << endl;
			} while (score[i][j]<0 || score[i][j]>100);

			score[i][subject] += score[i][j];
		}
		avg[i] = (double)score[i][subject] / subject;

		switch ((int)avg[i] / 10){
		case 10:
		case 9: major[i] = 'A'; break;
		case 8: major[i] = 'B'; break;
		case 7: major[i] = 'C'; break;
		case 6: major[i] = 'D'; break;
		default: major[i] = 'F';
		}
	}

	for (int i = 0; i < st_cnt; i++)
	{
		grade[i] = 1;
	}
	for (int i = 0; i < st_cnt - 1; i++){
		for (int j = i + 1; j < st_cnt; j++){
			if (avg[i] < avg[j]){
				grade[i]++;
			}
			else if (avg[i]>avg[j]){
				grade[j]++;
			}
		}
	}
	printf(" 학번    이름  ");
	for (int title = 0; title < subject; title++)
	{
		printf("%7s", sub[title]);
	}
	printf("   총점     평균     등급      석차\n");
	for (int i = 0; i < st_cnt; i++)
	{
		printf("%5s", st_number[i]);
		printf("%9s", st_name[i]);
		for (int j = 0; j < subject + 1; j++)
		{
			printf("%7d", score[i][j]);
		}
		printf("%10.2f", avg[i]); //100.00
		printf("%8c", major[i]);
		printf("%10d\n", grade[i]);
	}

	for (int i = 0; i < st_cnt; i++)
	{
		delete[] score[i];
		delete[] st_number[i];
		delete[] st_name[i];
	}

	delete[] score;
	delete[] avg;
	delete[] major;
	delete[] st_number;
	delete[] st_name;
	delete[] grade;

	return 0;
}