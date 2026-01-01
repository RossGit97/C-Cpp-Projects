#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//node definition
typedef struct Node {
	char data;
	struct Node * left;
	struct Node * right;
} Node;

//create node
Node* createNode(char data){
	Node* newNode = (Node*) malloc (sizeof(Node));
	newNode ->data = data;
	newNode ->left = NULL;
	newNode ->right = NULL;
	return newNode;
}

//create Morse alphabet tree
Node* createMorseAlphabet(){
	Node * morse = createNode('.');
	Node * E = createNode('E');
	Node * T = createNode('T');
	morse->left = E;
	morse->right = T;
	Node * I = createNode('I');
	Node * A = createNode('A');
	Node * N = createNode('N');
	Node * M = createNode('M');
	E->left = I;
	E->right = A;
	T->left = N;
	T->right = M;
	Node * S = createNode('S');
	Node * U = createNode('U');
	Node * R = createNode('R');
	Node * W = createNode('W');
	Node * D = createNode('D');
	Node * K = createNode('K');
	Node * G = createNode('G');
	Node * O = createNode('O');
	I->left = S;
	I->right = U;
	A->left = R;
	A->right = W;
	N->left = D;
	N->right = K;
	M->left = G;
	M->right = O;
	Node * H = createNode('H');
	Node * V = createNode('V');
	Node * F = createNode('F');
	Node * L = createNode('L');
	Node * P = createNode('P');
	Node * J = createNode('J');
	Node * B = createNode('B');
	Node * X = createNode('X');
	Node * C = createNode('C');
	Node * Y = createNode('Y');
	Node * Z = createNode('Z');
	Node * Q = createNode('Q');
	S->left = H;
	S->right = V;
	U->left = F;
	R->left = L;
	W->left = P;
	W->right = J;
	D->left = B;
	D->right = X;
	K->left = C;
	K->right = Y;
	G->left = Z;
	G->right = Q;
	return morse;
}

//decode a morse code input (single letter)
char decodeMorse(char input[], int inputSize, Node* alphabet){
	int x = 0;
	Node* value = alphabet;
	while(x<inputSize){
		if(input[x] == '.'){
			value = value->left;
		}else{
			value = value->right;
		}
		x++;
	}
	return value->data;
}


int main(void){
	Node* root = createMorseAlphabet();
	char in[4];
	printf("Enter Morse Code: ");
	scanf("%s", &in);
	char test = decodeMorse(in, strlen(in), root);
	printf("%c", test);
//	printf("%c", root->left->left->left->left->data);
//	printf("%c", root->right->right->left->right->data);
	return 0;
}
