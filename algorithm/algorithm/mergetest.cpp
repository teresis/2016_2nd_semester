#include <stdio.h>



void merge_sort(int array[], int left, int right);   //분할 함수

void merge(int num[], int left, int mid, int right);   //병합 함수



const int ITEMSIZE = 100000;

int result[ITEMSIZE];



int main(void)

{
int matrix[10000];/*행렬잡기*/
	int num;/* 변수개수*/
	int a; /*매개변수*/
	scanf("%d", &num);/*넣을 변수 개수 초기화*/
	for (a = 0; a < num; a++) {
		scanf("%d", &matrix[a]);/*행렬 초기화 */
		
	}
	for (a = 0; a < num; a++) {
		printf("%d", matrix[a]); /*출력 확인값*/

	}

	merge_sort(matrix, 0, num - 1);
	printf("\n");
	for (a = 0; a < num; a++) {
		printf("%d", matrix[a]); /*출력 확인값*/

	}
	return 0;
}



void merge_sort(int array[], int left, int right) {

	int mid;



	// 분할이 다 되지 않았을 경우 if 문 실행  

	if (left < right) {

		mid = (left + right) / 2;



		merge_sort(array, left, mid);      //왼쪽 블록 분할

		merge_sort(array, mid + 1, right);  //오른쪽 블록 분할

		merge(array, left, mid, right);   //분할된 블록 병합

	}
}



	void merge(int array[], int left, int mid, int right){

		int i, j, k, m;



		i = left;

		j = mid + 1;

		k = left;    //결과 배열의 인덱스



		int tempArray[ITEMSIZE];



		//left부터 mid 까지의 블록과 mid+1부터 right까지의 블록을 서로 비교하는 부분

		while (i <= mid && j <= right) {

			if (array[i] < array[j]) {   //left index 값이 right index 값보다 작으면 left index 값을 결과 result에 복사

				tempArray[k] = array[i];

				i++;

			}
			else {        //아니라면 right index 값을 결과 result에 복사

				tempArray[k] = array[j];

				j++;

			}

			k++;

		}



		// left 블록의 값은 다 처리되었는데 right 블록의 index가 아직 남아있을 경우

		// right index를 순차적으로 결과 result에 복사

		if (i > mid) {

			for (m = j; m <= right; m++) {

				tempArray[k] = array[m];

				k++;

			}

		}
		else {                    // left 블록의 index가 아직 남아있을 경우 left index를 순차적으로 결과 result에 복사 

			for (m = i; m <= mid; m++) {

				tempArray[k] = array[m];

				k++;

			}

		}



		for (m = left; m <= right; m++) {

			array[m] = tempArray[m];

		}

	}