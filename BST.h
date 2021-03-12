
// An integer binary search tree

struct treeNode {                                           
   struct treeNode *leftPtr; // pointer to left subtree 
   int data; // node value                               
   struct treeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode         

typedef struct treeNode TreeNode; // synonym for struct treeNode
typedef TreeNode *TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr rootPtr;
}BST;

// prototypes
void insertNode( BST *b, int value ){

	 TreeNodePtr t =b->rootPtr,new_node;
	 int inserted=0; //สำเร็จ =1 ไม่สำเร็จ =0
    new_node=(TreeNodePtr) malloc(sizeof(TreeNode));
	if(new_node){
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
	/*First Node*/
	if(!b->rootPtr) // if(b->root==NULL)
  	b->rootPtr=new_node;
	else {
    while(!inserted){ // while(insert!=1)
      if(t->data >=value)
      {
        if(t->leftPtr==NULL)
        {
          t->leftPtr=new_node;
          inserted=1;
          b->size++;
        }
        else
        {
          t=t->leftPtr;
        }
        
      }
       else{
         if(t->rightPtr==NULL)
        {
          t->rightPtr=new_node;
          inserted=1;
          b->size++;
        }
        else
        {
          t=t->rightPtr;
        }

	     }	

    }//end while		
 }//end else;
}
}//end function


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {                
      inOrder( treePtr->leftPtr ); //Recursion to the left 
      printf( "%3d", treePtr->data );  //print the value    
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                          
} // end function 

void preOrder( TreeNodePtr treePtr ){
  if ( treePtr != NULL ) {                
      printf( "%3d", treePtr->data );
      preOrder( treePtr->leftPtr );   
      preOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if
}
void postOrder( TreeNodePtr treePtr ){
  if ( treePtr != NULL ) {                
      postOrder( treePtr->leftPtr ); //Recursion to the left 
      postOrder( treePtr->rightPtr ); //Recursion to the right
      printf( "%3d", treePtr->data );  //print the value    
      
    } // end if
    
}
void printTree(TreeNodePtr treePtr,int level)
{
  int i;
  if(treePtr!=NULL)
  {
    printTree( treePtr->rightPtr,level+1);
    for(i=0;i<level;i++)
    {
      printf("\t");
    }
    printf( "%3d\n", treePtr->data );
    printTree( treePtr->leftPtr,level+1 );
    level--;
  }

}
