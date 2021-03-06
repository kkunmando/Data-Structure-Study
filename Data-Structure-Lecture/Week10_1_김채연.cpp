#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

void name();		//전공, 이름, 학번을 출력하는 함수

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));		//동적 메모리 할당 사용
}

void init(HeapType* h) {		//힙 초기화
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {		//최대 힙에 값 insert
	int i;
	i = ++(h->heap_size);		//노드 추가 후 증가된 말단 노드 인덱스를 i에 대입
	while ((i != 1) && (item.key > h->heap[i / 2].key)) {		//트리를 거슬러 올라가며 부모 노드 key값과 비교
		h->heap[i] = h->heap[i / 2];		//부모노드가 더 작을 경우 부모노드를 내림
		i /= 2;		//인덱스 새로운 위치로 이동
	}
	h->heap[i] = item;		//최종 결정된 위치에 새로운 노드를 insert
}

void insert_min_heap(HeapType* h, element item) {		//최소 힙에 값 insert
	int i;
	i = ++(h->heap_size);		//노드 추가 후 증가된 말단 노드 인덱스를 i에 대입
	while ((i != 1) && (item.key < h->heap[i / 2].key)) {		//트리를 거슬러 올라가며 부모 노드 key값과 비교
		h->heap[i] = h->heap[i / 2];		//부모노드가 더 클 경우 부모노드를 내림
		i /= 2;		//인덱스 새로운 위치로 이동
	}
	h->heap[i] = item;		//최종 결정된 위치에 새로운 노드를 insert
}

void delete_max_heap(HeapType* h) {		//최대 힙에서 노드 삭제
	int p = 1, c = 2;		//p는 부모, c는 자식. 두번째 노드부터 root노드와 비교 시작
	element item = h->heap[1];		//삭제되는 노드
	element temp = h->heap[h->heap_size--];		//말단 노드를 temp에 대입, 노드 삭제 시 heap_size 감소
	while (c <= h->heap_size) {		//말단 노드까지 트리를 내려가며 자식노드 키 값과 temp 키 값 비교
		if ((c < h->heap_size) && (h->heap[c].key < h->heap[c + 1].key))	//자식 노드가 두개 일때 둘 중 큰 값 찾기
			c++;
		if (temp.key >= h->heap[c].key)		//신규노드가 더 크면 위치 확정
			break;
		h->heap[p] = h->heap[c];		//자식노드가 더 크면 부모 노드에 자식 노드 복사
		p = c;
		c *= 2;		//자식 인덱스는 그 아래 자식으로 변경
	}
	h->heap[p] = temp;		//최종 결정된 위치에 신규 노드 insert
}

void delete_min_heap(HeapType* h) {
	int p = 1, c = 2;		//p는 부모, c는 자식. 두번째 노드부터 root노드와 비교 시작
	element item = h->heap[1];		//삭제되는 노드
	element temp = h->heap[h->heap_size--];		//말단 노드를 temp에 대입, 노드 삭제 시 heap_size 감소
	while (c <= h->heap_size) {		//말단 노드까지 트리를 내려가며 자식노드 키 값과 temp 키 값 비교
		if ((c < h->heap_size) && (h->heap[c].key > h->heap[c + 1].key))	//자식 노드가 두개 일때 둘 중 작은 값 찾기
			c++;
		if (temp.key <= h->heap[c].key)		//신규노드가 더 작으면 위치 확정
			break;
		h->heap[p] = h->heap[c];		//자식노드가 더 작으면 부모 노드에 자식 노드 복사
		p = c;
		c *= 2;		//자식 인덱스는 그 아래 자식으로 변경
	}
	h->heap[p] = temp;		//최종 결정된 위치에 신규 노드 insert
}

void print_heap(HeapType* max_h, HeapType* min_h) {		//힙 상태를 출력하는 함수
	printf("<Max Heap>\n");
	for (int i = 1; i <= max_h->heap_size; i++)
		printf("%d ", max_h->heap[i].key);		//최대 힙 출력
	printf("\n<Min Heap>\n");
	for (int i = 1; i <= min_h->heap_size; i++)
		printf("%d ", min_h->heap[i].key);		//최소 힙 출력
	printf("\n");
}

int main() {
	name();

	char ans;
	element item;
	//힙 생성
	HeapType* max_heap = create();
	HeapType* min_heap = create();
	//힙 초기화
	init(max_heap);
	init(min_heap);
	while (true) {
		printf("*Input Operation I(Insert) D(Delete) X(Exit): ");
		scanf(" %c", &ans);
		switch (ans) {
			case 'I':		//값 집어넣기
				printf("Input value to insert:");
				scanf("%d", &item);
				insert_max_heap(max_heap, item);
				insert_min_heap(min_heap, item);
				print_heap(max_heap, min_heap);
				break;
			case 'D':		//노드 삭제하기
				delete_max_heap(max_heap);
				delete_min_heap(min_heap);
				print_heap(max_heap, min_heap);
				break;
			case 'X':		//종료
				exit(1);	
		}
	}

	free(max_heap);
	free(min_heap);

	return 0;
}


void name()
{
	printf("===================\n");
	printf("학과: 사이버보안전공\n");
	printf("학번: 1971066\n");
	printf("성명: 김채연\n");
	printf("===================\n");
}