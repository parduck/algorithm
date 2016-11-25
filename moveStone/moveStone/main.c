/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h> 

int Answer;
int N;
int SUM;
int cnt;

int S[31] = { 0 };
int V[31] = { 0 };
int PSUM[31] = { 0 };


void calc(int n)
{
	int i;

	//base 
	if (n > 1){
		if (cnt == SUM){
			Answer++;
			return;
		}
		else if (cnt > SUM)
			return;

		//������� �հ� ���ڸ��� ���� MAX ���� ���ص� SUM�� �� �ȴٸ� Ž�� ���ʿ�
		if (cnt + PSUM[n + 1] < SUM)
			return;
	}

	if (n == 1){
		//V[1] = 1;
		cnt = cnt + S[1];
	}

	// �ܹ����� visited üũ�� �ʿ����: �հ��� ������ ������ ������ ���
	for (i = n + 1; i <= N; i++){
	//	if (V[i] == 0){
			//V[i] = 1;
			cnt = cnt + S[i];
			calc(i);
			//V[i] = 0;
			cnt = cnt - S[i];
		//}
	}
}

void preset()
{
	int i;
	PSUM[N] = S[N];
	for (i = N-1; i >= 1; i--){
		PSUM[i] = PSUM[i + 1] + S[i];
	}
}

int main(void)
{
	int T, test_case;
	/*
	The freopen function below opens input.txt file in read only mode, and afterward,
	the program will read from input.txt file instead of standard(keyboard) input.
	To test your program, you may save input data in input.txt file,
	and use freopen function to read from the file when using scanf function.
	You may remove the comment symbols(//) in the below statement and use it.
	But before submission, you must remove the freopen function or rewrite comment symbols(//).
	*/
	freopen("input.txt", "r", stdin);

	/*
	If you remove the statement below, your program's output may not be rocorded
	when your program is terminated after the time limit.
	For safety, please use setbuf(stdout, NULL); statement.
	*/
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{

		///////////////////////////////////////////////////////////////////////////////////////////// 
		/*
		Implement your algorithm here.
		The answer to the case will be stored in variable Answer.
		*/
		///////////////////////////////////////////////////////////////////////////////////////////// 
		int i;

		Answer = 0;
		SUM = 0;
		cnt = 0;

		scanf("%d", &N);

		for (i = 1; i <= N; i++){
			scanf("%d", &S[i]);
			V[i] = 0;
			PSUM[i] = 0;

			SUM = SUM + S[i];
		}

		SUM = SUM / 2;


		//���� ġ�⸦ ���� ������ ���� ���� ���´�.
		preset();		

		//��͹ۿ� ���ϰڴ�..T_T 
		calc(1);



		// Print the answer to standard output(screen). 
		printf("Case #%d\n", test_case + 1);
		printf("%d\n", Answer * 2);
	}

	return 0;//Your program should return 0 on normal termination. 
}