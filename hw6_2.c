
// hw6_2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl.h"
#include "bst.h"
#include "rb.h"

#define BUF_SIZE 128
#define STR_NUM 32

void print_avl( const struct avl_node* node ) {
	//printf("print_avl\n");
	if(node == NULL)
		return ;
	printf( "%s " , ((char *)node->avl_data));
	if(node->avl_link[0] != NULL || node->avl_link [1] != NULL) {
		putchar ('(') ;
		print_avl(node->avl_link[0]) ;
		putchar (',') ;
		putchar (' ') ;
		print_avl(node->avl_link[1]) ;
		putchar (')') ;
	}
}

void print_bst( const struct bst_node* node ) {
	//printf("print_bst\n");
	if(node == NULL)
		return ;
	printf( "%s " , (char *)node->bst_data);
	if(node->bst_link[0] != NULL || node->bst_link [1] != NULL) {
		putchar ('(') ;
		print_bst(node->bst_link[0]) ;
		putchar (',') ;
		putchar (' ') ;
		print_bst(node->bst_link[1]) ;
		putchar (')') ;
	}
}

void print_rb( const struct rb_node* node ) {
	//printf("print_rb\n");
	if(node == NULL)
		return ;
	printf( "%s " , ((char *)node->rb_data));
	if(node->rb_link[0] != NULL || node->rb_link [1] != NULL) {
		putchar ('(') ;
		print_rb(node->rb_link[0]) ;
		putchar (',') ;
		putchar (' ') ;
		print_rb(node->rb_link[1]) ;
		putchar (')') ;
	}
}

int str_cmp(const void* pa, const void* pb,void* param){
	int ret;
	ret = strncmp((char* )pa,(char*)pb,BUF_SIZE);
	if(ret > 0 ) return 1;
	if(ret < 0 ) return -1;
	else return 0;
}


int main() {
	struct avl_table* avl_tree;
	struct bst_table* bst_tree;
	struct rb_table* rb_tree;
	char* input_str[STR_NUM];
	char buf[BUF_SIZE];
	void** p[3];
	int str_length;
	
	avl_tree = avl_create( str_cmp , NULL, NULL) ;
	bst_tree = bst_create( str_cmp, NULL , NULL);
	rb_tree = rb_create(str_cmp, NULL , NULL);
	
	// input string
	for(int i=0;i<STR_NUM;i++){
		if(fgets(buf, BUF_SIZE , stdin)!= NULL) {
			str_length = strlen(buf)-1;
			input_str[i] = malloc(str_length*sizeof(char));
			strncpy(input_str[i],buf,str_length);
			//printf("%s\n",input_str[i]);
			p[0] = avl_probe( avl_tree , input_str[i]);
			p[1] = bst_probe( bst_tree , input_str[i]);
			p[2] = rb_probe( rb_tree , input_str[i]);
		}
	}
	print_avl(avl_tree->avl_root);
	printf("\n");
	print_bst(bst_tree->bst_root);
	printf("\n");
	print_rb(rb_tree->rb_root);
	printf("\n");
	return 0;
}

