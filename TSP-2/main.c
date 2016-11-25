/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h> 
#define MAX_C 15

double Answer;
int N;


double  TA[MAX_C + 1][MAX_C + 1] = { 0 };
int V[MAX_C + 1] = { 0 };
double map[MAX_C + 1][500000];

long toB(int n)
{
	int i;
	long rtn = 1;

	for (i = 1; i <= n; i++){
		rtn = rtn * 2;
	}

	return rtn;
}

double TSP(int from, long to, int n)
{
	int i, j;
	double tval;
	

	//basis
	if (n == 1){
		return 0;
	}

	//이미 해당 탐색 경로에 최소값이 구해져 있다.
	if (map[from][to] > 0)
		return map[from][to];

	tval = 100000000;

	for (i = 1; i <= N; i++){

		if (V[i] == 0){
			double sum = TA[from][i];
			V[i] = 1;
			int tmp = to - toB(i);
			sum = sum+ TSP(i, to-toB(i-1) , n - 1);
			
			V[i] = 0;

			if (tval > sum)
				tval = sum;			
		}		
		
	}
	
	//map에는 최소값을 넣는다.
	map[from][to] = tval;

	return tval;
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
		int i,j;
		double rtn = 0.0;
		long to;

		Answer = 10000000000;		

		scanf("%d", &N);

		for (i = 1; i <= N; i++){
			for (j = 1; j <= N; j++){
				scanf("%lf", &TA[i][j]);
			}

			V[i] = 0;
		}

		for (i = 1; i <= 15; i++){
			for (j = 1; j <= 500000; j++){
				map[i][j]=0;
			}
		}
		
		
		for (i = 1; i <= N; i++){
			to = toB(N) - 1 - toB(i-1);
			
			V[i] = 1;
			rtn = TSP(i, to, N);
			V[i] = 0;

			if (rtn < Answer)
				Answer = rtn;
		}


		// Print the answer to standard output(screen). 
		printf("Case #%d\n", test_case + 1);
		printf("%.10lf\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination. 
}