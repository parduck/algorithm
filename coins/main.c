#include <stdio.h> 

int Answer;
int M, C;
long long Mo[5001];
int CA[101];

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
		int i, j;

		Answer = 0;

		scanf("%d", &M);

		scanf("%d", &C);

		for (i = 1; i <= C; i++){
			scanf("%d", &CA[i]);
		}

		for (i = 1; i < 5001; i++)
			Mo[i] = 0;

		for (i = 1; i <= C; i++){

			Mo[CA[i]]++;

			for (j = 1; j + CA[i] <= M; j++){

				Mo[CA[i] + j] = Mo[CA[i] + j] + Mo[j];
			}
		}

		Answer = Mo[M] % 1000000007;

		printf("%d\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination. 
}